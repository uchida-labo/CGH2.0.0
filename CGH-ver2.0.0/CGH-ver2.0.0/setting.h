#pragma once

class Setting {
public:
	int mediasize_X = 2000 / (13.68/8);	//�s�N�Z����
	int mediasize_Y = 2000 / (13.68/8);	//�s�N�Z����
	double pixcelpitch = 13.68 / 8;		//um�Ŏw��
	int HD_width = 1024;
	int HD_length = 768;

	double wavelength = 532.0;
	double amplitude = 0.5;
	double apperin_distance = 0.000;
	double incident_angle = 0;
	int sepa = 1;//��ӓ�����̕�����
};