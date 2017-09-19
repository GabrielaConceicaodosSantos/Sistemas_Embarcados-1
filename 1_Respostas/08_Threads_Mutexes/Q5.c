#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h> //para a funcao time()

struct verifica_matriz
{	
	long int *lin_mat[12]; //lin_mat - um vetor de ponteiros para 12 linhas da matriz
	long int somatoria;
};

void *soma_matriz(void *soma)
{
	struct verifica_matriz *p = (struct verifica_matriz *) soma;
	int i,j;

	p->somatoria = 0;
	for(i=0;i<12;i++)
	{
		
		for(j=0;j<60;j++)
		{
			p->somatoria += p->lin_mat[i][j];
		}
	}
}

int main()
{
	srand(time(NULL)); //jogando uma semente para srand com base nos segundos passados desde 1970
	
	long int matriz[60][60],soma;
	int i,j;

	soma = 0;
	for(i=0;i<60;i++)
	{
		for(j=0;j<60;j++)
		{
			matriz[i][j] = rand() % 100;
			soma += matriz[i][j];
		}
	}
	printf("A soma de valores na matriz de forma sequencial e' %ld.\n",soma);

	pthread_t thread_id[5]; //5 threads
	struct verifica_matriz verificador[5];
	for(i=0;i<5;i++)
	{
		for(j=0;j<12;j++)
		{
			verificador[i].lin_mat[j] = &matriz[12*i + j];
		}

		pthread_create(&thread_id[i],NULL,&soma_matriz,&verificador[i]);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(thread_id[i],NULL);
	}

	soma = 0;
	for(i=0;i<5;i++)
	{
		soma += verificador[i].somatoria;
	}

	printf("A soma de valores na matriz de forma paralela e' %ld.\n",soma);
	return 0;	
}