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
		cout << "无参被调用\n";
	}
	Student(const char* name,int age){
		if (name == " " || name == "\0" || name == "\t") {name = "空";}
		this->age = strlen(name) + 1;
		this->name = (char*)malloc(this->age);
		strcpy_s(this->name,this->age, name);
		this->age = age;
		cout << "有参函数\n";
	}
	Student(const Student& s) {
		cout << "拷贝构造函数被调用!\n";
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
		cout << "重载=函数被调用!\n";
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
	void 打印() {
		stringstream str;
		str << "姓名:" << name << " 年龄:" << age << endl;
		cout << str.str();
	}
	~Student() {
		if (name) {
			free(name);
			name = NULL;
			cout << "析构\n";
		}
	}
private:
//protected:
	char* name=NULL;//必须类内定义为NULL,不然使用容器时会造成野指针出现
	int age=0;
};
int main(void) {
	vector<Student>   ss;
	//vector<Student>   ss(10);//分配好空间
	Student s("珠珠", 15);
	//s.打印();
	Student s1("huanghaunghau",585);
	//s1=s;
	//s1.打印();
	//ss.push_back(Student("珠珠", 15));//临时变量再拷贝

	//变参模板和完美转发  
	//ss.emplace_back("王大锤", 28);//直接构造 //变参模板和完美转发  .push_back相当,但节省了一次临时变量

	//ss[0].打印();
	//ss.emplace(ss.end(),"王彩虹",23);//相当于insret 
	//ss.emplace(ss.begin(),s1);
	ss.push_back(s);//拷贝
	//ss.emplace_back(s);//拷贝
	//ss[0].打印();
	//ss[1].打印();

	//ss.clear();
	system("pause");
	return 0;
}