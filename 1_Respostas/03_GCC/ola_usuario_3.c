#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
	{
		int i;
		printf("Ola ");
		for (i=1;i<argc;i++)
		{
			printf("%s ", argv[i]);
		}
		printf("\n");
		printf("Numero de entradas = %d\n",argc);
		return 0;
	}
