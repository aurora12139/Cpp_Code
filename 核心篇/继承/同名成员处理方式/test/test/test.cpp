#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
#### 继承同名成员处理方式
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

* 访问子类同名成员   直接访问即可
* 访问父类同名成员   需要加作用域


#### 继承同名静态成员处理方式
问题：继承中同名的静态成员在子类对象上如何进行访问？
静态成员和非静态成员出现同名，处理方式一致

- 访问子类同名成员   直接访问即可
- 访问父类同名成员   需要加作用域

*/


/*
class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func()调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}

	int m_A;
};


class son :public Base
{
public:
	son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "son - func()调用" << endl;
	}

	int m_A;
};

//同名成员属性处理
void test01()
{
	son s;
	cout << "son_m_A= " << s.m_A << endl;//直接访问的是子类本身的数值
	cout << "Base_m_A= " << s.Base::m_A << endl; //如果通过子类对象想访问父类同名成员，需要加作用域

}

//同名成员函数处理
void test02()
{
	son s2;
	s2.func();
	s2.Base::func();

	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	s2.Base::func(10);
}

int main() {

	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/



class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

public:
	static int m_A;//静态成员类内声明类外初始化
};
int Base::m_A = 100;

class son :public Base
{
public:
	static void func()
	{
		cout << "son - static void func()" << endl;
	}

	static int m_A;
};
int son::m_A = 200;

//同名静态成员属性
void test01()
{
	//通过对象访问静态成员
	son s;
	cout << "通过对象访问： " << endl;
	cout << "Son  下 m_A = " << s.m_A << endl;
	cout << "Base 下 m_A = " << s.Base::m_A << endl;

	//通过类名访问静态成员
	cout << "通过类名访问： " << endl;
	cout << "Son  下 m_A = " << son::m_A << endl;//不用创建对象s了
	cout << "Base 下 m_A = " << son::Base::m_A<< endl;//第一个：：表示通过类名方式访问，第二个：：表示访问父类作用域下

}

//同名静态成员函数
void test02()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	son s2;
	s2.func();
	s2.Base::func();

	//通过类名访问
	cout << "通过类名访问： " << endl;
	son::func();
	son::Base::func();
	//出现同名，子类会隐藏掉父类中所有的同名成员函数，包括有参和无参，需要加作作用域访问
	son::Base::func(10);

}


int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
//总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）