#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t child_pid[3];
	printf("Sou o processo pai. Meu ID eh %d.\n",(int)getpid());
	child_pid[0]= fork();
	if(child_pid[0] == 0)
	{
		printf("Sou o primeiro processo-filho. Meu ID eh %d. Vou encerrar\n",(int)getpid());
		return 0;
	}
	else
	{
		wait(NULL);
		printf("Sou um processo-pai e vou criar mais um filho.\n");
		child_pid[1] = fork();
		if(child_pid[1] == 0)
		{
			printf("Sou o segundo processo-filho. Meu ID eh %d. Vou encerrar\n",(int)getpid());
			return 0;
		}
		else
		{
			wait(NULL);
			printf("Sou um processo-pai e vou criar mais um filho.\n");
			child_pid[2] = fork();
			if(child_pid[2]==0)
			{
				printf("Sou o terceiro processo-filho, o cacula. Meu ID eh %d. Vou encerrar\n",(int)getpid());
			}
			else
			{
				wait(NULL);
				printf("Sou um processo-pai. Agora que criei tres filhos, posso encerrar.\n");
				return 0;
			}
		}

	}

	return 0;
}

