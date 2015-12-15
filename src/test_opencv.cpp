/*************************************************************************
    > File Name: test_opencv.cpp
    > Author: lengjing
    > Mail: jingleng77@sina.com 
    > Created Time: 2015年12月15日 星期二 16时14分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <boost/filesystem.hpp>
using namespace cv;

//#include "Config.h"
//


int main(int argc, char **argv)
{
	namedWindow("test_capture");
	VideoCapture cap(0);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

	Mat img, img_g;
	unsigned int frame = 0;
	double time = 0;
	while( char(waitKey(1) != 'q'))
	{
		double t0 = getTickCount();
		cap >> img;
		cvtColor(img, img_g, CV_RGB2GRAY);
		frame++;
		imshow("test_capture", img_g);
		time += (getTickCount() - t0) / getTickFrequency();
		cout << frame / time <<  " fps "<< endl;
	}


	cout << "test_opencv" << endl;
}



