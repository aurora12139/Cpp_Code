#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

/*
**功能描述：**
* 减少vector在动态扩展容量时的扩展次数



**函数原型：**
* `reserve(int len);`//容器预留len个元素长度，预留位置不初始化，元素不可访问。


*/


void test01()
{
	vector<int> v;

	int num = 0;//统计开辟的次数
	int* p = NULL;
	v.reserve(100000);

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];//因为每次开辟都会重新找一整块内存，原来的指针指向原来内存的首地址，重新开辟之后就不是了
			num++;
		}
	}
	cout << "num= " << num << endl;//30次，如果一开始就预留了这么大的空间就只用开辟一次
}


int main() {

	test01();

	system("pause");

	return 0;
}