#define _CRT_SECURE_NO_WARNINGS
#include"myArrary.hpp"


/*
案例描述:  实现一个通用的数组类，要求如下：

可以对内置数据类型以及自定义数据类型的数据进行存储
将数组中的数据存储到堆区(new)
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及operator=防止浅拷贝问题
提供尾插法和尾删法对数组中的数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获取数组中当前元素个数和数组的容量

*/

void printIntArray(myArrary<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test01()
{
	myArrary<int> arr1(5);//有参构造

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.pushBack(i);
	}
	cout << "arr1打印输出：" << endl;
	printIntArray(arr1);

	cout << "array1的大小：" << arr1.getSize() << endl;
	cout << "array1的容量：" << arr1.getCapacity() << endl;


	myArrary<int> arr2(arr1);//拷贝构造
	arr2.PopBack();//尾删
	cout << "arr2打印输出：" << endl;
	printIntArray(arr2);
	cout << "arr2的大小：" << arr2.getSize() << endl;
	cout << "arr2的容量：" << arr2.getCapacity() << endl;


	//myArrary<int> arr2(arr1);//拷贝构造
	//2myArrary<int> arr3(100);//operator= 重载
	//arr3 = arr1;
}


//测试自定义数据类型
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(myArrary<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) 
	{
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}


void test02()
{
	//创建数组
	myArrary<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.pushBack(p1);
	pArray.pushBack(p2);
	pArray.pushBack(p3);
	pArray.pushBack(p4);
	pArray.pushBack(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;

}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}