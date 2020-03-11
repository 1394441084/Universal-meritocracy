#pragma once
#include <iostream>

using namespace std;

/*
设计一个数组类容器 Vector，重载[]操作，数组初始化时，对数组的个数进行有效检查
1）index<0 抛出异常errNegativeException
2）index = 0 抛出异常 errZeroException
3）index>1000抛出异常errTooBigException
4）index<10 抛出异常errTooSmallException
5）errSizeException类是以上类的父类，实现有参数构造、并定义virtual void printError()输出错误。
*/

class errSizeException {
public:
	errSizeException(int size = 0) { m_size = size; }
	virtual void printError(){ printf("size:%d\n", m_size); }
protected:
	int m_size=0;
};

class errNegativeException :public errSizeException {
public:
	errNegativeException(int size) :errSizeException(size) {}
	virtual void printError() { printf("errNegativeException:%d\n", m_size); }
};

class errZeroException :public errSizeException {
public:
	errZeroException(int size) :errSizeException(size) {}
	virtual void printError() { printf("errZeroException:%d\n", m_size); }
};

class errTooBigException :public errSizeException {
public:
	errTooBigException(int size) : errSizeException(size) {}
	virtual void printError() { printf("errTooBigException:%d\n", m_size); }
};

class errTooSmallException :public errSizeException {
public:
	errTooSmallException(int size) : errSizeException(size) {}
	virtual void printError() { printf("errTooSmallException:%d\n", m_size); }
};

