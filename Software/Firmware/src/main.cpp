#include <Arduino.h>
#include <stdio.h>
#include "gui.h"
#include "hardware.h"
#include "geiger.h"
#include "settings.h"
#include "connectivity.h"
#include "time.h"

hw_timer_t *geigerTimer = NULL;
const char *ntp_server = "pool.ntp.org";

void IRAM_ATTR geiger_isr()
{
  geiger_loop();
}

void setup()
{
  Serial.begin(9600);
  load_settings();
  measurement_init();
  geiger_tube_init();
  wakeup_handler();
  gui_init();
  hardware_init();
  geigerTimer = timerBegin(0, 80, true);
  timerAttachInterrupt(geigerTimer, &geiger_isr, true);
  timerAlarmWrite(geigerTimer, 1000, true);
  timerAlarmEnable(geigerTimer);
  connectivity_init();
  configTime(get_timezone_offset_seconds(), 0, ntp_server);
}

int gui_timer_handler = millis();
void loop()
{
  if ((millis() - gui_timer_handler) > 5)
  {
    lv_timer_handler();
    gui_timer_handler = millis();
  }
}
