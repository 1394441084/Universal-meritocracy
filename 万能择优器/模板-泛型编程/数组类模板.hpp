#include "������ģ��(vector).h"

template <typename TT>
Vector<TT>::Vector() {
		m_len = 0;
		m_bese = NULL;
}

template <typename TT>
Vector<TT>::Vector(int size) {
	if (size > 0) {
		m_len = size;
		m_bese = new TT[m_len];
	}
}//���캯��

template <typename TT>
Vector<TT>::Vector(const Vector& other) {
	if (m_bese != NULL) delete[] m_bese;
	
	m_len = other.m_len;
	m_bese = new TT[m_len];

	for (int i = 0; i < m_len; i++) {
		m_bese[i] = other.m_bese[i];
	}
}//�������캯��

template <typename TT>
Vector<TT>::~Vector() {
	if (m_bese != NULL) {
		delete[] m_bese;
		m_bese = NULL;
	}
}//��������



//Vector<int> a1; a1[0]
template <typename TT>
TT& Vector<TT>::operator[](int i)const {
	return m_bese[i];//return *(m_bese+i)
}

template <typename TT>
Vector<TT>& Vector<TT>::operator=(const Vector<TT>& other) {
	if (m_bese != NULL) { delete[] m_bese; }

	m_len = other.m_len;
	m_bese = new TT[m_len];

	for (int i = 0; i < m_len; i++) {
		m_bese[i] = other[i];
	}
	return *this;
}

template <typename TT>
int Vector<TT>::getlen() {
	return m_len;
}//��ȡ�ڲ����Ԫ�ظ���


//ostream& operator<<<TT>(ostream& os, const Vector<TT>& other) {//�þͻ������ʾ����
template <typename TT>
ostream& operator<<(ostream& os, const Vector<TT>& other) {
	for (int i = 0; i < other.m_len; i++) {
		os << other.m_bese[i]<<" ";//Students a("����",18);
	}
	return os;
}

