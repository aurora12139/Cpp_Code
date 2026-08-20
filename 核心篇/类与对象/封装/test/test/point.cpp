#define _CRT_SECURE_NO_WARNINGS
#include"point.h"
//设置x
void point::setx(int a)//表明setx是point作用域下的
{
	x = a;
}
//获取x
int point::getx()
{
	return x;
}
//设置y
void point::sety(int a)
{
	y = a;
}
//获取y
int point::gety()
{
	return y;
}
