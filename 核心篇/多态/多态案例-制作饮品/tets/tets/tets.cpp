#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程,制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}

};


//制作咖啡
class coffee :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入牛奶!" << endl;
	}
};


class Tea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮自来水！" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "将茶叶倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞!" << endl;
	}
};

void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;//释放内存
}

void test01()
{
	//制作咖啡
	doWork(new coffee);//new开辟出来的空间返回值就是这块内存的首地址，所以就等于AbstractDrinking* abs=new coffee
	
	cout << "--------------" << endl;
	//泡茶
	doWork(new Tea);

}

int main() {

	test01();

	system("pause");

	return 0;
}