#include <string.h>
#include <stdint.h>
#include <stdlib.h>

//#include <util/delay.h>


#include "libavrutils.h"


/* ******************* */
/*    Memory/String    */
/* ******************* */


//void memshft(void* ptr, uint16_t val, uint16_t size, uint8_t zero)
//{
////    if (val >= size)
////    {
////        val = size % val;
////    }
////    if (val < 1)
////    {
////        return;
////    }
////
////    memmove(ptr, (void*)ptr+val, size-val);
////
////    if (zero)
////    {
////        memset ((void*)ptr+(size-val), 0, val);
////    }
//}

int16_t strfnd(char* str, char* chain, uint8_t backward, uint8_t at_end, uint16_t skip, uint16_t max)
{
    int16_t tmp = 0;
    int16_t str_len;
    int16_t chain_len = strlen(chain);

	if (!max)
	{
		str_len = strlen(str);
	}
	else
	{
		str_len = max;
	}
	
    if (strlen(str) == 0)
    {
        return -1;
    }

    switch(backward)
    {
    case 1:
//        for (int16_t i = str_len-1; i > 0; i--)
//        {
//
//            if(str[i] == chain[0])
//            {
//                for (int16_t j = 0; j < chain_len; j++)
//                {
//
//                    if(str[i+j] == chain[j])
//                    {
//                        tmp++;
//                    }
//                    else
//                    {
//                        j = chain_len;
//                        tmp = 0;
//                    }
//                    if (j == chain_len-1 && tmp == chain_len)
//                    {
//                        if(skip > 0)
//                        {
//                            skip--;
//                        }
//                        else
//                        {
//                            if(at_end)
//                            {
//                                return i + strlen(chain);
//                            }
//                            else
//                            {
//                                return i;
//                            }
//                        }
//                    }
//                }
//            }
//        }
        break;
 
    case 0:
        for (int16_t i = 0; i < str_len; i ++)
        {
 
            if(str[i] == chain[0])
            {
                for (int16_t j = 0; j < chain_len; j++)
                {
 
                    if(str[i+j] == chain[j])
                    {
                        tmp++;
                    }
                    else
                    {
                        j = chain_len;
                        tmp = 0;
                    }
                    if (j == chain_len-1 && tmp == chain_len)
                    {
                        if(skip > 0)
                        {
                            skip--;
                        }
                        else
                        {
                            if(at_end)
                            {
                                return i + strlen(chain);
                            }
                            else
                            {
                                return i;
                            }
                        }
                    }
                }
            }
        }
        break;
    }
 
    return -1;
}
 
//int16_t chrfnd(char* str, char* chars, uint8_t backward, uint8_t at_end, uint16_t skip)
//{
//	int16_t tmp = 0;
//	int16_t inicio = -1, final = -1;
//	
//	
//	int16_t str_len = strlen(str), chars_len = strlen(chars);
//
//	if (strlen(str) == 0){return -1;}
//
//	switch(backward){
//		case 1:
//			for (int16_t i = str_len-1; i >= 0; i --)
//			{
//				tmp = 0;
//				for (int16_t j = 0; j < chars_len; j++)
//				{
//					if (str[i]==chars[j])
//					{
//						if (final < 0){ final = i+1;}
//						tmp = 1;
//						break;
//					}
//				}
//				if (tmp == 0 && final != -1)
//				{
//					inicio = i+1;
//					if (skip > 0){skip --; final=-1; inicio=-1;}
//					else{
//						return (at_end != 0 ? final : inicio);
//					}
//				}
//			}
//			if ( final != -1 && inicio == -1)
//			{
//				if (skip > 0){skip --;}
//				else{
//					return (at_end != 0 ? final : 0);
//				}
//			}
//			break;
//		case 0:
//			for (int16_t i = 0; i < str_len; i ++)
//			{
//				tmp = 0;
//				for (int16_t j = 0; j < chars_len; j++)
//				{
//					if (str[i]==chars[j])
//					{
//						if (inicio < 0) { inicio = i; }
//						tmp = 1;
//						break;
//					}
//				}
//				if (tmp == 0 && inicio != -1)
//				{
//					final = i;
//					if (skip > 0){skip --; inicio=-1; final=-1;}
//					else{
//						return (at_end != 0 ? final : inicio);
//					}
//				}
//			}
//			if (inicio != -1 && final == -1)
//			{
//				return (at_end != 0 ? str_len : inicio);
//			}
//			break;
//	}
//
//	return -1;
//}


/* ******************* */
/*         Math        */
/* ******************* */

void binstr(uint8_t val, char* bin)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		if(val%2){bin[7-i] = '1';}
		else{bin[7-i] = '0';}
		val = val>>1;
	}
}

//uint8_t average_uint8(uint8_t n, uint8_t* values, uint8_t n)
//{
//	
//	uint16_t 		timp		= 0;
//	static uint8_t 	cnt 		= 0;
//	
//	values [cnt++%8] = n;
//	
//	for (uint8_t i=0; i<8;i++)
//	{
//		timp += values[i];
//	}
//	timp /= 8;
//	return timp;
//}

//double average_double(double n)
//{
//	
//	double	 		timp		= 0.0;
//	static uint8_t 	cnt 		= 0;
//	static double 	num [8] 	= {255,255,255,255,255,255,255,255};
//	
//	num [cnt++%8] = n;
//	
//	for (uint8_t i=0; i<8;i++)
//	{
//		timp += num[i];
//	}
//	timp /= 8;
//	return timp;
//}


/* ******************* */
/*         Time        */
/* ******************* */
//void _delay_ms_plus(uint16_t ms)
//{
//	for(uint16_t i=0;i<ms;i++){_delay_ms(1);}
//}

