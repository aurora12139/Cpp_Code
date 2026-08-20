#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>


/*
当其他类对象作为本类成员，构造的时候先构造类对象（小的类），再构造自身，析构的顺序与构造相反。

*/

class phone
{
public:
	phone(string pname)
	{
		m_pname = pname;
		cout << "phone的构造函数" << endl;
	}
	~phone()
	{
		cout << "phone的析构函数" << endl;
	}
	//手机品牌名称
	string m_pname;
};

class person
{
public:
	person(string name, string pname) :m_name(name), m_phone(pname)
	{
		cout << "person的构造函数" << endl;
	}
	~person()
	{
		cout << "person的析构函数" << endl;
	}
	//姓名
	string m_name;

	//手机
	phone m_phone;
};

void test01()
{
	person p("张三", "华为");
	cout << p.m_name << " 拿着 " << p.m_phone.m_pname << endl;
}

int main()
{
	test01();
	return 0;
}