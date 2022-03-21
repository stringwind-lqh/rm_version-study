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
    vector<Mat> channels;
	split(srcImage, channels);
	imshow("Blue", channels.at(0));
	imshow("Green", channels.at(1));
	imshow("Red", channels.at(2));
	waitKey(0);
	return 0; 
}