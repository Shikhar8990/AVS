/*
 * extern.h
 *
 *  Created on: Apr 14, 2012
 *      Author: MIHIR
 */

#ifndef EXTERN_H_
#define EXTERN_H_

extern Uint16 uiADC00;
extern Uint16 uiADC01;
extern Uint16 uiADC02;
extern Uint16 uiADC03;
extern Uint16 uiADC04;
extern Uint16 uiADC05;
extern Uint16 uiADC06;
extern Uint16 uiADC07;
extern Uint16 uiADC08;
extern Uint16 uiADC09;
extern Uint16 uiADC10;
extern Uint16 uiADC11;
extern Uint16 uiADC12;
extern Uint16 uiADC13;
extern Uint16 uiADC14;
extern Uint16 uiADC15;

extern int16 FBCM1_Buck_EPwmOnTime;
extern int16 FBCM1_Boost_EPwmOnTime;
extern int16 FBCM2_Buck_EPwmOnTime;
extern int16 FBCM2_Boost_EPwmOnTime;
extern int16 FBCM3_Buck_EPwmOnTime;
extern int16 FBCM3_Boost_EPwmOnTime;

extern int16 POL1_EPwmOnTime;
extern int16 POL2_EPwmOnTime;
extern int16 POL3_EPwmOnTime;
extern int16 POL4_EPwmOnTime;

extern Uint16 ADCConversionEnd;
extern Uint16 UARTTransmit;

extern float32 SensedVoltage_X_In;
extern float32 SensedVoltage_Y_In;
extern float32 SensedVoltage_Z_In;
extern Uint16 SensedADC_X_In;
extern Uint16 SensedADC_Y_In;
extern Uint16 SensedADC_Z_In;

extern float32 SensedVoltage_FBCM_Out;
extern Uint16 SensedADC_FBCM_Out;

extern float32 SensedCurrent_X_In;
extern float32 SensedCurrent_Y_In;
extern float32 SensedCurrent_Z_In;
extern Uint16 SensedADC_Cur_X_In;
extern Uint16 SensedADC_Cur_Y_In;
extern Uint16 SensedADC_Cur_Z_In;

extern float32 SensedCurrent_FBCM_X;
extern float32 SensedCurrent_FBCM_Y;
extern float32 SensedCurrent_FBCM_Z;
extern Uint16 SensedADC_Cur_FBCM_X;
extern Uint16 SensedADC_Cur_FBCM_Y;
extern Uint16 SensedADC_Cur_FBCM_Z;

extern float32 SensedVoltage_POL_1;
extern float32 SensedVoltage_POL_2;
extern float32 SensedVoltage_POL_3;
extern float32 SensedVoltage_POL_4;
extern Uint16 SensedADC_POL_1;
extern Uint16 SensedADC_POL_2;
extern Uint16 SensedADC_POL_3;
extern Uint16 SensedADC_POL_4;

extern float32 SensedVoltage_BATT_1;
extern float32 SensedVoltage_BATT_2;
extern Uint16 SensedADC_BATT_1;
extern Uint16 SensedADC_BATT_2;

extern float32 SensedVoltage_SWBATT;
extern Uint16 SensedADC_SWBATT;
extern int Voltage_POL_1_3;
extern int Voltage_POL_2_4;

extern float32 SensedCurrent_POL_1;
extern float32 SensedCurrent_POL_2;
extern float32 SensedCurrent_POL_3;
extern float32 SensedCurrent_POL_4;
extern float32 SensedADC_CUR_1;
extern Uint16 SensedADC_CUR_2;
extern Uint16 SensedADC_CUR_3;
extern Uint16 SensedADC_CUR_4;
extern int Current_POL_1_3;
extern int mppt_counter;

extern float SetOutputVoltage_POL1;
extern float SetOutputVoltage_POL2;
extern float SetOutputVoltage_POL3;
extern float SetOutputVoltage_POL4;
extern float SetOutputVoltage_FBCM;
//extern float SetOutputVoltage_FBCM2;
//extern float SetOutputVoltage_FBCM3;

extern Uint16 RequiredADCCount_POL1;
extern Uint16 RequiredADCCount_POL2;
extern Uint16 RequiredADCCount_POL3;
extern Uint16 RequiredADCCount_POL4;
extern Uint16 RequiredADCCount_FBCM1;
extern Uint16 RequiredADCCount_FBCM2;
extern Uint16 RequiredADCCount_FBCM3;

extern ADC_IN_Select ADC_VIn_Pol_1_3;
extern ADC_IN_Select ADC_VIn_Pol_2_4;
extern ADC_IN_Select Batt_Vin_1_2;
extern ADC_IN_Select ADC_Iin_Pol_1_3;
extern ADC_IN_Select ADC_Iin_Pol_2_4;

extern char ReceivedStr[25];
extern Uint16 Received;

extern Uint16 FBCM1_PWM_Served;
extern float SetOutputCurrent_FBCM, current_x, current,voltage_ref, x_panel_current,x_panel_voltage, duty_ratio;
extern int switch_counter, mppt_counter, current_counter;
extern float32 x_panel_voltage_ref, duty_ratio_output_reg, duty_ratio_mppt;
#endif /* EXTERN_H_ */
