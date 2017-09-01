/*
 * central_control.c
 *
 *  Created on: Mar 28, 2014
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
#include "pid_control.h"
#include "Gpio.h"
#include "fbcm_control.h"
#include "mppt.h"
#include "fbcm_state_machine.h"

int cnt = 1;
void Control(void)
{

	ADCConversionEnd = 1;
	current= (float)(current_x/4.0f);

	#ifdef PID_CONTROL
		/*---------------Run FDPOL converters--------------*/
		//pid_control_buck1();
		//pid_control_buck3();
		//pid_control_boost2();
		//pid_control_boost4();
		/*-------------------------------------------------*/

		/*---------------State Machine Code----------------*/
		//fbcm_mode_select();
		/*-------------------------------------------------*/

		/*---------------Old code segment------------------*/
				control_fbcm1_cv();
				//control_fbcm1_cc();
				/*if(mppt_counter == 10){
					mppt_fbcm_x();
					//input_control_fbcm_x();
					mppt_counter = 0;
				}
				input_control_fbcm_x();
				mppt_counter++;
		/*-------------------------------------------------*/

	#endif
	current_x = 0;
	ADCConversionEnd = 1;

	EPwm1Regs.CMPA.half.CMPA = FBCM1_Buck_EPwmOnTime;
	EPwm1Regs.CMPB = POL1_EPwmOnTime;
	EPwm2Regs.CMPA.half.CMPA = FBCM1_Boost_EPwmOnTime;
	EPwm2Regs.CMPB = POL2_EPwmOnTime;
	EPwm3Regs.CMPB = POL3_EPwmOnTime;
	EPwm4Regs.CMPB = POL4_EPwmOnTime;
	EPwm3Regs.CMPA.half.CMPA = FBCM2_Buck_EPwmOnTime;
	EPwm4Regs.CMPA.half.CMPA = FBCM2_Boost_EPwmOnTime;
	EPwm5Regs.CMPA.half.CMPA = FBCM3_Buck_EPwmOnTime;
	EPwm6Regs.CMPA.half.CMPA = FBCM3_Boost_EPwmOnTime;
}
