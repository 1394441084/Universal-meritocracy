#include <iostream>
using namespace std;

//ģ�� <�������� T>
template <typename T1>
//void ����ģ��(){}
void A_function_template(T1& a, T1& b) {
	T1 t=a;//���������ɵ���ģ�庯��,�Զ�����Ǻ���ģ��
	a = b;
	b = t;
	cout << "����ģ�屻������\n";
	//������һ��ͨ������ʱ,���ṩ��ʽ��������ת��,�����ϸ��ƥ��,����template <typename T,typename T1>
}

void A_function_template(int& a, int& b) {
	int t = a;
	a = b;
	b = a;
	cout << "int��ͨ���غ�����������\n";
	//����ģ�����ͨ���غ�������,��ƥ��,��������ͨ���غ���
}

void A_function_template(char &a,int &b) {
	int t = a;
	a = b; 
	b = a;
	cout << "��ͨ���غ�����������\n";
	//����ģ�����ͨ���غ�������,��ƥ��,��������ͨ���غ���
	//���ͺ���ͨ���غ�����ƥ��ʱ,���õ�����ͨ���غ���
}

//��ģ�����
//��һ��
int Max(int a, int b)
{
	cout << "���� int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	cout << "���� T Max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c) {
	cout << "���� T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);//������һ��Ҳ�ܽ���Ƕ��
}

//�ڶ���
int Max1(int a, int b)
{
	cout << "���� int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T1, typename T2>
T1 Max1(T1 a, T2 b)
{
	cout << "���� T Max1(T1 a, T2 b)" << endl;
	return a > b ? a : b;
}


void Template_functionsand_function_overloads() {
	char c = 'c';
	int i = 65;//A
	int a = 55;
	float n= 1.0;
	float m = 2.0;
	A_function_template(c, i);//�������ͺ���ͨ���غ�����ƥ��
	A_function_template(a, i);//����ģ������ͨ���غ�������,��ƥ��,����������ѡ����ͨ���غ���
	A_function_template<>(a, i);//��<> �����б�,<int>,���õ���ģ�庯��,���Լ�ѡ��
	A_function_template(n,m);//�������ģ���������õ�ƥ��,�ͻ�ʹ�ú���ģ��

	cout << "-------------------------------\n";
	//��ģ�����
	char cc = 'a';
	//�������ģ���������õ�ƥ�䣬ʹ�ú���ģ��
	//Max1(cc, a);
	//Max(1.0, 2.0);

	Max(3.0, 4.0, 5.0);
	/*
	����ģ�����ͨ������һ�𣬵��ù��� 
	1 ����ģ���������ͨ����һ��������
	2 C++���������ȿ�����ͨ����
	3 �������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��
	4 ����ͨ����ģ��ʵ���б���﷨�޶�������ֻͨ��ģ��ƥ��
	*/
}