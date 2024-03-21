#include <avr/io.h>
#include <math.h>


#include "eeprom.h"
#include "vars.h"

uint8_t ADC_tmp;

void ADC_init ()
{
	
	DDRC 	= 0;
	PORTC 	= 0;
	
	ADCSRA 	= 0;  // Disable ADC
	
	ADMUX	= (1 << REFS0)|(1 << ADLAR); // AVcc y 8bits
	ADCSRA 	= (1 << ADPS2)|(1 << ADPS1); // Set ADC prescalar to 64 - 125KHz sample rate @ 8MHz
	
	ADCSRA |= (1 << ADEN);  // Enable ADC
}

uint8_t ADC_getvalue8(uint8_t channel, uint8_t ch_sel)
{
	channel &= ~0b11110000;
	
	ADMUX &= ~0b00001111;
	ADMUX |= _BV(channel);
	
	
	ADCSRA |= _BV(ADSC);
	while ((ADCSRA & _BV(ADSC)) == 0){}
	ADCSRA |= _BV(ADIF);

	//if (ADC_OFF[ch_sel] == 0){return ADCH;}
	if 		((int16_t)(ADCH+RAM_CONFIG.ADC_OFF[ch_sel]) > 255) 	{channel = 255;}
	else if ((int16_t)(ADCH+RAM_CONFIG.ADC_OFF[ch_sel]) < 0) 	{channel = 0;}
	else 												{channel = (ADCH+RAM_CONFIG.ADC_OFF[ch_sel]);}
	
	return round(((float)channel)*(255.0/(255.0+(float)RAM_CONFIG.ADC_OFF[ch_sel])));
}
