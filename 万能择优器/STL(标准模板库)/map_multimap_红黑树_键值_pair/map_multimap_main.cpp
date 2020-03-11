#include <map>  //标准的关联式容器，一个map里存储的元素是一个键值对序列，叫做(key,value)键值对。它提供基于key快速检索数据的能力。
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
void map_multimap概述();
void map的插入和迭代器();
void map排序_赋值_大小_删除();
void map查找();
int main(void) {
	//map_multimap概述();
	//map的插入和迭代器();
	//map排序_赋值_大小_删除();
	map查找();
	system("pause");
	return 0;
}

void map_multimap概述() {
	while (1) {
		map<int, string> mapstu;
		mapstu.insert(pair<int, string>(1, "张三"));
		mapstu.insert(pair<int, string>(2, "李四"));
		mapstu.insert(pair<int, string>(3, "屌丝"));
		//mapstu.insert(pair<int, string>(4, "挂逼"));//Key值是唯一的,集合中的元素都按一定顺序排序
		mapstu[4] = "老刘";//赋值

		for (map<int, string>::iterator it = mapstu.begin(); it != mapstu.end(); it++) {
			cout << "Key:" << (*it).first << " Value:" << (*it).second << endl;//红黑树变体排序
			 //支持[]操作
		}
		//multimap支持相同key值,不支持[]操作,用法和map一样

		break;
	}
}

void map的插入和迭代器() {
	map<int, string> mapstu;

	pair<map<int, string>::iterator, bool> ret=mapstu.insert(pair<int, string>(1, "张三"));//插入方式一
	ret.second == true ? cout << "插入成功! value:" << (*(ret.first)).second << endl : cout << "插入失败! value: \n";

	ret = mapstu.insert(pair<int, string>(1, "张捌"));//如果key值存在,则插入失败,使用insert
	ret.second ? cout << "插入成功! value:" << (*(ret.first)).second << endl : cout << "插入失败! value: \n";

	ret=mapstu.insert(make_pair(2, "张si"));//插入方式二
	ret.second == true ? cout << "插入成功! value:" << (*(ret.first)).second << endl : cout << "插入失败! value: \n";

	ret=mapstu.insert(map<int, string>::value_type(3, "屌丝"));//插入方式三,value_type(类型定义)相当于pair
	ret.second == true ? cout << "插入成功! value:" << (*(ret.first)).second << endl : cout << "插入失败! value: \n";

	mapstu[4] = "老刘";//插入方式四
	mapstu[4] = "老陈";//key已经存在,则覆盖原值
	mapstu[5] = mapstu[6];//key值存了,因为是string所以默认初始化值:空字符串,底层生成了节点(key占)
	mapstu[7] = mapstu[4];//赋值,mapstu[7]= "老刘";

	for (map<int, string>::iterator it = mapstu.begin(); it != mapstu.end(); it++) {
		cout << "Key:" << (*it).first << " Value:" << (*it).second << endl;
	}
}

void map排序_赋值_大小_删除() {
	while (1) { 
	map<int, string,greater<int>> mapstu;//排序和set容器一样
	mapstu.insert(pair<int, string>(1, "张三"));
	mapstu.insert(pair<int, string>(4, "张捌"));
	mapstu.insert(make_pair(2, "张si"));
	mapstu.insert(map<int, string>::value_type(3, "屌丝"));
	//大小和set差不多,同没有resize()方法; mapstu.size();//元素个数;  mapstu.empty();//判断容器是否为空
	//删除也和set一样,
	//mapstu.clear();//清空容器
	//mapstu.erase();//删除单个元素 || 删除区间元素 || 删除key和key对组的元素 (前两个用法返回下一个元素的迭代器)
	map<int, string, greater<int>>::size_type st = mapstu.erase(5);//删除元素的个数
	int r[] = { 1,2,3,4 };
	for (map<int, string, greater<int>>::iterator it = mapstu.begin(); it != mapstu.end(); it++) {
		cout << "Key:" << (*it).first << " Value:" << (*it).second << endl;}

	cout << "st:" << st << endl;

	//逆序输出
	/*
	for (map<int, string, greater<int>>::reverse_iterator it = mapstu.rbegin(); it != mapstu.rend(); it++) {
		cout << "Key:" << (*it).first << " Value:" << (*it).second << endl;  }*/

	break;
	}
}

void map查找() {
	//map的查找
	while (0) { 
	map<int, string> mapstu;
	mapstu.insert(pair<int, string>(1, "张三"));
	mapstu.insert(pair<int, string>(4, "张捌"));
	mapstu.insert(make_pair(2, "张si"));
	mapstu.insert(map<int, string>::value_type(3, "屌丝"));

	map<int, string>::iterator it = mapstu.find(2);
	if (it != mapstu.end()) {//找到了
		cout <<"mapstu.find(2):" <<(*it).second << endl;
	}
	else {
		cout << "没找到为2的键值对\n";
	}
	
	break;
	}
	/*
	map.lower_bound(keyElem);  //返回第一个key>=keyElem元素的迭代器。
map.upper_bound(keyElem);	   //  返回第一个key>keyElem元素的迭代器。
map.equal_range(keyElem);		//返回容器中key与keyElem相等的上下限的两个迭代器。上限是闭区间，下限是开区间，如[beg,end)。
	参考set
	*/
	//mutimap的查找
	while (1) {
		multimap<int, string> mapstu;
		mapstu.insert(pair<int, string>(1, "张三"));
		mapstu.insert(pair<int, string>(4, "张捌"));
		mapstu.insert(pair<int, string>(4, "万万"));
		mapstu.insert(make_pair(2, "张si"));
		mapstu.insert(map<int, string>::value_type(3, "屌丝"));
		mapstu.insert(map<int, string>::value_type(3, "成真"));

		int cz = 3;//需查找数
		map<int, string>::iterator it = mapstu.find(cz);//迭代器
		
		/*
		if (it != mapstu.end()) {//找到了//通过循环
			for(;it != mapstu.end();it++){
				if((*it).first==cz)
				{
					cout << "mapstu.find("<<cz<<"):" << (*it).second << endl;
				}
				else {
					break;
				}
			}
		}
		else {
			cout << "没找到为("<<cz<<")的键值对\n";
		}*/
		
		int ct = mapstu.count(cz);//得到key在容器中的个数
		if (ct > 0) {//通过计数
			it = mapstu.find(cz);
			for (int i = 0; i < ct;i++,it++) {
				cout << "mapstu.find("<<cz<<"):" << (*it).second << endl;
			}
		}
		else {
			cout << "没找到为("<<cz<<")的键值对\n";
		}

		cout << "mapstu.equal_range()示例:\n";
		pair<map<int, string>::iterator, map<int, string>::iterator> iit = mapstu.equal_range(cz);//pair<迭代器,迭代器>
		if (iit.first != mapstu.end()) {//判断有无要找key,如果没有就去打印会崩溃
			cout << "mapstu.equal_range(" << cz << ")所取得pair中第一个迭代器内容:" << (*iit.first).second<< endl;
			if (iit.second != mapstu.end())
			cout << "mapstu.equal_range(" << cz << ")所取得pair中第二个迭代器内容:" << (*iit.second).second << endl;
		}
		else {
			cout << "mapstu.equal_range(" << cz << ")没有\n";
		}

		break;
	}

}