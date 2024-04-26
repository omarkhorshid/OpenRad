#include "settings.h"
#include <Preferences.h>

Preferences preferences;

unsigned char screen_brightness = DEFAULT_SCREEN_BRIGHTNESS;
bool clicker_enabled = DEFAULT_CLICKER_ENABLED;
int measurement_window_size = DEFAULT_MEASUREMENT_WINDOW_SIZE;
int measurement_update_period = DEFAULT_MEASUREMENT_UPDATE_PERIOD;
bool alarm_enabled = DEFAULT_ALARM_ENABLED;
double alarm_threshold = DEFAULT_ALARM_THRESHOLD;
bool sleep_wake_enabled = DEFAULT_SLEEP_WAKE_ENABLED;
unsigned char sleep_wake_period_choice = DEFAULT_SLEEP_WAKE_PEROID_choice;
unsigned char sleep_wake_sample_time_choice = DEFAULT_SLEEP_WAKE_SAMPLE_TIME_choice;
unsigned char tube_voltage_level = DEFAULT_TUBE_VOLTAGE_LEVEL;
double tube_conversion_rate = DEFAULT_CONVERSION_RATE;
int sleep_wake_every_value = 1 * 60 * 1000;
int sleep_wake_sample_window_value = 20;
int sleep_wake_sample_period_value = 250;
bool wifi_enabled = DEFAULT_WIFI_ENABLED;
bool wifi_ap_enabled = DEFAULT_WIFI_AP_ENABLED;
String wifi_sta_ssid = "";
String wifi_sta_pass = "";
bool mqtt_enabled = DEFAULT_MQTT_ENABLED;
String mqtt_host = "";
int mqtt_port = 1883;
String mqtt_client_id = "";
String mqtt_username = "";
String mqtt_password = "";
String mqtt_doserate_topic = "";
String mqtt_dose_topic = "";
int timezone_offset_h = DEFAULT_TIMEZONE_OFFSET_H;
int timezone_offset_m = DEFAULT_TIMEZONE_OFFSET_M;

double d_dose = 0;

void calc_wake_every_value();
void calc_wake_sample_value();

void load_settings()
{
    preferences.begin("openrad", false);
    screen_brightness = preferences.getUChar("scr_brightness", DEFAULT_SCREEN_BRIGHTNESS);
    clicker_enabled = preferences.getBool("clicker_enabled", DEFAULT_CLICKER_ENABLED);
    measurement_window_size = preferences.getInt("m_window_size", DEFAULT_MEASUREMENT_WINDOW_SIZE);
    measurement_update_period = preferences.getInt("m_update_period", DEFAULT_MEASUREMENT_UPDATE_PERIOD);
    alarm_enabled = preferences.getBool("g_alarm_enabled", DEFAULT_ALARM_ENABLED);
    alarm_threshold = preferences.getDouble("g_alarm_thr", DEFAULT_ALARM_THRESHOLD);
    d_dose = preferences.getDouble("d_dose", 0);
    sleep_wake_enabled = preferences.getBool("m_wake_en", DEFAULT_SLEEP_WAKE_ENABLED);
    sleep_wake_period_choice = preferences.getUChar("m_wake_every_c", DEFAULT_SLEEP_WAKE_PEROID_choice);
    sleep_wake_sample_time_choice = preferences.getUChar("m_wake_sample_c", DEFAULT_SLEEP_WAKE_SAMPLE_TIME_choice);
    tube_voltage_level = preferences.getUChar("a_tube_v_level", DEFAULT_TUBE_VOLTAGE_LEVEL);
    tube_conversion_rate = preferences.getDouble("a_conv_rate", DEFAULT_CONVERSION_RATE);
    wifi_enabled = preferences.getBool("c_wifi_en", DEFAULT_WIFI_ENABLED);
    wifi_ap_enabled = preferences.getBool("c_wifi_ap_en", DEFAULT_WIFI_AP_ENABLED);
    wifi_sta_ssid = preferences.getString("c_wifi_ssid", "");
    wifi_sta_pass = preferences.getString("c_wifi_pass", "");
    mqtt_enabled = preferences.getBool("mqtt_en", DEFAULT_MQTT_ENABLED);
    mqtt_host = preferences.getString("mqtt_host", "");
    mqtt_port = preferences.getInt("mqtt_port", 1883);
    mqtt_client_id = preferences.getString("mqtt_client", "");
    mqtt_username = preferences.getString("mqtt_user", "");
    mqtt_password = preferences.getString("mqtt_passwd", "");
    mqtt_doserate_topic = preferences.getString("mqtt_dr_topic", "");
    mqtt_dose_topic = preferences.getString("mqtt_d_topic", "");
    timezone_offset_h = preferences.getInt("timezone_h", DEFAULT_TIMEZONE_OFFSET_H);
    timezone_offset_m = preferences.getInt("timezone_m", DEFAULT_TIMEZONE_OFFSET_M);

    calc_wake_sample_value();
    calc_wake_every_value();
}

void factory_reset()
{
    preferences.clear();
    screen_brightness = DEFAULT_SCREEN_BRIGHTNESS;
    clicker_enabled = DEFAULT_CLICKER_ENABLED;
    measurement_window_size = DEFAULT_MEASUREMENT_WINDOW_SIZE;
    measurement_update_period = DEFAULT_MEASUREMENT_UPDATE_PERIOD;
    alarm_enabled = DEFAULT_ALARM_ENABLED;
    alarm_threshold = DEFAULT_ALARM_THRESHOLD;
    tube_voltage_level = DEFAULT_TUBE_VOLTAGE_LEVEL;
    tube_conversion_rate = DEFAULT_CONVERSION_RATE;
    wifi_enabled = DEFAULT_WIFI_ENABLED;
    wifi_ap_enabled = DEFAULT_WIFI_AP_ENABLED;
    wifi_sta_ssid = "";
    wifi_sta_pass = "";
    mqtt_enabled = DEFAULT_MQTT_ENABLED;
    mqtt_host = "";
    mqtt_port = 1883;
    mqtt_client_id = "";
    mqtt_username = "";
    mqtt_password = "";
    mqtt_doserate_topic = "";
    mqtt_dose_topic = "";
    timezone_offset_h = DEFAULT_TIMEZONE_OFFSET_H;
    timezone_offset_m = DEFAULT_TIMEZONE_OFFSET_M;
    preferences.putUChar("scr_brightness", DEFAULT_SCREEN_BRIGHTNESS);
    preferences.putBool("clicker_enabled", DEFAULT_CLICKER_ENABLED);
    preferences.putInt("m_window_size", DEFAULT_MEASUREMENT_WINDOW_SIZE);
    preferences.putInt("m_update_period", DEFAULT_MEASUREMENT_UPDATE_PERIOD);
    preferences.putBool("g_alarm_enabled", DEFAULT_ALARM_ENABLED);
    preferences.putDouble("g_alarm_thr", DEFAULT_ALARM_THRESHOLD);
    preferences.putBool("m_wake_en", DEFAULT_SLEEP_WAKE_ENABLED);
    preferences.putUChar("m_wake_every_c", DEFAULT_SLEEP_WAKE_PEROID_choice);
    preferences.putUChar("m_wake_sample_c", DEFAULT_SLEEP_WAKE_SAMPLE_TIME_choice);
    preferences.putUChar("a_tube_v_level", DEFAULT_TUBE_VOLTAGE_LEVEL);
    preferences.putDouble("a_conv_rate", DEFAULT_CONVERSION_RATE);
    preferences.putBool("c_wifi_en", DEFAULT_WIFI_ENABLED);
    preferences.putBool("c_wifi_ap_en", DEFAULT_WIFI_AP_ENABLED);
    preferences.putString("c_wifi_ssid", "");
    preferences.putString("c_wifi_pass", "");
    preferences.putBool("mqtt_en", DEFAULT_MQTT_ENABLED);
    preferences.putString("mqtt_host", "");
    preferences.putInt("mqtt_port", 1883);
    preferences.putString("mqtt_client", "");
    preferences.putString("mqtt_user", "");
    preferences.putString("mqtt_passwd", "");
    preferences.putString("mqtt_dr_topic", "");
    preferences.putString("mqtt_d_topic", "");
    preferences.putInt("timezone_h", DEFAULT_TIMEZONE_OFFSET_H);
    preferences.putInt("timezone_m", DEFAULT_TIMEZONE_OFFSET_M);
    calc_wake_sample_value();
    calc_wake_every_value();
}

bool get_clicker_enabled()
{
    // clicker_enabled = preferences.getInt("clicker_enabled",DEFAULT_CLICKER_ENABLED);
    return clicker_enabled;
}

void set_clicker_enabled(bool val)
{
    clicker_enabled = val;
    preferences.putBool("clicker_enabled", val);
}

bool get_alarm_enabled()
{
    return alarm_enabled;
}

void set_alarm_enabled(bool val)
{
    alarm_enabled = val;
    preferences.putBool("g_alarm_enabled", val);
}

double get_alarm_threshold()
{
    return alarm_threshold;
}

void set_alarm_threshold(double threshold)
{
    alarm_threshold = threshold;
    preferences.putDouble("g_alarm_thr", threshold);
}

void get_measurement_settings(int *window_size, int *update_period)
{
    measurement_window_size = preferences.getInt("m_window_size", DEFAULT_MEASUREMENT_WINDOW_SIZE);
    measurement_update_period = preferences.getInt("m_update_period", DEFAULT_MEASUREMENT_UPDATE_PERIOD);
    *window_size = measurement_window_size;
    *update_period = measurement_update_period;
}

int get_measurement_window_size()
{
    // measurement_window_size = preferences.getInt("m_window_size",DEFAULT_MEASUREMENT_WINDOW_SIZE);
    return measurement_window_size;
}

int get_measurement_update_period()
{
    // measurement_update_period = preferences.getInt("m_update_period",DEFAULT_MEASUREMENT_UPDATE_PERIOD);
    return measurement_update_period;
}

void set_measurement_window_size(int val)
{
    measurement_window_size = val;
    preferences.putInt("m_window_size", val);
}

void set_measurement_update_period(int val)
{
    measurement_update_period = val;
    preferences.putInt("m_update_period", val);
}

unsigned char get_screen_brightness()
{
    return screen_brightness;
}

void set_screen_brightness(unsigned char val)
{
    screen_brightness = val;
    preferences.putUChar("scr_brightness", val);
}

void set_ddose(double dose)
{
    preferences.putDouble("d_dose", dose);
    d_dose = dose;
}

double get_ddose()
{
    return d_dose;
}

void reset_ddose()
{
    preferences.putDouble("d_dose", 0);
    d_dose = 0;
}

bool get_wake_enabled()
{
    return sleep_wake_enabled;
}

void set_wake_enabled(bool en)
{
    sleep_wake_enabled = en;
    preferences.putBool("m_wake_en", en);
}

unsigned char get_wake_every_choice()
{
    return sleep_wake_period_choice;
}

void set_wake_every_choice(unsigned char choice)
{
    sleep_wake_period_choice = choice;
    preferences.putUChar("m_wake_every_c", choice);
    calc_wake_every_value();
}

unsigned char get_wake_sample_choice()
{
    return sleep_wake_sample_time_choice;
}

void set_wake_sample_choice(unsigned char choice)
{
    sleep_wake_sample_time_choice = choice;
    preferences.putUChar("m_wake_sample_c", choice);
    calc_wake_sample_value();
}

void calc_wake_every_value()
{

    switch (get_wake_every_choice())
    {
    case 0: // 10s
        sleep_wake_every_value = 10 * 1000;
        break;
    case 1: // 30s
        sleep_wake_every_value = 30 * 1000;
        break;
    case 2: // 1min
        sleep_wake_every_value = 1 * 60 * 1000;
        break;
    case 3: // 5min
        sleep_wake_every_value = 5 * 60 * 1000;
        break;
    case 4: // 10min
        sleep_wake_every_value = 10 * 60 * 1000;
        break;
    case 5: // 15min
        sleep_wake_every_value = 15 * 60 * 1000;
        break;
    case 6: // 30min
        sleep_wake_every_value = 30 * 60 * 1000;
        break;
    case 7: // 1hr
        sleep_wake_every_value = 60 * 60 * 1000;
        break;
    default:
        break;
    }
}

void calc_wake_sample_value()
{

    switch (get_wake_sample_choice())
    {
    case 0: // 1s
        sleep_wake_sample_window_value = 4;
        sleep_wake_sample_period_value = 250;
        break;
    case 1: // 5s
        sleep_wake_sample_window_value = 20;
        sleep_wake_sample_period_value = 250;
        break;
    case 2: // 10s
        sleep_wake_sample_window_value = 20;
        sleep_wake_sample_period_value = 500;
        break;
    case 3: // 15s
        sleep_wake_sample_window_value = 15;
        sleep_wake_sample_period_value = 1000;
        break;
    case 4: // 30s
        sleep_wake_sample_window_value = 30;
        sleep_wake_sample_period_value = 1000;
        break;
    case 5: // 1min
        sleep_wake_sample_window_value = 60;
        sleep_wake_sample_period_value = 1000;
        break;
    case 6: // 2min
        sleep_wake_sample_window_value = 60;
        sleep_wake_sample_period_value = 2000;
        break;
    case 7: // 5min
        sleep_wake_sample_window_value = 150;
        sleep_wake_sample_period_value = 2000;
        break;
    default:
        break;
    }
}

int get_wakeup_every()
{
    return sleep_wake_every_value;
}

int get_wakeup_window()
{
    return sleep_wake_sample_window_value;
}

int get_wakeup_period()
{
    return sleep_wake_sample_period_value;
}

unsigned char get_tube_voltage_level()
{
    return tube_voltage_level;
}

void set_tube_voltage_level(unsigned char lvl)
{
    preferences.putUChar("a_tube_v_level", lvl);
    tube_voltage_level = lvl;
}

double get_conversion_rate()
{
    return tube_conversion_rate;
}

void set_conversion_rate(double val)
{
    preferences.putDouble("a_conv_rate", val);
    tube_conversion_rate = val;
}

bool get_wifi_enabled()
{
    return wifi_enabled;
}

void set_wifi_enabled(bool val)
{
    preferences.putBool("c_wifi_en", val);
    wifi_enabled = val;
}

bool get_wifi_ap_enabled()
{
    return wifi_ap_enabled;
}

void set_wifi_ap_enabled(bool val)
{
    preferences.putBool("c_wifi_ap_en", val);
    wifi_ap_enabled = val;
}

char *get_wifi_sta_ssid()
{
    // char *ssid = (char*)malloc(33*sizeof(char));
    // strcpy(ssid, wifi_sta_ssid.c_str());
    // return ssid;
    return (char *)wifi_sta_ssid.c_str();
}

char *get_wifi_sta_pass()
{
    return (char *)wifi_sta_pass.c_str();
}

void set_wifi_sta_ssid(char *ssid)
{
    preferences.putString("c_wifi_ssid", ssid);
    wifi_sta_ssid = ssid;
}

void set_wifi_sta_pass(char *pass)
{
    preferences.putString("c_wifi_pass", pass);
    wifi_sta_pass = pass;
}

bool get_mqtt_enabled()
{
    return mqtt_enabled;
}

char *get_mqtt_host()
{
    return (char *)mqtt_host.c_str();
}

int get_mqtt_port()
{
    return mqtt_port;
}

char *get_mqtt_client_id()
{
    return (char *)mqtt_client_id.c_str();
}

char *get_mqtt_username()
{
    return (char *)mqtt_username.c_str();
}

char *get_mqtt_password()
{
    return (char *)mqtt_password.c_str();
}

char *get_mqtt_doserate_topic()
{
    return (char *)mqtt_doserate_topic.c_str();
}

char *get_mqtt_dose_topic()
{
    return (char *)mqtt_dose_topic.c_str();
}

void set_mqtt_enabled(bool en)
{
    preferences.putBool("mqtt_en", en);
    mqtt_enabled = en;
}

void set_mqtt_port(int port)
{
    preferences.putInt("mqtt_port", port);
    mqtt_port = port;
}

void set_mqtt_host(char *host)
{
    preferences.putString("mqtt_host", host);
    mqtt_host = host;
}

void set_mqtt_client_id(char *client_id)
{
    preferences.putString("mqtt_client", client_id);
    mqtt_client_id = client_id;
}

void set_mqtt_username(char *username)
{
    preferences.putString("mqtt_user", username);
    mqtt_username = username;
}

void set_mqtt_password(char *password)
{
    preferences.putString("mqtt_passwd", password);
    mqtt_password = password;
}

void set_mqtt_doserate_topic(char *topic)
{
    preferences.putString("mqtt_dr_topic", topic);
    mqtt_doserate_topic = topic;
}

void set_mqtt_dose_topic(char *topic)
{
    preferences.putString("mqtt_d_topic", topic);
    mqtt_dose_topic = topic;
}

int get_timezone_h()
{
    return timezone_offset_h;
}

int get_timezone_m()
{
    return timezone_offset_m;
}

void set_timezone_h(int val)
{
    preferences.putInt("timezone_h", val);
    timezone_offset_h = val;
}

void set_timezone_m(int val)
{
    preferences.putInt("timezone_m", val);
    timezone_offset_m = val;
}

int get_timezone_offset_seconds()
{
    return (timezone_offset_h * 3600) + (timezone_offset_m * 60);
}