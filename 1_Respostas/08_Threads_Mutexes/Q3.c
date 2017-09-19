#include <stdio.h>
#include <stdlib.h> //rand() e srand() estao aqui
#include <pthread.h>
#include <unistd.h>
#include <time.h> //para a funcao time()

#define TAM_VETOR 50000

struct ver_vetor
{
	long int *vec;
	double m;
};

void *media_vetor(void *media)
{
	struct ver_vetor *p = (struct ver_vetor *) media;
	p->m = 0;
	int i;
	for(i=0;i < (TAM_VETOR)/4;i++)
	{
		//printf("v[i] = %ld \n",p->vec[i]);
		p->m += p->vec[i];
	}
	p->m = (p->m)/(TAM_VETOR/4);

	//printf("Rodei %d posicoes e minha media e' %.2lf.\n",i,p->m);
	return NULL;
}

int main()
{
	long int v[TAM_VETOR];
	srand(time(NULL));
	int i;
	
	for(i=0;i<TAM_VETOR;i++)
	{
		v[i] = rand() % 1000;
		//v[i] = i+1;
		/*if(i<200)
		{
			printf("Valor = %ld\n",v[i]);
		}*/
	}
	
	double media;
	media = 0;

	for(i=0;i<TAM_VETOR;i++)
	{
		//printf("v[i] = %ld\n",v[i]);
		media += v[i];
	}
	media = media/TAM_VETOR;

	printf("O valor medio usando a busca completa e' %.2lf.\n",media);
	struct ver_vetor verificar_vetor[4];
	pthread_t thread_id[4];
	
	for(i=0;i<4;i++)
	{
		verificar_vetor[i].vec = &v[(TAM_VETOR/4)*i];
		pthread_create(&thread_id[i],NULL,&media_vetor,&verificar_vetor[i]);
	}

	for(i=0;i<4;i++)
		pthread_join(thread_id[i],NULL);

	media = 0;
	
	for(i=0;i<4;i++)
	{
		media += verificar_vetor[i].m;
	}
	
	media = media/4;
	printf("O valor medio usando a busca paralela e' %.2lf.\n",media);

	return 0;
}