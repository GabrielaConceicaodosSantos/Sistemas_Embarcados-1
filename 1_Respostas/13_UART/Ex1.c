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
	int amostras[10],k;
	double media=0;
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
	puts("Pressione CTRL+C para encerrar o programa.\n");
	while(1)
	{
		k = 0;
		for(k=0;k<100;k++)
		{
			amostras[k] = FF & ((unsigned char)serialGetchar(uart0_df));
			amostras[k] |=  ((unsigned char)serialGetchar(uart0_df) << 8);
			usleep(10000); //espere 10 ms até a proxima conversao
		}
		for(k=0;k<100,k++)
		{
			//soma as amostras
			media += amostras[k];
		}
		//divide pelo numero de amostras
		media = media/100;
		//obtencao do valor de tensao analogica medio lido
		media = (media*3)/1024;
		printf("Valor de tensao medio: %.3lf V\n",media);
	}
}


