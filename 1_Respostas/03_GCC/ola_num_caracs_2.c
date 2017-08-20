#include<stdio.h>
#include<stdlib.h>
#include"num_caracs.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int total_caracteres = 0;
	for(i=0;i<argc;i++)
	{
		total_caracteres += Num_Caracs(argv[i]);
	}
	printf("Total de caracteres de entrada: %d\n",total_caracteres);
	return 0;
}



