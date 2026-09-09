#pragma once
#include <iostream>
#include<string>
using namespace std;

template <class T1, class T2>
class person
{
public:
	person(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

template <class T1, class T2>
person<T1, T2>::person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template <class T1, class T2>
void person<T1, T2>::showPerson()
{
	cout << "ÐÕÃû: " << this->m_Name << " ÄêÁä:" << this->m_Age << endl;
}
