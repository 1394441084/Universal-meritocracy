#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <sstream>
#include <vector> //����.STL(��̬����)
#include <algorithm>//�㷨.STL

using namespace std;

template <typename T>
string ��ӡ(const char* name,const vector<T> v1) {
	stringstream str;
	str << name<<"��Ԫ�ظ���:" << v1.size() << endl;//Ԫ�ظ���,�����Ԫ���ж����Ƕ���.�����������Զ����ݵ�,ֻ��>=����Ԫ�ظ���
	str << name<<"������С:" << v1.capacity() << endl;//�����������㷨�Զ����ݵ�,Ϊ�������Ԫ�ض�����ȫ����������Ч�ʵ��µ��Զ������㷨(n)
	for (int i = 0; i < v1.size(); i++) {
		str << name<<"[" << i << "]:" << v1[i] << "  ";
	}
	str << endl;
	return str.str();
}

void ��ͨ����vector() {
	//vector ����Ĭ�Ϲ���,����v1[0] = 1;
	while (0) { 
	vector<int> v1;
	cout << "v1��Ԫ�ظ���:" << v1.size() << endl;
	cout << "v1������С:" << v1.capacity() << endl;
	//v1[0] = 1;//������ʹ��Ĭ�Ϲ���ʱ,����ֱ��ͨ���±����
	v1.push_back(1);//�����Ŀռ���
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	cout << "v1��Ԫ�ظ���:" << v1.size() << endl;//5;Ԫ�ظ���,�����Ԫ���ж����Ƕ���.�����������Զ����ݵ�,ֻ��>=����Ԫ�ظ���
	cout << "v1������С:" << v1.capacity() << endl;//6;�����������㷨�Զ����ݵ�,Ϊ�������Ԫ�ض�����ȫ����������Ч�ʵ��µ��Զ������㷨(n)
	break;
	}

	//vector ������ι��캯��
	while (0) {
	//ָ����С,���10��Ԫ�ص�����
	vector<int> v1(10);//����ʱ�ͷ���ռ�ͬʱ����Ԫ��(ȫΪ0)
	vector<int> v2(10,666);////����ʱ�ͷ���ռ�ͬʱ����Ԫ��(ȫΪ666)
	//vector<int> v3(v2);//v3��v2�ĸ�ֵƷ
	vector<int> v3(v2.begin(), v2.end()); //��vector<int> v3(v2); һ��
	vector<int> v4(v2.begin()+3,v2.end());//ָ�����乹��
	v2[0] = 1;//��ֵ
	v2[1] = 2;

	int tese[] = { 1,2,3,4,5,6 };
	vector<int> v5(tese, tese + 2);//�����׵�ַ,�׵�ַ+2,�ƶ�2λ;�Ƶ�3��ֹ,������3

	/*
	//��ӡ��
	cout << "v1��Ԫ�ظ���:" << v1.size() << endl;
	cout << "v1������С:" << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1["<<i<<"]:"<<v1[i] <<"  ";
	}
	cout << endl;
	cout << "v2������С:" << v2.capacity() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]:" << v2[i] << "  ";
	}
	cout << endl;
	cout << "v3������С:" << v3.capacity() << endl;
	for (int i = 0; i < v3.size(); i++) {
		cout << "v3[" << i << "]:" << v3[i] << "  ";
	}
	cout << endl;
	cout << "v4������С:" << v4.capacity() << endl;
	for (int i = 0; i < v4.size(); i++) {
		cout << "v4[" << i << "]:" << v4[i] << "  ";
	}
	cout << endl;*/
	cout << ��ӡ("v1", v1);
	cout << ��ӡ("v2", v2);
	cout << ��ӡ("v3", v3);
	cout << ��ӡ("v4", v4);
	cout << ��ӡ("v5", v5);
	

	break; 
	}

	//vector ������С
	while (0) {
		vector<int> v2(10, 666);
		vector<int> v3(v2.begin(), v2.end()); 
		vector<int> v1;
		cout << "v1��Ԫ�ظ���:" << v1.size() << endl;//Ԫ�ظ���,�����Ԫ���ж����Ƕ���.�����������Զ����ݵ�,ֻ��>=����Ԫ�ظ���
		cout << "v1������С:" << v1.capacity() << endl;//�����������㷨�Զ����ݵ�,Ϊ�������Ԫ�ض�����ȫ����������Ч�ʵ��µ��Զ������㷨(n)
		if (v1.empty()) {
			cout << "v1�����ռ�Ϊ��!\n";
		}
		//v2.assign(2, 888);//��ֵ,�ı�ԭ��Ԫ�ظ�����ֵ
	//v2.assign(v3.begin(), v3.end());//ʹ�õ�������ֵ
	//v2.assign(tese, tese + 3);//ʹ�����鸳ֵ
		v2 = v3;//���ø�ֵ����
		cout << "����.assign();��:\n";
		cout << ��ӡ("v2", v2);

		//���µ���vector�Ĵ�С
		v2.resize(2);//���¶����С;��ͷ��ʼ��.v2[0],v2[1],����;��С�ռ䲢��ֵ,������;
		//v2.resize(13,888);//���¶���ռ䲢�������Ŀռ丳ֵ;13�ռ�,�¿��ռ�ֵΪ888;
		//v2.resize(13);//����ָ����ֵ,Ĭ��ֵΪ��
		cout << "����.resize();��:\n";
		cout << ��ӡ("v2", v2);

		break;
	}

	//vector β����Ӻ�ɾ��Ԫ��
	while (0) {
		vector<int> v2(10, 666);
		v2.push_back(999);//β�����;typename _Ty&& _Val(��ֵ����,C++11������)
		v2.pop_back();//β��ɾ��

		v2[0] = 777;//ʹ���±����
		v2.at(2) = 854;//.at();���ص�������
		//�����ַ�������,���ע��Խ��

		for (int i = 0; i < v2.size(); i++) {
			cout<<  "v2[" << i << "]:" << v2.at(i)<< "  ";
		}
		cout << endl;
		cout << "v2�ĵ�һ��Ԫ��"<<v2.front() << endl;
		cout <<"v2�����һ��Ԫ��" <<v2.back() << endl;
		v2.front()=99;//���ص�������,���޸�ֵ
		v2.back()=78;
		cout << "v2�ĵ�һ��Ԫ��" << v2.front() << endl;
		cout << "v2�����һ��Ԫ��" << v2.back() << endl;
		for (int i = 0; i < v2.size(); i++) {
			cout << "v2[" << i << "]:" << v2.at(i) << "  ";
		}
		break;
	}

	//vector �Ĳ����ɾ��  //����//rbegin()ָ�����end()λ��,rend()ָ��begin();//���������
	while (1) {
		vector<int> v1(10, 666);
		//���뵥��Ԫ��: //�����Ԫ�ض�������,10�ռ��11�ռ�
		v1.insert(v1.begin(),888);//.insert(������,�������ֵ);v1.begin()+1,λ�õ�1

		//������Ԫ��: //����ֵ�ǵ�����
		//vector<int>::iterator it = v1.insert(v1.begin(), 3, 886);//.insert(������,�������, �������ֵ);
		v1.insert(v1.begin(), 3, 886);

		int tese[] = { 1,2,3,4,5,6 };
		vector<int> v5(tese, tese + 5);
		v1.insert(v1.begin() + 1, v5.begin(), v5.end());//.insert(������,�������, �����յ�);

		cout << ��ӡ("v1", v1);

		//v1.clear();//����vectorɾ����
		v1.erase(v1.begin());//ɾ������Ԫ��.erase(ɾ��Ԫ��λ��);
		//v1.erase(v1.begin(),v1.begin()+2);//.erase(��ʼλ��,������λ��);//ɾ�����Ԫ��

		cout << ��ӡ("v1", v1);
		cout << "\n�������v5\n";
		//rbegin()ָ�����end()λ��,rend()ָ��begin();//���������
		vector<int>::reverse_iterator rit = v5.rbegin();//��ת�ĵ�����
		for (; rit != v5.rend(); rit++) {
			cout << *rit << "  ";
		}
		cout << "\n";
		break;
	}
}

