#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
int main(int argc, char** argv )
{

    if ( argc != 2 )
    {
        cout<<"usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }
    Mat srcImage;
    srcImage = imread( argv[1], 1 );
    if ( !srcImage.data )
    {
        cout<<"No image data \n";
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", srcImage);
    Mat dst;
	dst.create(srcImage.size(), srcImage.type());
	int heigth = srcImage.rows;
	int width = srcImage.cols;
	int nc = srcImage.channels();

	for (int row = 0; row < heigth; row++) {
		for (int col = 0; col < width; col++) {
			if(nc==1){
				int gray = srcImage.at<uchar>(row, col);    //获取像素值
				dst.at<uchar>(row, col) = 255 - gray; //像素值取反赋值
			}
			else if (nc == 3) {
				int b = srcImage.at<Vec3b>(row, col)[0];  //获取像素值b 
				int g = srcImage.at<Vec3b>(row, col)[1];  //获取像素值g
				int r = srcImage.at<Vec3b>(row, col)[2];  //获取像素值r
				dst.at<Vec3b>(row, col)[0] = (b+g+r)/3;
				dst.at<Vec3b>(row, col)[1] = (b+g+r)/3;
				dst.at<Vec3b>(row, col)[2] = (b+g+r)/3;

			}
		}
	}
    namedWindow("TONGDAOTONGYI",WINDOW_AUTOSIZE);
	imshow("TONGDAOTONGYI", dst);
    waitKey(0);
    return 0;
}



