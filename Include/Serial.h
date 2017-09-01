/*
 * Serial.h
 *
 *  Created on: Apr 6, 2012
 *      Author: MIHIR
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUDSTEP 100            // Amount BRR will be incremented between each
                                // autobaud lock


void InitSerial(void);
void autobaud(void);
void scia_init(void);
void scia_echoback_init(void);
void scia_xmit(int a);
void scia_msg(char * msg);
void scia_fifo_init(void);
void InitSciaGpio(void);










#endif /* SERIAL_H_ */
