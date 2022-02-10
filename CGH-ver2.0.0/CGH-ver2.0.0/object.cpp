#include "object.h"

void Object::P() {//
	point = { {0,0,5000} };
}

void Object::Ps() {
	point = { {0,0,5000}, {300,0,5000} ,{0,300,5000} ,{1000,1000,50} };
}

void Object::P_lineX(int size, int resolution) {
	point.resize(resolution, vector<int>(3));
	for (int i = 0; i < resolution; i++) {
		point[i][0] = size / resolution * i;
		point[i][1] = 0;
		point[i][2] = 0;	
	}
}

void Object::cubic(int size, int resolution,int distance) {
	point.resize(8 + 12 * (resolution-1), vector<int>(3));
	for (int i = 0; i < resolution; i++) {
		for (int m = 0; m < 4; m++) {
			point[4 * i + m][0] = pow(-1, ((m % 2) ^ (m / 2))) * (size / 2 - (size / resolution * i) * ((m + 1) % 2));
			point[4 * i + m][1] = pow(-1, m / 2) * (size / 2 - (size / resolution * i) * (m % 2));
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
		for (int m = 0; m < 4; m++) {
			point[2 * 4 * resolution + 4 * i + m][0] = pow(-1, ((m % 2) ^ (m / 2))) * (size / 2);
			point[2 * 4 * resolution + 4 * i + m][1] = pow(-1, m / 2) * (size / 2);
			point[2 * 4 * resolution + 4 * i + m][2] = distance + size / resolution * (i+1);
		}
	}
}

void Object::initial_position(double x, double y, double z, vector<vector<int>> object_position) {

	for (int i = 0; i < object_position.size(); i++) {
		point[i][0] = object_position[i][0] + x;
		point[i][1] = object_position[i][1] + y;
		point[i][2] = object_position[i][2] + z;
	}
}

void Object::moving_parallel_transport(double incident_angle, vector<vector<int>> object_position) {
	for (int i = 0; i < object_position.size(); i++) {
		point[i][0] = object_position[i][0] + (int)(object_position[i][2] * sin(incident_angle));
		point[i][2] = object_position[i][2] - (int)(object_position[i][2] * sin(incident_angle) * tan(incident_angle));
		//printf("%d %d \n", point[i][0], point[i][2]);
	}
}

void Object::H() {
	printf("Hin\n");
	Setting set;
	point.resize(set.Object_height * set.Object_width, vector<int>(1));

	for (int i = 0; i < set.Object_height * set.Object_width; i++) {
		point[i][0] = 0;
	}

	for (int m = 25; m < 125; m++) {
		for (int i = 25; i < 50; i++) {
			point[i + m * set.Object_width][0] = 1;		
		}
	}

	for (int m = 25; m < 125; m++) {
		for (int i = 100; i < 125; i++) {
			point[i + m * set.Object_width][0] = 1;
		}
	}

	for (int m = 60; m < 90; m++) {
		for (int i = 50; i < 100; i++) {
			point[i + m * set.Object_width][0] = 1;
		}
	}

	for (int i = 0; i < set.Object_height; i+=5) {
		for (int m = 0; m < set.Object_width; m+=5) {
			printf("%d", point[m + i * set.Object_width][0]);
		}
		printf("\n");
	}
}

void Media::media_criate(int mediasize_X, int mediasize_Y, int pixcel_pitch) {
	point.resize(mediasize_Y);
	for (int i = 0; i < mediasize_Y; i++) {
		point[i].resize(mediasize_X);
		for (int m = 0; m < mediasize_X; m++) {
			point[i][m].resize(3);
			point[i][m][0] = (-mediasize_X / 2 + m);
			point[i][m][1] = (mediasize_Y / 2 - i);
			point[i][m][2] = 0;
		}
	}
}

void Media::initial_position(int x, int y, int z, vector<vector<vector<int>>> point_inf) {
	for (int i = 0; i < point_inf.size(); i++) {
		for (int m = 0; m < point_inf[i].size(); m++) {
			point[i][m][0] = point_inf[i][m][0] + x;
			point[i][m][1] = point_inf[i][m][1] + y;
			point[i][m][2] = point_inf[i][m][2] + z;
		}
	}
}