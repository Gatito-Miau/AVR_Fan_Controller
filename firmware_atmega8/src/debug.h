#ifdef _DEBUG
#include <stdint.h>
void 	gotox			(uint16_t x, char* str);
void 	_UART_DumpMem 	(void* Addr, int8_t n, int8_t jump);
#endif

#ifdef _DEBUG
#define UART_DumpMem(Addr,n,jump) _UART_DumpMem(Addr,n,jump)
#else
#define UART_DumpMem(Addr,n,jump)
#endif
