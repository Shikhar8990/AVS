#ifndef ADC_H
#define ADC_H


#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)


void InitADC(void);
void StartADC_Seq1(void);

#endif
