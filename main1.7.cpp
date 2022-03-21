#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;

int main()
{
	//原图；灰度图；对比度增强后的伽马图像
	Mat img, gray_image, gamma_image;
	img = imread("/home/stringwind-lqh/C And C++ Code/build/test.png");
	imshow("original image",img);
    cvtColor(img,gray_image,COLOR_BGR2GRAY);
	gamma_image.create(gray_image.size(), CV_64F);
	//伽马变换
	Mat src,gammaimage;  //归一化图像
	double gamma = 0.5;
	gray_image.convertTo(src, CV_64F, 1.0 / 255,0);
	int height = src.rows;
	int width = src.cols;
	gamma_image.create(src.size(), CV_64F);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			gamma_image.at<double>(i, j) = pow(src.at<double>(i, j), gamma);
		
		};
	};
	gamma_image.convertTo(gammaimage, CV_8U, 255,0);
	imshow("gamma", gammaimage);
	waitKey(0);
	return 0;
};
