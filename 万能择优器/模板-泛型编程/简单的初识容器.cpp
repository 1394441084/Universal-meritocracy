#pragma once
#include "��.h"

void Measured_at_the_beginning_of_the_container() {
	vector<int>int1;//װ����int���͵���,���Է�float,���ܷ�char,string,����
	int1.push_back(1);//����������
	int1.push_back(2);//��̬����
	int i1 = 3;
	int i2 = 6;
	int1.push_back(i1);
	int1.push_back(i2);
	//int1.size();�������浱ǰ�ĸ���
	for (int i = 0; i < int1.size(); i++) {
		printf("vector int1 ��%d��Ԫ��:%d\n", i, int1[i]);
	}

	demo d1(10);
	vector<demo>dd;//װ����demo��,ֻ�ܷ�demo��Ķ���
	dd.push_back(d1);
	cout << dd[0].getk() << endl;
}