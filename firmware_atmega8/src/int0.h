#ifndef _INT0_H
#define _INT0_H

#include <stdint.h>

extern volatile uint8_t INT0_MODE;

enum INT0_MODE_T
{
	INT0_MODE_NOP,
	INT0_MODE_RESET,
};

void INT0_init();

#endif
