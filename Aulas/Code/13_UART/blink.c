#include<msp430g2553.h>

#define LED1 BIT0
#define LED2 BIT6

int main(void)
{
	volatile int i = 0;
	//Stop Watchdog Timer
	WDTCTL = WDTPW|WDTHOLD;
	
	//Set P1 Direction
	P1DIR |= LED1 + LED2;
	P1OUT &= (LED1 + LED2);
	for(;;)
	{
		//Toogle Leds
		P1OUT ^= (LED1 + LED2);
		for(i=0;i<10000;i++);
	}
}
