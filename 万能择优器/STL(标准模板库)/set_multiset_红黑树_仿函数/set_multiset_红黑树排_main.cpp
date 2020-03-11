#include <set> //set��multiset����(�Զ�����,��ο����������),�޷�ʹ��.at()��[]����
#include <iostream>
#include "set_multiset.h"

void set_multiset���();
void set����();
void set��º���();
void set�Ĳ����pair���÷�();
void set_��С_ɾ��_����();

template <typename T,typename TT>
void ��ӡ(const char* name,const set<T,TT> &setint) {
	//ע�⣺�κ�ʱ����ģ��(template)��ʹ��һ��Ƕ�״�����������,?��Ҫ��ǰһ��λ��,?��ӹؼ���typename;
	stringstream str;
	typename set<T,TT>::iterator it = setint.begin();
	for (; it != setint.end(); it++) {
		str << *it << " ";
	}
	str << endl;
	cout <<name<<"������:"<<endl<<str.str();
}

int main(void) {
	//set_multiset���();
	//set����();
	//set��º���();
	//set�Ĳ����pair���÷�();
	set_��С_ɾ��_����();

	system("pause");
	return 0;
}

void set_multiset���() {
	set<int> setint;
	multiset<int> multisetint;

	for (int i = 0; i < 10; i++) {
		multisetint.insert(100 - i);
	}
	//setint.insert(99);//set�������������ͬһԪ��
	multisetint.insert(99);//multisetint�����������ͬһԪ��,ͬԪ�ؽ�������
	multiset<int>::iterator it = multisetint.begin();
	for (; it != multisetint.end(); it++) {
		cout << *it << " ";
	}
}

void set����() {
	set<int> setint;
	for (int i = 5; i>0; i--) {
		setint.insert(i);
	}
	set<int> setint1(setint);//1 2 3 4 5
	set<int> setint2=setint1;//1 2 3 4 5
	setint2.insert(666);//��ӵ���Ԫ��
	setint2.swap(setint1);//����
	��ӡ("setint2", setint2);
	��ӡ("setint1", setint1);
}

void set��º���() {
	//less<int> //�º���,ȥ���붨���
	//less��������ʵ�ֱȽ�,Ϊ�����ṩ���� ��<��
	//set<int,less<int>> setint;
	//set<int> setint;
	set<int, greater<int>> setint;//��>�� 
	for (int i = 5; i > 0; i--) {
		setint.insert(i);
	}
	��ӡ("setint", setint);//1 2 3 4 5

	//Studentss s("s", 0);
	Studentss s1("s1", 1);
	Studentss s2("s2", 2);

	//set<Studentss> setstu;//Ĭ��set<Studentss,less<Studentss>> setstu;����,���Եײ�ʵ��������<
	//set<Studentss, greater<Studentss>> setstu;//�������,�Ӵ�С
	set<Studentss,FunStudent> setstu;//ɧ��
	setstu.insert(Studentss("s", 15));
	setstu.insert(Studentss("s1", 12));
	setstu.emplace_hint(setstu.begin(), s2);

	��ӡ("setstu", setstu);
	//less,greater���Ǻ�������,�ֽзº���
	//������������һ��ʹ��
	FunStudent funstu;
	bool ret=funstu(s1, s2);
	cout << "�ȽϽ��:" << ret << endl;
}

void set�Ĳ����pair���÷�() {
	/*
	pair��ʾһ�����飬��������ֵ��Ϊһ����Ԫ��������ֵ������һ��
pair<T1,T2>������ŵ�����ֵ�����ͣ����Բ�һ����Ҳ����һ������T1Ϊint��T2Ϊfloat��T1,T2Ҳ�������Զ����ࡣ
	*/
	set<int> setint;
	for (int i = 5; i > 0; i--) {
		pair<set<int>::iterator, bool> ret = setint.insert(i);//�жϲ����Ƿ�ɹ�
		ret.second ? cout << i<<"����ɹ�\n": cout << i << "����ʧ��\n";
		setint.insert(i);
	}

	//�����Ƿ�ɹ�
	//bool ret= setint.insert(5);//���ز�����bool
	pair<set<int>::iterator, bool> ret =setint.insert(5);
	cout << *(ret.first) << endl;//������ (���ص������ռ�����)
	cout << ret.second << endl;//bool //0 ��������*(ret.first)

}

void set_��С_ɾ��_����() {
	set<int> setint;
	//cout << "max_size:" << setint.max_size() << endl;//���Ա�������Ԫ�صĸ���
	for (int i = 10; i > 0; i--) {
		setint.insert(i);
	}
	//cout << "max_size:" << setint.max_size() << endl;

	//setint.clear();//�������
	//setint.erase();//ɾ������ || ɾ�������ĳһԪ�� || ɾ����������ָԪ��(��һ)���ص����� 

	set<int>::iterator it=setint.find(15);//���Ҿ����ĳһԪ�ز�����ָ�����ĵ�����
	if (it != setint.end()) {//find �Ƿ���ҵ�Ԫ��,����ͨ�����صĵ�������and()�������бȽ�
		//end()������ǲ����ڵı߽�,�����������ж�
		int e = *it;
		cout << e << endl;
	}
	else {
		cout << "15������\n";
	}

	int icount=setint.count(5);//���ؾ����ĳһԪ�ص�Ԫ�ظ���
	cout << icount << endl;

	set<int>::iterator it1 = setint.lower_bound(5);//���ص�һ��>=����ĳһԪ�صĵ����� 5
	set<int>::iterator it2 = setint.upper_bound(5);//���ص�һ��>����ĳһԪ�صĵ�����  6
	int e1 = *it1;		int e2 = *it2;
	cout << "e1=" << e1 << "\te2=" << e2 << endl;

	pair<set<int>::iterator,set<int>::iterator> ii=setint.equal_range(10);//���������޵�����������,��:����5(5)  ������5(6) ,����װ��pair��
	if (ii.second != setint.end()) {
		//ii.first�ҵ�10ͣס��        //������.end()������,ii.second����������,����!=end()
		cout << *ii.first << endl;    cout << *ii.second << endl;
	}
	else {
		cout << "������\n";
	}
}