#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	/*
	 *argv[0] -> busca_e_conta
	 *argv[1] -> string que deseja-se verificar
	 *argv[2] -> arquivo que sera verificado
	 */
	FILE *fp;
	fp = fopen(argv[2],"r");
	if(!fp)
	{
		printf("Erro ao abrir o arquivo. Fim do programa.");
		exit(1);
	}
	int ocorrencias=0;
	char s[20]={0};
	while((fscanf(fp,"%s",s))!= EOF)
	{
		printf("%s\n",s);
		if(strcmp(s,argv[1]) == 0)
		{
			ocorrencias++;
		}
	}
	printf("'%s' ocorre %d vezes no arquivo '%s'.\n",argv[1],ocorrencias,argv[2]);
	fclose(fp);
	return 0;
}

