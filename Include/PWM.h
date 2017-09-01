#ifndef PWM_H
#define PWM_H

#define EPWM1_MIN_DB 0
#define EPWM2_MIN_DB 0
#define EPWM3_MIN_DB 0
#define EPWM4_MIN_DB 0
#define EPWM5_MIN_DB 0
#define EPWM6_MIN_DB 0

#define PWMPeriod 100

void InitPWM();
void InitPwm1Gpio(void);
void InitPwm2Gpio(void);
void InitPwm3Gpio(void);

#if DSP28_EPWM4
void InitPwm4Gpio(void);
#endif // endif DSP28_EPWM4

#if DSP28_EPWM5
void InitPwm5Gpio(void);
#endif // endif DSP28_EPWM5

#if DSP28_EPWM6
void InitPwm6Gpio(void);
#endif // endif DSP28_EPWM6

void InitEPwm1();
void InitEPwm2();
void InitEPwm3();
void InitEPwm4();
void InitEPwm5();
void InitEPwm6();

#endif
