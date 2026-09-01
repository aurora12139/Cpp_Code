#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

/*
多态的优点：
* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护



*/



//分别利用普通写法和多态技术实现计算器

//普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return num1 + num2;
		}
		else if(oper == "-")
		{
			return num1 - num2;
		}
		else if (oper == "*")
		{
			return num1 * num2;
		}
		//如果要扩展新的功能，需要修改源码
		//在真实开发中提倡开闭原则
		//对拓展开放，但是对修改关闭

		else if (oper == "/")
		{
			return num1 / num2;
		}

	}


	int num1;//操作数1
	int num2;//操作数2
};


void test01()
{
	//创建计算器对象
	Calculator c;
	c.num1 = 20;
	c.num2 = 10;

	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
	cout << c.num1 << " / " << c.num2 << " = " << c.getResult("/") << endl;

}


//利用多态实现计算器

//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult() = 0;//纯虚函数


	int num1;
	int num2;
};

//加法计算器类
class Addcalculator :public AbstractCalculator
{
	int getResult()
	{
		return num1 + num2;
	}
};

//减法计算器类
class Subcalculator :public AbstractCalculator
{
	int getResult()
	{
		return num1 - num2;
	}
};

//乘法计算器类
class Mulcalculator :public AbstractCalculator
{
	int getResult()
	{
		return num1 * num2;
	}
};

//除法计算器类
class Divbcalculator :public AbstractCalculator
{
	int getResult()
	{
		return num1 / num2;
	}
};

void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	//加法
	AbstractCalculator* abc = new Addcalculator;
	abc->num1 = 100;
	abc->num2 = 10;

	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	//new出来的对象在堆区，用完记得销毁
	delete abc;//指针还在只是指针指向的对象不在了

	//减法
	abc = new Subcalculator;
	abc->num1 = 100;
	abc->num2 = 10;

	cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
	//new出来的对象在堆区，用完记得销毁
	delete abc;

	//乘法
	abc = new Mulcalculator;
	abc->num1 = 100;
	abc->num2 = 10;

	cout << abc->num1 << " * " << abc->num2 << " = " << abc->getResult() << endl;
	//new出来的对象在堆区，用完记得销毁
	delete abc;

}


int main()
{
	//test01();
	test02();
	return 0;
}

//多态好处：
//代码组织结构清晰
//可读性强
//利于前期和后期的扩展以及维护




