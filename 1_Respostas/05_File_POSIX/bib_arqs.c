#include "bib_arqs.h"

int Tam_arq_texto(char *nome_arquivo)
{
	int fp,caracteres=0;
	char c;
	fp = open(nome_arquivo,O_RDONLY);
	if(fp == -1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
		exit(1);
	}
	while(read(fp, &c, 1) != 0)
	{
		caracteres++;
	}
	close(fp);
	return caracteres*sizeof(char);
}

void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	int tamanho_arquivo = Tam_arq_text(nome_arquivo);
	conteudo = (char*)malloc(tamanho_arquivo);
	int fp;
	fp = open(nome_arquivo,O_RDONLY);
	if(fp == -1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
	}
	read(fp,conteudo,tamanho_arquivo);
	close(fp);
}

/*
 * Teste com a main
int main (int argc, char *argv[])
{	int tamanho;
	tamanho = Tam_arq_text(argv[1]);
	printf("O tamanho do arquivo em bytes e` %d\n",tamanho);
	return 0;
}  */ 

