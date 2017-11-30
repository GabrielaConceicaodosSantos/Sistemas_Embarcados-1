/*
 * ProjetoFinal.h
 *
 *  Created on: Nov 28, 2017
 *      Author: pi
 */

#ifndef PROJETOFINAL_H_
#define PROJETOFINAL_H_

#include "Botao.h"
#include "Display.h"
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <sstream>

#include <fcntl.h> //funcao open()
#include <unistd.h> //funcao close()
#include <stdlib.h> //funcao exit()
#include <string.h> //funcao strcat()

using namespace cv;
using namespace std;



void Tomar_Decisao(struct Decisao *decisao,Display *display);
void Realizar_Acao(struct Decisao *decisao, Display *display);
void Acao_Display(Display *display, char *str1, char *str2);
int Registrar_Presenca(Display *display);

#endif /* PROJETOFINAL_H_ */