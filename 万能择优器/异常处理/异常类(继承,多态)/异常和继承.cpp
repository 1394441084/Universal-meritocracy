#pragma once
#include "Vector数组类.h"

#include <exception> //标准库的异常类头文件
#include <stdexcept> //标准库的异常类头文件


class Student {
public:
	Student(int age) {
		if (age > 249) {
			throw out_of_range("年龄太大，你是外星人嘛?");
		}
		m_age = age;
		m_space = new int[1024 * 1024 * 100];
	}

private:
	int m_age;
	int* m_space;
};


void 标准库的异常类() {

	try {
		for (int i = 1; i < 1024; i++) {
			Student* xiao6lang = new Student(18);
		}
	}
	catch (out_of_range & e) {
		cout << "捕捉到一只异常：" << e.what() << endl;
	}
	catch (bad_alloc & e) {
		cout << "捕捉到动态内存分配的异常：" << e.what() << endl;
	}

	system("pause");
}

void 异常和继承() {
	try {
		Vector v(10000);
		for (int i = 0; i < 5; i++) {
			v[i] = i + 10;
			printf("v[%d]:%d\n", i, v[i]);
		}
	}//采用多态继承方式实现
	catch (errSizeException & e) {
		e.printError();
	}
	catch (...) {
		printf("....\n");
	}

	/*//采用普通形式
	catch(errNegativeException &e){
		printf("errNegativeException<0....\n");
	}
	catch (errZeroException &e) {
		printf("errZeroException==0....\n");
	}
	catch (errTooBigException &e) {
		printf("errTooBigException>1000....\n");
	}
	catch (errTooSmallException &e) {
		printf("errTooSmallException<10....\n");
	}catch(...) {
		printf("....\n");
	}*/

	system("pause");
}

int main(void) {
	//异常和继承();
	标准库的异常类();
	system("pause");
	return 0;
}

