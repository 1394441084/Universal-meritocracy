#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

class EET {
public:
	EET() { printf("���캯��!\n"); ID = 0; }
	EET(const EET& e) { ID++; printf("�������캯��!\n"); }
	~EET(){ printf("~��������!ID=%d\n",ID); }

	int ID=0;
};

//ʵ���ļ��Ķ����ƿ���
int copyfile2(const char* dest,const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;//�ļ�

	//rb ֻ����ʽ��һ���������ļ���ֻ�����ȡ����
	fopen_s(&fp1, src, "rb");
	//errno_t fopen_s(FILE * *pFile, const char* filename, const char* mode);
	//FILE* fopen(const char* filename, const char* mode)

	if (fp1 == NULL) {
		//throw new string("�ļ�������");
		//throw EET();//�׳���(��������)//ʹ������Ч�ʸ���
		//EET eeE;//�ֲ�����,�쳣û����ǰ��������
		//throw eeE;//������ʱ�������������ֲ��������׳�
		throw new EET();//�׳�ָ��
	}

	//wb ��ֻд�ķ�ʽ�򿪻��½�һ���������ļ���ֻ����д���ݡ�
	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//����������ݣ������0
	while ((readlen = fread(buffer, 1, BUFSIZE, fp1)) > 0) {
		writelen = fwrite(buffer, 1, readlen, fp2);
		if (readlen != writelen) {
			throw - 3;
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

//throw(string,int,float)//�����쳣����,�ñ�ĳ���Ա����Ҫ��׽�����쳣����
int copyfile1(const char* dest,const char* src)throw() {//�����׳��쳣,�����ǿ����׳�


	copyfile2(dest, src);


	//�����׳��쳣���Ͳ���
	/*
	try {
		copyfile2(dest, src);
	}
	catch (...) {//�쳣������,ִ��printf("����copyfile1()��...\n");
		printf("copyfile1-catch...\n");
		//throw EET();//�׳���//����׳��Ĳ��������б��е�����.�ᾯ��,��������������[throw(int)],Ҳ������ֹ����
		//throw ;//�׳��쳣,��ֹ����
		//��ʾ�������˵��쳣�����ǿ�����catch�����һ����֧��ʹ��throw�﷨�������������throw��
	}*/

	return 0;
}

int main() {
	int ret = 0;
	
	try {//������
		printf("����copyfile1()��...\n");
		ret = copyfile1("c:/test/dest.txt", "c:/test/src.txt");//���쳣,ֱ��תcatch
		printf("����copyfile1()��...\n");//���쳣,����ִ��
	}
	catch (int error) {//�쳣����//�쳣��
		printf("�����쳣����%d\n", error);
	}
	catch (string * error) {
		printf("��׽���ַ����쳣��%s\n", error->c_str());
		delete error;
	}
	catch (EET e) {//�������������,�������׳����Ķ���(��������)
		e.ID = 2;//ʹ�����ý�,Ч������ߵ�,�޷��Ӷ�̬�ڴ�(ָ��)
		printf("��׽��EET�쳣,id=%d\n",e.ID);
	}
	catch (EET *e) {
		printf("��׽��EET *e�쳣,id=%d\n", e->ID);
		delete e;
	}
	catch (...) {//ͨ��
		//������ⶼ������,�ͻ���ֹ���򲢷���
		printf("catch(...)\n");
	}

	system("pause");
	return 0;
}
/*
r	��һ�����е��ı��ļ��������ȡ�ļ���
w	��һ���ı��ļ�������д���ļ�������ļ������ڣ���ᴴ��һ�����ļ���
	��������ĳ������ļ��Ŀ�ͷд�����ݡ�����ļ����ڣ���ûᱻ�ض�Ϊ�㳤�ȣ�����д�롣
a	��һ���ı��ļ�����׷��ģʽд���ļ�������ļ������ڣ���ᴴ��һ�����ļ�����������ĳ���������е��ļ�������׷�����ݡ�
r+	��һ���ı��ļ��������д�ļ���
w+	��һ���ı��ļ��������д�ļ�������ļ��Ѵ��ڣ����ļ��ᱻ�ض�Ϊ�㳤�ȣ�����ļ������ڣ���ᴴ��һ�����ļ���
a+	��һ���ı��ļ��������д�ļ�������ļ������ڣ���ᴴ��һ�����ļ�����ȡ����ļ��Ŀ�ͷ��ʼ��д����ֻ����׷��ģʽ��
���������Ƕ������ļ�������ʹ������ķ���ģʽ��ȡ������ķ���ģʽ��

"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
*/