#pragma once
#include <iostream>

using namespace std;

//继承中父子类和模板类的结合情况
//1.父类是一般类,子类是模板类,和普通继承玩法类似
//2.子类是一般类,父类是模板类,继承时必须实例化父类的类型参数<>
//3.子类父类都是模板类,子类的虚拟类型可以传给父类,遵循上面规则

template <typename T>
class C {
public:
	C(int t = 0) {
		this->t = t;
	}
	T gett() {
		return t;
	}
private:
	int t;
};

template <typename G>
//和普通继承差不多,只是编译器不智能,所以只能将模板具体化
//class B :public C{//缺少类模板的参数列表,子类不知道父类的虚拟函数类型是哪个,所以需要自己定义
class B :public C<int>{
public:
	//B(int b){ this->b = b; }//这也行!如果父类构造函数没有定默认参数就不行了,就得需要下面操作
	//B(int b) :C(777){ this->b = b; }
	B(G b) :C<G>(b){ this->b = b; }

private:
	int b;
};

void callC(C<int>& a) {
	cout << a.gett() << endl;
}

void Class_templatesand_inheritance(){
	C<int> a(666);
	callC(a);
	cout << a.gett() << endl;

	B<int> b(888);
	cout << b.gett() << endl;
}