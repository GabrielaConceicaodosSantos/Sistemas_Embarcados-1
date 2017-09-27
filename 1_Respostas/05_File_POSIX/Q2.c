
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, const char * argv[])
{
	int fp;
	fp = open("ola_usuario_1.txt", O_RDWR | O_CREAT, S_IRWXU);
	if(fp == -1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
		exit(1);
	}
	char nome[30],idade[20],texto[50];
	printf("Digite o seu nome: ");
	gets(nome);
	printf("\nDigite a sua idade: ");
	gets(idade);
	strcpy(texto,"Nome: ");
	strcat(texto,nome);
	strcat(texto,"\n");
	strcat(texto,"Idade: ");
	strcat(texto,idade);
	strcat(texto,"\n");
	printf("%s\n",texto);
	write(fp,texto,strlen(texto)*sizeof(char));
	close(fp);
	return 0;
}
