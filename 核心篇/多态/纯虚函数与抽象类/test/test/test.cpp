#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
####  纯虚函数和抽象类
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将虚函数改为**纯虚函数**

纯虚函数语法：`virtual 返回值类型 函数名 （参数列表）= 0 ;`

当类中有了纯虚函数，这个类也称为==抽象类==

**抽象类特点**：
无法实例化对象
子类必须重写抽象类中的纯虚函数，否则也属于抽象类






*/


class Base
{
public:
	virtual void func() = 0;//必须对虚函数才能直接等于0
	//纯虚函数，只要有一个纯虚函数这个类就成为抽象类
	//抽象类：不允许实例化对象   以及 必须要重写父类中的纯虚函数，否则也属于抽象类
};

class son :public Base
{
	virtual void func()
	{
		cout << "func的调用" << endl;
	}
};


void test01()
{
	//Base a;抽象类不允许实例化对象
	//son s;//子类必须重写父类中的虚函数，否则也无法实例化

	Base* b = new son;
	b->func();//父类指针指向子类对象56
}



int main()
{

	test01();

	system("pause");

	return 0;
}