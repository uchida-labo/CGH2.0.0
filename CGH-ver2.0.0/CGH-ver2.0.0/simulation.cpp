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

	printf("please input filename\n");
	cin >> filename;
	//media�̒��S��(0,0,0)�_���Ȃ��̂ŁC�����̉��� "ok" 
	media.media_criate(set.mediasize_X, set.mediasize_Y, set.pixcelpitch);
	//media.initial_position(0, 0, 0, media.point);

	//object��media�����яo�������������炷�����ɂ���D"ok"
	//�ȉ��̒l�͑S�������l�ɂ��Ă���������LUT�@�ɂ����Ċy�ɂȂ邩��"ok"
	//object.P();
	object.Ps();
	//object.P_lineX(4, 1);//test:object.P_lineX(400,10);
	//object.cubic(400, 10, 5000);//test�Fobject.cubic(400, 1,5000);//���ϐ��̍ő�l�͑��ϐ��܂�
	object.moving_parallel_transport(set.incident_angle, object.point);

	culcurate.traditional_method(object.point, media.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch * 0.000001);
	copy_writing_inf = culcurate.writing_inf;
	culcurate.writing_inf.clear();
	culcurate.LUT_method(object.point, set.wavelength, set.mediasize_X, set.mediasize_Y, set.pixcelpitch*0.000001);
	//grapth.write(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y);

	for (int i = 0; i < copy_writing_inf.size(); i++) {
		for (int m = 0; m < copy_writing_inf[i].size(); m++) {
			if (copy_writing_inf[i][m] != culcurate.writing_inf[i][m])
				miss++;
		}
	}

	printf("miss %d,miss rate %f\n", miss, (double)miss / (copy_writing_inf.size() * copy_writing_inf[0].size()));
	
	image.generation(culcurate.writing_inf, set.mediasize_X, set.mediasize_Y, 0, filename);
	image.N_generation(culcurate.writing_inf, set.HD_width, set.HD_length,set.mediasize_X,set.mediasize_Y ,0, filename, 3);
	printf("end");
}