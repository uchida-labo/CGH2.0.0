#pragma once

class Setting {
public:
	int mediasize_X = 4400 / (13.68/12);	//ピクセル数
	int mediasize_Y = 3000 / (13.68/12);	//ピクセル数
	double pixcelpitch = 13.68 / 12 * 1e-3;		//umで指定
	int HD_width = 1024;
	int HD_length = 768;

	double wavelength = 532.0 * 1e-6;
	double amplitude = 0.5;
	double apperin_distance = 0.000;
	double incident_angle = -0*3.141592653589793/180.0;
	int sepa = 1;//一辺当たりの分割数
};