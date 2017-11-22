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

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout
				<< "Execute este programa informando o numero da turma e o numero do aluno."
				<< endl;
		cout << ".\\TakePicture 1 1, por exemplo." << endl;
		exit(1);
	}

	char num_turma[2] = { *argv[1] };
	char num_aluno[2] = { *argv[2] };
	char comando_1[50] = { };
	strcat(comando_1, "cd turma");
	strcat(comando_1, num_turma);
	strcat(comando_1, ";");
	if (system(comando_1) == 512) {

		cout << "Erro tentando entrar no diretorio da turma." << endl;
		cout << "Crie um diretorio para a turma especificada." << endl;
		exit(2);
	}

	char comando_2[50] = { };
	strcat(comando_2, "mkdir ");
	strcat(comando_2, num_aluno);
	strcat(comando_2, "-img");
	strcat(comando_2, ";");

	char comando_3[50] = { };
	strcat(comando_3, "cd ");
	strcat(comando_3, num_aluno);
	strcat(comando_3, "-img");

	char comando[50] = { };
	strcat(comando, comando_1);
	strcat(comando, comando_2);
	strcat(comando, comando_3);

	system(comando);

	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;
	cout << "Pressione ESC para comecar a tirar as fotos." << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	bool bSuccess;
	while (1) {
		Mat frame;

		bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		if (waitKey(30) == 27) {
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	//if success, and user have pressed the key, then take 150 photos
	if (bSuccess) {
		for (int i = 1; i <= 150; i++) {
			Mat frame;
			cap.read(frame);
			ostringstream oss;
			oss << num_aluno[0] << "-img" << i << ".jpg";
			imwrite(oss.str(), frame);
			//usleep(26000);
		}

		char str[50];
		sprintf(str, "mv *.jpg turma%c/img%c", num_turma[0], num_aluno[0]);
		system(str);
	} else {
		cout << "Erro ao salvar imagens." << endl;
	}
	cout << "Pressione qualquer tecla para encerrar." << endl;
	waitKey(0);

	return 0;
}
