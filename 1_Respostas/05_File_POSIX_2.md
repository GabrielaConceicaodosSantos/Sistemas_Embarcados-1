Para todas as questões, utilize as funções da norma POSIX (open(), close(), write(), read() e lseek()). Compile os códigos com o gcc e execute-os via terminal.

1. Crie um código em C para escrever "Ola mundo!" em um arquivo chamado 'ola_mundo.txt'.

```
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

```

2. Crie um código em C que pergunta ao usuário seu nome e sua idade, e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':

```bash
$ ./ola_usuario_1
$ Digite o seu nome: Eu
$ Digite a sua idade: 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, const char * argv[])
{
	int fp;
	fp = open("ola_usuario_1.txt", O_RDWR | O_CREAT, S_IRWXU);
	if(fp == -1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
		exit(1);
	}
	char nome[30],idade[20],texto[50];
	printf("Digite o seu nome: ");
	gets(nome);
	printf("\nDigite a sua idade: ");
	gets(idade);
	strcpy(texto,"Nome: ");
	strcat(texto,nome);
	strcat(texto,"\n");
	strcat(texto,"Idade: ");
	strcat(texto,idade);
	strcat(texto,"\n");
	printf("%s\n",texto);
	write(fp,texto,strlen(texto)*sizeof(char));
	close(fp);
	return 0;
}
```

3. Crie um código em C que recebe o nome do usuário e e sua idade como argumentos de entrada (usando as variáveis `argc` e `*argv[]`), e escreve este conteúdo em um arquivo com o seu nome e extensão '.txt'. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':

```bash
$ ./ola_usuario_2 Eu 30
$ cat Eu.txt
$ Nome: Eu
$ Idade: 30 anos
```
```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[])
{
		int fp;
		fp = open("ola_usuario_1.txt", O_RDWR | O_CREAT, S_IRWXU);
		if(fp == -1)
		{
			printf("Erro na abertura do arquivo. Fim do programa.\n");
			exit(1);
		}		
		char texto[50];
		strcpy(texto,"Nome: ");
		strcat(texto,argv[1]);
		strcat(texto,"\n");
		strcat(texto,"Idade: ");
		strcat(texto,argv[2]);
		strcat(texto,"\n");
		///*printf("*%s\n",texto);
		write(fp,texto,strlen(texto)*sizeof(char));
		close(fp);
		return 0;
}
```

4. Crie uma função que retorna o tamanho de um arquivo, usando o seguinte protótipo: `int tam_arq_texto(char *nome_arquivo);` Salve esta função em um arquivo separado chamado 'bib_arqs.c'. Salve o protótipo em um arquivo chamado 'bib_arqs.h'. Compile 'bib_arqs.c' para gerar o objeto 'bib_arqs.o'.

- Formato da funcao:

```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int Tam_arq_text(char *nome_arquivo)
{
	int fp,caracteres=0;
	char c;
	fp = open(nome_arquivo,O_RDONLY);
	if(fp == -1)
	{
		printf("Erro na abertura do arquivo. Fim do programa.\n");
		exit(1);
	}
	while(read(fp, &c, 1) != 0)
	{
		caracteres++;
	}
	close(fp);
	return caracteres*sizeof(char);
}
```
- Formato do header:

```
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int Tam_arq_text(char *nome_arquivo);

```
- Comando utilizado:

```
gcc -c bib_arqs.c
```

5. Crie uma função que lê o conteúdo de um arquivo-texto e o guarda em uma string, usando o seguinte protótipo: `void le_arq_texto(char *nome_arquivo, char *conteúdo);` Repare que o conteúdo do arquivo é armazenado no vetor `conteudo[]`. Ou seja, ele é passado por referência. Salve esta função no mesmo arquivo da questão 4, chamado 'bib_arqs.c'. Salve o protótipo no arquivo 'bib_arqs.h'. Compile 'bib_arqs.c' novamente para gerar o objeto 'bib_arqs.o'.



6. Crie um código em C que copia a funcionalidade básica do comando `cat`: escrever o conteúdo de um arquivo-texto no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'cat_falsificado':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./cat_falsificado ola.txt
$ Ola mundo cruel! Ola universo ingrato!
```

7. Crie um código em C que conta a ocorrência de uma palavra-chave em um arquivo-texto, e escreve o resultado no terminal. Reaproveite as funções já criadas nas questões anteriores. Por exemplo, considerando que o código criado recebeu o nome de 'busca_e_conta':

```bash
$ echo Ola mundo cruel! Ola universo ingrato! > ola.txt
$ ./busca_e_conta Ola ola.txt
$ 'Ola' ocorre 2 vezes no arquivo 'ola.txt'.
```
