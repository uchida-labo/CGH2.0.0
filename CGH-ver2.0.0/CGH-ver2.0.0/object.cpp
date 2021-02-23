#include "object.h"

void Object::P() {
	point = { {0.0,0.0,0.0} };
}

void Object::initial_position(double x, double y, double z, vector<vector<double>> object_position) {

	for (int i = 0; i < object_position[0].size(); i++) {
		point[i][0] = object_position[i][0] + x;
		point[i][1] = object_position[i][1] + y;
		point[i][2] = object_position[i][2] + z;
	}
}


void Media::media_criate(int mediasize_X, int mediasize_Y, int pixcel_pitch,double distance) {
	point_inf.resize(mediasize_Y);
	for (int i = 0; i < mediasize_Y; i++) {
		point_inf[i].resize(mediasize_X);
		for (int m = 0; m < mediasize_X; m++) {
			point_inf[i][m].resize(3);
			point_inf[i][m][0] = (-((double)mediasize_X / 2) + m) * (double)pixcel_pitch * micro;
			point_inf[i][m][1] = ((double)mediasize_Y / 2 - i) * (double)pixcel_pitch * micro;
			point_inf[i][m][2] = distance;
		}
	}
}

void Media::initial_position(double x, double y, double z, vector<vector<vector<double>>> point_inf) {
	for (int i = 0; i < point_inf.size(); i++) {
		for (int m = 0; m < point_inf[i].size(); m++) {
			point_inf[i][m][0] = point_inf[i][m][0] + x;
			point_inf[i][m][1] = point_inf[i][m][1] + y;
			point_inf[i][m][2] = point_inf[i][m][2] + z;
		}
	}
}