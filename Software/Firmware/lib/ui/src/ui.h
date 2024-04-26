// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: OpenRad

#ifndef _OPENRAD_UI_H
#define _OPENRAD_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"
#include "ui_theme_manager.h"
#include "ui_themes.h"

void ToastMsg_Animation(lv_obj_t * TargetObject, int delay);
void RadWarning_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Home
void ui_Home_screen_init(void);
void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_HomeScreenArea;
extern lv_obj_t * ui_PrimaryGuageArea;
extern lv_obj_t * ui_PrimaryGuage;
extern lv_obj_t * ui_PrimaryUnit;
extern lv_obj_t * ui_SecondaryGuageArea;
extern lv_obj_t * ui_SecondaryGuage;
extern lv_obj_t * ui_SecondaryUnit;
extern lv_obj_t * ui_HomeButtonsArea;
void ui_event_ChartNavBtn(lv_event_t * e);
extern lv_obj_t * ui_ChartNavBtn;
void ui_event_SettingsNavBtn(lv_event_t * e);
extern lv_obj_t * ui_SettingsNavBtn;
void ui_event_PowerBtn(lv_event_t * e);
extern lv_obj_t * ui_PowerBtn;
extern lv_obj_t * ui_TimeDisp;
extern lv_obj_t * ui_BottomArea;
extern lv_obj_t * ui_IndicatorArea;
extern lv_obj_t * ui_BatteryIndicator;
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_BatteryGuage;
extern lv_obj_t * ui_ChargingIcon;
extern lv_obj_t * ui_BatLabel;
extern lv_obj_t * ui_ClickerEnableIndicator;
extern lv_obj_t * ui_AlertIndicator;
extern lv_obj_t * ui_SleepSampleIndicator;
extern lv_obj_t * ui_WifiIndicator;
extern lv_obj_t * ui_BtIndicator;
void ui_event_DoseGuageArea(lv_event_t * e);
extern lv_obj_t * ui_DoseGuageArea;
extern lv_obj_t * ui_DoseGuage;
extern lv_obj_t * ui_DoseUnit;
extern lv_obj_t * ui_RadRange;
extern lv_obj_t * ui_PowerOffMsg;
extern lv_obj_t * ui_PowerOffMsgLabel;
extern lv_obj_t * ui_RadWarningIcon;
extern lv_obj_t * ui_NullNavigationSelector;
// SCREEN: ui_Settings
void ui_Settings_screen_init(void);
void ui_event_Settings(lv_event_t * e);
extern lv_obj_t * ui_Settings;
extern lv_obj_t * ui_SettingsMenu;
extern lv_obj_t * ui_GeneralSettingsPanel;
void ui_event_GeneralSettingsBtn(lv_event_t * e);
extern lv_obj_t * ui_GeneralSettingsBtn;
extern lv_obj_t * ui_GeneralSettingsLabel;
extern lv_obj_t * ui_MeasurementSettingsPanel;
void ui_event_MeasurementSettingsBtn(lv_event_t * e);
extern lv_obj_t * ui_MeasurementSettingsBtn;
extern lv_obj_t * ui_MeasurementSettingsLabel;
extern lv_obj_t * ui_ConnectivitySettingsPanel;
void ui_event_ConnectivitySettingsBtn(lv_event_t * e);
extern lv_obj_t * ui_ConnectivitySettingsBtn;
extern lv_obj_t * ui_ConnectivitySettingsLabel;
extern lv_obj_t * ui_DisplaySettingsPanel;
void ui_event_DisplaySettingsBtn(lv_event_t * e);
extern lv_obj_t * ui_DisplaySettingsBtn;
extern lv_obj_t * ui_DisplaySettingsLabel;
extern lv_obj_t * ui_AdvancedSettingsPanel;
void ui_event_AdvancedSettingsBtn(lv_event_t * e);
extern lv_obj_t * ui_AdvancedSettingsBtn;
extern lv_obj_t * ui_AdvancedSettingsLabel;
extern lv_obj_t * ui_TopNavBar1;
extern lv_obj_t * ui_NavBarTitle1;
void ui_event_BackBtn1(lv_event_t * e);
extern lv_obj_t * ui_BackBtn1;
extern lv_obj_t * ui_Label11;
// SCREEN: ui_GeneralSettings
void ui_GeneralSettings_screen_init(void);
void ui_event_GeneralSettings(lv_event_t * e);
extern lv_obj_t * ui_GeneralSettings;
extern lv_obj_t * ui_GeneralSettingsMenu;
extern lv_obj_t * ui_ClickerPanel;
extern lv_obj_t * ui_ClickerLabel;
void ui_event_ClickerSwitch(lv_event_t * e);
extern lv_obj_t * ui_ClickerSwitch;
extern lv_obj_t * ui_AlarmPanel;
extern lv_obj_t * ui_AlarmLabel;
void ui_event_AlarmSwitch(lv_event_t * e);
extern lv_obj_t * ui_AlarmSwitch;
extern lv_obj_t * ui_AlarmThrPanel;
extern lv_obj_t * ui_AlarmThrLabel;
void ui_event_AlarmThresholdInp(lv_event_t * e);
extern lv_obj_t * ui_AlarmThresholdInp;
extern lv_obj_t * ui_TimeZonePanel;
extern lv_obj_t * ui_TimeZoneLabel;
void ui_event_TimeZoneOffsetInpH(lv_event_t * e);
extern lv_obj_t * ui_TimeZoneOffsetInpH;
void ui_event_TimeZoneOffsetInpM(lv_event_t * e);
extern lv_obj_t * ui_TimeZoneOffsetInpM;
extern lv_obj_t * ui_FactoryResetPanel;
void ui_event_FactoryResetBtn(lv_event_t * e);
extern lv_obj_t * ui_FactoryResetBtn;
extern lv_obj_t * ui_FactoryResetLabel;
extern lv_obj_t * ui_TopNavBar2;
extern lv_obj_t * ui_NavBarTitle2;
void ui_event_BackBtn2(lv_event_t * e);
extern lv_obj_t * ui_BackBtn2;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_ToastMsg;
extern lv_obj_t * ui_ToastMsgLabel;
// SCREEN: ui_MeasurementSettings
void ui_MeasurementSettings_screen_init(void);
void ui_event_MeasurementSettings(lv_event_t * e);
extern lv_obj_t * ui_MeasurementSettings;
extern lv_obj_t * ui_MeasurementSettingsMenu;
extern lv_obj_t * ui_WindowSizePanel;
extern lv_obj_t * ui_WindowSizeLabel;
void ui_event_WindowSizeInp(lv_event_t * e);
extern lv_obj_t * ui_WindowSizeInp;
extern lv_obj_t * ui_SamplingPeriodPanel;
extern lv_obj_t * ui_SamplingPeriodLabel;
void ui_event_SamplingPeriodInp(lv_event_t * e);
extern lv_obj_t * ui_SamplingPeriodInp;
extern lv_obj_t * ui_WakeToMeasureEnPanel;
extern lv_obj_t * ui_WakeToMeasureEnLabel;
void ui_event_WakeEnSwitch(lv_event_t * e);
extern lv_obj_t * ui_WakeEnSwitch;
extern lv_obj_t * ui_WakeEveryPanel;
extern lv_obj_t * ui_WakeEveryLabel;
void ui_event_WakeEveryDrop(lv_event_t * e);
extern lv_obj_t * ui_WakeEveryDrop;
extern lv_obj_t * ui_WakeSamplePanel;
extern lv_obj_t * ui_WakeSampleLabel;
void ui_event_WakeSampleDrop(lv_event_t * e);
extern lv_obj_t * ui_WakeSampleDrop;
extern lv_obj_t * ui_TopNavBar5;
extern lv_obj_t * ui_NavBarTitle5;
void ui_event_BackBtn5(lv_event_t * e);
extern lv_obj_t * ui_BackBtn5;
extern lv_obj_t * ui_Label14;
// SCREEN: ui_DisplaySettings
void ui_DisplaySettings_screen_init(void);
void ui_event_DisplaySettings(lv_event_t * e);
extern lv_obj_t * ui_DisplaySettings;
extern lv_obj_t * ui_DisplaySettingsMenu;
extern lv_obj_t * ui_BrightnessPanel;
extern lv_obj_t * ui_BrightnessLabel;
void ui_event_BrightnessSlider(lv_event_t * e);
extern lv_obj_t * ui_BrightnessSlider;
extern lv_obj_t * ui_TopNavBar3;
extern lv_obj_t * ui_NavBarTitle3;
void ui_event_BackBtn3(lv_event_t * e);
extern lv_obj_t * ui_BackBtn3;
extern lv_obj_t * ui_Label20;
// SCREEN: ui_History
void ui_History_screen_init(void);
void ui_event_History(lv_event_t * e);
extern lv_obj_t * ui_History;
extern lv_obj_t * ui_HistoryScreenArea1;
extern lv_obj_t * ui_Panel20;
extern lv_obj_t * ui_Label37;
void ui_event_Button21(lv_event_t * e);
extern lv_obj_t * ui_Button21;
extern lv_obj_t * ui_Label24;
extern lv_obj_t * ui_HistoryChart;
// SCREEN: ui_AdvancedSettings
void ui_AdvancedSettings_screen_init(void);
void ui_event_AdvancedSettings(lv_event_t * e);
extern lv_obj_t * ui_AdvancedSettings;
extern lv_obj_t * ui_AdvancedSettingsMenu;
extern lv_obj_t * ui_TubeVoltagePanel;
extern lv_obj_t * ui_TubeVoltageLabel;
void ui_event_TubeVoltageInp(lv_event_t * e);
extern lv_obj_t * ui_TubeVoltageInp;
extern lv_obj_t * ui_ConversionRatePanel;
extern lv_obj_t * ui_ConversionRateLabel;
void ui_event_ConversionRateInp(lv_event_t * e);
extern lv_obj_t * ui_ConversionRateInp;
extern lv_obj_t * ui_TopNavBar6;
extern lv_obj_t * ui_NavBarTitle6;
void ui_event_BackBtn6(lv_event_t * e);
extern lv_obj_t * ui_BackBtn6;
extern lv_obj_t * ui_Label29;
// SCREEN: ui_ConnectivitySettings
void ui_ConnectivitySettings_screen_init(void);
void ui_event_ConnectivitySettings(lv_event_t * e);
extern lv_obj_t * ui_ConnectivitySettings;
extern lv_obj_t * ui_ConnectivitySettingsMenu;
extern lv_obj_t * ui_WifiEnPanel;
extern lv_obj_t * ui_WifiEnLabel;
void ui_event_WifiEnSwitch(lv_event_t * e);
extern lv_obj_t * ui_WifiEnSwitch;
extern lv_obj_t * ui_WifiSSIDPanel;
extern lv_obj_t * ui_WifiSSIDBtn;
extern lv_obj_t * ui_WifiSSIDLabel;
extern lv_obj_t * ui_WifiSSIDDisp;
extern lv_obj_t * ui_WifiRSSIPanel;
extern lv_obj_t * ui_WifiRSSIBtn;
extern lv_obj_t * ui_WifiRSSILabel;
extern lv_obj_t * ui_WifiRSSIDisp;
extern lv_obj_t * ui_WifiIPPanel;
extern lv_obj_t * ui_WifiIPBtn;
extern lv_obj_t * ui_WifiIPLabel;
extern lv_obj_t * ui_WifiIPDisp;
extern lv_obj_t * ui_WifiAPEnPanel;
extern lv_obj_t * ui_WifiAPEnLabel;
void ui_event_WifiAPEnSwitch(lv_event_t * e);
extern lv_obj_t * ui_WifiAPEnSwitch;
extern lv_obj_t * ui_MqttEnPanel;
extern lv_obj_t * ui_MqttEnLabel;
void ui_event_MqttEnSwitch(lv_event_t * e);
extern lv_obj_t * ui_MqttEnSwitch;
extern lv_obj_t * ui_MqttStatePanel;
extern lv_obj_t * ui_MqttStateBtn;
extern lv_obj_t * ui_MqttStateDisp;
extern lv_obj_t * ui_TopNavBar4;
extern lv_obj_t * ui_NavBarTitle4;
void ui_event_BackBtn4(lv_event_t * e);
extern lv_obj_t * ui_BackBtn4;
extern lv_obj_t * ui_Label32;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_graph_20x20_png);    // assets/graph_20x20.png
LV_IMG_DECLARE(ui_img_gear_icon_20x20_png);    // assets/gear_icon_20x20.png
LV_IMG_DECLARE(ui_img_power_icon_20x20_png);    // assets/power_icon_20x20.png
LV_IMG_DECLARE(ui_img_1762124945);    // assets/battery-charging-20px.png
LV_IMG_DECLARE(ui_img_volume_high_15x15_png);    // assets/volume_high_15x15.png
LV_IMG_DECLARE(ui_img_bell_15x15_png);    // assets/bell_15x15.png
LV_IMG_DECLARE(ui_img_moon_15x15_png);    // assets/moon_15x15.png
LV_IMG_DECLARE(ui_img_wifi_15x15_png);    // assets/wifi_15x15.png
LV_IMG_DECLARE(ui_img_bt_15x15_png);    // assets/bt_15x15.png
LV_IMG_DECLARE(ui_img_radiation_warning_25x25_png);    // assets/radiation_warning_25x25.png
LV_IMG_DECLARE(ui_img_home_20x20_png);    // assets/home_20x20.png
LV_IMG_DECLARE(ui_img_power_icon_25x25_png);    // assets/power_icon_25x25.png
LV_IMG_DECLARE(ui_img_pwr_icon_25x25_png);    // assets/pwr_icon_25x25.png
LV_IMG_DECLARE(ui_img_settings_25x25_png);    // assets/settings.25x25.png
LV_IMG_DECLARE(ui_img_volume_xmark_15x15_png);    // assets/volume_xmark_15x15.png



LV_FONT_DECLARE(ui_font_SevenSig38);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif