#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat sourceImage = imread("lenna.bmp");

    if(sourceImage.empty()) {  //file loading check
        cout << "Image load failed" <<endl;
        return 1;
    }
    else if(sourceImage.type() != CV_8UC3) {   //type check
        cout << "Image load type failed" <<endl;
        return 1;
    }

    Mat copyImage = sourceImage.clone();

    for(int j=0; j<copyImage.rows; j++) {
        for(int i=0; i<copyImage.cols; i++) {
            Vec3b& pixel = copyImage.at<Vec3b>(j, i);
            uchar r = pixel[0];
            uchar g = pixel[1];
            uchar b = pixel[2];
            
            uchar gray = (uchar)((b + g + r ) / 3);
            
            if((30 <= b && b <= 180) && (0 <= g  && g <= 130) && (30 <= r && r <= 140)) {
                //nothing
            }else {
                pixel[0] = gray;
                pixel[1] = gray;
                pixel[2] = gray;
            }
        }
    }

    imshow("source image", sourceImage);
    imshow("copy image", copyImage);
    
    waitKey();
    return 0;
}