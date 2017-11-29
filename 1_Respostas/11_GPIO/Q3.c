#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/polli.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>

#define LED 4
#define BTN 5

//LED deve ser ligado no GPIO4
//BOTAO deve ser ligado no GPIO5, lembrar de usar resistor de pull-up!

int freq=1;
int encerrar=0;

void ctrl_c(int sig)
{
	encerrar=1;
	free_GPIO(LED);
	free_GPIO(BTN);
}

void setup_GPIO(int GPIOnum,char mode)
{
	char str[80];
	if(mode == "out")
	{
		sprintf(str,"Configurando GPIO%d como saida digital...\n",GPIOnum);
		puts(str);
		sprintf(str,"echo %d > /sys/class/gpio/export",GPIOnum);
		system(str);
		sprintf(str,"echo out > /sys/class/gpio/gpio%d/direction",GPIOnum);
		system(str);
		puts("Configurado.\n");
	}
	else if(mode == "in")
	{
		sprintf(str,"Configurando GPIO%d como entrada digital...",GPIOnum);
		puts(str);
		sprintf(str,"echo %d > /sys/class/gpio/export",GPIOnum);
		system(str);
		sprintf(str,"echo in > /sys/class/gpio/gpio%d/direction",GPIOnum);
		system(str);
		puts("Configurado.\n");
	}
}

void free_GPIO(int GPIO_num)
{
	char str[80];
	sprintf(str,"echo %d > /sys/class/gpio/unexport",GPIO_num);
	system(str);
	printf("GPIO %d liberada.\n",GPIO_num);
}

void altera_frequencia()
{
	printf("Captei vossa mensagem. A frequencia sera alterada.\n");
	if(freq<64)
	{
		freq *= 2;
		printf("A frequencia atual e %d Hz.\n",freq);
	}
	else
	{
		freq = 1;
		printf("A frequencia atual e %d Hz.\n",freq);
	}
}

int main(void)
{
	struct pollfd pfd;
	int pid;
	char buffer;
	char str[80];
	setup_GPIO(LED,"out");
	setup_GPIO(BTN,"in");
	
	// Criando um filho
	pid = fork();
	// Codigo do filho
	
	signal(SIGUSR1, altera_frequencia);
	
	if(pid==0)
	{
		while(1)
		{
			//O filho faz o led piscar
			system("echo 1 > /sys/class/gpio/gpio4/value");
			usleep(1000000/(2*freq));
			system("echo 0 > /sys/class/gpio/gpio4/value");
			usleep(1000000/(2*freq));
		}
	}
	// Codigo do pai
	else
	{
		signal(SIGINT, ctrl_c);
		pfd.fd = open("/sys/class/gpio/gpio5/value",O_RDONLY);
		pfd.events = POLLPRI | POLLERR;
		pdf.revents = 0;
		while(encerrar==0)
		{
			//o pai le o botao e verifica
			//se a frequencia deve aumentar
			lseek(pfd.fd, 0,SEEK_SET);
			read(pfd.fd, &buffer,1);
			puts("Aguardando pressionar o botao...");
			poll(&pfd,1,-1);
			puts("Borda de descida!")
			//Pai envia um sinal do tipo SIGUSR1
			//para avisar o filho que a
			//frequencia deve ser alterada
			kill(pid,SIGUSR1);
		}
		//Processo filho sera encerrado
		kill(pid,SIGKILL);
		wait(NULL);
		free_GPIO(LED);
		free_GPIO(BTN);
		return 0;
	}
}
