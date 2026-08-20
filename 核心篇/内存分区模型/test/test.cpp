#define _CRT_SECURE_NO_WARNINGS

/*
C++程序在执行时，将内存大方向划分为**4个区域**
- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
- 堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收














*/
#include <iostream>
#include<string>
using namespace std;

////全局变量
//int g_a = 10;
//int g_b = 10;
//
////const修饰的全局变量
//const int c_b = 10;
//
//
//int main()
//{
//	//全局区：包含全局变量，静态变量，常量
//
//	//创建普通局部变量
//	int a = 10;
//	int b = 10;
//
//	cout << "a的地址为：" << &a << endl;
//	cout << "b的地址为：" << &b << endl;
//
//	cout << "g_a的地址为：" << &g_a << endl;
//	cout << "g_b的地址为：" << &g_b << endl;
//
//	//创建静态变量
//	static int s_a = 10;
//	static int s_b = 10;
//	cout << "s_a的地址为：" << &s_a << endl;
//	cout << "s_b的地址为：" << &s_b << endl;
//
//	//常量分为
//	//字符串常量		例："hello"
//	//const修饰的全局变量	例：const int a，注意const修饰局部变量不放在全局区里面
//	const int c_a = 10;
//	cout << "字符串常量的地址为：" << &"hello" << endl;
//	cout << "const修饰的全局变量c_b的地址为：" << &c_b << endl;
//	cout << "const修饰的局部变量c_a的地址为：" << &c_a << endl;
//
//
//
//	return 0;
//	system("pause");
//}


////栈区数据注意事项			--不要返回局部变量地址
////栈区的数据由编译器管理开辟和释放
////栈区存放形参和局部变量
//int* func(int b)   //形参数据存放在栈区
//{
//	b = 100;
//	int a = 10;//局部变量也存在栈区，栈区的数据在函数执行完后自动释放
//	return &a;
//}
//
//int main()
//{
//	int b = 10;
//	int* p = func(b);
//	cout << *p << endl;//第一次可以正确打印a的值，是因为编译器作了保留
//	cout << *p << endl;//第二次这个数据就不再保留了
//
//	return 0;
//}




//堆区
//由程序员分配释放, 若程序员不释放, 程序结束时由操作系统回收
//在C++中主要利用new在堆区开辟内存

int* func()
{
	//利用new关键字。将数据开辟到堆区,返回的是这一块区间的地址
	//指针本质也是一个局部变量，放在栈区，只是指针指向的数据保存在堆区
	int* p=new int(10);//在堆区上开辟了一个整型是10，小括号是创建变量

	return p;
}

int* func2()
{
	//利用new关键词创建10个整型的数组
	int *arr= new int[10];
	return arr;
}


//int main()
//{
//	//在堆区开辟数据
//	int* p = func();
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;//不管打印几次都是10
//
//	//如果想释放堆区的数据，需要利用关键字delete
//	delete p;
//	cout << *p << endl;//此时就无法打印
//	return 0;
//}

int main()
{
	int* p = func2();
	for (int i = 0; i < 10; i++)
	{
		p[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << endl;
	}

	//想释放堆区的数组的话，要加一个[]才行
	delete[] p;
	return 0;
}


