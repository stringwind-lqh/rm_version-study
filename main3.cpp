#include "stdio.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include<opencv2/imgproc/imgproc_c.h>
 
using namespace std;
using namespace cv;
bool draw;
Mat src;
Mat roi;
Point cursor;
Rect rect;
void onMouse(int event, int x, int y, int flags, void *param);
int main(int argc, char** argv)
{            
    
    src = imread("/home/stringwind-lqh/C And C++ Code/build/5.png");
    namedWindow("Image");
    imshow("Image", src);
    setMouseCallback("Image", onMouse, NULL);
    waitKey(0);
    return 0;
}
void onMouse(int event, int x, int y, int flags, void *param)
{
    Mat img = src.clone();
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        cursor = Point(x, y);
        rect = Rect(x, y, 0, 0);
        draw = true;
        break;


    case EVENT_LBUTTONUP:
        if (rect.height > 0 && rect.width > 0)
        {
            roi = img(Rect(rect.x, rect.y, rect.width, rect.height));//将img中的矩形区域复制给roi，并显示在SignROI窗口 
            rectangle(img, rect, Scalar(0, 0, 255), 2);
            namedWindow("SignROI");
            imshow("SignROI", img);
            src.copyTo(img);  //还原  
            imshow("Image", img);
            namedWindow("ROI");
            imshow("ROI", roi);  //显示ROI图像
            waitKey(0);  
        }
		draw = false;
        break;
    case EVENT_MOUSEMOVE:
        if (draw)
        {
            rect.x = MIN(x, cursor.x);
            rect.y = MIN(y, cursor.y);
            rect.width = abs(cursor.x - x);
            rect.height = abs(cursor.y - y);
            rect &= Rect(0, 0, src.cols, src.rows);
        }
        break;
    }
}