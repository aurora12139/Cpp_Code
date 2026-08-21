#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
继承中的对象模型
从父类继承过来的成员，哪些属于子类对象中？
都属于，private也属于，只是被隐藏了

继承中构造和析构顺序
继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反

*/


/*
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void test01()
{
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性 是被编译器给隐藏了，所以访问不到，但是确实被继承了
	cout << "sizeof Son = " << sizeof(Son) << endl;//3*4+1*4=16
}

int main() {

	test01();

	system("pause");

	return 0;
}

//利用开发人员命令提示工具可以查看对象模型
//跳转盘符  D：
//跳转文件路径 cd 
//查看命名
//开始报告单个类布局：cl /d1 reportSingleClassLayout类名 文件名

*/


class Base
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base()
	{
		cout << "Base析构函数!" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son()
	{
		cout << "Son析构函数!" << endl;
	}

};


void test01()
{
	//继承中 先构造父类再构造子类，析构顺序与构造相反，先析构子类再析构父类
	Son s;
}

int main() {

	test01();

	system("pause");

	return 0;
}