#include"simulation.h"

void simulation() {
	printf("hello simulation\n");
	Media media;
	Object object;
	Culcurate culcurate;
	Setting set;
	Image image;
	// Grapth grapth;
	double cubic_size = 0.001;


	string filename;

	printf("please input filename\n");
	cin >> filename;

	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch,set.apperin_distance);
	media.initial_position(0, 0, 0, media.point);

	//object.P();
	object.cubic(cubic_size, 1000);

	object.initial_position(-(set.mediasize_X * set.pixcelpitch / 2 *1e-6)+(cubic_size/2), 0.000, 0.000, object.point);

	//culcurate.traditional_method(object.point, media.point, set.wavelength,set.mediasize_X,set.mediasize_Y);
	culcurate.LUT_method(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch,set.apperin_distance*million);
	//grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);
	image.generation(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
	image.N_generation(culcurate.writing_inf, set.HD_width, set.HD_length,set.mediasize_X,set.mediasize_Y ,0, filename, 1);
	printf("end");
}