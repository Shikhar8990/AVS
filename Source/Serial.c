/*
 * Serial.c
 *
 *  Created on: Apr 6, 2012
 *      Author: MIHIR
 */

#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_Adc.h"
#include "Global.h"
#include "Serial.h"
#include "ISRs.h"

void InitSerial()
{
   InitSciaGpio();

   EALLOW;	    // This is needed to write to EALLOW protected registers
   PieVectTable.SCIRXINTA = &rxaint_isr;
   EDIS;       // This is needed to disable write to EALLOW protected register


   scia_init();       // Initalize SCIA

   // Interrupts that are used in this example are re-mapped to
   // ISR functions found within this file.
      EALLOW;	    // This is needed to write to EALLOW protected registers
      PieVectTable.SCIRXINTA = &rxaint_isr;
      PieVectTable.SCITXINTA = &txaint_isr;
      EDIS;       // This is needed to disable write to EALLOW protected register


      // Enable interrupts
      PieCtrlRegs.PIEIER9.all = 0x0003; // Enable all SCIA RXINT interrupt
      IER |= 0x0100;			         // enable PIEIER9, and INT9
      EINT;



}



void autobaud()
{
/*	Uint16 LoopCount, i;
	//Uint16 xmitCount;
	Uint16 ReceivedCount;
	Uint16 ErrorCount;
	Uint16 SendChar;
	Uint16 ReceivedAChar;   // scia received character
	Uint16 ReceivedBChar;   // scib received character
	Uint16 BRRVal;
	Uint16 Buff[10] = {0x55, 0xAA, 0xF0, 0x0F, 0x00, 0xFF, 0xF5, 0x5F, 0xA5, 0x5A};
    // Start with BRR = 1, work through each baud rate setting
    // incrementing BRR by BAUDSTEP
    for (BRRVal = 0x0000; BRRVal < (Uint32)0xFFFF; BRRVal+=BAUDSTEP)
    {

	    // Initiate an autobaud lock with scia.  Check
	    // returned character against baud lock character 'A'
//	    scia_AutobaudLock();
	    while(ScibRegs.SCIRXST.bit.RXRDY != 1) { }
	    ReceivedBChar = 0;
	    ReceivedBChar =  ScibRegs.SCIRXBUF.bit.RXDT;
	    if(ReceivedBChar != 'A')
	    {
	        error(0);
	    }

	    // Send/echoback characters
	    // 55 AA F0 0F 00 FF F5 5F A5 5A
	    for(i= 0; i<=9; i++)
	    {
	      SendChar = Buff[i];
	      scib_xmit(SendChar);			    // Initiate interrupts and xmit data in isr
	      // Wait to get the character back and check
	      // against the sent character.
	      while(ScibRegs.SCIRXST.bit.RXRDY != 1)
	      {
	          asm("   NOP");
	      }
	      ReceivedBChar = 0;
	      ReceivedBChar =  ScibRegs.SCIRXBUF.bit.RXDT;
//	      if(ReceivedBChar != SendChar) error(1);
	    }

    } // Repeat for next BRR setting
*/
}

// SCIA  8-bit word, baud rate 0x000F, default, 1 STOP bit, no parity
void scia_init()
{
    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function
	scia_fifo_init();
	
    // Reset FIFO's
 //   SciaRegs.SCIFFTX.all=0x8000;
 //   SciaRegs.SCIFFTX.bit.SCIFFENA = 1;
 //   SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;

    SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
    SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
    SciaRegs.SCICTL2.all =0x0003;
	SciaRegs.SCICTL2.bit.TXINTENA =1;
    SciaRegs.SCICTL2.bit.RXBKINTENA =1;


//    SciaRegs.SCIHBAUD    =0x0001;  // 9600 baud @LSPCLK = 37.5MHz.
//    SciaRegs.SCILBAUD    =0x00E7;

//    SciaRegs.SCIHBAUD    =0x0000;  // 38400 baud @LSPCLK = 37.5MHz.
//    SciaRegs.SCILBAUD    =0x0079;

//    SciaRegs.SCIHBAUD    =0x0000;  // 57600 baud @LSPCLK = 37.5MHz.
//    SciaRegs.SCILBAUD    =0x0050;

    SciaRegs.SCIHBAUD    =0x0000;  // 115200 baud @LSPCLK = 37.5MHz.
    SciaRegs.SCILBAUD    =0x0027;

//    SciaRegs.SCIHBAUD    =0x0000;  // 921600 baud @LSPCLK = 37.5MHz.
//    SciaRegs.SCILBAUD    =0x0005;

    SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset

}


// Test 1,SCIA  DLB, 8-bit word, baud rate 0x000F, default, 1 STOP bit, no parity
void scia_echoback_init()
{
    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function

 	SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
                                   // No parity,8 char bits,
                                   // async mode, idle-line protocol
	SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
                                   // Disable RX ERR, SLEEP, TXWAKE
	SciaRegs.SCICTL2.all =0x0003;
	SciaRegs.SCICTL2.bit.TXINTENA =1;
	SciaRegs.SCICTL2.bit.RXBKINTENA =1;
	#if (CPU_FRQ_150MHZ)
	      SciaRegs.SCIHBAUD    =0x0001;  // 9600 baud @LSPCLK = 37.5MHz.
	      SciaRegs.SCILBAUD    =0x00E7;
	#endif
	#if (CPU_FRQ_100MHZ)
      SciaRegs.SCIHBAUD    =0x0001;  // 9600 baud @LSPCLK = 20MHz.
      SciaRegs.SCILBAUD    =0x0044;
	#endif
	SciaRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset
}


// Transmit a character from the SCI
void scia_xmit(int a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0) {}
    SciaRegs.SCITXBUF=a;

}

void scia_msg(char * msg)
{
    int i;
    i = 0;
    while(msg[i] != '\0')
    {
        scia_xmit(msg[i]);
        i++;
    }
}

// Initalize the SCI FIFO
void scia_fifo_init()
{
    SciaRegs.SCIFFTX.all=0xE040;
    SciaRegs.SCIFFRX.all=0x204f;
    SciaRegs.SCIFFCT.all=0x0;

}




void InitSciaGpio()
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled disabled by the user.
// This will enable the pullups for the specified pins.

	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;	   // Enable pull-up for GPIO29 (SCITXDA)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.
// This will select asynch (no qualification) for the selected pins.

	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

/* Configure SCI-A pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be SCI functional pins.

	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation

    EDIS;
}

