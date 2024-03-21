#include <math.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include <func.h>

#include "eeprom.h"
#include "pwm.h"
#include "vars.h"
#include "uart.h"
#include "printf.h"
/* ******************* */
/*         PWM         */
/* ******************* */
//int16_t 	PWM_tmp16;
float		PWM_tmp;
float 		PWM_lmt;

float		PWM_DCO [PWM_OUTPUT_CHANNELS];

float		PWM_DCC [PWM_OUTPUT_CHANNELS];
float		PWM_DCC_OLD [PWM_OUTPUT_CHANNELS];

float		PWM_SMOOTH_AVG [PWM_OUTPUT_CHANNELS][PWM_SMOOTH_AVG_SIZE];
uint8_t		PWM_SMOOTH_AVG_CNTR [PWM_OUTPUT_CHANNELS];

void PWM_init(void)
{
    DDRB |= (1<<PB3) | (1<<PB2) | (1<<PB1);

    TIMSK &= ~((1<<OCIE2)|(1<<TOIE2));
	
	TCCR1A 	= _BV(COM1B1) | _BV(COM1A1) | _BV(WGM10);
	TCCR1B	= _BV(WGM12) | _BV(CS10);
	
    TCCR2 	= _BV(WGM20) | _BV(COM21) | _BV(WGM21) | _BV(CS20);

	PWM_CHANNEL_1 = RAM_CONFIG.PWM_INIT_VALUE[0];
	PWM_DCC[0] = PWM_CHANNEL_1;
	PWM_DCO[0] = PWM_DCC[0];
	
#if PWM_OUTPUT_CHANNELS > 1
	PWM_CHANNEL_2 = RAM_CONFIG.PWM_INIT_VALUE[1];
	PWM_DCC[1] = PWM_CHANNEL_2;
	PWM_DCO[1] = PWM_DCC[1];
#endif
#if PWM_OUTPUT_CHANNELS > 2
	PWM_CHANNEL_3 = RAM_CONFIG.PWM_INIT_VALUE[2];
	PWM_DCC[2] = PWM_CHANNEL_3;
	PWM_DCO[2] = PWM_DCC[2];
#endif
	
	for (uint16_t i = 0; i < PWM_OUTPUT_CHANNELS*PWM_SMOOTH_AVG_SIZE; i++)
	{
		PWM_SMOOTH_AVG[i/PWM_SMOOTH_AVG_SIZE][i%PWM_SMOOTH_AVG_SIZE] = RAM_CONFIG.PWM_INIT_VALUE[i/PWM_SMOOTH_AVG_SIZE];
	}
	
	_delay_ms_plus(RAM_CONFIG.START_UP_DELAY*100);
}


/* ******************* */
/*     Functions       */
/* ******************* */
void PMW_adc_adj(int16_t* dc, uint8_t ch_sel)
{
	if (RAM_CONFIG.PWM_SMOOTH_TYPE[ch_sel])
	{
		*dc = RAM_CONFIG.PWM_MIN[ch_sel] + round ((float)(*dc)/(float)255*(float)(RAM_CONFIG.PWM_MAX[ch_sel]-RAM_CONFIG.PWM_MIN[ch_sel]));
	}
}
void PMW_dcc_adj(float* dcc, uint8_t ch_sel)
{
	if (dcc[ch_sel] > RAM_CONFIG.PWM_MAX[ch_sel])
    {
        dcc[ch_sel] = RAM_CONFIG.PWM_MAX[ch_sel];
    }
    else if (dcc[ch_sel] < RAM_CONFIG.PWM_MIN[ch_sel])
    {
        dcc[ch_sel] = RAM_CONFIG.PWM_MIN[ch_sel];
    }
}
void PWM_set_dc(float* dcc, uint8_t ch_sel)
{
	if ( isnan(dcc[ch_sel]) || isinf(dcc[ch_sel]))
    {
    	dcc[ch_sel] = PWM_DCC_OLD[ch_sel];
	}	
	if (ch_sel == 0)		// canal 1
	{
		while ( (ASSR&(1<<OCR2UB)) == (1<<OCR2UB) ){_delay_us(100);}
		PWM_CHANNEL_1 = round(dcc[ch_sel]);
	}
	else if (ch_sel == 1)	// canal 2
	{
#if PWM_OUTPUT_CHANNELS_ENABLED > 1		
		PWM_CHANNEL_2 = round(dcc[ch_sel]);
#endif
	}
	else if (ch_sel == 2)	// canal 3
	{
#if PWM_OUTPUT_CHANNELS_ENABLED > 2
		PWM_CHANNEL_3 = round(dcc[ch_sel]);
#endif
	}
	PWM_DCC_OLD[ch_sel] = dcc[ch_sel];
}
void PWM_dc_rotation(int16_t* dc, uint8_t ch_sel)
{
	*dc = round( (float)(RAM_CONFIG.PWM_ROT_CENTER[ch_sel] + ((float)((*dc)-RAM_CONFIG.PWM_ROT_CENTER[ch_sel])*(float)RAM_CONFIG.PWM_LINEAL_ROT[ch_sel])));
	if (*dc > 255) {*dc = 255;}
	if (*dc < 0) {*dc = 0;}
}
void PWM_update_lmt(uint8_t ch_sel)
{
	PWM_lmt = ((255.0/(float)RAM_CONFIG.SAMPLE_RATE)*((float)RAM_CONFIG.SAMPLE_RATE/(RAM_CONFIG.PWM_SMOOTH_LVL[ch_sel]+1.0)));
}

float PWM_linear_smooth(int16_t dc, uint8_t ch_sel)
{
	float PWM_tmp;
	
	PWM_tmp = (float)((float)PWM_DCO[ch_sel] - (float)dc);
	
	PWM_update_lmt(ch_sel);
	if (mod(PWM_tmp) >  PWM_lmt)	
	{
		PWM_tmp /= (float)(mod(PWM_tmp) / PWM_lmt);
	}
	
	PWM_tmp = PWM_DCO[ch_sel] - PWM_tmp;
	PWM_DCO[ch_sel] = PWM_tmp;
	
	return PWM_average(PWM_tmp, PWM_SMOOTH_AVG[ch_sel], RAM_CONFIG.PWM_SMOOTH_AVGLV[ch_sel], &PWM_SMOOTH_AVG_CNTR[ch_sel]) ;
}
void PWM_setdc(int16_t dc,  uint8_t ch_sel)
{
	PWM_dc_rotation(&dc, ch_sel);
	
	PMW_adc_adj(&dc, ch_sel);
	
	PWM_tmp = PWM_linear_smooth(dc, ch_sel);
	int16_t d,r,x,y;
	switch (RAM_CONFIG.PWM_MODE[ch_sel])
	{
		default:
		case 0:	// linear
			PWM_DCC[ch_sel] = PWM_tmp;
			break;
		case 1:	// hyperbolic
			PWM_DCC[ch_sel] = (pow(RAM_CONFIG.HYP_A[ch_sel],(PWM_tmp/RAM_CONFIG.HYP_X_DIV[ch_sel])+RAM_CONFIG.HYP_X_OFF[ch_sel])+RAM_CONFIG.HYP_Y_OFF[ch_sel]);
			break;
		case 2:	// logaritmic
			PWM_DCC[ch_sel] = ((log((PWM_tmp/RAM_CONFIG.LOG_X_DIV[ch_sel])+RAM_CONFIG.LOG_X_OFF[ch_sel])*RAM_CONFIG.LOG_A[ch_sel])+RAM_CONFIG.LOG_Y_OFF[ch_sel]);
			break;
		case 255:	// custom
			d = PWM_tmp/17;
			r = (uint8_t)PWM_tmp%17;
			x = RAM_CONFIG.PWM_CUSTOM[ch_sel][d];
			y = RAM_CONFIG.PWM_CUSTOM[ch_sel][d+1]-x;
			if (d >= 15) {PWM_DCC[ch_sel] = RAM_CONFIG.PWM_CUSTOM[ch_sel][15];}
			else
			{
				PWM_DCC[ch_sel] = x+(((float)(y)/17.0)*r);
			}
			break;
	}

	PMW_dcc_adj(PWM_DCC, ch_sel);
    
    PWM_set_dc(PWM_DCC, ch_sel);
}


float PWM_average(float n, float* values, uint8_t vcnt, uint8_t* cntr)
{
	float	timp		= 0;
	
	values [(*cntr)++%vcnt] = n;
	
	for (uint8_t i=0; i<vcnt;i++)
	{
		timp += values[i];
	}
	timp /= vcnt;
	return timp;
}
