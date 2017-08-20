#include<stdio.h>
#include<stdlib.h>

int main(int arc, char *argv[])
{
	FILE *fp;
	fp = fopen("Eu.txt","w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fprintf(fp,"Nome: %s\nIdade: %d\n",argv[1],atoi(argv[2]));
	fclose(fp);
	return(0);
}
