/*
 * fbcm_control.h
 *
 *  Created on: April 8, 2014
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
#include "fbcm_control.h"
#include "mppt.h"
#include "fbcm_state_machine.h"
#include "gpio.h"

enum fbcm_mode fbcm1_mode = IDLE;
enum charging_mode charging1_mode = CC;

float duty_ratio_output_reg = 0.0, duty_ratio_mppt = 1.0;
float voltage_battery;

void fbcm_mode_select(){

	if(SensedVoltage_BATT_2 < VOLTAGE_LOW_LIMIT && SensedVoltage_BATT_1 > VOLTAGE_LOW_LIMIT){
		voltage_battery = SensedVoltage_BATT_2;
		Batt2_To_SwBatt_Disable();
		Batt1_To_SwBatt_Enable();
		FBCM_To_Batt1_Disable();
		FBCM_To_Batt2_Enable();
	}

	if(SensedVoltage_BATT_1 < VOLTAGE_LOW_LIMIT && SensedVoltage_BATT_2 > VOLTAGE_LOW_LIMIT){
		voltage_battery = SensedVoltage_BATT_1;
		Batt2_To_SwBatt_Enable();
		Batt1_To_SwBatt_Disable();
		FBCM_To_Batt1_Enable();
		FBCM_To_Batt2_Disable();
	}

	if(current < CURRENT_LIMIT && fbcm1_mode == BATTERY){
		fbcm1_mode = IDLE;
	}

	if(SensedVoltage_BATT_2 < VOLTAGE_LOW_LIMIT && fbcm1_mode == IDLE){
		fbcm1_mode = BATTERY;
		charging1_mode = CC;
	}

	if(SensedVoltage_BATT_2 >= VOLTAGE_LIMIT && fbcm1_mode == BATTERY && charging1_mode == CC){
		charging1_mode = CV;
	}

	if(current < CURRENT_LIMIT && fbcm1_mode == BATTERY && charging1_mode == CV){
		fbcm1_mode = IDLE;
	}

	if(duty_ratio_output_reg < duty_ratio_mppt && fbcm1_mode == BATTERY){
		fbcm1_mode = MPPT;
	}

	if(duty_ratio_output_reg > duty_ratio_mppt && fbcm1_mode == MPPT){
		fbcm1_mode = BATTERY;
	}

	if(fbcm1_mode == BATTERY && charging1_mode == CC){
			control_fbcm1_cc();
	}
	if(fbcm1_mode == BATTERY && charging1_mode == CV){
		control_fbcm1_cv();
	}
	if(fbcm1_mode == MPPT){
		if(mppt_counter == 10){
				mppt_fbcm_x();
				mppt_counter = 0;
	}
		input_control_fbcm_x(); // The input voltage PI loop should run faster than the MPPT VREF code
		mppt_counter++;
	}
}
