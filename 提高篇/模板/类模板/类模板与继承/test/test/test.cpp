#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
#### 类模板与继承

当类模板碰到继承时，需要注意一下几点：

1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
2.如果不指定，编译器无法给子类分配内存
3.如果想灵活指定出父类中T的类型，子类也需变为类模板

*/


template <class T>
class Base
{
	T m;
};

//class Son :public Base		//错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son:public Base<int>
{

};

void test01()
{
	Son s1;
}

//如果想灵活指定父类中T的类型，子类也需要边成类模板
template <class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}

	T1 obj;

};

void test02()
{
	Son2<int, char>s2;//int表示的子类的数据类型，char表示父类中的数据类型
}


int main() {

	test01();

	test02();

	system("pause");

	return 0;
}