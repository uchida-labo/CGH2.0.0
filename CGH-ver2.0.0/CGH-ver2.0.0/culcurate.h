#pragma once
#include <vector>
#include <math.h>
#include <time.h>
#include"context.h"
#include"setting.h"

using namespace std;

class Culcurate {
public:
	vector<vector<double>> writing_inf;
	void traditional_method(vector<vector<double>> point_group, vector<vector<vector<double>>>media_point, double wavelength,int mediasize_X,int mediasize_Y);
	void LUT_method(vector<vector<double>> point_group, vector<vector<vector<double>>> media_point, double wavelength, int mediasize_X, int mediasize_Y, double pixcel_pitch);
};