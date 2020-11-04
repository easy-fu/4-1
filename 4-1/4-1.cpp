#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("C:/Users/DELL/Desktop/3.jpg", 0);
	if (srcMat.empty())
	{
		cout << "fail to read pic!" << endl;
		return -1;
	}
	cv::Mat result;
	cv::Mat dilate_Mat;
	cv::Mat erode_Mat;
	cv::Mat open_Mat;
	cv::Mat close_Mat;

	threshold(srcMat, result, 100, 255, THRESH_BINARY);
	 morphologyEx( result , erode_Mat,MORPH_ERODE,Mat(5,5,CV_8U),Point(-1,-1), 1,BORDER_CONSTANT,morphologyDefaultBorderValue() );
	 morphologyEx(result, dilate_Mat, MORPH_DILATE, Mat(5, 5, CV_8U), Point(-1, -1), 1, BORDER_CONSTANT, morphologyDefaultBorderValue());
	 morphologyEx(result, open_Mat, MORPH_OPEN, Mat(5, 5, CV_8U), Point(-1, -1), 1, BORDER_CONSTANT, morphologyDefaultBorderValue());
	 morphologyEx(result, close_Mat, MORPH_CLOSE, Mat(5, 5, CV_8U), Point(-1, -1), 1, BORDER_CONSTANT, morphologyDefaultBorderValue());
	

	imshow("src1", erode_Mat);
	imshow("src2", dilate_Mat);
	imshow("src3", open_Mat);
	imshow("src4", close_Mat);
	imshow("src5", result);

	waitKey(0);
	return 0;
}