#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <vector> //����.STL(��̬����)
#include <algorithm>//�㷨.STL

using namespace std;

class Student {
public:
	Student(const char* name = "δ����", const int age = 0) {
		if (name == " "||name=="\0"||name=="\t") { name = "�ո�"; }
		this->name = new char[sizeof(name) + 1];strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Student(const Student& other) {
		age = other.age;
		cout << "���ÿ������캯��\n";
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

void STL����() {
	//��һ���� ����vector<>
	vector<int> v1;
	cout << "v1��Ԫ�ظ���:" << v1.size() << endl;
	cout << "v1������С:" << v1.capacity() << endl;
	
	v1.push_back(1);//�����Ŀռ���
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << "v1��Ԫ�ظ���:" << v1.size() << endl;
	cout << "v1������С:" << v1.capacity() << endl;
	//�±����v1�е�Ԫ��
	for (unsigned int i = 0; i < v1.size(); i++) {
		printf("v1[%d]:%d\n", i, v1[i]);
	}

	//�ڶ����� ������ vector<>::iterator
	//����������v1�е�Ԫ��
	//����һ������������ָ��v1�ĵ�һ��Ԫ��
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {//v1.end()������λ��,�������һ��Ԫ��,����һ��������
		cout << *it << endl;
	}

	//�������� �㷨
	int ncount = count(v1.begin(), v1.end(), 3);//count(ͷԪ��,βԪ��,��ͳ����)
	printf("v1����ֵΪ3��Ԫ�ظ���:%d\n", ncount);//2
}

void demo() {//����ֱ�Ӵ�Ŷ���
	vector<Student> v2;
	Student s1("���", 20);
	Student s2("�»�", 18);
	v2.push_back(s1);//���п������캯��
	v2.push_back(s2);//��s2����ͬһ������
	v2.push_back(Student("li", 30));
	cout << "v2��ѧ������:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << endl;
	}
	vector<Student>::iterator it = v2.begin();
	for (; it != v2.end(); it++) {//it��ָ��ָ��v2��һ��Ԫ��,ͨ�������õ���һԪ���������
		cout << (*it).name<<": "<<(*it).age << endl;
	}
}
void demo1() {//�������ָ��
	vector<Student *> v2;
	Student s1("���", 20);
	Student s2("�»�", 18);
	v2.push_back(&s1);//���п������캯��
	v2.push_back(&s2);
	cout << "v2��ѧ������:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << endl;
	}
	vector<Student *>::iterator it = v2.begin();
	for (; it != v2.end(); it++) {
		cout << (**it).name << ": " << (**it).age << endl;
	}
}

