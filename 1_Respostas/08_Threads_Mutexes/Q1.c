#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
struct numero
{
	int num;
};

void *print_num(void *parameters)
{
	struct numero *p = (struct numero*)parameters;
	int i;
	for(i=0;i<10;i++)
	{
		printf("Recebi %d\n",p->num);
		sleep(1);
	}
	return NULL;
}
 int main()
 {
 	pthread_t thread_id1;
 	struct numero thread_args_1;
 	int i;
 	pthread_create(&thread_id1,NULL,&print_num,&thread_args_1);
 	for(i=0;i<10;i++)
 	{
 		thread_args_1.num = i+1;
 		sleep(1);
 	}
 	pthread_join(thread_id1,NULL);
 	return 0;
 }