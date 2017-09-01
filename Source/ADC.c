// DSP2833x_SysCtrl.c
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_Adc.h"
#include "Global.h"
#include "ADC.h"
#include "ISRs.h"
#include "extern.h"
#define ADC_usDELAY  5000L

extern float32 SensedVoltage1;
void InitADC(void)
{
	extern void DSP28x_usDelay(Uint32 Count);
	DINT;
	EALLOW;
#if (CPU_FRQ_150MHZ)				// Default - 150 MHz SYSCLKOUT
#define ADC_MODCLK 0x3 				// HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
#endif
#if (CPU_FRQ_100MHZ)
#define ADC_MODCLK 0x2 				// HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*2)   = 25.0 MHz
#endif

	PieVectTable.ADCINT = &adc_isr;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
	ADC_cal();
	EDIS;
	AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits

//	AdcRegs.ADCTRL3.bit.SMODE_SEL = 0x1;
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 0x1;

	DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels

	// Enable ADCINT in PIE
	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;
	
//	IER |= M_INT3;
	IER |= M_INT1;
	EINT;          					// Enable Global interrupt INTM
	ERTM;          					// Enable Global realtime interrupt DBGM

	// Configure ADC
	AdcRegs.ADCMAXCONV.all = 0x000F;       	// Setup 5 conv's on
	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;
 	AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1;
 	AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 2;
 	AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 3;
 	AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 4;
 	AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 5;
 	AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 6;
 	AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 7;
 	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 8;
 	AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 9;
 	AdcRegs.ADCCHSELSEQ3.bit.CONV10 = 10;
 	AdcRegs.ADCCHSELSEQ3.bit.CONV11 = 11;
 	AdcRegs.ADCCHSELSEQ4.bit.CONV12 = 12;
 	AdcRegs.ADCCHSELSEQ4.bit.CONV13 = 13;
 	AdcRegs.ADCCHSELSEQ4.bit.CONV14 = 14;
 	AdcRegs.ADCCHSELSEQ4.bit.CONV15 = 15;

 	AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;	// Disable SOCA from ePWM to start SEQ1
 	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;  	// Enable SEQ1 interrupt (every EOS)
 	AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2 = 0;	// Disable SOCA from ePWM to start SEQ1
 	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 0;  	// Enable SEQ1 interrupt (every EOS)
		
}

void StartADC_Seq1(void)
{
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;
//	AdcRegs.ADCTRL2.bit.SOC_SEQ2 = 1;
}


