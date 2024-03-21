#ifndef _LIBAVRUTILS_H
#define _LIBAVRUTILS_H

#include <stdint.h>


/* ******************* */
/*    Memory/String    */
/* ******************* */

//void 	memshft(void* ptr, uint16_t val, uint16_t size, uint8_t zero);
int16_t strfnd(char* str, char* chain, uint8_t backward, uint8_t at_end, uint16_t skip, uint16_t max);
//int16_t chrfnd(char* str, char* chars, uint8_t backward, uint8_t at_end, uint16_t skip);

/* ******************* */
/*         Math        */
/* ******************* */

void 	binstr(uint8_t val, char bin[9]);
//uint8_t average_uint8(uint8_t n);
//double average_double(double n);

/* ******************* */
/*         Time        */
/* ******************* */
#define _delay_ms_plus(ms) {for(uint16_t i=0;i<ms;i++){_delay_ms(1);}}
//void _delay_ms_plus(uint16_t ms);

/* ******************* */
/*        System       */
/* ******************* */

#define Reset_AVR() wdt_enable(WDTO_30MS); while(1) {} 

#endif
