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
		//	sleep(1);
		}
		wait(NULL);
	}
	return 0;
}
