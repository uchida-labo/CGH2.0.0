#include <iostream>
#include"simulation.h"

int main() {
	printf("hello\n");
	simulation();
}

/* opence test
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = Mat::zeros(100, 100, CV_8UC3);
	imshow("", image);
	waitKey(0);
}
*/

/* matplotlib test
#include <iostream>
#include <matplotlib-cpp/matplotlibcpp.h>
#include <vector> 
using namespace std;
namespace plt = matplotlibcpp;

int main() {
	int n = 1000;
	vector<vector<double>> x, y, z;

	for (double i = -5.0; i < 5.0; i += 1) {
		vector<double> x_row, y_row, z_row;
		for (double m = -5.0; m < 5.0; m += 1) {
			x_row.push_back(i);
			y_row.push_back(m);
			z_row.push_back(hypot(i, m));
		}
		x.push_back(x_row);
		y.push_back(y_row);
		z.push_back(z_row);
	}

	plt::plot_surface(x, y, z);
	plt::show();

	return 0;
}
*/