#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "text.h"

using namespace std;


void text()
{
    int a = 2;
    const int* pa = &a;
    cout << "�޸�ǰ��" << a << endl;

    a = 3;
    cout << "�޸ĺ�" << a << endl;
}

void TextEntrance()
{
    text();
}