#pragma once
#include <vector>  //容器头文件
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
数组模板类（ Vector ），完成对int、char、float、double 以及任意的自定义类等类型元素进行管理。
需求:
	a.实现构造函数
	b.实现拷贝构造函数
	c.实现cout << 操作
	d.实现下标访问符[] 的重载操作
	e.实现 = 号操作符重载
*/

template <typename TT>
class Vector {
public:
	Vector();
	Vector(int size = 128);//构造函数
	Vector(const Vector<TT>& other);//拷贝构造函数
	~Vector();//析构函数

	template <typename TT> //包含进来会出现operator<< "非法使用显式模板参数";
	//friend ostream& operator<<(ostream& os, const Vector& other);//加入特殊类型后.编译器无法解析
	friend ostream& operator<<<TT>(ostream& os, const Vector<TT>& other);//用这个也不行!!//加入Students类就需要他

	//Vector<int> a1; a1[0]
	TT& operator[](int i)const;

	Vector& operator=(const Vector<TT>& other);

	int getlen();//获取内部存的元素个数

private:
	TT* m_bese=NULL;//索引类型数组
	int m_len;//成员变量的个数

};

//学生
class Students {
public:
	Students() {
		age = 0;
		name[0] = '\0';
	}
	Students(const char* name, int age) {
		this->age = age;
		strcpy_s(this->name, 64, name);
	}
	~Students() {}
	void printf11() {
		cout << name << "\t" << age << endl;
	}
	/*
	Students& operator=(const Students& s) {
		this->age = s.age;
		strcpy_s(this->name, 64, name);
		return *this;
	}
	int operator[](int i) {
		return i;
	}*/
	friend ostream& operator<<(ostream& os, const Students& s);
private:
	int age;//年龄
	char name[64];//姓名
};

