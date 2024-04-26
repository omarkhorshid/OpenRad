#include <Arduino.h>
#include "geiger.h"
#include "settings.h"
#include "hardware.h"
#include "gui.h"

TaskHandle_t clicker_task;

uint16_t count = 0;
int event = 0;
int alarm_triggered = 0;
uint16_t count_window[300] = {0};
double measurement_history[HISTORY_WINDOW_SIZE] = {0};
int cpm = 0;
double usv = 0.0;
double cdose = get_ddose();
int geiger_counter_millis = millis();
int history_millis = millis();
int update_period = DEFAULT_MEASUREMENT_UPDATE_PERIOD;
int window_size = DEFAULT_MEASUREMENT_WINDOW_SIZE;

// increment count for each detection (under the UINT16 limit)
void IRAM_ATTR geiger_pulse()
{
    if (count < UINT16_MAX)
        count++;
    event = 1;
}

void measurement_init()
{
    window_size = get_measurement_window_size();
    update_period = get_measurement_update_period();
    cdose = get_ddose();
}

void reset_count_window()
{
    for (int i = 0; i < sizeof(count_window) / sizeof(uint16_t); i++)
    {
        count_window[i] = 0;
    }
}

void radiation_measurement(int window_size, int update_period, bool wakeup_sampling)
{
    // TODO: update the count window, so that when changed no visible spikes in measurment are formed
    // update measurments using an average and reset count
    if ((millis() - geiger_counter_millis) >= update_period)
    {
        for (int i = (window_size - 1); i > 0; i--)
        {
            count_window[i] = count_window[i - 1];
        }
        count_window[0] = count;

        cpm = 0;
        for (int i = 0; i < window_size; i++)
        {
            cpm += count_window[i];
        }
        cpm *= ((60000.0 / update_period) / window_size);
        count = 0;
        geiger_counter_millis = millis();
        usv = cpm / get_conversion_rate();
        if (!wakeup_sampling)
        {
            cdose += usv * (update_period / 3600000.0);
        }
    }
    if ((millis() - history_millis) >= (1000))
    {
        for (int i = 0; i < HISTORY_WINDOW_SIZE - 1; i++)
        {
            measurement_history[i] = measurement_history[i + 1];
        }
        measurement_history[HISTORY_WINDOW_SIZE - 1] = usv;
        history_millis = millis();
    }
}

int alarm_hyst_flg = 1;
// on detect pulse from gieger counter
void geiger_loop()
{
    clicker();
    sound_alarm();

    // if radiation is higher than threshold
    // trigger warning
    // and,if the alarm is enabled, trigger it too
    if (usv >= get_alarm_threshold())
    {
        warning_sign_triggered = 1;
        if (get_alarm_enabled())
        {
            alarm_triggered = 1;
            alarm_hyst_flg = 0;
        }
        else
        {
            alarm_triggered = 0;
        }
    }
    else if ((usv < (get_alarm_threshold()) * 0.75) && !alarm_hyst_flg)
    {
        alarm_hyst_flg = 1;
    }

    // if radiation is not higher than threshold
    // untrigger the warning and alarm
    else
    {
        warning_sign_triggered = 0;
        if (alarm_hyst_flg)
        {
            alarm_triggered = 0;
        }
    }

    window_size = get_measurement_window_size();
    update_period = get_measurement_update_period();
    radiation_measurement(window_size, update_period, false);
}

// getter functions
int get_cpm()
{
    return cpm;
}

double get_usv()
{
    return usv;
}

double get_dose()
{
    return cdose;
}

void set_dose(double dose)
{
    cdose = dose;
}

// reset functions
void reset_dose()
{
    cdose = 0;
    reset_ddose();
}

void get_history_data(double *data)
{
    for (int i = 0; i < HISTORY_WINDOW_SIZE; i++)
    {
        data[i] = measurement_history[i];
    }
}