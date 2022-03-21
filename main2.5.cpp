#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	VideoCapture cap(0);
	while (1)
	{
		Mat origin;
		Mat newMat1,newMat2,newMat3;
		cap >> origin;
		medianBlur(origin, newMat1, 3);
		blur(origin, newMat2,Size(3,3));
		GaussianBlur(origin, newMat3, Size(3,3),0.1);
		imshow("original image",origin);
		imshow("中值滤波", newMat1);
		imshow("均值滤波", newMat2);
		imshow("高斯滤波", newMat3);
		waitKey(0);
	}
}

