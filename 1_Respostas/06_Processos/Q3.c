#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, const char *argv[])
{
	int i;
	char *arg_list[2] = {NULL,NULL};
	for(i=1;i<argc;i++)
	{
		//printf("%s\n",argv[i]);
		if(fork()==0)
		{
			arg_list[0] = (char *)argv[i];
			execvp(arg_list[0],arg_list);
			exit(0);
		}
		else
		{
		wait(NULL);
		}
	}	
	return 0;
}
