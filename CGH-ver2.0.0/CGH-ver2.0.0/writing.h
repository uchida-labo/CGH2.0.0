#pragma once
#include <vector>
#include<opencv2/opencv.hpp>
#include<iostream>

#include "context.h"

using namespace cv;
using namespace std;

class Image {
public:
	Mat image;
	//�摜����
	void generation_DMD(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename);
	//generation_DMD�ɂ���Đ������ꂽ�摜��N����
	void N_generation_DMD(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X, int mediasize_Y, double harf, string filename, int sepa);
	//LCOS�p�̉摜����
	void generation_LCOS(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, string filename);
};