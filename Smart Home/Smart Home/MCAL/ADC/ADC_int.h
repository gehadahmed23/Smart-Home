/*
 * ADC_int.h
 *
 * Created: 8/15/2024 11:29:32 AM
 *  Author: Dell
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "../../MCAL/DIO/DIO_int.h"
#include "ADC_privite.h"
#include "ACD_config.h"

#define CH_0 0x00
#define CH_1 0x01
#define CH_2 0x02
#define CH_3 0x03
#define CH_4 0x04
#define CH_5 0x05
#define CH_6 0x06
#define CH_7 0x07

void ADC_voidADCinit();
u16 ADC_Read(void);




#endif /* ADC_INT_H_ */