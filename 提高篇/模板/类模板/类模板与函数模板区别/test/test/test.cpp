#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
类模板与函数模板区别主要有两点：
1. 类模板没有自动类型推导的使用方式
2. 类模板在模板参数列表中可以有默认参数


类模板中成员函数创建时机
类模板中成员函数和普通类中成员函数创建时机是有区别的：
1.普通类中的成员函数一开始就可以创建
2.类模板中的成员函数在调用时才创建

*/


/*
template<class NameType = string , class AgeType = int>//类模板中的模板参数列表可以指定默认参数
class person
{
public:
	person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}

public:
	NameType mName;
	AgeType mAge;
};


//1、类模板没有自动类型推导的使用方式
void test01()
{
	//person p("mike", 12);	// 错误 类模板使用时候，不可以用自动类型推导
	person<string, int>p("mike", 12);
	p.showPerson();

}



//2、类模板在模板参数列表中可以有默认参数
void test02()
{
	person<>p("tom", 13);//没传类别就用默认的
	p.showPerson();

}



int main() {

	test01();

	test02();

	system("pause");

	return 0;
}
//总结： 类模板使用只能用显示指定类型方式
//		类模板中的模板参数列表可以有默认参数
*/



class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template <class T>
class Myclass
{
public:
	T obj;

	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	Myclass<Person1>m;
	m.func1();
	//m.func2();//编译会出错，说明函数调用才会去创建成员函数，没被调用的话func2没被创建

}

int main() {

	test01();

	system("pause");

	return 0;
}
//总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建