#include "object.h"

void Object::P() {//
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

void Object::cubic(int size, int resolution,int distance) {
	resolution += 1;
	point.resize(8 + 12 * (resolution-1), vector<double>(3));
	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[4 * i + m][0] = pow(-1,((m % 2) ^ (m / 2))) * (size / 2 - (size / resolution * i) * ((m+1) % 2));
			point[4 * i + m][1] = pow(-1,m / 2)* (size / 2 - (size / resolution * i) * (m % 2));
			point[4 * i + m][2] = distance;
		}
	}

	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[4 * resolution + 4 * i + m][0] = pow(-1, ((m % 2) ^ (m / 2))) * (size / 2 - (size / resolution * i) * ((m + 1) % 2));
			point[4 * resolution + 4 * i + m][1] = pow(-1, m / 2) * (size / 2 - (size / resolution * i) * (m % 2));
			point[4 * resolution + 4 * i + m][2] = distance + size;
		}
	}

	for (int i = 0; i < resolution-1; i++) {
		printf("in");
		for (int m = 0; m < 4; m++) {
			point[2 * 4 * resolution + 4 * i + m][0] = pow(-1, ((m % 2) ^ (m / 2))) * (size / 2);
			point[2 * 4 * resolution + 4 * i + m][1] = pow(-1, m / 2) * (size / 2);
			point[2 * 4 * resolution + 4 * i + m][2] = distance + size / resolution * (i+1);
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

void Media::media_criate(int mediasize_X, int mediasize_Y, int pixcel_pitch) {
	point.resize(mediasize_Y);
	for (int i = 0; i < mediasize_Y; i++) {
		point[i].resize(mediasize_X);
		for (int m = 0; m < mediasize_X; m++) {
			point[i][m].resize(3);
			point[i][m][0] = (-((double)mediasize_X / 2) + m) * (double)pixcel_pitch * micro;
			point[i][m][1] = ((double)mediasize_Y / 2 - i) * (double)pixcel_pitch * micro;
			point[i][m][2] = 0;
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