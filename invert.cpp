#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void) 
{

    Mat img1 = imread("cat.bmp");

    Mat img2;
    img2 = ~img1(Rect(220, 120, 340, 240)).clone();

    imshow("img1", img1);
    imshow("img2", img2);

    waitKey();
    return 0;
}