#include "bib_arqs.h"
int Tam_arq_text(char *nome_arquivo)
{
	FILE *fp;
	fp = fopen(nome_arquivo,"r");
	if(!fp)
	{
		printf("Erro ao abrir arquivo. Fim do programa.");
		exit(1);
	}
	int caracteres=0;
	while(getc(fp)!= EOF)
		caracteres++;
	fclose(fp);
	return caracteres;
}
void le_arq_texto(char *nome_arquivo, char *conteudo)
{
	/*Recebe o nome do arquivo e um vetor em que será retornado o conteúdo do arquivo.*/
	int tamanho_arquivo = Tam_arq_text(nome_arquivo);
	FILE *fp;
	fp = fopen(nome_arquivo,"r");
	fgets(conteudo, tamanho_arquivo, fp);
	fclose(fp);
}
