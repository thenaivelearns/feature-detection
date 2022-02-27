#include <opencv2/opencv.hpp>
#include <iostream>
#include "harris.h"

int main() {
	Mat src1;
	Mat src = imread("D:/AAwork/VS Project/corner_harris/B1.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return - 1;
	}
	namedWindow("input image",WINDOW_AUTOSIZE);
	imshow("input image", src);
	resize(src, src1, Size(400,400 ));
	
	//createTrackbar("threshold:", "output", &thresh, max_count, Harris_Demo);
	cout << "result is "<< Harris_Demo(src1) << endl;
	waitKey(0);
	return 0;
}


