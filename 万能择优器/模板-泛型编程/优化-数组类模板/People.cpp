#include "People.h"

template <typename P>
ostream& operator<<(ostream& os, const People<P>& other)
{
	if (other.p_a_len == NULL) {
		os << "��Աδ����,�붨������ٲ���.";
		return os;
	}

	for (int i = 0; i < other.a_len; i++) {
		os << other.p_a_len[i] << " ";
	}
	return os;
}

int main(void) {
	int i = 2;
	People<man*> p1(2);
	man man1("����", 21);
	man man2("ţ��ϲ", 26);

	p1[0] = &man1;
	p1[1] = &man2;

	cout << p1<< endl;


	system("pause");
	return 0;
}


