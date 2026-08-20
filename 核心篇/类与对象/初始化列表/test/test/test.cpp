#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
** 作用：**

C++提供了初始化列表语法，用来初始化属性

语法：** `构造函数()：属性1(值1), 属性2（值2）... {}`





*/


//class person
//{
//public:
//	//传统方式初值化
//	person(int a, int b, int c)
//	{
//		A = a;
//		B = b;
//		C = c;
//	}
//	int A;
//	int B;
//	int C;
//};
//
//void test01()
//{
//	person p(10, 20, 30);
//	cout << "A= " << p.A << " B= " << p.B << " C= " << p.C << endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}


//初始化列表实现
class person
{
public:
	//person() :A(10), B(20), C(30)
	//{
	//	
	//}

	person(int a, int b, int c) :A(a), B(b), C(c)
	{

	}

	int A;
	int B;
	int C;

};
void test01()
{
	//person p(10, 20, 30);
	//person p;
	person p(30, 20, 10);
	cout << "A= " << p.A << " B= " << p.B << " C= " << p.C << endl;
}

int main()
{
	test01();
	return 0;
}