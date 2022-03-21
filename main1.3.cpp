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
    Mat shallowMat = srcImage;
	Mat deepMat = srcImage.clone();
	dst.create(srcImage.size(), srcImage.type());
	int heigth = srcImage.rows;
	int width = srcImage.cols;
	uchar threshold=100;
	for (int row = 0; row < heigth; row++) {
		for (int col = 0; col < width; col++) {
				uchar average =(srcImage.at<Vec3b>(row, col)[0]+srcImage.at<Vec3b>(row, col)[1]+srcImage.at<Vec3b>(row, col)[2])/3;
                if(average > threshold) average=255;
                else average=0;
                srcImage.at<Vec3b>(row, col)[0]=average;
                srcImage.at<Vec3b>(row, col)[1]=average;
                srcImage.at<Vec3b>(row, col)[2]=average;
			}
    }
    imshow("shallow", shallowMat);
	imshow("deep", deepMat);
    waitKey(0);
    return 0;    
}