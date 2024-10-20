/*
 * Timer.c
 *
 * Created: 2/6/2024 8:17:57 AM
 *  Author: Dell
 */ 

#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer.h"

void timer_overflow(void){
	//set no prescaler here
	SET_BIT(TCCR0,CS00);
	//SET_BIT(TCCR0,CS02);
	//sei();
	//SET_BIT(TIMSK,TOIE0);
}
void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

void timer1_wave_fastPWM_A(short angle)
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,5);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	double value, step = 0.0055555555555556;
	if(angle < 0){
		value = 1 + (step * (90 + angle));
	}
	else {
		value = 1.5 + (step * angle);
	}
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
}

void timer1_wave_fastPWM_B(short angle)
{
	/* set OC1B as output pin */
	SET_BIT(DDRD,4);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1B,ICR1 */
	double value, step = 0.0055555555555556;
	if(angle < 0){
		value = 1 + (step * (90 + angle));
	}
	else {
		value = 1.5 + (step * angle);
	}
	OCR1B=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1B1);
}

void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer2_overflow_init_interrupt(void)
{
	/* select timer clock */
	SET_BIT(ASSR,AS2);
	/* select timer pre scalar */
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,TOIE2);
}
