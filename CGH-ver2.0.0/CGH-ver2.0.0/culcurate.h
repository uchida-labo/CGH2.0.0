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
	void traditional_method(vector<vector<int>> point_group, vector<vector<vector<int>>>media_point, double wavelength,int mediasize_X,int mediasize_Y,double pixcelpitch);
	void LUT_method(vector<vector<int>> point_group, double wavelength, int mediasize_X, int mediasize_Y, double pixcel_pitch,double apperin_distance);
};