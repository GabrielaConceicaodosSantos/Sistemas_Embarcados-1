#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/poll.h>
#include<unistd.h>
#include<signal.h>

void ctrl_c(int sig)
{
	puts("\nApagando os arquivos de GPIO...\n");
	system("echo 4 > /sys/class/gpio/unexport");
	puts("\nArquivos apagados. Fim do programa.\n");
	exit(-1);
}

int main(void)
{
	int freq=1;
	system("echo 4 > /sys/class/gpio/export");
	puts("Verificando arquivos... \n");
	system("ls /sys/class/gpio/gpio4");
	puts("\nEstes sao os arquivos na pasta gpio4.\n");
	system("echo out > /sys/class/gpio/gpio4/direction");
	signal(SIGINT, ctrl_c);
	printf("\nGPIO criada. O led piscara na frequencia de %d Hz.\n",freq);
	puts("\nAtencao. Pressione CTRL+C para encerrar o programa!\n");
	while(1)
	{
		system("echo 1 > /sys/class/gpio/gpio4/value");
		usleep(1000000/(2*freq));
		system("echo 0 > /sys/class/gpio/gpio4/value");
		usleep(1000000/(2*freq));
	}
	return 0;
}
