#pragma once

#include <vector>
#include "context.h"

using namespace std;

enum class axis{x,y,z};

class Object {
protected:
	vector<vector<double>> point;

public:
	void P();
	void P_lineX(double size, int resolution);
	void cubic(double size, double resolution);
	void initial_position(double x, double y, double z, vector<vector<double>> object_position);
	void pushbuck_3dpoints(double x, double y, double z);
	void rotate(double angle, vector<vector<double>> object_position, axis Axis);
	vector<vector<double>> get_points() { return point; };
};

class Media :public Object {
public:
	Media();
	void media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch,double distance);
	void media_criate(int mediasize_X, int mediasize_Y, double pixcel_pitch, double distance, double angle);

	double GetPixelPitch();

private:
	double Pixel_pitch;
};