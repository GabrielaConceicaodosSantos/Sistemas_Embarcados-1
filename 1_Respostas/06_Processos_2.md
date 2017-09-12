1. Crie um código em C para gerar três processos-filho usando o `fork()`.

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
	pid_t child_pid[3];
	printf("Sou o processo pai. Meu ID eh %d.\n",(int)getpid());
	child_pid[0]= fork();
	if(child_pid[0] == 0)
	{
		printf("Sou o primeiro processo-filho. Meu ID eh %d. Vou encerrar\n",(int)getpid());
		return 0;
	}
	else
	{
		wait(NULL);
		printf("Sou um processo-pai e vou criar mais um filho.\n");
		child_pid[1] = fork();
		if(child_pid[1] == 0)
		{
			printf("Sou o segundo processo-filho. Meu ID eh %d. Vou encerrar\n",(int)getpid());
			return 0;
		}
		else
		{
			wait(NULL);
			printf("Sou um processo-pai e vou criar mais um filho.\n");
			child_pid[2] = fork();
			if(child_pid[2]==0)
			{
				printf("Sou o terceiro processo-filho, o cacula. Meu ID eh %d. Vou encerrar\n",(int)getpid());
			}
			else
			{
				wait(NULL);
				printf("Sou um processo-pai. Agora que criei tres filhos, posso encerrar.\n");
				return 0;
			}
		}

	}

	return 0;
}
```

2. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um sequencialmente usando `system()`. Por exemplo, considerando que o código criado recebeu o nome de 'serial_system', e que ele foi executado na pasta '/Sistemas_Embarcados/Code/06_Processos', que contem diversos arquivos:

```bash
$ ./serial_system pwd echo ls echo cal
$ ~/Sistemas_Embarcados/Code/06_Processos
$
$ Ex1.c    Ex2b.c   Ex4.c   Ex6.c
$ Ex2a.c   Ex3.c    Ex5.c   serial_system
$
$     Março 2017
$ Do Se Te Qu Qu Se Sá
$           1  2  3  4
$  5  6  7  8  9 10 11
$ 12 13 14 15 16 17 18
$ 19 20 21 22 23 24 25
$ 26 27 28 29 30 31
```
```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, const char *argv[])
{
	int i=1;
	for(i=1;i<=argc;i++)
	{
		system(argv[i]);
	}
	return 0;
}
```

3. Crie um código em C que recebe o nome de diversos comandos pelos argumentos de entrada (`argc` e `*argv[]`), e executa cada um usando `fork()` e `exec()`.

```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, const char *argv[])
{
	int i;
	char *arg_list[2] = {NULL,NULL};
	for(i=1;i<argc;i++)
	{
		//printf("%s\n",argv[i]);
		if(fork()==0)
		{
			arg_list[0] = (char *)argv[i];
			execvp(arg_list[0],arg_list);
			exit(0);
		}
		else
		{
		wait(NULL);
		}
	}	
	return 0;
}
```

4. Crie um código em C que gera três processos-filho usando o `fork()`, e que cada processo-filho chama a seguinte função uma vez:

```
int v_global = 0; // Variavel global para este exemplo
void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
}
```

(Repare que a função `Incrementa_Variavel_Global()` recebe como entrada o ID do processo que a chamou.) Responda: a variável global `v_global` foi compartilhada por todos os processos-filho, ou cada processo enxergou um valor diferente para esta variável?

Neste caso, cada processo enxergou o valor da variavel global do pai, e portanto, cada um tem sua propria variavel global sem sofrer alteração por conta de algum outro processo-filho que tenha sido criado anteriormente.

- Código do programa:

```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int v_global = 0; //Variavel global
void incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d.\n",(int)id_atual);
	printf("v_global = %d\n",v_global);
}

int main(int argc, const char *argv[])
{
	pid_t child_pid[3];
	int i;
	for(i=0;i<3;i++)
	{
		child_pid[i] = fork();
		if(child_pid[i]==0)
		{
			incrementa_Variavel_Global(getpid());
			return 0;
		}
		else
		{
			wait(NULL);
		}
	}
	return 0;
}
```

5. Repita a questão anterior, mas desta vez faça com que o processo-pai também chame a função `Incrementa_Variavel_Global()`. Responda: a variável global `v_global` foi compartilhada por todos os processos-filho e o processo-pai, ou cada processo enxergou um valor diferente para esta variável?


Neste caso, o valor alterado da variável global só foi propagado nos filhos que vieram depois desta ser incrementada. Se a variável global é incrementada antes do fork(), o valor que estava antes deste fork() será propagado para o processo-filho, mas após isto, qualquer alteração na variável global do pai não causará mais efeito na variável global do filho.

- Código da função:

```
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int v_global = 0; //Variavel global
void incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", (int)id_atual);
	printf("v_global = %d\n",v_global);
}
int main(int argc, const char *argv[])
{
	pid_t child_pid[3];
	int i;
	for(i=0;i<3;i++)
	{
		child_pid[i] = fork();
		if(child_pid[i]==0)
		{
			incrementa_Variavel_Global(getpid());
			return 0;
		}
		else
		{
			wait(NULL);
			incrementa_Variavel_Global(getpid());
		}
	}
	return 0;
}
```


