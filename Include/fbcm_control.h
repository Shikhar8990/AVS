/*
 * fbcm_control.h
 *
 *  Created on: Mar 21, 2014
 *      Author: ssingh14
 */

#ifndef FBCM_CONTROL_H_
#define FBCM_CONTROL_H_

void control_fbcm1_cv(void);
void control_fbcm1_cc(void);

typedef struct
{
	float32 error, error_1, error_2;
	float32 duty, duty_1, duty_2;
}pidParams_t;


typedef struct
{
	float32 error, error_1, error_2;
	float32 voltage, voltage_1, voltage_2;
}pidParams_c;

#endif /* FBCM_CONTROL_H_ */
