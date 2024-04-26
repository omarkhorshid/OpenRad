#ifndef SETTINGS_H
#define SETTINGS_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define DEFAULT_SCREEN_BRIGHTNESS 5
#define DEFAULT_CLICKER_ENABLED 1
#define DEFAULT_MEASUREMENT_WINDOW_SIZE 40
#define DEFAULT_MEASUREMENT_UPDATE_PERIOD 250
#define DEFAULT_PRIMARY_UNIT 0
#define DEFAULT_PRIMARY_MULTIPLIER 0
#define DEFAULT_SECONDARY_UNIT 0
#define DEFAULT_SECONDARY_MULTIPLIER 0
#define DEFAULT_LONG_PRESS_TIME 1000
#define DEFAULT_ALARM_ENABLED 0
#define DEFAULT_ALARM_THRESHOLD 1.0
#define DEFAULT_SLEEP_WAKE_ENABLED 0
#define DEFAULT_SLEEP_WAKE_PEROID_choice 2
#define DEFAULT_SLEEP_WAKE_SAMPLE_TIME_choice 1
#define DEFAULT_TUBE_VOLTAGE_LEVEL 80
#define DEFAULT_WIFI_ENABLED 0
#define DEFAULT_WIFI_AP_ENABLED 1
#define DEFAULT_MQTT_ENABLED 0
#define DEFAULT_TIMEZONE_OFFSET_H 0
#define DEFAULT_TIMEZONE_OFFSET_M 0
#define DEFAULT_CONVERSION_RATE 150.510

#define HISTORY_WINDOW_SIZE 20

#define DEFAULT_WIFI_AP_SSID "OpenRAD V1"
#define DEFAULT_WIFI_AP_PASS "OpenradConfigAdmin"

void load_settings();
EXTERNC void factory_reset();
EXTERNC bool get_clicker_enabled();
EXTERNC void set_clicker_enabled(bool val);
EXTERNC bool get_alarm_enabled();
EXTERNC void set_alarm_enabled(bool val);
EXTERNC double get_alarm_threshold();
EXTERNC void set_alarm_threshold(double threshold);
EXTERNC void get_measurement_settings(int *window_size, int *update_period);
EXTERNC void set_measurement_update_period(int val);
EXTERNC void set_measurement_window_size(int val);
EXTERNC int get_measurement_update_period();
EXTERNC int get_measurement_window_size();
EXTERNC unsigned char get_screen_brightness();
EXTERNC void set_screen_brightness(unsigned char val);
EXTERNC void set_ddose(double dose);
EXTERNC double get_ddose();
EXTERNC void reset_ddose();
EXTERNC bool get_wake_enabled();
EXTERNC void set_wake_enabled(bool en);
EXTERNC unsigned char get_wake_every_choice();
EXTERNC void set_wake_every_choice(unsigned char choice);
EXTERNC unsigned char get_wake_sample_choice();
EXTERNC void set_wake_sample_choice(unsigned char choice);
EXTERNC int get_wakeup_period();
EXTERNC int get_wakeup_window();
EXTERNC int get_wakeup_every();
EXTERNC void set_tube_voltage_level(unsigned char lvl);
EXTERNC unsigned char get_tube_voltage_level();
EXTERNC double get_conversion_rate();
EXTERNC void set_conversion_rate(double val);
EXTERNC bool get_wifi_enabled();
EXTERNC void set_wifi_enabled(bool val);
EXTERNC bool get_wifi_ap_enabled();
EXTERNC void set_wifi_ap_enabled(bool val);
EXTERNC char *get_wifi_sta_ssid();
EXTERNC char *get_wifi_sta_pass();
EXTERNC void set_wifi_sta_ssid(char *ssid);
EXTERNC void set_wifi_sta_pass(char *pass);
EXTERNC bool get_mqtt_enabled();
EXTERNC char *get_mqtt_host();
EXTERNC int get_mqtt_port();
EXTERNC char *get_mqtt_client_id();
EXTERNC char *get_mqtt_username();
EXTERNC char *get_mqtt_password();
EXTERNC char *get_mqtt_doserate_topic();
EXTERNC char *get_mqtt_dose_topic();
EXTERNC void set_mqtt_enabled(bool en);
EXTERNC void set_mqtt_port(int port);
EXTERNC void set_mqtt_host(char *host);
EXTERNC void set_mqtt_client_id(char *client_id);
EXTERNC void set_mqtt_username(char *username);
EXTERNC void set_mqtt_password(char *password);
EXTERNC void set_mqtt_doserate_topic(char *topic);
EXTERNC void set_mqtt_dose_topic(char *topic);
EXTERNC int get_timezone_h();
EXTERNC int get_timezone_m();
EXTERNC void set_timezone_h(int val);
EXTERNC void set_timezone_m(int val);
EXTERNC int get_timezone_offset_seconds();

#undef EXTERNC
#endif