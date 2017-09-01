/*
 * fbcm_control.c
 *
 *  Created on: Mar 21, 2014
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


pidParams_t fbcm_x;
pidParams_t	pid_FBCM_buck	=	{0.0,0.0,0.0,0.0,0.0,0.0};			// FBCM voltage mode control parameters
pidParams_t	pid_FBCM_boost	=	{0.0,0.0,0.0,0.0,0.0,0.0};			// FBCM voltage mode control parameters
pidParams_c	pid_FBCM_buck_o =	{0.0,0.0,0.0,0.0,0.0,0.0};			// FBCM voltage mode control parameters - outer loop
pidParams_c	pid_FBCM_boost_o=	{0.0,0.0,0.0,0.0,0.0,0.0};			// FBCM voltage mode control parameters - outer loop

void control_fbcm1_cv(void){

	if(SensedADC_X_In < MIN_INPUT_VOLTAGE_ADC)
	{
		//FBCM1_State = FBCM_Off_State;
		FBCM1_Buck_EPwmOnTime = 0;
		FBCM1_Boost_EPwmOnTime = 0;
	}
	else
	{
		if(SensedVoltage_X_In < SetOutputVoltage_FBCM-1) // margin of 1
		{
			//Buck Converter is bypassed
			FBCM1_Buck_EPwmOnTime = 1000;

			//Boost Converter is run
			pid_FBCM_boost.error = SetOutputVoltage_FBCM - SensedVoltage_FBCM_Out;

			//resitive loop
			//pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) +  0.000020903*(pid_FBCM_boost.error + pid_FBCM_boost.error_1);


			pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) + 0.010865*(pid_FBCM_boost.error + pid_FBCM_boost.error_1);

			//new one with battery load, 1000 rad/sec
			//pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) +  0.074079*(pid_FBCM_boost.error - 0.8978*pid_FBCM_boost.error_1);

			if(pid_FBCM_boost.duty<0.01)
				pid_FBCM_boost.duty=0.01;
			if(pid_FBCM_boost.duty>0.80)
				pid_FBCM_boost.duty = 0.80;

			FBCM1_Boost_EPwmOnTime = 1000 - pid_FBCM_boost.duty*1000;
			pid_FBCM_boost.duty_1 = pid_FBCM_boost.duty;
			pid_FBCM_boost.error_1 = pid_FBCM_boost.error;
			//FBCM1_State = FBCM_Boost_State;
		}

		if(SensedVoltage_X_In > SetOutputVoltage_FBCM+1)
		{
			//Boost Converter is bypassed
			FBCM1_Boost_EPwmOnTime = 1000;

			//Buck Converter is run
			pid_FBCM_buck.error = SetOutputVoltage_FBCM - SensedVoltage_FBCM_Out;
			//slower loop 54.9 rad/sec
			pid_FBCM_buck.duty = (pid_FBCM_buck.duty_1) + 0.020009*(pid_FBCM_buck.error + pid_FBCM_buck.error_1);

			if(pid_FBCM_buck.duty<0.01)
				pid_FBCM_buck.duty=0.01;
			if(pid_FBCM_buck.duty>0.98)
				pid_FBCM_buck.duty = 0.98;

			FBCM1_Buck_EPwmOnTime = pid_FBCM_buck.duty*1000;
			pid_FBCM_buck.duty_1 = pid_FBCM_buck.duty;
			pid_FBCM_buck.error_1 = pid_FBCM_buck.error;
			//FBCM1_State = FBCM_Buck_State;
		}
		if((SetOutputVoltage_FBCM-1 <= SensedVoltage_X_In)  && (SensedVoltage_X_In <= SetOutputVoltage_FBCM+1))
		{
			FBCM1_Boost_EPwmOnTime = 1000;
			FBCM1_Buck_EPwmOnTime = 1000;
		}
	}
	duty_ratio_output_reg = pid_FBCM_boost.duty;
}

void control_fbcm1_cc(void){

	//SetOutputVoltage_FBCM = SetOutputCurrent_FBCM*10;
	if(SensedADC_X_In < MIN_INPUT_VOLTAGE_ADC)
	{
		//FBCM1_State = FBCM_Off_State;
		FBCM1_Buck_EPwmOnTime = 0;
		FBCM1_Boost_EPwmOnTime = 0;
	}
	else
	{
		if(SensedVoltage_X_In < SetOutputVoltage_FBCM-1) // margin of 1
		{
			//Buck Converter is bypassed
			FBCM1_Buck_EPwmOnTime = 1000;

			//outer current loop
			pid_FBCM_boost_o.error = SetOutputCurrent_FBCM - current;
			pid_FBCM_boost_o.voltage = (pid_FBCM_boost_o.voltage_1) + 0.0045312*(pid_FBCM_boost_o.error + pid_FBCM_boost_o.error_1);

			//voltage reference determined by the outer loop
			voltage_ref = pid_FBCM_boost_o.voltage;

			//inner voltage loop
			pid_FBCM_boost.error = pid_FBCM_boost_o.voltage - SensedVoltage_FBCM_Out;
			pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) + 0.010865*(pid_FBCM_boost.error + pid_FBCM_boost.error_1);

			if(pid_FBCM_boost.duty<0.01)
				pid_FBCM_boost.duty=0.01;
			if(pid_FBCM_boost.duty>0.80)
				pid_FBCM_boost.duty = 0.80;

			FBCM1_Boost_EPwmOnTime = 1000 - pid_FBCM_boost.duty*1000;
			pid_FBCM_boost_o.voltage_1 = pid_FBCM_boost_o.voltage;
			pid_FBCM_boost_o.error_1 = pid_FBCM_boost_o.error;
			pid_FBCM_boost.duty_1 = pid_FBCM_boost.duty;
			pid_FBCM_boost.error_1 = pid_FBCM_boost.error;
		}

		if(SensedVoltage_X_In > SetOutputVoltage_FBCM+1)
		{
			//Boost Converter is bypassed
			FBCM1_Boost_EPwmOnTime = 1000;

			//Buck Converter is run - RESISTIVE LOAD
			pid_FBCM_buck_o.error = SetOutputCurrent_FBCM - current;
			//pid_FBCM_buck_o.voltage = (pid_FBCM_buck_o.voltage_1) + 0.001923*(pid_FBCM_buck_o.error + pid_FBCM_buck_o.error_1);
			pid_FBCM_buck_o.voltage = (pid_FBCM_buck_o.voltage_1) + 0.0060011*(pid_FBCM_buck_o.error + pid_FBCM_buck_o.error_1);
			pid_FBCM_buck.error = pid_FBCM_buck_o.voltage - SensedVoltage_FBCM_Out;
			pid_FBCM_buck.duty = (pid_FBCM_buck.duty_1) + 0.027789*(pid_FBCM_buck.error + pid_FBCM_buck.error_1);

			if(pid_FBCM_buck.duty<0.01)
				pid_FBCM_buck.duty=0.01;
			if(pid_FBCM_buck.duty>0.98)
				pid_FBCM_buck.duty = 0.98;

			FBCM1_Buck_EPwmOnTime = pid_FBCM_buck.duty*1000;


			pid_FBCM_buck_o.voltage_1 = pid_FBCM_buck_o.voltage;
			pid_FBCM_buck_o.error_1 = pid_FBCM_buck_o.error;
			pid_FBCM_buck.duty_1 = pid_FBCM_buck.duty;
			pid_FBCM_buck.error_1 = pid_FBCM_buck.error;
			//FBCM1_State = FBCM_Buck_State;
		}
		if((SetOutputVoltage_FBCM-1 <= SensedVoltage_X_In)  && (SensedVoltage_X_In <= SetOutputVoltage_FBCM+1))
		{
			FBCM1_Boost_EPwmOnTime =900;
			FBCM1_Buck_EPwmOnTime = 900;
		}
	}
	duty_ratio_output_reg = pid_FBCM_boost.duty;
}

void input_control_fbcm_x() {

	fbcm_x.error =   (float32)x_panel_voltage_ref - (float32)SensedVoltage_X_In;

	fbcm_x.duty = (fbcm_x.duty_1) - 0.079*(fbcm_x.error + fbcm_x.error_1);
	if(fbcm_x.duty<0.20)
			fbcm_x.duty=0.20;
		if(fbcm_x.duty>0.8)
			fbcm_x.duty = 0.8;

	duty_ratio_mppt = fbcm_x.duty;
	FBCM1_Boost_EPwmOnTime = 1000 - fbcm_x.duty*1000;

	fbcm_x.duty_1 = fbcm_x.duty;
	fbcm_x.error_1 = fbcm_x.error;
}

/*	if(fbcm_x.error > 0){
		FBCM1_Boost_EPwmOnTime++;
	}
	else{
		FBCM1_Boost_EPwmOnTime--;
	}
	if(FBCM1_Boost_EPwmOnTime<200)
		FBCM1_Boost_EPwmOnTime=200;
	if(FBCM1_Boost_EPwmOnTime>800)
		FBCM1_Boost_EPwmOnTime = 800;
*/
