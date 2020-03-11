#pragma once
#include "类.h"

void Measured_at_the_beginning_of_the_container() {
	vector<int>int1;//装的是int整型的数,可以放float,不能放char,string,类了
	int1.push_back(1);//在最后面添加
	int1.push_back(2);//动态数组
	int i1 = 3;
	int i2 = 6;
	int1.push_back(i1);
	int1.push_back(i2);
	//int1.size();容器里面当前的个数
	for (int i = 0; i < int1.size(); i++) {
		printf("vector int1 中%d的元素:%d\n", i, int1[i]);
	}

	demo d1(10);
	vector<demo>dd;//装的是demo类,只能放demo类的对象
	dd.push_back(d1);
	cout << dd[0].getk() << endl;
}