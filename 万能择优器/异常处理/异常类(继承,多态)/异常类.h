#pragma once
#include <iostream>

using namespace std;

/*
���һ������������ Vector������[]�����������ʼ��ʱ��������ĸ���������Ч���
1��index<0 �׳��쳣errNegativeException
2��index = 0 �׳��쳣 errZeroException
3��index>1000�׳��쳣errTooBigException
4��index<10 �׳��쳣errTooSmallException
5��errSizeException����������ĸ��࣬ʵ���в������졢������virtual void printError()�������
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

