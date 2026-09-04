#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



/*
类模板
1.3.1 类模板语法
类模板作用：
建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。

语法：
template<typename T>
类


解释：
template  -- - 声明创建模板
typename  -- - 表面其后面的符号是一种数据类型，可以用class代替
T-- - 通用的数据类型，名称可以替换，通常为大写字母

*/


//类模板

template <class NameType, class AgeType>
class person
{
public:
	person(NameType name, AgeType age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	void showPerson()
	{
		cout << " name: " << this->m_name << " age: " << this->m_age << endl;
	}
public:
	NameType m_name;
	AgeType m_age;
};

void test01()
{
	person<string, int> p1("mike", 18);
	p1.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板