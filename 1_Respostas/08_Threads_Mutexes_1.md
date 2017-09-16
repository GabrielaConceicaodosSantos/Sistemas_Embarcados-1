1. Quais são as vantagens e desvantagens em utilizar:

(a) fork?

- Os filhos criados rodam como processos específicos

- Cada filho executa sua própria tarefa

- Cada filho tem seu espaço de memória protegido

- A comunicação é feita por pipes, sinais, etc.

(b) threads?

- Uma só aplicação pode rodar várias threads

- Todas as threads compartilham o mesmo espaço de memória

- A comunicação é mais simples por usar memória compartilhada

- Risco de corrupção de dados

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)



```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```

3. Apresente as características e utilidades das seguintes funções:

pthread_cancel - send a cancellation request to a thread

#include <pthread.h>

       int pthread_cancel(pthread_t thread);

       Compile and link with -pthread.

The  pthread_cancel()  function  sends  a  cancellation  request to the thread thread.  Whether and when the target thread reacts to  the  cancellation  request depends on two attributes that are under the control of that thread: its cancelability state and type.

(a) `pthread_setcancelstate()`

A  thread's  cancelability  state,  determined  by   pthread_setcancel‐state(3), can be enabled (the default for new threads) or disabled.  If a thread has disabled cancellation, then a cancellation request remains queued  until the thread enables cancellation.  If a thread has enabled cancellation, then its cancelability type determines when  cancellation occurs.

(b) `pthread_setcanceltype()`

(DICA: elas são relacionadas à função pthread_cancel().)

A  thread's  cancellation type, determined by pthread_setcanceltype(3), may be either *asynchronous* or *deferred* (the default for  new  threads). Asynchronous cancelability means that the thread can be canceled at any time (usually immediately, but the system  does  not  guarantee  this). Deferred  cancelability  means  that cancellation will be delayed until the thread next calls a function that is a cancellation point. A  list of functions that are or may be cancellation points is provided in pthreads(7).


