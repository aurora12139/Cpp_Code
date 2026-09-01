#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
#### 多态的基本概念
**多态是C++面向对象三大特性之一**

多态分为两类
* 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
* 静态多态的函数地址早绑定  -  编译阶段确定函数地址
* 动态多态的函数地址晚绑定  -  运行阶段确定函数地址




*/


//动物类
class animal
{
public:
	virtual void speak()
//Speak函数就是虚函数
//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	{
		cout << "动物在说话" << endl;
	}

};


//猫类
class cat :public animal
{
public:
	//void speak()
	//{
	//	cout << "小猫在说话" << endl;
	//}
};


//狗类
class dog :public animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};


//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编

//执行说话的函数
//地址早绑定  在编译阶段就确定了函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定，在animal里的speak函数前加virtual
void doSpeak(animal& a)   //animal &a =cat
{
	a.speak();
}

void test01()
{
	cat c;
	doSpeak(c);

	dog d;
	doSpeak(d);
}

void test02()
{
	cout << "sizeof animal= " << sizeof(animal) << endl;//不加virtual是1，加了是4，4即为指针的大小，vfptr：虚函数指针
	//vfptr指向虚函数表vftable，表内会记录虚函数的地址：&animal::speak
	//子类继承之后，也会把父类中的虚函数继承下来，
	//但是当子类重写父类的虚函数之后，子类中的虚函数表 内部 会被替换成子类的虚函数地址，即vftable中为：&cat::speak
	//所以当父类的指针或者引用指向子类对象的时候，就会发生多态
	//即animal&a=cat,则a.speak()就会调用子类中的该虚函数

}

int main()
{
	//test01();
	test02();
	system("pause");//动物在说话
	return 0;
}

//总结：
//多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数  //重写：函数返回值类型  函数名 参数列表 完全一致称为重写
//多态使用：
//父类指针或引用指向子类对象