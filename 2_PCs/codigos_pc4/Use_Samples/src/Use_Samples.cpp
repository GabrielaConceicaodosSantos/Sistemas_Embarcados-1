//============================================================================
// Name        : Use_Samples.cpp
// Author      : Leonardo Amorim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

#include <fcntl.h> //function open()
#include <unistd.h> //function close(),write()

int main() {

	//frame's width
	double dWidth = 640;

	//frame's length
	double dHeight = 480;
	char cNum_aluno[1] = { '1' };
	char sPhotos_information[50];
	char sFilename1[15], sFilename2[15];
	//create a file for the samples called
	// xsamples.dat where x refers to students's number.

	//first, let's create the file with the positive samples

	int fp1, fp2;

	sprintf(sFilename1, "%c-samples.dat", cNum_aluno[0]);

	fp1 = open(sFilename1, O_RDWR | O_CREAT, S_IRWXU);
	if (fp1 == -1) {
		cout << "Could not create the file" << sFilename1 << ". Exiting."
				<< endl;
		exit(1);
	}

	cout << "Success. Filename created with name: " << sFilename1 << endl;

	for (int i = 1; i <= 150; i++) {

		// img/img1.jpg 1 140 100 45 45
		//sprintf(sPhotos_information, "img%c/%c-img%d.jpg 1 0 0 %.0lf %.0lf\n",
		//cNum_aluno[0], cNum_aluno[0], i, dWidth, dHeight);
		sprintf(sPhotos_information,"img1/1-img%d.jpg 1 200 0 360 460\n",i);
		write(fp1, sPhotos_information, strlen(sPhotos_information));
	}

	cout << "Success. Samples file from student " << cNum_aluno[0]
			<< " created." << endl;

	//system(opencv_createsamples -info 1-samples.dat -num 120 -w 64 -h 48 -vec 1.vec);

	//finally, lets create the file with the negative samples

	sprintf(sFilename2, "%c-negsamples.txt", cNum_aluno[0]);
	fp2 = open(sFilename2, O_RDWR | O_CREAT, S_IRWXU);

	if (fp2 == -1) {
		cout << "Could not create the file" << sFilename2 << ". Exiting."
				<< endl;
		exit(2);
	}

	for (int i = 1; i <= 400; i++) {
		//Example: 1-img2.jpg
		sprintf(sPhotos_information, "neg/1-img%d.jpg\n",i);
		write(fp2, sPhotos_information, strlen(sPhotos_information));
	}

	cout << "Success. Negative Samples file created." << endl;

	//system(opencv_traincascade -data data1 -vec 1.vec -bg 1-negsamples.txt -numPos 110 -numNeg 80 -numStages 2 -w 64 -h 48 -featureType LBP);


	close(fp1);
	close(fp2);

	return 0;
}
