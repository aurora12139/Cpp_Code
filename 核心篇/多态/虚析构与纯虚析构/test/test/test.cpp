#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*
#### 虚析构和纯虚析构
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性：

* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象


虚析构语法：
`virtual ~类名(){}`

纯虚析构语法：

` virtual ~类名() = 0;`

`类名::~类名(){}`
*/


class Animal
{
public:
	Animal()
	{
		cout << "Animal 构造函数调用！" << endl;
	}

	//纯虚函数
	virtual void speak() = 0;


	//virtual ~Animal()
	//{
	//	cout << "Animal 析构函数调用！" << endl;
	//}

	//纯虚析构
	virtual ~Animal() = 0;//必须要代码实现
	//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
};

Animal:: ~Animal()
{
	cout << "Animal 纯析构函数调用！" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		 m_name = new string(name);
	}
	virtual void speak()
	{
		cout << *m_name <<"小猫在说话" << endl;
	}

	~Cat()
	{
		if (m_name != NULL)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	string* m_name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类指针在析构的时候不会调用子类中的析构函数，导致子类如果有堆区属性，有可能出现内存泄露
	//怎么解决？给父类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {

	test01();

	system("pause");

	return 0;
}

/*
总结：

​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象，因为有些子类对象创建在堆区，所以子类也需要释放

​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构

​	3. 拥有纯虚析构函数的类也属于抽象类

*/