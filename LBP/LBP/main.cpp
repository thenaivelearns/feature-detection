#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat dst,gray_src;
	Mat src = imread("D:/AAwork/VS Project/LBP/lbp2.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);

	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	int width = gray_src.cols;
	int height = gray_src.rows;

	Mat lbpImage = Mat::zeros(height - 2, width - 2, CV_8UC1);
	for (int row = 1; row < height-1; row++) {
		for (int col = 1; col < width - 1; col++) {
			uchar c = gray_src.at<uchar>(row, col);
			uchar code = 0;
			code |= (gray_src.at<uchar>(row - 1, col - 1) > c) << 7;
			code |= (gray_src.at<uchar>(row - 1, col ) > c) << 7;
			code |= (gray_src.at<uchar>(row - 1, col + 1) > c) << 7;
			code |= (gray_src.at<uchar>(row , col + 1) > c) << 7;
			code |= (gray_src.at<uchar>(row + 1, col + 1) > c) << 7;
			code |= (gray_src.at<uchar>(row + 1, col ) > c) << 7;
			code |= (gray_src.at<uchar>(row + 1, col - 1) > c) << 7;
			code |= (gray_src.at<uchar>(row , col - 1) > c) << 7;
			lbpImage.at<uchar>(row - 1, col - 1) = code;
		}
	}
	namedWindow("LBP result", WINDOW_AUTOSIZE);
	imshow("LBP result", lbpImage);
	waitKey(0);
	return 0;
}


