#pragma once
#include <stdlib.h>
#include <sstream>
#include <functional> //仿函数 功能
#include <algorithm>  //算法
#include <vector>

using namespace std;
class Studentss {
public:
	Studentss(const char* name = "空", int age = 0) {
		//cout << "默认构造函数\n";
		this->age = age;
		age = sizeof(name) + 1;
		this->name = new char[age];
		strcpy_s(this->name, age, name);
	}
	Studentss(const Studentss& other) {
		//cout << "拷贝构造函数\n";
		age = sizeof(other.name) + 1;
		//如果没有类内定义name=NULL,那么容器生成的临时对象name是野指针,此时会造成访问冲突,你都没空间,delete不是找死么
		if (name)delete[] name;
		name = new char[age];
		strcpy_s(name, age, other.name);
		age = other.age;
	}
	Studentss& operator=(const Studentss& other) {
		if (this == &other)return *this;
		//cout << "运算符重载=\n";
		if (name)delete[] name;
		age = sizeof(other.name) + 1;
		name = new char[age];
		strcpy_s(name, age, other.name);
		age = other.age;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Studentss& other) {
		os << "Student name:" << other.name << " age:" << other.age << endl;
		return os;
	}
	bool operator<(const Studentss& other)const { return age < other.age; }
	bool operator>(const Studentss& other)const { return age > other.age; }

	int getage()const { return age; }
	~Studentss() {
		if (name) {
			delete[] name;
			name = NULL;
			//cout << "析构\n";
		}
	}

private:
	char* name = NULL;
	int age = 0;
};
//自定义仿函数(制成模板类就跟less仿函数一样了)
class FunStudent {//class可见是私有的(private:) //struct FunStudent  可见是公有的(public:)
public:
	bool operator()(const Studentss& left, const Studentss& right)const {//Left to right
		cout << "调用了fun\n";
		return left.getage() < right.getage();
	}
};