#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    int Brightness = -180;

    Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if(img1.empty()) {
        cout << "Image load failed" <<endl;
        return 1;
    }

    Mat img2 = img1.clone();

    for(int j=0; j<img2.rows; j++) {
        for(int i=0; i<img2.cols; i++) {
            if(img2.at<uchar>(j, i) + Brightness > 255) {
                img2.at<uchar>(j, i) = 255;
            }
            else if(img2.at<uchar>(j, i) + Brightness < 0) {
                img2.at<uchar>(j, i) = 0;   
            }
            else img2.at<uchar>(j, i) += Brightness; 
        }
    }

    // for(int j=0; j<img2.rows; j++) {
    //     uchar* p = img2.ptr<uchar>(j);
    //     for(int i=0; i<img2.cols; i++) {
    //         if(p[i] + Brightness > 255) {
    //             p[i] = 255;
    //         }
    //         else if(p[i] + Brightness < 0) {
    //             p[i] = 0;
    //         }
    //         else p[i] += Brightness;
    //     }
    // }

    // for(MatIterator_<uchar> it = img2.begin<uchar>(); it != img2.end<uchar>(); ++it) {
    //     if((*it) + Brightness > 255) {
    //         (*it) = 255;
    //     }
    //     else if((*it) + Brightness < 0) {
    //         (*it) = 0;
    //     }
    //     else (*it) += Brightness;
    // }

    imshow("img1", img1);
    imshow("img2", img2);

    waitKey();
}

    
