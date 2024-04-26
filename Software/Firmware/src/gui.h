#ifndef GUI_H
#define GUI_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <SPI.h>
extern TFT_eSPI tft;
#else
#define EXTERNC
#endif

extern int warning_sign_triggered;

// Function to flush the display
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

// Function to read encoder and button states
void key_input_driver(lv_indev_drv_t *drv, lv_indev_data_t *data);

// Function for the graphics task
void graphics_task_handler(void *pvParameters);

// Function to initialize the GUI
void gui_init();

void enable_nav_input(bool en);

void show_warning_sign(bool en);

EXTERNC void update_main_page_objects(double sv, int cpm, double cdose);
EXTERNC void update_graph_page();

EXTERNC void update_screens();

// State variables for buttons (declared as extern to avoid multiple definitions)
extern int upbutton_state;
extern int dwnbutton_state;
extern int okbutton_state;

#undef EXTERNC
#endif // GUI_H
