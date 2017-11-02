#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/poll.h>
#include<unistd.h>
#include<signal.h>

void ctrl_c(int sig)
{
	puts("Apagando os arquivos de GPIO...");
	system("echo 4 > /sys/class/gpio/unexport");
	puts("Arquivos apagados. Fim do programa.");
	exit(-1);
}

int main(void)
{
	system("echo 4 > /sys/class/gpio/export");
	puts("Verificando arquivos... \n");
	system("ls /sys/class/gpio/gpio4");
	puts("\nEstes sao os arquivos na pasta gpio4.");
	system("echo out > /sys/class/gpio/gpio4/direction");
	signal(SIGINT, ctrl_c);
	puts("\nGPIO criada. LED piscara na frequencia de 1 hz.\n");
	puts("Atencao. Pressione CTRL+C para encerrar o programa!\n");
	while(1)
	{
		system("echo 1 > /sys/class/gpio/gpio4/value");
		usleep(500000);
		system("echo 0 > /sys/class/gpio/gpio4/value");
		usleep(500000);
	}
	return 0;
}
