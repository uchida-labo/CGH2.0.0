#pragma once
#include"context.h"

class Setting {
public:
	int mediasize_X = 1024;//1024*3;
	int mediasize_Y = 768;//768*3;
	double pixcelpitch = 1.0;//um
	int HD_width = 1024;
	int HD_length = 768;

	double wavelength = 532.0;
	double amplitude = 0.5;
	double apperin_distance = 0.005;
	double incident_angle = 0;// 22.5 / 360 * 2 * PI;
	int sepa = 3;//一辺当たりの分割数
};