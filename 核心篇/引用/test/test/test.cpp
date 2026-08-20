#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


/*
1、引用的基本语法
数据类型 &别名=原名			--就可以用别名来操作原名的内容

2、引用需要注意的事项：
1、引用必须初始化
即不能直接 int &b；需要初始化到a上
2、引用在初始化后，不可以改变
即不能更改别名；
例int c=20;
b=c;//这是赋值操作，不是更改引用

3、引用的作用：
（1）引用做函数参数
函数传参时，可以利用引用的技术让形参修饰实参
从而可以简化指针修改实参

（2）引用做函数返回值
作用：引用是可以作为函数的返回值存在的
注意：**不要返回局部变量引用**
用法：函数调用作为左值


4、引用的本质
本质：引用的本质在C++内部实现是一个指针常量int* const p

//发现是引用，转换为 int* const ref = &a;
void func(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}
int main(){
	int a = 10;

	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改，但是指向的内容可以改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	return 0;
}


5、常量引用
作用：常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，防止形参改变实参

//引用使用的场景，通常用来修饰形参
void showValue(const int& v) {//此处const确保v不能被修改，也等于v引用的main函数中的a不能被修改
	//v += 10;
	cout << v << endl;
}

int main() {

	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref = 10;

	//ref = 100;  //加入const后不可以修改变量
	cout << ref << endl;

	//函数中利用常量引用防止误操作修改实参
	int a = 10;
	showValue(a);

	system("pause");

	return 0;
}



*/



//引用的基本使用
//int main()
//{
//	int a = 10;
//	//创建引用
//	int& b = a;
//	cout <<"b= " << b << endl;
//	cout <<"a= " << a << endl;
//
//	//通过别名修改原名的内容
//	b = 100;
//	cout << "b= " << b << endl;
//	cout << "a= " << a << endl;
//	return 0;
//}



////交换函数
////1.值传递
//void myswap1(int a, int b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
////2.地址传递
//void myswap2(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//
//}
////3.引用传递
//void myswap3(int& a, int& b)//这里的a，b都是main函数中a，b的别名，所以对别名修改都会修改原名的内容
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	myswap1(a, b);
//	cout << "a=" << a << "  b=" << b << endl;//结果仍然是10和20，值传递返回的并没有更改
//
//	//myswap2(&a, &b);
//	//cout << "a=" << a << "  b=" << b << endl;//正常交换
//
//	myswap3(a, b);//引用传递，形参会修饰实参
//	cout << "a=" << a << "  b=" << b << endl;//正常交换
//
//}




//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

int main() {

	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;//第二次就会被释放，从而输出错误

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;//函数引用可以直接作为左值，来被赋值，从而修改函数的返回值

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}
