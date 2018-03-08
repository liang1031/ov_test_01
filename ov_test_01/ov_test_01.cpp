// ov_test_01.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
void find_contours(Mat ostuImage) {

	Mat dstImage = Mat::zeros(ostuImage.rows, ostuImage.cols, CV_8UC3);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(ostuImage, contours, hierarchy,
		CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	int index = 0;
	double area;
	Scalar color(255, 255, 255);
	for (; index >= 0; index = hierarchy[index][0])
	{
		area = contourArea(contours[index]);
		if (area > 25) {
			drawContours(dstImage, contours, index, color, CV_FILLED, 8, hierarchy);
		}
		
	}
	imshow("轮廓图", dstImage);
}
void ostu(Mat srcImage){
	Mat grayImage,ostuImage;
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	imshow("gray",grayImage);
	threshold(grayImage, ostuImage, 0, 255, CV_THRESH_OTSU);
	imshow("ostu", ostuImage);
	find_contours(ostuImage);
}
int main() {
	Mat srcImage = imread("14.bmp");
	imshow("src",srcImage);
	ostu(srcImage);
	waitKey(0);
	return 0;
}

