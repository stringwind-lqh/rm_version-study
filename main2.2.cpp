#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char* argv[] )
{
	cv::Mat srcMat = imread("/home/stringwind-lqh/C And C++ Code/build/test2.png",0);
	Mat newMat;
	Mat Mat_open;
	Mat Mat_close;
	Mat Mat_erode;
	Mat Mat_dilate;//对图像二值化
	threshold(srcMat, newMat, 100, 255, THRESH_OTSU);

	Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));

	morphologyEx(newMat, Mat_open, MORPH_OPEN, kernel);
	morphologyEx(newMat, Mat_close, MORPH_CLOSE, kernel);
	erode(newMat, Mat_erode, kernel);
	dilate(newMat, Mat_dilate,kernel);

	imshow("srcMat", srcMat);
	imshow("open",Mat_open);
	imshow("close", Mat_close);
	imshow("erode", Mat_erode);
	imshow("dilate", Mat_dilate);
	waitKey(0);
	}

