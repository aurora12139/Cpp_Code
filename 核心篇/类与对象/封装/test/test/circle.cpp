#define _CRT_SECURE_NO_WARNINGS
#include "circle.h"
//设置半径
void circle::setR(int a)
{
	R = a;
}
//获取半径
int circle::getR()
{
	return R;
}
//设置圆心
void circle::setcenter(point c)
{
	center = c;
}
//获取圆心
point circle::getcenter()
{
	return center;
}
