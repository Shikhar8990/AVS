/*
 * mppt.c
 *
 *  Created on: Feb 4, 2014
 *      Author: ssingh14
 */

#include "DSP2833x_Device.h"
#include "Global.h"
#include "BoardInit.h"
#include "Timers.h"
#include "ADC.h"
#include "Serial.h"
#include "Debug.h"
#include "PWM.h"
#include "extern.h"

#define MPPT_STEP 0.01

float32 x_panel_voltage=0.0, x_panel_current=0.0;
float32 x_voltage=0.0, x_current=0.0;
float32 x_power=0.0, x_prev_power=0.0;
float32 x_panel_voltage_ref = 7;
int mppt_counter=0;

typedef enum {
	UP,
	DOWN
}mppt_direction;

mppt_direction updown = UP;

void mppt_fbcm_x(void)	{
	x_voltage = SensedCurrent_X_In;
	x_current = SensedVoltage_X_In;
	x_power = x_voltage * x_current;

	if(x_power < x_prev_power) {
		if(updown == UP)
			updown = DOWN;
		else
			updown = UP;
	}

	if(updown == DOWN)
		x_panel_voltage_ref -= MPPT_STEP;
	else
		x_panel_voltage_ref += MPPT_STEP;

	x_prev_power = x_power;
	x_panel_voltage = 0;
	x_panel_current = 0;
}

//x_current = (float)(x_panel_current)/400.0f;
//x_voltage = (float)(x_panel_voltage)/400.0f;


