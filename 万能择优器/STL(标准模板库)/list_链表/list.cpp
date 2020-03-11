#include <list> //˫����������
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
/*
list��˫����������,��ÿ��Ԫ�ض�������ȴ�ܷ����ھӵ�ַ,������ָ��(����������),
��ΪԪ�ض�������,���Ե���������ֱ��+1����+2����,ֻ��++����--����,��ע��Խ��;
����vector�м����,ɾ������Ч,�����ռ������;
�޷�ʹ��[],.at()��ʽ���ʲ���.ֻ�ܵ�����������;
*/
template <typename T>
void ��ӡ(const char* name, const list<T>& v1) {
	stringstream str;
	if (v1.empty()) { str << name << "������Ϊ��,���ëѽ!" << endl; cout << str.str(); return; }
	str << name << "��Ԫ�ظ���:" << v1.size() << endl;
	//!v1.empty() ? str << name << "������Ϊ��\n":str << name << "����Ϊ��\n";
	//vector.capacity();//Ԥ�ȷ���ռ�
	//listû��.capacity();����,���Բ�ûԤ�ȷ���ռ�,�ǰ������

	//list<T>::const_iterator it;//ʹ������벻ͨ��
	typename list<T>::const_iterator it;//����typename�Ǹ�֪������,�������ʹ����ģ��
	int i = 0;
	for (it = v1.begin(); it != v1.end(); it++) {
		str << name << "[" << i++ << "]:" << *it << "  ";
	}
	str << endl;
	cout<< str.str();
}
void list����() {
	//list<int> d;
	//cout << "list<int>d size:" << d.size() << endl;//0
	list<int> dd;
	dd.push_back(1);
	dd.push_back(2);
	dd.push_back(3);
	dd.push_back(4);
	dd.push_back(5);
	dd.push_back(6);
	dd.push_back(7);
	dd.push_back(8);
	dd.push_back(9);
	dd.push_back(10);

	list<int> d1(10, 66);
	��ӡ("d1", d1);
	list<int> d2(d1);
	��ӡ("d2", d2);
	list<int>::iterator it = ++dd.begin();
	list<int> d3(++it, --dd.end());//������ֻ��ʹ��++,����ʹ��+1����//Ҳ�ǰ���ͷ������β�Ĳ���
	��ӡ("d3", d3);//3 4 5 6 7 8 9
}
void listͷβ���ɾ��() {
	list<int> d1;
	d1.push_back(1);//β����ӵ�������
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(5);

	d1.pop_front();//ɾ������ͷԪ��
	d1.pop_front();
	��ӡ("d1",d1);
	d1.push_front(11);//���뵥��ͷԪ��
	d1.push_front(12);
	��ӡ("d1", d1);
	d1.pop_back();//ɾ������βԪ��
	d1.pop_back();
	��ӡ("d1", d1);
}
void list���ݵĴ�ȡ(){
	list<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(5);
	int ͷԪ�� = d1.front();//1
	int βԪ�� = d1.back();//5
	d1.front() = 11;//ͷԪ�ر�Ϊ11
	d1.back() = 19;//βԪ�ر�Ϊ19
	cout << "ͷԪ��=" << ͷԪ�� << " βԪ��=" << βԪ�� << endl;
	��ӡ("d1", d1);
}
void list�����÷�() {
	list<int> a, b, c, d;
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(9);

	//b.assign(a.begin(), a.end());//1 3 5 7 9
	b.assign(++a.begin(), --a.end());//3 5 7
	//��ӡ("b", b);
	c.assign(5, 8);//8 8 8 8 8
	//��ӡ("c", c);
	d = a;//1 3 5 7 9
	//��ӡ("d", d);
	//cout << "������\n";
	d.swap(c);
	//��ӡ("d", d);//8 8 8 8 8 
	//��ӡ("c", c);//1 3 5 7 9
	a.resize(4);//1 3 5 7
	//��ӡ("a", a);
	a.resize(3, 99);//�ض̿ռ�,ָ����ֵ������
	//��ӡ("a", a);//1 3 5
	a.resize(10, 99);//1 3 5 99 99 99 99 99 99 99
	//��ӡ("a", a);
	c.insert(c.begin(), -1);//-1 1 3 5 7 9
	//��ӡ("c", c);
	c.insert(++c.begin(),2,-2);//-1 -2 -2 1 3 5 7 9
	//��ӡ("c", c);
	list<int>::iterator it = ++a.begin();
	++it;
	c.insert(c.begin(),a.begin(), ++it);//1 3 5 -1 -2 -2 1 3 5 7 9
	//��ӡ("c", c);

	list<int>::iterator cit = ++c.begin();++cit; ++cit;
	//c.clear();//�Ƴ���������������
	//c.erase(c.begin(),cit);  //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�//-1 -2 -2 1 3 5 7 9
	//c.erase(cit);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�//1 3 5 -2 -2 1 3 5 7 9
	//c.remove(-2);//ɾ��������������elemֵƥ���Ԫ�ء�//1 3 5 -1 1 3 5 7 9
	//����Ȼ��ɾ��
	for (list<int>::iterator ct = a.begin(); ct != a.end();) {*ct == 99 ? ct = a.erase(ct) : ct++;}
	//a.reverse();//��ת����
	��ӡ("a", a);
}
void list_main() {
	//list����();
	//listͷβ���ɾ��();
	//list���ݵĴ�ȡ();
	list�����÷�();
}