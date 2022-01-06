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
	vector<vector<double>> copy_writing_inf;
	int miss=0;

	bool intensity = true;
	bool phase = false;

	printf("please input filename\n");
	cin >> filename;
	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch);
	//media.initial_position(0, 0, 0, media.point);

	object.P();
	//object.Ps();
	//object.P_lineX(4, 1);//test:object.P_lineX(400,10);
	//オブジェクトの選択
	//object.cubic(400, 10, 5000);//test：object.cubic(400, 1,5000);//第二変数の最大値は第一変数まで
	//レーザー入射角に関する関数
	object.moving_parallel_transport(set.incident_angle, object.point);
	
	//計算手法について，現在従来手法とLUT法の二つを行い，計算結果に間違いがないかチェックしている
	culcurate.LUT_method(object.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch * 0.000001);
	copy_writing_inf = culcurate.writing_inf;
	culcurate.writing_inf.clear();
	//culcurate.traditional_method_intensity(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch * 0.000001);
	culcurate.traditional_method_phase(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch * 0.000001);
	//grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);
	/*
	for (int i = 0; i < copy_writing_inf.size(); i++) {
		for (int m = 0; m < copy_writing_inf[i].size(); m++) {
			if (copy_writing_inf[i][m] != culcurate.writing_inf[i][m])
				miss++;
		}
	}

	printf("miss %d,miss rate %f\n", miss, (double)miss / (copy_writing_inf.size() * copy_writing_inf[0].size()));
	*/
	//DMD用の画像出力
	//image.generation_DMD(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
	//image.N_generation_DMD(culcurate.writing_inf, set.HD_width, set.HD_length,set.mediasize_X,set.mediasize_Y ,0, filename, 3);
	image.generation_LCOS(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y,filename);
	printf("end");
}