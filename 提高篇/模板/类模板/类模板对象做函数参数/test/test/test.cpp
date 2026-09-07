#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<string>
/*
#### 类模板对象做函数参数

学习目标：

* 类模板实例化出的对象，向函数传参的方式



一共有三种传入方式：

1. 指定传入的类型   --- 直接显示对象的数据类型
2. 参数模板化           --- 将对象中的参数变为模板进行传递
3. 整个类模板化       --- 将这个对象类型 模板化进行传递

*/


//类模板
template <class T1, class T2>
class person
{
public:
	person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};


//1.指定传入的类型
void printPerson1(person<string, int>& p)//直接把整个类名称作为参数传入函数
{
	p.showPerson();
}

void test01()
{
	person<string, int>p("Mike", 18);
	printPerson1(p);
}


//2. 参数模板化
template<class T1,class T2>
void printPerson2(person<T1, T2>& p)
{
	p.showPerson();
	//cout << "T1 的类型为： " << typeid(T1).name() << endl;
	//cout << "T2 的类型为： " << typeid(T2).name() << endl;

}

void test02()
{
	person<string, int>p("Tom", 12);
	printPerson2(p);
}


//3. 整个类模板化 
template<class T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << "T的数据类型为：" << typeid(T).name() << endl;
}


void test03()
{
	person<string, int>p("John", 10);
	printPerson3(p);
}



int main() {

	test01();
	test02();
	test03();

	system("pause");

	return 0;
}