1. Quantos pipes serão criados após as linhas de código a seguir? Por quê?

(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```

Primeiro, o processo pai cria 1 pipe, depois um processo-filho é criado, logo 1 pipe será criado.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```

Neste caso, o processo filho é criado, e depois o processo filho e o processo pai criam um pipe cada um, logo 2 pipes foram criados.

2. Apresente mais cinco sinais importantes do ambiente Unix, além do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais são suas características e utilidades?

- SIGKILL - Mata um processo. Não pode ser ignorada, tampouco interceptada (existe ainda o SIGTERM para uma morte mais "suave" para processos).

- SIGCLD - Morte um filho: enviado ao pai pela terminação de um processo filho.

- SIGPIPE - Escrita sobre um pipe não aberto em leitura.

- SIGSTOP - Para a execução. Não pode ser ignorado ou pego.

- SIGCONT - Continua a execução, se o processo estiver parado.


3. Considere o código a seguir:

```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```

Sabendo que a função `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, quão precisos são os alarmes criados neste código? De onde vem a imprecisão? Este é um método confiável para desenvolver aplicações em tempo real?

Não há como saber o quão preciso é a função `alarm()`, pois o processador roda diversos processos ao mesmo tempo e isto vai depender do tanto de tarefas que este estiver executando, quantos cores, qual a velocidade de processamento, etc. Para aplicações em tempo real, a resposta é: depende. Se o tempo em que a aplicação tem que tomar uma decisão for muito gritante, não é interessante utilizar este tipo de função, sendo melhor o uso de um microcontrolador. Mas se alguns milisegundos de erro não causarem tanto problema, não há problema o uso desta função.
