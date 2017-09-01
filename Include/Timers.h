/*
 * Timers.h
 *
 *  Created on: Mar 20, 2012
 *      Author: MIHIR
 */

#ifndef TIMERS_H_
#define TIMERS_H_






void InitTimers();
void ConfigTimer0(float Period);
void ConfigTimer1(float Period);
void ConfigTimer2(float Period);
void StartTimer0(void);
void StartTimer1(void);
void StartTimer2(void);
void StopTimer0(void);
void StopTimer1(void);
void StopTimer2(void);


#endif /* TIMERS_H_ */
