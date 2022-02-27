#ifndef HARRIS_H
#define HARRIS_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

extern int thresh, max_count, row_d[], col_d[];
char Harris_Demo(Mat src);
double PointsFeature(int* row, int* col,int i);
#endif