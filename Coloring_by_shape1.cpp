#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img1 = imread("hwfig021.jpg", IMREAD_COLOR); //영상 읽어서 img1에 저장
	Mat img2 = Mat(size(img1), CV_8UC3, Scalar(255, 255, 255));  
	//img1의 사이즈대로, 8비트 usignedchar인 컬러영상으로, 흰색으로 초기화하며 img2 생성
	Point2i pt;
	for (pt.y = 0; pt.y < img1.rows; pt.y++) {
		for (pt.x = 0; pt.x < img1.cols; pt.x++) {
			if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] > 200 //빨간색 원
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 255, 255);//노란색으로
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] > 100 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] > 100 //노란색 마름모
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 255, 0);//초록색으로
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] > 200 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] < 50 //초록색 삼각형
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(255, 0, 0);//파란색으로
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] > 100 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] < 50 //파란색 직사각형
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 0, 255);//빨간색으로
			}
			else { //나머지
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(255, 255, 255);//흰색으로
			}
		}
	}
	namedWindow("hwfig01", WINDOW_AUTOSIZE); //윈도우 이름 설정
	namedWindow("hw2-1", WINDOW_AUTOSIZE); //윈도우 이름 설정
	imshow("hwfig01", img1); //영상 출력
	imshow("hw2-1", img2); //영상 출력
	waitKey(0);
}