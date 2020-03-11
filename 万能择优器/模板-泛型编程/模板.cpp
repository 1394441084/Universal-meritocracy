#pragma once
//#include "类.h"  //使用类模板文件分开,会找不到类函数的定义(因为编译器会对类模板进行两次编译),所以需要:
//#include "类模板的写法(特殊情况-友元函数).cpp"  //.h和.cpp文件是一块的了.这样main函数就能找到了
#include "类模板的写法(特殊情况-友元函数).hpp"    //行业将类模板具体实现一般定为.hpp(统一区分)
#include "数组类模板(vector).hpp"
#include <stdlib.h>

using namespace std;

//简单的初测容器
void Measured_at_the_beginning_of_the_container();

//简单初测函数模板
void Simple_pretest_function_template();

//简单初测模板函数和函数重载
void Template_functionsand_function_overloads();

//类模板的定义和调用
void Class_templates_are_definedand_invoked();

//类模板和继承
void Class_templatesand_inheritance();

//类模板的写法(特殊情况-友元函数)
void Class_template();

//类模板和static成员
void Class_templatesand_static_members();

//数组类模板(vector)
void Array_class_template();

int main(void) {
	//Measured_at_the_beginning_of_the_container();

	//Simple_pretest_function_template();

	//Template_functionsand_function_overloads();

	//Class_templates_are_definedand_invoked();

	//Class_templatesand_inheritance();

	//Class_template();

	//Class_templatesand_static_members();

	Array_class_template();
	system("pause");
	return 0;
}

//类模板的写法(特殊情况-友元函数)
void Class_template() {
	D<int> d1(785), d2(565);
	D<int> d3 = d1 + d2;
	cout << d3.gett() << endl;
	//d1 = addD(d1, d2);//编译不通过,无法引用
	//友元函数调用必须显示类型如:addD<int>(d1, d2)
	d3 = addD<int>(d1, d2);//无法访问private成员
	cout << d3.gett() << endl;
}

//类模板和static成员
void Class_templatesand_static_members() {
	D<int> d1(785), d2(565);//同类型共享静态成员(自定义)
	d1.stti = 555;
	cout << d2.stti << endl;//555

	D<float> d3(654),d4(485);//不同类型不共享静态成员(默认值)
	cout << d3.stti << endl;//666
	//编译器内部会底层实现两个D类,将虚拟类型实例化了(分别是:int,char)的,我们用的名字是一样,但编译器偷偷做了改动,我们无法看到;
	d3.stti = 58245;
	cout << d4.stti << endl;
	cout << d2.stti << endl;
}

//数组类模板(vector)
void Array_class_template() {
	//将普通类型放进数组类模板
	while (0) { 
	Vector<int> myVector(10);
	//int a[10]; len:sizeof(a)/sizeof(a[0])
	for (int i = 0; i < myVector.getlen(); i++) {
		myVector[i] = i;
	}

	for (int i = 0; i < myVector.getlen(); i++) {
		cout << myVector[i] << endl;
	}

	Vector<int> myintvector(20);
	for (int i = 0; i < myintvector.getlen(); i++) {
		myintvector[i] = i;
	}
	myVector = myintvector;
	for (int i = 0; i < myVector.getlen(); i++) {
		cout << myVector[i] << endl;
	}
	cout <<myVector<< endl;
	cout << "----------------------\n";
	Vector<float> myVector1(10);

	//int a[10]; len:sizeof(a)/sizeof(a[0])
	for (int i = 0; i < myVector1.getlen(); i++) {
		myVector1[i] = i*0.1;
	}

	for (int i = 0; i < myVector1.getlen(); i++) {
		cout << myVector1[i] << endl;
	}
	break;
	}

	//将自定义类放进数组类模板
	while (1) { 
	Students s1("陈小小", 25);
	Students s2("李红", 20);

	//Vector<Students> vectors(2);vectors[1] = s2;//赋值这样效率不高
	Vector<Students*> vectors(2);//使用指针可打印出来的是地址
	vectors[0] = &s1;//浅拷贝(没自定义拷贝构造函数)
	vectors[1] = &s2;

	/*
	for (int i = 0; i < vectors.getlen(); i = i + 1) {
		vectors[i].printf11();
		//cout << vectors[i] ;
	}*/
	cout << vectors << endl;
	break;
	}
}

ostream& operator<<(ostream& os, const Students& s) {
	if (s.name[0] == '\0' || s.name == NULL) {
		os << "未命名,0" << endl;
	}
	else {
		os << "(" << s.name << " " << s.age << ")" ;
	}
	return os;
}