/*
 * Sev_seg.h
 *
 * Created: 8/13/2024 10:54:51 AM
 *  Author: Dell
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#include "../../MCAL/DIO/DIO_int.h"
#include "Sev_config.h"
#include <util/delay.h>

void seven_seg_vinit(u8 sev_port);
void seven_seg_write(u8 sev_port,u8 num);
void Sev_voidCountUp(u8 sev_port);
void Sev_voidCountDown(u8 sev_port);
void Sev_voidTurnOFF(u8 sev_port);
void Sev_voidCheckAll(u8 sev_port);
void Sev_voidDisplay2Digit(u8 sev_port1, u8 sev_port2, u8 num);

#endif /* SEV_SEG_H_ */