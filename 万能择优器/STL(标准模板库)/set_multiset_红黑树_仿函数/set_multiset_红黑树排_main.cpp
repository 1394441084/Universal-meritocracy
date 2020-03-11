#include <set> //set和multiset容器(自动排序,请参考红黑树排序),无法使用.at()和[]方法
#include <iostream>
#include "set_multiset.h"

void set_multiset差别();
void set构造();
void set与仿函数();
void set的插入和pair的用法();
void set_大小_删除_查找();

template <typename T,typename TT>
void 打印(const char* name,const set<T,TT> &setint) {
	//注意：任何时候在模板(template)中使用一个嵌套从属类型名称,?需要在前一个位置,?添加关键字typename;
	stringstream str;
	typename set<T,TT>::iterator it = setint.begin();
	for (; it != setint.end(); it++) {
		str << *it << " ";
	}
	str << endl;
	cout <<name<<"的数据:"<<endl<<str.str();
}

int main(void) {
	//set_multiset差别();
	//set构造();
	//set与仿函数();
	//set的插入和pair的用法();
	set_大小_删除_查找();

	system("pause");
	return 0;
}

void set_multiset差别() {
	set<int> setint;
	multiset<int> multisetint;

	for (int i = 0; i < 10; i++) {
		multisetint.insert(100 - i);
	}
	//setint.insert(99);//set容器不允许出现同一元素
	multisetint.insert(99);//multisetint容器允许出现同一元素,同元素紧邻排序
	multiset<int>::iterator it = multisetint.begin();
	for (; it != multisetint.end(); it++) {
		cout << *it << " ";
	}
}

void set构造() {
	set<int> setint;
	for (int i = 5; i>0; i--) {
		setint.insert(i);
	}
	set<int> setint1(setint);//1 2 3 4 5
	set<int> setint2=setint1;//1 2 3 4 5
	setint2.insert(666);//添加单个元素
	setint2.swap(setint1);//交换
	打印("setint2", setint2);
	打印("setint1", setint1);
}

void set与仿函数() {
	//less<int> //仿函数,去进入定义深究
	//less函数对象实现比较,为排序提供依据 右<左
	//set<int,less<int>> setint;
	//set<int> setint;
	set<int, greater<int>> setint;//右>左 
	for (int i = 5; i > 0; i--) {
		setint.insert(i);
	}
	打印("setint", setint);//1 2 3 4 5

	//Studentss s("s", 0);
	Studentss s1("s1", 1);
	Studentss s2("s2", 2);

	//set<Studentss> setstu;//默认set<Studentss,less<Studentss>> setstu;操作,所以底层实现需重载<
	//set<Studentss, greater<Studentss>> setstu;//逆序输出,从大到小
	set<Studentss,FunStudent> setstu;//骚气
	setstu.insert(Studentss("s", 15));
	setstu.insert(Studentss("s1", 12));
	setstu.emplace_hint(setstu.begin(), s2);

	打印("setstu", setstu);
	//less,greater都是函数对象,又叫仿函数
	//函数对象像函数一样使用
	FunStudent funstu;
	bool ret=funstu(s1, s2);
	cout << "比较结果:" << ret << endl;
}

void set的插入和pair的用法() {
	/*
	pair表示一个对组，它将两个值视为一个单元，把两个值捆绑在一起。
pair<T1,T2>用来存放的两个值的类型，可以不一样，也可以一样，如T1为int，T2为float。T1,T2也可以是自定义类。
	*/
	set<int> setint;
	for (int i = 5; i > 0; i--) {
		pair<set<int>::iterator, bool> ret = setint.insert(i);//判断插入是否成功
		ret.second ? cout << i<<"插入成功\n": cout << i << "插入失败\n";
		setint.insert(i);
	}

	//插入是否成功
	//bool ret= setint.insert(5);//返回并不是bool
	pair<set<int>::iterator, bool> ret =setint.insert(5);
	cout << *(ret.first) << endl;//迭代器 (返回的容器空间内容)
	cout << ret.second << endl;//bool //0 容器中有*(ret.first)

}

void set_大小_删除_查找() {
	set<int> setint;
	//cout << "max_size:" << setint.max_size() << endl;//可以保存最大的元素的个数
	for (int i = 10; i > 0; i--) {
		setint.insert(i);
	}
	//cout << "max_size:" << setint.max_size() << endl;

	//setint.clear();//清空容器
	//setint.erase();//删除区间 || 删除具体的某一元素 || 删除迭代器所指元素(单一)返回迭代器 

	set<int>::iterator it=setint.find(15);//查找具体的某一元素并返回指向它的迭代器
	if (it != setint.end()) {//find 是否查找到元素,可以通过返回的迭代器和and()方法进行比较
		//end()代表的是不存在的边界,利用这点进行判断
		int e = *it;
		cout << e << endl;
	}
	else {
		cout << "15不存在\n";
	}

	int icount=setint.count(5);//返回具体的某一元素的元素个数
	cout << icount << endl;

	set<int>::iterator it1 = setint.lower_bound(5);//返回第一个>=具体某一元素的迭代器 5
	set<int>::iterator it2 = setint.upper_bound(5);//返回第一个>具体某一元素的迭代器  6
	int e1 = *it1;		int e2 = *it2;
	cout << "e1=" << e1 << "\te2=" << e2 << endl;

	pair<set<int>::iterator,set<int>::iterator> ii=setint.equal_range(10);//返回上下限的两个迭代器,如:等于5(5)  不等于5(6) ,被封装在pair中
	if (ii.second != setint.end()) {
		//ii.first找到10停住了        //后面是.end()迭代器,ii.second还往下找了,所以!=end()
		cout << *ii.first << endl;    cout << *ii.second << endl;
	}
	else {
		cout << "不存在\n";
	}
}