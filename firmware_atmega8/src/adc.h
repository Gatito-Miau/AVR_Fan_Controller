#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>

void 	ADC_init ();
uint8_t	ADC_getvalue8(uint8_t channel, uint8_t ch_sel);

#endif
