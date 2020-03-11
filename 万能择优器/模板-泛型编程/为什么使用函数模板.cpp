#pragma once
#include "类.h"

/*
项目需求
程序员Jack 的团队新接手了一个底层的项目，项目经理要求Jack 实现一个通用的容器，
能够支持插入多种不同的普通类型（包含 int char float double 等)和自定义结构体和自定义类的对象，
并能根据每种不同类型的比较规则从容器中取得最大或最小的那个值或对象。


C++提供了模板(template)编程的概念。
所谓模板，实际上是建立一个通用函数或类，其类内部的类型和函数的形参类型不具体指定，
用一个虚拟的类型来代表。这种通用的方式称为模板。
模板是泛型编程的基础,泛型编程即以一种独立于任何特定类型的方式编写代码。

1. C++函数模板的使用
为什么要有函数模板
项目需求: 实现多个函数用来返回两个数的最大值，要求能支持char类型、int类型、double
*/

/*
int Max(int a, int b)
{
	return a > b ? a : b;
}

char Max(char a, char b)
{
	return a > b ? a : b;
}

float Max(float a, float b)
{
	return a > b ? a : b;
}
*/

//替代上面代码
//template 关键字告诉C++编译器 我要开始泛型编程了,请你不要随意报错
//T - 参数化数据类型
//声明,模板 <类型名字 T> //可以替代任何类型
//template <typename T>
//template <class T>//和上面效果等同
template <typename T,typename T1> //可以多个虚拟类型,定义后函数体必须要用
//如:T Max1(T a, T1 b)

//没写这时,上面的声明会报错
//返回类型 函数名(通类型 a,通类型 b){实现}
T Max1(T a, T1 b) {
	return a > b ? a : b;
}

void Simple_pretest_function_template() {
	char a1 = 'c';

	int  x = 1;
	int	 y = 2;

	//模板函数:编译器调用函数模板时会实现下面的函数,模板作为参数,编译器通过模板具体实现,类也是一样
	/*如果T 使用int 类型,T1使用char调用,相当于调用下面这个函数
int Max(int a, char b)
{
	return a>b ? a:b;
}
*/
	cout << "max1(1, 2) = " << Max1(x, a1) << endl;//实现参数类型的自动推导Max1(x, y)
	cout << "max1(1, 2) = " << Max1<int>(x, a1) << endl;//实现参数类型的自动推导Max1(x, y)
	cout << "max1(1, 2) = " << Max1<int,char>(x, a1) << endl;//实现参数类型的自动推导Max1(x, y)
	/*如果T 使用int 类型调用,相当于调用下面这个函数
int Max(int a, int b)
{
	return a>b ? a:b;
}
*/
	cout << "max1(1, 2) = " << Max1<int>(x, y) << endl;//显示调用

	float a = 2.0;
	float b = 3.0;

	cout << "max(2.0, 3.0) = " << Max1(a, b) << endl;

	demo demo1(10);
	demo demo2(20);
	cout << "max1(1, 2) = " << Max1(demo1, demo2).getk() << endl;
	/*等同于写了这么一个函数
	T Max1(T a, T1 b) {
	return a > b ? a : b;
}
	*/

}

/*
函数模板语法

所谓函数模板，实际上是建立一个通用函数，其函数类型和形参类型不具体指定，用一个虚拟的类型来代表。
这个通用函数就称为函数模板。凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，
只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。

函数模板定义形式
  由以下三部分组成：  模板说明 + 函数定义 + 函数模板调用

  template < 类型形式参数表 >
  类型  函数名 (形式参数表)
{
	//语句序列
}
*/