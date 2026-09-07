#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

/*
问题：
类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：
解决方式1：直接包含.cpp源文件
解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
一般都用第二种方式


*/


//第一种方式，直接包含源文件
//#include "person.h"因为这样编译器看不到函数的具体实现
//#include "person.cpp"//把这里包含头文件.h改成.cpp

//第二种方式，将.h和.cpp中的内容写到一起，将后缀名改成.hpp文件
#include "person.hpp"


/*
问题：
* 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到


解决：
* 解决方式1：直接包含.cpp源文件
* 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制


*/

//template <class T1, class T2>
//class person
//{
//public:
//	person(T1 name, T2 age);
//
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//template <class T1, class T2>
//person<T1, T2>::person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template <class T1, class T2>
//void person<T1, T2>::showPerson()
//{
//	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
//}
//
//void test01()
//{
//	person<string, int>p("tom", 12);
//	p.showPerson();
//}


void test01()
{
	person<string, int>p("tom", 12);
	p.showPerson();
}


int main() {

	test01();

	system("pause");

	return 0;
}