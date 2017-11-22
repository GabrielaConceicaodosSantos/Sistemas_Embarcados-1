//============================================================================
// Name        : Student_Detector.cpp
// Author      : Leonardo Amorim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
using namespace cv;

int main( )
{
    Mat image;
    image = imread("/home/leonardo/Documentos/Projeto_Embarcados/imagem-teste.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow( "window1", 1 );
    imshow( "window1", image );
    waitKey(0);

    // Load Face cascade (.xml file)
    CascadeClassifier face_cascade;
    face_cascade.load( "/home/leonardo/Documentos/Projeto_Embarcados/data1/cascade.xml" );

    // Detect faces
    std::vector<Rect> faces;
    face_cascade.detectMultiScale( image, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(150, 150) );

    // Draw circles on the detected faces
    for( int i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }

    imshow( "Detected Face", image );

    waitKey(0);
    return 0;

/*
    CascadeClassifier cascade;
        const float scale_factor(1.2f);
        const int min_neighbors(3);

        if (cascade.load("/home/leonardo/Documentos/Projeto_Embarcados/data1/cascade.xml")) {

            {
            	string image_path = "/home/leonardo/Documentos/Projeto_Embarcados/imagem-teste.jpg";
                Mat img = imread(image_path, CV_LOAD_IMAGE_GRAYSCALE);
                equalizeHist(img, img);
                vector<Rect> objs;
                vector<int> reject_levels;
                vector<double> level_weights;
                cascade.detectMultiScale(img, objs, reject_levels, level_weights, scale_factor, min_neighbors, 0, Size(), Size(), true);

                Mat img_color = imread(image_path, CV_LOAD_IMAGE_COLOR);
                for (int n = 0; n < objs.size(); n++) {
                    rectangle(img_color, objs[n], Scalar(255,0,0), 8);
                    putText(img_color, to_string(reject_levels[n]),Point(objs[n].x, objs[n].y), 1, 1, Scalar(0,0,255));
                }
                imshow("Detected Face", img_color);
                waitKey(0);
            }
        }

        return 0;
*/
}



