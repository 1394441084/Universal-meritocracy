#pragma once
#include "��.h"

//�ֳ�.h��.cpp�ļ�Ҳ��һ��,ֻ����û�зֿ�����
//����ģ��ŵ��ⲿʵ��:
template <typename T>//����ǰ��������
D<T>::D(T t) {//��ĳ�Ա����ǰ�޶���˵�����������������б�
	this->t = t;
}

template <typename T>
T D<T>::gett() {
	return t;//��Ա�����г���ģ����Ķ���ʱ���������������б�
}

template <typename T>
D<T> D<T>::operator+(const D& d) {//������Ķ�����������������б�
	D tmp;//����ڲ�������ʾ����,Ҳ������ʽ
	tmp.t = d.t + this->t;//��Ա�����ڲ�û���޶�
	return tmp;
}

template <typename T>
void D<T>::printfD()const{
	cout << this->t << endl;
}

