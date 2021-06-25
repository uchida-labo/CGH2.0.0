#pragma once

#include <vector>
#include <math.h>
#include "context.h"

using namespace std;

class Object {
public:
	void P();
	void P_lineX(int size, int resolution,int distance);
	void cubic(int size, int resolution,int distance);
	void initial_position(double x, double y, double z, vector<vector<int>> object_position);
	void moving_parallel_transport(double incident_angle, vector<vector<int>> object_position);
	vector<vector<int>> point;
};

class Media {
public:
	void media_criate(int mediasize_X, int mediasize_Y, int pixcel_pitch);

	vector<vector<vector<int>>> point;
	void initial_position(int x, int y, int z, vector<vector<vector<int>>> point_inf);

};