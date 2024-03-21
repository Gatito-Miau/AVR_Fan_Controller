#ifndef _VARS_H
#define _VARS_H
#include <stdint.h>


/* ******************* */
/*       GLOABAL       */
/* ******************* */

extern volatile uint8_t			halt;

/* ******************* */
/*       CONFIG        */
/* ******************* */

volatile extern struct CONFIG_t	RAM_CONFIG;

/* ******************* */
/*        USART        */
/* ******************* */

extern volatile char				UART_buffer [];
extern volatile uint8_t 			UART_buffer_pos;


#endif
