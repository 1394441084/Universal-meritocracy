#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <sstream>
#include <vector> //容器.STL(动态数组)
#include <algorithm>//算法.STL

using namespace std;

template <typename T>
string 打印(const char* name,const vector<T> v1) {
	stringstream str;
	str << name<<"的元素个数:" << v1.size() << endl;//元素个数,里面的元素有多少是多少.容器容量是自动扩容的,只会>=容器元素个数
	str << name<<"容器大小:" << v1.capacity() << endl;//容器里面有算法自动扩容的,为避免插入元素而进行全部拷贝导致效率低下的自动扩容算法(n)
	for (int i = 0; i < v1.size(); i++) {
		str << name<<"[" << i << "]:" << v1[i] << "  ";
	}
	str << endl;
	return str.str();
}

void 普通类型vector() {
	//vector 对象默认构造,不能v1[0] = 1;
	while (0) { 
	vector<int> v1;
	cout << "v1的元素个数:" << v1.size() << endl;
	cout << "v1容器大小:" << v1.capacity() << endl;
	//v1[0] = 1;//当我们使用默认构造时,不能直接通过下标访问
	v1.push_back(1);//往最后的空间存放
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << "v1的元素个数:" << v1.size() << endl;//5;元素个数,里面的元素有多少是多少.容器容量是自动扩容的,只会>=容器元素个数
	cout << "v1容器大小:" << v1.capacity() << endl;//6;容器里面有算法自动扩容的,为避免插入元素而进行全部拷贝导致效率低下的自动扩容算法(n)
	break;
	}

	//vector 对象带参构造函数
	while (0) {
	//指定大小,存放10个元素的数组
	vector<int> v1(10);//构造时就分配空间同时插入元素(全为0)
	vector<int> v2(10,666);////构造时就分配空间同时插入元素(全为666)
	//vector<int> v3(v2);//v3是v2的赋值品
	vector<int> v3(v2.begin(), v2.end()); //和vector<int> v3(v2); 一样
	vector<int> v4(v2.begin()+3,v2.end());//指定区间构造
	v2[0] = 1;//赋值
	v2[1] = 2;

	int tese[] = { 1,2,3,4,5,6 };
	vector<int> v5(tese, tese + 2);//数组首地址,首地址+2,移动2位;移到3终止,不保存3

	/*
	//打印区
	cout << "v1的元素个数:" << v1.size() << endl;
	cout << "v1容器大小:" << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1["<<i<<"]:"<<v1[i] <<"  ";
	}
	cout << endl;
	cout << "v2容器大小:" << v2.capacity() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << "  ";
	}
	cout << endl;
	cout << "v3容器大小:" << v3.capacity() << endl;
	for (int i = 0; i < v3.size(); i++) {
		cout << "v3[" << i << "]:" << v3[i] << "  ";
	}
	cout << endl;
	cout << "v4容器大小:" << v4.capacity() << endl;
	for (int i = 0; i < v4.size(); i++) {
		cout << "v4[" << i << "]:" << v4[i] << "  ";
	}
	cout << endl;*/
	cout << 打印("v1", v1);
	cout << 打印("v2", v2);
	cout << 打印("v3", v3);
	cout << 打印("v4", v4);
	cout << 打印("v5", v5);
	

	break; 
	}

	//vector 容器大小
	while (0) {
		vector<int> v2(10, 666);
		vector<int> v3(v2.begin(), v2.end()); 
		vector<int> v1;
		cout << "v1的元素个数:" << v1.size() << endl;//元素个数,里面的元素有多少是多少.容器容量是自动扩容的,只会>=容器元素个数
		cout << "v1容器大小:" << v1.capacity() << endl;//容器里面有算法自动扩容的,为避免插入元素而进行全部拷贝导致效率低下的自动扩容算法(n)
		if (v1.empty()) {
			cout << "v1容器空间为空!\n";
		}
		//v2.assign(2, 888);//赋值,改变原来元素个数和值
	//v2.assign(v3.begin(), v3.end());//使用迭代器赋值
	//v2.assign(tese, tese + 3);//使用数组赋值
		v2 = v3;//调用赋值运算
		cout << "调用.assign();后:\n";
		cout << 打印("v2", v2);

		//重新调整vector的大小
		v2.resize(2);//重新定义大小;从头开始算.v2[0],v2[1],这样;缩小空间并赋值,无意义;
		//v2.resize(13,888);//重新定义空间并将开扩的空间赋值;13空间,新开空间值为888;
		//v2.resize(13);//扩大不指定赋值,默认值为零
		cout << "调用.resize();后:\n";
		cout << 打印("v2", v2);

		break;
	}

	//vector 尾部添加和删除元素
	while (0) {
		vector<int> v2(10, 666);
		v2.push_back(999);//尾部添加;typename _Ty&& _Val(右值引用,C++11新特性)
		v2.pop_back();//尾部删除

		v2[0] = 777;//使用下标操作
		v2.at(2) = 854;//.at();返回的是引用
		//上两种方法访问,务必注意越界

		for (int i = 0; i < v2.size(); i++) {
			cout<<  "v2[" << i << "]:" << v2.at(i)<< "  ";
		}
		cout << endl;
		cout << "v2的第一个元素"<<v2.front() << endl;
		cout <<"v2的最后一个元素" <<v2.back() << endl;
		v2.front()=99;//返回的是引用,可修改值
		v2.back()=78;
		cout << "v2的第一个元素" << v2.front() << endl;
		cout << "v2的最后一个元素" << v2.back() << endl;
		for (int i = 0; i < v2.size(); i++) {
			cout << "v2[" << i << "]:" << v2.at(i) << "  ";
		}
		break;
	}

	//vector 的插入和删除  //逆向//rbegin()指向的是end()位置,rend()指向begin();//属逆向操作
	while (1) {
		vector<int> v1(10, 666);
		//插入单个元素: //后面的元素都往后移,10空间变11空间
		v1.insert(v1.begin(),888);//.insert(迭代器,插入的数值);v1.begin()+1,位置到1

		//插入多个元素: //返回值是迭代器
		//vector<int>::iterator it = v1.insert(v1.begin(), 3, 886);//.insert(迭代器,插入个数, 插入的数值);
		v1.insert(v1.begin(), 3, 886);

		int tese[] = { 1,2,3,4,5,6 };
		vector<int> v5(tese, tese + 5);
		v1.insert(v1.begin() + 1, v5.begin(), v5.end());//.insert(迭代器,插入起点, 插入终点);

		cout << 打印("v1", v1);

		//v1.clear();//整个vector删除掉
		v1.erase(v1.begin());//删除单个元素.erase(删除元素位置);
		//v1.erase(v1.begin(),v1.begin()+2);//.erase(起始位置,到结束位置);//删除多个元素

		cout << 打印("v1", v1);
		cout << "\n逆向输出v5\n";
		//rbegin()指向的是end()位置,rend()指向begin();//属逆向操作
		vector<int>::reverse_iterator rit = v5.rbegin();//逆转的迭代器
		for (; rit != v5.rend(); rit++) {
			cout << *rit << "  ";
		}
		cout << "\n";
		break;
	}
}

