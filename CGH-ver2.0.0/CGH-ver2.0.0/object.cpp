#include "object.h"

void Object::P() {
	point = { {0.0,0.0,0.0} };
}

void Object::P_lineX(double size, int resolution) {
	point.resize(resolution, vector<double>(3));
	for (int i = 0; i < resolution; i++) {
		point[i][0] = size / resolution * i;
		point[i][1] = 0;
		point[i][2] = 0;	
	}
}

void Object::cubic(double size, double resolution) {
	point.resize(12 * resolution, vector<double>(3));
	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[i * 4 + m][0] = size / resolution * i;
			point[i * 4 + m][1] = size * ((m % 2) ^ (m / 2));
			point[i * 4 + m][2] = -size * (m / 2);
		}
	}
	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[4 * resolution + i * 4 + m][0] = size * ((m % 2) ^ (m / 2));
			point[4 * resolution + i * 4 + m][1] = size / resolution * i;
			point[4 * resolution + i * 4 + m][2] = -size * (m / 2);
		}
	}
	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[2 * 4 * resolution + i * 4 + m][0] = size * ((m % 2) ^ (m / 2));
			point[2 * 4 * resolution + i * 4 + m][1] = size * (m / 2);
			point[2 * 4 * resolution + i * 4 + m][2] = -size / resolution * i;
		}
	}
}

void Object::initial_position(double x, double y, double z, vector<vector<double>> object_position) {

	for (int i = 0; i < object_position.size(); i++) {
		point[i][0] = object_position[i][0] + x;
		point[i][1] = object_position[i][1] + y;
		point[i][2] = object_position[i][2] + z;
	}
}

void Media::media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch,double distance) {
	point.resize(mediasize_Y);
	for (int i = 0; i < mediasize_Y; i++) {
		point[i].resize(mediasize_X);
		for (int m = 0; m < mediasize_X; m++) {
			point[i][m].resize(3);
			point[i][m][0] = ((mediasize_X / 2.0 - m) * pixcel_pitch * micro);
			point[i][m][1] = ((mediasize_Y / 2.0 - i) * pixcel_pitch * micro);
			point[i][m][2] = distance;
		}
	}
}

void Media::initial_position(double x, double y, double z, vector<vector<vector<double>>> point_inf) {
	for (int i = 0; i < point_inf.size(); i++) {
		for (int m = 0; m < point_inf[i].size(); m++) {
			point[i][m][0] = point_inf[i][m][0] + x;
			point[i][m][1] = point_inf[i][m][1] + y;
			point[i][m][2] = point_inf[i][m][2] + z;
		}
	}
}