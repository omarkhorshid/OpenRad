#ifndef GEIGER_H
#define GEIGER_H

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

extern int event;
extern int alarm_triggered;

void IRAM_ATTR geiger_pulse();
void geiger_loop();
int get_cpm();
double get_usv();
double get_dose();
void set_dose(double dose);
EXTERNC void reset_dose();
EXTERNC void reset_count_window();
void radiation_measurement(int window_size, int update_period, bool wakeup_sampling);
void measurement_init();
void get_history_data(double *data);

#undef EXTERNC
#endif