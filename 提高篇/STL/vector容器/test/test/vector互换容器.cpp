#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

/*
**功能描述：**
* 实现两个容器内元素进行互换


**函数原型：**
* `swap(vec);`  // 将vec与本身的元素互换


*/


void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	cout << "互换前：" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	//互换容器
	cout << "互换后：" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//2.实际用途
//巧用swap可以收缩内存空间
void test02()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v的容量为： " << v.capacity() << endl;//13w
	cout << "v的大小为： " << v.size() << endl;//10w

	v.resize(3);//重新指定大小
	cout << "v的容量为： " << v.capacity() << endl;//还是13w,浪费空间
	cout << "v的大小为： " << v.size() << endl;//3

	//巧用swap收缩内存
	vector<int>(v).swap(v);
	//vector<int>(v)匿名对象，拷贝构造，会按v目前所用的个数来初始化容器，然后再和原来的指针互换
	//互换之后匿名对象会被回收
	cout << "v的容量为： " << v.capacity() << endl;//3
	cout << "v的大小为： " << v.size() << endl;//3
}



int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}
