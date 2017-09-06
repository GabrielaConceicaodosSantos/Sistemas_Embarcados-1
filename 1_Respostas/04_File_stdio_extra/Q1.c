#include<stdio.h>

int main()
{
	unsigned long int f[100];
	int i;
	f[0]=0;
	f[1]=1;
	for(i=2;i<100;i++)
	{
		f[i] = f[i-1]+f[i-2];
	}
	FILE *fp;
	fp = fopen("fibbonaci.bin","wb");
	if(!fp)
	{
		printf("Erro ao abrir arquivo. Fim do programa.\n");
	}
	fwrite(f,sizeof(unsigned long int),100,fp);
	fclose(fp);
	return 0;
}
