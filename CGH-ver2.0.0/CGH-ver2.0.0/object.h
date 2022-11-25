#pragma once

#include <vector>
#include "context.h"

using namespace std;

class Object {
public:
	void P();
	void P_lineX(double size, int resolution);
	void cubic(double size, double resolution);
	void initial_position(double x, double y, double z, vector<vector<double>> object_position);
	vector<vector<double>> point;
};

class Media {
public:
	Media();
	void media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch,double distance);

	vector<vector<vector<double>>> point;
	void initial_position(double x, double y, double z, vector<vector<vector<double>>> point_inf);
	double GetPixelPitch();

private:
	double Pixel_pitch;
};