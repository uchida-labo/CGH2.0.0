#pragma once

class Setting {
public:
	double pixcelpitch = 7.0 * 1e-3;//13.68 / 12 * 1e-3;		//um�Ŏw��
	int mediasize_X = 5500 / 7.0;//(13.68/12);	//�s�N�Z����
	int mediasize_Y = 4500 / 7.0;//(13.68/12);	//�s�N�Z����
	int HD_width = 1024;
	int HD_length = 768;

	double wavelength = 532.0 * 1e-6;
	double amplitude = 0.5;
	double apperin_distance = 0.0;
	double incident_angle = -22.5*3.14159265358979/180;
	int sepa = 1;//��ӓ�����̕�����
};