/*
 * DC_config.h
 *
 * Created: 12/08/2024 03:24:07 م
 *  Author: Gehad
 */ 


#ifndef DC_CONFIG_H_
#define DC_CONFIG_H_
#include "../../MCAL/DIO/DIO_int.h"

#define TERM1 PORTC
#define TERM2 PORTC

typedef enum { //creat new type that represent how dc motor will work
     off, CW, A_CW //off //clockwise ..anti-colckwise
} DcMotor_State; //type of these variable


#endif /* DC_CONFIG_H_ */