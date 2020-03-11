#pragma once
#include <vector> //容器头文件
#include <iostream>
#include <stdlib.h>

using namespace std;

class demo {
public:
	demo(int k = 0) { this->k = k; }
	~demo() {}

	int getk() { return k; }
	bool operator>(demo& demo1) const {if (k > demo1.k) {return true;}else {return false;}}

private:
	int k;
};


//类模板的写法(特殊情况-友元函数)
template <typename T>
class D {
public:
	D(T t = 0);
	T gett();
	D operator+(const D& d);

	//类模板友元函数必须带上模板声明,不然会出现编译不通过
	template <typename T>  //没加会无法访问私有成员,一定要带上
	friend D<T> addD(const D<T>& a,const D<T>& b);//编译不通过

	void printfD()const;

	//static int stti;
	static T stti;
private:
	int t;
};

//template <typename T> int D<T>::stti = 666;//可以使用虚拟参数
template <typename T> T D<T>::stti = 666;

//友元函数
template <typename T>
D<T> addD(const D<T>& a, const D<T>& b) {
	//D d;//这样问题会多默认构造函数无法调用
	D<int> d;//无法访问private成员
	d.t = a.t - b.t;
	//cout << "调用友元\n";
	return d;
}


