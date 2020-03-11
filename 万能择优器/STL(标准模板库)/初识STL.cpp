#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <vector> //容器.STL(动态数组)
#include <algorithm>//算法.STL

using namespace std;

class Student {
public:
	Student(const char* name = "未命名", const int age = 0) {
		if (name == " "||name=="\0"||name=="\t") { name = "空格"; }
		this->name = new char[sizeof(name) + 1];strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Student(const Student& other) {
		age = other.age;
		cout << "调用拷贝构造函数\n";
		if (name != NULL)delete[] name;
		if (other.name == NULL){name = NULL;return;}
		name = new char[sizeof(other.name) + 1];
		strcpy_s(name, sizeof(other.name) + 1, other.name);
		/*
		if (other.name == NULL) {
			if (name == NULL) {
				age = other.age;
				return;
			}
			else {
				delete[] name;
				name == NULL;
				age = other.age;
				return;
			}
		}
		else {
			if (name == NULL) {
				name = new char[sizeof(other.name) + 1];
				strcpy_s(name, sizeof(other.name) + 1, other.name);
				age = other.age;
				return;
			}
			else {
				delete[] name;
				name = new char[sizeof(other.name) + 1];
				strcpy_s(name, sizeof(other.name) + 1, other.name);
				age = other.age;
				return;
			}
		}*/
	}
	~Student() {
		if (name != NULL) {
			delete[] name;
			name = NULL;
		}
	}
	friend ostream& operator<<(ostream& os, const Student& other) {
		other.name == NULL ? os << "name==NULL" : os << "name=" << other.name << "\tage=" << other.age;
		return os;}
//private:
	int age=0;
	char* name = NULL;
};

void STL概述() {
	//第一部分 容器vector<>
	vector<int> v1;
	cout << "v1的元素个数:" << v1.size() << endl;
	cout << "v1容器大小:" << v1.capacity() << endl;
	
	v1.push_back(1);//往最后的空间存放
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << "v1的元素个数:" << v1.size() << endl;
	cout << "v1容器大小:" << v1.capacity() << endl;
	//下标访问v1中的元素
	for (unsigned int i = 0; i < v1.size(); i++) {
		printf("v1[%d]:%d\n", i, v1[i]);
	}

	//第二部分 迭代器 vector<>::iterator
	//迭代器访问v1中的元素
	//定义一个迭代器对象指向v1的第一个元素
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {//v1.end()是最后的位置,不是最后一个元素,而是一个迭代器
		cout << *it << endl;
	}

	//第三部分 算法
	int ncount = count(v1.begin(), v1.end(), 3);//count(头元素,尾元素,需统计数)
	printf("v1中数值为3的元素个数:%d\n", ncount);//2
}

void demo() {//容器直接存放对象
	vector<Student> v2;
	Student s1("李洁", 20);
	Student s2("陈欢", 18);
	v2.push_back(s1);//进行拷贝构造函数
	v2.push_back(s2);//和s2不是同一个对象
	v2.push_back(Student("li", 30));
	cout << "v2的学生个数:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << endl;
	}
	vector<Student>::iterator it = v2.begin();
	for (; it != v2.end(); it++) {//it是指针指向v2第一个元素,通过解引得到第一元素里的内容
		cout << (*it).name<<": "<<(*it).age << endl;
	}
}
void demo1() {//容器存放指针
	vector<Student *> v2;
	Student s1("李洁", 20);
	Student s2("陈欢", 18);
	v2.push_back(&s1);//进行拷贝构造函数
	v2.push_back(&s2);
	cout << "v2的学生个数:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << endl;
	}
	vector<Student *>::iterator it = v2.begin();
	for (; it != v2.end(); it++) {
		cout << (**it).name << ": " << (**it).age << endl;
	}
}

