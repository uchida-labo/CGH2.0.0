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

void Image::N_generation(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X,int mediasize_Y,double harf, string filename, int sepa) {
	image = Mat::zeros(HD_length, HD_width, CV_8UC1);
	static bool flag1,flag2 = true;

	printf("hello N-geeration\n");
	for (int i = 0; i < sepa * sepa; i++) {
		flag1 = true;
		flag2 = true;
		for (int m = i/sepa; m < (HD_length-1) || m < (mediasize_Y-1); m+=sepa) {
			if (mediasize_Y - HD_length > 0 && flag1 == true) {
				m += (mediasize_Y - HD_length) / 2;
				flag1 = false;
			}
			for (int n = i%sepa; n < (HD_width-1) || n < (mediasize_X-1); n+=sepa) {
				if (mediasize_X - HD_width > 0 && flag2 == true) {
					n += (mediasize_X - HD_width) / 2;
					flag2 = false;
				}
				//printf("%d %d\n", m, n);
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
			//printf("out\n");
		}
		string extention = ".bmp";
		imwrite(filename + to_string(i) + extention, image);
	}
}