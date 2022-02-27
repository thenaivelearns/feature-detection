#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include "opencv2/opencv_modules.hpp"

using namespace std;

using namespace cv;

int main() {
	Mat src1;
	Mat src = imread("D:/AAwork/1.jpg",IMREAD_GRAYSCALE);
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);
	int minHessian = 400;
	Ptr<SURF>detector = ;

	waitKey(0);
	return 0;
}


