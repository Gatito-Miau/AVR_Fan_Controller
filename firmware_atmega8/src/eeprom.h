#ifndef _EEPROM_H
#define _EEPROM_H

#include <stdlib.h>
#include <stdint.h>

#include "pwm.h"
void EEPROM_init();
void EEPROM_load_config();
void EEPROM_save_config();
uint8_t EEPROM_sanity_check();

//void eeprom_write_1 (uint8_t* __p, uint8_t value);
//void eeprom_write_2 (uint16_t* __p, uint16_t value);
void eeprom_write_b (const void *__src, void *__dst, size_t __n);

extern struct CONFIG_t EEPROM_CONFIG;

#define CONFIG_t_SIZE sizeof(struct CONFIG_t)

//#define CONFIG_t_Initializer {InitxN(0), InitxN(0),0, 0 ,InitxN(0),InitxN(0),InitxN(0), InitxN(0),InitxN(0),InitxN(0),InitxN(PWM_CUSTOM_INITIALIZER),InitxN(0),InitxN(0), InitxN(0),InitxN(0), InitxN(0),InitxN(0),InitxN(0),InitxN(0), InitxN(0),InitxN(0),InitxN(0),InitxN(0)}
struct CONFIG_t
{
	int16_t		ADC_OFF			[PWM_OUTPUT_CHANNELS];	// 0
	
	uint8_t		CHANNEL_SRC		[PWM_OUTPUT_CHANNELS];	// 2
	
	uint8_t		PWM_SMOOTH_TYPE	[PWM_OUTPUT_CHANNELS];	// 3
	float		PWM_SMOOTH_LVL	[PWM_OUTPUT_CHANNELS];	// 4 
	uint8_t		PWM_SMOOTH_AVGLV[PWM_OUTPUT_CHANNELS];	// 8
		
	uint8_t		PWM_MODE		[PWM_OUTPUT_CHANNELS];	// 9
	uint8_t		PWM_CUSTOM		[PWM_OUTPUT_CHANNELS][16]; // 10
	uint8_t		PWM_MIN			[PWM_OUTPUT_CHANNELS];	// 26
	uint8_t		PWM_MAX			[PWM_OUTPUT_CHANNELS];	// 27
	
	float		PWM_LINEAL_ROT	[PWM_OUTPUT_CHANNELS];	// 28
	float		PWM_ROT_CENTER	[PWM_OUTPUT_CHANNELS];	// 32
	
	float		HYP_A			[PWM_OUTPUT_CHANNELS];	// 36
	float		HYP_X_DIV		[PWM_OUTPUT_CHANNELS];	// 40
	float		HYP_X_OFF		[PWM_OUTPUT_CHANNELS];	// 44
	float		HYP_Y_OFF		[PWM_OUTPUT_CHANNELS];	// 48
	
	float		LOG_A			[PWM_OUTPUT_CHANNELS];	// 52
	float		LOG_X_DIV		[PWM_OUTPUT_CHANNELS];	// 56
	float		LOG_X_OFF		[PWM_OUTPUT_CHANNELS];	// 60
	float		LOG_Y_OFF		[PWM_OUTPUT_CHANNELS];	// 64
	
	uint8_t		PWM_MANUAL_VALUE[PWM_OUTPUT_CHANNELS];	// 68 - para q queden los float en multiplo de 4
	uint8_t		PWM_MANUAL_MODE [PWM_OUTPUT_CHANNELS];	// 69
	
	uint8_t		SAMPLE_RATE;							// 0 + 70 *
	uint8_t		START_UP_DELAY;							// 1 + 70 *
	uint8_t		PWM_INIT_VALUE	[PWM_OUTPUT_CHANNELS];	// 2 + 70
}; // 2 + 71 * PWM_OUTPUT_CHANNELS) bytes



#define Initx1(a) a
#define Initx2(a) {a,a}
#define Initx3(a) {a,a,a}
#define Initx4(a) {a,a,a,a}
//
//#define __InitxN(a,b) Initx ## a (b)
//
//#define	_InitxN(a,b) __InitxN(a,b)
//
//#define	InitxN(a) _InitxN(PWM_OUTPUT_CHANNELS,a) 

#define __InitxN(a) Initx ## a

#define	_InitxN(a) __InitxN(a)

#define	InitxN _InitxN(PWM_OUTPUT_CHANNELS) 

#endif
