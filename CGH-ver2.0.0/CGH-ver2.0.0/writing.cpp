#include "writing.h"

void Image::generation_DMD(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename) {
	printf("hello writing\n");
	image = Mat::zeros(mediasize_Y, mediasize_X, CV_8UC3);
	//printf("%d %d", writing_inf.size(), writing_inf[0].size());
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			if (writing_inf[i][m] > harf) {
				for (int n = 0; n < 3; n++) {
					image.at<Vec3b>(i, m)[n] = 255;
				}
			}
			else {
				for (int n = 0; n < 3; n++) {
					image.at<Vec3b>(i, m)[n] = 0;
				}
			}
		}
	}
	imshow("", image);
	waitKey(0);

	string extention = ".bmp";
	imwrite(filename + extention, image);
}

void Image::N_generation_DMD(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X,int mediasize_Y,double harf, string filename, int sepa) {
	image = Mat::zeros(HD_length, HD_width, CV_8UC3);
	static bool flag1,flag2 = true;

	printf("hello N-geeration\n");

	if ((mediasize_X > HD_width) && (mediasize_Y > HD_length)) {//case1
		printf("case1");
		for (int i = 0; i < sepa * sepa; i++) {
			for (int m = 0; m < HD_length-1;m ++) {
				for (int n = 0; n < HD_width-1; n++) {
					//printf("%d\n",n);
					if ((m * sepa +i/sepa) < mediasize_Y && (n * sepa + i % sepa) < mediasize_X) {
						if (writing_inf[(m * sepa + i / sepa) ][(n * sepa + i % sepa)] > harf) {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 255;
							}
						}
						else {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 0;
							}
						}
					}
				}
			}
			string extention = ".bmp";
			imwrite(filename + to_string(i) + extention, image);
			image.zeros(HD_length, HD_width, CV_8UC3);
		}
	}
	else if ((mediasize_X > HD_width) && (mediasize_Y <= HD_length)) {//case2
		printf("case2");
		for (int i = 0; i < sepa * sepa; i++) {
			for (int m = i / sepa; m < mediasize_Y; m++) {
				for (int n = i % sepa; n < (i % sepa + (mediasize_X - HD_width) / 2 + HD_width); n++) {
					if ((m + i / sepa) * sepa < mediasize_Y && (n + i % sepa) * sepa < mediasize_X) {
						if (writing_inf[(m + i / sepa) * sepa][(n + i % sepa) * sepa] > harf) {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 255;
							}
						}
						else {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 0;
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
			for (int m = i / sepa; m < HD_length; m++) {
				for (int n = i % sepa; n < mediasize_X; n++) {
					if ((m + i / sepa) * sepa < mediasize_Y && (n + i % sepa) * sepa < mediasize_X) {
						if (writing_inf[(m + i / sepa) * sepa][(n + i % sepa) * sepa] > harf) {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 255;
							}
						}
						else {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 0;
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
			for (int m = i / sepa; m < mediasize_Y; m++) {
				for (int n = i % sepa; n < mediasize_X; n++) {
					if ((m + i / sepa) * sepa < mediasize_Y && (n + i % sepa) * sepa < mediasize_X) {
						if (writing_inf[(m + i / sepa) * sepa][(n + i % sepa) * sepa] > harf) {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 255;
							}
						}
						else {
							for (int o = 0; o < 3; o++) {
								image.at<Vec3b>(m, n)[o] = 0;
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

void Image::generation_LCOS(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, string filename) {
	printf("hello writing\n");
	image = Mat::zeros(mediasize_Y, mediasize_X, CV_8UC3);
	//printf("%d %d", writing_inf.size(), writing_inf[0].size());
	double Max=0;
	double Min=0;

	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			if (Max < writing_inf[i][m]) Max = writing_inf[i][m];
			if (Min > writing_inf[i][m]) Min = writing_inf[i][m];
		}
	}
	printf("%f %f\n", Max, Min);
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			for (int n = 0; n < 3; n++) {
				image.at<Vec3b>(i, m)[n] = (writing_inf[i][m] - Min) * (256 / (Max-Min));
			}
		}
	}

	imshow("", image);
	waitKey(0);

	string extention = ".bmp";
	imwrite(filename + extention, image);
}