#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char* argv[] )
{
	cv::Mat srcMat = imread("/home/stringwind-lqh/C And C++ Code/build/test2.png",0);
	Mat newMat;
	Mat lableMat;
	Mat stateMat;
	Mat centrMat;
	Mat resultMat;//二值化
	threshold(srcMat, newMat, 100, 255, THRESH_OTSU);

	int nComp = cv::connectedComponentsWithStats(newMat, lableMat, stateMat, centrMat, 8, CV_32S);

	std::cout << "number:" << nComp - 1 << std::endl;	

	resultMat = cv::Mat::zeros(srcMat.size(),CV_8UC3);
	std::vector <cv::Vec3b> colors(nComp);
	colors[0]= cv::Vec3b(0, 0, 0);

	for (int n = 1; n < nComp; n++)
	{
		colors[n] = cv::Vec3b(rand() / 255, rand() / 255, rand() / 255);
	}

	for (int y = 0; y < srcMat.rows; y++)
	{
		for (int x=0; x < srcMat.cols; x++)
		{
			int lable = lableMat.at<int>(y, x);
			CV_Assert(0 <= lable&&lable <= nComp);
			resultMat.at<cv::Vec3b>(y, x) = colors[lable];
		}
	}
	for (int i = 1; i < nComp;i++)
	{
		Rect bndbox;

		bndbox.x = stateMat.at<int>(i, 0);
		bndbox.y = stateMat.at<int>(i, 1);

		bndbox.width = stateMat.at<int>(i, 2);
		bndbox.height = stateMat.at<int>(i, 3); //各个连通域的统计信息保存在stasMat中,并绘制bounding box

		rectangle(resultMat, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}
    imshow("original image",srcMat);
	imshow("result image", resultMat);
	waitKey(0);
	}

