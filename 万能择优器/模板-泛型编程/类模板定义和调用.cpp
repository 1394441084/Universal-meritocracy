#include <iostream>

using namespace std;

template <typename T>
class A {
public:
	//���Խ����������滻����������,��:A(T t= 0)
	A(int t= 0) {//�����б���������
		this->t = t;
	}
	//��:int gett()
	T gett() {//������������
		return t;
	}

private:
	//��:
	int t;//��Ա������������

};

//������Ϊ�����Ĳ���,void callA(A a);//ȱ����ģ������б�
void callA(A<int> &a) {
	cout << a.gett() << endl;
}

//��ģ��Ķ���͵���
void Class_templates_are_definedand_invoked(){
	//ʹ�ú���ģ�岻��Ҫָ������,��ʹ����ģ��ȴҪ
	//��ģ�嶨�������,������ʽָ������
	//A b(77);//ȱ����ģ������б�
	A<int> a(666);
	//ģ�������ʹ���˹��캯��,��������ǰ��Ĺ��캯�����ù���

	callA(a);//ģ������Ϊ��������
	cout << a.gett() << endl;
}