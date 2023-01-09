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

// ��ȡ��ǰϵͳʱ��
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
		<< "��ǰ����ʱ�䣺" << GetTimeNow() << endl
		<< "���ߣ�        ������" << endl
		<< "����ģʽ��    ��ͨ�û�" << endl
		<< "<==================================>" << endl;

	//KnEntrance();  // �﷨֪ʶ���ļ�����
	//DSEntrance();  // �㷨�ļ�����
	//ObjectEntrance();  // ����̳�֪ʶ���ļ�����
	//InheritEntrance();  // ������̳�֪ʶ���ļ�����
	PolymorphismEntrance();

}