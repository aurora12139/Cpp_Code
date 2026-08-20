#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
### 运算符重载

运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
#### 4.5.1 加号运算符重载
作用：实现两个自定义数据类型相加的运算









*/



/*
//加号运算符重载
class person
{
public:

	////1.成员函数重载+号
	//person operator+(person& p)
	//{
	//	person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}


	int m_A;
	int m_B;
};

//2.全局函数重载+号
person operator+(person& p1,person& p2)
{
	person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;

}

//函数重载的版本
person operator+(person& p1, int num)
{
	person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}


void test01()
{
	person p1;
	p1.m_A = 10;
	p1.m_B = 20;

	person p2;
	p2.m_A = 10;
	p2.m_B = 20;

	//成员函数重载 + 号调用本质
	//person p3 = p1.operator+(p2);

	//全局函数重载的本质调用
	person p3 = operator+(p1, p2);

	//上面两种的简化形式
	//person p3 = p1 + p2;

	//运算符重载 可以发生函数重载 
	person p4 = p1 + 100;


	cout << "p3.m_A= " << p3.m_A << endl;
	cout << "p3.m_B= " << p3.m_B << endl;
	cout << "p4.m_A= " << p4.m_A << endl;
	cout << "p4.m_B= " << p4.m_B << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
//总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
//总结2：不要滥用运算符重载
*/




/*
//左移运算符重载

class person
{
	friend ostream& operator<<(ostream& cout, person& p);

public:
	person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}

private:

	////利用成员函数重载左移运算符
	//void operator<<(cout)  //这样就是p<<cout了
	//	//所以不会利用成员函数重载
	//{

	//}

	int m_A;
	int m_B;
};

//只能用全局函数重载左移运算符
ostream& operator<<(ostream &cout, person &p) //本质是operator<<(cout,p),简化为cout<<p，括号里的就是<<的两个操作数
//必须返回的是ostream&， 因为ostream不允许拷贝，所以只能引用
{
	cout << "m_A= " << p.m_A << " m_B= " << p.m_B;
	return cout;
}

void test01()
{
	person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p <<" hello world " << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}
*/




/*
//递增运算符重载  ++
//作用： 通过重载递增运算符，实现自己的整型数据

//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_num=0;
	}

//重载前置++运算符
	MyInteger& operator++()//返回引用能避免拷贝,可以让他对同一个对象一直操作
	{
		//先进行++运算
		this->m_num++;
		//再将自身返回
		return *this;
	}

//重载后置++运算符
	MyInteger operator++(int)	//int代表占位参数，可以用于区分前置和后置递增
		//后置递增必须返回值，因为temp是临时对象
	{
		//先    记录当时结果
		MyInteger temp = *this;
		//后		递增
		m_num++;
		//最后将记录结果返回
		return temp;
	}


private:
	int m_num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_num;
	return cout;
}

void test01()
{
	MyInteger myint;

	cout << ++myint << endl;//1
	cout << myint++ << endl;//1
	cout << myint << endl;//2


}

int main() {

	test01();
	//test02();

	system("pause");

	return 0;
}

*/




/*
//赋值运算符重载
class person
{
public:
	person(int age)
	{
		m_age = new int(age);//在堆区创建
	}

	~person()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//重载赋值运算符
	person& operator=(person& p)
	{
		//编译器提供的浅拷贝
		//m_age=p.m_age,  就是指针复制一份过去


		//应该先判断是否又属性在堆区，如果有先是放干净，然后再深拷贝
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}

		//深拷贝，在堆区新创建一份内存
		m_age = new int(*p.m_age);//开辟一个int大小的内存，把*p.m_age放到这个内存里

		return *this;//返回对象本身
	}


	int *m_age;
};

void test01()
{
	person p1(18);

	person p2(20);

	person p3(30);

	p3 = p2 = p1;//赋值操作,如果直接这样赋值，会导致在析构释放队去内存的时候崩溃，编译器提供的赋值是浅拷贝，从而释放的时候这一个堆区内存会被重复释放
	//解决方案：利用深拷贝，解决浅拷贝带来的问题。
	cout << "p1's age= " << *p1.m_age << endl;
	cout << "p2's age= " << *p2.m_age << endl;
	cout << "p3's age= " << *p3.m_age << endl;


}



int main() {

	test01();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a;
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	//cout << "c = " << c << endl;

	system("pause");

	return 0;
}

*/


/*
//关系运算符重载
//作用：重载关系运算符，可以让两个自定义类型对象进行对比操作

class person
{
public:
	person(string name, int age)
	{
		m_name = name;
		m_age = age;

	}

	//重载==
	bool operator==(person& p)
	{
		if (this->m_age == p.m_age && this->m_name == p.m_name)
		{
			return true;
		}
		else
			return false;
	}

	//重载!=
	bool operator!=(person& p)
	{
		if (this->m_age != p.m_age || this->m_name != p.m_name)
		{
			return true;
		}
		else
			return false;
	}


	string m_name;
	int m_age;
};


void test01()
{
	person p1("tom", 18);
	person p2("mike", 18);

	if (p1 == p2)
	{
		cout << "p1和p2相等" << endl;
	}
	else
		cout << "p1和p2不相等" << endl;

	if (p1 != p2)
	{
		cout << "p1和p2不相等" << endl;
	}
	else
	{
		cout << "p1和p2相等" << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}

*/


//函数调用运算符重载
//函数调用运算符()  也可以重载
//由于重载后使用的方式非常像函数的调用，因此称为仿函数
//仿函数没有固定写法，非常灵活

class MyPrint
{
public:

	//重载函数调用运算符()
	void operator()(string test)
	{
		cout << test << endl;
	}

};

void myPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myPrint;

	myPrint("hello world");//使用的是重载后的()
	myPrint02("hello world");//普通函数调用

}


//加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(10, 20);
	cout << "ret= " << ret << endl;


	//匿名函数对象
	cout << MyAdd()(10, 20) << endl;//匿名函数对象MyAdd()用完就被释放了
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}
