#pragma once
#include <stdlib.h>
#include <sstream>
#include <functional> //�º��� ����
#include <algorithm>  //�㷨
#include <vector>

using namespace std;
class Studentss {
public:
	Studentss(const char* name = "��", int age = 0) {
		//cout << "Ĭ�Ϲ��캯��\n";
		this->age = age;
		age = sizeof(name) + 1;
		this->name = new char[age];
		strcpy_s(this->name, age, name);
	}
	Studentss(const Studentss& other) {
		//cout << "�������캯��\n";
		age = sizeof(other.name) + 1;
		//���û�����ڶ���name=NULL,��ô�������ɵ���ʱ����name��Ұָ��,��ʱ����ɷ��ʳ�ͻ,�㶼û�ռ�,delete��������ô
		if (name)delete[] name;
		name = new char[age];
		strcpy_s(name, age, other.name);
		age = other.age;
	}
	Studentss& operator=(const Studentss& other) {
		if (this == &other)return *this;
		//cout << "���������=\n";
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
			//cout << "����\n";
		}
	}

private:
	char* name = NULL;
	int age = 0;
};
//�Զ���º���(�Ƴ�ģ����͸�less�º���һ����)
class FunStudent {//class�ɼ���˽�е�(private:) //struct FunStudent  �ɼ��ǹ��е�(public:)
public:
	bool operator()(const Studentss& left, const Studentss& right)const {//Left to right
		cout << "������fun\n";
		return left.getage() < right.getage();
	}
};