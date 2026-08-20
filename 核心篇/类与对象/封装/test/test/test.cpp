#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<string>
/*
类和对象
C++面向对象的三大特性为：封装、继承、多态

C++认为万事万物都皆为对象，对象上有其属性和行为
具有相同性质的对象，就可以抽象成类，比如人属于人类、车属于车类

1、封装：封装是C++面向对象三大特性之一
封装的意义
* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制

**封装意义一：**
​	在设计类的时候，属性和行为写在一起，表现事物
语法：** `class 类名{   访问权限： 属性  / 行为  };
类中的属性和行为可以统称为成员
属性		也可以叫成员属性  成员变量
行为		也可以较成员函数  成员方法

**封装意义二：**
类在设计时，可以把属性和行为放在不同的权限下，加以控制
访问权限有三种：
1. public        公共权限	成员 类内可以访问  类外可以访问
2. protected	保护权限		成员 类内可以访问  类外不可以访问
3. private      私有权限		成员 类内可以访问  类外不可以访问

ps：在C++中 struct和class唯一的**区别**就在于 **默认的访问权限不同**
区别：
* struct 默认权限为公共   public
* class   默认权限为私有  private  默认类外不能访问属性


#### 成员属性设置为私有
**优点1：**将所有成员属性设置为私有，可以自己控制读写权限
**优点2：**对于写权限，我们可以检测数据的有效性





*/

/*
//设计一个圆类，求圆的周长

//class代表设计一个类，类后面紧跟着类名称
double pi = 3.14;
class circle
{
	//访问权限（公共权限）
public:
	//属性(半径)
	int r;
	//行为（获取圆的周长，一般用函数表示）
	double calculateZC()
	{
		return (2 * pi * r);
	}
};
//即需要写清楚类的权限、属性、行为，通过创建具体的圆来调用类的计算

int main()
{
	//通过圆类创建具体的圆（对象）
	circle c1;
	//给圆对象的属性进行赋值
	c1.r = 10;
	
	cout << "半径为10的圆的周长为：" << c1.calculateZC() << endl;

	return 0;

}
*/

/*
//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
#include <string>
class student 
{
	//访问权限
public:
	
	//属性
	string name;//姓名
	int id;//学号

	//行为
	//显示姓名和学号
	void showstudent()
	{
		cout << "姓名为：" << name << "学号为：" << id << endl;
	}
	//通过行为可以对属性进行赋值
	void setname(string n)
	{
		name = n;
	}
};

//实例化对象
int main()
{
	//创建一个具体学生
	student s1;
	//给对象赋值
	//s1.name = "zhangsan";
	s1.setname("zhangsan");
	s1.id = 2345585;
	//对对象进行操作
	s1.showstudent();

	student s2;
	s2.id = 327092;
	s2.name = "lisi";
	s1.showstudent();

	return 0;
}
*/


/*
//成员属性设置为私有,类外不能修改，只能类内提供函数方法来读写
class person
{
public:
	//设置姓名
	void setname(string n)
	{
		name = n;
	}
	//获取姓名
	string getname()
	{
		return name;
	}
	//获取年龄
	int getage()
	{
		return age;
	}
	void setage(int a)
	{
		if (a < 0 || a>150)
		{
			cout << "年龄不在范围，设置失败" << endl;
			return;
		}
		age = a;
	}
	//设置idol
	void setidol(string m)
	{
		idol = m;
	}
private:
	string name;//可读可写

	int age;//只读,可以写，但是年龄要在0~150之间

	string idol;//只写不能读
};

int main()
{
	person s1;
	s1.setname("zhangsan");
	cout << "姓名为：" << s1.getname() << endl;
	s1.setage(15);
	cout << "年龄为：" << s1.getage() << endl;
	s1.setidol("weixin");
	return 0;
}
*/

/*
//**练习案例1：设计立方体类**
//设计立方体类(Cube)
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等。

class cube
{
public:
	//设置长
	void setL(int l)
	{
		L = l;
	}
	//获取长
	int getL()
	{
		return L;
	}
	//设置宽
	void setW(int w)
	{
		W = w;
	}
	//获取宽
	int getW()
	{
		return W;
	}
	//设置高
	void setH(int h)
	{
		H = h;
	}
	//获取高
	int getH()
	{
		return H;
	}
	//计算面积
	int calculateS()
	{
		return 2 * L * W + 2 * L * H + 2 * H * W;
	}
	//计算体积
	int calculateV()
	{
		return L * H * W;
	}

	//利用成员函数判断两个立方体是否相等
	bool issamebyclass(cube c)
	{
		if (H == c.getH() && L == c.getL() && W == c.getW())
		{
			return true;
		}
		else
			return false;
	}


private:
	int L;
	int W;
	int H;
};

//利用全局函数判断是否相等
bool issame(cube& c1, cube& c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	else
		return false;
}

int main()
{
	cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout << "c1面积为：" << c1.calculateS() << endl;
	cout << "c1体积为：" << c1.calculateV() << endl;

	cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);
	cout << "c2面积为：" << c2.calculateS() << endl;
	cout << "c2体积为：" << c2.calculateV() << endl;

	//利用全局函数判断
	bool ret = issame(c1, c2);//全局函数需要传两个参数
	if (ret == 1)
	{
		cout << "c1和c2相等" << endl;
	}
	else
		cout << "c1和c2不相等" << endl;

	//利用成员函数判断
	ret = c1.issamebyclass(c2);//局部函数只用传一个参数，因为原始的就已经知道了，因为是c1.所以内部默认用的c1的参数
	if (ret == 1)
	{
		cout << "c1和c2相等" << endl;
	}
	else
		cout << "c1和c2不相等" << endl;
	return 0;
}
*/


//判断点与圆的位置关系

//class point
//{
//public:
//	//设置x
//	void setx(int a)
//	{
//		x = a;
//	}
//	//获取x
//	int getx()
//	{
//		return x;
//	}
//	//设置y
//	void sety(int a)
//	{
//		y = a;
//	}
//	//获取y
//	int gety()
//	{
//		return y;
//	}
//private:
//	int x;
//	int y;
//};

//class circle
//{
//public:
//	//设置半径
//	void setR(int a)
//	{
//		R = a;
//	}
//	//获取半径
//	int getR()
//	{
//		return R;
//	}
//	//设置圆心
//	void setcenter(point c)
//	{
//		center = c;
//	}
//	//获取圆心
//	point getcenter()
//	{
//		return center;
//	}
//private:
//	int R;//半径
//	point center;//圆心   在类中可以让另一个类作为本类中的成员
//};

#include"circle.h"
#include"point.h"
//判断点与圆的关系
void isIncircle(circle& c, point& p)
{
	int distance =
		(c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());

	int rdistance =
		c.getR() * c.getR();

	if (distance == rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if(distance <= rdistance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}

int main()
{
	//创建圆
	circle c;
	c.setR(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);

	//创建点
	point p;
	p.setx(10);
	p.sety(10);

	//判断
	isIncircle(c, p);
	return 0;
}