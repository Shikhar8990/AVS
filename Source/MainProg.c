#include "DSP2833x_Device.h"
#include "Global.h"
#include "BoardInit.h"
#include "Timers.h"
#include "ADC.h"
#include "Serial.h"
#include "Debug.h"
#include "PWM.h"
#include "extern.h"
#include "Gpio.h"
#include "pid_control.h"
#include "mppt.h"
#include "fbcm_control.h"
//#include <stdio.h>


float32 VoltSensed[100];

Uint16 ADCSensed_POL1[100];
Uint16 ADCSensed_POL2[100];
Uint16 ADCSensed_BATT1[100];
Uint16 ADCSensed_Curr1[100];

FBCM_State FBCM1_State = FBCM_Off_State;
FBCM_State FBCM2_State = FBCM_Off_State;



float ConvertStrToFloat(char* str)
{
	float fReturn = 0.0;
	float Multiplier = 0.1;
	int i = 0;

	while(str[i] != '.' && str[i] != '\0') {
		fReturn *= 10;
		fReturn += str[i] - '0';
		i++;
	}

	if(str[i] == '\0')
		return fReturn;
	i++;
	while(str[i] != '\0') {
		fReturn += (str[i] - '0') * Multiplier;
		Multiplier *= 0.1;
		i++;
	}
	return fReturn;
}

void Command()
{
	float Temp;
	switch(ReceivedStr[0]) {
	case FDPOL1_EN:
		break;

	case FDPOL1_Vout_SET:
		Temp = ConvertStrToFloat(&(ReceivedStr[2]));
		if (Temp < SensedVoltage_SWBATT) {
			SetOutputVoltage_POL1 = Temp;
			RequiredADCCount_POL1 = (SetOutputVoltage_POL1/POL1_ADJUST) * (234.13);
		}
		break;

	case FDPOL1_Iout_SET:
		break;

	case FDPOL2_EN:
		break;

	case FDPOL2_Vout_SET:
		/*Temp = ConvertStrToFloat(&(ReceivedStr[2]));
		if (Temp > SensedVoltage_SWBATT) {
			SetOutputVoltage_POL2 = Temp;
			RequiredADCCount_POL2 = (SetOutputVoltage_POL2/0.92) * (234.13);
		}*/
		break;

	case FDPOL2_Iout_SET:
		break;

	case FDPOL3_EN:
		break;

	case FDPOL3_Vout_SET:
		/*Temp = ConvertStrToFloat(&(ReceivedStr[2]));
		if (Temp < SensedVoltage_SWBATT) {
			SetOutputVoltage_POL3 = Temp;
			RequiredADCCount_POL3 = (SetOutputVoltage_POL3/0.92) * (234.13);
		}*/
		break;

	case FDPOL3_Iout_SET:
		break;

	case FDPOL4_EN:
		break;

	case FDPOL4_Vout_SET:
		/*Temp = ConvertStrToFloat(&(ReceivedStr[2]));
		if (Temp > SensedVoltage_SWBATT) {
			SetOutputVoltage_POL4 = Temp;
			RequiredADCCount_POL4 = (SetOutputVoltage_POL4/0.92) * (234.13);
		}*/
		break;


	case FDPOL4_Iout_SET:
		break;

	case SWBATT_EN:
		break;

	case BATT1_EN:
		break;

	case BATT2_EN:
		break;

	case FBCM1_EN:
		break;
	case FBCM1_Vout_SET:
		//SetOutputVoltage_FBCM = ConvertStrToFloat(&(ReceivedStr[2]));
		//RequiredADCCount_FBCM1 = (SetOutputVoltage_FBCM/0.92) * (234.13);
		break;
	case FBCM1_Iout_SET:
		break;

	case FBCM2_EN:
		break;
	case FBCM2_Vout_SET:
		SetOutputVoltage_FBCM = ConvertStrToFloat(&(ReceivedStr[2]));
		RequiredADCCount_FBCM2 = (SetOutputVoltage_FBCM/0.92) * (234.13);
		break;
	case FBCM2_Iout_SET:
		break;

	case FBCM3_EN:
		break;
	case FBCM3_Vout_SET:
		SetOutputVoltage_FBCM = ConvertStrToFloat(&(ReceivedStr[2]));
		RequiredADCCount_FBCM3 = (SetOutputVoltage_FBCM/0.92) * (234.13);
		break;
	case FBCM3_Iout_SET:
		break;

/*	case Set_FDPOL1_Vout:
		SetOutputVoltage_POL1 = ConvertStrToFloat(&(ReceivedStr[2]));
		RequiredADCCount_POL1 = (SetOutputVoltage_POL1/0.92) * (234.13);
		break;
*/	}
}

void main()
{
	InitBoard();
	ConfigTimer0(100);
	StartTimer0();
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;
	GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;
	
	EDIS;

	while(1)
	{
		
		
//		AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;
		
		//StartADC_Seq1();
		//scia_msg("A-");
		//scia_msg("Sending Test Message\n");

		if(1 == UARTTransmit) {
			UARTTransmit = 0;

//			scia_xmit('A');
			
	//		Debug_ADC_Val_All();
			
			
			Debug_FBCM_1();
			//Debug_FBCM_2();
			
//			Debug_Voltage_Batt_1();
			
	//		Debug_Voltage_Batt_2();
			
		//	Debug_Voltage_SWBatt();
			
			//Debug_Pol_1();
			//Debug_Pol_2();
			//Debug_Pol_3();
			
			
//			Debug_FBCM_2();
//			Debug_FBCM_3();
//			Debug_ADC_Val_08();

//			Debug_ADC_Voltage_Pol_1();
//			Debug_Voltage_Pol_1();
//			Debug_ADC_Current_Pol_1();
//			Debug_Current_Pol_1();

			//Debug_ADC_Voltage_Pol_2();
			//Debug_Voltage_Pol_2();

	//		Debug_Current_Pol_2();
//
	//		Debug_ADC_Current_Pol_2();
//
	//		Debug_Voltage_SWBatt();
		//	Debug_ADC_Voltage_SWBatt();

		}


		if(Received == 1) {
			//Command();
			Received = 0;
		}
 
	}

}
