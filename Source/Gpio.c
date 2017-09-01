// DSP2833x_SysCtrl.c
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "Global.h"
#include "Gpio.h"
#include "extern.h"
void InitGpio(void)
{
	Batt2_To_SwBatt_Disable();
	Batt1_To_SwBatt_Enable();
	FBCM_To_SwBatt_Disable();
	FBCM_To_Batt1_Disable();
	FBCM_To_Batt2_Enable();
	Pol_1_3_Out_Select(Pol1_Out_Vi);
	Pol_2_4_Out_Select(Pol2_Out_Vi);
	Pol_1_3_CS_Select(Pol1_CS_Vi);
	Pol_2_4_CS_Select(Pol2_CS_Vi);
	Solar_Power_Available();
	Batt_1_2_Select(Batt1_Vi);
//	Solar_Power_UnAvailable();
}

void Solar_Power_Available(void)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;
	GpioDataRegs.GPACLEAR.bit.GPIO28 = 1;
	EDIS;
}
void Solar_Power_UnAvailable(void)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;
	GpioDataRegs.GPASET.bit.GPIO28 = 1;
	EDIS;
}

void FBCM_To_Batt2_Enable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;
	GpioDataRegs.GPBSET.bit.GPIO61 = 1;
	EDIS;
}

void FBCM_To_Batt2_Disable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;
	GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
	EDIS;
}


void FBCM_To_Batt1_Enable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;
	GpioDataRegs.GPBSET.bit.GPIO60 = 1;
	EDIS;
}

void FBCM_To_Batt1_Disable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;
	GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
	EDIS;
}


void FBCM_To_SwBatt_Enable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;
	GpioDataRegs.GPBSET.bit.GPIO34 = 1;
	EDIS;
}

void FBCM_To_SwBatt_Disable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;
	GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
	EDIS;
}



void Batt1_To_SwBatt_Enable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO62 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;
	GpioDataRegs.GPBSET.bit.GPIO62 = 1;
	EDIS;
}

void Batt1_To_SwBatt_Disable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO62 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;
	GpioDataRegs.GPBCLEAR.bit.GPIO62 = 1;
	EDIS;
}

void Batt2_To_SwBatt_Enable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;
	GpioDataRegs.GPBSET.bit.GPIO63 = 1;
	EDIS;
}

void Batt2_To_SwBatt_Disable(void)
{
	EALLOW;
	GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;
	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;
	GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1;
	EDIS;
}


void Pol_1_3_Out_Select(ADC_IN_Select Pol1_3_Out)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;
	if(Pol1_Out_Vi == Pol1_3_Out)
	{
		GpioDataRegs.GPASET.bit.GPIO12 = 1;
		ADC_VIn_Pol_1_3 = Pol1_Out_Vi;
	}
	else if(Pol3_Out_Vi == Pol1_3_Out)
	{
		GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;
		ADC_VIn_Pol_1_3 = Pol3_Out_Vi;
	}
	EDIS;
}

void Pol_2_4_Out_Select(ADC_IN_Select Pol_2_4_Out)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;
	if(Pol2_Out_Vi == Pol_2_4_Out)
	{
		GpioDataRegs.GPASET.bit.GPIO15 = 1;
		ADC_VIn_Pol_2_4 = Pol2_Out_Vi;
	}
	else if(Pol4_Out_Vi == Pol_2_4_Out)
	{
		GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
		ADC_VIn_Pol_2_4 = Pol4_Out_Vi;
	}
	EDIS;
}

void Batt_1_2_Select(ADC_IN_Select Batt_1_2)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;
	if(Batt2_Vi == Batt_1_2)
		GpioDataRegs.GPASET.bit.GPIO11 = 1;
	else if(Batt1_Vi == Batt_1_2)
		GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
	EDIS;
}

void Pol_1_3_CS_Select(ADC_IN_Select Ana_1_3_Sel1)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;
	GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;
	GpioCtrlRegs.GPBPUD.bit.GPIO49 = 0;
	if(Pol1_CS_Vi == Ana_1_3_Sel1)
	{
		GpioDataRegs.GPASET.bit.GPIO13 = 1;
		GpioDataRegs.GPBSET.bit.GPIO49 = 1;
	}
	else if(Pol3_CS_Vi == Ana_1_3_Sel1)
	{
		GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
		GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
	}
	EDIS;
}

void Pol_2_4_CS_Select(ADC_IN_Select Ana_2_4_Sel1)
{
	EALLOW;
	GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;
	if(Pol2_CS_Vi == Ana_2_4_Sel1)
		GpioDataRegs.GPASET.bit.GPIO14 = 1;
	else if(Pol3_CS_Vi == Ana_2_4_Sel1)
		GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;
	EDIS;
}

