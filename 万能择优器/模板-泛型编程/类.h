#pragma once
#include <vector> //����ͷ�ļ�
#include <iostream>
#include <stdlib.h>

using namespace std;

class demo {
public:
	demo(int k = 0) { this->k = k; }
	~demo() {}

	int getk() { return k; }
	bool operator>(demo& demo1) const {if (k > demo1.k) {return true;}else {return false;}}

private:
	int k;
};


//��ģ���д��(�������-��Ԫ����)
template <typename T>
class D {
public:
	D(T t = 0);
	T gett();
	D operator+(const D& d);

	//��ģ����Ԫ�����������ģ������,��Ȼ����ֱ��벻ͨ��
	template <typename T>  //û�ӻ��޷�����˽�г�Ա,һ��Ҫ����
	friend D<T> addD(const D<T>& a,const D<T>& b);//���벻ͨ��

	void printfD()const;

	//static int stti;
	static T stti;
private:
	int t;
};

//template <typename T> int D<T>::stti = 666;//����ʹ���������
template <typename T> T D<T>::stti = 666;

//��Ԫ����
template <typename T>
D<T> addD(const D<T>& a, const D<T>& b) {
	//D d;//����������Ĭ�Ϲ��캯���޷�����
	D<int> d;//�޷�����private��Ա
	d.t = a.t - b.t;
	//cout << "������Ԫ\n";
	return d;
}


