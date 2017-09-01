/*
 * fbcm_control.h
 *
 *  Created on: April 8, 2014
 *      Author: ssingh14
 */

enum fbcm_mode {BATTERY, MPPT, IDLE};
enum charging_mode {CC, CV};

void fbcm_mode_select(void);

#define VOLTAGE_LIMIT 8.4
#define CURRENT_LIMIT 0.1
#define VOLTAGE_LOW_LIMIT 7.0
