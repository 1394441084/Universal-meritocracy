#include <deque> //deque����ͷ�ļ�(˫������)
#include <iostream>
#include <sstream>
/*
deque��vector���ⲻͬ:deque���ö�����˫������,vector���õ����鵥������
�����������޶������
*/
using namespace std;
class Student {
public:
	Student(const char* name = "δ����", const int age = 0) {
		cout << "���ù��캯��\n";
		if (name == " " || name == "\0" || name == "\t") { name = "�ո�"; }
		this->name = new char[sizeof(name) + 1]; strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}
	Student(const Student& other) {
		cout << "���ÿ������캯��\n";
		if (name != name)delete[] name;
		if (other.name == NULL) { name = NULL; age = other.age; return; }
		name = new char[sizeof(other.name) + 1];
		strcpy_s(name, sizeof(other.name) + 1, other.name);
		age = other.age;
	}
	~Student() {
		cout << "������������\n";
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
void ��ӡ(const char *name,const deque<T> &v1) {
	stringstream str;
	str << name << "��Ԫ�ظ���:" << v1.size() << endl;
	//str << name << "������С:" << v1.capacity() << endl;//dequeû�˺���
	for (int i = 0; i < v1.size(); i++) {
		//ʹ��������ʷ���ע��Խ��
		//str << name << "[" << i << "]:" << v1[i] << "  ";
		str << name << "[" << i << "]:" << v1.at(i) << "  ";
	}
	str << endl;
	cout<< str.str();
}

void deque������() {
	while (1) {
		deque<int> d1;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);

		//��ͨ������
		for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
			(*it)++;//*it++;//ָ��++    (*it)++;//Ԫ��++
			cout << *it << " ";
		}
		cout << endl;
		//����������
		for (deque<int>::const_iterator cit = d1.cbegin(); cit != d1.cend(); cit++) {
			//(*it)++;
			cout << *cit << " ";
		}
		cout << endl;
		//��ת������
		for (deque<int>::reverse_iterator rit = d1.rbegin(); rit != d1.rend(); rit++) {
			(*rit)++;
			cout << *rit << " ";
		}

		break;
	}
}

void deque��ֵ�ʹ�С() {
	while (0) {//��ֵ
		deque<int> d1, d2, d3, d4;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);

		d2.assign(d1.begin(), d1.end());//123456
		//d2.assign(d1.begin()+1, d1.end());//23456
		��ӡ("d2", d2);
		d3.assign(4, 888);//888 888 888 888
		��ӡ("d3", d3);
		d4 = d1;
		��ӡ("d4", d4);
		d3.swap(d4);//�໥����
		cout << "������:" << endl;
		��ӡ("d3", d3);
		��ӡ("d4", d4);
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

		int size = d1.size();//��С
		d1.resize(7);//1 2 3 4 5 6 0

		//d1.resize(3);//1 2 3

		d1.resize(9,1);//1 2 3 4 5 6 0 1 1
		��ӡ("d1", d1);

		break;
	}

}

void deque�����ɾ��() {
	//deque����
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
		//��ӡ("d1", d1);
		//d1.insert(d1.begin(), d2.begin(), d2.end());//15 16 17 18 0 888 888 1 2 3 4
		d1.insert(d1.begin(), d2.rbegin(), d2.rend());//18 17 16 15 0 888 888 1 2 3 4
		��ӡ("d1", d1);

		break; }

	//dequeɾ��
	while (1) { 
		deque<int> d1;
		d1.push_back(1);
		d1.push_back(2);
		d1.push_back(3);
		d1.push_back(4);
		d1.push_back(5);
		d1.push_back(6);
		
		/*
		d1.erase(d1.begin() + 1);//�ɵ�����Ԫ��
		��ӡ("d1", d1);//13456
		d1.erase(d1.begin() + 1, d1.end()-1);//�ɵ�����Ԫ��,������ʼ,��������β
		��ӡ("d1", d1);//1,6
		d1.clear();//�ɵ�����Ԫ��
		��ӡ("d1", d1);*/

		//ʹ�õ���������ɾ��
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
void deque����() {
	while (0) { 
	/*
deque��vector���ⲻͬ:deque���ö�����˫������,vector���õ����鵥������
�����������޶������
*/
	deque<int> d1;//���int��deque����
	//d1.push_back(12);
	deque<float> f1;
	f1.push_back(0.1);
	//deque ��ģ��Ĭ�Ϲ���
	deque<Student> s1;
	s1.push_back(Student("zhou", 18));//Student("zhou", 18)��ʱ����

	//deque ���εĹ���
	deque<int> d2(d1.begin(), d1.end());//��������,begin-end�е�Ԫ��
	deque<int> d3(10, 0);//ָ��n��Ԫ��,��ֵ
	deque<int> d4(d3);//��������
	��ӡ("d4", d4);

	//deque ͷ����β�� ���-ɾ�� :
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);//β����ӵ���Ԫ��
	d1.push_back(5);
	d1.push_back(6);//1 2 3 4 5 6
	��ӡ("d1", d1);

	d1.pop_front();//ͷ��ɾ��Ԫ��
	d1.pop_front();//3 4 5 6
	��ӡ("d1", d1);

	d1.push_front(7);//ͷ����ӵ���Ԫ��
	 ��ӡ("d1", d1);//7 3 4 5 6

	d1.push_front(8);//8 7 3 4 5 6 
	 ��ӡ("d1", d1);

	d1.pop_back();//β��ɾ��Ԫ��
	��ӡ("d1", d1);//8 7 3 4 5

	d1.pop_back();//8 7 3 4 
	��ӡ("d1", d1);
	break;
	}
	//deque������();
	//deque��ֵ�ʹ�С();
	deque�����ɾ��();
}

