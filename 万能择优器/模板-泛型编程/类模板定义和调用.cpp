#include <iostream>

using namespace std;

template <typename T>
class A {
public:
	//可以将所有类型替换成虚拟类型,如:A(T t= 0)
	A(int t= 0) {//参数列表虚拟类型
		this->t = t;
	}
	//如:int gett()
	T gett() {//返回虚拟类型
		return t;
	}

private:
	//如:
	int t;//成员变量虚拟类型

};

//将类作为函数的参数,void callA(A a);//缺少类模板参数列表
void callA(A<int> &a) {
	cout << a.gett() << endl;
}

//类模板的定义和调用
void Class_templates_are_definedand_invoked(){
	//使用函数模板不需要指定类型,但使用类模板却要
	//类模板定义类对象,必须显式指定类型
	//A b(77);//缺少类模板参数列表
	A<int> a(666);
	//模板中如果使用了构造函数,则遵守以前类的构造函数调用规则

	callA(a);//模板类作为函数参数
	cout << a.gett() << endl;
}