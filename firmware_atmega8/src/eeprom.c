#include <stdlib.h>
#include <avr/eeprom.h> 
#include <util/delay.h>

#include "uart.h"
#include "vars.h"
#include "pwm.h"
//#include "printf.h"

#include "eeprom.h"

struct CONFIG_t EEMEM EEPROM_CONFIG;//= CONFIG_t_Initializer;

uint8_t EEPROM_sanity_check()
{
	uint8_t rc = 0;
	
	if (RAM_CONFIG.SAMPLE_RATE < 20){RAM_CONFIG.SAMPLE_RATE=20;
		rc = 1;}
	for (uint8_t i = 0; i < PWM_OUTPUT_CHANNELS; i++)
	{
		if (RAM_CONFIG.PWM_SMOOTH_AVGLV[i] > PWM_SMOOTH_AVG_SIZE)
		{
			RAM_CONFIG.PWM_SMOOTH_AVGLV[i]=PWM_SMOOTH_AVG_SIZE; rc = 1;
		}
		
		if (RAM_CONFIG.PWM_SMOOTH_AVGLV[i] == 0)
		{
			RAM_CONFIG.PWM_SMOOTH_AVGLV[i]=1; rc = 1;
		}
		
//		if (RAM_CONFIG.PWM_SMOOTH_LVL[i] < (float)(1.0/RAM_CONFIG.SAMPLE_RATE))
//		{
//			RAM_CONFIG.PWM_SMOOTH_LVL[i]=(float)(1.0/RAM_CONFIG.SAMPLE_RATE); rc = 1;
//		}
		
		if (RAM_CONFIG.PWM_MAX[i] < RAM_CONFIG.PWM_MIN[i])
		{
			RAM_CONFIG.PWM_MAX[i]=RAM_CONFIG.PWM_MIN[i]; rc = 1;
		}
		
		if ( !((RAM_CONFIG.PWM_MODE[i] == 0) | (RAM_CONFIG.PWM_MODE[i] == 1) | (RAM_CONFIG.PWM_MODE[i] == 2) | (RAM_CONFIG.PWM_MODE[i] == 255)) )
		{
			RAM_CONFIG.PWM_MODE[i]=0; rc = 1;
		}
		
	}
	return rc;
}

void EEPROM_init()
{
	UART_print("Manten \"RESET\" para reiniciar configuracion");
//	for(uint8_t i=0; i<1; i++)
//	{
		//if((i%40) == 0){UART_print(".");}
		
		if (PIND & _BV(PD2))
		{
			UART_print("\r\nReiniciando...\r\n");
			EEPROM_save_config();
			while(PIND & _BV(PD2)){}
			return;
		}
		//_delay_ms(25);
//	}
	UART_print("\r\n");
	EEPROM_load_config();
}

void EEPROM_load_config()
{
	eeprom_read_block ((void*)&RAM_CONFIG, (const void*)0, CONFIG_t_SIZE);
	
	if (EEPROM_sanity_check())
		{EEPROM_save_config();}
}

void EEPROM_save_config()
{
	eeprom_write_b ((const void*)&RAM_CONFIG, (void*)0,	CONFIG_t_SIZE);
}


//void eeprom_write_1 (uint8_t* __p, uint8_t value)
//{
//	uint8_t tmp = eeprom_read_byte(__p);
//	
//	if (tmp == value) {return;}
//	eeprom_write_byte(__p, value);
//}
//void eeprom_write_2 (uint16_t* __p, uint16_t value)
//{
//	uint16_t tmp = eeprom_read_word(__p);
//	
//	if (tmp == value) {return;}
//	eeprom_write_word(__p, value);
//}
void eeprom_write_b (const void *__src, void *__dst, size_t __n)
{
	uint8_t tmp;
	for (size_t i = 0; i < __n; i++)
	{
		eeprom_read_block((void*)&tmp, __dst+i,1);
		if (((uint8_t*)__src)[i] != tmp)
		{
			eeprom_write_block (__src+i, __dst+i,1);
		}
	}
}

///uint8_t eeprom_read_byte (const uint8_t *addr)
///void eeprom_write_byte (uint8_t *addr, uint8_t value)
///uint16_t eeprom_read_word (const uint16_t *addr)
///void eeprom_write_word (uint16_t *addr, uint16_t value)
///void eeprom_read_block (void *pointer_ram, const void *pointer_eeprom, size_t n)
///void eeprom_write_block (void *pointer_eeprom, const void *pointer_ram, size_t n) 
