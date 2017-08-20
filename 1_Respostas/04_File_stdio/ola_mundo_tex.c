#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("ola_mundo.txt","w");
	if (!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fputs("Ola mundo!!!\n", fp);
	fclose(fp);
	return 0;
}
