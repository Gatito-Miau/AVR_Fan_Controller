#ifndef _UART_H
#define _UART_H

#include <stdint.h>

#define USART_BAUDRATE 19200
#define BAUD_PRESCALE (uint8_t)(((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define UART_BUFFER_SIZE 11

struct  UART_CMD;

/* ******************* */
/*        USART        */
/* ******************* */
void 	UART_initmsg	(void);
void	UART_init		(void);

void	UART_put		(uint8_t i);
void	UART_print		(char *s);
uint8_t	UART_get		(void);

uint8_t UART_check_cksum(struct UART_CMD* __p);
int8_t 	UART_command	(struct  UART_CMD* buffer);

#define MASK_ACTION 	0b0000000000000001
#define MASK_ADDRESS 	0b0000000111111110
#define MASK_NBYTES 	0b1111111000000000

#define UART_CMD_SIZE	11

#define UART_CMD_CKSUM	1
#define UART_CMD_MSGID	0

struct  UART_CMD	// 11 bytes
{
	uint8_t 	header	[2];	// >C (CMD)- >S (STRING) - >R (RESUME) - >H (HALT) - >T (RESET) - >G (GET STATUS) - >M (MANUAL) - >V (GET VERSION) - >L (LOAD SETTINGS) - >M (MANUAL SET)
	uint16_t	command;
	uint8_t		data	[4];
	uint8_t		footer	[3];	// msg_id + "cheksum" + <
};

/* *********************************** */
/* *   command(>C) - Description     * */
/* *********************************** */
/*    bit  |  Description              */
/* ----------------------------------- */
/*     0   |  Action: 0 set, 1 get     */
/*    1-8  |  Address (0x0 - 0xFF)     */
/*    9-15 |  N of data bytes (0 - 7F) */
/* *********************************** */

/* *********************************** */
/* *   command(>S) - Description     * */
/* *********************************** */
/* =(>CMD) |  Address + 0x100          */
/* *********************************** */
#endif
