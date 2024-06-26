// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: OpenRad

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void UpdateScreens(lv_event_t * e);
void ScreensUnloaded(lv_event_t * e);
void PowerLongPress(lv_event_t * e);
void PowerShortPress(lv_event_t * e);
void PowerReleased(lv_event_t * e);
void DoseReset(lv_event_t * e);
void CLickerEnableUpdate(lv_event_t * e);
void AlarmEnableUpdate(lv_event_t * e);
void AlarmLimitUpdate(lv_event_t * e);
void TzOffsetHUpdate(lv_event_t * e);
void TzOffsetMUpdate(lv_event_t * e);
void FactoryReset(lv_event_t * e);
void WindowSizeUpdate(lv_event_t * e);
void SamplingPeriodUpdate(lv_event_t * e);
void WakeEnableUpdate(lv_event_t * e);
void WakeEveryDropUpdate(lv_event_t * e);
void WakeSampleDropUpdate(lv_event_t * e);
void ScreenBrightnessUpdate(lv_event_t * e);
void TubeVoltageUpdate(lv_event_t * e);
void ConversionRateUpdate(lv_event_t * e);
void WifiEnableUpdate(lv_event_t * e);
void WifiAPEnableUpdate(lv_event_t * e);
void MqttEnableUpdate(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
