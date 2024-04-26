#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define MQTT_CONNECTION_TIMEOUT -4
#define MQTT_CONNECTION_LOST -3
#define MQTT_CONNECT_FAILED -2
#define MQTT_DISCONNECTED -1
#define MQTT_CONNECTED 0
#define MQTT_CONNECT_BAD_PROTOCOL 1
#define MQTT_CONNECT_BAD_CLIENT_ID 2
#define MQTT_CONNECT_UNAVAILABLE 3
#define MQTT_CONNECT_BAD_CREDENTIALS 4
#define MQTT_CONNECT_UNAUTHORIZED 5

void connectivity_init();
EXTERNC char *get_ssid_name();
EXTERNC long get_rssi_value();
EXTERNC char *get_local_ip_addr();
EXTERNC void disable_wifi();
EXTERNC void enable_wifi_sta();
EXTERNC void enable_wifi_ap();
EXTERNC void enable_wifi();
EXTERNC void mqtt_disconnect();
EXTERNC int mqtt_state();
void mqtt_loop();

#undef EXTERNC
#endif