// DSP2833x_SysCtrl.c
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_Adc.h"
#include "DSP2833x_Examples.h"   // Examples Include File
#include "Global.h"
#include "ISRs.h"
#include "ADC.h"
#include "Gpio.h"
#include "extern.h"

Uint16 uiADC00 = 0;
Uint16 uiADC01 = 0;
Uint16 uiADC02 = 0;
Uint16 uiADC03 = 0;
Uint16 uiADC04 = 0;
Uint16 uiADC05 = 0;
Uint16 uiADC06 = 0;
Uint16 uiADC07 = 0;
Uint16 uiADC08 = 0;
Uint16 uiADC09 = 0;
Uint16 uiADC10 = 0;
Uint16 uiADC11 = 0;
Uint16 uiADC12 = 0;
Uint16 uiADC13 = 0;
Uint16 uiADC14 = 0;
Uint16 uiADC15 = 0;


float32 SensedVoltage_X_In = 0;
float32 SensedVoltage_Y_In = 0;
float32 SensedVoltage_Z_In = 0;
Uint16 SensedADC_X_In = 0;
Uint16 SensedADC_Y_In = 0;
Uint16 SensedADC_Z_In = 0;

float32 SensedVoltage_FBCM_Out = 0;
Uint16 SensedADC_FBCM_Out = 0;

float32 SensedCurrent_X_In = 0;
float32 SensedCurrent_Y_In = 0;
float32 SensedCurrent_Z_In = 0;
Uint16 SensedADC_Cur_X_In = 0;
Uint16 SensedADC_Cur_Y_In = 0;
Uint16 SensedADC_Cur_Z_In = 0;

float32 SensedCurrent_FBCM_X = 0;
float32 SensedCurrent_FBCM_Y = 0;
float32 SensedCurrent_FBCM_X_average = 0;
float32 SensedCurrent_FBCM_Z = 0;
Uint16 SensedADC_Cur_FBCM_X = 0;
Uint16 SensedADC_Cur_FBCM_Y = 0;
Uint16 SensedADC_Cur_FBCM_Z = 0;

float32 SensedVoltage_POL_1 = 0;
float32 SensedVoltage_POL_2 = 0;
float32 SensedVoltage_POL_3 = 0;
float32 SensedVoltage_POL_4 = 0;
Uint16 SensedADC_POL_1 = 0;
Uint16 SensedADC_POL_2 = 0;
Uint16 SensedADC_POL_3 = 0;
Uint16 SensedADC_POL_4 = 0;

float32 SensedVoltage_BATT_1 = 0;
float32 SensedVoltage_BATT_2 = 0;
Uint16 SensedADC_BATT_1 = 0;
Uint16 SensedADC_BATT_2 = 0;

float32 SensedVoltage_SWBATT = 0;
Uint16 SensedADC_SWBATT = 0;

float32 SensedCurrent_POL_1 = 0;
float32 SensedCurrent_POL_2 = 0;
float32 SensedCurrent_POL_3 = 0;
float32 SensedCurrent_POL_4 = 0;
float32 sensed_node_voltage = 0;
float32 sensed_node_voltage_prev = 0;
float32 SensedADC_CUR_1 = 0;
Uint16 SensedADC_CUR_2 = 0;
Uint16 SensedADC_CUR_3 = 0;
Uint16 SensedADC_CUR_4 = 0;

float SetOutputVoltage_POL1=4.8;
float SetOutputVoltage_POL2=10;
float SetOutputVoltage_POL3=3.3;
float SetOutputVoltage_POL4=8;
float SetOutputVoltage_FBCM=8;
float SetOutputCurrent_FBCM=0.5;
//float SetOutputVoltage_FBCM2=0;
//float SetOutputVoltage_FBCM3=0;

Uint16 RequiredADCCount_POL1 = 0;
Uint16 RequiredADCCount_POL2 = 0;
Uint16 RequiredADCCount_POL3 = 0;
Uint16 RequiredADCCount_POL4 = 0;
Uint16 RequiredADCCount_FBCM1 = 0;
Uint16 RequiredADCCount_FBCM2 = 0;
Uint16 RequiredADCCount_FBCM3 = 0;

int16 FBCM1_Buck_EPwmOnTime = 0;
int16 FBCM1_Boost_EPwmOnTime = 0;
int16 FBCM2_Buck_EPwmOnTime = 0;
int16 FBCM2_Boost_EPwmOnTime = 0;
int16 FBCM3_Buck_EPwmOnTime = 0;
int16 FBCM3_Boost_EPwmOnTime = 0;

int16 POL1_EPwmOnTime = 0;
int16 POL2_EPwmOnTime = 0;
int16 POL3_EPwmOnTime = 0;
int16 POL4_EPwmOnTime = 0;

Uint16 ADCConversionEnd = 1;
Uint16 UARTTransmit = 1;

ADC_IN_Select ADC_VIn_Pol_1_3 = Pol3_Out_Vi;
ADC_IN_Select ADC_VIn_Pol_2_4 = Pol4_Out_Vi;
ADC_IN_Select Batt_Vin_1_2 = Batt1_Vi;
ADC_IN_Select ADC_Iin_Pol_1_3 = Pol1_CS_Vi;
ADC_IN_Select ADC_Iin_Pol_2_4 = Pol2_CS_Vi;

Uint16 FBCM1_PWM_Served = 0;

char ReceivedStr[25] = "";
Uint16 Received = 0;

static unsigned int uiWaitCounter = 0;

int Voltage_X_In = 0;
int Voltage_Y_In = 0;
int Voltage_Z_In = 0;
int Voltage_FBCM_Out = 0;
int Current_X_In = 0;
int Current_Y_In = 0;
int Current_Z_In = 0;
int Current_X_FBCM = 0;
int Current_Y_FBCM = 0;
int Current_Z_FBCM = 0;
int Voltage_POL_1_3 = 0;
int Voltage_POL_2_4 = 0;
int Current_POL_1_3 = 0;
int Current_POL_2_4 = 0;
int Voltage_SWBATT = 0;
int Voltage_BATT_1_2 = 0;

//my variables
int current_counter = 0;
float current_x = 0;
float current = 0,voltage_ref = 0.0;
int switch_counter = 1;

interrupt void  adc_isr(void)
{


	GpioDataRegs.GPASET.bit.GPIO31 = 1;
	
	DINT;

	uiADC00 = AdcRegs.ADCRESULT0 >> 4;
	uiADC01 = AdcRegs.ADCRESULT1 >> 4;
	uiADC02 = AdcRegs.ADCRESULT2 >> 4;
	uiADC03 = AdcRegs.ADCRESULT3 >> 4;
	uiADC04 = AdcRegs.ADCRESULT4 >> 4;
	uiADC05 = AdcRegs.ADCRESULT5 >> 4;
	//uiADC06 = AdcRegs.ADCRESULT6 >> 4;
	uiADC07 = AdcRegs.ADCRESULT7 >> 4;
	//uiADC08 = AdcRegs.ADCRESULT8 >> 4;
	uiADC09 = AdcRegs.ADCRESULT9 >> 4;
	//uiADC10 = AdcRegs.ADCRESULT10 >> 4;
	//uiADC11 = AdcRegs.ADCRESULT11 >> 4;
	//uiADC12 = AdcRegs.ADCRESULT12 >> 4;
	uiADC13 = AdcRegs.ADCRESULT13 >> 4;
	//uiADC14 = AdcRegs.ADCRESULT14 >> 4;
	//uiADC15 = AdcRegs.ADCRESULT15 >> 4;

/*
 * 	OLD ADC Configuration
	Voltage_X_In = uiADC00;//AdcRegs.ADCRESULT0 >> 4;
	//Voltage_Y_In = uiADC01;//AdcRegs.ADCRESULT1 >> 4;
	//Voltage_Z_In = uiADC02;//AdcRegs.ADCRESULT2 >> 4;

	Voltage_FBCM_Out = uiADC03;//AdcRegs.ADCRESULT3 >> 4;

	Current_X_In = uiADC04;//AdcRegs.ADCRESULT4 >> 4;
	//Current_Y_In = uiADC05;//AdcRegs.ADCRESULT5 >> 4;
	//Current_Z_In = uiADC06;//AdcRegs.ADCRESULT6 >> 4;

	Current_X_FBCM = uiADC07;//AdcRegs.ADCRESULT7 >> 4;

	Current_POL_2_4 = uiADC08;//AdcRegs.ADCRESULT8 >> 4;
	Voltage_POL_2_4 = uiADC09;//AdcRegs.ADCRESULT9 >> 4;

	Current_POL_1_3 = uiADC10;//AdcRegs.ADCRESULT10 >> 4;
	Voltage_POL_1_3 = uiADC11;//AdcRegs.ADCRESULT11 >> 4;

	//Voltage_SWBATT = uiADC12;//AdcRegs.ADCRESULT12 >> 4;

	//Voltage_BATT_1_2 = uiADC13;//AdcRegs.ADCRESULT13 >> 4;

	//Current_Y_FBCM = uiADC14;//AdcRegs.ADCRESULT14 >> 4;
	//Current_Z_FBCM = uiADC15;//AdcRegs.ADCRESULT15 >> 4;

	//Voltage_POL_1_3 = AdcRegs.ADCRESULT0 >> 4;
	//Voltage_POL_2_4 = AdcRegs.ADCRESULT1 >>4;
	//Voltage_SWBATT  = AdcRegs.ADCRESULT2 >>4;
	//Current_POL_1_3 = AdcRegs.ADCRESULT3 >>4;
	Current_POL_2_4 = AdcRegs.ADCRESULT4 >>4;
*/
	Voltage_X_In = uiADC00;//AdcRegs.ADCRESULT0 >> 4;
	Voltage_FBCM_Out = uiADC03;//AdcRegs.ADCRESULT3 >> 4;
	Current_X_In = uiADC04;//AdcRegs.ADCRESULT4 >> 4;
	Current_X_FBCM = uiADC07;//AdcRegs.ADCRESULT7 >> 4;
	SensedADC_POL_1 = uiADC01;//AdcRegs.ADCRESULT1 >> 4;
	SensedADC_POL_3	= uiADC02;//AdcRegs.ADCRESULT2 >> 4;
	SensedADC_POL_2	= uiADC09;//AdcRegs.ADCRESULT5 >> 4;
	Voltage_BATT_1_2 = uiADC13;//AdcRegs.ADCRESULT13 >> 4;

	ADCConversionEnd = 0;			// Lock values

	SensedADC_X_In = Voltage_X_In;
	//SensedADC_Y_In = Voltage_Y_In;
	//SensedADC_Z_In = Voltage_Z_In;
	SensedVoltage_X_In = (SensedADC_X_In/(4095.0))*(ADC_REF_VOLTAGE) * (33.1/3.0);
	x_panel_voltage += SensedVoltage_X_In;
	//SensedVoltage_Y_In = (SensedADC_Y_In/(4095.0))*(ADC_REF_VOLTAGE) * (33.0/3.0);
	//SensedVoltage_Z_In = (SensedADC_Z_In/(4095.0))*(ADC_REF_VOLTAGE) * (33.0/3.0);

	SensedADC_FBCM_Out = Voltage_FBCM_Out;
	SensedVoltage_FBCM_Out = (SensedADC_FBCM_Out/(4095.0))*(ADC_REF_VOLTAGE) * (53/10.0);

	SensedADC_Cur_X_In = Current_X_In;
	//SensedADC_Cur_Y_In = Current_Y_In;
	//SensedADC_Cur_Z_In = Current_Z_In;
	SensedCurrent_X_In = ((SensedADC_Cur_X_In/4095.0)*(ADC_REF_VOLTAGE))/(7.75*0.025);
	x_panel_current += SensedCurrent_X_In;
	//SensedCurrent_Y_In = ((SensedADC_Cur_Y_In/4095.0)*(ADC_REF_VOLTAGE))/(7.75*0.025);
	//SensedCurrent_Z_In = ((SensedADC_Cur_Z_In/4095.0)*(ADC_REF_VOLTAGE)) * (0.25 + (CS_R2/(4*CS_R1)));

	SensedADC_Cur_FBCM_X = Current_X_FBCM;
	//SensedADC_Cur_FBCM_Y = Current_Y_FBCM;
	//SensedADC_Cur_FBCM_Z = Current_Z_FBCM;
	SensedCurrent_FBCM_X = ((SensedADC_Cur_FBCM_X/4095.0)*(ADC_REF_VOLTAGE))/(7.75*0.025);
	SensedADC_CUR_1 = ((Current_POL_1_3/4095.0)*(ADC_REF_VOLTAGE))/(7.75*0.025);
	current_x = current_x + SensedADC_CUR_1;
	//SensedCurrent_FBCM_X = ((SensedADC_Cur_FBCM_X/4095.0)*(ADC_REF_VOLTAGE)) * (0.25 + (CS_R2/(4*CS_R1)));
	//SensedCurrent_FBCM_Y = ((SensedADC_Cur_FBCM_Y/4095.0)*(ADC_REF_VOLTAGE)) * (0.25 + (CS_R2/(4*CS_R1)));
	//SensedCurrent_FBCM_Z = ((SensedADC_Cur_FBCM_Z/4095.0)*(ADC_REF_VOLTAGE)) * (0.25 + (CS_R2/(4*CS_R1)));

	SensedVoltage_POL_1 = (SensedADC_POL_1/(4095.0))*(ADC_REF_VOLTAGE)*53/10.0f;
	SensedVoltage_POL_3 = (SensedADC_POL_3/(4095.0))*(ADC_REF_VOLTAGE)*53/10.0f;
	SensedVoltage_POL_2 = (SensedADC_POL_2/(4095.0))*(ADC_REF_VOLTAGE)*53/10.0f;

	if(Batt1_Vi == Batt_Vin_1_2) {
		SensedADC_BATT_1 = Voltage_BATT_1_2;
		SensedVoltage_BATT_1 = (SensedADC_BATT_1/(4095.0))*(ADC_REF_VOLTAGE) * 53/10.0f;	//Resistor Values
	} else if(Batt2_Vi == Batt_Vin_1_2) {
		SensedADC_BATT_2 = Voltage_BATT_1_2;
		SensedVoltage_BATT_2 = (SensedADC_BATT_2/(4095.0))*(ADC_REF_VOLTAGE) * 53/10.0f;	//Resistor Values
	}
	//SensedADC_SWBATT = Voltage_SWBATT;
	//SensedVoltage_SWBATT = /*(0.92)*/(SensedADC_SWBATT/(4095.0))*(ADC_REF_VOLTAGE) * 53/10.0f;

	ADCConversionEnd = 1;			// Unlock values
	
	// Reinitialize for next ADC sequence
	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;         // Reset SEQ1
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;       // Clear INT SEQ1 bit
	//EPwm2Regs.ETCLR.bit.SOCA = 1;
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
	/*if(switch_counter == 1){
		Pol_1_3_Out_Select(Pol3_Out_Vi);
		switch_counter = 0;
	}
	else{
		Pol_1_3_Out_Select(Pol1_Out_Vi);
		switch_counter = 1;
	}*/
	//current_counter++;
	uiWaitCounter++;
	if(uiWaitCounter > 500) {
		UARTTransmit = 1;
		uiWaitCounter = 0;
	}
	EINT;
	GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;
	return;
}

interrupt void epwm1_isr(void)
{
	if(FBCM1_PWM_Served < 2)
		FBCM1_PWM_Served++;
		
	//EPwm1Regs.CMPA.half.CMPA = FBCM1_Buck_EPwmOnTime;
	EPwm1Regs.CMPB = POL1_EPwmOnTime;
	StartADC_Seq1();
	// Clear INT flag for this timer
	EPwm1Regs.ETCLR.bit.INT = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm2_isr(void)
{
	//if(FBCM1_PWM_Served < 2)
	//	FBCM1_PWM_Served++;
		
	EPwm2Regs.CMPA.half.CMPA = FBCM1_Boost_EPwmOnTime;
	EPwm2Regs.CMPB = POL2_EPwmOnTime;
	//StartADC_Seq1();
	// Clear INT flag for this timer
	EPwm2Regs.ETCLR.bit.INT = 1;
	//EPwm2Regs.ETCLR.bit.SOCA = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

interrupt void epwm3_isr(void)
{
	EPwm3Regs.CMPA.half.CMPA = FBCM2_Buck_EPwmOnTime;
	EPwm3Regs.CMPB = POL3_EPwmOnTime;
	StartADC_Seq1();
	// Clear INT flag for this timer
	EPwm3Regs.ETCLR.bit.INT = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

interrupt void epwm4_isr(void)
{
	EPwm4Regs.CMPA.half.CMPA = FBCM2_Boost_EPwmOnTime;
	EPwm4Regs.CMPB = POL4_EPwmOnTime;
	// Clear INT flag for this timer
	EPwm4Regs.ETCLR.bit.INT = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

interrupt void epwm5_isr(void)
{
	EPwm5Regs.CMPA.half.CMPA = FBCM3_Buck_EPwmOnTime;
	//	EPwm5Regs.CMPB = POL3_EPwmOnTime;
	// Clear INT flag for this timer
	EPwm5Regs.ETCLR.bit.INT = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

interrupt void epwm6_isr(void)
{
	EPwm6Regs.CMPA.half.CMPA = FBCM3_Boost_EPwmOnTime;
	//	EPwm6Regs.CMPB = POL3_EPwmOnTime;
	// Clear INT flag for this timer
	EPwm6Regs.ETCLR.bit.INT = 1;

	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}


interrupt void cpu_timer0_isr(void)
{
	Control();
	// Acknowledge this interrupt to receive more interrupts from group 1
	//StartADC_Seq1();
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

interrupt void cpu_timer1_isr(void)
{
	//StartADC_Seq1();
}

interrupt void cpu_timer2_isr(void)
{
}


interrupt void rxaint_isr(void)
{
	static int position = 0;
//	static char test[100] = "";
	static int i = 0;
	char ReceivedChar;

	ReceivedChar = SciaRegs.SCIRXBUF.all;

//	test[i++] = ReceivedChar;

	if(i > 4)
	{
		i = 0;
	}
	if(Received == 0)
	{
		ReceivedStr[position++] = ReceivedChar;

		if(ReceivedChar == 0x0a)
		{
			position--;
			ReceivedStr[position] = '\0';
			position = 0;
			Received = 1;
		}
	}
/*	else if(Received == 2)
	{
		ReceivedStr[position++] = ReceivedChar;
		if(ReceivedChar == '\n')
		{
			position--;
			Received = 1;
			ReceivedStr[position] = '\0';
			position = 0;

		}
	}
*/
	PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ack
}

interrupt void txaint_isr(void)
{
	PieCtrlRegs.PIEACK.all|=0x100;       // Issue PIE ack
}



