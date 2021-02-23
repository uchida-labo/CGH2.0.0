#include "writing.h"

void Image::setup(int rows, int cols) {
	image = Mat::zeros(rows, cols, CV_8UC1);
}

void Image::generation(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename) {
	printf("hello writing\n");
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			if (writing_inf[i][m] > harf) {
				image.at<uchar>(i, m) = 255;
			}
			else {
				image.at<uchar>(i, m) = 0;
			}
		}
	}
	imshow("", image);
	waitKey(0);

	string extention = ".bmp";
	imwrite(filename + extention, image);
}