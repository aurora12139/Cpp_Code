#define _CRT_SECURE_NO_WARNINGS

/*
C++框架

#include <iostream>
using namespace std;
int main()
{

	cout << "hello world" << endl;
	//"<< endl"表示换行符\n
	system("pause");
	return 0;
}


C++输出字符串
#include <string>
string str="hello world"


布尔类型 bool
布尔数据类型代表真或者假的值
bool类型只有两个值：
true ---真（即本质为	1）
false ---假（即本质为0）
bool类型占1个字节大小
例：
bool flag = true;
cout << flag << endl;
bool flagtag = false;
cout << flagtag << endl;
cout << "bool类型占的空间为：" << sizeof(bool) << endl;


数据的输入
从键盘获取数据，等效scanf
语法：cin>>变量；










*/

//#include <iostream>
//using namespace std;
//
//int main()
//{
//
//	cout << "hello world" << endl;
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << a + b << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>
int main()
{
	//int a = sizeof(short);
	//cout << a << endl;
	//int a = 19;
	//long long a = 10;
	//cout << "a占用的内存大小为：" << sizeof(a) << endl;

	//float f1 = 3.14f;
	//cout << "f1=" << f1 << endl;

	//double f2 = 3.14;
	//cout << "f2=" << f2 << endl;
	//cout << "f1 f2占用的内存大小分别为：" << sizeof(f1) << " " << sizeof(f2) << endl;

	//char a = 'A';
	////cout << a << endl;
	//cout << "a占用的内存大小为: " << sizeof(a) << endl;
	//cout << (int)a << endl;
	////a--97
	////A--65

	//string str = "hello world";
	//cout << str << endl;

	//bool flag = true;
	//cout << flag << endl;
	//bool flagtag = false;
	//cout << flagtag << endl;
	//cout << "bool类型占的空间为：" << sizeof(bool) << endl;

	//int a = 0;
	//cout << "请输入a的值：" << endl;
	//cin >> a;
	//cout << "a的值为：" << a << endl;

	//float b = 0;
	//cout << "请输入浮点数b的值：" << endl;
	//cin >> b;
	//cout << "b的值为：" << b << endl;

	//char c = 'a';
	//cout << "请输入字符型变量c的值：" << endl;
	//cin >> c;
	//cout << "c的值为：" << c << endl;

	//string str = "hello";
	//cout << "请输入字符串str的值：" << endl;
	//cin >> str;
	//cout << "字符串str的值为：" << str << endl;

	//bool flag = false;
	//cout << "请输入布尔类型flag的值：" << endl;
	//cin >> flag;
	////布尔类型只要输入的是非零的值都为1；
	//cout << "flag的值为：" << flag << endl;

	//int a = 10;
	//float b = 3.0;
	//int c = 20;
	//cout << a + b << endl;
	//cout << a - b << endl;
	//cout << a * b << endl;
	//cout << a / b << endl;//至少两边要有一个是小数才能结果为小数
	//cout << a % b << endl;

	//cout << a++ << endl;//打印10
	//cout << ++a << endl;//打印12
	//cout << (a += 3) << endl;//打印15
	////<<的优先级很高，所以后面的表达式要用括号括起来先计算
	//cout << (a -= 5) << endl;//10
	//cout << (a *= 2) << endl;//20
	//cout << (a /= 5) << endl;//4

	//cout << (a == c) << endl;
	//cout << (a < c) << endl;
	//cout << (a <= c) << endl;
	//cout << (a >= c) << endl;
	//cout << (a > c) << endl;


	//cout << !a << endl;
	//cout << (a && c) << endl;
	//c = 0;
	//cout << (a || c) << endl;
	//cout << (a && c) << endl;


	//if多重判断
	//double score = 0.0;
	//cout << "请输入您的分数：" << endl;
	//while (cin >> score)
	//{
	//	if (score > 750||score < 0)
	//	{
	//		cout << "输入错误，请重新输入" << endl;
	//		continue;
	//	}
	//	if (score > 600)
	//	{
	//		cout << "考上了一本大学！" << endl;
	//		if (score > 700)
	//			cout << "考上了北京大学！" << endl;
	//		else if (score > 650)
	//			cout << "考上了清华大学！" << endl;
	//		else
	//			cout << "考上了人民大学！" << endl;

	//	}
	//	else if (score > 500)
	//	{
	//		cout << "考上了二本大学！" << endl;

	//	}
	//	else if (score > 400)
	//	{
	//		cout << "考上了三本大学！" << endl;

	//	}
	//	else
	//	{
	//		cout << "没考上大学！" << endl;
	//	}
	//}



	//输入三个数比大小
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "请输入三个数a、b、c：" << endl;
	cin >> a >> b >> c;

	int max = a;
	if (a >= b)
	{
		if (a >= c)
		{
			max = a;
		}
		else
		{
			max = c;
		}
	}
	else
		max = b;
	cout << max << endl;
	system("pause");
	return 0;
}