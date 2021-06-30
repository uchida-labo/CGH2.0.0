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
					scatterd_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * (point_group[n][0] - media_point[i][m][0]) * pixcelpitch));
					total += scatterd_light_intensity;
				}
				//printf("%d %d %f\n", m,i, total);
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
	int x_max = 0, x_min = 0, y_max = 0, y_min = 0;
	int virtual_media_x_max, virtual_media_x_min, virtual_media_y_max, virtual_media_y_min;

	vector<vector<double>> virtual_media;
	vector<vector<double>> two_dimensions_inf;
	vector<vector<vector<int>>> point_sort{ {{0,0,0}} };

	/*this is point sortingÅ´*/
	point_sort[0][0][0] = point_group[0][0];
	point_sort[0][0][1] = point_group[0][1];
	point_sort[0][0][2] = point_group[0][2];	
	if (x_max < point_group[0][0]) {
		x_max = point_group[0][0];
	}
	else {}
	if (x_min > point_group[0][0]) {
		x_min = point_group[0][0];
	}
	if (y_max < point_group[0][1]) {
		y_max = point_group[0][1];
	}
	if (y_min > point_group[0][1]) {
		y_min = point_group[0][1];
	}
	for (int i = 1; i < point_group.size(); i++) {
		for (int m = 0; m < point_sort.size(); m++) {
			if ((int)(point_group[i][2]) == (int)(point_sort[m][0][2])) {
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

		if (x_max < point_group[i][0]) {
			x_max = point_group[i][0];
		}
		else {}		
		if (x_min > point_group[i][0]) {
			x_min = point_group[i][0];
		}
		if (y_max < point_group[i][1]) {
			y_max = point_group[i][1];
		}
		if (y_min > point_group[i][1]) {
			y_min = point_group[i][1];
		}
	}
/*
	for (int i = 0; i < point_sort.size(); i++) {
		for (int m = 0; m < point_sort[i].size();m++) {
			printf("%d %d %d\n", point_sort[i][m][0], point_sort[i][m][1], point_sort[i][m][2]);
		}
	}
*/
/*this is point sortingÅ™*/

/*this is meking planeÅ´*/
	virtual_media_x_max = (x_min < 0) ? (mediasize_X / 2 - x_min) : mediasize_X / 2;
	virtual_media_x_min = (x_max > 0) ? (-(mediasize_X / 2 + x_max)) : -mediasize_X / 2;
	virtual_media_y_max = (y_min < 0) ? (mediasize_Y / 2 + y_max) : mediasize_Y / 2;
	virtual_media_y_min = (y_max > 0) ? (-mediasize_Y / 2 + y_min) : -mediasize_Y / 2;
	printf("%d %d %d %d\n", virtual_media_x_max, virtual_media_x_min, virtual_media_y_max, virtual_media_y_min);
	writing_inf.resize(mediasize_Y, vector<double>(mediasize_X));
	for (int k = 0; k < point_sort.size(); k++) {
		virtual_media.resize(virtual_media_y_max - virtual_media_y_min);
		for (int i = 0; i < virtual_media_y_max - virtual_media_y_min; i++) {
			virtual_media[i].resize(virtual_media_x_max - virtual_media_x_min);
			for (int m = 0; m < virtual_media_x_max - virtual_media_x_min; m++) {
				if (i >= abs(y_min) + mediasize_Y/ 2) {
					distance = sqrt((pow(virtual_media_x_min + m, 2) + pow(virtual_media_y_max - i, 2) + pow(point_sort[k][0][2], 2)) * pixcel_pitch * pixcel_pitch);
					scattered_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * (virtual_media_x_min + m) * pixcel_pitch));
					virtual_media[i][m] = scattered_light_intensity;
					//printf("%d %d\n", virtual_media_x_min + m, virtual_media_y_max - i);
				}
			}
		}

		for (int i = 0; i < point_sort[k].size(); i++) {
			for (int m = 0; m < mediasize_Y; m++) {
				y = m + abs(y_min) + point_sort[k][i][1];
				for (int n = 0; n < mediasize_X; n++) {
					x = n + abs(x_max) - point_sort[k][i][0];
					//printf("%d %d \n", x, y);
					writing_inf[m][n] += virtual_media[y][x];
				}
			}
		}
	}
}
