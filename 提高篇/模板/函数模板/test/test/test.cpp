#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
### 函数模板
* C++另一种编程思想称为 ==泛型编程== ，主要利用的技术就是模板
* C++提供两种模板机制:**函数模板**和**类模板**

#### 1.2.1 函数模板语法
函数模板作用：
建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表。


**语法：**
```C++
template<typename T>
函数声明或定义
```
**解释：**
template  ---  声明创建模板
typename  --- 表明其后面的符号是一种数据类型，可以用class代替

T    ---   通用的数据类型，名称可以替换，通常为大写字母
总结：
1.函数模板利用关键字 template
2.使用函数模板有两种方式：自动类型推导、显示指定类型
3.模板的目的是为了提高复用性，将类型参数化


#### 函数模板注意事项
注意事项：
* 自动类型推导，必须推导出一致的数据类型T,才可以使用
* 模板必须要确定出T的数据类型，才可以使用






*/



/*
//两个整型交换函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}


//函数模板
template<typename T>
//声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个通用的数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}




void test01()
{
	int a = 10;
	int b = 20;

	double c = 10.1;
	double d = 20.2;

	//swapInt(a, b);
	//swapDouble(c, d);
	
	//利用模板实现交换
	//1、自动类型推导
	mySwap(a, b);
	mySwap(c, d);

	//2、显示指定类型
	mySwap<int>(a, b);   //<int>指定T的数据类型


	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
*/


//函数模板案例

/*
案例描述：
* 利用函数模板封装一个排序的函数，可以对** 不同数据类型数组** 进行排序
* 排序规则从大到小，排序算法为** 选择排序**
* 分别利用** char数组** 和** int数组** 进行测试
*/

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//最大数的下标
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}//找到最大数
		if (max != i)//如果最大数的下标不是i，交换两者
		{
			mySwap(arr[max],arr[i]);
		}
	}
}

//提供打印数组模板
template<typename T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	//测试char数组
	char charArr[] = "badcfljggke";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);


}

void test02()
{
	//测试int数组
	int intArr[] = {8,9,7,6,334,6,2,2,1};
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);


}

int main() {

	test01();
	test02();
	system("pause");

	return 0;
}