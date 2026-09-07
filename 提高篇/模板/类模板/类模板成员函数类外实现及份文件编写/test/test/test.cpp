#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

//类模板成员函数类外实现
template <class T1,class T2>
class person
{
public:
	person(T1 name, T2 age);//类内声明，类外实现
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}

	void showPerson();
	//{
	//	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	//}

	T1 m_Name;
	T2 m_Age;
};

//构造函数的类外实现
template <class T1, class T2>
person<T1,T2>::person(T1 name, T2 age)//必须要写模板的参数列表
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数的类外实现
template <class T1, class T2>
void person<T1, T2>::showPerson()
{
	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
}

void test01()
{
	person<string, int>p("Mike", 18);
	p.showPerson();
}

int main() {

	test01();

	system("pause");

	return 0;
}