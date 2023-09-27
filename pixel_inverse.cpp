#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    Mat img1 = imread("lenna.bmp", IMREAD_COLOR);   // 컬러영상 로딩

    if(img1.empty()) {  // 이미지 로딩 체크
        cout << "Image load failed" <<endl;
        return 0;
    }
    else if(img1.type() != CV_8UC3) {   // 이미지 타입 체크
        cout << "Image load type failed" <<endl;
        return 0;
    }
    
    Mat img2 = img1.clone();

    // 채널별 반전
    for(int r=0; r<img2.rows; r++) {
        for(int c=0; c<img2.cols; c++) {
            Vec3b& pixel = img2.at<Vec3b>(r, c);

            pixel[0] = 255 - pixel[0];
            pixel[1] = 255 - pixel[1];
            pixel[2] = 255 - pixel[2];
        }
    }

    imshow("img1", img1);   // 원 영상 출력
    imshow("img2", img2);   // 반전된 영상 출력

    waitKey();
}
