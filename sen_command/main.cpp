#include <iostream>
#include <stdint.h>
#include <string.h>

#include "tty_stuff.h"
#include "libgenutils.h"

#define CONFIG_t_Initializer {0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},0,0,0,0, 0,0,0,0, 0,0,0,0, 0, 0}

using namespace std;

int fd, rc;
#define UART_CMD_SIZE	11

struct  UART_CMD	// 11 bytes
{
	char 		header	[2];	// >C (CMD)- >S (STRING) - >R (RESUME) - >H (HALT) - >T (RESET)
	uint16_t	command;
	uint8_t		data	[4];
	char		footer	[3];	// msg_id + "cheksum" + <
};

struct CONFIG_t
{

	int16_t		ADC_OFF;
	
	uint8_t		GEN_SAMPLE_RTE;		

	uint8_t		PWM_MODE;
	uint8_t		PWM_CUSTOM [16];
	uint8_t		PWM_SMOOTH_LVL;
	uint8_t		PWM_SMOOTH_INT;
	uint8_t		PWM_MIN;
	uint8_t		PWM_MAX;

	float		HYP_A;
	float		HYP_X_DIV;
	float		HYP_X_OFF;
	float		HYP_Y_OFF;

	float		LOG_A;
	float		LOG_X_DIV;
	float		LOG_X_OFF;
	float		LOG_Y_OFF;

};// 56 bytes

void reverse (void* __p, uint32_t __n)
{
	uint8_t data;
	uint8_t* P = (uint8_t*)__p;
	
	for (uint32_t i = 0; i < __n/2; i++)
	{
		data = P[i];
		P[i] = P[__n-i-1];
		P[__n-i-1] = data;
	}
	
}
char imp = 0x7f;
uint8_t do_cksum(UART_CMD* __p)
{
	uint8_t rc = 0;
	for (int i = 1; i < UART_CMD_SIZE-2; i++ )
	{
		rc ^= reinterpret_cast<uint8_t*>(__p)[i];
	}
	return rc;
}
int main()
{
    fd = open_port("/dev/ttyUSB0");
    configure_port(fd);
    
    UART_CMD asd = {{'>', 0},0,{0,0,0,0},{0, 0, '<'}};
    
    char* tmp = (char*)malloc(1024);
	CONFIG_t* aaa = (CONFIG_t*)(tmp+1);
	
   	write(fd, "\000\000\000\000\000\000\000\000\000\000\000",11);
    rc = read(fd, tmp, 1024);
	usleep(0.25*1000*1000);
	rc = read(fd, tmp, 1024);
	
	
/****************************************/

    asd.header[1] = 'S';     asd.command = 0 | (0x0<<1) | 65<<9;	asd.footer[0] = imp++;
	memcpy (&asd.data, "1234", 4);
	
	asd.footer[1] = do_cksum(&asd);
	
	
	rc = write(fd, (void*)&asd, UART_CMD_SIZE); debug::DumpMem((void*)&asd,0,0,UART_CMD_SIZE,16); debug::DumpMemASCII((void*)&asd,0,0,UART_CMD_SIZE,16);
	
	rc = read(fd, tmp, 1024); cout << rc <<  endl; debug::DumpMemASCII(tmp,0,0,rc,16);	debug::DumpMem(tmp,0,0,rc,16);
	
/****************************************/
    asd.header[1] = 'S';     asd.command = 1 | (0x0<<1) | 4<<9;	asd.footer[0] = imp++;
	memcpy (&asd.data, "5678", 4);
	
	asd.footer[1] = do_cksum(&asd);
	
	
	rc = write(fd, (void*)&asd, UART_CMD_SIZE); debug::DumpMem((void*)&asd,0,0,UART_CMD_SIZE,16); debug::DumpMemASCII((void*)&asd,0,0,UART_CMD_SIZE,16);
	
	rc = read(fd, tmp, 1024); cout << rc << endl; debug::DumpMemASCII(tmp,0,0,rc,16);	debug::DumpMem(tmp,0,0,rc,16);
	
	
/****************************************/
    asd.header[1] = 'S';     asd.command = 0 | (0x0<<1) | 4<<9;	asd.footer[0] = imp++;
	memcpy (&asd.data, "9101", 4);
	
	asd.footer[1] = do_cksum(&asd);
	
	
	rc = write(fd, (void*)&asd, UART_CMD_SIZE); debug::DumpMem((void*)&asd,0,0,UART_CMD_SIZE,16); debug::DumpMemASCII((void*)&asd,0,0,UART_CMD_SIZE,16);
	
	rc = read(fd, tmp, 1024); cout << rc << endl; debug::DumpMemASCII(tmp,0,0,rc,16);	debug::DumpMem(tmp,0,0,rc,16);
	
	
	
/****************************************/
    asd.header[1] = 'T';     asd.command = 0 | (0x0<<1) | 0<<9;	asd.footer[0] = imp++;    // reset + checksum check
	memcpy (&asd.data, "\0\0\0\0", 4);
	rc = write(fd, (void*)&asd, UART_CMD_SIZE); debug::DumpMem((void*)&asd,0,0,UART_CMD_SIZE,16); debug::DumpMemASCII((void*)&asd,0,0,UART_CMD_SIZE,16);
	rc = read(fd, tmp, 1024); cout << rc << endl; debug::DumpMemASCII(tmp,0,0,rc,16);	debug::DumpMem(tmp,0,0,rc,16);
	asd.footer[1] = do_cksum(&asd);
	rc = write(fd, (void*)&asd, UART_CMD_SIZE); debug::DumpMem((void*)&asd,0,0,UART_CMD_SIZE,16); debug::DumpMemASCII((void*)&asd,0,0,UART_CMD_SIZE,16);
	rc = read(fd, tmp, 1024); cout << rc << endl; debug::DumpMemASCII(tmp,0,0,rc,16);	debug::DumpMem(tmp,0,0,rc,16);
	
	
	
	
	//reverse(aaa, sizeof(float));
	//memcpy (aaa, tmp+4, 56);
		//debug::DumpMem(tmp,0,0,rc,16);

    return 0;
}
