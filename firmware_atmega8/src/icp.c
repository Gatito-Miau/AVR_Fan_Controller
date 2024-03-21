#include <avr/io.h>
#include <avr/interrupt.h>

#include "pwm.h"
#include "icp.h"

volatile uint16_t t1, t2, t2_old;
volatile uint8_t busy;

/* ******************* */
/*         ICP         */
/* ******************* */
void ICP_init()
{
    DDRB |= _BV(PB1);
    PORTB &= ~_BV(PB1);

    DDRB   &= ~_BV(PB0);	//PB0 as input
    PORTB  &= ~_BV(PB0);	//PB0 in HI-Z state

    TCCR1A 	= 0;			//Normal mode
    TCCR1B 	= _BV(CS10);	// 1 divider and noise canceler _BV(ICNC1)|

    TCCR1B &= ~_BV(ICES1);		// start in falling edge
	busy = 0; // por las putas
	
    TIMSK  |= _BV(TICIE1);		//ICP interrupt _BV(TOIE1)|

}

ISR(SIG_INPUT_CAPTURE1)
{
//    if( !busy )					// ¨¨|________
	if( !(PINB & _BV(PB0)) )
    {
    	t2_old = t2;
        t2 = ICR1;
//		TCNT1 = 0;
        TCCR1B |= _BV(ICES1);
//        busy = 1;
	}
    else						// __|¨¨¨¨¨¨¨¨
    {
    	t1 = ICR1;

        TCCR1B &= ~_BV(ICES1);
//        busy = 0;
	}
//	if( !(PINB & _BV(PB0)) )
//    {
////        TCNT1=0;
//        t2 = ICR1;
// 
//        TCCR1B |= _BV(ICES1);
//        }
//    else
//    {
//        t1 = ICR1;
// 
//        TCCR1B &= ~_BV(ICES1);
//        } 

}
ISR(SIG_OVERFLOW1)
{
//    if (PINB & _BV(PB0))
//    {
//        PWM_setdc_lineal(255);
//    }
//    else
//    {
//	    PWM_setdc_lineal(0);
//    }
}
