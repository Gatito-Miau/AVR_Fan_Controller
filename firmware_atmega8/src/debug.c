#ifdef _DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/pgmspace.h> 

#include "uart.h"

char* DEBUG_tmp;
void gotox(int x, char* str) {
        char essq[9];
        char xstr[6];

        sprintf(xstr, "%d", x);
        essq[0] = '\0';

		strcat(essq, "\033[");
        strcat(essq, xstr);
        strcat(essq, "G");
		
		strcpy(str, essq);
        
}

void _UART_DumpMem (void* Addr, int8_t n, int8_t jump)
{
	DEBUG_tmp = (char*)malloc(16);
	
	sprintf_P(DEBUG_tmp, PSTR("%X-%X\r\n"), Addr, Addr+n); UART_print(DEBUG_tmp);
	
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && i%jump==0){UART_print("\r\n");}
		
		gotox( ((i%jump)*4)+(i%jump/4)*1, DEBUG_tmp); UART_print(DEBUG_tmp);
		
		if (((uint8_t*)Addr+i)[0] < 16){UART_print("0");}
		sprintf_P(DEBUG_tmp, PSTR("%X"), ((uint8_t*)Addr+i)[0]); UART_print(DEBUG_tmp);
	}
	UART_print("\r\n");
	
	
	
	free(DEBUG_tmp);
}

#endif
