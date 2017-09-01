#ifndef GPIO_H
#define GPIO_H

void InitGpio(void);
void Batt1_To_SwBatt_Enable(void);
void Batt1_To_SwBatt_Disable(void);
void Batt2_To_SwBatt_Enable(void);
void Batt2_To_SwBatt_Disable(void);
void FBCM_To_SwBatt_Disable(void);
void FBCM_To_SwBatt_Enable(void);
void FBCM_To_Batt1_Enable(void);
void FBCM_To_Batt1_Disable(void);
void FBCM_To_Batt2_Enable(void);
void FBCM_To_Batt2_Disable(void);

void Pol_1_3_Out_Select(ADC_IN_Select Pol1_3_Out);
void Pol_2_4_Out_Select(ADC_IN_Select Pol_2_4_Out);
void Batt_1_2_Select(ADC_IN_Select Batt_1_2);
void Pol_1_3_CS_Select(ADC_IN_Select Ana_1_3_Sel1);
void Pol_2_4_CS_Select(ADC_IN_Select Ana_2_4_Sel1);
void Solar_Power_Available(void);
void Solar_Power_UnAvailable(void);

#endif
