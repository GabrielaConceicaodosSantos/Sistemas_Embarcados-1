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

4. Crie um programa em C que cria um processo-filho e um pipe de comunicação. O processo-filho deverá pedir o nome do usuário, envia-lo para o pai via pipe, e o pai deverá escrever o nome do usuário no terminal.

5. Utilize o sinal de alarme para chamar a cada segundo o comando `ps` ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu código atualizará a lista de processos a cada segundo. Além disso, o código deverá tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execução do processo.
