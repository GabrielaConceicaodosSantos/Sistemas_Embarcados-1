1. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Faça com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o número 10, ele aguarda 1 segundo e termina a execução. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execução.

```C
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int pid;
	int fd[2];
	//Cria o pipe
	pipe(fd);
	//Cria o processo
	pid = fork();
	//Codigo do filho
	if(pid == 0)
	{
		int i,j;
		for(i=1;i<11;i++)
		{
			read(fd[0],&j,sizeof(int));
			printf("Filho recebeu %d do pai.\n",j);
		}
	}
	//Codigo do pai
	else
	{
		int i;
		for(i=1;i<11;i++)
		{
			printf("Pai vai escrever %d no pipe.\n",i);
			write(fd[1],&i,sizeof(int));
			sleep(1);
		}
		wait(NULL);
	}
	return 0;
}
```

2. Crie um programa em C que cria um processo-filho e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO: Pai, qual é a verdadeira essência da sabedoria?
PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
FILHO: Mas até uma criança de três anos sabe disso!
PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
```
Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.

```C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>

void Escreve_Pipe(int fd,char mensagem[])
{
	if(write(fd,mensagem,strlen(mensagem)+1)<0)
	{
		printf("Erro ao escrever no pipe\n");
	}
	usleep(1000);
}

void Ler_Pipe(int fd)
{
	int i;
	char mensagem[200];
	i = -1;
	do{
		i++;
		read(fd,mensagem+i,1);
	}while(mensagem[i]!='\0');
	printf("%s",mensagem);
	usleep(1000);
}

int main()
{
	int pid;
	int fd[2];
	//Cria o pipe
	pipe(fd);
	//Cria o processo
	pid = fork();
	//Codigo do filho
	if(pid==0)
	{
		Escreve_Pipe(fd[1],"FILHO: Pai, qual é a verdadeira essência da sabedoria?\n");
		Ler_Pipe(fd[0]);
		Escreve_Pipe(fd[1],"FILHO: Mas até uma criança de três anos sabe disso!\n");
		Ler_Pipe(fd[0]);
	}
	//Codigo do Pai
	else
	{
		Ler_Pipe(fd[0]);
		Escreve_Pipe(fd[1],"PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.\n");
		Ler_Pipe(fd[0]);
		Escreve_Pipe(fd[1],"PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...\n");
		wait(NULL);
	}
	return 0;
}
```


3. Crie um programa em C que cria dois processos-filhos e um pipe de comunicação. Utilize o pipe para executar a seguinte conversa entre processos:

```
FILHO1: Quando o vento passa, é a bandeira que se move.
FILHO2: Não, é o vento que se move.
PAI: Os dois se enganam. É a mente dos senhores que se move.
```

Neste exercício, quem recebe a mensagem via pipe é quem as escreve no terminal.


```C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>

void Escreve_Pipe(int fd,char mensagem[])
{
	if(write(fd,mensagem,strlen(mensagem)+1)<0)
	{
		printf("Erro ao escrever no pipe.\n");
	}
	usleep(1000);
}
void Ler_Pipe(int fd)
{
	int i;
	char mensagem[200];
	i = -1;
	do{
		i++;
		read(fd,mensagem+i,1);
	}while(mensagem[i]!='\0');
	printf("%s",mensagem);
	usleep(1000);
}
int main()
{
	int pid[2];
	int fd[2];
	//Cria o Pipe
	pipe(fd);
	//Cria o processo
	pid[0] = fork();
	if(pid[0]==0)
	{
		//Codigo do primeiro filho
		Escreve_Pipe(fd[1],"FILHO1: Quando o vento passa, é a bandeira que se move.\n");
	}
	else
	{
		//Codigo do pai, após o primeiro
		//filho ser criado
		pid[1] = fork();
		if(pid[1]==0)
		{
			//Codigo do segundo filho
			Ler_Pipe(fd[0]);
			Escreve_Pipe(fd[1],"FILHO2: Não, é o vento que se move.\n");
		}
		else
		{

			//Codigo do pai, após o segundo
			//filho ser criado
			//Espera os filhos se comunicarem
			usleep(10000);
			Ler_Pipe(fd[0]);
			puts("PAI: Os dois se enganam. É a mente dos senhores que se move.");

		}
	}
	return 0;
}
```


4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.

```C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>

int fd_geral[2];

void Escreve_Pipe(int fd,char mensagem[])
{
	if(write(fd,mensagem,strlen(mensagem)+1)<0)
	{
		printf("Erro ao escrever no pipe.\n");
	}
	//usleep(1000);
}

void Ler_Pipe(int fd)
{
	int i;
	char mensagem[200];
	i = -1;
	do{
		i++;
		read(fd,mensagem+i,1);
	}while(mensagem[i]!='\0');
	printf("Recebi pelo pipe que seu nome e' %s.\n",mensagem);
	//usleep(1000);
}

void tratamento_SIGUSR1()
{
	Ler_Pipe(fd_geral[0]);
	exit(1);
}

int main()
{
	int pid;
	int fd[2];
	int father_pid;
	char nome[50];
	signal(SIGUSR1, tratamento_SIGUSR1);
	father_pid  = getpid();
	// Cria o Pipe
	pipe(fd);
	fd_geral[0] = fd[0];
	fd_geral[1] = fd[1];
	// Cria o processo
	pid = fork();
	if(pid==0)
	{

		//Codigo do filho
		printf("Insira seu nome: ");
		gets(nome);
		printf("Ok, seu nome e' %s. Agora o processo pai vai escrever seu nome.\n",nome);
		Escreve_Pipe(fd[1],nome);
		//Manda um SIGUSR1 pro pai.
		kill(father_pid,SIGUSR1);
	}
	else
	{
		//Codigo do pai
		//Pai vai aguardar o filho mandar um sinal SIGUSR1, quando este saberá que o filho terminou
		//de escrever no pipe o que o usuário digitou
		while(1);
	}
	return 0;
}
```
5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.
