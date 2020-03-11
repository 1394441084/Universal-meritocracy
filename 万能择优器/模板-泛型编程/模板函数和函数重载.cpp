#include <iostream>
using namespace std;

//模板 <类型名称 T>
template <typename T1>
//void 函数模板(){}
void A_function_template(T1& a, T1& b) {
	T1 t=a;//编译器生成的是模板函数,自定义的是函数模板
	a = b;
	b = t;
	cout << "函数模板被调用了\n";
	//单存于一个通用类型时,不提供隐式数据类型转换,必须严格的匹配,除非template <typename T,typename T1>
}

void A_function_template(int& a, int& b) {
	int t = a;
	a = b;
	b = a;
	cout << "int普通重载函数被调用了\n";
	//函数模板和普通重载函数并存,且匹配,优先是普通重载函数
}

void A_function_template(char &a,int &b) {
	int t = a;
	a = b; 
	b = a;
	cout << "普通重载函数被调用了\n";
	//函数模板和普通重载函数并存,且匹配,优先是普通重载函数
	//类型和普通重载函数更匹配时,调用的是普通重载函数
}

//两模版测试
//第一版
int Max(int a, int b)
{
	cout << "调用 int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "调用 T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c) {
	cout << "调用 T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);//和重载一样也能进行嵌套
}

//第二版
int Max1(int a, int b)
{
	cout << "调用 int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T1, typename T2>
T1 Max1(T1 a, T2 b)
{
	cout << "调用 T Max1(T1 a, T2 b)" << endl;
	return a > b ? a : b;
}


void Template_functionsand_function_overloads() {
	char c = 'c';
	int i = 65;//A
	int a = 55;
	float n= 1.0;
	float m = 2.0;
	A_function_template(c, i);//参数类型和普通重载函数更匹配
	A_function_template(a, i);//函数模板与普通重载函数并存,且匹配,编译器优先选择普通重载函数
	A_function_template<>(a, i);//加<> 类型列表,<int>,调用的是模板函数,即自己选择
	A_function_template(n,m);//如果函数模板会产生更好的匹配,就会使用函数模板

	cout << "-------------------------------\n";
	//两模版测试
	char cc = 'a';
	//如果函数模板会产生更好的匹配，使用函数模板
	//Max1(cc, a);
	//Max(1.0, 2.0);

	Max(3.0, 4.0, 5.0);
	/*
	函数模板和普通函数在一起，调用规则： 
	1 函数模板可以像普通函数一样被重载
	2 C++编译器优先考虑普通函数
	3 如果函数模板可以产生一个更好的匹配，那么选择模板
	4 可以通过空模板实参列表的语法限定编译器只通过模板匹配
	*/
}