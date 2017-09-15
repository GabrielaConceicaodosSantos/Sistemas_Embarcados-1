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

int main()
{
	int pid;
	int fd[2];
	char nome[50];
	// Cria o Pipe
	pipe(fd);
	//fd_geral[0] = fd[0];
	//fd_geral[1] = fd[1];
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
	}
	else
	{
		//Codigo do pai
		//Pai vai aguardar o filho mandar um sinal SIGUSR1, quando este saberá que o filho terminou
		//de escrever no pipe o que o usuário digitou
		Ler_Pipe(fd[0]);
		wait(NULL);
	}
	return 0;
}
