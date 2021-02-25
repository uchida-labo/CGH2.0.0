#include "writing.h"

void Image::generation(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename) {
	printf("hello writing\n");
	image = Mat::zeros(mediasize_Y, mediasize_X, CV_8UC1);
	//printf("%d %d", writing_inf.size(), writing_inf[0].size());
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

void Image::N_generation(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X,int mediasize_Y,double harf, string filename, int sepa) {
	image = Mat::zeros(HD_length, HD_width, CV_8UC1);
	static bool flag1,flag2 = true;

	printf("hello N-geeration\n");

	if ((mediasize_X > HD_width) && (mediasize_Y > HD_length)) {//case1
		printf("case1");
		for (int i = 0; i < sepa * sepa; i++) {
			for (int m = i / sepa; m < HD_length; m += sepa) {
				for (int n = i % sepa; n < (sepa - 1 + (mediasize_X - HD_width) / 2 + HD_width) ; n += sepa) {
					//printf("%d\n",n);
					if (m + sepa - 1 < HD_length && n + sepa - 1 < HD_width) {
						if (writing_inf[m][n] > harf) {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa, n + o % sepa) = 255;
							}
						}
						else {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa, n + o % sepa) = 0;
							}
						}
					}
				}
			}
			string extention = ".bmp";
			imwrite(filename + to_string(i) + extention, image);
			image.zeros(HD_length, HD_width, CV_8UC1);
		}
	}
	else if ((mediasize_X > HD_width) && (mediasize_Y <= HD_length)) {//case2
		printf("case2");
		for (int i = 0; i < sepa * sepa; i++) {
			for (int m = i / sepa; m < mediasize_Y; m += sepa) {
				for (int n = i % sepa; n < (i % sepa + (mediasize_X - HD_width) / 2 + HD_width); n += sepa) {
					if (m + sepa - 1 < HD_length && n + sepa - 1 < HD_width) {
						if (writing_inf[m][n] > harf) {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa + (HD_length - mediasize_Y) / 2, n + o % sepa) = 255;
							}
						}
						else {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa + (HD_length - mediasize_Y) / 2, n + o % sepa) = 0;
							}
						}
					}
				}
			}
			string extention = ".bmp";
			imwrite(filename + to_string(i) + extention, image);
			image.zeros(HD_length, HD_width, CV_8UC1);
		}
	}
	else if ((mediasize_X <= HD_width) && (mediasize_Y > HD_length)) {//case3
		printf("case3");
		for (int i = 0; i < sepa*sepa; i++) {
			for (int m = i / sepa; m < HD_length; m += sepa) {
				for (int n = i % sepa; n < mediasize_X; n += sepa) {
					if (m + sepa - 1 < HD_length && n + sepa - 1 < HD_width) {
						if (writing_inf[m][n] > harf) {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa, n + o % sepa + (HD_width - mediasize_X) / 2) = 255;
							}
						}
						else {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa, n + o % sepa + (HD_width - mediasize_X) / 2) = 0;
							}
						}
					}
				}
			}
			string extention = ".bmp";
			imwrite(filename + to_string(i) + extention, image);
			image.zeros(HD_length, HD_width, CV_8UC1);
		}
	}
	else if ((mediasize_X <= HD_width) && (mediasize_Y <= HD_length)) {//case4
		printf("case4");
		for (int i = 0; i < sepa * sepa; i++) {
			for (int m = i / sepa; m < mediasize_Y; m += sepa) {
				for (int n = i % sepa; n < mediasize_X; n += sepa) {
					if (m + sepa - 1 < HD_length && n + sepa - 1 < HD_width) {
						if (writing_inf[m][n] > harf) {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa + (HD_length - mediasize_Y) / 2, n + o % sepa + (HD_width - mediasize_X) / 2) = 255;
							}
						}
						else {
							for (int o = 0; o < sepa * sepa; o++) {
								image.at<uchar>(m + o / sepa + (HD_length - mediasize_Y) / 2, n + o % sepa + (HD_width - mediasize_X) / 2) = 0;
							}
						}
					}
				}
			}
			string extention = ".bmp";
			imwrite(filename + to_string(i) + extention, image);
			image.zeros(HD_length, HD_width, CV_8UC1);
		}
	}
}