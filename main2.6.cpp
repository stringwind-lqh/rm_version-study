#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	cv::Mat origin = imread("/home/stringwind-lqh/C And C++ Code/build/1.png", 0);
	Mat Canny_image;
	Mat dx,dy;
	Sobel(origin, dx, CV_16SC1, 1, 0, 3);
	Sobel(origin, dy, CV_16SC1, 0, 1, 3);
	Canny(dx,dy, Canny_image, 60, 180);

	imshow("original image", origin);
	imshow("Canny_image", Canny_image);

	waitKey(0);
}

