#pragma once
#include <iostream>

using namespace std;

template <typename P>
class People
{
	//template <typename P>
	friend ostream& operator<<<P>(ostream& os, const People<P>& other);
public:
	People();
	People(int a_len=0);
	People(const People<P>& other);
	~People();

	int a_len_size()const;
	People<P>& operator=(const People<P>& other);
	P& operator[](int i)const;
	

private:
	int a_len;//多少个
	P* p_a_len=NULL;//开辟多少个
};

class man {
public:
	man() {age = 0;name = NULL;}
	man(const char* name1,const int age) {
		this->age = age;
		if (name1 == " " || name1 == NULL || name1 == "\0") {name1 = "空白";}
		int len = strlen(name1) +1;
		this->name = new char[len];
		strcpy_s(this->name, len, name1);
	}
	man(const man& a_man) {
		if (name != NULL)delete[] name;
		if (a_man.name == NULL) { name = NULL; age = 0; return; }
		age = a_man.age;
		//int len = ;
		if ((strlen(a_man.name) + 1) > 0) {
			name = new char[strlen(a_man.name) + 1];
			strcpy_s(name, strlen(a_man.name) + 1, a_man.name);
		}
	}
	~man() {if (name != NULL) { delete[] name; name = NULL; }}

	man& operator=(const man& a_man) {
		if (this == &a_man)return *this;
		if (name != NULL)delete[] name;
		if (a_man.name == NULL) {name = NULL;age = 0;}
		age = a_man.age;int len = strlen(a_man.name) + 1;
		name = new char[len];strcpy_s(name, len, a_man.name);
		return *this;}

	friend ostream& operator<<(ostream& os, const man& a_man) {
		if (a_man.name == NULL) {
			os << "name==NULL";
		}
		else {
			os << a_man.name << " " << a_man.age;
		}
		return os;
	}

private:
	int age=0;
	char* name=NULL;
};

template<typename P>
inline People<P>::People()
{
	a_len = 0;
	p_a_len = NULL;
}

template<typename P>
inline People<P>::People(int a_len)
{
	if (a_len > 0) {
		this->a_len = a_len;
		p_a_len = new P[a_len];
	}
}

template<typename P>
inline People<P>::People(const People<P>& other)
{
	if (p_a_len != NULL) delete[] p_a_len;
	if (other.a_len <= 0) {
		a_len = 0;
		p_a_len = NULL;
		return;
	}
	this->a_len = other.a_len;
	p_a_len = new P[a_len];
	for (int i = 0; i < a_len; i = i + 1) {
		p_a_len[i] = other.p_a_len[i];
	}
}

template<typename P>
inline People<P>::~People()
{
	if (p_a_len != NULL) {
		delete[] p_a_len;
		p_a_len = NULL;
	}
}

template<typename P>
inline int People<P>::a_len_size() const
{
	return a_len;
}

template<typename P>
inline People<P>& People<P>::operator=(const People<P>& other)
{
	if (p_a_len != NULL) delete[] p_a_len;//不是野指针,消灭先
	if (other.a_len <= 0) {//传来空值就拜拜
		a_len = 0;
		p_a_len = NULL;
		return;
	}
	this->a_len = other.a_len;
	p_a_len = new P[a_len];
	for (int i = 0; i < a_len; i = i + 1) {
		p_a_len[i] = other.p_a_len[i];
	}
}

template<typename P>
inline P& People<P>::operator[](int i) const
{
	if (i < 0)i = 0;
	return p_a_len[i];
}
