/*
 * software_timer.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#include "software_timer.h"

//timer 0
int timer0_counter = 0;
int timer0_flag = 0;
int timer1_counter = 0;
int timer1_flag = 0;
//#define TICK 10;
void setTimer0(int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}

void setTimer1(int duration)
{
	timer1_counter = duration;
	timer1_flag = 0;
}
void timer_run()
{
	if(timer0_counter > 0)
	{
		timer0_counter--;
		if(timer0_counter == 0)
		{
			timer0_flag = 1;
		}
	}

	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter == 0)
		{
			timer1_flag = 1;
		}
	}
}

