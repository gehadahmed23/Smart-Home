/*
 * Timer_int.h
 *
 * Created: 10/19/2024 11:17:08 PM
 *  Author: Dell
 */ 


#ifndef TIMER_INT_H_
#define TIMER_INT_H_


#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../lib/BITMATH.h"
#include "../../lib/TYPES.h"

void timer0_overflow(void);
void timer_CTC_init_interrupt(void);
void timer1_overflow(void);
void timer1_ctc(void);
void timer2_overflow(void);
void timer2_ctc(void);
void timer2_overflow_External_clock(void);
void timer_wave_nonPWM(void);
void timer_wave_fastPWM(u8 duty_cycle);
void timer_wave_phasecorrectPWM(void);
void timer1_wave_fastPWM_B(u16 value);
void timer1_wave_fastPWM_A(u16 value);
void timer2_overflow_init_interrupt(void);


#endif /* TIMER_INT_H_ */