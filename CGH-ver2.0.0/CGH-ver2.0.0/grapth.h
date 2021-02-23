#pragma once
#include <vector>
#include <matplotlib-cpp/matplotlibcpp.h>
#include "context.h"
#include"setting.h"

using namespace std;
namespace plt = matplotlibcpp;

class Grapth {
public:
	void write(vector<vector<double>> writing_inf,int mediasize_X,int mediasize_Y);

};