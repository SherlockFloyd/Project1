#pragma warning(disable:4996)

#include<iostream>
#include<cmath>
#include<iomanip>
#include<time.h>

#include "DS.h"
#include "Knowledge.h"

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
	cout << "#################################" << endl
		<< "��ǰ����ʱ�䣺" << GetTimeNow() << endl
		<< "���ߣ�        ������" << endl
		<< "����ģʽ��    ��ͨ�û�" << endl
		<< "#################################" << endl;

	KnEntrance();  // ֪ʶ���ļ�����
	//DSEntrance();  // �㷨�ļ�����

}