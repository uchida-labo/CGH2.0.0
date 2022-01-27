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
	//画像生成
	void generation_DMD(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename);
	//generation_DMDによって生成された画像をN分割
	void N_generation_DMD(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X, int mediasize_Y, double harf, string filename, int sepa);
	//LCOS用の画像生成
	void generation_LCOS(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, string filename);
	//IFTA用の画像生成
	void generation_IFTA(vector<vector<double>> writing_inf, int LCOS_width, int LCOS_height, string filename);
};