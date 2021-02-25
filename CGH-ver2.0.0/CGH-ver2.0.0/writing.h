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
	void generation(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename);
	void N_generation(vector<vector<double>> writing_inf, int HD_width, int HD_length, int mediasize_X, int mediasize_Y, double harf, string filename, int sepa);
};