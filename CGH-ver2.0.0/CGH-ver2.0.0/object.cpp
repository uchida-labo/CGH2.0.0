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

void Object::rotate(double angle, vector<vector<double>> object_position, axis Axis) {
	vector<vector<double>> rotate_array(3, vector<double>(3));
	switch (Axis) {
		case axis::x:
			rotate_array = {{1,          0,          0},
							{0, cos(angle), sin(angle)},
							{0,-sin(angle), cos(angle)}};
			break;
		case axis::y:
			rotate_array = {{cos(angle), 0, -sin(angle)},
							{		  0, 1,           0},
							{sin(angle), 0,  cos(angle)}};
			break;
		case axis::z:
			rotate_array = {{ cos(angle), sin(angle), 0},
							{-sin(angle), cos(angle), 0},
						    {          1,          0, 1}};
			break;
	}

	for (int i = 0; i < object_position.size(); i++) {
		for (int dim = 0; dim < 3; dim++) {
			point[i][dim] = object_position[i][0] * rotate_array[dim][0] +
							object_position[i][1] * rotate_array[dim][1] +
							object_position[i][2] * rotate_array[dim][2];
		}
	}
}

Media::Media() :Pixel_pitch(0) {}

double Media::GetPixelPitch() { return Pixel_pitch; }

void Media::media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch,double distance) {
	Pixel_pitch = pixcel_pitch;
	unsigned long pointnum = 0;
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			point.emplace_back();
			point[pointnum].push_back((mediasize_X / 2.0 - m) * pixcel_pitch);
			point[pointnum].push_back((mediasize_Y / 2.0 - i) * pixcel_pitch);
			point[pointnum].push_back(distance);

			pointnum++;
		}
	}
}

void Media::media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch, double distance, double angle) {
	Pixel_pitch = pixcel_pitch;
	long pointnum = 0;
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			point.emplace_back();
			point[pointnum].push_back((mediasize_X / 2.0 - m) * pixcel_pitch * cos(angle));
			point[pointnum].push_back((mediasize_Y / 2.0 - i) * pixcel_pitch);
			point[pointnum].push_back(((mediasize_X / 2.0 - m) * pixcel_pitch * sin(angle)) + distance);

			pointnum++;
		}
	}
}