#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<cstring>
#include "KnowledgeConstructDataType.h"

using namespace std;

// 枚举类型（基本数据类型）
/*
变量取值被限定在有限的范围内
定义格式：
enum <枚举类型名>
{
	标识符[=整型常数],
	标识符[=整型常数],
	...
	标识符[=整型常数],
} 枚举变量;

默认情况下，第一个变量赋值为0，依次递增
指定成员值之后的变量按照依次加1的原则取值。

仅允许赋值和关系运算
允许枚举常量赋值给枚举变量、两个相同类型的变量之间赋值，
	不能直接将常量赋值给枚举变量、两个不同类型的枚举变量之间不能互相赋值。
*/

// 结构类型
/*
由若干个不同类型但相关的变量构成
结构定义：
struct 结构名
{
	成员表
};
*/

// 共用体（联合）
/*
表示几个不同类型的变量共用一段同一起始地址的存储单元
	即将相同的数据部分当作不同的数据类型来处理，或用于不同变量名引用相同的数据部分
	但同一时刻只能有一个变量起作用
联合定义：
unoin 共用体名
{
	类型名 成员名1;
	类型名 成员名2;
	...
	类型名 成员名n;
}
共用体的定义只是描述了该共用体的“模式”或“形态”，不能为共用体分配存储空间，只有给出共用体变量后，编译程序才会为其分配存储空间
分配的存储空间是一个足以容纳其中最大成员的存储空间
不能对其进行初始化和赋值
*/

// 自定义数据类型
/*
typedef existing_type new_type_name;
如果在一个程序中反复使用一种数据类型，而在以后的版本中有可能改变该数据类型，typedef就很有用。
*/

// 实例 职工成绩转换
#define N1 1
struct person
{
	long num;
	char name[20];
	int age;
	union
	{
		float exam;
		char grade;
	}score;
}p[N1];
void Function01()
{
	int n = 0;
	for (int i = 0; i < N1; i++)
	{
		cout << "请输入职员信息（编号、姓名、年龄）：" << endl;
		cin >> p[i].num >> p[i].name >> p[i].age;
		if (p[i].age < 25)
		{
			cout << "请输入考试分数：" << endl;
			cin >> p[i].score.exam;
		}
		else if (p[i].age >= 25)
		{
			cout << "请输入职工等级：" << endl;
			cin >> p[i].score.grade;
		}
		if (p[i].score.exam >= 60 || p[i].score.grade != 'D')
			n++;
	}
	for (int i = 0; i < N1; i++)
	{
		if (p[i].age < 25)
			cout << p[i].num << '\t' << p[i].name << '\t' << p[i].age << '\t' << p[i].score.exam << endl;
		else if (p[i].age >= 25)
			cout << p[i].num << '\t' << p[i].name << '\t' << p[i].age << '\t' << p[i].score.grade << endl;
	}
	cout << "合格人数一共为" << n << "人。" << endl;
}


void ConstructDataType()
{
	Function01();
}