#ifndef HARDWARE_H
#define HARDWARE_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define BL_PIN 4

#define UP_BUTTON_PIN 13
#define DOWN_BUTTON_PIN 2
#define OK_BUTTON_PIN 15
#define WAKEUP_GPIO_NUM GPIO_NUM_15

#define BUZZER_PIN 26

#define TUBE_DETECT_PIN 27
#define TUBE_HV_PIN 33
#define TUBE_HV_FREQ 6000
#define TUBE_HV_DEF_DUTY 85

#define BAT_ADC_PIN 34
#define BAT_ADC_CONV_RATE 1.8
#define BAT_AVG_SAMPLES 20
#define BAT_ADC_SMOOTHING_FACTOR 0.05
#define MIN_USB_VOLAGE 4.4
#define BAT_VOLTAGE_OFFSET 0.035

void nav_buttons_init();

void geiger_tube_init();

EXTERNC void set_tube_voltage(unsigned char level);
EXTERNC void turn_display_off();
EXTERNC void turn_display_on();
EXTERNC void gui_enable_input(bool en);
EXTERNC void enter_deep_sleep();
void enable_wakeup_timer(int ms);
void disable_wakeup_timer();
void wakeup_handler();
void hardware_init();
void sound_alarm();
int get_bat_charge_lvl();
void clicker();
EXTERNC void apply_screen_brightness(int val);

#undef EXTERNC
#endif // GUI_H