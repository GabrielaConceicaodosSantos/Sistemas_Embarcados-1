#include<stdio.h>
#include<stdlib.h>

int main()
{
	char nome[50];
	int idade;
	FILE *fp;
	printf("Digite o seu nome: ");
	gets(nome);
	printf("Digite a sua idade: ");
	scanf("%d",&idade);
	fp = fopen("Eu.txt","w");
	if(!fp)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	fprintf(fp,"Nome: %s\nIdade: %d\n",nome,idade);
	fclose(fp);
	return(0);
}
