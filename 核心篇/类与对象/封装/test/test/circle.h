#pragma once
#include<iostream>
using namespace std;
#include"point.h"
class circle
{
public:
	//设置半径
	void setR(int a);

	//获取半径
	int getR();

	//设置圆心
	void setcenter(point c);

	//获取圆心
	point getcenter();

private:
	int R;//半径
	point center;//圆心   在类中可以让另一个类作为本类中的成员
};
