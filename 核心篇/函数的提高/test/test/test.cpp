#define _CRT_SECURE_NO_WARNINGS

/*
函数提高
函数内部可以默认参数，但是如果自己传入数据，就用自己的数据，如果没有就用默认值
注意事项：
1、如果某个位置开始有默认参数，那么从这这个位置往后，从左到右都必须要有默认值
2、如果函数声明有默认参数，则函数实现就不能有默认参数（声明和实现只能有一个有默认参数）


函数占位参数
格式：返回值类型		函数名（数据类型）{}
ps：占位参数也可以有默认值

函数重载
意义：函数名可以相同，提高复用性
函数重载满足条件：
1、同一个作用域下     2、函数名称相同			3、函数参数类型不同  或者个数不同  或者顺序不同
需注意函数的返回值不能作为函数重载的条件
并且函数重载在有默认参数时容易出现二义性，在写函数重载时尽量避免写函数默认参数

*/

#include<iostream>
using namespace std;

////默认参数
//int func(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
//int main()
//{
//	cout << func(10,30) << endl;
//
//	return 0;
//}

//函数重载
void func()
{
	cout << "func的调用" << endl;
}
void func(int a)
{
	cout << "func（int a）的调用" << endl;
}
int main()
{
	func();
	func(10);
	return 0;
}

