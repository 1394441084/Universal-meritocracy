#pragma once
#include <vector>  //����ͷ�ļ�
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
����ģ���ࣨ Vector ������ɶ�int��char��float��double �Լ�������Զ����������Ԫ�ؽ��й���
����:
	a.ʵ�ֹ��캯��
	b.ʵ�ֿ������캯��
	c.ʵ��cout << ����
	d.ʵ���±���ʷ�[] �����ز���
	e.ʵ�� = �Ų���������
*/

template <typename TT>
class Vector {
public:
	Vector();
	Vector(int size = 128);//���캯��
	Vector(const Vector<TT>& other);//�������캯��
	~Vector();//��������

	template <typename TT> //�������������operator<< "�Ƿ�ʹ����ʽģ�����";
	//friend ostream& operator<<(ostream& os, const Vector& other);//�����������ͺ�.�������޷�����
	friend ostream& operator<<<TT>(ostream& os, const Vector<TT>& other);//�����Ҳ����!!//����Students�����Ҫ��

	//Vector<int> a1; a1[0]
	TT& operator[](int i)const;

	Vector& operator=(const Vector<TT>& other);

	int getlen();//��ȡ�ڲ����Ԫ�ظ���

private:
	TT* m_bese=NULL;//������������
	int m_len;//��Ա�����ĸ���

};

//ѧ��
class Students {
public:
	Students() {
		age = 0;
		name[0] = '\0';
	}
	Students(const char* name, int age) {
		this->age = age;
		strcpy_s(this->name, 64, name);
	}
	~Students() {}
	void printf11() {
		cout << name << "\t" << age << endl;
	}
	/*
	Students& operator=(const Students& s) {
		this->age = s.age;
		strcpy_s(this->name, 64, name);
		return *this;
	}
	int operator[](int i) {
		return i;
	}*/
	friend ostream& operator<<(ostream& os, const Students& s);
private:
	int age;//����
	char name[64];//����
};

