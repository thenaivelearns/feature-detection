

// opencvtest.cpp : �������̨Ӧ�ó������ڵ㡣
//
 
#include <stdio.h>
#include <tchar.h>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <time.h>
#include<windows.h>
using namespace cv;
using namespace std;
 
int _tmain(int argc, _TCHAR* argv[])
{
 
	VideoCapture capture(1);
	Sleep(100);
	//capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	//capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	capture.set(CAP_PROP_FPS, 1);//֡��
	//capture.set(CV_CAP_PROP_BRIGHTNESS, 1);//���� 50
	//capture.set(CV_CAP_PROP_CONTRAST, 40);//�Աȶ� 50
	//capture.set(CV_CAP_PROP_SATURATION, 50);//���Ͷ� 50
	//capture.set(CV_CAP_PROP_HUE, 50);//ɫ�� 0
	capture.set(CAP_PROP_EXPOSURE, 50);//�ع� -12
	//capture.set(CAP_PROP_FOURCC, FOURCC(��M��, ��J��, ��P��, ��G��));
	Sleep(100);
	/*
	//��ӡ����ͷ����
	printf("width = %.2f\n", capture.get(CV_CAP_PROP_FRAME_WIDTH));
	printf("height = %.2f\n", capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	printf("fbs = %.2f\n", capture.get(CV_CAP_PROP_FPS));
	printf("brightness = %.2f\n", capture.get(CV_CAP_PROP_BRIGHTNESS));
	printf("contrast = %.2f\n", capture.get(CV_CAP_PROP_CONTRAST));
	printf("saturation = %.2f\n", capture.get(CV_CAP_PROP_SATURATION));
	printf("hue = %.2f\n", capture.get(CV_CAP_PROP_HUE));
	printf("exposure = %.2f\n", capture.get(CV_CAP_PROP_EXPOSURE));
	*/
	while (1)
	{
		Mat frame;
		capture >> frame;
 
		waitKey(300);
		imshow("1", frame);
		waitKey(30);
	}
	system("pause");
	return 0;
}