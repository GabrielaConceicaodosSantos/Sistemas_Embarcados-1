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
