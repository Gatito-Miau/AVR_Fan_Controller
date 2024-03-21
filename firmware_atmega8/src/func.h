#ifndef _FUNC_H
#define _FUNC_H


//int16_t strfnd(char* str, char* chain, uint8_t at_end, uint16_t max);

#define _delay_ms_plus(ms) {for(uint16_t i=0;i<ms;i++){_delay_ms(1);}}

#define Reset_AVR() wdt_enable(WDTO_30MS); while(1) {} 

#define _CS(a) (char*)&a
#define _i16(a,b) ((b<<8)|a)

#define mod(a) (sqrt(pow(a,2)))

//double logWithBase(double base, double x);

#endif
