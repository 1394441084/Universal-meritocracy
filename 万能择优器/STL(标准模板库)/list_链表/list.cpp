#include <list> //双向链表容器
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
/*
list是双向链表容器,但每个元素独立存在却能返回邻居地址,由特殊指针(迭代器接收),
因为元素独立存在,所以迭代器不能直接+1或者+2以上,只能++或者--操作,请注意越界;
它比vector中间插入,删除更高效,增减空间更合理;
无法使用[],.at()方式访问操作.只能迭代器来进行;
*/
template <typename T>
void 打印(const char* name, const list<T>& v1) {
	stringstream str;
	if (v1.empty()) { str << name << "的容器为空,你搞毛呀!" << endl; cout << str.str(); return; }
	str << name << "的元素个数:" << v1.size() << endl;
	//!v1.empty() ? str << name << "容器不为空\n":str << name << "容器为空\n";
	//vector.capacity();//预先分配空间
	//list没有.capacity();方法,所以并没预先分配空间,是按需分配

	//list<T>::const_iterator it;//使用这编译不通过
	typename list<T>::const_iterator it;//加上typename是告知编译器,这个变量使用了模板
	int i = 0;
	for (it = v1.begin(); it != v1.end(); it++) {
		str << name << "[" << i++ << "]:" << *it << "  ";
	}
	str << endl;
	cout<< str.str();
}
void list构造() {
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
	打印("d1", d1);
	list<int> d2(d1);
	打印("d2", d2);
	list<int>::iterator it = ++dd.begin();
	list<int> d3(++it, --dd.end());//迭代器只能使用++,不能使用+1操作//也是包含头不包含尾的操作
	打印("d3", d3);//3 4 5 6 7 8 9
}
void list头尾添加删除() {
	list<int> d1;
	d1.push_back(1);//尾部添加单个数据
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(5);

	d1.pop_front();//删除单个头元素
	d1.pop_front();
	打印("d1",d1);
	d1.push_front(11);//插入单个头元素
	d1.push_front(12);
	打印("d1", d1);
	d1.pop_back();//删除单个尾元素
	d1.pop_back();
	打印("d1", d1);
}
void list数据的存取(){
	list<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(5);
	int 头元素 = d1.front();//1
	int 尾元素 = d1.back();//5
	d1.front() = 11;//头元素变为11
	d1.back() = 19;//尾元素变为19
	cout << "头元素=" << 头元素 << " 尾元素=" << 尾元素 << endl;
	打印("d1", d1);
}
void list容器用法() {
	list<int> a, b, c, d;
	a.push_back(1);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(9);

	//b.assign(a.begin(), a.end());//1 3 5 7 9
	b.assign(++a.begin(), --a.end());//3 5 7
	//打印("b", b);
	c.assign(5, 8);//8 8 8 8 8
	//打印("c", c);
	d = a;//1 3 5 7 9
	//打印("d", d);
	//cout << "交换后\n";
	d.swap(c);
	//打印("d", d);//8 8 8 8 8 
	//打印("c", c);//1 3 5 7 9
	a.resize(4);//1 3 5 7
	//打印("a", a);
	a.resize(3, 99);//截短空间,指定赋值无意义
	//打印("a", a);//1 3 5
	a.resize(10, 99);//1 3 5 99 99 99 99 99 99 99
	//打印("a", a);
	c.insert(c.begin(), -1);//-1 1 3 5 7 9
	//打印("c", c);
	c.insert(++c.begin(),2,-2);//-1 -2 -2 1 3 5 7 9
	//打印("c", c);
	list<int>::iterator it = ++a.begin();
	++it;
	c.insert(c.begin(),a.begin(), ++it);//1 3 5 -1 -2 -2 1 3 5 7 9
	//打印("c", c);

	list<int>::iterator cit = ++c.begin();++cit; ++cit;
	//c.clear();//移除容器的所有数据
	//c.erase(c.begin(),cit);  //删除[beg,end)区间的数据，返回下一个数据的位置。//-1 -2 -2 1 3 5 7 9
	//c.erase(cit);//删除pos位置的数据，返回下一个数据的位置。//1 3 5 -2 -2 1 3 5 7 9
	//c.remove(-2);//删除容器中所有与elem值匹配的元素。//1 3 5 -1 1 3 5 7 9
	//遍历然后删除
	for (list<int>::iterator ct = a.begin(); ct != a.end();) {*ct == 99 ? ct = a.erase(ct) : ct++;}
	//a.reverse();//反转链表
	打印("a", a);
}
void list_main() {
	//list构造();
	//list头尾添加删除();
	//list数据的存取();
	list容器用法();
}