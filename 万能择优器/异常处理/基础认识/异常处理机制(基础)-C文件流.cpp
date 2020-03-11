#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUFSIZE 1024

class EET {
public:
	EET() { printf("构造函数!\n"); ID = 0; }
	EET(const EET& e) { ID++; printf("拷贝构造函数!\n"); }
	~EET(){ printf("~析构函数!ID=%d\n",ID); }

	int ID=0;
};

//实现文件的二进制拷贝
int copyfile2(const char* dest,const char* src) {
	FILE* fp1 = NULL, * fp2 = NULL;//文件

	//rb 只读方式打开一个二进制文件，只允许读取数据
	fopen_s(&fp1, src, "rb");
	//errno_t fopen_s(FILE * *pFile, const char* filename, const char* mode);
	//FILE* fopen(const char* filename, const char* mode)

	if (fp1 == NULL) {
		//throw new string("文件不存在");
		//throw EET();//抛出类(匿名对象)//使用这种效率更快
		//EET eeE;//局部变量,异常没处理前就析构了
		//throw eeE;//生成临时匿名变量拷贝局部变量并抛出
		throw new EET();//抛出指针
	}

	//wb 以只写的方式打开或新建一个二进制文件，只允许写数据。
	fopen_s(&fp2, dest, "wb");
	if (fp2 == NULL) {
		throw - 2;
	}

	char buffer[BUFSIZE];
	int readlen, writelen;

	//如果读到数据，则大于0
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

//throw(string,int,float)//声明异常类型,让别的程序员明白要捕捉哪种异常类型
int copyfile1(const char* dest,const char* src)throw() {//不想抛出异常,但还是可以抛出


	copyfile2(dest, src);


	//继续抛出异常类型测试
	/*
	try {
		copyfile2(dest, src);
	}
	catch (...) {//异常被处理,执行printf("运行copyfile1()完...\n");
		printf("copyfile1-catch...\n");
		//throw EET();//抛出类//如果抛出的不是声明列表中的类型.会警告,但程序依旧运行[throw(int)],也可能终止程序
		//throw ;//抛出异常,终止程序
		//提示：处理不了的异常，我们可以在catch的最后一个分支，使用throw语法，继续向调用者throw。
	}*/

	return 0;
}

int main() {
	int ret = 0;
	
	try {//保护段
		printf("运行copyfile1()中...\n");
		ret = copyfile1("c:/test/dest.txt", "c:/test/src.txt");//有异常,直接转catch
		printf("运行copyfile1()完...\n");//有异常,不会执行
	}
	catch (int error) {//异常类型//异常段
		printf("出现异常啦！%d\n", error);
	}
	catch (string * error) {
		printf("捕捉到字符串异常：%s\n", error->c_str());
		delete error;
	}
	catch (EET e) {//先析构这个对象,再析构抛出来的对象(匿名对象)
		e.ID = 2;//使用引用接,效率是最高的,无法接动态内存(指针)
		printf("捕捉到EET异常,id=%d\n",e.ID);
	}
	catch (EET *e) {
		printf("捕捉到EET *e异常,id=%d\n", e->ID);
		delete e;
	}
	catch (...) {//通配
		//如果连这都进不来,就会终止程序并反馈
		printf("catch(...)\n");
	}

	system("pause");
	return 0;
}
/*
r	打开一个已有的文本文件，允许读取文件。
w	打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。
	在这里，您的程序会从文件的开头写入内容。如果文件存在，则该会被截断为零长度，重新写入。
a	打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。
r+	打开一个文本文件，允许读写文件。
w+	打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
a+	打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。
如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：

"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
*/