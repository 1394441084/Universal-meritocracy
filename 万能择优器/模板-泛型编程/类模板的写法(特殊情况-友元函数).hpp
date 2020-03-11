#pragma once
#include "类.h"

//分成.h和.cpp文件也是一样,只是有没有分开而已
//将类模板放到外部实现:
template <typename T>//函数前必须声明
D<T>::D(T t) {//类的成员函数前限定域说明必须带上虚拟参数列表
	this->t = t;
}

template <typename T>
T D<T>::gett() {
	return t;//成员函数中出现模板类的对象时必须带上虚拟参数列表
}

template <typename T>
D<T> D<T>::operator+(const D& d) {//返回类的对象必须带上虚拟参数列表
	D tmp;//类的内部可以显示声明,也可以隐式
	tmp.t = d.t + this->t;//成员函数内部没有限定
	return tmp;
}

template <typename T>
void D<T>::printfD()const{
	cout << this->t << endl;
}

