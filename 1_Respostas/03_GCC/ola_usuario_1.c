#include<stdio.h>
int main()
	{
		printf("Digite o seu nome: ");
		char nome[20];
		gets(nome);
		printf("Ola %s\n",nome);
	}
