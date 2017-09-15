#include "bib_arqs.h"
int Tam_arq_text(char *nome_arquivo)
{
	FILE *fp;
	int caracteres=0;
	fp = fopen(nome_arquivo,"r");
	if(!fp)
	{
		printf("Erro ao abrir arquivo. Fim do programa.");
		exit(1);
	}
	while(getc(fp)!= EOF)
		caracteres++;
	fclose(fp);
	//printf("N de caracteres: %d\n",caracteres);
	return caracteres;
}
char *le_arq_texto(char *nome_arquivo)
{
	/*Recebe o nome do arquivo e um vetor em que será retornado o conteúdo do arquivo.*/
	int tamanho_arquivo = Tam_arq_text(nome_arquivo), fread_size;
	char *conteudo = (char*)malloc((tamanho_arquivo+1)*sizeof(char));
	FILE *fp;
	fp = fopen(nome_arquivo,"r");
	if(!fp)
	{
		printf("Erro ao abrir o arquivo. Fim do programa.");
		exit(1);
	}
	fread_size = (int) fread((void*) conteudo,sizeof(char),tamanho_arquivo,fp);
	conteudo[tamanho_arquivo] = '\0';
	if(fread_size < tamanho_arquivo)
	{
		//puts(conteudo);
		printf("Erro ao ler %d bytes do arquivo (leu %d). Fim do programa.\n", tamanho_arquivo, fread_size);
		fclose(fp);
		free(conteudo);
		exit(1);
	}
	fclose(fp);
	return conteudo;
	//free(conteudo);
}
