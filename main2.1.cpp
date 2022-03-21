#include <opencv2/core/core.hpp>              
#include <opencv2/highgui/highgui.hpp>              
#include <opencv2/imgproc/imgproc.hpp>             
#include <iostream>            
using namespace std;
using namespace cv;
 
int main()
{
	Mat srcImage = imread("/home/stringwind-lqh/C And C++ Code/build/1.png");
	imshow("original image", srcImage); 
	Mat srcGray;
	cvtColor(srcImage, srcGray, COLOR_RGB2GRAY);
	Mat dstImage;
	inRange(srcGray, Scalar(30, 30, 30), Scalar(100, 100, 100), dstImage);
	imshow(" HSV 通道的二值化", dstImage);
	waitKey(0);
	return 0;
}
