#include"simulation.h"
#include <chrono>

void simulation() {
	printf("hello simulation\n");
	Media media;
	Object object;
	Culcurate culcurate;
	Setting set;
	Image image;
	// Grapth grapth;
	double cubic_size = 1e-3;
	FILE *fp;
	char line[100];
	
	fopen_s(&fp,"G:\\�}�C�h���C�u\\�����f�[�^\\tsuru_mm.txt", "r");
	double x, y, z,x_max=0,y_max=0;

	while(fscanf_s(fp, "%lf,%lf,%lf", &x, &y, &z) != EOF)
	{
		object.point.push_back(vector<double>({x,y,z}));
		if (x > x_max) x_max = x;
		if (y > y_max) y_max = y;
	}

	printf("%d", object.point.size());
	object.initial_position(-x_max/2,
							((double)set.mediasize_Y * set.pixcelpitch / 2.0 * 1e-6) - y_max - 1e-4,
							0,
							object.point);


	string filename;

	printf("please input filename\n");
	cin >> filename;

	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch,set.apperin_distance);
	media.initial_position(0, 0, 0, media.point);

	//object.P();
	//object.cubic(cubic_size, 100);

	//printf("%f\n", ((double)set.mediasize_Y * set.pixcelpitch / 2.0 * 1e-6) - cubic_size);
	/*object.initial_position(-(cubic_size/2.0),
							((double)set.mediasize_Y * set.pixcelpitch / 2.0 * 1e-6) - cubic_size - 1e-4,
							-5.0 * 1e-3,
							object.point);*/

	/*auto itr = media.point.begin();
	for (; itr != media.point.end(); ++itr) {
		auto itr2 = (*itr).begin();
		for (; itr2 != (*itr).end(); ++itr2) {
			printf("%e,%e,%e\n", (*itr2)[0], (*itr2)[1], (*itr2)[2]);
		}
	}*/
	/*auto itr = object.point.begin();
	for (;itr != object.point.end(); ++itr)
	{
		printf("%08e,%08e,%08e\n", (*itr)[0], (*itr)[1], (*itr)[2]);
	}*/
	
	auto start = std::chrono::system_clock::now();

	culcurate.traditional_method(object.point, media, set.wavelength,set.mediasize_X,set.mediasize_Y);
	//culcurate.LUT_method(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch,set.apperin_distance*million);
	//grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);


	auto end = std::chrono::system_clock::now();
	auto dur = end - start;
	printf("\n%d\n", std::chrono::duration_cast<std::chrono::seconds>(dur).count());


	image.generation(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
	//image.N_generation(culcurate.writing_inf, set.HD_width, set.HD_length,set.mediasize_X,set.mediasize_Y ,0, filename, 1);
	printf("end");
}