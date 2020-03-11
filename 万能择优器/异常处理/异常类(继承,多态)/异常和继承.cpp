#pragma once
#include "Vector������.h"

#include <exception> //��׼����쳣��ͷ�ļ�
#include <stdexcept> //��׼����쳣��ͷ�ļ�


class Student {
public:
	Student(int age) {
		if (age > 249) {
			throw out_of_range("����̫��������������?");
		}
		m_age = age;
		m_space = new int[1024 * 1024 * 100];
	}

private:
	int m_age;
	int* m_space;
};


void ��׼����쳣��() {

	try {
		for (int i = 1; i < 1024; i++) {
			Student* xiao6lang = new Student(18);
		}
	}
	catch (out_of_range & e) {
		cout << "��׽��һֻ�쳣��" << e.what() << endl;
	}
	catch (bad_alloc & e) {
		cout << "��׽����̬�ڴ������쳣��" << e.what() << endl;
	}

	system("pause");
}

void �쳣�ͼ̳�() {
	try {
		Vector v(10000);
		for (int i = 0; i < 5; i++) {
			v[i] = i + 10;
			printf("v[%d]:%d\n", i, v[i]);
		}
	}//���ö�̬�̳з�ʽʵ��
	catch (errSizeException & e) {
		e.printError();
	}
	catch (...) {
		printf("....\n");
	}

	/*//������ͨ��ʽ
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
	//�쳣�ͼ̳�();
	��׼����쳣��();
	system("pause");
	return 0;
}

