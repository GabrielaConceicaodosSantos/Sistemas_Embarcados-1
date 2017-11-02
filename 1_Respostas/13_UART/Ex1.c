#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <errno.h>
#include <string.h>

// Este codigo requer a biblioteca wiringPi. Compile-o usando
// gcc Ex1.c -lwiringPi -o Ex1

// Arquivo de acesso a porta serial
// #define TTY "/dev/ttyAMA0"
// Arquivo de acesso a porta serial para o Rpi 3
# define TTY "/DEV/ttyS0"

int uart0_fd;
void ctrl_c(int sig)
{
	puts("Fechando " TTY "...");
	serialClose(uart0_fd);
	exit(-1);
}
int main(void)
{
	unsigned char msp430_input=1;
	int amostras[10];
	int k;
	signal(SIGINT,ctrl_c);
	uart0_fd = serialOpen(TTY,9600);
	if(uart0_fd == -1)
	{
		puts("Erro em wiringPi().");
		return -1;
	}
	puts(TTY "aberto.");
	puts("UART configurada: ");
	system("stty -F" TTY);
	puts("");
	serialFlush(uart0_fd);
	while(1)
	{
		k = 0;
		if(k<10)
		{
			msp430_input = (unsigned char)serialGetchar(uart0_fd);
			amostras[k] = msp430_input;
			usleep(10000);//Esperar 10 ms
			amostras[k] |= (msp430_input << 8);
		}

	}
}


