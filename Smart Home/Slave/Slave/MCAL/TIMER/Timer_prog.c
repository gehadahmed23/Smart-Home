/*
 * Timer_prog.h
 *
 * Created: 10/19/2024 11:17:08 PM
 *  Author: Dell
 */ 


#ifndef TIMER_PROG_H_
#define TIMER_PROG_H_

/*
 * Timer.c
 *
 * Created: 2/6/2024 4:29:47 AM
 *  Author: VTE
 */ 
#include "Timer_int.h"

void timer0_overflow(void){
	//set prescaler here
	//SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	//SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	//SET_BIT(TCCR0,CS00);
	//sei();
	//SET_BIT(TIMSK,TOIE0);
}
void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=78;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	//sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer1_overflow(void){
	  // Set Timer1 mode (normal mode)
	  TCCR1A = 0;
	  TCCR1B = 0;
	  
	  // Set Timer1 prescaler to 1 (no prescaling)
	  TCCR1B |= (1 << CS10);
	  TCCR1B=0xC2;
	  // Enable Timer1 overflow interrupt
	 // TIMSK |= (1 << TOIE1);
	  
	  // Enable global interrupts
	  //sei();
}
void timer1_ctc(void){
	//set prescaler here
	SET_BIT(TCCR1B,CS10);
	//SET_BIT(TCCR2,CS20)
	//CLR_BIT(TCCR2,WGM10);
	SET_BIT(TCCR1B,WGM12);
	//SET_BIT(TCCR2,CS20);
	// load value here
	OCR1A=0;
	//sei();
	//SET_BIT(TIMSK,OCF1A);
}
void timer2_overflow(void){
	//set prescaler here
	SET_BIT(TCCR2,CS21);
	//SET_BIT(TCCR2,CS20)
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	//SET_BIT(TCCR2,CS20);
	//sei();
	//SET_BIT(TIMSK,TOIE2);
	//
}
void timer2_ctc(void){
	//set prescaler here
	//SET_BIT(TCCR2,CS20)
	//SET_BIT(TCCR2,CS20)
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,CS20);
	// load value here
	OCR0=0;
	sei();
	SET_BIT(TIMSK,OCF2);
}
void timer2_overflow_External_clock(void)
{
	// select timer clock 
	SET_BIT(ASSR,AS2);
	// select timer prescalar 
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	sei();
	SET_BIT(TIMSK,TOIE2);
}
void timer_wave_nonPWM(void)
{

	SET_BIT(DDRB,3);
	// select CTC mode
	SET_BIT(TCCR0,WGM01);
	//load in ocr0
	OCR0=64;
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// toggle OC0 on compare match
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(u8 duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0 //???? ?? ??? ??????

	OCR0 = duty_cycle; // Set Compare Value //  ??? ???? ???? ?????? ???? ????? ?????  compare match
    SET_BIT(DDRB,3);
	//DDRB = DDRB | (1 << PB3); // Configure PB3/OC0 as output pin
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1 // ctc<< clear ,, overflow<< set
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}


void timer_wave_phasecorrectPWM(void)
{
	
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM00);
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
void timer1_wave_fastPWM_A(u16 angle)
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

void timer1_wave_fastPWM_B(u16 angle)
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
void timer2_overflow_init_interrupt(void){
	SET_BIT(ASSR,AS2);
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	//sei();
	SET_BIT(TIMSK,TOIE2);
}


#endif /* TIMER_PROG_H_ */