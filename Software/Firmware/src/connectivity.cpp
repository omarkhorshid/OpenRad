#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "connectivity.h"
#include "settings.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include "geiger.h"
#include <string.h>
#include "time.h"
#include "hardware.h"

AsyncWebServer server(80);

AsyncWebSocket ws("/ws");

WiFiClient espClient;
PubSubClient client(espClient);

JsonDocument deserializeData(AsyncWebServerRequest *request, uint8_t *data)
{
    JsonDocument doc;
    doc.clear();
    DeserializationError error = deserializeJson(doc, (const char *)data, request->contentLength());
    if (error)
    {
        request->send(400, "application/json", "{\"error\":\"Couldn't Parse the request content.\"}");
        doc.clear();
    }
    return doc;
}

void wifi_settings_request_handler(AsyncWebServerRequest *request, uint8_t *data)
{
    JsonDocument obj = deserializeData(request, data);
    const char *ssid = obj["ssid"];
    const char *pass = obj["password"];
    set_wifi_sta_ssid((char *)ssid);
    set_wifi_sta_pass((char *)pass);
}

int mqtt_connect(const char *mqtt_client_id, const char *mqtt_username, const char *mqtt_password)
{
    if (!client.connected())
    {
        if (client.connect(mqtt_client_id, mqtt_username, mqtt_password))
        {
        }
    }
    return client.state();
}

void mqtt_disconnect()
{
    client.disconnect();
}

int mqtt_state()
{
    return client.state();
}

void mqtt_settings_request_handler(AsyncWebServerRequest *request, uint8_t *data)
{
    JsonDocument obj = deserializeData(request, data);
    const char *mqtt_host = obj["broker"];
    int mqtt_port = atoi(obj["port"]);
    const char *mqtt_username = obj["username"];
    const char *mqtt_password = obj["password"];
    const char *mqtt_client_id = obj["clientId"];
    const char *mqtt_doserate_topic = obj["doseTopic"];
    const char *mqtt_dose_topic = obj["totalDoseTopic"];
    set_mqtt_host((char *)mqtt_host);
    set_mqtt_port(mqtt_port);
    set_mqtt_username((char *)mqtt_username);
    set_mqtt_password((char *)mqtt_password);
    set_mqtt_client_id((char *)mqtt_client_id);
    set_mqtt_doserate_topic((char *)mqtt_doserate_topic);
    set_mqtt_dose_topic((char *)mqtt_dose_topic);
    mqtt_disconnect();
    client.setServer(get_mqtt_host(), get_mqtt_port());
}

void set_settings_request_handler(AsyncWebServerRequest *request, uint8_t *data)
{
    JsonDocument obj = deserializeData(request, data);
    bool clicker_en = obj["generalSettings"]["clicker"];
    bool alarm_en = obj["generalSettings"]["alarm"];
    double alarm_thr = obj["generalSettings"]["alarmThr"];
    int screen_brightness = obj["displaySettings"]["brightness"];
    int window_size = obj["measurementSettings"]["windowSize"];
    int sample_period = obj["measurementSettings"]["samplingPeriod"];
    set_clicker_enabled(clicker_en);
    set_alarm_enabled(alarm_en);
    set_alarm_threshold(alarm_thr);
    set_screen_brightness(screen_brightness);
    set_measurement_window_size(window_size);
    set_measurement_update_period(sample_period);
    apply_screen_brightness(screen_brightness);
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    switch (type)
    {
    case WS_EVT_CONNECT:
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
    case WS_EVT_DISCONNECT:
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
    case WS_EVT_DATA:
        //   handleWebSocketMessage(arg, data, len);
        break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
        break;
    }
}

void websocket_init()
{
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}

void list_available_networks_handler(AsyncWebServerRequest *request)
{
    JsonDocument doc;
    // Create JSON document
    doc.clear();
    JsonArray networks = doc["networks"].to<JsonArray>();

    int numNetworks = WiFi.scanComplete();
    if (numNetworks == -1)
    {
        Serial.println("Scanning failed!");
        request->send(500, "text/plain", "Scanning failed!");
        return;
    }

    // Loop through scanned networks and add them to the JSON array
    for (int i = 0; i < numNetworks; i++)
    {
        JsonObject network = networks.add<JsonObject>();
        network["ssid"] = WiFi.SSID(i);
        network["bssid"] = WiFi.BSSIDstr(i);
        // network["channel"] = WiFi.channel(i);
        network["rssi"] = WiFi.RSSI(i);
        // network["encryption"] = WiFi.encryptionType(i);
    }
    char data[4096];
    // Send JSON response
    serializeJson(doc, data);
    request->send(200, "application/json", data);
    WiFi.scanNetworks(true);
}

int mqtt_connection_check_millis = 0;
void mqtt_loop()
{
    if (get_wifi_enabled() && get_mqtt_enabled())
    {
        if ((millis() - mqtt_connection_check_millis) > 500)
        {
            if (!client.connected())
            {
                mqtt_connect(get_mqtt_client_id(), get_mqtt_username(), get_mqtt_password());
            }
            else
            {
                String dr_payload = String(get_usv(), 4);
                client.publish(get_mqtt_doserate_topic(), dr_payload.c_str());
                String d_payload = String(get_dose(), 4);
                client.publish(get_mqtt_dose_topic(), d_payload.c_str());
            }
            mqtt_connection_check_millis = millis();
        }
        client.loop();
    }
}

JsonDocument doc;
int ws_connection_check_millis = 0;
void ws_loop()
{
    if (get_wifi_enabled() && (ws.getClients().length()))
    {
        if ((millis() - ws_connection_check_millis) > 500)
        {
            struct tm timeInfo;
            getLocalTime(&timeInfo, 100);
            char formattedTime[24];
            strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", &timeInfo);
            doc["time"] = formattedTime;
            doc["uSv"] = get_usv();
            doc["total_uSv"] = get_dose();
            doc["CPM"] = get_cpm();
            doc["danger_threshold"] = get_alarm_threshold();
            doc["mqtt_status"] = mqtt_state();
            String jsonString;
            serializeJson(doc, jsonString);
            ws.textAll(jsonString);
            ws_connection_check_millis = millis();
            ws.cleanupClients();
        }
    }
}

void mqtt_task(void *pvParameters)
{
    while (1)
    {
        mqtt_loop();
        delay(1);
    }
}

void ws_task(void *pvParameters)
{
    while (1)
    {
        ws_loop();
        delay(1);
    }
}

void get_wifi_data_handler(AsyncWebServerRequest *request)
{
    JsonDocument data;
    data["ssid"] = get_wifi_sta_ssid();
    data["password"] = "**************";
    String jsonstr;
    serializeJson(data, jsonstr);
    request->send(200, "application/json", jsonstr);
}

void get_mqtt_data_handler(AsyncWebServerRequest *request)
{
    JsonDocument data;
    data["broker"] = get_mqtt_host();
    data["port"] = get_mqtt_port();
    data["username"] = get_mqtt_username();
    data["password"] = get_mqtt_password();
    data["clientId"] = get_mqtt_client_id();
    // data["rootTopic"] = get_mqtt
    data["doseTopic"] = get_mqtt_doserate_topic();
    data["totalDoseTopic"] = get_mqtt_dose_topic();
    String jsonstr;
    serializeJson(data, jsonstr);
    request->send(200, "application/json", jsonstr);
}

void get_settings_data_handler(AsyncWebServerRequest *request)
{
    JsonDocument data;
    data["generalSettings"].to<JsonObject>();
    data["generalSettings"]["clicker"] = get_clicker_enabled();
    data["generalSettings"]["alarm"] = get_alarm_enabled();
    data["generalSettings"]["alarmThr"] = get_alarm_threshold();
    data["displaySettings"].to<JsonObject>();
    data["displaySettings"]["brightness"] = get_screen_brightness();
    data["measurementSettings"].to<JsonObject>();
    data["measurementSettings"]["windowSize"] = get_measurement_window_size();
    data["measurementSettings"]["samplingPeriod"] = get_measurement_update_period();
    String jsonstr;
    serializeJson(data, jsonstr);
    request->send(200, "application/json", jsonstr);
}

void connectivity_init()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    //   while (WiFi.status() != WL_CONNECTED) {
    //     delay(1000);
    //     Serial.println("Connecting to WiFi...");
    //   }
    //   Serial.println("Connected to WiFi");

    //   // Print the ESP32's IP address
    //   Serial.print("ESP32 Web Server's IP address: ");
    //   Serial.println(WiFi.localIP());
    // Define a route to serve the HTML page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/index.html", String(), false); });

    server.on("/eye_closed.svg", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/eye_closed.svg", String(), false); });
    server.on("/eye_open.svg", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/eye_open.svg", String(), false); });
    server.on("/refresh.svg", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/refresh.svg", String(), false); });
    server.on("/chart.js", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/chart.js", String(), false); });

    server.on("/settings/wifi", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
              {
        wifi_settings_request_handler(request, data);
        request->send(200, "application/json", "{\"message\":\"OK\"}");
        delay(1000);
        enable_wifi_sta(); });

    server.on("/settings/wifi", HTTP_GET, [](AsyncWebServerRequest *request)
              { get_wifi_data_handler(request); });

    server.on("/settings/mqtt", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
              {
        mqtt_settings_request_handler(request, data);
        request->send(200, "application/json", "{\"message\":\"OK\"}"); });

    server.on("/settings/mqtt", HTTP_GET, [](AsyncWebServerRequest *request)
              { get_mqtt_data_handler(request); });

    server.on("/settings", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
              {
        set_settings_request_handler(request, data);
        request->send(200, "application/json", "{\"message\":\"OK\"}"); });

    server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request)
              { get_settings_data_handler(request); });

    server.on("/list-available-networks", HTTP_GET, [](AsyncWebServerRequest *request)
              { list_available_networks_handler(request); });

    if (get_wifi_enabled())
    {
        enable_wifi();
    }

    if (get_mqtt_enabled())
    {
        client.setServer(get_mqtt_host(), get_mqtt_port());
    }
    xTaskCreatePinnedToCore(mqtt_task, "mqtt_task", 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(ws_task, "ws_task", 4096, NULL, 1, NULL, 0);
    websocket_init();
}

char *get_ssid_name()
{
    char *ssid = (char *)malloc(33 * sizeof(char));
    if (WiFi.isConnected())
    {
        strcpy(ssid, WiFi.SSID().c_str());
        return ssid;
    }
    else
    {
        strcpy(ssid, "Not Connected");
        return ssid;
    }
}

long get_rssi_value()
{
    return WiFi.RSSI();
}

char *get_local_ip_addr()
{
    char *ipaddr = (char *)malloc(16 * sizeof(char));
    if (WiFi.isConnected())
    {
        strcpy(ipaddr, WiFi.localIP().toString().c_str());
        return ipaddr;
    }
    else
    {
        strcpy(ipaddr, "N/A");
        return ipaddr;
    }
}

void disable_wifi()
{
    server.end();
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);
}

void enable_wifi_sta()
{
    if (get_wifi_ap_enabled())
    {
        set_wifi_ap_enabled(0);
    }
    WiFi.mode(WIFI_STA);
    WiFi.begin(get_wifi_sta_ssid(), get_wifi_sta_pass());
}

void enable_wifi_ap()
{
    if (!get_wifi_ap_enabled())
    {
        set_wifi_ap_enabled(1);
    }
    WiFi.mode(WIFI_AP);
    WiFi.softAP(DEFAULT_WIFI_AP_SSID, DEFAULT_WIFI_AP_PASS);
}

void enable_wifi()
{
    if (get_wifi_ap_enabled())
    {
        enable_wifi_ap();
    }
    else
    {
        enable_wifi_sta();
    }
    server.begin();
}