#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	int fp;
	fp = open("ola_mundo.txt", O_RDWR | O_CREAT, S_IRWXU);
	if(fp==-1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
		exit(1);
	}
	char ola[] = "Ola mundo cruel!";
	write(fp,ola,strlen(ola)*sizeof(char));
	close(fp);
	return 0;
}
