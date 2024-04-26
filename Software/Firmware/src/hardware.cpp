#include <Arduino.h>
#include "hardware.h"
#include "geiger.h"
#include "gui.h"
#include "settings.h"
#include "batteryLUT.h"

TaskHandle_t geiger_counter_int_task;
int alarm_silenced = 0;

bool display_on = 1;
int display_state_millis = millis();

void IRAM_ATTR ok_button_isr()
{
  if (digitalRead(OK_BUTTON_PIN))
  {
    if (display_on)
    {
      gui_enable_input(1);
    }
    if (alarm_triggered && !alarm_silenced)
    {
      alarm_silenced = 1;
      gui_enable_input(1);
    }
  }
  else
  {
    if ((!display_on) && (millis() - display_state_millis > 1000))
    {
      turn_display_on();
    }
  }
}

void turn_display_off()
{

  tft.writecommand(ST7789_DISPOFF); // Switch off the display

  tft.writecommand(ST7789_SLPIN); // Sleep the display driver

  ledcWrite(1, 0);
  display_on = 0;
  display_state_millis = millis();
}

void turn_display_on()
{

  tft.writecommand(ST7789_DISPON); // Switch on the display

  tft.writecommand(ST7789_SLPOUT); // wake the display driver

  apply_screen_brightness(get_screen_brightness());
  display_on = 1;
  display_state_millis = millis();
}

void gui_enable_input(bool en)
{
  enable_nav_input(en);
}

void store_persistent_data()
{
  set_ddose(get_dose());
}

void enter_deep_sleep()
{
  turn_display_off();
  if (get_wake_enabled())
  {
    enable_wakeup_timer(get_wakeup_every());
  }
  else
  {
    disable_wakeup_timer();
  }
  store_persistent_data();
  esp_sleep_enable_ext0_wakeup(WAKEUP_GPIO_NUM, 0);
  esp_deep_sleep_start();
}

void apply_screen_brightness(int val)
{
  int display_brightness_pwm = (val * (255 - 20)) / 5 + 20;
  ledcWrite(1, display_brightness_pwm);
}

void nav_buttons_init()
{
  pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(OK_BUTTON_PIN, INPUT_PULLUP);
}

void buzzer_init()
{
  digitalWrite(BUZZER_PIN, HIGH);
  pinMode(BUZZER_PIN, OUTPUT);
}

void geiger_counter_int_task_handler(void *pvParameters)
{
  attachInterrupt(TUBE_DETECT_PIN, geiger_pulse, FALLING);
}

float exponential_smoothing(float new_voltage, float smoothed_voltage)
{
  // Update smoothed voltage based on new reading and weight
  smoothed_voltage = BAT_ADC_SMOOTHING_FACTOR * new_voltage + (1 - BAT_ADC_SMOOTHING_FACTOR) * smoothed_voltage;
  return smoothed_voltage;
}

// pseudo-Lookup table for getting the Battery level from the voltage.
int volt_to_level(double volts)
{
  int idx = 50;
  int prev = 0;
  int half = 0;
  volts += BAT_VOLTAGE_OFFSET;
  if (volts >= MIN_USB_VOLAGE)
  {
    return -1;
  }
  if (volts >= 4.2)
  {
    return 100;
  }
  if (volts <= 3.2)
  {
    return 0;
  }
  while (true)
  {
    half = abs(idx - prev) / 2;
    prev = idx;
    if (volts >= battery_voltage_lut[idx])
    {
      idx = idx + half;
    }
    else
    {
      idx = idx - half;
    }
    if (prev == idx)
    {
      break;
    }
  }
  return idx;
}

double bat_volt_smoothed = -1;
double read_battery_voltage()
{
  int totalValue = 0;
  int averageValue = 0;
  for (int i = 0; i < BAT_AVG_SAMPLES; i++)
  {
    totalValue += analogRead(BAT_ADC_PIN);
  }
  averageValue = totalValue / BAT_AVG_SAMPLES;
  double volts;
  volts = averageValue * BAT_ADC_CONV_RATE / 1000;
  if (volts >= MIN_USB_VOLAGE)
  {
    return volts;
  }
  if (bat_volt_smoothed < 0)
  {
    bat_volt_smoothed = volts;
  }
  bat_volt_smoothed = exponential_smoothing(volts, bat_volt_smoothed);
  return bat_volt_smoothed;
}

int get_bat_charge_lvl()
{
  return volt_to_level(read_battery_voltage());
}

void enable_wakeup_timer(int ms)
{
  esp_sleep_enable_timer_wakeup(ms * 1000);
}

void disable_wakeup_timer()
{
  esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_TIMER);
}

int wakeup_millis = millis();
void weakup_measurement()
{
  nav_buttons_init();
  int window_size = get_wakeup_window();
  int period = get_wakeup_period();
  bool last_btn_state = true;
  int btn_millis;
  while ((millis() - wakeup_millis) < (period * (window_size + 1)))
  {
    radiation_measurement(window_size, period, true);
    if (!digitalRead(OK_BUTTON_PIN))
    {
      if (last_btn_state)
      {
        btn_millis = millis();
      }
      else if ((millis() - btn_millis > 3000))
      {
        return;
      }
    }
    last_btn_state = digitalRead(OK_BUTTON_PIN);
  }
  double dose = get_dose();
  dose += get_usv() * ((double)(get_wakeup_every() + (window_size * period)) / 3600000.0);
  set_dose(dose);
  if (get_usv() >= get_alarm_threshold() && get_alarm_enabled())
  {
  }
  else
  {
    enter_deep_sleep();
  }
}

void wakeup_handler()
{
  int wakeup_millis = millis();
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason)
  {
  case ESP_SLEEP_WAKEUP_TIMER:
    weakup_measurement();
    break;
  case ESP_SLEEP_WAKEUP_EXT0:
    nav_buttons_init();
    while (!digitalRead(OK_BUTTON_PIN) && (millis() - wakeup_millis < 3000))
    {
    }
    if (!digitalRead(OK_BUTTON_PIN))
    {
      return;
    }
    else
    {
      enter_deep_sleep();
    }
    break;
  default:
    return;
    break;
  }
}

void set_tube_voltage(unsigned char level)
{
  ledcWrite(0, level);
}

void geiger_tube_init()
{
  pinMode(TUBE_DETECT_PIN, INPUT_PULLUP);
  pinMode(TUBE_HV_PIN, OUTPUT);
  ledcSetup(0, TUBE_HV_FREQ, 8);
  ledcAttachPin(TUBE_HV_PIN, 0);
  ledcWrite(0, TUBE_HV_DEF_DUTY);
  set_tube_voltage(get_tube_voltage_level());
  attachInterrupt(TUBE_DETECT_PIN, geiger_pulse, FALLING);
}

// initilize Hardware Components
void hardware_init()
{
  buzzer_init();            // buzzer initialize
  pinMode(BL_PIN, OUTPUT);  // Screen Backlight Pin
  ledcSetup(1, 5000, 8);    // 0-15, 5000, 8
  ledcAttachPin(BL_PIN, 1); // TFT_BL, 0 - 15

  attachInterrupt(OK_BUTTON_PIN, ok_button_isr, CHANGE);
  apply_screen_brightness(get_screen_brightness());
}

// a particle has been detected!
int click_start_millis;
int clicker_buzzer_on = 0;
void clicker()
{
  if (get_clicker_enabled())
  {
    // if a particle has been detected and it has been 10 millisecs since the last click:
    // turn buzzer on (to make a click sound)
    // reset gieger event
    if (event && ((millis() - click_start_millis) > 10))
    {
      click_start_millis = millis();
      digitalWrite(BUZZER_PIN, LOW);
      event = 0;
      clicker_buzzer_on = 1;
    }
  }
  // makes click sound when enabling the clicker from the settings.
  else
  {
    event = 1;
  }

  // if the buzzer(acting like a clicker) is on and it has been 1 millisec since the click start:
  // turn buzzer off (to end the click sound).
  if (clicker_buzzer_on && (millis() - click_start_millis) > 1)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    clicker_buzzer_on = 0;
  }
}

// count time from the start of the program
// millis is used instead of interupts, as not to pause the running program.
int alarm_start_millis = millis();
int alarm_buzzer_on = 0;
void sound_alarm()
{
  // if the alarm triger condition is on and the alarm is not silenced by the user:
  // turn on display if off.
  if (alarm_triggered && !alarm_silenced)
  {
    gui_enable_input(0);
    if (!display_on)
    {
      turn_display_on();
    }

    // if it has been 200 millisecs since the alarm started:
    // turn buzzer off, if it was on.
    // and reset the alarm start variable.
    if ((millis() - alarm_start_millis) > 200)
    {
      if (alarm_buzzer_on)
      {
        digitalWrite(BUZZER_PIN, HIGH);
        alarm_buzzer_on = 0;
      }
      alarm_start_millis = millis();
    }

    // otherwise, if it has been 100 millisecs since the alarm started:
    // turn buzzer on.
    else if ((millis() - alarm_start_millis) > 100)
    {
      digitalWrite(BUZZER_PIN, LOW);
      alarm_buzzer_on = 1;
    }
  }

  // if the alarm isn't supposed to be on, or it is silenced:
  // turn buzzer off, if it was on.
  else if (alarm_buzzer_on)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    alarm_buzzer_on = 0;
  }

  // when the alarm conditions become false:
  // cancel the silence for the next alarm and return control over the GUI.
  if (!alarm_triggered)
  {
    alarm_silenced = 0;
  }
}