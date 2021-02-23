#include"culcurate.h"

void Culcurate::traditional_method(vector<vector<double>> point_group, vector<vector<vector<double>>>media_point, double wavelength, int mediasize_X, int mediasize_Y) {
	printf("hello traditional\n");
	Setting set;
	double scatterd_light_intensity = 0;
	double distance = 0;
	double total = 0;


	writing_inf.resize(3, vector<double>(media_point.size() * media_point[0].size()));

	for (int i = 0; i < mediasize_Y; i++) {
		for (int m = 0; m < mediasize_X; m++) {
			for (int n = 0; n < point_group.size(); n++) {
				if (point_group[n][1] >= media_point[i][m][1]) {
					distance = sqrt((point_group[n][0] - media_point[i][m][0]) * (point_group[n][0] - media_point[i][m][0]) + (point_group[n][1] - media_point[i][m][1]) * (point_group[n][1] - media_point[i][m][1]) + (point_group[n][2] - media_point[i][m][2]) * (point_group[n][2] - media_point[i][m][2]));
					scatterd_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * media_point[i][m][0]));
					total += scatterd_light_intensity;
				}
			}
			writing_inf[i][m] = total;
			total = 0;
		}
	}
}
