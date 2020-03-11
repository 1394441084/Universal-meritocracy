#pragma once
#include <iostream>
#include <Windows.h>
#include <set>

using namespace std;
//�Զ�������������(��Ĭ��,Ĭ��ʹ��set��������)
template <typename _Ty,
	typename _Container = set<_Ty>>
class sizeFilter{ //��С������
public:
	typedef sizeFilter<_Ty, _Container>   _Myt;//ʹ��sizeFilter<_Ty, _Container> ̫��,Ӱ���Ŷ�д,���Խ������Ͷ���
	/*
	typename _Container ʹ��ģ��,����α���,����߱�����,����ʹ��ģ��,�������������������;
	typedef typename _Container::size_type;  �൱��:typedef typename set<_Ty>::size_type
	��Ϊset��������һ��������size_type���ͻ�ȡ��С,�����Դ˻�������Ϊ����sizeFilter������size_type;
	*/
	typedef typename _Container::size_type  size_type;
	typedef typename _Container::value_type  value_type;//ʹ��_Ty���Ǻ�����,��������set��������������,set<���>
public:
	sizeFilter():sizeFilter::con(){
		//Ĭ�Ϲ��캯��,��ʶ����������
		cout << "//���캯��,ͨ��ָ������������0" << endl;
	}
	sizeFilter(const _Myt &_Right):sizeFilter::con(_Right.con){
		//���캯��,ͨ��ָ��sizeFilter����������
		
	}
	sizeFilter(const _Container& _Cont):sizeFilter::con(_Cont) {
		//���캯��,ͨ��ָ������������
		cout << "//���캯��,ͨ��ָ������������" << endl;
	}
	_Myt& operator=(const _Myt & _Right){
		//ʹ����һ��sizeFilter��ֵ(��ʼ��)
		con = _Right.con;
		return *this;
	}
		bool empty()const {
		//����sizeFilter�����Ƿ�Ϊ��
		return con.empty();
	}
	size_type size()const {
		//����sizeFilter�����ĳ���
		return con.size();
	}
	bool insert(const value_type& _Val){//ʹ�����Ҳ����
	//bool insert(const _Ty& _Val) {//ʹ�����Ҳ����
		/*ʹ��Ч����ʾ��:
		set<_Ty> s;
		_Ty ������;
		bool of;
		of=s.insert(������)
		*/
		//pair<_Container::iterator, bool> pi = con.insert(_Val);//ʹ��pair������multiset
		//pi.second ? return true : return false;
		/*
		if (pi.second) {
			cout << "����" << _Val << "�ɹ�\n";
			return true;
		}
		else {
			cout << "����" << _Val << "ʧ��\n";
			return false;
		}*/
		
		typename _Container::iterator it = con.insert(con.begin(),_Val);
		//con.count(_Val);
		if (it != con.end()) {
			cout << "����" << _Val << "�ɹ�\n";
			return true;
		}
		else {
			cout << "����" << _Val << "ʧ��\n";
			return false;
		}
	}
	bool erase(const value_type& _Val) {//ɾ��Ԫ��
		//con.erase(_Val) > 0 ? return true : return false;
		if (con.erase(_Val) > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//_Ty& getMin() {//����Ϊ�ղ�����
	pair<value_type,bool> getMin()const{//��ȡ��Сֵ
		pair<value_type, bool> ret;
		//typename _Container::iterator it = con.begin();
		//if (con.begin() > 0) {//����������������,һ������Ϊ��,��ʹ�������!!!

		if (con.size() > 0) {//������Сֵ
			typename _Container::iterator it = con.begin();
			ret.first = *it;
			ret.second = true;
			return ret;
		}
			ret.second = false;
			return ret;
	}
	pair<value_type, bool> getbig()const {//��ȡ���ֵ
		pair<value_type, bool> ret;
		if (con.size()>0) {//����ֵ
			typename _Container::iterator it = con.end();
			ret.first = *(--it);
			ret.second = true;
			return ret;
		}
			ret.second = false;
			return ret;
	}

protected:
	_Container con;
//private:

};

