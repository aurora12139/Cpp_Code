#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/*
### 二进制文件
以二进制的方式对文件进行读写操作
打开方式要指定为 ==ios::binary==


#### 5.2.1 写文件
二进制方式写文件主要利用流对象调用成员函数write
函数原型 ：`ostream& write(const char * buffer,int len);`
参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

#### 5.2.2 读文件
二进制方式读文件主要利用流对象调用成员函数read
函数原型：`istream& read(char *buffer,int len);`
参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
*/


/*
//二进制文件  写文件
class person
{
public:


	char m_Name[64];  //姓名
	int m_Age;   //年龄
};

void test01()
{
	//1、包含头文件

	//2、创建输出流对象
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out | ios::binary)；
	
	//3、打开文件
	ofs.open("person.txt", ios::out | ios::binary);//以二进制方式写

	//4、写文件
	person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(person));

	//5、关闭文件
	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结：
//* 文件输出流对象 可以通过write函数，以二进制方式写数据,要强制转换成const char *接地址
*/



//二进制文件，读文件
class person
{
public:
	char m_Name[64];
	int m_Age;
};


void test01()
{
//1、包含头文件

//2、创建输出流对象
	ifstream ifs;


//3、打开文件
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

//4、读文件
	person p;

	ifs.read((char*)&p, sizeof(person));

	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;

//5、关闭文件
	ifs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}
