#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/eeprom.h> 

#include "adc.h"
#include "pwm.h"
#include "eeprom.h"
#include "func.h"
#include "uart.h"
#include "vars.h"
#include "printf.h"
#include "version.h"

/* ******************* */
/*        USART        */
/* ******************* */

uint8_t	UART_is_inited;
 
volatile char	 UART_buffer [UART_BUFFER_SIZE];
volatile uint8_t UART_buffer_pos = 0;
volatile uint8_t UART_msg_id;

void UART_initmsg ()
{
	UART_print("\rFan Controller MK1 - V");
	UART_print((char*)FULLVERSION_STRING);
	UART_print("\r\n");
}
 
void UART_init(void)
{
    //ports
    DDRD &= ~_BV(PD0);
    DDRD |= _BV(PD1);
    PORTD |= _BV(PD0)|_BV(PD1);
 
    // uart
    UCSRB 	= 0x00;									// disable UART
 
    UCSRB 	|= _BV(RXCIE);
    UCSRC 	= _BV(URSEL)|_BV(UCSZ1)|_BV(UCSZ0);		//8 bit date
 
    UBRRH 	= (uint8_t)(BAUD_PRESCALE>>8);			//baud rate high bits
    UBRRL 	= (uint8_t)BAUD_PRESCALE;				//baud rate low bits
 
    UCSRB 	|= _BV(RXEN) | _BV(TXEN);				//Enable
 
    UART_is_inited = 1;
}
 
void UART_put(uint8_t i)
{
    while(!(UCSRA & _BV(UDRE)));	//when the buffer is empty then send a bit
    UDR = i;
}
 
void UART_print(char *s)
{
    while(*s)
    {
        UART_put(*s);
        s++;
        //_delay_us(100);
    }
}
ISR(USART_RXC_vect)
{
    static uint32_t start_code = 0;
 
    uint8_t tmp = UDR;
	
    start_code = start_code << 8;
    start_code |= tmp;
 
    /* ************************************************ */
    /*               CYCLIC BUFFER                      */
    /* ************************************************ */
    if (UART_buffer_pos > UART_BUFFER_SIZE-1)
    {
        for (uint8_t i = 0; i < UART_BUFFER_SIZE-1; i++)
        {
            UART_buffer[i] =UART_buffer[i+1];
        }
        UART_buffer[UART_buffer_pos-1] = tmp;
    }
    else
    {
        UART_buffer[UART_buffer_pos++] = tmp;
    }
    /* ************************************************ */
 
    if (UART_buffer[0] == '>' && UART_buffer[UART_BUFFER_SIZE-1] == '<'){
        tmp = UART_command((struct UART_CMD*)&UART_buffer[0]);
        
        if		(tmp == 0)
        {
        	UART_put('>');UART_put(UART_msg_id);
            UART_print("OK<\r\n");
        }
        else if	(tmp == 1)
        {
            UART_put('>');UART_put(UART_msg_id);
            UART_print("ER<\r\n");
        }
        else if	(tmp == 2)
        {
        	UART_put('>');UART_put(UART_msg_id);
        	UART_print("CE<\r\n");
        } 
        goto clear;
    }
 
    if (!start_code && UART_buffer[0] != '>' ) // "\000\000\000\000"
    {
		clear:
        UART_buffer[0] = 0; UART_buffer[UART_BUFFER_SIZE-1] = 0;
        UART_buffer_pos = 0;
    }
}
uint8_t UART_check_cksum(struct UART_CMD* __p)
{
	uint8_t rc = 0, i;
	for (i = 1; i < UART_CMD_SIZE-2; i++)
	{
		rc ^= ((uint8_t*)(__p))[i];
	}
	if (rc == __p->footer[UART_CMD_CKSUM]){return 1;}
	return 0;
}
int8_t UART_command(struct UART_CMD* buffer)
{
	
	uint8_t  cksum = 0, data;
	uint16_t address, nbytes, i;
	
	UART_msg_id = buffer->footer[UART_CMD_MSGID];

	if (!UART_check_cksum(buffer)){return 2;} // checksum
	
    switch (_i16(buffer->header[0],buffer->header[1]))
	{
	case _i16('>','C'):	// MEMORY WORK - C | SETTINGS - S STRING
    case _i16('>','S'):
		address = (buffer->command & MASK_ADDRESS)>>1;
			if (buffer->header[1] == 'S'){address += sizeof(struct CONFIG_t);}
		nbytes = (buffer->command & MASK_NBYTES)>>9;
        
        //printf("%u - %u - %u\r\n", address, nbytes, buffer->command);
        
        
        if(!(buffer->command & MASK_ACTION)) // set
        {
        	if (nbytes > 4){nbytes = 4;}
        	eeprom_write_b ((const void*)&buffer->data[0], (void*)address, nbytes);
        	break;
        }

		UART_put('>');
		for(i = 0; i < nbytes; i++)
		{
			data = eeprom_read_byte((uint8_t*)(address+i));
			cksum ^= data;
			UART_put(data);
		}
		cksum ^= UART_msg_id;
		UART_put(UART_msg_id);UART_put(cksum);UART_print("<\r\n");

        break;
    case _i16('>','R'):	// RESUME
        halt = 0;
        break;
    case _i16('>','H'):	// HALT
        halt = 1;
        break;
    case _i16('>','T'):	// RESET
        Reset_AVR();
        break;
    case _i16('>','G'):	// GET STATUS
   		UART_put('>');
   		
   		data = (512-sizeof(struct CONFIG_t))>>1;
   		
   		UART_put(data); cksum ^= data;	// free text data bytes
   		UART_put(PWM_OUTPUT_CHANNELS); cksum ^= PWM_OUTPUT_CHANNELS;	// number of channels
   		UART_put(PWM_OUTPUT_CHANNELS_ENABLED); cksum ^= PWM_OUTPUT_CHANNELS_ENABLED;	// number of channels enabled
   		
   		for (i = 0; i < PWM_OUTPUT_CHANNELS; i++)						// adc value of each's input channel
   		{
   			data = ADC_getvalue8(RAM_CONFIG.CHANNEL_SRC[i],i);
   			UART_put(data); cksum ^= data;
   		}
   		for (i = 0; i < PWM_OUTPUT_CHANNELS; i++)						// pwm value of each output
   		{
   			UART_put((uint8_t)PWM_DCC[i]); cksum ^= (uint8_t)PWM_DCC[i];
   		}
		UART_put(halt); cksum ^= halt;									// halt status
		cksum ^= UART_msg_id;
		UART_put(UART_msg_id);UART_put(cksum);UART_print("<\r\n");
        break;
    case _i16('>','V'):	// GET VERSION
        UART_put('>');
   		
   		
   		for (i = 0; i < strlen(FULLVERSION_STRING); i++)
   		{
   			UART_put(FULLVERSION_STRING[i]); cksum ^= FULLVERSION_STRING[i];
   		}
   		
		cksum ^= UART_msg_id;
		UART_put(UART_msg_id);UART_put(cksum);UART_print("<\r\n");
        break;
	case _i16('>','L'):	// LOAD
        EEPROM_load_config();
        break;
	case _i16('>','M'):	// Manual
		for (int i = 0; i < PWM_OUTPUT_CHANNELS; i++)
        {
        	RAM_CONFIG.PWM_MANUAL_MODE[i] = ((uint8_t*)buffer) [2 + i];
        	RAM_CONFIG.PWM_MANUAL_VALUE[i] = ((uint8_t*)buffer) [5 + i];
        }
        eeprom_write_b ((const void*)&RAM_CONFIG.PWM_MANUAL_VALUE[0], (void*)&EEPROM_CONFIG.PWM_MANUAL_VALUE[0] ,PWM_OUTPUT_CHANNELS*2);
        break;
	default:
		return 1;
    }

    return 0;
}
 
 
