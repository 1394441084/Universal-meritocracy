/*
程序员Jack 的团队新接手了一个底层的项目，项目经理要求Jack 实现一个通用的容器，
能够支持插入多种不同的普通类型（包含 int char float double 等)和自定义结构体和自定义类的对象，
并能根据每种不同类型的比较规则从容器中取得最大或最小的那个值或对象。
*/
#include "sizeFilter.h"

int main(void) {
	//sizeFilter<int, multiset<int>> int1;
	sizeFilter<int> int1;
	for (int i = 0; i < 10; i++) {
		int1.insert(i * 5);
	}
	int1.insert(15);
	int1.insert(26);

	set<int> m;
	//m.count()
	//m.insert(//没有pair

	//int1.erase(0);
	//int1.erase(45);

	string s(100,'-');
	cout << "获取结果:\n";
	
	pair<int,bool> pi = int1.getbig();
	pi.second ? cout << "最大值为:" << pi.first << endl :
		cout << "容器为空,最大值没得!"<< endl;

	cout << s << endl;

	pi = int1.getMin();
	pi.second ? cout << "最小值为:" << pi.first << endl :
		cout << "容器为空,最小值没得!" << endl;

	system("pause");
	return 0;
}