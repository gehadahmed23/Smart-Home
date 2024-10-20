/*
 *      Author: Gehad
 *      
 */


#include "DIO_int.h"






void DIO_voidSetPinDir(u8 u8PortId, u8 u8PinId, u8 u8PinDir)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{

			if (u8PinDir == DIO_PIN_INPUT)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: CLR_BIT(DDRA,u8PinId); break;
						case DIO_PORTB: CLR_BIT(DDRB,u8PinId); break;
						case DIO_PORTC: CLR_BIT(DDRC,u8PinId); break;
						case DIO_PORTD: CLR_BIT(DDRD,u8PinId); break;
					}
				}
				else if (u8PinDir == DIO_PIN_OUTPUT)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: SET_BIT(DDRA,u8PinId); break;
						case DIO_PORTB: SET_BIT(DDRB,u8PinId); break;
						case DIO_PORTC: SET_BIT(DDRC,u8PinId); break;
						case DIO_PORTD: SET_BIT(DDRD,u8PinId); break;
					}
				}
		}
}



void DIO_voidSetPinVal(u8 u8PortId, u8 u8PinId, u8 u8PinVal)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{

			if (u8PinVal == DIO_PIN_LOW)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: CLR_BIT(PORTA,u8PinId); break;
						case DIO_PORTB: CLR_BIT(PORTB,u8PinId); break;
						case DIO_PORTC: CLR_BIT(PORTC,u8PinId); break;
						case DIO_PORTD: CLR_BIT(PORTD,u8PinId); break;
					}
				}
				else if (u8PinVal == DIO_PIN_HIGH)
				{
					switch(u8PortId)
					{
						case DIO_PORTA: SET_BIT(PORTA,u8PinId); break;
						case DIO_PORTB: SET_BIT(PORTB,u8PinId); break;
						case DIO_PORTC: SET_BIT(PORTC,u8PinId); break;
						case DIO_PORTD: SET_BIT(PORTD,u8PinId); break;
					}
				}
		}
}


void DIO_voidTogPinVal(u8 u8PortId, u8 u8PinId)
{
		if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
		{
					switch(u8PortId)
					{
						case DIO_PORTA: TOG_BIT(PORTA,u8PinId); break;
						case DIO_PORTB: TOG_BIT(PORTB,u8PinId); break;
						case DIO_PORTC: TOG_BIT(PORTC,u8PinId); break;
						case DIO_PORTD: TOG_BIT(PORTD,u8PinId); break;
					}

		}
}




u8 DIO_u8GetPinVal(u8 u8PortId, u8 u8PinId)
{

	if (u8PortId <=  DIO_PORTD && u8PinId <= DIO_PIN7 )
	{
		u8 u8Result;

		switch(u8PortId)
		{
			case DIO_PORTA: u8Result= READ_BIT(PINA,u8PinId); break;
			case DIO_PORTB: u8Result= READ_BIT(PINB,u8PinId); break;
			case DIO_PORTC: u8Result= READ_BIT(PINC,u8PinId); break;
			case DIO_PORTD: u8Result= READ_BIT(PIND,u8PinId); break;
		}
		return u8Result;
	}
}






void DIO_voidSetPortDir(u8 u8PortId, u8 u8PortDir)
{
	if (u8PortId <=  DIO_PORTD)
	{
			switch(u8PortId)
			{
			case DIO_PORTA: DDRA =  u8PortDir; break;
			case DIO_PORTB: DDRB=  u8PortDir; break;
			case DIO_PORTC: DDRC=  u8PortDir; break;
			case DIO_PORTD: DDRD=  u8PortDir; break;
			}
	}

}


void DIO_voidSetPortVal(u8 u8PortId, u8 u8PortVal)
{
	if (u8PortId <=  DIO_PORTD)
	{
			switch(u8PortId)
			{
			case DIO_PORTA: PORTA=  u8PortVal; break;
			case DIO_PORTB: PORTB=  u8PortVal; break;
			case DIO_PORTC: PORTC=  u8PortVal; break;
			case DIO_PORTD: PORTD=  u8PortVal; break;
			}
	}
}

void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		if(connect_pullup==DIO_PIN_HIGH)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(connect_pullup==DIO_PIN_HIGH)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		if(connect_pullup==DIO_PIN_HIGH)
		{
			SET_BIT(PORTC,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		if(connect_pullup==DIO_PIN_HIGH)
		{
			SET_BIT(PORTD,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
	}
}
void write_low_nibble(unsigned char portname,unsigned char value)
{
	value&=0x0f;
	switch(portname)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		case 'C':
		PORTC&=0xf0;
		PORTC|=value;
		case 'D':
		PORTD&=0xf0;
		PORTD|=value;
	}
}

void write_high_nibble(unsigned char portname,unsigned char value)
{
	value<<=4;
	switch(portname)
	{
		case DIO_PORTA:
		PORTA&=0x0f;
		PORTA|=value;
		case DIO_PORTB:
		PORTB&=0x0f;
		PORTB|=value;
		case DIO_PORTC:
		PORTC&=0x0f;
		PORTC|=value;
		case DIO_PORTD:
		PORTD&=0x0f;
		PORTD|=value;
	}
}