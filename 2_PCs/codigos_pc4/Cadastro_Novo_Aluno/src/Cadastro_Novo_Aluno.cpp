//============================================================================
// Name        : Cadastro_Novo_Aluno.cpp
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

int Em_Branco(char *matricula, char *turma){
	int fp;
		char Nome_Arquivo[20];
		sprintf(Nome_Arquivo, "turma%c/listaturma%c.txt", turma[0], turma[0]);
		fp = open(Nome_Arquivo, O_RDWR | O_CREAT, S_IRWXU);
		if (fp == -1) {
			cout << "Nao foi possivel abrir a lista." << endl;
			cout
					<< "Certifique-se de que esteja digitando o numero da turma corretamente."
					<< endl;
			exit(2);
		}
		char c;
		if(read(fp,&c,1) == 0){
			cout << "Nenhum Aluno Cadastrado." << endl;
			cout << "Primeiro Aluno sera Cadastrado." << endl;
			char sCadastro_aluno[20];
			sprintf(sCadastro_aluno,"1 %s\n",matricula);
			write(fp,sCadastro_aluno,strlen(sCadastro_aluno));
			cout << "Matricula: " << matricula << " cadastrada." << endl;
			close(fp);
			return true;
		}
		else{
			cout << "Existem alunos cadastrados." << endl;
			close(fp);
			return false;
		}
}


int main(int argc, char *argv[]) {

	if (argc != 3) {
		cout << "Use este programa da forma: " << endl;
		cout
				<< "./Cadastro_Novo_Aluno \"Matricula do Aluno\" \"Numero da Turma\"" << endl;
		exit(1);
	}
	if(Em_Branco(argv[1],argv[2])){

	}

	return 0;
}
