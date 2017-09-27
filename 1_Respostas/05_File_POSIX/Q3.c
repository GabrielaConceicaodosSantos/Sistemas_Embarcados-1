#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[])
{
		int fp;
		fp = open("ola_usuario_1.txt", O_RDWR | O_CREAT, S_IRWXU);
		if(fp == -1)
		{
			printf("Erro na abertura do arquivo. Fim do programa.\n");
			exit(1);
		}		
		char texto[50];
		strcpy(texto,"Nome: ");
		strcat(texto,argv[1]);
		strcat(texto,"\n");
		strcat(texto,"Idade: ");
		strcat(texto,argv[2]);
		strcat(texto,"\n");
		///*printf("*%s\n",texto);
		write(fp,texto,strlen(texto)*sizeof(char));
		close(fp);
		return 0;
}
