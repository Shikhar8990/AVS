// DSP2833x_SysCtrl.c
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_EPwm_defines.h"

#include "Global.h"
#include "PWM.h"
#include "ISRs.h"
#include "extern.h"

void InitPWM()
{
// NOTE: These can be replaced by exact names of controllers
	DINT;
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
	EDIS;
	
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
	EDIS;
	
	EALLOW;  // This is needed to write to EALLOW protected register
	PieVectTable.EPWM1_INT = &epwm1_isr;
	PieVectTable.EPWM2_INT = &epwm2_isr;
	PieVectTable.EPWM3_INT = &epwm3_isr;
	PieVectTable.EPWM4_INT = &epwm4_isr;
	PieVectTable.EPWM5_INT = &epwm5_isr;
	PieVectTable.EPWM6_INT = &epwm6_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers
	
	// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
	//PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
	PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
	/*PieCtrlRegs.PIEIER3.bit.INTx3 = 1;
	PieCtrlRegs.PIEIER3.bit.INTx4 = 1;
	PieCtrlRegs.PIEIER3.bit.INTx5 = 1;
	PieCtrlRegs.PIEIER3.bit.INTx6 = 1;
	*/
	//IER |= M_INT1;
	//IER |= M_INT3;
	EINT;
	ERTM;
	
	InitEPwm1();
	InitEPwm2();
	InitEPwm3();
	InitEPwm4();
	InitEPwm5();
	InitEPwm6();


}

void InitPwm1Gpio(void)
{
	EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)   
   
/* Configure ePWM-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM1 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    EDIS;
}

void InitPwm2Gpio(void)
{
	EALLOW;
	
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)

/* Configure ePWM-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM2 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B

	EDIS;
}

void InitPwm3Gpio(void)
{
	EALLOW;
   
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
	GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)
       
/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM3 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B

	EDIS;
}

#if DSP28_EPWM4
void InitPwm4Gpio(void)
{
	EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
	GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;    // Enable pull-up on GPIO7 (EPWM4B)

/* Configure ePWM-4 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM4 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
	
	EDIS;
}
#endif // endif DSP28_EPWM4  

#if DSP28_EPWM5
void InitPwm5Gpio(void)
{
	EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
	GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)

/* Configure ePWM-5 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
	GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;   // NOT Configure GPIO9 as EPWM5B - let it be GPIO
	
	EDIS;
}
#endif // endif DSP28_EPWM5

#if DSP28_EPWM6
void InitPwm6Gpio(void)
{
	EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user. 
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
	GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up on GPIO11 (EPWM6B)

/* Configure ePWM-6 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;   // Configure GPIO11 as GPIO - As it is BATT_1_2_SEL

	EDIS;
}
#endif // endif DSP28_EPWM6  

void InitEPwm1()
{
	InitPwm1Gpio();

	EPwm1Regs.TBPRD = 999;                        // Set timer period
 	EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm1Regs.TBCTR = 0x0000;                      // Clear counter
	
 	// Setup TBCLK
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
	
 	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	
 	// Setup compare
	EPwm1Regs.CMPA.half.CMPA = 500;
 	EPwm1Regs.CMPB = 500;
	
 	// Set actions
	EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm1Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm1Regs.DBRED = EPWM1_MIN_DB;
 	EPwm1Regs.DBFED = EPWM1_MIN_DB;
	
 	// Interrupt where we will change the Deadband
	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event
	
}

void InitEPwm2()
{
	InitPwm2Gpio();

	EPwm2Regs.TBPRD = 999;                        // Set timer period
 	EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm2Regs.TBCTR = 0x0000;                      // Clear counter
	
 	// Setup TBCLK
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;

 	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

 	// Setup compare
	EPwm2Regs.CMPA.half.CMPA = 500;
 	EPwm2Regs.CMPB = 500;
	
 	// Set actions
	EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm2Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm2Regs.DBRED = EPWM2_MIN_DB;
 	EPwm2Regs.DBFED = EPWM2_MIN_DB;
	
 	// Interrupt where we will change the Deadband
 	//EPwm2Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	//EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm2Regs.ETSEL.bit.SOCAEN = 1;
 	EPwm2Regs.ETSEL.bit.SOCASEL = ET_CTR_PRD;
 	EPwm2Regs.ETPS.bit.SOCAPRD = ET_2ND;
 	//EPwm2Regs.ETPS.bit.INTPRD = ET_2ND;           // Generate INT on 3rd event
	
}
void InitEPwm3()
{
	InitPwm3Gpio();

	EPwm3Regs.TBPRD = 999;                        // Set timer period
 	EPwm3Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm3Regs.TBCTR = 0x0000;                      // Clear counter
	
 	// Setup TBCLK
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	
	EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
	
 	EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;
	
 	// Setup compare
	EPwm3Regs.CMPA.half.CMPA = 500;
 	EPwm3Regs.CMPB = 500;
	
 	// Set actions
	EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm3Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm3Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm3Regs.DBRED = EPWM3_MIN_DB;
 	EPwm3Regs.DBFED = EPWM3_MIN_DB;
	
 	// Interrupt where we will change the Deadband
	EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm3Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event
	
}

void InitEPwm4()
{
	InitPwm4Gpio();

	EPwm4Regs.TBPRD = 999;                        // Set timer period
 	EPwm4Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm4Regs.TBCTR = 0x0000;                      // Clear counter

 	// Setup TBCLK
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;

 	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

 	// Setup compare
	EPwm4Regs.CMPA.half.CMPA = 500;
 	EPwm4Regs.CMPB = 500;

 	// Set actions
	EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm4Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm4Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm4Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm4Regs.DBRED = EPWM3_MIN_DB;
 	EPwm4Regs.DBFED = EPWM3_MIN_DB;

 	// Interrupt where we will change the Deadband
	EPwm4Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm4Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	EPwm4Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

}

void InitEPwm5()
{
	InitPwm5Gpio();

	EPwm5Regs.TBPRD = 999;                        // Set timer period
 	EPwm5Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm5Regs.TBCTR = 0x0000;                      // Clear counter

 	// Setup TBCLK
	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm5Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;

 	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

 	// Setup compare
	EPwm5Regs.CMPA.half.CMPA = 500;
 	EPwm5Regs.CMPB = 500;

 	// Set actions
	EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm5Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm5Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm5Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm5Regs.DBRED = EPWM3_MIN_DB;
 	EPwm5Regs.DBFED = EPWM3_MIN_DB;

 	// Interrupt where we will change the Deadband
	EPwm5Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm5Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	EPwm5Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

}

void InitEPwm6()
{
	InitPwm6Gpio();

	EPwm6Regs.TBPRD = 999;                        // Set timer period
 	EPwm6Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
 	EPwm6Regs.TBCTR = 0x0000;                      // Clear counter

 	// Setup TBCLK
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
 	EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
 	EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
 	EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm6Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;

 	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;    // Load registers every ZERO
 	EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
 	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
 	EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

 	// Setup compare
	EPwm6Regs.CMPA.half.CMPA = 500;
 	EPwm6Regs.CMPB = 500;

 	// Set actions
	EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm6Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm6Regs.AQCTLB.bit.CBU = AQ_CLEAR;


 	// Active Low PWMs - Setup Deadband
	EPwm6Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;
 	EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
 	EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
 	EPwm6Regs.DBRED = EPWM3_MIN_DB;
 	EPwm6Regs.DBFED = EPWM3_MIN_DB;

 	// Interrupt where we will change the Deadband
	EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
 	EPwm6Regs.ETSEL.bit.INTEN = 1;                // Enable INT
 	EPwm6Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event
}
