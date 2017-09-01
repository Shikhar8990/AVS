#ifndef GLOBAL_H
#define GLOBAL_H
#include "DSP2833x_GlobalPrototypes.h"         // Prototypes for global functions within the
                                              // .c files.


/*-----------------------------------------------------------------------------
      Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
-----------------------------------------------------------------------------*/
//#define DSP28_DIVSEL   0   // Enable /4 for SYSCLKOUT
//#define DSP28_DIVSEL   1 // Enable /4 for SYSCKOUT
#define DSP28_DIVSEL     2 // Enable /2 for SYSCLKOUT
//#define DSP28_DIVSEL     3 // Enable /1 for SYSCLKOUT

#define DSP28_PLLCR   10
//#define DSP28_PLLCR    9
//#define DSP28_PLLCR    8
//#define DSP28_PLLCR    7
//#define DSP28_PLLCR    6
//#define DSP28_PLLCR    5
//#define DSP28_PLLCR    4
//#define DSP28_PLLCR    3
//#define DSP28_PLLCR    2
//#define DSP28_PLLCR    1
//#define DSP28_PLLCR    0  // PLL is bypassed in this mode
//----------------------------------------------------------------------------


/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.

      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat
      the number as a 64-bit value.

      Only one statement should be uncommented.

      Example 1:150 MHz devices:
                CLKIN is a 30MHz crystal.

                In step 1 the user specified PLLCR = 0xA for a
                150Mhz CPU clock (SYSCLKOUT = 150MHz).

                In this case, the CPU_RATE will be 6.667L
                Uncomment the line:  #define CPU_RATE  6.667L

      Example 2:  100 MHz devices:
                  CLKIN is a 20MHz crystal.

	              In step 1 the user specified PLLCR = 0xA for a
	              100Mhz CPU clock (SYSCLKOUT = 100MHz).

	              In this case, the CPU_RATE will be 10.000L
                  Uncomment the line:  #define CPU_RATE  10.000L
-----------------------------------------------------------------------------*/
#define CPU_RATE    6.667L   // for a 150MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    7.143L   // for a 140MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    8.333L   // for a 120MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   10.000L   // for a 100MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   13.330L   // for a 75MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//----------------------------------------------------------------------------

/*-----------------------------------------------------------------------------
      Target device (in DSP2833x_Device.h) determines CPU frequency
      (for examples) - either 150 MHz (for 28335 and 28334) or 100 MHz
      (for 28332). User does not have to change anything here.
-----------------------------------------------------------------------------*/
#if DSP28_28332                   // DSP28_28332 device only
  #define CPU_FRQ_100MHZ    1     // 100 Mhz CPU Freq (20 MHz input freq)
  #define CPU_FRQ_150MHZ    0
#else
  #define CPU_FRQ_100MHZ    0     // DSP28_28335||DSP28_28334
  #define CPU_FRQ_150MHZ    1     // 150 MHz CPU Freq (30 MHz input freq) by DEFAULT
#endif


//---------------------------------------------------------------------------
// Include Example Header Files:
//

#include "DSP2833x_GlobalPrototypes.h"         // Prototypes for global functions within the
                                              // .c files.

#define PARTNO_28335  0xEF
#define PARTNO_28334  0xEE
#define PARTNO_28332  0xED
#define PARTNO_28235  0xE8
#define PARTNO_28234  0xE7
#define PARTNO_28232  0xE6



// DO NOT MODIFY THIS LINE.
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)



typedef enum {
	Batt1_Vi,
	Batt2_Vi,
	Pol1_CS_Vi,
	Pol2_CS_Vi,
	Pol3_CS_Vi,
	Pol4_CS_Vi,
	Pol1_Out_Vi,
	Pol2_Out_Vi,
	Pol3_Out_Vi,
	Pol4_Out_Vi
} ADC_IN_Select;

typedef enum {
	FBCM_Off_State,
	FBCM_On_State,
	FBCM_Buck_State,
	FBCM_Boost_State
} FBCM_State;

typedef enum {
	Blank,

	ADCVal00,
	ADCVal01,
	ADCVal02,
	ADCVal03,
	ADCVal04,
	ADCVal05,
	ADCVal06,
	ADCVal07,
	ADCVal08,
	Blank1,
	ADCVal09,
	ADCVal10,
	ADCVal11,
	ADCVal12,
	ADCVal13,
	ADCVal14,
	ADCVal15,

	FDPOL1_EN,
	FDPOL1_Vout,
	FDPOL1_Iout,
	FDPOL1_Vout_ADC,
	FDPOL1_Iout_ADC,
	FDPOL1_Vout_SET,
	FDPOL1_Iout_SET,

	FDPOL2_EN,
	FDPOL2_Vout,
	FDPOL2_Iout,
	FDPOL2_Vout_ADC,
	FDPOL2_Iout_ADC,
	FDPOL2_Vout_SET,
	FDPOL2_Iout_SET,

	FDPOL3_EN,
	FDPOL3_Vout,
	FDPOL3_Iout,
	FDPOL3_Vout_ADC,
	FDPOL3_Iout_ADC,
	FDPOL3_Vout_SET,
	FDPOL3_Iout_SET,

	FDPOL4_EN,
	FDPOL4_Vout,
	FDPOL4_Iout,
	FDPOL4_Vout_ADC,
	FDPOL4_Iout_ADC,
	FDPOL4_Vout_SET,
	FDPOL4_Iout_SET,

	SWBATT_EN,
	SWBATT_V,
	SWBATT_V_ADC,
	SWBATT_I,
	SWBATT_I_ADC,

	BATT1_EN,
	BATT1_V,
	BATT1_V_ADC,
	BATT1_I,
	BATT1_I_ADC,

	BATT2_EN,
	BATT2_V,
	BATT2_V_ADC,
	BATT2_I,
	BATT2_I_ADC,

	FBCM1_EN,
	FBCM1_Vin,
	FBCM1_Iin,
	FBCM1_Vin_ADC,
	FBCM1_Iin_ADC,
	FBCM1_Vout,
	FBCM1_Iout,
	FBCM1_Vout_ADC,
	FBCM1_Iout_ADC,
	FBCM1_Vout_SET,
	FBCM1_Iout_SET,

	FBCM2_EN,
	FBCM2_Vin,
	FBCM2_Iin,
	FBCM2_Vin_ADC,
	FBCM2_Iin_ADC,
	FBCM2_Vout,
	FBCM2_Iout,
	FBCM2_Vout_ADC,
	FBCM2_Iout_ADC,
	FBCM2_Vout_SET,
	FBCM2_Iout_SET,

	FBCM3_EN,
	FBCM3_Vin,
	FBCM3_Iin,
	FBCM3_Vin_ADC,
	FBCM3_Iin_ADC,
	FBCM3_Vout,
	FBCM3_Iout,
	FBCM3_Vout_ADC,
	FBCM3_Iout_ADC,
	FBCM3_Vout_SET,
	FBCM3_Iout_SET,

	FBCM_Vout,
	FBCM_Vout_ADC
} eCommand;

#define Err_Op (100)
#define Err_Ip (100)

//#define FEEDBACK_CONTROL
#define PID_CONTROL
//#define NODE_LOGIC
//#define FBCM_FEEDBACK

#define POL1_ADJUST (0.88)
#define FBCM1_In_ADJUST (0.9)
#define FBCM_Out_ADJUST (0.9)
#define Kp_POL1 (200.0)

#define Kp_POL2 (100.0)

#define CS_R2 (30)
#define CS_R1 (1)

#define MIN_INPUT_VOLTAGE_ADC (60)

#define MIN_BOOST_DUTY (100) //Note: This is 1-D in all

#define ADC_REF_VOLTAGE (3.00)

void Control(void);

#endif
