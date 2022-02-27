#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture(0);
	while (1) {
		Mat src, src_gray, re;
		//src = imread("D:/AAwork/yuan.jpg");
		capture >> src;
		if (!src.data)
		{
			return -1;
		}
		cvtColor(src, src_gray, COLOR_BGR2GRAY);
		GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
		resize(src_gray, re, Size(320, 240));
		vector<Vec3f> circles;

		HoughCircles(re, circles, HOUGH_GRADIENT, 1, 150, 100, 60, 5, 200);//1,最小距离,canny阈值,检测阈值,最小半径,最大

		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			// circle center
			circle(src, center, 3, Scalar(255, 0, 0), -1, 8, 0);
			// circle outline
			circle(src, center, radius, Scalar(255, 0, 0), 3, 8, 0);
		}

		namedWindow("Hough Circle Transform Demo", WINDOW_AUTOSIZE);
		imshow("Hough Circle Transform Demo", src);

		waitKey(10);
	}
		return 0;
}

