/*
 * Timers.c
 *
 *  Created on: Mar 20, 2012
 *      Author: MIHIR
 */


#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_EPwm_defines.h"
#include "ISRs.h"
#include "Timers.h"

struct CPUTIMER_VARS CpuTimer0;

// When using DSP BIOS & other RTOS, comment out CPU Timer 2 code.
struct CPUTIMER_VARS CpuTimer1;
struct CPUTIMER_VARS CpuTimer2;

void InitTimers()
{
	// CPU Timer 0
	// Initialize address pointers to respective timer registers:
	CpuTimer0.RegsAddr = &CpuTimer0Regs;
	// Initialize timer period to maximum:
	CpuTimer0Regs.PRD.all  = 0xFFFFFFFF;
	// Initialize pre-scale counter to divide by 1 (SYSCLKOUT):
	CpuTimer0Regs.TPR.all  = 0;
	CpuTimer0Regs.TPRH.all = 0;
	// Make sure timer is stopped:
	CpuTimer0Regs.TCR.bit.TSS = 1;
	// Reload all counter register with period value:
	CpuTimer0Regs.TCR.bit.TRB = 1;
	// Reset interrupt counters:
	CpuTimer0.InterruptCount = 0;


// CpuTimer2 is reserved for DSP BIOS & other RTOS
// Do not use this timer if you ever plan on integrating
// DSP-BIOS or another realtime OS.

	// Initialize address pointers to respective timer registers:
	CpuTimer1.RegsAddr = &CpuTimer1Regs;
	CpuTimer2.RegsAddr = &CpuTimer2Regs;
	// Initialize timer period to maximum:
	CpuTimer1Regs.PRD.all  = 0xFFFFFFFF;
	CpuTimer2Regs.PRD.all  = 0xFFFFFFFF;
	// Make sure timers are stopped:
	CpuTimer1Regs.TCR.bit.TSS = 1;
	CpuTimer2Regs.TCR.bit.TSS = 1;
	// Reload all counter register with period value:
	CpuTimer1Regs.TCR.bit.TRB = 1;
	CpuTimer2Regs.TCR.bit.TRB = 1;
	// Reset interrupt counters:
	CpuTimer1.InterruptCount = 0;
	CpuTimer2.InterruptCount = 0;

   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.TINT0 = &cpu_timer0_isr;
   PieVectTable.XINT13 = &cpu_timer1_isr;
   PieVectTable.TINT2 = &cpu_timer2_isr;
   EDIS;    // This is needed to disable write to EALLOW protected registers

   // Enable CPU int1 which is connected to CPU-Timer 0, CPU int13
   // which is connected to CPU-Timer 1, and CPU int 14, which is connected
   // to CPU-Timer 2:
      IER |= M_INT1;
      IER |= M_INT13;
      IER |= M_INT14;

   // Enable TINT0 in the PIE: Group 1 interrupt 7
      PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

   // Enable global Interrupts and higher priority real-time debug events:
      EINT;   // Enable Global interrupt INTM
      ERTM;   // Enable Global realtime interrupt DBGM
}

void ConfigTimer0(float Period)
{
  ConfigCpuTimer(&CpuTimer0, 150, Period);
}

void ConfigTimer1(float Period)
{
  ConfigCpuTimer(&CpuTimer1, 150, Period);
}

void ConfigTimer2(float Period)
{
  ConfigCpuTimer(&CpuTimer2, 150, Period);
}

void StartTimer0(void)
{
	  CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0
}

void StartTimer1(void)
{
	  CpuTimer1Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0
}

void StartTimer2(void)
{
	  CpuTimer2Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0
}

void StopTimer0(void)
{
	  CpuTimer0Regs.TCR.all = 0x4011; // Use write-only instruction to set TSS bit = 0
}

void StopTimer1(void)
{
	  CpuTimer1Regs.TCR.all = 0x4011; // Use write-only instruction to set TSS bit = 0
}

void StopTimer2(void)
{
	  CpuTimer2Regs.TCR.all = 0x4011; // Use write-only instruction to set TSS bit = 0
}

//---------------------------------------------------------------------------
// ConfigCpuTimer:
//---------------------------------------------------------------------------
// This function initializes the selected timer to the period specified
// by the "Freq" and "Period" parameters. The "Freq" is entered as "MHz"
// and the period in "uSeconds". The timer is held in the stopped state
// after configuration.
//
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period)
{
    Uint32  temp;

    // Initialize timer period:
    Timer->CPUFreqInMHz = Freq;
    Timer->PeriodInUSec = Period;
    temp = (long) (Freq * Period);
    Timer->RegsAddr->PRD.all = temp;

    // Set pre-scale counter to divide by 1 (SYSCLKOUT):
    Timer->RegsAddr->TPR.all  = 0;
    Timer->RegsAddr->TPRH.all  = 0;

    // Initialize timer control register:
    Timer->RegsAddr->TCR.bit.TSS = 1;      // 1 = Stop timer, 0 = Start/Restart Timer
    Timer->RegsAddr->TCR.bit.TRB = 1;      // 1 = reload timer
    Timer->RegsAddr->TCR.bit.SOFT = 1;
    Timer->RegsAddr->TCR.bit.FREE = 1;     // Timer Free Run
    Timer->RegsAddr->TCR.bit.TIE = 1;      // 0 = Disable/ 1 = Enable Timer Interrupt

    // Reset interrupt counter:
    Timer->InterruptCount = 0;
}

