#include <stdio.h>
#include <stdlib.h>
#include "bib_arqs.h"

int main (int argc, char *argv[])
{
	char *p = le_arq_texto(argv[1]);
	puts(p);
	free(p);
	return 0;
}
