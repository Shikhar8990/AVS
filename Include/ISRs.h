#ifndef ISR_H
#define ISR_H

interrupt void  adc_isr(void);
interrupt void epwm1_isr(void);
interrupt void epwm2_isr(void);
interrupt void epwm3_isr(void);
interrupt void epwm4_isr(void);
interrupt void epwm5_isr(void);
interrupt void epwm6_isr(void);

interrupt void cpu_timer0_isr(void);
interrupt void cpu_timer1_isr(void);
interrupt void cpu_timer2_isr(void);

interrupt void rxaint_isr(void);
interrupt void txaint_isr(void);

#endif
