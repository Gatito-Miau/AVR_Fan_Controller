//#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include <avr/wdt.h> 
#include <avr/io.h>
#include <util/atomic.h> 
#include <util/delay.h>
#include <avr/eeprom.h> 

#include <func.h>


#include "fancontroler.h"
#include "pwm.h"
#include "uart.h"
#include "adc.h"
#include "int0.h"
#include "eeprom.h"
//#include "debug.h"
#include "printf.h"

#include "config.h"


volatile int16_t 	imp16;

volatile uint8_t	halt;

int main(void)
{
	init();

    while(1)
    {
    	while(halt){_delay_ms(100);}
    	
		for (uint8_t i = 0; i < PWM_OUTPUT_CHANNELS; i++)
		{
			if (RAM_CONFIG.PWM_MANUAL_MODE[i])
			{
				imp16 = RAM_CONFIG.PWM_MANUAL_VALUE[i];
			}
			else
			{
				imp16 = ADC_getvalue8(RAM_CONFIG.CHANNEL_SRC[i],i);
			}
			
			PWM_setdc(imp16,i);
		}
		
//		printf("%i\r\n", RAM_CONFIG.ADC_OFF*-1);
//		printf("adc: %i | %u - %u - %u | %i - %i - %i\r\n", imp16, PWM_CHANNEL_1, PWM_CHANNEL_2, PWM_CHANNEL_3, (int)(PWM_DCC[0]*100), (int)(PWM_DCC[1]*100), (int)(PWM_DCC[2]*100) );

		_delay_ms(1000.0/(float)RAM_CONFIG.SAMPLE_RATE);

    }

    //Reset_AVR();
}

 
void init()
{
	//DDRB = _BV(PB3)|_BV(PB2)|_BV(PB1); PORTB = _BV(PB3)|_BV(PB2)|_BV(PB1); // just in case it hangs while initiatin, the fans stay at full speed

	UART_init();
	UART_initmsg();

	EEPROM_init();
	
    PWM_init();
    ADC_init();
	INT0_init();
	
	INT0_MODE = INT0_MODE_RESET;
	sei();
	UART_print("Listo!\r\n");
}
