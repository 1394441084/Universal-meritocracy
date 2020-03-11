#pragma once
//#include "��.h"  //ʹ����ģ���ļ��ֿ�,���Ҳ����ຯ���Ķ���(��Ϊ�����������ģ��������α���),������Ҫ:
//#include "��ģ���д��(�������-��Ԫ����).cpp"  //.h��.cpp�ļ���һ�����.����main���������ҵ���
#include "��ģ���д��(�������-��Ԫ����).hpp"    //��ҵ����ģ�����ʵ��һ�㶨Ϊ.hpp(ͳһ����)
#include "������ģ��(vector).hpp"
#include <stdlib.h>

using namespace std;

//�򵥵ĳ�������
void Measured_at_the_beginning_of_the_container();

//�򵥳��⺯��ģ��
void Simple_pretest_function_template();

//�򵥳���ģ�庯���ͺ�������
void Template_functionsand_function_overloads();

//��ģ��Ķ���͵���
void Class_templates_are_definedand_invoked();

//��ģ��ͼ̳�
void Class_templatesand_inheritance();

//��ģ���д��(�������-��Ԫ����)
void Class_template();

//��ģ���static��Ա
void Class_templatesand_static_members();

//������ģ��(vector)
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

//��ģ���д��(�������-��Ԫ����)
void Class_template() {
	D<int> d1(785), d2(565);
	D<int> d3 = d1 + d2;
	cout << d3.gett() << endl;
	//d1 = addD(d1, d2);//���벻ͨ��,�޷�����
	//��Ԫ�������ñ�����ʾ������:addD<int>(d1, d2)
	d3 = addD<int>(d1, d2);//�޷�����private��Ա
	cout << d3.gett() << endl;
}

//��ģ���static��Ա
void Class_templatesand_static_members() {
	D<int> d1(785), d2(565);//ͬ���͹���̬��Ա(�Զ���)
	d1.stti = 555;
	cout << d2.stti << endl;//555

	D<float> d3(654),d4(485);//��ͬ���Ͳ�����̬��Ա(Ĭ��ֵ)
	cout << d3.stti << endl;//666
	//�������ڲ���ײ�ʵ������D��,����������ʵ������(�ֱ���:int,char)��,�����õ�������һ��,��������͵͵���˸Ķ�,�����޷�����;
	d3.stti = 58245;
	cout << d4.stti << endl;
	cout << d2.stti << endl;
}

//������ģ��(vector)
void Array_class_template() {
	//����ͨ���ͷŽ�������ģ��
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

	//���Զ�����Ž�������ģ��
	while (1) { 
	Students s1("��СС", 25);
	Students s2("���", 20);

	//Vector<Students> vectors(2);vectors[1] = s2;//��ֵ����Ч�ʲ���
	Vector<Students*> vectors(2);//ʹ��ָ��ɴ�ӡ�������ǵ�ַ
	vectors[0] = &s1;//ǳ����(û�Զ��忽�����캯��)
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
		os << "δ����,0" << endl;
	}
	else {
		os << "(" << s.name << " " << s.age << ")" ;
	}
	return os;
}