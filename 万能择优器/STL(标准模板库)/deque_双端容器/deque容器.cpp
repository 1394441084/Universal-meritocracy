#include <deque> //deque容器头文件(双向容器)
#include <iostream>
#include <sstream>
/*
deque和vector特殊不同:deque采用多数组双端容器,vector采用单数组单端容器
其它操作并无多大区别
*/
using namespace std;
class Student {
public:
	Student(const char* name = "未命名", const int age = 0) {
		cout << "调用构造函数\n";
		if (name == " " || name == "\0" || name == "\t") { name = "空格"; }
		this->name = new char[sizeof(name) + 1]; strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Student(const Student& other) {
		cout << "调用拷贝构造函数\n";
		if (name != name)delete[] name;
		if (other.name == NULL) { name = NULL; age = other.age; return; }
		name = new char[sizeof(other.name) + 1];
		strcpy_s(name, sizeof(other.name) + 1, other.name);
		age = other.age;
	}
	~Student() {
		cout << "调用析构函数\n";
		if (name != NULL) {
			delete[] name;
			name = NULL;
		}
	}
	friend ostream& operator<<(ostream& os, const Student& other) {
		other.name == NULL ? os << "name==NULL" : os << "name=" << other.name << "\tage=" << other.age;
		return os;
	}
private:
	int age = 0;
	char* name = NULL;
};

template<typename T>
void 打印(const char *name,const deque<T> &v1) {
	stringstream str;
	str << name << "的元素个数:" << v1.size() << endl;
	//str << name << "容器大小:" << v1.capacity() << endl;//deque没此函数
	for (int i = 0; i < v1.size(); i++) {
		//使用数组访问法请注意越界
		//str << name << "[" << i << "]:" << v1[i] << "  ";
		str << name << "[" << i << "]:" << v1.at(i) << "  ";
	}
	str << endl;
	cout<< str.str();
}

void deque迭代器() {
	while (1) {
		deque<int> d1;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);

		//普通迭代器
		for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
			(*it)++;//*it++;//指针++    (*it)++;//元素++
			cout << *it << " ";
		}
		cout << endl;
		//常量迭代器
		for (deque<int>::const_iterator cit = d1.cbegin(); cit != d1.cend(); cit++) {
			//(*it)++;
			cout << *cit << " ";
		}
		cout << endl;
		//逆转迭代器
		for (deque<int>::reverse_iterator rit = d1.rbegin(); rit != d1.rend(); rit++) {
			(*rit)++;
			cout << *rit << " ";
		}

		break;
	}
}

void deque赋值和大小() {
	while (0) {//赋值
		deque<int> d1, d2, d3, d4;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);

		d2.assign(d1.begin(), d1.end());//123456
		//d2.assign(d1.begin()+1, d1.end());//23456
		打印("d2", d2);
		d3.assign(4, 888);//888 888 888 888
		打印("d3", d3);
		d4 = d1;
		打印("d4", d4);
		d3.swap(d4);//相互交换
		cout << "交换后:" << endl;
		打印("d3", d3);
		打印("d4", d4);
		break;
	}
	while (1) {
		deque<int> d1;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);

		int size = d1.size();//大小
		d1.resize(7);//1 2 3 4 5 6 0

		//d1.resize(3);//1 2 3

		d1.resize(9,1);//1 2 3 4 5 6 0 1 1
		打印("d1", d1);

		break;
	}

}

void deque插入和删除() {
	//deque插入
	while (0) { 
		deque<int> d1, d2;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		 
		d2.push_back(15);
		d2.push_back(16);
		d2.push_back(17);
		d2.push_back(18);
		
		d1.insert(d1.begin(), 0);//0 1 2 3 4
		d1.insert(d1.begin()+1,2,888);//0 888 888 1 2 3 4
		//打印("d1", d1);
		//d1.insert(d1.begin(), d2.begin(), d2.end());//15 16 17 18 0 888 888 1 2 3 4
		d1.insert(d1.begin(), d2.rbegin(), d2.rend());//18 17 16 15 0 888 888 1 2 3 4
		打印("d1", d1);

		break; }

	//deque删除
	while (1) { 
		deque<int> d1;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);
		
		/*
		d1.erase(d1.begin() + 1);//干掉单个元素
		打印("d1", d1);//13456
		d1.erase(d1.begin() + 1, d1.end()-1);//干掉区间元素,包含开始,不包含结尾
		打印("d1", d1);//1,6
		d1.clear();//干掉所有元素
		打印("d1", d1);*/

		//使用迭代器遍历删除
		for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
			if ((*it) == 4) {
				it=d1.erase(it);
				//continue;
			}
			cout << *it;
			cout << " ";
		}




		break; }
}
void deque构造() {
	while (0) { 
	/*
deque和vector特殊不同:deque采用多数组双端容器,vector采用单数组单端容器
其它操作并无多大区别
*/
	deque<int> d1;//存放int的deque容器
	//d1.push_back(12);
	deque<float> f1;
	f1.push_back(0.1);
	//deque 类模板默认构造
	deque<Student> s1;
	s1.push_back(Student("zhou", 18));//Student("zhou", 18)临时对象

	//deque 带参的构造
	deque<int> d2(d1.begin(), d1.end());//给定区间,begin-end中的元素
	deque<int> d3(10, 0);//指定n个元素,赋值
	deque<int> d4(d3);//拷贝构造
	打印("d4", d4);

	//deque 头部和尾部 添加-删除 :
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);//尾部添加单个元素
	d1.push_back(5);
	d1.push_back(6);//1 2 3 4 5 6
	打印("d1", d1);

	d1.pop_front();//头部删除元素
	d1.pop_front();//3 4 5 6
	打印("d1", d1);

	d1.push_front(7);//头部添加单个元素
	 打印("d1", d1);//7 3 4 5 6

	d1.push_front(8);//8 7 3 4 5 6 
	 打印("d1", d1);

	d1.pop_back();//尾部删除元素
	打印("d1", d1);//8 7 3 4 5

	d1.pop_back();//8 7 3 4 
	打印("d1", d1);
	break;
	}
	//deque迭代器();
	//deque赋值和大小();
	deque插入和删除();
}

