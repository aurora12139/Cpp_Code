#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
拷贝构造函数调用时机
C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象



构造函数调用规则
默认情况下，c++编译器至少给一个类添加3个函数：
1．默认构造函数(无参，函数体为空)
2．默认析构函数(无参，函数体为空)
3．默认拷贝构造函数，对属性进行值拷贝


构造函数调用规则如下：
* 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
* 如果用户定义拷贝构造函数，c++不会再提供其他构造函数




*/


/*
class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}
	person(int a)
	{
		age = a;;
		cout << "person的有参构造函数调用" << endl;
	}
	person(const person& p)
	{
		cout << "person的拷贝构造函数调用" << endl;
		age= p.age;
	}
	~person()
	{
		cout << "person的析构函数调用" << endl;
	}

	int age;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	person p1(20);
	person p2(p1);
	cout << "p2的年龄为：" <<p2.age<< endl;
}

//2.值传递的方式给函数参数传值
void dowork(person p)
{

}

void test02()
{
	person p;
	dowork(p);
}


//以值方式返回局部对象
person dowork2()
{
	person p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test03()
{
	person p = dowork2();
	cout << (int*)&p << endl;//这两个地址不一样，下面的p是上面函数拷贝的一份新的p的地址
}


int main()
{
	test01();
	test02();
	test03();
	return 0;
}
*/


class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}
	person(int a)
	{
		cout << "person的有参构造函数调用" << endl;
		age = a;
	}
	person(const person& p) 
	{
		age = p.age;
		cout << "person的拷贝构造函数调用" << endl;
	}
	~person()
	{
		cout << "person的析构函数调用" << endl;
	}
	int age;
};

void test01()
{
	person p;
	p.age = 18;
	person p2(p);
	cout << "p2的年龄为：" << p2.age << endl;
}

int main()
{
	test01();
	system ("pause");
	return 0;
}
