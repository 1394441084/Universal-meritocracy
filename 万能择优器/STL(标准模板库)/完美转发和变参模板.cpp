#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <sstream>


using namespace std;

class Student {
public:
	Student() {
		const char* name1 = "kongkong";
		age = strlen(name1) + 1;
		name = (char*)malloc(age);
		strcpy_s(name,age,name1);
		age = 0;
		cout << "�޲α�����\n";
	}
	Student(const char* name,int age){
		if (name == " " || name == "\0" || name == "\t") {name = "��";}
		this->age = strlen(name) + 1;
		this->name = (char*)malloc(this->age);
		strcpy_s(this->name,this->age, name);
		this->age = age;
		cout << "�вκ���\n";
	}
	Student(const Student& s) {
		cout << "�������캯��������!\n";
		age = s.age;
		if (name != NULL) {
			free(name);
		}
		if (!s.name) { this->name = NULL; return; }
		int len = strlen(s.name) + 1;
		this->name = (char*)malloc(len);
		strcpy_s(this->name, len, s.name);
	}
	Student& operator=(const Student& s) {
		cout << "����=����������!\n";
		age = s.age;
		if (name != NULL) {
			free(name);
		}
		if (!s.name) { name = NULL; return *this; }
		int len = strlen(s.name) + 1;
		name = (char*)malloc(len);
		strcpy_s(name, len, s.name);
		return *this;
	}
	void ��ӡ() {
		stringstream str;
		str << "����:" << name << " ����:" << age << endl;
		cout << str.str();
	}
	~Student() {
		if (name) {
			free(name);
			name = NULL;
			cout << "����\n";
		}
	}
private:
//protected:
	char* name=NULL;//�������ڶ���ΪNULL,��Ȼʹ������ʱ�����Ұָ�����
	int age=0;
};
int main(void) {
	vector<Student>   ss;
	//vector<Student>   ss(10);//����ÿռ�
	Student s("����", 15);
	//s.��ӡ();
	Student s1("huanghaunghau",585);
	//s1=s;
	//s1.��ӡ();
	//ss.push_back(Student("����", 15));//��ʱ�����ٿ���

	//���ģ�������ת��  
	//ss.emplace_back("����", 28);//ֱ�ӹ��� //���ģ�������ת��  .push_back�൱,����ʡ��һ����ʱ����

	//ss[0].��ӡ();
	//ss.emplace(ss.end(),"���ʺ�",23);//�൱��insret 
	//ss.emplace(ss.begin(),s1);
	ss.push_back(s);//����
	//ss.emplace_back(s);//����
	//ss[0].��ӡ();
	//ss[1].��ӡ();

	//ss.clear();
	system("pause");
	return 0;
}