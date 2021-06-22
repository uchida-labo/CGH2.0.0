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
	//mediaの中心に(0,0,0)点がないので，そこの改良 "ok" 
	//mediaの中心を軸に自由にすることで，光の入射角等の変更に対処
	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch);
	//media.initial_position(0, 0, 0, media.point);

	//objectをmediaから飛び出し距離だけずらす感じにする．"ok"
	//以下の値は全部整数値にしてあげた方がLUT法において楽になるかも"ok"
	object.P();
	//object.cubic(400, 10, 5000);//推奨値：object.cubic(400, 1,5000);
	//object.initial_position(-200, 750, 0, object.point);
	
	//culcurate.traditional_method(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch * 0.000001);
	culcurate.LUT_method(object.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch*0.000001);
	//grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);
	image.generation(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
	image.N_generation(culcurate.writing_inf, set.HD_width, set.HD_length,set.mediasize_X,set.mediasize_Y ,0, filename, 3);
	printf("end");
}