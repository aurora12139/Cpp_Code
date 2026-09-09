#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

/*
**功能描述：**
* 对vector中的数据的存取操作


**函数原型：**
* `at(int idx); `     //返回索引idx所指的数据
* `operator[]; `       //返回索引idx所指的数据
* `front(); `            //返回容器中第一个数据元素
* `back();`              //返回容器中最后一个数据元素
*/

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//利用[]方式访问数组中元素
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";//类似数组可以用中括号去访问容器内部数据
	}
	cout << endl;

	//利用at方式访问元素
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;

	//获取第一个元素
	cout << "第一个元素为： " << v.front() << endl;

	//获取最后一个元素
	cout << "最后一个元素为： " << v.back() << endl;
}


int main() {

	test01();

	system("pause");

	return 0;
}
