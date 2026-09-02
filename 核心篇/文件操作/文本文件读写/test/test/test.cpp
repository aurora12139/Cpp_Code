#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include<fstream> //头文件包含
#include<string>

/*
程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
通过**文件可以将数据持久化**

C++中对文件操作需要包含头文件 fstream

文件类型分为两种：

1. **文本文件**     -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们


操作文件的三大类:
1. ofstream： 写操作,**o** = Output 输出，输出就是往文件**写**东西
2. ifstream： 读操作，**i** = Input 输入，文件内容输入到程序
3. fstream ： 读写操作



#### 5.1.1写文件

   写文件步骤如下：

1. 包含头文件

   #include <fstream>

2. 创建流对象

   ofstream ofs;

3. 打开文件
   ofs.open("文件路径",打开方式);
打开方式：
ios::in  为读文件而打开文件
ios::out 为写文件而打开文件
ios::binary	二进制方式
**注意：** 文件打开方式可以配合使用，利用 | 操作符
**例如：**用二进制方式写文件 ios::binary |  ios:: out


4. 写数据

   ofs << "写入的数据";

5. 关闭文件

   ofs.close();



*/


/*
//写文件
void test01()
{
	//1.包含头文件 fstream

	//2.创建流对象
	ofstream ofs;
	
	//3.打开文件
	ofs.open("text.txt", ios::out);//未指定路径，则会创建在与当前项目同一文件夹

	//4.写数据
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//5.关闭文件
	ofs.close();
}

int main() {

	test01();

	system("pause");

	return 0;
}
*/

/*
总结：
文件操作必须包含头文件 fstream
读文件可以利用 ofstream  ，或者fstream类
打开文件时候需要指定操作文件的路径，以及打开方式
利用<<可以向文件中写数据
操作完毕，要关闭文件
*/


//读文件
/*
读文件步骤如下：
1.包含头文件
#include <fstream>

2.创建流对象
ifstream ifs;

3.打开文件并判断文件是否打开成功
ifs.open("文件路径",打开方式);

4.读数据
四种方式读取

5.关闭文件
ifs.close();

*/

void test01()
{
	//1.包含头文件

	//2.创建流对象
	ifstream ifs;

	//3.打开文件并判断文件是否打开成功
	ifs.open("text.txt", ios::in);

	if (!ifs.is_open())   //ifs.is_open布尔类型可以直接判断
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读数据(四种方式)
	//第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)         //`>>` 叫**流提取运算符**，`ifs >> buf`：从文件读取一串字符，存到`buf`数组。
	//{
	//	cout << buf << endl;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))//一行一行的读
	//{
	//	cout << buf << endl;
	//}

	//第三种，推荐buf没有指定上限
	string buf;
	while (getline(ifs, buf))
	{
	     cout << buf << endl;
	}

	//第四种,一个字符一个字符的读,不推荐，速度慢
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}


	//5.关闭文件
	ifs.close();
};

int main() {

	test01();

	system("pause");

	return 0;
}