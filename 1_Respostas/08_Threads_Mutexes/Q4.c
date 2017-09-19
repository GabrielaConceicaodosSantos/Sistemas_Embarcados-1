#include <stdio.h>
#include <math.h>
#include <stdlib.h> //rand() e srand() estao aqui
#include <pthread.h>
#include <unistd.h>
#include <time.h> //para a funcao time()

#define TAM_VETOR 50000 //cuidado, deve ser multiplo de 4

//Atençao! Leia-me!!
//Lembre-se de compilar este código usando
// gcc Q4.c -o Q4 -lpthread -lm
// O "-lm" vem do linker que deve ser feito à biblio math.h

/*
	Variancia populacional (temos todos os dados da série de números)
	
	variancia = sum(x_i - media)²/n

	x_i ---> dado da serie
	n   ---> n de termos da serie
	x_i - media ---> dispersao de cada um dos dados da serie
*/


struct ver_vetor
{
	long int *vec;
	double m; //refere-se a media
	long double v; //refere-se a variancia
};

void *media_vetor(void *media)
{
	struct ver_vetor *p = (struct ver_vetor *) media;
	int i;
	p->m = 0;

	for(i=0;i < (TAM_VETOR)/4;i++)	
	{
		p->m += p->vec[i];
	}
	p->m = (p->m)/(TAM_VETOR/4);
	//printf("Rodei %d posicoes e minha media e' %.2lf.\n",i,p->m);
	return NULL;
}

void *variancia_vetor(void *variancia)
{
	struct ver_vetor *p = (struct ver_vetor *) variancia;
	int i;
	p->v = 0;
	for(i=0;i < (TAM_VETOR)/4; i++)
	{
		//printf("x_i(=%ld) - media = %.2lf\n",p->vec[i],p->vec[i] - p->m);
		p->v += pow(p->vec[i] - p->m,2);
		//printf("Iteracao = %d| Variancia atual =  %Lf \n",i,p->v);
	}
}

int main()
{
	long int v[TAM_VETOR];
	srand(time(NULL)); //jogando uma semente para srand com base nos segundos passados desde 1970
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
	long double variancia;
	media = 0;
	
	for(i=0;i<TAM_VETOR;i++)
	{
		//printf("v[i] = %ld\n",v[i]);
		media += v[i];
	}

	media = media/TAM_VETOR;
	printf("O valor medio usando a busca completa e' %.2lf.\n",media);
	
	variancia = 0;

	for(i=0;i<TAM_VETOR;i++)
	{
		//printf("x_i(= %ld) - media = %.2lf \n",v[i],v[i] - media );
		variancia += pow(v[i]-media,2);
		//printf("Iteracao = %d| Variancia atual =  %Lf \n",i,variancia);
	}
	variancia = variancia/TAM_VETOR;
	
	printf("A variancia usando a busca completa e' %.2Lf.\n",variancia);

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
	
	//Vamos chamar as threads de novo, mas agora pra calcular a variancia

	for(i=0;i<4;i++)
	{
		verificar_vetor[i].vec = &v[(TAM_VETOR/4)*i];
		verificar_vetor[i].m = media;
		//atualizando o valor da media encontrado
		pthread_create(&thread_id[i],NULL,&variancia_vetor,&verificar_vetor[i]);
	}

	for(i=0;i<4;i++)
		pthread_join(thread_id[i],NULL);

	variancia = 0;

	for(i=0;i<4;i++)
	{
		variancia += verificar_vetor[i].v;
	}
	//printf("Variancia antes de dividir pelo tamanho do vetor: %.2Lf \n",variancia);
	variancia = variancia/TAM_VETOR;

	printf("A variancia usando a busca paralela e' %.2Lf.\n",variancia);

	return 0;
}