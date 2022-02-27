#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("D:/AAwork/VS Project/hog/hog6.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", WINDOW_AUTOSIZE);
	imshow("input image", src);
	/*
	Mat dst, dst_gray;
	resize(src, dst, Size(64, 128));
	cvtColor(dst, dst_gray, COLOR_BGR2GRAY);
	HOGDescriptor detector(Size(64, 128), Size(16, 16), Size(8, 8), Size(8, 8), 9);

	vector<float>descriptors;
	vector<Point>locations;
	detector.compute(dst_gray, descriptors, Size(0, 0), Size(0, 0), locations);
	cout << "number of HOG descriptors:" << descriptors.size() << endl;
	*/
	HOGDescriptor hog = HOGDescriptor();
	hog.setSVMDetector(hog.getDefaultPeopleDetector());
	vector<Rect>peoples;
	hog.detectMultiScale(src, peoples, 0, Size(8, 8), Size(32, 32), 1.05, 2);
	Mat result = src.clone();
	for (size_t t = 0; t < peoples.size(); t++) {
		rectangle(result, peoples[t], Scalar(255, 0, 0), 2, 8, 0);
	}
	namedWindow("HOG SVM Detector Demo", WINDOW_AUTOSIZE);
	imshow("HOG SVM Detector Demo", result);


	waitKey(0);
	return 0;
}


