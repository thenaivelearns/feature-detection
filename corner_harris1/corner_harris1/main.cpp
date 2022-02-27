#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Mat src,gray_src;
int thresh = 130;
int max_count = 255;
void Harris_Demo(int, void*);
int main() {
	src = imread("D:/AAwork/VS Project/corner_harris/1.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);

	namedWindow("output", WINDOW_AUTOSIZE);
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	createTrackbar("threshold:", "output", &thresh, max_count, Harris_Demo);
	Harris_Demo(0, 0);
	waitKey(0);
	return 0;
}

void Harris_Demo(int,void*) {
	Mat dst, norm_dst, normScaleDst;
	dst = Mat::zeros(gray_src.size(), CV_32FC1);

	int blocksize = 2;
	int ksize = 3;
	double k = 0.04;
	cornerHarris(gray_src, dst, blocksize, ksize, k, BORDER_DEFAULT);
	normalize(dst, norm_dst, 0, 255, NORM_MINMAX, CV_32FC1, Mat());//πÈ“ªªØ
	convertScaleAbs(norm_dst, normScaleDst);

	Mat resultImg = src.clone();
	for (int row = 0; row < resultImg.rows; row++) {
		uchar* currentRow = normScaleDst.ptr(row);
		for (int col = 0; col < resultImg.cols; col++) {
			int value = (int)* currentRow;
			if (value > thresh) {
				circle(resultImg, Point(col, row), 1, Scalar(0, 0, 255), 2, 8, 0);
			}
			currentRow++;
		}
	}
	imshow("output", resultImg);
}
