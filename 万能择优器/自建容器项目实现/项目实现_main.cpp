/*
����ԱJack ���Ŷ��½�����һ���ײ����Ŀ����Ŀ����Ҫ��Jack ʵ��һ��ͨ�õ�������
�ܹ�֧�ֲ�����ֲ�ͬ����ͨ���ͣ����� int char float double ��)���Զ���ṹ����Զ�����Ķ���
���ܸ���ÿ�ֲ�ͬ���͵ıȽϹ����������ȡ��������С���Ǹ�ֵ�����
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
	//m.insert(//û��pair

	//int1.erase(0);
	//int1.erase(45);

	string s(100,'-');
	cout << "��ȡ���:\n";
	
	pair<int,bool> pi = int1.getbig();
	pi.second ? cout << "���ֵΪ:" << pi.first << endl :
		cout << "����Ϊ��,���ֵû��!"<< endl;

	cout << s << endl;

	pi = int1.getMin();
	pi.second ? cout << "��СֵΪ:" << pi.first << endl :
		cout << "����Ϊ��,��Сֵû��!" << endl;

	system("pause");
	return 0;
}