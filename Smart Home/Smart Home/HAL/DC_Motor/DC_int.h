/*
 * DC_int.h
 *
 * Created: 12/08/2024 03:23:38 م
 *  Author: Dell
 */ 


#ifndef DC_INT_H_
#define DC_INT_H_

#include "../../lib/BITMATH.H"
#include "../../lib/TYPES.H"


#include "../../MCAL/DIO/DIO_int.h"
#include "DC_config.h"

void DC_init();
void DC_Motor_voidRotate(DcMotor_State state, u8 pin, u8 speed);


#endif /* DC_INT_H_ */