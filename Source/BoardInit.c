// DSP2833x_SysCtrl.c
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "Global.h"
#include "BoardInit.h"
#include "ADC.h"
#include "Timers.h"
#include "PWM.h"
#include "Serial.h"
#include "extern.h"
void InitValues()
{
	RequiredADCCount_POL1 = (SetOutputVoltage_POL1/0.92) * (234.13);
	RequiredADCCount_POL2 = (SetOutputVoltage_POL2/0.92) * (234.13);
	RequiredADCCount_POL3 = (SetOutputVoltage_POL3/0.92) * (234.13);
	RequiredADCCount_POL4 = (SetOutputVoltage_POL4/0.92) * (234.13);

	POL1_EPwmOnTime = 500;
	POL2_EPwmOnTime = 500;
	POL3_EPwmOnTime = 500;
	POL4_EPwmOnTime = 500;

	FBCM1_Boost_EPwmOnTime = 1000;
	FBCM1_Buck_EPwmOnTime = 500;
	FBCM2_Boost_EPwmOnTime = 1000;
	FBCM2_Buck_EPwmOnTime = 0;
	FBCM3_Boost_EPwmOnTime = 1000;
	FBCM3_Buck_EPwmOnTime = 0;

}

void InitBoard()
{
	InitValues();
	InitSysCtrl();
	InitGpio();

	// Clear all interrupts and initialize PIE vector table:
	// Disable CPU interrupts
	DINT;
	// Initialize the PIE control registers to their default state.
	// The default state is all PIE interrupts disabled and flags
	// are cleared.
	// This function is found in the DSP2833x_PieCtrl.c file.
	InitPieCtrl();
	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;
	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	// This will populate the entire table, even if the interrupt
	// is not used in this example.  This is useful for debug purposes.
	// The shell ISR routines are found in DSP2833x_DefaultIsr.c.
	// This function is found in DSP2833x_PieVect.c.
	InitPieVectTable();

	InitADC();
	InitPWM();
	InitTimers();
	InitSerial();
}
