#include"grapth.h"

void Grapth::write(vector<vector<double>> writing_inf,int mediasize_X,int mediasize_Y) {
	vector<vector<double>> x, y, z;
	printf("hello grapth\n");
	for (int i = mediasize_X*2/8; i < mediasize_X*6/8; i++) {
		vector<double> x_row, y_row, z_row;
		for (int m = mediasize_Y*2/8; m<mediasize_Y*6/8; m++) {
			x_row.push_back(i);
			y_row.push_back(m);
			z_row.push_back(writing_inf[m][i]);
		}
		x.push_back(x_row);
		y.push_back(y_row);
		z.push_back(z_row);
	}
	plt::plot_surface(x, y, z);
	plt::show();
}
