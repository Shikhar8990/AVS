//*********************************************************************************************
/*										PID CONTROL
				PID control implementation of Point of Load Converters

Author - Shikhar Singh
Start Date - 14th May 2013

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

//structure to store the PID control parameters of a converter

/*typedef struct
{
	float32 error, error_1, error_2;
	float32 duty, duty_1, duty_2;
}pidParams_t;*/

pidParams_t pid_FDPOL1_Vout;									// Buck 1 voltage control parameters
pidParams_t pid_FDPOL3_Vout;									// Buck 3 voltage control parameters
pidParams_t pid_FDPOL2_Vout={0.0,0.0,0.0,0.0,0.0,0.0};			// Boost2 voltage control parameters
pidParams_t pid_FDPOL4_Vout={0.0,0.0,0.0,0.0,0.0,0.0};			// Boost4 voltage control parameters


//									PID control of Buck Converter 1
/*
	Vin = 7V
	Vout = 3V
 */

void pid_control_buck1(void)
{
	pid_FDPOL1_Vout.error =   (float32)SetOutputVoltage_POL1 - (float32)SensedVoltage_POL_1 ;

	pid_FDPOL1_Vout.duty = 	(pid_FDPOL1_Vout.duty_1) + 0.027789*(pid_FDPOL1_Vout.error + pid_FDPOL1_Vout.error_1);

	if(pid_FDPOL1_Vout.duty<0.1)
		pid_FDPOL1_Vout.duty=0.1;
	if(pid_FDPOL1_Vout.duty>0.98)
		pid_FDPOL1_Vout.duty = 0.98;

	POL1_EPwmOnTime = pid_FDPOL1_Vout.duty*1000;

	pid_FDPOL1_Vout.duty_1 = pid_FDPOL1_Vout.duty;
	pid_FDPOL1_Vout.error_1 = pid_FDPOL1_Vout.error;
}


//									PID control of Buck Converter 3
/*
	Vin = 7V
	Vout = 3V
 */

void pid_control_buck3(void)
{
	pid_FDPOL3_Vout.error =   (float32)SetOutputVoltage_POL3 - (float32)SensedVoltage_POL_3;

	//pi loop 15000 rad/s - sampling freq 150khz
	//pid_FDPOL3_Vout.duty = (pid_FDPOL3_Vout.duty_1) + 0.050000*(pid_FDPOL3_Vout.error - 0.9619*pid_FDPOL3_Vout.error_1);

	//pi loop 2500 rad/s - sampling period 200 micro sound
	//pid_FDPOL3_Vout.duty = (pid_FDPOL3_Vout.duty_1) + 0.003973*(pid_FDPOL3_Vout.error - 0.1524*pid_FDPOL3_Vout.error_1);

	//pi loop 4000 rad/s - sampling period 100 micro second
	//used for thesis and based on the model of buck converter on TI application note ...
	pid_FDPOL3_Vout.duty = (pid_FDPOL3_Vout.duty_1) + 0.027789*(pid_FDPOL3_Vout.error + pid_FDPOL3_Vout.error_1);

	if(pid_FDPOL3_Vout.duty<0.1)
		pid_FDPOL3_Vout.duty=0.1;
	if(pid_FDPOL3_Vout.duty>0.98)
		pid_FDPOL3_Vout.duty = 0.98;

	POL3_EPwmOnTime = pid_FDPOL3_Vout.duty*1000;

	pid_FDPOL3_Vout.duty_1 = pid_FDPOL3_Vout.duty;
	pid_FDPOL3_Vout.error_1 = pid_FDPOL3_Vout.error;
}


//									PI control of Boost Converter 2
/*
 * PI compensator closed loop transfer function
 * s
 * Vin = 7.2V, Vout = 10V
 */
void pid_control_boost2(void)
{

	pid_FDPOL2_Vout.error = (float32)SetOutputVoltage_POL2 - (float32)SensedVoltage_POL_2 ;

	//100ma current
	//pid_FDPOL2_Vout.duty = (pid_FDPOL2_Vout.duty_1) + 0.02748*(pid_FDPOL2_Vout.error - 0.9988*pid_FDPOL2_Vout.error_1);

	//1 amp cuurent
	pid_FDPOL2_Vout.duty = (pid_FDPOL2_Vout.duty_1) + 0.010865*(pid_FDPOL2_Vout.error + pid_FDPOL2_Vout.error_1);

	//fbcm test
	//pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) +  4.1996e-05*(pid_FBCM_boost.error + pid_FBCM_boost.error_1);

	if(pid_FDPOL2_Vout.duty<0.01)
		pid_FDPOL2_Vout.duty=0.01;
	if(pid_FDPOL2_Vout.duty>0.80)
		pid_FDPOL2_Vout.duty = 0.80;

	POL2_EPwmOnTime = 1000 - pid_FDPOL2_Vout.duty*1000;

	pid_FDPOL2_Vout.duty_1 = pid_FDPOL2_Vout.duty;
	pid_FDPOL2_Vout.error_1 = pid_FDPOL2_Vout.error;
}

//									PI control of Boost Converter 4
/*
 * PI compensator closed loop transfer function
 * s
 * Vin = 7.2V, Vout = 10V
 */

void pid_control_boost4(void)
{

	pid_FDPOL4_Vout.error = (float32)SetOutputVoltage_POL4 - (float32)SensedVoltage_POL_4 ;

	//100ma current
	//pid_FDPOL2_Vout.duty = (pid_FDPOL2_Vout.duty_1) + 0.02748*(pid_FDPOL2_Vout.error - 0.9988*pid_FDPOL2_Vout.error_1);

	//1 amp cuurent
	pid_FDPOL4_Vout.duty = (pid_FDPOL4_Vout.duty_1) + 0.00020903*(pid_FDPOL4_Vout.error + pid_FDPOL4_Vout.error_1);

	//fbcm test
	//pid_FBCM_boost.duty = (pid_FBCM_boost.duty_1) +  4.1996e-05*(pid_FBCM_boost.error + pid_FBCM_boost.error_1);

	if(pid_FDPOL4_Vout.duty<0.01)
		pid_FDPOL4_Vout.duty=0.01;
	if(pid_FDPOL4_Vout.duty>0.80)
		pid_FDPOL4_Vout.duty = 0.80;

	POL4_EPwmOnTime = 1000 - pid_FDPOL4_Vout.duty*1000;

	pid_FDPOL4_Vout.duty_1 = pid_FDPOL4_Vout.duty;
	pid_FDPOL4_Vout.error_1 = pid_FDPOL4_Vout.error;
}



