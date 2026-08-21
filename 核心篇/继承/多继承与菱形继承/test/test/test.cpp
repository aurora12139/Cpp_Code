#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
#### 多继承语法
C++允许** 一个类继承多个类**

语法：` class 子类 ：继承方式 父类1 ， 继承方式 父类2...`逗号分隔就行

多继承可能会引发父类中有同名成员出现，需要加作用域区分
 C++实际开发中不建议用多继承**


 #### 菱形继承
**菱形继承概念：**
两个派生类继承同一个基类
又有某个类同时继承者两个派生类
这种继承被称为菱形继承，或者钻石继承


 */


/*
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}

	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}

	int m_A;
};

//子类  同时继承A和B
class son :public Base1, public Base2
{
public:
	son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};


void test01()
{
	son s;

	cout << "sizeof Son = " << sizeof(s) << endl;
	//cout << "m_A= " << s.m_A << endl;//二义性，如果两个父类中都有同名成员的话，需要加作用域区分
	
	cout <<"Base1::m_A= " << s.Base1::m_A << endl;
	cout << "Base2::m_A= " << s.Base2::m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结： 多继承中如果父类中出现了同名情况，子类使用时候要加作用域
*/



//动物类
class animal
{
public:
	int m_Age;
};

//羊类
class sheep :virtual public animal
{

};
//驼类
class tuo :virtual public animal
{

};
//羊驼类
class sheeptuo :public sheep, public tuo
{

};



void test01()
{
	sheeptuo st;
	st.sheep::m_Age = 18;
	st.tuo::m_Age = 28;

	//当菱形继承时，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age = " << st.sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.tuo::m_Age << endl;

	//但是这份数据只要有一份就可以了，但是菱形继承会导致数据有两份，资源浪费
	//利用虚继承可以解决菱形继承的问题
	//在继承之前加上关键字virtual变为虚继承
	// 中间基被继承成了{vbptr}，虚基类指针，指向虚基类表，记录了偏移量，通过这个表可以找到唯一的m_Age
	//animal类被称为虚基类
	//这样上面两个输出都是28，因为m_Age只有一份了
	cout << "st.m_Age = " <<st.m_Age << endl;//就不会出现不明确的问题了


};

int main() {

	test01();

	system("pause");

	return 0;
}

//总结：
//* 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//* 利用虚继承可以解决菱形继承问题