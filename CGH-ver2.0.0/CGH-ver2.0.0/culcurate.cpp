#include"culcurate.h"
#include <stdlib.h>
#include <omp.h>

double sign(double check) { return signbit(check) == 0 ? -1 : 1; }

void Culcurate::traditional_method(vector<vector<double>> point_group, Media media, double wavelength, int mediasize_X, int mediasize_Y) {
	printf("hello traditional\n");
	Setting set;
	double scatterd_light_intensity = 0;
	double distance = 0;
	double distance_adjacent_x = 0;
	double distance_adjacent_y = 0;
	double total = 0;
	int n = 0;
	unsigned long ser = 0;
	double random_val;
	double kappa = 2 * PI / (wavelength);
	double max_diffraction_angle = wavelength / (2 * media.GetPixelPitch());
	double tan_max_diffraction_angle = tan(max_diffraction_angle);
	double xyPlane_distance, height, xaxis_distance, yaxis_distance;
	double pixel_dis_x = cos(set.incident_angle) * media.GetPixelPitch(),
		   pixel_dis_z = sin(set.incident_angle) * media.GetPixelPitch();
	int last_progress, now_progress;

	vector<vector<double>> media_point = media.get_points();

	writing_inf.resize(mediasize_Y,vector<double>(mediasize_X,0));
	
	vector<double> random_phase;
	srand(point_group.size());

	for (n = 0; n < point_group.size(); n++)
	{
		random_val = (PI/ RAND_MAX)*rand();
		//random_val = 0;
		random_phase.push_back(random_val);
	}

	#pragma omp parallel
	for (int i = 0; i < mediasize_Y; i++) {
		#pragma omp for private(ser,distance, scatterd_light_intensity, xyPlane_distance, height, xaxis_distance, yaxis_distance, n, distance_adjacent_x, distance_adjacent_y)
		for (int m = 0; m < mediasize_X; m++) {
			ser = i * mediasize_X + m;
			for (n = 0; n < point_group.size(); n++) {
				if (point_group[n][1] >= media_point[ser][1]) {

					xaxis_distance = abs(point_group[n][0] - media_point[ser][0]);
					yaxis_distance = abs(point_group[n][1] - media_point[ser][1]);
					height         = abs(point_group[n][2] - media_point[ser][2]);


					distance = sqrt((point_group[n][0] - media_point[ser][0]) * (point_group[n][0] - media_point[ser][0])
								  + (point_group[n][1] - media_point[ser][1]) * (point_group[n][1] - media_point[ser][1])
								  + (point_group[n][2] - media_point[ser][2]) * (point_group[n][2] - media_point[ser][2]));

					distance_adjacent_x = sqrt((xaxis_distance - pixel_dis_x) * (xaxis_distance - pixel_dis_x)
											  + yaxis_distance * yaxis_distance
											  +(height* height));

					distance_adjacent_y = sqrt( xaxis_distance * xaxis_distance
											  +(yaxis_distance - (media.GetPixelPitch())) * (yaxis_distance - (media.GetPixelPitch()))
									  		  +(height * height));

					if(abs((distance - distance_adjacent_x) / (media.GetPixelPitch() ) + set.incident_angle * sign(point_group[n][0] - media_point[ser][0])) <= max_diffraction_angle){
					if(abs((distance - distance_adjacent_y) / (media.GetPixelPitch() )) <= max_diffraction_angle) {
							scatterd_light_intensity = (1 / distance) * cos(kappa * (distance - sin(set.incident_angle) * media_point[ser][0]) + random_phase[n]);
							writing_inf[i][m] += scatterd_light_intensity;
					}
					}
				}
			}
		}
		#pragma omp barrier
		#pragma omp single
		{	
			now_progress = (int)((double)(i + 1) / (double)mediasize_Y * 100.0);
			if (now_progress != last_progress)
			{
				printf("\rworking...%d%%", (int)((double)(i + 1) / (double)mediasize_Y * 100.0));
				last_progress = now_progress;
			}
		}
	}
}

void Culcurate::LUT_method(vector<vector<double>> point_group, vector<vector<vector<double>>> media_point, double wavelength, int mediasize_X, int mediasize_Y, double pixcel_pitch,double apperin_distance) {
//	printf("hello LUTmethod\n");
//	Setting set;
//	double scattered_light_intensity;
//	double distance;
//	bool flag = false;
//	int num = 0;
//	int x, y, x_in;
//
//	vector<vector<vector<double>>> virtual_media;
//	vector<vector<double>> two_dimensions_inf;
//	vector<vector<vector<double>>> point_sort{ {{0,0,0}} };
//
//	/*this is point sortingÅ´*/
//	point_sort[0][0][0] = point_group[0][0] / (pixcel_pitch * micro);
//	point_sort[0][0][1] = point_group[0][1] / (pixcel_pitch * micro);
//	point_sort[0][0][2] = point_group[0][2] / (pixcel_pitch * micro);
//	for (int i = 1; i < point_group.size(); i++) {
//		for (int m = 0; m < point_sort.size(); m++) {
//			if ((int)(point_group[i][2] * 1000000) == (int)(point_sort[m][0][2])) {
//				//printf("in");
//				point_sort[m].resize(point_sort[m].size() + 1);
//				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][0] / (pixcel_pitch * micro));
//				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][1] / (pixcel_pitch * micro));
//				point_sort[m][point_sort[m].size() - 1].insert(point_sort[m][point_sort[m].size() - 1].end(), point_group[i][2] / (pixcel_pitch * micro));
//				flag = true;
//			}
//		}
//		if (flag == false) {
//			point_sort.resize(point_sort.size() + 1);
//			point_sort[point_sort.size() - 1].resize(1);
//			point_sort[point_sort.size() - 1][0].resize(3);
//			point_sort[point_sort.size() - 1][0][0] = point_group[i][0] / (pixcel_pitch * micro);
//			point_sort[point_sort.size() - 1][0][1] = point_group[i][1] / (pixcel_pitch * micro);
//			point_sort[point_sort.size() - 1][0][2] = point_group[i][2] / (pixcel_pitch * micro);
//		}
//		flag = false;
//	}
//
///*this is point sortingÅ™*/
//
///*this is meking planeÅ´*/
//	writing_inf.resize(3);
//	for (int k = 0; k < point_sort.size(); k++) {
//		//printf("ininin");
//		virtual_media.resize(mediasize_Y);
//		two_dimensions_inf.resize(mediasize_Y);
//		for (int i = 0; i < mediasize_Y; i++) {
//			virtual_media[i].resize(mediasize_X);
//			two_dimensions_inf[i].resize(mediasize_X);
//			for (int m = 0; m < mediasize_X; m++) {
//				virtual_media[i][m].resize(4);
//				virtual_media[i][m][0] = m;
//				virtual_media[i][m][1] = i;
//				virtual_media[i][m][2] = apperin_distance - point_sort[k][0][2];
//
//				distance = sqrt((m * m + i * i + virtual_media[i][m][2] * virtual_media[i][m][2]) * pixcel_pitch * micro * pixcel_pitch * micro);
//				scattered_light_intensity = (1 / distance) * cos(2 * PI / (wavelength * nano) * (distance - sin(set.incident_angle) * m * pixcel_pitch * micro));
//				virtual_media[i][m][3] = scattered_light_intensity;
//			}
//		}
//
//		for (int i = 0; i < point_sort[k].size(); i++) {
//			y = mediasize_Y / 2 - point_sort[k][i][1] + 0.1;
//			for (int m = 0; m < mediasize_Y; m++) {
//				x = mediasize_X / 2 + point_sort[k][i][0];
//				x_in = mediasize_X / 2 + point_sort[k][i][0];
//				for (int n = 0; n < mediasize_X; n++) {
//					if ((x >= 0 && x < mediasize_X) && (y >= 0 && y < mediasize_Y)) {
//						if (x != x_in) {
//							two_dimensions_inf[y][x] += virtual_media[m][n][3];
//						}
//						else {
//							two_dimensions_inf[y][x] += virtual_media[m][n][3];
//						}
//					}
//					if ((y >= 0 && y < mediasize_Y) && (x_in >= 0 && x_in < mediasize_X)) {
//						if (x != x_in) {
//							two_dimensions_inf[y][x_in] += virtual_media[m][n][3];
//						}
//						else {
//						}
//					}
//					x++;
//					x_in--;
//				}
//				y++;
//			}
//		}
//	}
//	/*this is meking planeÅ™*/
//
//	/*this is moveing dataÅ´*/
//	writing_inf.resize(mediasize_Y, vector<double>(mediasize_X));
//	
//	for (int i = 0; i < mediasize_Y; i++) {
//		writing_inf[i].resize(mediasize_X);
//		for (int m = 0; m < mediasize_X; m++) {
//			writing_inf[i][m] = two_dimensions_inf[i][m];
//		}
//	}
//	/*this is moving dataÅ™*/
}
