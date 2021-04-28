#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img1 = imread("hwfig021.jpg", IMREAD_COLOR); //���� �о img1�� ����
	Mat img2 = Mat(size(img1), CV_8UC3, Scalar(255, 255, 255));  
	//img1�� ��������, 8��Ʈ usignedchar�� �÷���������, ������� �ʱ�ȭ�ϸ� img2 ����
	Point2i pt;
	for (pt.y = 0; pt.y < img1.rows; pt.y++) {
		for (pt.x = 0; pt.x < img1.cols; pt.x++) {
			if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] > 200 //������ ��
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 255, 255);//���������
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] > 100 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] > 100 //����� ������
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 255, 0);//�ʷϻ�����
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] > 200 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] < 50 //�ʷϻ� �ﰢ��
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(255, 0, 0);//�Ķ�������
			}
			else if (img1.at<Vec3b>(pt.y, pt.x)[0] > 100 &&
				img1.at<Vec3b>(pt.y, pt.x)[1] < 50 &&
				img1.at<Vec3b>(pt.y, pt.x)[2] < 50 //�Ķ��� ���簢��
				) {
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(0, 0, 255);//����������
			}
			else { //������
				img2.at<Vec3b>(pt.y, pt.x) = Vec3b(255, 255, 255);//�������
			}
		}
	}
	namedWindow("hwfig01", WINDOW_AUTOSIZE); //������ �̸� ����
	namedWindow("hw2-1", WINDOW_AUTOSIZE); //������ �̸� ����
	imshow("hwfig01", img1); //���� ���
	imshow("hw2-1", img2); //���� ���
	waitKey(0);
}