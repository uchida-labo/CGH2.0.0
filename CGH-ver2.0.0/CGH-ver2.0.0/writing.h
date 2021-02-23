#pragma once
#include <vector>
#include<opencv2/opencv.hpp>

#include "context.h"

using namespace cv;
using namespace std;

class Image {
public:
	Mat image;
	void setup(int rows, int cols);
	void generation(vector<vector<double>> writing_inf, int mediasize_X, int mediasize_Y, double harf, string filename);
};