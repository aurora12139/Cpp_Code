#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

/*
在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为  ==friend==

友元的三种实现

* 全局函数做友元
* 类做友元
* 成员函数做友元

*/

/*
//全局函数做友元
class Building
{
	//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
	friend void goodGay(Building& building);

public:
	Building()
	{
		m_Sittingroom = "客厅";
		m_Bedroom = "卧室";
	}

public:
	string m_Sittingroom;//客厅

private:
	string m_Bedroom;//卧室
};


//全局函数
void goodGay(Building& building)
{
	cout << "好基友正在访问： " << building.m_Sittingroom << endl;
	cout << "好基友正在访问： " << building.m_Bedroom << endl;
}

void test01()
{
	Building building;
	goodGay(building);
}


int main()
{
	test01();
	return 0;
}
*/

/*
//类做友元
class Building;
class goodGay
{
public:
	void visit();//参观函数访问Building中的属性
	goodGay();
	Building* building;//定义了一个指针变量，类指针，building指针名，building 保存一个 Building 对象的地址

};

class Building
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay;

public:
	Building();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};


//类外写成员函数
Building::Building()//告诉是在Building作用域下
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	//创建一个建筑物对象
	building = new Building;//new关键字创建出一个Building对象
}

void goodGay::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
	goodGay gg;
	gg.visit();

}

int main() {

	test01();

	system("pause");
	return 0;
}
*/




//成员函数做友元

class Building;
class goodGay
{
public:
	goodGay();

	void visit();//让visit函数可以访问Building中私有内容
	void visit2();//让visit2函数不能访问Building中私有内容

	Building* building;
};

class Building
{
	friend void goodGay::visit();	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容

public:
	Building();
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit函数正在访问：" << building->m_BedRoom << endl;

}
void goodGay::visit2()
{
	cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit2函数正在访问：" << building->m_BedRoom << endl;

}

void test01()
{
	goodGay gg;
	gg.visit();
	gg.visit2();
}

int main() {

	test01();

	system("pause");
	return 0;
}