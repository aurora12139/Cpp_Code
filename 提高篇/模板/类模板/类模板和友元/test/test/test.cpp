#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

/*
类模板与友元
学习目标：
掌握类模板配合友元函数的类内和类外实现


全局函数类内实现 - 直接在类内声明友元即可
全局函数类外实现 - 需要提前让编译器知道全局函数的存在

*/
template<class T1,class T2>
class person;

//全局函数    类外实现,   必须先让编译器先看到有这个全局函数以及类
template <class T1, class T2>
void printPerson2(person<T1, T2> p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}


template <class T1,class T2>
class person
{
	//全局函数  类内实现
	//friend void printPerson(person<T1,T2> p)
	//{
	//	cout << "类内实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	//}

	//全局函数 类外实现
	//需要加空模板的参数列表<>
	//如果全局函数是类外实现的话，需要让编译器提前知道这个函数的存在，放在整个程序最前面
	friend void printPerson2<>(person<T1, T2> p);


public:
	person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};




//1.全局函数在类内实现
void test01()
{
	person<string, int>p("Mike", 18);
	printPerson2(p);
}

//2.全局函数在类外实现测试
void test02()
{
	person<string, int>p("tom", 18);
	printPerson2(p);
}



int main() {

	test01();

	//test02();

	system("pause");

	return 0;
}