// ov_test_01.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "opencv2/nonfree/nonfree.hpp"    
//#include "opencv2/legacy/legacy.hpp" 
#include <iostream>
#include"segment.h"

int main() {
	Mat srcImage = imread("14.bmp");
	imshow("src",srcImage);
	ostu(srcImage);
	waitKey(0);
	return 0;
}


//void match(Mat srcImage, Mat matchImage) {
//	GoodFeaturesToTrackDetector Detector(500);  //最大点数,值越大，点越多
//	vector<KeyPoint> keyPoint1, keyPoint2;
//	Detector.detect(srcImage, keyPoint1);
//	Detector.detect(matchImage, keyPoint2);
//
//	//特征点描述，为下边的特征点匹配做准备    
//	SiftDescriptorExtractor  Descriptor;
//	Mat imageDesc1, imageDesc2;
//	Descriptor.compute(srcImage, keyPoint1, imageDesc1);
//	Descriptor.compute(matchImage, keyPoint2, imageDesc2);
//
//	BruteForceMatcher< L2<float> > matcher;
//	vector<vector<DMatch> > matchePoints;
//	vector<DMatch> GoodMatchePoints;
//
//	vector<Mat> train_desc(1, imageDesc1);
//	matcher.add(train_desc);
//	matcher.train();
//
//	matcher.knnMatch(imageDesc2, matchePoints, 2);
//	cout << "total match points: " << matchePoints.size() << endl;
//
//	for (int i = 0; i < matchePoints.size(); i++)
//	{
//		if (matchePoints[i][0].distance < 0.6 * matchePoints[i][1].distance)
//		{
//			GoodMatchePoints.push_back(matchePoints[i][0]);
//		}
//	}
//
//	Mat first_match;
//	drawMatches(matchImage, keyPoint2, srcImage, keyPoint1, GoodMatchePoints, first_match);
//	imshow("first_match ", first_match);
//}