/*
 * SoftwareTimer.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Bao Quoc
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
