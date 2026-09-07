#pragma once

#include<iostream>
#include<string>
using namespace std;


template<class T>
class myArrary
{
public:

	//有参构造
	myArrary(int capacity)
	{
		//cout << "有参构造" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];   //在堆区，创建N 个 T 类型元素的数组,返回数组首元素地址，赋值给指针 `pAddress`。
	}

	//拷贝构造
	myArrary(const myArrary& arr)
	{
		//cout << "拷贝构造" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		//this->pAddress=arr.pAddress    浅拷贝，两个内容指向同一个地址，会造成释放两次，重复释放

		//深拷贝
		this->pAddress = new T[arr.capacity];

		//将arr中的数据全都拷贝过来
		for (int i = 0; i < this->size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//重载= 操作符  防止浅拷贝问题
	myArrary& operator= (const myArrary& arr)    //返回当前对象引用，用来支持链式赋值：a = b = c
	{
		//cout << "operator=调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->capacity = 0;
			this->size = 0;
		}

		//深拷贝
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[this->capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void pushBack(const T& val)
	{
		//判断容量是否等于大小
		if (this->capacity == this->size)
		{
			return;
		}

		this->pAddress[this->size] = val;//在数组末尾插入数据
		this->size++;//更新数组大小
	}

	//尾删法
	void PopBack()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->size == 0)
		{
			return ;
		}
		else
		{
			this->size--;
		}
	}

	//通过下标的方式访问数组中的元素
	//重载[]
	T& operator[](int index)   //T&可以返回arr[i]本身
	{
		return this->pAddress[index];
	}

	//返回数组的容量
	int getCapacity()
	{
		return this->capacity;
	}

	//返回数组的大小
	int getSize()
	{
		return this->size;
	}

	//析构函数
	~myArrary()
	{
		if (this->pAddress != NULL)
		{
			//cout << "析构函数调用" << endl;
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}



private:
	T* pAddress;   //指针指向堆区开辟的真实数组

	int capacity;  //数组的容量

	int size;     //数组的大小
};