#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
初始化列表
作用：C++提供了初始化列表语法，用来初始化属性

语法：构造函数()：属性（值1），属性（值2）...{}


 类对象作为类成员
 C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
 例如：
class A {}
class B
{
	A a；
}
B类中有对象A作为成员，A为对象成员


*/



//class person
//{
//public:
//	//person() :a(10), b(20), c(30)
//	//{
//
//	//}
//	//也可以
//	person(int a,int b, int c) :a(a), b(b), c(c)
//	{
//
//	}
//
//	int a;
//	int b;
//	int c;
//};
//
//int main()
//{
//	//person p;
//	person p(20, 30, 10);
//	cout << "a= " << p.a << endl;
//	cout << "b= " << p.b << endl;
//	cout << "c= " << p.c << endl;
//
//	system("pause");
//	return 0;
//}



#include<string>
//手机类
class phone
{
public:
	phone(string P)//构造函数
	{
		Pname = P;
		cout << "phone的构造函数的调用" << endl;
	}
	~phone()
	{
		cout << "phone的析构函数的调用" << endl;

	}
	//品牌名称
	string Pname;

};

//人类
class person
{
public:
	person(string n, string t) :name(n), tele(t)
	{
		cout << "person的构造函数的调用" << endl;
	}

	~person()
	{
		cout << "person的析构函数的调用" << endl;

	}

	//姓名 
	string name;
	//手机
	phone tele;
	//当其他类对象作为本类成员，构造时先构造类对象，再构造自身，先构造小类后构造大类
	//析构的顺序与构造相反，先析构大类再析构小类
};

void test01()
{
	person p("张三", "apple");

	cout << p.name << " have " << p.tele.Pname << endl;
}

int main()
{
	test01();
	return 0;
}