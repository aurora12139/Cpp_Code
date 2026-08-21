#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
继承的语法：class 子类 : 继承方式  父类
子类也称为派生类，父类也称为基类

**继承方式一共有三种：公共继承、保护继承、私有继承

*/

/*
* 分别利用普通写法和继承的写法来实现网页中的内容
//普通实现，不使用继承
//Java页面
class Java
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};
//Python页面
class Python
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};
//C++页面
class CPP
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();

}

int main() {

	test01();

	system("pause");

	return 0;
}
//可以发现，会有大量重复的代码，只有content有所不同
//继承可以减少大量重复代码

*/


/*
//继承的写法
//公共页面类
class Basepage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};

//java页面
class Java :public Basepage//: public 表示继承
{
public:
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};

//python页面
class Python :public Basepage//: public 表示继承
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

//C++页面
class CPP :public Basepage//: public 表示继承
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};

void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();

}

int main() {

	test01();

	system("pause");

	return 0;
}

**总结：**
继承的好处： == 可以减少重复的代码 ==
class A : public B;
A 类称为子类 或 派生类
B 类称为父类 或 基类
*/



//父类中private的内容子类不管哪种继承方式都无法访问
//共有继承权限不变，保护和私有继承分别变为对应的权限

//继承方式
//公共继承

class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//可访问 public权限
		m_B = 10;//可访问 protected权限
		//m_C = 12;//不可访问，因为在父类中是private的
	}
};

class son2 :protected Base1
{
	void func()
	{
		m_A = 10;//可访问 public权限,但是到子类中都是protected权限了
		m_B = 10;//可访问 protected权限,但是到子类中都是protected权限了
		//m_C = 12;//不可访问，因为在父类中是private的
	}
};

class son3 :private Base1
{
	void func()
	{
		m_A = 10;//可访问 public权限,但是到子类中都是private权限了
		m_B = 10;//可访问 protected权限,但是到子类中都是private权限了
		//m_C = 12;//不可访问，因为在父类中是private的
	}
};

class Grandson3 :public son3
{
	void func()
	{
		//m_A = 1000;
		//m_B = 1000;因为A和B在son3中都变成私有了，所以不能再被子子类访问
	}
};

void test01()
{
	son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//到了son1中m_B是个保护权限，类外访问不到

	son2 s2;
	//s2.m_A = 100;//因为son2中A和B都是保护权限，类外不能访问
	//s2.m_B=100;// 但是到子类中都是protected权限了

	son3 s3;
	//s3.m_A = 100;//因为son2中A和B都是私有权限，类外不能访问
	//s3.m_B=100;// 但是到子类中都是private权限了

}