// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: OpenRad

#include "../ui.h"

void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_Home, scr_unloaded_delete_cb, LV_EVENT_SCREEN_UNLOADED, &ui_Home);

    ui_HomeScreenArea = lv_obj_create(ui_Home);
    lv_obj_remove_style_all(ui_HomeScreenArea);
    lv_obj_set_width(ui_HomeScreenArea, 240);
    lv_obj_set_height(ui_HomeScreenArea, 135);
    lv_obj_set_align(ui_HomeScreenArea, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_HomeScreenArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PrimaryGuageArea = lv_obj_create(ui_HomeScreenArea);
    lv_obj_remove_style_all(ui_PrimaryGuageArea);
    lv_obj_set_width(ui_PrimaryGuageArea, 197);
    lv_obj_set_height(ui_PrimaryGuageArea, 50);
    lv_obj_set_x(ui_PrimaryGuageArea, 0);
    lv_obj_set_y(ui_PrimaryGuageArea, -15);
    lv_obj_set_align(ui_PrimaryGuageArea, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PrimaryGuageArea, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PrimaryGuageArea, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PrimaryGuageArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PrimaryGuage = lv_label_create(ui_PrimaryGuageArea);
    lv_obj_set_width(ui_PrimaryGuage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PrimaryGuage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PrimaryGuage, -7);
    lv_obj_set_y(ui_PrimaryGuage, -9);
    lv_obj_set_align(ui_PrimaryGuage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PrimaryGuage, "--");
    lv_obj_set_style_text_font(ui_PrimaryGuage, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrimaryUnit = lv_label_create(ui_PrimaryGuageArea);
    lv_obj_set_width(ui_PrimaryUnit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PrimaryUnit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PrimaryUnit, 42);
    lv_obj_set_y(ui_PrimaryUnit, 1);
    lv_obj_set_align(ui_PrimaryUnit, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PrimaryUnit, "uSv/h");
    lv_obj_set_style_text_font(ui_PrimaryUnit, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SecondaryGuageArea = lv_obj_create(ui_HomeScreenArea);
    lv_obj_remove_style_all(ui_SecondaryGuageArea);
    lv_obj_set_width(ui_SecondaryGuageArea, 197);
    lv_obj_set_height(ui_SecondaryGuageArea, 21);
    lv_obj_set_x(ui_SecondaryGuageArea, 0);
    lv_obj_set_y(ui_SecondaryGuageArea, 20);
    lv_obj_set_align(ui_SecondaryGuageArea, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SecondaryGuageArea, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SecondaryGuageArea, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SecondaryGuageArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_SecondaryGuageArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_SecondaryGuageArea, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SecondaryGuage = lv_label_create(ui_SecondaryGuageArea);
    lv_obj_set_width(ui_SecondaryGuage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SecondaryGuage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SecondaryGuage, -14);
    lv_obj_set_y(ui_SecondaryGuage, 30);
    lv_obj_set_align(ui_SecondaryGuage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SecondaryGuage, "--");
    lv_obj_set_style_text_color(ui_SecondaryGuage, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SecondaryGuage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SecondaryGuage, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SecondaryUnit = lv_label_create(ui_SecondaryGuageArea);
    lv_obj_set_width(ui_SecondaryUnit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SecondaryUnit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SecondaryUnit, 34);
    lv_obj_set_y(ui_SecondaryUnit, 31);
    lv_obj_set_align(ui_SecondaryUnit, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SecondaryUnit, "CPM");
    lv_obj_set_style_text_color(ui_SecondaryUnit, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SecondaryUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SecondaryUnit, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HomeButtonsArea = lv_obj_create(ui_HomeScreenArea);
    lv_obj_remove_style_all(ui_HomeButtonsArea);
    lv_obj_set_width(ui_HomeButtonsArea, 38);
    lv_obj_set_height(ui_HomeButtonsArea, 135);
    lv_obj_set_align(ui_HomeButtonsArea, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_flow(ui_HomeButtonsArea, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_HomeButtonsArea, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END);
    lv_obj_clear_flag(ui_HomeButtonsArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_HomeButtonsArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_HomeButtonsArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_HomeButtonsArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_HomeButtonsArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_HomeButtonsArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_HomeButtonsArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChartNavBtn = lv_btn_create(ui_HomeButtonsArea);
    lv_obj_set_width(ui_ChartNavBtn, 30);
    lv_obj_set_height(ui_ChartNavBtn, 28);
    lv_obj_set_align(ui_ChartNavBtn, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ChartNavBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChartNavBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ChartNavBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChartNavBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ChartNavBtn, &ui_img_graph_20x20_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_ChartNavBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ChartNavBtn, &ui_img_graph_20x20_png, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_img_opa(ui_ChartNavBtn, 128, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_color(ui_ChartNavBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_ChartNavBtn, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_ChartNavBtn, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_ChartNavBtn, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_SettingsNavBtn = lv_btn_create(ui_HomeButtonsArea);
    lv_obj_set_width(ui_SettingsNavBtn, 30);
    lv_obj_set_height(ui_SettingsNavBtn, 28);
    lv_obj_set_align(ui_SettingsNavBtn, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_SettingsNavBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SettingsNavBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SettingsNavBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsNavBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SettingsNavBtn, &ui_img_gear_icon_20x20_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_SettingsNavBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SettingsNavBtn, &ui_img_gear_icon_20x20_png, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_img_opa(ui_SettingsNavBtn, 128, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_color(ui_SettingsNavBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_SettingsNavBtn, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_SettingsNavBtn, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_SettingsNavBtn, 0, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_PowerBtn = lv_btn_create(ui_HomeButtonsArea);
    lv_obj_set_width(ui_PowerBtn, 30);
    lv_obj_set_height(ui_PowerBtn, 28);
    lv_obj_set_align(ui_PowerBtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PowerBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_PowerBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PowerBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PowerBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_PowerBtn, &ui_img_power_icon_20x20_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_PowerBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_PowerBtn, &ui_img_power_icon_20x20_png, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_img_opa(ui_PowerBtn, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_img_recolor(ui_PowerBtn, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_img_recolor_opa(ui_PowerBtn, 255, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_TimeDisp = lv_label_create(ui_HomeScreenArea);
    lv_obj_set_width(ui_TimeDisp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeDisp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeDisp, -5);
    lv_obj_set_y(ui_TimeDisp, 5);
    lv_obj_set_align(ui_TimeDisp, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_TimeDisp, "00:00");
    lv_obj_set_style_text_color(ui_TimeDisp, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeDisp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeDisp, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BottomArea = lv_obj_create(ui_Home);
    lv_obj_remove_style_all(ui_BottomArea);
    lv_obj_set_width(ui_BottomArea, 210);
    lv_obj_set_height(ui_BottomArea, 33);
    lv_obj_set_align(ui_BottomArea, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_BottomArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_BottomArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_BottomArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_BottomArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_BottomArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_BottomArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_BottomArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IndicatorArea = lv_obj_create(ui_BottomArea);
    lv_obj_remove_style_all(ui_IndicatorArea);
    lv_obj_set_width(ui_IndicatorArea, 139);
    lv_obj_set_height(ui_IndicatorArea, 26);
    lv_obj_set_align(ui_IndicatorArea, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_flex_flow(ui_IndicatorArea, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_IndicatorArea, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_IndicatorArea, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_IndicatorArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_IndicatorArea, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BatteryIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_BatteryIndicator);
    lv_obj_set_width(ui_BatteryIndicator, 39);
    lv_obj_set_height(ui_BatteryIndicator, 18);
    lv_obj_set_align(ui_BatteryIndicator, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_BatteryIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel3 = lv_obj_create(ui_BatteryIndicator);
    lv_obj_set_width(ui_Panel3, 14);
    lv_obj_set_height(ui_Panel3, 6);
    lv_obj_set_x(ui_Panel3, 8);
    lv_obj_set_y(ui_Panel3, 0);
    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x003955), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0x003955), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BatteryGuage = lv_bar_create(ui_BatteryIndicator);
    lv_bar_set_value(ui_BatteryGuage, 100, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_BatteryGuage, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_BatteryGuage, 23);
    lv_obj_set_height(ui_BatteryGuage, 12);
    lv_obj_set_x(ui_BatteryGuage, -1);
    lv_obj_set_y(ui_BatteryGuage, 0);
    lv_obj_set_align(ui_BatteryGuage, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_BatteryGuage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BatteryGuage, lv_color_hex(0x003955), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BatteryGuage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_BatteryGuage, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ChargingIcon = lv_img_create(ui_BatteryIndicator);
    lv_img_set_src(ui_ChargingIcon, &ui_img_1762124945);
    lv_obj_set_width(ui_ChargingIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargingIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChargingIcon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ChargingIcon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ChargingIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BatLabel = lv_label_create(ui_BatteryIndicator);
    lv_obj_set_width(ui_BatLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BatLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BatLabel, 0);
    lv_obj_set_y(ui_BatLabel, -1);
    lv_obj_set_align(ui_BatLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_BatLabel, "--");
    lv_obj_set_style_text_font(ui_BatLabel, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ClickerEnableIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_ClickerEnableIndicator);
    lv_obj_set_width(ui_ClickerEnableIndicator, 15);
    lv_obj_set_height(ui_ClickerEnableIndicator, 15);
    lv_obj_set_align(ui_ClickerEnableIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ClickerEnableIndicator, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ClickerEnableIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_ClickerEnableIndicator, &ui_img_volume_high_15x15_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_ClickerEnableIndicator, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AlertIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_AlertIndicator);
    lv_obj_set_width(ui_AlertIndicator, 15);
    lv_obj_set_height(ui_AlertIndicator, 15);
    lv_obj_set_align(ui_AlertIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_AlertIndicator, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_AlertIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_AlertIndicator, &ui_img_bell_15x15_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_AlertIndicator, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SleepSampleIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_SleepSampleIndicator);
    lv_obj_set_width(ui_SleepSampleIndicator, 15);
    lv_obj_set_height(ui_SleepSampleIndicator, 15);
    lv_obj_set_align(ui_SleepSampleIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SleepSampleIndicator, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_SleepSampleIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_SleepSampleIndicator, &ui_img_moon_15x15_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_SleepSampleIndicator, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WifiIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_WifiIndicator);
    lv_obj_set_width(ui_WifiIndicator, 15);
    lv_obj_set_height(ui_WifiIndicator, 15);
    lv_obj_set_align(ui_WifiIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WifiIndicator, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_WifiIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_WifiIndicator, &ui_img_wifi_15x15_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_WifiIndicator, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtIndicator = lv_obj_create(ui_IndicatorArea);
    lv_obj_remove_style_all(ui_BtIndicator);
    lv_obj_set_width(ui_BtIndicator, 15);
    lv_obj_set_height(ui_BtIndicator, 15);
    lv_obj_set_align(ui_BtIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtIndicator, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_BtIndicator, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_BtIndicator, &ui_img_bt_15x15_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_BtIndicator, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DoseGuageArea = lv_btn_create(ui_BottomArea);
    lv_obj_set_width(ui_DoseGuageArea, 78);
    lv_obj_set_height(ui_DoseGuageArea, 21);
    lv_obj_set_align(ui_DoseGuageArea, LV_ALIGN_RIGHT_MID);
    lv_obj_set_flex_flow(ui_DoseGuageArea, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_DoseGuageArea, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_DoseGuageArea, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DoseGuageArea, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DoseGuageArea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DoseGuageArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DoseGuage = lv_label_create(ui_DoseGuageArea);
    lv_obj_set_width(ui_DoseGuage, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DoseGuage, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DoseGuage, -14);
    lv_obj_set_y(ui_DoseGuage, 30);
    lv_obj_set_align(ui_DoseGuage, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DoseGuage, "--");
    lv_obj_set_style_text_color(ui_DoseGuage, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DoseGuage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DoseGuage, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DoseUnit = lv_label_create(ui_DoseGuageArea);
    lv_obj_set_width(ui_DoseUnit, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DoseUnit, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DoseUnit, 34);
    lv_obj_set_y(ui_DoseUnit, 31);
    lv_obj_set_align(ui_DoseUnit, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DoseUnit, "uSv");
    lv_obj_set_style_text_color(ui_DoseUnit, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DoseUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DoseUnit, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RadRange = lv_bar_create(ui_Home);
    lv_obj_set_width(ui_RadRange, 129);
    lv_obj_set_height(ui_RadRange, 10);
    lv_obj_set_x(ui_RadRange, 0);
    lv_obj_set_y(ui_RadRange, 5);
    lv_obj_set_align(ui_RadRange, LV_ALIGN_TOP_MID);
    lv_obj_set_style_pad_left(ui_RadRange, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_RadRange, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_RadRange, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_RadRange, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_anim_time(ui_RadRange, 500, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_grad_color(ui_RadRange, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_RadRange, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_PowerOffMsg = lv_obj_create(ui_Home);
    lv_obj_set_width(ui_PowerOffMsg, 169);
    lv_obj_set_height(ui_PowerOffMsg, 90);
    lv_obj_set_align(ui_PowerOffMsg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PowerOffMsg, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_PowerOffMsg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PowerOffMsgLabel = lv_label_create(ui_PowerOffMsg);
    lv_obj_set_width(ui_PowerOffMsgLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PowerOffMsgLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PowerOffMsgLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PowerOffMsgLabel, "Release to power off\nKeep holding to cancel");
    lv_obj_set_style_text_align(ui_PowerOffMsgLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PowerOffMsgLabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RadWarningIcon = lv_obj_create(ui_Home);
    lv_obj_remove_style_all(ui_RadWarningIcon);
    lv_obj_set_width(ui_RadWarningIcon, 29);
    lv_obj_set_height(ui_RadWarningIcon, 29);
    lv_obj_set_x(ui_RadWarningIcon, 10);
    lv_obj_set_y(ui_RadWarningIcon, -10);
    lv_obj_set_align(ui_RadWarningIcon, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_RadWarningIcon, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_RadWarningIcon, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_RadWarningIcon, &ui_img_radiation_warning_25x25_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_RadWarningIcon, lv_color_hex(0xEAFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_RadWarningIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NullNavigationSelector = lv_btn_create(ui_Home);
    lv_obj_set_width(ui_NullNavigationSelector, 17);
    lv_obj_set_height(ui_NullNavigationSelector, 20);
    lv_obj_set_x(ui_NullNavigationSelector, 102);
    lv_obj_set_y(ui_NullNavigationSelector, 83);
    lv_obj_set_align(ui_NullNavigationSelector, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_NullNavigationSelector, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NullNavigationSelector, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NullNavigationSelector, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NullNavigationSelector, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NullNavigationSelector, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ChartNavBtn, ui_event_ChartNavBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsNavBtn, ui_event_SettingsNavBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PowerBtn, ui_event_PowerBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DoseGuageArea, ui_event_DoseGuageArea, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

}
