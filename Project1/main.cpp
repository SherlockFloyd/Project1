#pragma exection_character_set("GBK")
#pragma warning(disable:4996)

#include<iostream>
#include<time.h>

#include "DS.h"
#include "Knowledge.h"
#include "KnowledgeObject.h"
#include "KnowledgeInherit.h"
#include "KnowledgePolymorphism.h"
#include "TimeDown.hpp"

using namespace std;

// 获取当前系统时间
string GetTimeNow()
{
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}

int main()
{
	cout << "<==================================>" << endl
		<< "当前运行时间：" << GetTimeNow() << endl
		<< "作者：        冯少朋" << endl
		<< "运行模式：    普通用户" << endl
		<< "<==================================>" << endl;

	//KnEntrance();  // 语法知识点文件调用
	//DSEntrance();  // 算法文件调用
	//ObjectEntrance();  // 类与继承知识点文件调用
	//InheritEntrance();  // 派生与继承知识点文件调用
	PolymorphismEntrance();

}