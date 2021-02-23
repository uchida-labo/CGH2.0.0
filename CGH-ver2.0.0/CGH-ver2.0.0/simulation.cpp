#include"simulation.h"

void simulation() {
	printf("hello simulation\n");
	Media media;
	Object object;
	Culcurate culcurate;
	Setting set;
	Image image;
	Grapth grapth;

	string filename;

	printf("please input filename\n");
	cin >> filename;

	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch,set.apperin_distance);
	media.initial_position(0, 0, 0, media.point_inf);
	image.setup(set.mediasize_X, set.mediasize_Y);

	object.P();
	object.initial_position(0, 0, 0, object.point);

	culcurate.traditional_method(object.point, media.point_inf, set.wavelength,set.mediasize_X,set.mediasize_Y);

	grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);
	image.generation(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
}