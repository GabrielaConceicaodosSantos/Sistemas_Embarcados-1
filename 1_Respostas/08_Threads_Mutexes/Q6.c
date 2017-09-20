#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h> //para a funcao time()

#define TAM_MATRIZ 60

struct verifica_matriz
{	
	long int *lin_mat_A[12]; //lin_mat - um vetor de ponteiros 
	//para 12 linhas da matriz
	long int *lin_mat_B[12];
	long int *lin_mat_result[12];
};

void printa_matriz(int a,int b,long int matriz[][TAM_MATRIZ])
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%ld ",matriz[i][j]);
		}
		printf("\n");
	}
}


void *soma_matriz(void *soma)
{
	struct verifica_matriz *p = (struct verifica_matriz *) soma;
	int i,j;
	for(i=0;i<12;i++)
	{
		
		for(j=0;j<60;j++)
		{
			p->lin_mat_result[i][j] = p->lin_mat_A[i][j] + p->lin_mat_B[i][j];
		}
	}
}

int main()
{
	srand(time(NULL)); //jogando uma semente para srand com base nos segundos passados desde 1970
	
	long int matriz_A[TAM_MATRIZ][TAM_MATRIZ];
	long int matriz_B[TAM_MATRIZ][TAM_MATRIZ];
	long int matriz_resultante[TAM_MATRIZ][TAM_MATRIZ];
	int i,j,k,soma=0;

	for(i=0;i<TAM_MATRIZ;i++)
	{
		for(j=0;j<TAM_MATRIZ;j++)
		{
			matriz_A[i][j] = rand() % 100;
			matriz_B[i][j] = rand() % 100;
			matriz_resultante[i][j] = matriz_A[i][j] + matriz_B[i][j];
		}
	}
	printf("\n\nMATRIZ A \n\n");
	printa_matriz(TAM_MATRIZ,TAM_MATRIZ,matriz_A);
	printf("\n\nMATRIZ B \n\n");
	printa_matriz(TAM_MATRIZ,TAM_MATRIZ,matriz_B);
	printf("\n\nMATRIZ RESULTANTE \n\n");
	printa_matriz(TAM_MATRIZ,TAM_MATRIZ,matriz_resultante);


	pthread_t thread_id[5]; //5 threads
	struct verifica_matriz verificador[5];
	for(i=0;i<5;i++)
	{
		for(j=0;j<12;j++)
		{
			verificador[i].lin_mat_A[j] = &matriz_A[12*i + j];
			verificador[i].lin_mat_B[j] = &matriz_B[12*i + j];
			verificador[i].lin_mat_result[j] = &matriz_resultante[12*i + j];
		}

		pthread_create(&thread_id[i],NULL,&soma_matriz,&verificador[i]);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(thread_id[i],NULL);
	}

	printf("\n\nMATRIZ RESULTANTE DE FORMA PARALELA \n\n");

	for(i=0;i<5;i++)
	{
		//andando em cada struct
		for(j=0;j<12;j++)
		{
		//andando em cada ponteiro
			for(k=0;k<60;k++)
			{
				//andando em cada coluna do ponteiro
				printf("%ld ",verificador[i].lin_mat_result[j][k]);
				soma++;
			}
			printf("\n");
			//printf("Soma atual %d\n",soma);
			//printf("\n \n");
		}
	}
	
	return 0;	
}