#include <stdio.h>
#include <math.h>

int main()
{
	double numero;
	printf("Insira um numero: ");
	scanf("%lf",&numero);
	printf(" %lf² = %lf\n",numero,pow(numero,2));
	return 0;
}