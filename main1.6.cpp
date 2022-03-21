#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
 
int main()
{
    Mat img = imread("1.png");
	//draw a line
	line(img, Point(0, img.size().height / 2), Point(img.size().width, img.size().height / 2), Scalar(0, 0, 255));
	//draw a rectangle
	rectangle(img, Point(img.size().width/4, img.size().height/4), Point(img.size().width- img.size().width / 4, img.size().height - img.size().height/4), Scalar(0, 255, 255));
	//draw a circle
	circle(img, Point(img.size().width / 2, img.size().height / 2), 50, Scalar(255, 0, 255));
	imshow("draw", img);
	imwrite("afterdraw.jpg", img);

	waitKey(0);
}
