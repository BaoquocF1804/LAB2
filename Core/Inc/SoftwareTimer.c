/*
 * SoftwareTimer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Bao Quoc
 */

#include "SoftwareTimer.h"

int timer1_flag = 0;
int time1_counter = 0;
int TIMER_CYCLE = 10;


void setTimer1(int duration){
	time1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
};



void timerRun(){
	if(time1_counter> 0){
		time1_counter--;
		if (time1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
