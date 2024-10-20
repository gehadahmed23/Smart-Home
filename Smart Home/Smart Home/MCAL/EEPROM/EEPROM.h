/*
 * EEPROM.h
 *
 * Created: 11/6/2023 11:55:00 AM
 *  Author: Dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../lib/BITMATH.h"
#include "../../lib/TYPES.h"
#include <avr/io.h> 

unsigned char EEPROM_read( u16 address);
void EEPROM_write(u16 address, unsigned char data);

#endif /* EEPROM_H_ */