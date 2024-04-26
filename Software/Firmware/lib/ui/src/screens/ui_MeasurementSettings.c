// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: OpenRad

#include "../ui.h"

void ui_MeasurementSettings_screen_init(void)
{
    ui_MeasurementSettings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MeasurementSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_MeasurementSettings, scr_unloaded_delete_cb, LV_EVENT_SCREEN_UNLOADED, &ui_MeasurementSettings);
    lv_obj_set_style_pad_left(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_MeasurementSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MeasurementSettingsMenu = lv_obj_create(ui_MeasurementSettings);
    lv_obj_set_height(ui_MeasurementSettingsMenu, 120);
    lv_obj_set_width(ui_MeasurementSettingsMenu, lv_pct(100));
    lv_obj_set_align(ui_MeasurementSettingsMenu, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_MeasurementSettingsMenu, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_MeasurementSettingsMenu, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_radius(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MeasurementSettingsMenu, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MeasurementSettingsMenu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_MeasurementSettingsMenu, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_MeasurementSettingsMenu, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_MeasurementSettingsMenu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WindowSizePanel = lv_obj_create(ui_MeasurementSettingsMenu);
    lv_obj_set_height(ui_WindowSizePanel, 40);
    lv_obj_set_width(ui_WindowSizePanel, lv_pct(100));
    lv_obj_set_x(ui_WindowSizePanel, 0);
    lv_obj_set_y(ui_WindowSizePanel, -26);
    lv_obj_set_align(ui_WindowSizePanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WindowSizePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_WindowSizePanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_primary);
    ui_object_set_themeable_style_property(ui_WindowSizePanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_primary);
    lv_obj_set_style_border_width(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_WindowSizePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WindowSizePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_WindowSizePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_WindowSizePanel, lv_color_hex(0xF8F8F8), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_WindowSizePanel, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_WindowSizePanel, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_WindowSizePanel, -1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_WindowSizeLabel = lv_label_create(ui_WindowSizePanel);
    lv_obj_set_width(ui_WindowSizeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WindowSizeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WindowSizeLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_WindowSizeLabel, "Window size");

    ui_WindowSizeInp = lv_spinbox_create(ui_WindowSizePanel);
    lv_obj_set_width(ui_WindowSizeInp, 45);
    lv_obj_set_height(ui_WindowSizeInp, 35);
    lv_obj_set_align(ui_WindowSizeInp, LV_ALIGN_RIGHT_MID);
    lv_spinbox_set_digit_format(ui_WindowSizeInp, 3, 0);
    lv_spinbox_set_range(ui_WindowSizeInp, 1, 300);
    lv_spinbox_set_cursor_pos(ui_WindowSizeInp, 1 - 1);

    ui_SamplingPeriodPanel = lv_obj_create(ui_MeasurementSettingsMenu);
    lv_obj_set_height(ui_SamplingPeriodPanel, 40);
    lv_obj_set_width(ui_SamplingPeriodPanel, lv_pct(100));
    lv_obj_set_x(ui_SamplingPeriodPanel, 0);
    lv_obj_set_y(ui_SamplingPeriodPanel, -26);
    lv_obj_set_align(ui_SamplingPeriodPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SamplingPeriodPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_SamplingPeriodPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_primary);
    ui_object_set_themeable_style_property(ui_SamplingPeriodPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_primary);
    lv_obj_set_style_border_width(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SamplingPeriodPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SamplingPeriodPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_SamplingPeriodPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_SamplingPeriodPanel, lv_color_hex(0xF8F8F8), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_SamplingPeriodPanel, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_SamplingPeriodPanel, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_SamplingPeriodPanel, -1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_SamplingPeriodLabel = lv_label_create(ui_SamplingPeriodPanel);
    lv_obj_set_width(ui_SamplingPeriodLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SamplingPeriodLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SamplingPeriodLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SamplingPeriodLabel, "Sampling period (ms)");

    ui_SamplingPeriodInp = lv_spinbox_create(ui_SamplingPeriodPanel);
    lv_obj_set_width(ui_SamplingPeriodInp, 55);
    lv_obj_set_height(ui_SamplingPeriodInp, 35);
    lv_obj_set_align(ui_SamplingPeriodInp, LV_ALIGN_RIGHT_MID);
    lv_spinbox_set_digit_format(ui_SamplingPeriodInp, 4, 0);
    lv_spinbox_set_range(ui_SamplingPeriodInp, 1, 9999);
    lv_spinbox_set_cursor_pos(ui_SamplingPeriodInp, 1 - 1);

    ui_WakeToMeasureEnPanel = lv_obj_create(ui_MeasurementSettingsMenu);
    lv_obj_set_height(ui_WakeToMeasureEnPanel, 40);
    lv_obj_set_width(ui_WakeToMeasureEnPanel, lv_pct(100));
    lv_obj_set_x(ui_WakeToMeasureEnPanel, 0);
    lv_obj_set_y(ui_WakeToMeasureEnPanel, -26);
    lv_obj_set_align(ui_WakeToMeasureEnPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WakeToMeasureEnPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_WakeToMeasureEnPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_primary);
    ui_object_set_themeable_style_property(ui_WakeToMeasureEnPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_primary);
    lv_obj_set_style_border_width(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_WakeToMeasureEnPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WakeToMeasureEnPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_WakeToMeasureEnPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_WakeToMeasureEnPanel, lv_color_hex(0xF8F8F8), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_WakeToMeasureEnPanel, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_WakeToMeasureEnPanel, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_WakeToMeasureEnPanel, -1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_WakeToMeasureEnLabel = lv_label_create(ui_WakeToMeasureEnPanel);
    lv_obj_set_width(ui_WakeToMeasureEnLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WakeToMeasureEnLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WakeToMeasureEnLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_WakeToMeasureEnLabel, "Wake to measure");

    ui_WakeEnSwitch = lv_switch_create(ui_WakeToMeasureEnPanel);
    lv_obj_set_width(ui_WakeEnSwitch, 50);
    lv_obj_set_height(ui_WakeEnSwitch, 25);
    lv_obj_set_align(ui_WakeEnSwitch, LV_ALIGN_RIGHT_MID);


    ui_WakeEveryPanel = lv_obj_create(ui_MeasurementSettingsMenu);
    lv_obj_set_height(ui_WakeEveryPanel, 40);
    lv_obj_set_width(ui_WakeEveryPanel, lv_pct(100));
    lv_obj_set_x(ui_WakeEveryPanel, 0);
    lv_obj_set_y(ui_WakeEveryPanel, -26);
    lv_obj_set_align(ui_WakeEveryPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WakeEveryPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_WakeEveryPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_primary);
    ui_object_set_themeable_style_property(ui_WakeEveryPanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_primary);
    lv_obj_set_style_border_width(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_WakeEveryPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WakeEveryPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_WakeEveryPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_WakeEveryPanel, lv_color_hex(0xF8F8F8), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_WakeEveryPanel, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_WakeEveryPanel, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_WakeEveryPanel, -1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_WakeEveryLabel = lv_label_create(ui_WakeEveryPanel);
    lv_obj_set_width(ui_WakeEveryLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WakeEveryLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WakeEveryLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_WakeEveryLabel, "Wake every");

    ui_WakeEveryDrop = lv_dropdown_create(ui_WakeEveryPanel);
    lv_dropdown_set_options(ui_WakeEveryDrop, "10s\n30s\n1min\n5min\n10min\n15min\n30min\n1hr");
    lv_obj_set_width(ui_WakeEveryDrop, 79);
    lv_obj_set_height(ui_WakeEveryDrop, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WakeEveryDrop, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_WakeEveryDrop, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags



    ui_WakeSamplePanel = lv_obj_create(ui_MeasurementSettingsMenu);
    lv_obj_set_height(ui_WakeSamplePanel, 40);
    lv_obj_set_width(ui_WakeSamplePanel, lv_pct(100));
    lv_obj_set_x(ui_WakeSamplePanel, 0);
    lv_obj_set_y(ui_WakeSamplePanel, -26);
    lv_obj_set_align(ui_WakeSamplePanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_WakeSamplePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_WakeSamplePanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_primary);
    ui_object_set_themeable_style_property(ui_WakeSamplePanel, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_primary);
    lv_obj_set_style_border_width(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_WakeSamplePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WakeSamplePanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_WakeSamplePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_WakeSamplePanel, lv_color_hex(0xF8F8F8), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_opa(ui_WakeSamplePanel, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_width(ui_WakeSamplePanel, 1, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_outline_pad(ui_WakeSamplePanel, -1, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_WakeSampleLabel = lv_label_create(ui_WakeSamplePanel);
    lv_obj_set_width(ui_WakeSampleLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WakeSampleLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WakeSampleLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_WakeSampleLabel, "Wake sample");

    ui_WakeSampleDrop = lv_dropdown_create(ui_WakeSamplePanel);
    lv_dropdown_set_options(ui_WakeSampleDrop, "1s\n5s\n10s\n15s\n30s\n1min\n2min\n5min");
    lv_obj_set_width(ui_WakeSampleDrop, 79);
    lv_obj_set_height(ui_WakeSampleDrop, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WakeSampleDrop, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_WakeSampleDrop, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags



    ui_TopNavBar5 = lv_obj_create(ui_MeasurementSettings);
    lv_obj_set_width(ui_TopNavBar5, 240);
    lv_obj_set_height(ui_TopNavBar5, 15);
    lv_obj_set_align(ui_TopNavBar5, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_TopNavBar5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TopNavBar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_object_set_themeable_style_property(ui_TopNavBar5, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_navbar);
    ui_object_set_themeable_style_property(ui_TopNavBar5, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_navbar);
    lv_obj_set_style_border_width(ui_TopNavBar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NavBarTitle5 = lv_label_create(ui_TopNavBar5);
    lv_obj_set_width(ui_NavBarTitle5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NavBarTitle5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NavBarTitle5, 0);
    lv_obj_set_y(ui_NavBarTitle5, -2);
    lv_obj_set_align(ui_NavBarTitle5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_NavBarTitle5, "Settings / Measurement");
    lv_obj_set_style_text_font(ui_NavBarTitle5, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BackBtn5 = lv_btn_create(ui_TopNavBar5);
    lv_obj_set_width(ui_BackBtn5, 12);
    lv_obj_set_height(ui_BackBtn5, 8);
    lv_obj_set_align(ui_BackBtn5, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_BackBtn5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BackBtn5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BackBtn5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BackBtn5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BackBtn5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_BackBtn5);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "<");
    lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_WindowSizeInp, ui_event_WindowSizeInp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SamplingPeriodInp, ui_event_SamplingPeriodInp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_WakeEnSwitch, ui_event_WakeEnSwitch, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_WakeEveryDrop, ui_event_WakeEveryDrop, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_WakeSampleDrop, ui_event_WakeSampleDrop, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BackBtn5, ui_event_BackBtn5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_MeasurementSettings, ui_event_MeasurementSettings, LV_EVENT_ALL, NULL);

}