#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//点与圆关系案例

class point
{
public://行为
	//设置xy和获取xy
	void setX(int x)
	{
		X = x;
	}
	int getX()
	{
		return X;
	}

	void setY(int y)
	{
		Y = y;
	}
	int getY()
	{
		return Y;
	}

private://属性
	int X;
	int Y;
};


class circle
{
public:
	//设置与获取半径、圆心
	void setR(int r)
	{
		R = r;
	}
	int getR()
	{
		return R;
	}

	void setcenter(point c)
	{
		center = c;
	}
	point getcenter()
	{
		return center;
	}
private:
	int R;//半径
	point center;//圆心
};


//判断点和圆的关系
void isInCircle(circle &c,point &p)
{
	//圆心与点之间的距离平方
	int distance = (c.getcenter().getX() - p.getX()) * (c.getcenter().getX() - p.getX()) +
		(c.getcenter().getY() - p.getY()) * (c.getcenter().getY() - p.getY());

	//半径的平方
	int rDistance = c.getR() * c.getR();

	//判断关系
	if (distance < rDistance)
	{
		cout << "点在圆内" << endl;
	}
	else if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
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
	center.setX(10);
	center.setY(0);
	c.setcenter(center);
	//创建点
	point p;
	p.setX(10);
	p.setY(10);
	isInCircle(c, p);
	system("pause");
	return 0;
}