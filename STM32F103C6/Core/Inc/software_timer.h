/*
 * software_timer.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
int timer0_flag;
int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);

void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
