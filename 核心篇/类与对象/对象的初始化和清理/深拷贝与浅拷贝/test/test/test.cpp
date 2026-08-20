#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*

浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作

*/

class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}

	person(int a,int b)
	{
		age = a;
		high = new int(b);
		cout << "person的有参构造函数调用" << endl;
	}

	//所以要自己设计拷贝构造函数
	person(const person& p)
	{
		cout << "person的拷贝构造函数调用" << endl;
		age = p.age;
		//high = p.high;//编译器默认浅拷贝操作
		//深拷贝操作，重新在堆区创建一块内存空间
		high = new int(*p.high);//在堆区创建一个整型（身高180）


	}
	~person()
	{
		//析构代码可以将堆区开辟的数据做释放操作
		if (high != NULL)
		{
			delete high;
			high = NULL;
		}
		cout << "person的析构函数调用" << endl;
		
	}
	int age;//年龄
	int* high;

};

void test01()
{
	person p1(18,180);
	cout << "p1的年龄为" << p1.age << endl;
	cout << "p1的身高为" << *p1.high << endl;

	person p2(p1);//浅拷贝操作，high指向的地址编号会完全复制过去，p1p2就会重复释放一块区间，会造成堆区内存重复释放
	cout << "p2的年龄为" << p2.age << endl;
	cout << "p2的身高为" << *p2.high << endl;


}

int main()
{
	test01();


	system("pause");
	return 0;
}