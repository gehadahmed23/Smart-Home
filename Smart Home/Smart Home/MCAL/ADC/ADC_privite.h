/*
 * ADC_privite.h
 *
 * Created: 8/15/2024 11:29:53 AM
 *  Author: Dell
 */ 



#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include <avr/io.h> // Include standard AVR IO definitions

// ADC Register Definitions
#define ADMUX    (*(volatile u8 *) (0x27)) // ADC Multiplexer Selection Register
#define ADCSRA   (*(volatile u8 *) (0x26)) // ADC Control and Status Register A
#define ADCH     (*(volatile u8 *) (0x25)) // ADC Data Register High Byte
#define ADCL     (*(volatile u8 *) (0x24)) // ADC Data Register Low Byte
#define ADC_ADC  (*(volatile u16 *)(0x24)) // ADC Data Register (16-bit access)

// ADC Reference Voltage Selections for ADMUX Register
#define REFS1 7
#define REFS0 6

// ADC Left Adjust Result Bit in ADMUX
#define ADLAR 5

// ADC Channel Selection Bits in ADMUX
#define MUX4  4
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0

// ADC Enable Bit in ADCSRA Register
#define ADEN  7

// ADC Start Conversion Bit in ADCSRA Register
#define ADSC  6

// ADC Auto Trigger Enable Bit in ADCSRA Register
#define ADATE 5

// ADC Interrupt Flag Bit in ADCSRA Register
#define ADIF  4

// ADC Interrupt Enable Bit in ADCSRA Register
#define ADIE  3

// ADC Prescaler Select Bits in ADCSRA Register
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

//Clear prescale
#define PRE_CLR 0xf8
#define REF_CLR 0x3f
#define CH_CLR 0xf8
#define ch_check 0x07



#endif /* ADC_PRIVATE_H_ */
