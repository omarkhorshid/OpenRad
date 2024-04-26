#include "Arduino.h"
#include "gui.h"
#include "settings.h"
#include <ui.h>
#include "hardware.h"
#include "geiger.h"
#include "connectivity.h"

static lv_indev_t *indev;
int warning_sign_triggered = 0;

/*Change to your screen resolution*/
static const uint16_t screenWidth = TFT_HEIGHT;
static const uint16_t screenHeight = TFT_WIDTH;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

// Initialize TFT instance
TFT_eSPI tft = TFT_eSPI();

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

#define BUTTON_COUNT 3
typedef struct
{
  const uint8_t pin;
  lv_key_t key;
  uint8_t last_state;
  uint8_t current_state;
} button_t;

button_t buttons[BUTTON_COUNT] = {
    {UP_BUTTON_PIN, LV_KEY_LEFT, 0, 0},
    {OK_BUTTON_PIN, LV_KEY_ENTER, 0, 0},
    {DOWN_BUTTON_PIN, LV_KEY_RIGHT, 0, 0}

};

// input handling for the three keys
void key_input_driver(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  uint8_t keypress_flg;
  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    button_t *button = &buttons[i];
    button->current_state = !digitalRead(button->pin);
    keypress_flg |= button->current_state;
  }

  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    button_t *button = &buttons[i];

    if (button->current_state != button->last_state)
    { // State change detected
      button->last_state = button->current_state;
      data->key = button->key;
      break;
    }
  }
  if (keypress_flg)
    data->state = LV_INDEV_STATE_PRESSED;
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

// lvgl logging
void my_log_cb(const char *buf)
{
  Serial.write(buf);
}

// enable/disable navigation input
void enable_nav_input(bool en)
{
  lv_indev_enable(indev, en);
}

// shows specified object.
void show_object(lv_obj_t *TargetObject)
{
  if (lv_obj_has_flag(TargetObject, LV_OBJ_FLAG_HIDDEN))
  {
    lv_obj_clear_flag(TargetObject, LV_OBJ_FLAG_HIDDEN);
  }
}

// hides specified object.
void hide_object(lv_obj_t *TargetObject)
{
  if (!lv_obj_has_flag(TargetObject, LV_OBJ_FLAG_HIDDEN))
  {
    lv_obj_add_flag(TargetObject, LV_OBJ_FLAG_HIDDEN);
  }
}

// show warning sign, with animation.
void show_warning_sign(bool en)
{
  if (en)
  {
    if (lv_obj_has_flag(ui_RadWarningIcon, LV_OBJ_FLAG_HIDDEN))
    {
      show_object(ui_RadWarningIcon);
      RadWarning_Animation(ui_RadWarningIcon, 0);
    }
  }
  else
  {
    hide_object(ui_RadWarningIcon);
  }
}

// returns true if obj on screen.
bool is_obj_on_screen(_lv_obj_t *lv_obj)
{

  return (lv_scr_act() == lv_obj_get_screen(lv_obj));
}

// update main page objects
void update_main_page_objects(double sv, int cpm, double cdose)
{
  // if active screen is home
  if (lv_scr_act() == ui_Home)
  {

    // if primarary gauge is on screen
    if (is_obj_on_screen(ui_PrimaryGuage))
    {
      // UNIT PREFIX
      // if value >= 1000000.0 -> Sv/h
      // if value >= 1000.0 ----> mSv/h
      // else value ------------> uSv/h
      if (sv >= 1000000.0)
      {
        lv_label_set_text(ui_PrimaryUnit, "Sv/h");
        sv /= 1000000.0;
      }
      else if (sv >= 1000.0)
      {
        lv_label_set_text(ui_PrimaryUnit, "mSv/h");
        sv /= 1000.0;
      }
      else
      {
        lv_label_set_text(ui_PrimaryUnit, "uSv/h");
      }
      lv_label_set_text_fmt(ui_PrimaryGuage, "%.2f", sv); // apply unit prefix
    }
    // if ui_DoseGaugen is on screen
    if (is_obj_on_screen(ui_DoseGuage))
    {
      // UNIT PREFIX
      // if value >= 1000000.0 -> Sv
      // if value >= 1000.0 ----> mSv
      // else value ------------> uSv
      if (cdose >= 1000000.0)
      {
        lv_label_set_text(ui_DoseUnit, "Sv");
        cdose /= 1000000.0;
      }
      else if (cdose >= 1000.0)
      {
        lv_label_set_text(ui_DoseUnit, "mSv");
        cdose /= 1000.0;
      }
      else
      {
        lv_label_set_text(ui_DoseUnit, "uSv");
      }
      lv_label_set_text_fmt(ui_DoseGuage, "%.2f", cdose); // apply unit prefix
    }
    if (is_obj_on_screen(ui_SecondaryGuage))
    {
      // UNIT PREFIX
      // if value >= 1000.0 ----> kcpm
      // else value ------------> cpm
      if (cpm >= 1000.0)
      {
        lv_label_set_text(ui_SecondaryUnit, "kCPM");
        lv_label_set_text_fmt(ui_SecondaryGuage, "%.2f", cpm / 1000.0);
      }
      else
      {
        lv_label_set_text(ui_SecondaryUnit, "CPM");
        lv_label_set_text_fmt(ui_SecondaryGuage, "%d", cpm);
      }
    }
    // if ui_RadRange on screen, change values
    if (is_obj_on_screen(ui_RadRange))
    {
      lv_bar_set_value(ui_RadRange, ((sv - 0.0) * (100 - 10) / (1.0 - 0.0) + 10), LV_ANIM_ON);
    }
    if (is_obj_on_screen(ui_BatteryGuage))
    {
      // if charging, show charging bolt, hide battery indicator and fill battery percentage label.
      int value = get_bat_charge_lvl();
      if (value == -1)
      {
        lv_bar_set_value(ui_BatteryGuage, 100, LV_ANIM_OFF);
        show_object(ui_ChargingIcon);
        hide_object(ui_BatLabel);
      }
      // if not charging, hide charging bolt, show battery indicator and adjust battery percentage label.
      else
      {
        hide_object(ui_ChargingIcon);
        show_object(ui_BatLabel);
        lv_label_set_text_fmt(ui_BatLabel, "%d", value);
        lv_bar_set_value(ui_BatteryGuage, value, LV_ANIM_OFF);

        // if battery is under 15%, turn battery color red.
        if (value < 15)
        {
          lv_obj_set_style_bg_color(ui_BatteryGuage, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
        }
        else
        {
          lv_obj_set_style_bg_color(ui_BatteryGuage, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
        }
      }
    }

    // All Indicators
    // clicker Indicator
    if (get_clicker_enabled())
    {
      show_object(ui_ClickerEnableIndicator);
    }
    else
    {
      hide_object(ui_ClickerEnableIndicator);
    }

    // AlertIndicator Indicator
    if (get_alarm_enabled())
    {
      show_object(ui_AlertIndicator);
    }
    else
    {
      hide_object(ui_AlertIndicator);
    }

    if (get_wake_enabled())
    {
      show_object(ui_SleepSampleIndicator);
    }
    else
    {
      hide_object(ui_SleepSampleIndicator);
    }

    if (get_wifi_enabled())
    {
      show_object(ui_WifiIndicator);
    }
    else
    {
      hide_object(ui_WifiIndicator);
    }

    // warning_sign Indicator
    if (warning_sign_triggered)
    {
      show_warning_sign(1);
    }
    else
    {
      show_warning_sign(0);
    }
  }
}

double find_max_value(const double data[], int size)
{
  double max_value = 0;
  for (int i = 0; i < size; i++)
  {
    if (data[i] > max_value)
    {
      max_value = data[i];
    }
  }
  return max_value;
}

// lv_chart_series_t *data_series;
void update_graph_page()
{
  if (lv_scr_act() == ui_History)
  {
    double histroy_data[HISTORY_WINDOW_SIZE] = {0};
    get_history_data(histroy_data);
    lv_chart_series_t *data_series = lv_chart_get_series_next(ui_HistoryChart, NULL);
    // if(empty_graph_series){
    //   // lv_chart_set_all_value(ui_HistoryChart, data_series,0);
    // }else{
    //     data_series = lv_chart_add_series(ui_HistoryChart, lv_palette_main(LV_PALETTE_GREY), LV_CHART_AXIS_PRIMARY_Y);
    //     empty_graph_series = 1;
    //   lv_chart_refresh(ui_HistoryChart);
    // }
    double max_value = find_max_value(histroy_data, HISTORY_WINDOW_SIZE);
    lv_chart_set_range(ui_HistoryChart, LV_CHART_AXIS_PRIMARY_Y, 0, (max_value * 100.0) + 10);
    for (int i = 0; i < HISTORY_WINDOW_SIZE; i++)
    {
      lv_chart_set_next_value(ui_HistoryChart, data_series, histroy_data[i] * 100.0);
    }
  }
}

void update_general_settings_screen()
{
  if (lv_scr_act() == ui_GeneralSettings)
  {
    if (get_clicker_enabled() && !lv_obj_has_state(ui_ClickerSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_ClickerSwitch, LV_STATE_CHECKED);
    }
    else if (!get_clicker_enabled() && lv_obj_has_state(ui_ClickerSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_ClickerSwitch, LV_STATE_CHECKED);
    }

    if (get_alarm_enabled() && !lv_obj_has_state(ui_AlarmSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_AlarmSwitch, LV_STATE_CHECKED);
    }
    else if (!get_alarm_enabled() && lv_obj_has_state(ui_AlarmSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_AlarmSwitch, LV_STATE_CHECKED);
    }

    lv_spinbox_set_value(ui_AlarmThresholdInp, get_alarm_threshold() * 100);
    lv_spinbox_set_value(ui_TimeZoneOffsetInpH, get_timezone_h());
    lv_spinbox_set_value(ui_TimeZoneOffsetInpM, get_timezone_m());
  }
}

void update_measurement_settings_screen()
{
  if (lv_scr_act() == ui_MeasurementSettings)
  {
    lv_spinbox_set_value(ui_WindowSizeInp, get_measurement_window_size());
    lv_spinbox_set_value(ui_SamplingPeriodInp, get_measurement_update_period());
    if (get_wake_enabled() && !lv_obj_has_state(ui_WakeEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_WakeEnSwitch, LV_STATE_CHECKED);
    }
    else if (!get_wake_enabled() && lv_obj_has_state(ui_WakeEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_WakeEnSwitch, LV_STATE_CHECKED);
    }
    lv_dropdown_set_selected(ui_WakeEveryDrop, get_wake_every_choice());
    lv_dropdown_set_selected(ui_WakeSampleDrop, get_wake_sample_choice());
  }
}

void update_display_settings_screen()
{
  if (lv_scr_act() == ui_DisplaySettings)
  {
    lv_slider_set_value(ui_BrightnessSlider, get_screen_brightness(), LV_ANIM_OFF);
  }
}

void update_advanced_settings_screen()
{
  if (lv_scr_act() == ui_AdvancedSettings)
  {
    lv_spinbox_set_value(ui_TubeVoltageInp, get_tube_voltage_level());
    lv_spinbox_set_value(ui_ConversionRateInp, get_conversion_rate() * 1000);
  }
}

void update_connectivity_settings_screen()
{
  if (lv_scr_act() == ui_ConnectivitySettings)
  {
    if (get_wifi_enabled() && !lv_obj_has_state(ui_WifiEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_WifiEnSwitch, LV_STATE_CHECKED);
    }
    else if (!get_wifi_enabled() && lv_obj_has_state(ui_WifiEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_WifiEnSwitch, LV_STATE_CHECKED);
    }
    if (get_wifi_ap_enabled())
    {
      lv_label_set_text(ui_WifiSSIDDisp, DEFAULT_WIFI_AP_SSID);
      lv_label_set_text(ui_WifiRSSILabel, "Pass:");
      lv_label_set_text(ui_WifiRSSIDisp, DEFAULT_WIFI_AP_PASS);
      lv_label_set_text(ui_WifiIPDisp, "N/A");
    }
    else
    {
      lv_label_set_text(ui_WifiSSIDDisp, get_ssid_name());
      lv_label_set_text(ui_WifiRSSILabel, "Signal Strength");
      lv_label_set_text_fmt(ui_WifiRSSIDisp, "%ddBm", get_rssi_value());
      lv_label_set_text(ui_WifiIPDisp, get_local_ip_addr());
    }
    if (get_wifi_ap_enabled() && !lv_obj_has_state(ui_WifiAPEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_WifiAPEnSwitch, LV_STATE_CHECKED);
    }
    else if (!get_wifi_ap_enabled() && lv_obj_has_state(ui_WifiAPEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_WifiAPEnSwitch, LV_STATE_CHECKED);
    }
    if (get_mqtt_enabled() && !lv_obj_has_state(ui_MqttEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_add_state(ui_MqttEnSwitch, LV_STATE_CHECKED);
    }
    else if (!get_mqtt_enabled() && lv_obj_has_state(ui_MqttEnSwitch, LV_STATE_CHECKED))
    {
      lv_obj_clear_state(ui_MqttEnSwitch, LV_STATE_CHECKED);
    }
    if (get_wifi_enabled())
    {
      show_object(ui_WifiSSIDPanel);
      show_object(ui_WifiRSSIPanel);
      show_object(ui_WifiIPPanel);
      show_object(ui_WifiAPEnPanel);
      show_object(ui_MqttEnPanel);
      show_object(ui_MqttStatePanel);
    }
    else
    {
      hide_object(ui_WifiSSIDPanel);
      hide_object(ui_WifiRSSIPanel);
      hide_object(ui_WifiIPPanel);
      hide_object(ui_WifiAPEnPanel);
      hide_object(ui_MqttEnPanel);
      hide_object(ui_MqttStatePanel);
    }

    switch (mqtt_state())
    {
    case MQTT_CONNECTION_TIMEOUT:
      lv_label_set_text(ui_MqttStateDisp, "Connection Timeout");
      break;
    case MQTT_CONNECTION_LOST:
      lv_label_set_text(ui_MqttStateDisp, "Connection Lost");
      break;
    case MQTT_CONNECT_FAILED:
      lv_label_set_text(ui_MqttStateDisp, "Connection Failed");
      break;
    case MQTT_DISCONNECTED:
      lv_label_set_text(ui_MqttStateDisp, "Disconnected");
      break;
    case MQTT_CONNECTED:
      lv_label_set_text(ui_MqttStateDisp, "Connected");
      break;
    case MQTT_CONNECT_BAD_PROTOCOL:
      lv_label_set_text(ui_MqttStateDisp, "Bad Protocol");
      break;
    case MQTT_CONNECT_BAD_CLIENT_ID:
      lv_label_set_text(ui_MqttStateDisp, "Bad Client ID");
      break;
    case MQTT_CONNECT_UNAVAILABLE:
      lv_label_set_text(ui_MqttStateDisp, "Connect Unavailable");
      break;
    case MQTT_CONNECT_BAD_CREDENTIALS:
      lv_label_set_text(ui_MqttStateDisp, "Bad Credentials");
      break;
    case MQTT_CONNECT_UNAUTHORIZED:
      lv_label_set_text(ui_MqttStateDisp, "Unauthorized");
      break;
    default:
      lv_label_set_text(ui_MqttStateDisp, "Unknown State");
      break;
    }
  }
}

void update_history_page()
{
  if (lv_scr_act() == ui_History)
  {
    update_graph_page();
  }
}

void update_monitoring_page()
{
  if (lv_scr_act() == ui_Home)
  {
    int cpm = get_cpm();
    double usv = get_usv();
    double cdose = get_dose();
    update_main_page_objects(usv, cpm, cdose);
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo, 100))
    {
    }
    else
    {
      lv_label_set_text_fmt(ui_TimeDisp, "%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min);
    }
  }
}

void update_screens()
{
  update_monitoring_page();
  update_general_settings_screen();
  update_measurement_settings_screen();
  update_display_settings_screen();
  update_advanced_settings_screen();
  update_connectivity_settings_screen();
  update_history_page();
}

void periodically_update_screens(lv_timer_t *timer)
{
  update_monitoring_page();
  update_connectivity_settings_screen();
  update_history_page();
}

void gui_init()
{

  nav_buttons_init();

  lv_init();

  lv_log_register_print_cb(my_log_cb);

  tft.begin();        // TFT init
  tft.setRotation(1); // Landscape orientation, flipped

  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

  // Initialize the display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  // Set display resolution
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  // Initiliaze lvgl driver
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_ENCODER;
  indev_drv.read_cb = key_input_driver;
  indev_drv.long_press_repeat_time = 0;
  indev_drv.long_press_time = DEFAULT_LONG_PRESS_TIME; // how long for long press.
  indev = lv_indev_drv_register(&indev_drv);
  static lv_group_t *group_ = lv_group_create();
  lv_group_set_default(group_);
  lv_indev_set_group(indev, group_);

  ui_init();
  gui_enable_input(0); // Disable input on initialization to prevent accidental input
  lv_timer_t *screenRefresher = lv_timer_create(periodically_update_screens, 500, NULL);
}