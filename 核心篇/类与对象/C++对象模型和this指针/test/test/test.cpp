#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
成员变量和成员函数分开存储的

c++通过提供特殊的对象指针，this指针，解决上述问题。**this指针指向被调用的成员函数所属的对象**
this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的用途：

*  当形参和成员变量同名时，可用this指针来区分
*  在类的非静态成员函数中返回对象本身，可使用return *this


#### 空指针访问成员函数
C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
如果用到this指针，需要加以判断保证代码的健壮性


#### const修饰成员函数
**常函数：**
* 成员函数后加const后我们称为这个函数为**常函数**
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数

*/



/*
//成员函数和成员变量是分开存储的，只有非静态成员变量才属于类对象
class Person
{
	int m_A;//非静态成员变量.   属于类对象上

	static int m_B;//静态成员变量，  不属于类对象上

	void func()  {};//非静态成员函数，   不属于类对象上
	static void func2() {};//静态成员函数，   不属于类对象上
};
int Person::m_B = 0;

void test01()
{
	Person p;
	
	cout << "size of p= " << sizeof(p) << endl;
	//答案为1，因为C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
}

void test02()
{
	Person p;

	cout << "size of p= " << sizeof(p) << endl;
	//答案为4,当对象不是空的时候，就是按内部的成员变量大小分配内存了
}

int main()
{
	//test01();
	test02();
	return 0;
}
*/



/*
//*  当形参和成员变量同名时，可用this指针来区分
//* 在类的非静态成员函数中返回对象本身，可使用return* this
class person
{
public:
	person(int age)
	{
		this->age = age; //当形参和成员变量同名时，可用this指针来区分,this指针指向被调用的成员函数所属的对象
	}

	person& personAddAge(person& p)//必须返回的也是引用形式，避免拷贝新对象，从而支持链式调用
		//如果不带这个&引用的话，就会临时拷贝一份新名称出来，后续的链式调用就不是调的最开始的了
	{
		this->age += p.age;

		return *this;//this指向p2的指针，而*this指向的就是p2这个对象本体
	}


	int age;
};

void test01()
{
	person p1(18);
	cout << "p1's age = " << p1.age << endl;
}

void test02()
{
	person p1(10);
	person p2(10);
	//p2.personAddAge(p1);//20

	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);

	cout<< "p2's age = " << p2.age << endl;


}

int main()
{
	//test01();
	test02();
	return 0;
}
*/



/*
//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;//mAge默认前面会有一个this指针等效于this->mAge
	}

public:
	int mAge;
};

void test01()
{
	Person* p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}
*/



class person
{
public:

	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void showPerson() const//加了这个const之后this指针指向的对象的数据也不可以修改
	{
		//this->m_A = 100;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的

		this->m_B = 200;
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B;  //加了mutable这个关键字之后就可以修改了
};

void test01()
{
	person p;
	p.showPerson();
}

//常对象
void test02()
{
	const person p;//在对象前加const，变为常对象
	//p.m_A = 100;//常对象不能修改成员变量的值,但是可以访问
	p.m_B = 400;//但是常对象可以修改mutable修饰成员变量

	//常对象只能调用常函数
	p.showPerson();
	//p.func();常对象不能调用普通成员函数，因为普通成员函数可以修改属性
}

int main() {

	test01();

	system("pause");

	return 0;
}