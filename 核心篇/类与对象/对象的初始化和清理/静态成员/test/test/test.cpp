#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
静态成员

静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

静态成员分为：

*  静态成员变量
   *  所有对象共享同一份数据
   *  在编译阶段分配内存
   *  类内声明，类外初始化
*  静态成员函数
   *  所有对象共享同一个函数
   *  静态成员函数只能访问静态成员变量



*/


/*
class person
{
public:

	//所有对象共享同一份数据
	//在编译阶段分配内存
	//类内声明，类外初始化
	static int A;
private:
	static int B;
};
//类外初始化，表示在person作用域下
int person::A = 100;
int person::B = 200;
void test01()
{
	//person p;
	//cout << p.A << endl;//100

	//person p1;
	//p1.A = 200;
	//cout << p1.A << endl;//200，一个人改了其他人都会变

	//静态成员变量有两种访问方式
	//1.通过对象进行访问
	person p;
	cout << p.A << endl;
	//2.通过类名进行访问
	cout << person::A << endl;

	//此外静态成员变量也是有访问权限的
	//cout << person::B << endl;//会报错因为在private权限下

}

int main()
{
	test01();
	system("pause");
	return 0;
}

*/


//静态成员函数
class person
{
	//所有对象共享同一个函数
	//静态成员函数只能访问静态成员变量
public:
	static void func()
	{
		A = 200;
		//B = 100;静态成员函数只能访问静态成员变量,因为B可以在多个对象中出现，可能是P1，p2等等，因为B没有共享，所以函数不知道是哪个对象的 
		cout << "静态成员函数的调用" << endl;
	}
	static int A;
	int B = 10;
};

int person::A = 100;

void test01()
{
	//1.通过对象访问
	person p;
	p.func();
	//2.通过类名访问
	person::func();

	//此外同样有访问权限，不能访问private里的
}

int main()
{
	test01();
	return 0;
}