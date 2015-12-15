/*************************************************************************
    > File Name: warpAffine.cpp
    > Author: lengjing
    > Mail: jingleng77@sina.com 
    > Created Time: 2015年12月15日 星期二 17时04分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include <opencv2/opencv.hpp>
#include <opencv2/stitching/stitcher.hpp>
#include <opencv2/stitching/warpers.hpp>

using namespace cv;

int main(int argc, char **argv)
{
	Mat im = imread("../data/data1/image.jpg");
	Mat im_transformed;
	imshow("Original", im);

	int rotation_degrees = 30;
	Mat M = getRotationMatrix2D(Point(im.cols / 2, im.rows / 2), rotation_degrees,1);

	cout << M << endl;

	warpAffine(im, im_transformed, M, im.size(), INTER_LINEAR);

	imshow("Transformed", im_transformed);

    while(char(waitKey(1) != 'q')) {

	}
	return 0;
}
