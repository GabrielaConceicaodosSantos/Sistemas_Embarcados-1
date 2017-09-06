#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned long int f[100]={0};
	FILE *fp;
	if((fp = fopen("fibbonaci.bin","rb")) == NULL)
	{
		printf("Erro na abertura do arquivo. Fim do programa.");
		exit(1);
	}
	if(fread(f,sizeof(unsigned long int),100,fp) == 1)
	{
		printf("Erro na leitura do arquivo.");
	}
	int i;
	for(i=0;i<100;i++)
	{
		printf("O termo %d da sequencia de fibbonaci e' %lu.\n",i,f[i]);
	}
}

