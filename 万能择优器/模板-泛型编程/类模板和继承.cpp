#pragma once
#include <iostream>

using namespace std;

//�̳��и������ģ����Ľ�����
//1.������һ����,������ģ����,����ͨ�̳��淨����
//2.������һ����,������ģ����,�̳�ʱ����ʵ������������Ͳ���<>
//3.���ุ�඼��ģ����,������������Ϳ��Դ�������,��ѭ�������

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
//����ͨ�̳в��,ֻ�Ǳ�����������,����ֻ�ܽ�ģ����廯
//class B :public C{//ȱ����ģ��Ĳ����б�,���಻֪����������⺯���������ĸ�,������Ҫ�Լ�����
class B :public C<int>{
public:
	//B(int b){ this->b = b; }//��Ҳ��!������๹�캯��û�ж�Ĭ�ϲ����Ͳ�����,�͵���Ҫ�������
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