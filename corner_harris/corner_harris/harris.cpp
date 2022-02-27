#include "harris.h"

int thresh = 130;
int row_d[50] = {}, col_d[50] = {};

char Harris_Demo(Mat src) {
	int i = 0;
	int max_count = 255;
	char result;
	Mat gray_src,dst, norm_dst, normScaleDst;
	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	dst = Mat::zeros(gray_src.size(), CV_32FC1);

	int blocksize = 2;
	int ksize = 3;
	double k = 0.04;
	cornerHarris(gray_src, dst, blocksize, ksize, k, BORDER_DEFAULT);
	normalize(dst, norm_dst, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(norm_dst, normScaleDst);

	Mat resultImg = src.clone();
	for (int row = 0; row < resultImg.rows; row++) {
		uchar* currentRow = normScaleDst.ptr(row);
		for (int col = 0; col < resultImg.cols; col++) {
			int value = (int)* currentRow;
			if (value > thresh) {
				circle(resultImg, Point(col, row), 1, Scalar(0, 0, 255), 2, 8, 0);
				row_d[i] = row;
				col_d[i] = col;
				i++;
			}
			currentRow++;
		}
	}
	imshow("output", resultImg);
	double feature = PointsFeature(row_d, col_d, i);
	cout << feature << endl;
	switch (i) {
	case 4:
		result = 'B';//D

		break;
	case 5:
		result = 'J';
		break;
	case 6:
		result = 'L';
		break;
	case 7:
		if(feature < 2)
		result = 'G';//I
		else result = 'I';
		break;
	case 11:
		if (feature < 1)
			result = 'A';//E
		else result = 'E';
		break;
	case 12:
		if (feature > 1)
			result = 'F';//M
		else result = 'M';
		break;
	case 14:
		result = 'K';
		break;
	case 17:
		result = 'H';
		break;
	default: result = 'N';
		break;
	}
	cout << "number of harris_corner points: " << i << endl;
	return result;
}

double PointsFeature(int* row, int* col,int i) {
	int row_max = 0, row_min = 1000;
	int col_max = 0, col_min = 1000;
	for (int j = 0; j < i; j++) {
		if (row[j] > row_max)row_max = row[j];
		if (row[j] < row_min)row_min = row[j];
		if (col[j] > col_max)col_max = col[j];
		if (col[j] < col_min)col_min = col[j];
	}
	return (double)(row_max - row_min) / (double)(col_max - col_min);
}