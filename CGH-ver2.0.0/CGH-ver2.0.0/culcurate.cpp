#include"culcurate.h"

void Culcurate::traditional_method(vector<vector<int>> point_group, vector<vector<vector<int>>>media_point, double wavelength, int mediasize_X, int mediasize_Y,double pixcelpitch) {
	printf("hello traditional\n");
	Setting set;
	double scatterd_light_intensity = 0;
	double distance = 0;
	double total = 0;

	writing_inf.resize(mediasize_Y,vector<double>(mediasize_X));
	
	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			for (int n = 0; n < point_group.size(); n++) {
				if (point_group[n][1] >= media_point[i][m][1]) {
					distance = sqrt((((point_group[n][0] - media_point[i][m][0]) * (point_group[n][0] - media_point[i][m][0]) + (point_group[n][1] - media_point[i][m][1]) * (point_group[n][1] - media_point[i][m][1]) + (point_group[n][2] - media_point[i][m][2]) * (point_group[n][2] - media_point[i][m][2])))*pixcelpitch * pixcelpitch);
					scatterd_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * media_point[i][m][0]*pixcelpitch));
					total += scatterd_light_intensity;
				}
			}
			writing_inf[i][m] = total;
			total = 0;
		}
	}
}

void Culcurate::LUT_method(vector<vector<int>> point_group, double wavelength, int mediasize_X, int mediasize_Y, double pixcel_pitch) {
	printf("hello LUTmethod\n");
	Setting set;
	double scattered_light_intensity;
	double distance;
	bool flag = false;
	int num = 0;
	int x, y, x_in;
	int x_max = mediasize_X / 2, x_min = -mediasize_X / 2, y_max = mediasize_Y / 2, y_min = -mediasize_Y / 2;

	vector<vector<vector<double>>> virtual_media;
	vector<vector<double>> two_dimensions_inf;
	vector<vector<vector<int>>> point_sort{ {{0,0,0}} };

	/*this is point sortingÅ´*/
	point_sort[0][0][0] = point_group[0][0];
	point_sort[0][0][1] = point_group[0][1];
	point_sort[0][0][2] = point_group[0][2];
	for (int i = 1; i < point_group.size(); i++) {
		for (int m = 0; m < point_sort.size(); m++) {
			if ((int)(point_group[i][2]) == (int)(point_sort[m][0][2])) {
				//printf("in");
				point_sort[m].resize(point_sort[m].size() + 1);
				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][0]);
				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][1]);
				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][2]);
				flag = true;
			}
		}
		if (flag == false) {
			point_sort.resize(point_sort.size() + 1);
			point_sort[point_sort.size() - 1].resize(1);
			point_sort[point_sort.size() - 1][0].resize(3);
			point_sort[point_sort.size() - 1][0][0] = point_group[i][0];
			point_sort[point_sort.size() - 1][0][1] = point_group[i][1];
			point_sort[point_sort.size() - 1][0][2] = point_group[i][2];
		}
		flag = false;
		if (x_max > point_group[i][0]) {
			x_max = point_group[i][0];
		}
		if (x_min < point_group[i][0]) {
			x_min = point_group[i][0];
		}
		if (y_max > point_group[i][1]) {
			y_max = point_group[i][1];
		}
		if (y_min < point_group[i][1]) {
			y_min = point_group[i][1];
		}
	}

/*this is point sortingÅ™*/

/*this is meking planeÅ´*/
	writing_inf.resize(mediasize_Y, vector<double>(mediasize_X));
	for (int k = 0; k < point_sort.size(); k++) {
		//printf("ininin");
		virtual_media.resize(((mediasize_Y <= y_max - y_min)) ? y_max - y_min : mediasize_Y);
		two_dimensions_inf.resize(((mediasize_Y <= y_max - y_min)) ? y_max - y_min : mediasize_Y);
		for (int i = 0; i < ((mediasize_Y <= y_max - y_min)) ? y_max - y_min : mediasize_Y; i++) {
			virtual_media[i].resize(((mediasize_X <= x_max - x_min)) ? x_max - x_min : mediasize_X);
			two_dimensions_inf[i].resize(((mediasize_X <= x_max - x_min)) ? x_max - x_min : mediasize_X);
			for (int m = 0; m < ((mediasize_X <= x_max - x_min)) ? x_max - x_min : mediasize_X; m++) {
				virtual_media[i][m].resize(3);
				virtual_media[i][m][0] = m;
				virtual_media[i][m][1] = i;
				if (i < (y_max - y_min) / 2) {
					distance = sqrt((m * m + i * i + point_sort[i][m][2] * point_sort[i][m][2]) * pixcel_pitch * pixcel_pitch);
					scattered_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * m * pixcel_pitch * micro));
					virtual_media[i][m][2] = scattered_light_intensity;
				}
			}
		}

		for (int i = 0; i < point_sort[k].size(); i++) {
			y = 1 / 2 * (y_max - y_min - mediasize_Y)+point_sort[k][i][1];
			for (int m = 0; m < mediasize_Y; m++) {
				x = 1 / 2 * (x_max - x_min - mediasize_X) + point_sort[k][i][0];
				for (int n = 0; n < mediasize_X; n++) {
					writing_inf[i][m] = virtual_media[y][x][2];
					x++;
				}
				y++;
			}
		}
		/*
		for (int i = 0; i < point_sort[k].size(); i++) {
			y = mediasize_Y / 2 - point_sort[k][i][1] + 0.1;
			for (int m = 0; m < mediasize_Y; m++) {
				x = mediasize_X / 2 + point_sort[k][i][0];
				x_in = mediasize_X / 2 + point_sort[k][i][0];
				for (int n = 0; n < mediasize_X; n++) {
					if ((x >= 0 && x < mediasize_X) && (y >= 0 && y < mediasize_Y)) {
						if (x != x_in) {
							two_dimensions_inf[y][x] += virtual_media[m][n][3];
						}
						else {
							two_dimensions_inf[y][x] += virtual_media[m][n][3];
						}
					}
					if ((y >= 0 && y < mediasize_Y) && (x_in >= 0 && x_in < mediasize_X)) {
						if (x != x_in) {
							two_dimensions_inf[y][x_in] += virtual_media[m][n][3];
						}
						else {
						}
					}
					x++;
					x_in--;
				}
				y++;
			}
		}
		*/
	}
	/*this is meking planeÅ™*/

	/*this is moveing dataÅ´*/
	
	/*this is moving dataÅ™*/
}
