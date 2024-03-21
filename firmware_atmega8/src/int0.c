#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h> 
#include <util/delay.h>

#include <func.h>

#include "uart.h"
#include "vars.h"

#include "int0.h"

volatile uint8_t INT0_MODE = 0;

void INT0_init()
{
	DDRD   &= ~_BV(PD2);
	PORTD  &= ~_BV(PD2);	
	
	MCUCR  |= _BV(ISC01) | _BV(ISC00);
	GICR   |= _BV(INT0);
}

ISR(SIG_INTERRUPT0)
{
	switch (INT0_MODE)
	{
		case 0:
			break;
			
		case INT0_MODE_RESET:
			while(PIND & _BV(PD2)){}
			Reset_AVR();
			break;
		
	}
}
