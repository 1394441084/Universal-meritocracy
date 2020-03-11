#pragma once
#include <iostream>
#include <Windows.h>
#include <set>

using namespace std;
//自定义两虚拟类型(无默认,默认使用set容器构造)
template <typename _Ty,
	typename _Container = set<_Ty>>
class sizeFilter{ //大小过滤器
public:
	typedef sizeFilter<_Ty, _Container>   _Myt;//使用sizeFilter<_Ty, _Container> 太长,影响着读写,所以进行类型定义
	/*
	typename _Container 使用模板,因二次编译,需告诉编译器,容器使用模板,编译找这里的虚拟类型;
	typedef typename _Container::size_type;  相当于:typedef typename set<_Ty>::size_type
	因为set容器里有一个整型数size_type类型获取大小,所以以此基础定义为属于sizeFilter容器的size_type;
	*/
	typedef typename _Container::size_type  size_type;
	typedef typename _Container::value_type  value_type;//使用_Ty不是很明白,所以引用set容器的内置类型,set<这个>
public:
	sizeFilter():sizeFilter::con(){
		//默认构造函数,初识化内置容器
		cout << "//构造函数,通过指定容器来构造0" << endl;
	}
	sizeFilter(const _Myt &_Right):sizeFilter::con(_Right.con){
		//构造函数,通过指定sizeFilter容器来构造
		
	}
	sizeFilter(const _Container& _Cont):sizeFilter::con(_Cont) {
		//构造函数,通过指定容器来构造
		cout << "//构造函数,通过指定容器来构造" << endl;
	}
	_Myt& operator=(const _Myt & _Right){
		//使用另一个sizeFilter赋值(初始化)
		con = _Right.con;
		return *this;
	}
		bool empty()const {
		//测试sizeFilter容器是否为空
		return con.empty();
	}
	size_type size()const {
		//测试sizeFilter容器的长度
		return con.size();
	}
	bool insert(const value_type& _Val){//使用这个也可以
	//bool insert(const _Ty& _Val) {//使用这个也可以
		/*使用效果演示如:
		set<_Ty> s;
		_Ty 变量名;
		bool of;
		of=s.insert(变量名)
		*/
		//pair<_Container::iterator, bool> pi = con.insert(_Val);//使用pair不兼容multiset
		//pi.second ? return true : return false;
		/*
		if (pi.second) {
			cout << "插入" << _Val << "成功\n";
			return true;
		}
		else {
			cout << "插入" << _Val << "失败\n";
			return false;
		}*/
		
		typename _Container::iterator it = con.insert(con.begin(),_Val);
		//con.count(_Val);
		if (it != con.end()) {
			cout << "插入" << _Val << "成功\n";
			return true;
		}
		else {
			cout << "插入" << _Val << "失败\n";
			return false;
		}
	}
	bool erase(const value_type& _Val) {//删除元素
		//con.erase(_Val) > 0 ? return true : return false;
		if (con.erase(_Val) > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//_Ty& getMin() {//容器为空不适用
	pair<value_type,bool> getMin()const{//获取最小值
		pair<value_type, bool> ret;
		//typename _Container::iterator it = con.begin();
		//if (con.begin() > 0) {//迭代器不能在外面,一旦容器为空,会使程序崩溃!!!

		if (con.size() > 0) {//存在最小值
			typename _Container::iterator it = con.begin();
			ret.first = *it;
			ret.second = true;
			return ret;
		}
			ret.second = false;
			return ret;
	}
	pair<value_type, bool> getbig()const {//获取最大值
		pair<value_type, bool> ret;
		if (con.size()>0) {//存在值
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

