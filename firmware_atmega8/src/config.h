#ifndef _CONFIG_H
#define _CONFIG_H

#include "eeprom.h"
#include "vars.h"
#include "pwm.h"

/* ******************* */
/*       CONFIG        */
/* ******************* */

volatile struct CONFIG_t	RAM_CONFIG = {\
	/*ADC_OFF*/					InitxN(0),\
									
	/*CHANNEL_SRC[2]*/			InitxN(0),\
								
	/*PWM_SMOOTH_TYPE[2]*/		InitxN(0),\
	/*PWM_SMOOTH_LVL[2]*/		InitxN(100),\
	/*PWM_SMOOTH_AVGLV[2]*/		InitxN(20),\
	
	/*PWM_MODE[2]*/				{0,1,2},\
	/*PWM_CUSTOM[2][16]*/		InitxN(PWM_CUSTOM_INITIALIZER),\
	/*PWM_MIN[2]*/				InitxN(0),\
	/*PWM_MAX[2]*/				InitxN(255),\
								
	/*PWM_LINEAL_ROT[2]*/		InitxN(1),\
	/*PWM_ROT_CENTER[2]*/		InitxN(127.5),\
								
	/*HYP_A[2]*/				InitxN(1.0215908438),\
	/*HYP_X_DIV[2]*/			InitxN(1.0),\
	/*HYP_X_OFF[2]*/			InitxN(4.0),\
	/*HYP_Y_OFF[2]*/			InitxN(-1),\
								
	/*LOG_A[2]*/				InitxN(97.8648403),\
	/*LOG_X_DIV[2]*/			InitxN(25.5),\
	/*LOG_X_OFF[2]*/			InitxN(-1.4509803),\
	/*LOG_Y_OFF[2]*/			InitxN(45.0),\

	/*PWM_MANUAL_VALUE[2]*/		InitxN(255),\
	/*PWM_MANUAL_MODE[2]*/		InitxN(0),\
	
	/*SAMPLE_RATE*/				60,\
	/*START_UP_DELAY*/			10,\
	/*PWM_INIT_VALUE[2]*/		InitxN(255)\
};
//{{0,17,34,51,68,70,72,30,32,34,38,82,100,221,238,255},{0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255}}
							
	/*HYP_A[2]*/			//	InitxN(1.02518438),
	/*HYP_X_DIV[2]*/		//	InitxN(1.0),
	/*HYP_X_OFF[2]*/		//	InitxN(-15.0),
	/*HYP_Y_OFF[2]*/		//	InitxN(9.312),

#endif
