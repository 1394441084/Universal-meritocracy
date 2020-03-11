#include <queue>
//队列,先进先出容器,默认情况是使用deque容器实现的一种容器,当然自己能指定使用哪种容器来实现
//它只允许在队列的前端（front）进行删除操作，而在队列的后端（back）进行插入操作
#include <iostream>
#include <Windows.h>
#include <vector>
#include <list> 
#include <stack> //堆栈容器,先进后出队列,默认情况下是内置deque容器实现
#include <set>  
#include <map>
#include <string>
//使用队列,默认deque效率最高
using namespace std;

void queue构造();
void Priority_queue优先级队列();
void stack详情();

int main(void) {
	//queue构造();
	//Priority_queue优先级队列();
	stack详情();


	system("pause");
	return 0;
}

void queue构造() {
	//构造与赋值 : a(b) ; b=c ;
	queue<int> q;//因为默认是deque容器构造,所以底层并无自动排序
	queue<int, list<int>> q1;//指定使用list构造
	//queue<int, vector<int>> q2; //不能做为queue内置容器,因为vector没有.pop()函数,不兼容
	queue<int, set<int>> q3;
	//queue<int, map<int,string>> q4;//不能做为queue内置容器,也是因为map没有.pop()函数,不兼容

	q.push(1);
	q.push(3);
	q.push(2);
	q.push(9);
	q.push(5);

	q.pop();//删除首元素,调用一次删除一个

	q.front() = 56;//返回的是引用,所以可以修改
	q.back() = 88;

	cout <<"首元素是:"<< q.front() << endl;
	cout<< "尾元素是:" << q.back() << endl;

	//获取大小
	if (!q.empty()) {//判断队列是否为空
		int qsize = q.size();
		cout << "queue q 的元素个数为:" << qsize << endl;
	}

	//q.emplace();//完美转发,变参模板
}

void Priority_queue优先级队列() {//没有迭代器
	//priority_queue<int> pq;//默认内置容器vector,默认仿函数less;//排序:默认值越大,优先级越高
	priority_queue<int,vector<int>,greater<int>> pq;
	//priority_queue<int, deque<int>, greater<int>> pq;
	//priority_queue<int,list<int>,greater<int>> pq;//list不能使用
	//priority_queue<int,set<int>,greater<int>> pq;//set不能使用
	
	pq.push(2);
	pq.push(1);
	pq.push(6);
	pq.push(6);
	pq.push(8);
	pq.push(3);
	pq.push(6);

	//pq.swap();//交换
	//pq.emplace();//完美转发,变参模板

	while (!pq.empty()) {
		cout << pq.top() <<" ";//返回的是const引用,读取对首的元素
		pq.pop();//出队列
	}
	cout << endl;

}

void stack详情(){//没有迭代器
	//构造与赋值 : stack<int> a(b); stack<int> b=c ;
	stack<int> s;
	//stack<int, vector<int>> s;
	//stack<int, list<int>> s;
	//stack<int, set<int>> s;//不能使用
	//stack<int,map<int,string>> s;//不能使用
	//stack<int, queue<int>> s;//不能使用

	s.push(2);//进栈
	s.push(9);
	s.push(25);
	s.push(97);
	//s.pop();//97出栈
	s.push(1);
	s.top() = 456;
	//cout << s.size() << endl;//大小
	while (!s.empty()) {
		cout << "最后进栈的元素:" << s.top() << " ";//返回的是引用,所以可以修改
		s.pop();//删除最后进栈的元素
	}
	cout << endl;
	
}
