#pragma once
#include<iostream>
using namespace std;
class point
{
public:
	//设置x
	void setx(int a);

	//获取x
	int getx();

	//设置y
	void sety(int a);

	//获取y
	int gety();

private:
	int x;
	int y;
};