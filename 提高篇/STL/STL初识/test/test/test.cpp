#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include <string>


/*
//vector 容器存放内置数据类型
void myPrint(int val)
{
	cout << val << endl;
}


void test01()
{
	//创建了一个vector容器，数组
	vector <int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();  //起始迭代器，  指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();   //返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置


	//第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}//迭代器就当指针用


	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种遍历方式，利用stl提供的标准遍历算法
	for_each(v.begin(), v.end(), myPrint);
}

int main() {

	test01();

	system("pause");

	return 0;
}
*/



/*
// Vector存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//像容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "姓名为： " << (*it).m_Name << "年龄为： " << (*it).m_Age << endl;
		//点号：用在对象 / 对象引用，访问成员
		cout << "姓名为： " << it->m_Name << "年龄为： " << it->m_Age << endl;
		//**箭头**：用在**指针**，访问指针指向对象的成员
	}
}

////放自定义类型对象指针
void test02()
{
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//像容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) 
	{
		cout << "Name:" << (*it)->m_Name << " Age:" << (*it)->m_Age << endl;
	}
}

int main() {

	//test01();
	test02();
	system("pause");

	return 0;
}
*/




//Vector容器嵌套容器
//容器中嵌套容器，我们将所有数据进行遍历输出

void test01()
{
	vector<vector<int>> v;

	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器插入到大的容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器把所有数据遍历一遍
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)			也是容器vector<int>,直接就是<>里的内容
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}
int main() {

	test01();

	system("pause");

	return 0;
}
