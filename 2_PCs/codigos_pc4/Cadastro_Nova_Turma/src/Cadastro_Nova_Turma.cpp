//============================================================================
// Name        : Cadastro_Nova_Turma.cpp
// Author      : Leonardo Amorim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stdio.h>
#include <fcntl.h> //funcao open()
#include <unistd.h> //funcao close()
#include <stdlib.h> //funcao exit()
#include <string.h> //funcao strcat()
#include <sys/types.h> //funcao lseek()

int Verificar_Arquivo_Turmas() {

	int fp;
	char sArquivoInfoTurmas[20] = "infoturmas.txt";
	fp = open(sArquivoInfoTurmas, O_RDONLY);
	if (fp == -1) {
		cout << "Arquivo infoturmas.txt nao existe e sera criado." << endl;
		return 0; //arquivo nao existe
	}
	cout << "Arquivo infoturmas.txt encontrado." << endl;
	close(fp);
	return 1; //arquivo existe
}

void Cadastrar_Primeira_Turma(char *NomeDisciplina, char *Turma) {
	int fp1;
	char sArquivoInfoTurmas[20] = "infoturmas.txt";
	fp1 = open(sArquivoInfoTurmas, O_RDWR | O_CREAT, S_IRWXU);
	if (fp1 == -1) {
		cout << "Could not create the file " << sArquivoInfoTurmas << endl;
		exit(2);
	}

	char sNomeDisciplina[50];
	strcpy(sNomeDisciplina, NomeDisciplina);
	char sTurma[3];
	strcpy(sTurma, Turma);
	char sNumeroDisciplina[3] = "1\n";

	strcat(sNomeDisciplina, "\n");
	strcat(sTurma, "\n");

	write(fp1, sNumeroDisciplina, strlen(sNumeroDisciplina));
	write(fp1, sNomeDisciplina, strlen(sNomeDisciplina));
	write(fp1, sTurma, strlen(sTurma));
	close(fp1);

	cout << "Arquivo " << sArquivoInfoTurmas << " criado com sucesso." << endl;
	cout << "Disciplina: " << sNomeDisciplina;
	cout << "Turma: " << sNumeroDisciplina;

	//como essa e' a primeira turma cadastrada, entao vai ser a primeira lista

	system("mkdir turma1");
	char sArquivoTurma[50] = "turma1/listaturma1.txt";
	int fp2;

	fp2 = open(sArquivoTurma, O_RDWR | O_CREAT, S_IRWXU);

	if (fp2 == -1) {
		cout << "Could not create the file " << sArquivoInfoTurmas << endl;
		exit(3);
	}

	cout << "Arquivo criado em: " << sArquivoTurma << endl;
	close(fp2);
}

int Verifica_Turma(char *disciplina, char *turma) {

	char sDisciplina_Lida[25]={0};
	char sTurma_Lida[1]={0};
	char sNumero[2]; //refere-se ao numero da disciplina lida no momento
	char sNumero_Disciplinas[2]; //refere-se ao numero total de disciplinas
	int fp, iNumero_Disciplinas;
	bool turma_existe = false;

	fp = open("infoturmas.txt", O_RDONLY);
	read(fp, sNumero_Disciplinas, 1); //o primeiro byte e' o numero de
	//da ultima disciplina cadastrada, que se e' tambem o numero de
	//disciplinas cadastradas no arquivo

	iNumero_Disciplinas = atoi(sNumero_Disciplinas);

	for (int i = 0; i < iNumero_Disciplinas; i++) {
		char c;

		if (i == 0) {
			read(fp, &c, 1); //ler o caracter /n
		} else {
			read(fp, sNumero, 1); //ler o numero da disciplina
			read(fp, &c, 1); //ler o caracter /n
		}

		int j = 0;
		c = 0;
		while (c != '\n') {
			read(fp, &c, 1);
			if (c != '\n') {
				sDisciplina_Lida[j] = c; //lendo linha que se refere a disciplina
				j++;
			}
		}

		read(fp, sTurma_Lida, 1); //ler turma
		if ((strncmp(sDisciplina_Lida, disciplina, strlen(disciplina)) == 0)
				&& (strncmp(sTurma_Lida, turma, strlen(turma)) == 0)) {
			turma_existe = true;
			break;
		}
	}

	close(fp);
	if (turma_existe == true) {
		return 1;
	} else {
		return 0; //turma nao existe
	}
}

void Acrescentar_Turma(char *disciplina, char *turma) {
	int fp, iNumero_Disciplinas, NumeroCaracteres = 0;
	char sNumero_Disciplinas[2];
	char nova_linha = '\n', c;
	fp = open("infoturmas.txt", O_RDONLY);
	if(fp == -1){
		cout << "Could not open the file" << endl;
		exit(1);
	}

	read(fp, sNumero_Disciplinas, 1);
	NumeroCaracteres++; //comecou lendo 1 byte
	iNumero_Disciplinas = atoi(sNumero_Disciplinas); //convertendo o numero
	//de disciplinas cadastradas para int

	iNumero_Disciplinas++; //incrementando o numero de disciplinas

	sprintf(sNumero_Disciplinas, "%d", iNumero_Disciplinas);
	//adicionando este valor a string

	//lendo a quantidade de caracteres no arquivo
	while (read(fp, &c, 1) != 0) {
		NumeroCaracteres++;
	}

	//alocando memoria para colocar toda a informacao do arquivo na memoria
	char *texto = (char *)calloc(NumeroCaracteres + 1,1);

	close(fp);

	fp = open("infoturmas.txt", O_RDONLY);

	int j = 0;
	while(read(fp,&c,1) != 0){
		texto[j] = c;
		j++;
	}
	//ler todos os caracteres menos a
	//primeira linha

	cout << texto << endl;

	close(fp);

	fp = open("infoturmas.txt", O_RDWR | O_CREAT, S_IRWXU);

	write(fp, sNumero_Disciplinas, 1); //inserir o novo numero de disciplinas
	//cadastradas
	write(fp, &nova_linha, 1); //pula uma linha
	write(fp, disciplina, strlen(disciplina)); //insere o nome da nova disciplina
	write(fp, &nova_linha, 1); //pula uma linha
	write(fp, turma, strlen(turma)); //insere a nova turma
	write(fp, &nova_linha, 1); //pula uma linha
	write(fp, texto, strlen(texto)); //insere o restante do conteudo
	//antigo do arquivo
	write(fp, &nova_linha, 1); //pula uma linha

	delete[] texto; //limpa o buffer

	close(fp); //fecha o arquivo

	cout << "Adicionado:" << endl;
	cout << "Disciplina: " << disciplina << endl;
	cout << "Turma: " << turma << endl;
	cout << "Numero da Turma: " << iNumero_Disciplinas << endl;

	//criando diretorio e lista da turma especifica
	char sArquivoTurma[50];

	//criando diretorio
	sprintf(sArquivoTurma, "mkdir turma%d", iNumero_Disciplinas);
	system(sArquivoTurma);

	sprintf(sArquivoTurma, "turma%d/listaturma%d.txt", iNumero_Disciplinas,
			iNumero_Disciplinas);
	int fp2;

	fp2 = open(sArquivoTurma, O_RDWR | O_CREAT, S_IRWXU);

	cout << "Arquivo criado em: " << sArquivoTurma << endl;
	close(fp2);

}

int main(int argc, char *argv[]) {

	if (argc != 3) {
		cout << "Para cadastrar uma nova turma, use:" << endl;
		cout << "./Cadastro_Nova_Turma \"Nome da Disciplina\" \"Turma\" "
				<< endl;
		exit(1);
	}
//verificar se arquivo infoturmas.txt existe
//criar arquivos de turmas e lista da primeira turma a ser cadastrada (OK)
//verificar se turma existe
//verificar numero de turmas existentes
//acrescentar nova turma  ao arquivo infoturmas.txt e criar lista da turma

	if (!Verificar_Arquivo_Turmas())
		Cadastrar_Primeira_Turma(argv[1], argv[2]);
	else {
		if (Verifica_Turma(argv[1], argv[2])) {
			cout << "A turma especificada ja esta cadastrada!" << endl;
		} else {
			Acrescentar_Turma(argv[1], argv[2]);
		}
	}

	return 0;
}
