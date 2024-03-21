#ifndef _PWM_H
#define _PWM_H

#include <stdint.h>

/* ******************* */
/*         PWM         */
/* ******************* */
#define PWM_CUSTOM_INITIALIZER {0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255}

#define	PWM_SMOOTH_AVG_SIZE	20

#define PWM_OUTPUT_CHANNELS	3
#define PWM_OUTPUT_CHANNELS_ENABLED	3


#define PWM_CHANNEL_1	OCR2
#define PWM_CHANNEL_2	OCR1B
#define PWM_CHANNEL_3	OCR1A

extern float	PWM_DCC [PWM_OUTPUT_CHANNELS];


void 	PWM_init		(void);

void PWM_setdc(int16_t dc,  uint8_t ch_sel);

float PWM_average		(float n, float* values, uint8_t vcnt, uint8_t* cnt);


#endif
