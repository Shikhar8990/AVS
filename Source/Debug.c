/*
 * Debug.c
 *
 *  Created on: Apr 12, 2012
 *      Author: MIHIR
 */
#include "DSP2833x_Device.h"     	// DSP2833x Headerfile Include File
#include "DSP2833x_EPwm_defines.h"

#include "Global.h"
#include "Debug.h"
#include "Serial.h"
#include "PWM.h"
#include "extern.h"

void Debug_ALL()
{
	Debug_ADC_Voltage_Pol_1();
	Debug_ADC_Voltage_Pol_2();
	Debug_ADC_Voltage_Pol_3();
	Debug_ADC_Voltage_Pol_4();
	Debug_Voltage_Pol_1();
	Debug_Voltage_Pol_2();
	Debug_Voltage_Pol_3();
	Debug_Voltage_Pol_4();


	Debug_ADC_Voltage_Batt_1();
	Debug_ADC_Voltage_Batt_2();
	Debug_Voltage_Batt_1();
	Debug_Voltage_Batt_2();

	Debug_ADC_Current_Pol_1();
	Debug_ADC_Current_Pol_2();
	Debug_ADC_Current_Pol_3();
	Debug_ADC_Current_Pol_4();

	Debug_Current_Pol_1();
	Debug_Current_Pol_2();
	Debug_Current_Pol_3();
	Debug_Current_Pol_4();
}

void New_Line(void)
{
	scia_xmit(0x0a);
//	scia_xmit(0x0d);
}

void Print_Integer(int Integer)
{
	char str[25] = "";
	int IntegerCopy = 0;
	int Length = 0;

	IntegerCopy = Integer;
	if(Integer == 0)
		Length = 1;
	else {
		while(Integer != 0)
		{
			Length++;
			Integer /= 10;
		}
	}

	str[Length--] = '\0';
	while(Length >= 0){
		str[Length--] = IntegerCopy % 10 + 48;
		IntegerCopy /= 10;
	}

	scia_msg(str);
}

void Print_Float(float Float)
{
	char str[25] = "";
	int Length = 0, LengthCopy = 0;
	int Integer = 0, IntegerCopy = 0, Fraction = 0;

	Integer = (int)(Float * 100);

	Fraction = Integer % 10;
	Fraction *= 10;
	Integer /= 10;
	Fraction += Integer % 10;
	Integer /= 10;

	IntegerCopy = Integer;
	if(Integer == 0)
		Length = 1;
	else {
		while(Integer != 0)
		{
			Length++;
			Integer /= 10;
		}
	}

	LengthCopy = Length;
	str[Length--] = '.';
	while(Length >= 0){
		str[Length--] = IntegerCopy % 10 + 48;
		IntegerCopy /= 10;
	}

	Length = 0;
	Integer = Fraction;
	IntegerCopy = Integer;
	if(Integer == 0)
		Length = 1;
	else {
		while(Integer != 0)
		{
			Length++;
			Integer /= 10;
		}
	}

	str[LengthCopy++ + Length--] = '\0';
	while(Length-- >= 0){
		str[LengthCopy++] = IntegerCopy % 10 + 48;
		IntegerCopy /= 10;
	}

	scia_msg(str);
}

void Debug_ADC_Val_All()
{
	Debug_ADC_Val_00();
	Debug_ADC_Val_01();
	Debug_ADC_Val_02();
	Debug_ADC_Val_03();
	Debug_ADC_Val_04();
	Debug_ADC_Val_05();
	Debug_ADC_Val_06();
	Debug_ADC_Val_07();
	Debug_ADC_Val_08();
	Debug_ADC_Val_09();
	Debug_ADC_Val_10();
	Debug_ADC_Val_11();
	Debug_ADC_Val_12();
	Debug_ADC_Val_13();
	Debug_ADC_Val_14();
	Debug_ADC_Val_15();
}

void Debug_ADC_Val_00()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal00;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC00);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_01()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal01;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC01);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_02()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal02;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC02);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_03()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal03;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC03);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_04()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal04;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC04);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_05()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal05;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC05);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_06()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal06;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC06);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_07()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal07;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC07);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_08()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal08;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC08);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_09()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal09;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC09);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_10()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal10;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC10);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_11()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal11;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC11);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_12()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal12;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC12);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_13()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal13;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC13);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_14()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal14;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC14);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Val_15()
{
	char str[25] = "  ";
	str[0] = (char)ADCVal15;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(uiADC15);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Pol_1()
{
	Debug_ADC_Voltage_Pol_1();
	Debug_Voltage_Pol_1();
	Debug_ADC_Current_Pol_1();
	Debug_Current_Pol_1();
}

void Debug_Pol_2()
{
	Debug_ADC_Voltage_Pol_2();
	Debug_Voltage_Pol_2();
	Debug_ADC_Current_Pol_2();
	Debug_Current_Pol_2();
}

void Debug_Pol_3()
{
	Debug_ADC_Voltage_Pol_3();
	Debug_Voltage_Pol_3();
	Debug_ADC_Current_Pol_3();
	Debug_Current_Pol_3();
}

void Debug_Pol_4()
{
	Debug_ADC_Voltage_Pol_4();
	Debug_Voltage_Pol_4();
	Debug_ADC_Current_Pol_4();
	Debug_Current_Pol_4();
}



void Debug_ADC_Voltage_Pol_1()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL1_Vout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_POL_1);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(RequiredADCCount_POL1);
//	scia_msg("\n");
	New_Line();

//	sprintf(str, "VP13 %d\n", SensedADC_POL_1_3);

}

void Debug_Voltage_Pol_1()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL1_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_POL_1);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Float(SetOutputVoltage_POL1);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP13 %.2f\n", SensedVoltage_POL_1_3);
}

void Debug_ADC_Voltage_Pol_2()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL2_Vout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_POL_2);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(RequiredADCCount_POL2);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP24 %d\n", SensedADC_POL_2_4);
}

void Debug_Voltage_Pol_2()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL2_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_POL_2);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Float(SetOutputVoltage_POL2);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP24 %.2f\n", SensedVoltage_POL_2_4);

}

void Debug_ADC_Voltage_Pol_3()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL1_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_POL_3);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(RequiredADCCount_POL3);
//	scia_msg("\n");
	New_Line();

//	sprintf(str, "VP13 %d\n", SensedADC_POL_1_3);

}

void Debug_Voltage_Pol_3()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL3_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_POL_3);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Float(SetOutputVoltage_POL3);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP13 %.2f\n", SensedVoltage_POL_1_3);
}

void Debug_ADC_Voltage_Pol_4()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL4_Vout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_POL_4);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(RequiredADCCount_POL4);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP24 %d\n", SensedADC_POL_2_4);
}

void Debug_Voltage_Pol_4()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL2_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_POL_4);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Float(SetOutputVoltage_POL4);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VP24 %.2f\n", SensedVoltage_POL_2_4);

}

void Debug_ADC_Voltage_SWBatt()
{
	char str[25] = "  ";
	str[0] = (char)	SWBATT_V_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_SWBATT);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Voltage_SWBatt()
{
	char str[25] = "  ";
	str[0] = (char)SWBATT_V;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_SWBATT);
	ADCConversionEnd = 1;
//	scia_msg("\n");
	New_Line();
}


void Debug_ADC_Voltage_Batt_1()
{
	char str[25] = "  ";
	str[0] = (char)BATT1_V_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_BATT_1);
	ADCConversionEnd = 1;
//	scia_msg("/");
//	Print_Float(RequiredADCCount_POL1);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VB12 %d\n", SensedADC_BATT_1_2);
}

void Debug_Voltage_Batt_1()
{
	char str[25] = "  ";
	str[0] = (char)BATT1_V;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_BATT_1);
	ADCConversionEnd = 1;
//	scia_msg("\n");
	New_Line();

//	sprintf(str, "VB12 %.2f\n", SensedVoltage_BATT_1_2);

}

void Debug_ADC_Voltage_Batt_2()
{
	char str[25] = "  ";
	str[0] = (char)BATT2_V_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_BATT_2);
	ADCConversionEnd = 1;
//	scia_msg("/");
//	Print_Float(RequiredADCCount_POL1);
	//scia_msg("\n");
	New_Line();

//	sprintf(str, "VB12 %d\n", SensedADC_BATT_1_2);
}

void Debug_Voltage_Batt_2()
{
	char str[25] = "  ";
	str[0] = (char)BATT2_V;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_BATT_2);
	ADCConversionEnd = 1;
//	scia_msg("\n");
	New_Line();

//	sprintf(str, "VB12 %.2f\n", SensedVoltage_BATT_1_2);

}

void Debug_ADC_Current_Pol_1()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL1_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_CUR_1);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_Pol_1()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL1_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_POL_1);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_Pol_2()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL2_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_CUR_2);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_Pol_2()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL2_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_POL_2);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_Pol_3()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL3_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_CUR_3);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_Pol_3()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL3_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_POL_3);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_Pol_4()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL4_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_CUR_4);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_Pol_4()
{
	char str[25] = "  ";
	str[0] = (char)FDPOL4_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_POL_4);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_PWM1A()
{
	char str[25] = "PWM1A ";
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(POL1_EPwmOnTime);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(PWMPeriod+1);
	New_Line();
}

void Debug_PWM2A()
{
	char str[25] = "PWM2A ";
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(POL2_EPwmOnTime);
	ADCConversionEnd = 1;
	scia_msg("/");
	Print_Integer(PWMPeriod+1);
	New_Line();
}

void Debug_Voltage_FBCM_1_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Vin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_X_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Voltage_FBCM_1_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Vin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_X_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Voltage_FBCM_2_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Vin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_Y_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Voltage_FBCM_2_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Vin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Y_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Voltage_FBCM_3_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Vin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_Z_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Voltage_FBCM_3_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Vin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Z_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_1_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Iin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_X_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_1_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Iin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Cur_X_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_2_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Iin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_Y_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_2_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Iin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Cur_Y_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_3_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Iin;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_Z_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_3_In()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Iin_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Cur_Z_In);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_1_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(current);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_1_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM1_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(Current_POL_1_3);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_2_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_FBCM_Y);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_2_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM2_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Cur_FBCM_Y);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Current_FBCM_3_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Iout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedCurrent_FBCM_Z);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Current_FBCM_3_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM3_Iout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_Cur_FBCM_Z);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_Voltage_FBCM_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM_Vout;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Float(SensedVoltage_FBCM_Out);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_ADC_Voltage_FBCM_Out()
{
	char str[25] = "  ";
	str[0] = (char)FBCM_Vout_ADC;
	scia_msg(str);
	while(ADCConversionEnd != 1);
	ADCConversionEnd = 0;
	Print_Integer(SensedADC_FBCM_Out);
	ADCConversionEnd = 1;
	New_Line();
}

void Debug_FBCM_1()
{
	Debug_Voltage_FBCM_1_In();
	Debug_ADC_Voltage_FBCM_1_In();
	Debug_Current_FBCM_1_In();
	Debug_ADC_Current_FBCM_1_In();
	Debug_Current_FBCM_1_Out();
	Debug_ADC_Current_FBCM_1_Out();

	Debug_Voltage_FBCM_Out();
	Debug_ADC_Voltage_FBCM_Out();
}

void Debug_FBCM_2()
{
	Debug_Voltage_FBCM_2_In();
	Debug_ADC_Voltage_FBCM_2_In();
	Debug_Current_FBCM_2_In();
	Debug_ADC_Current_FBCM_2_In();
	Debug_Current_FBCM_2_Out();
	Debug_ADC_Current_FBCM_2_Out();

	Debug_Voltage_FBCM_Out();
	Debug_ADC_Voltage_FBCM_Out();
}

void Debug_FBCM_3()
{
	Debug_Voltage_FBCM_3_In();
	Debug_ADC_Voltage_FBCM_3_In();
	Debug_Current_FBCM_3_In();
	Debug_ADC_Current_FBCM_3_In();
	Debug_Current_FBCM_3_Out();
	Debug_ADC_Current_FBCM_3_Out();

	Debug_Voltage_FBCM_Out();
	Debug_ADC_Voltage_FBCM_Out();
}
