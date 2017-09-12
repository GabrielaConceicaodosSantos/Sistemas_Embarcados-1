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
