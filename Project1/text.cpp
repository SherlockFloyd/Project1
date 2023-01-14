#pragma warning(disable:4996)  // 忽略警告提醒

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
    cout << "修改前：" << a << endl;

    a = 3;
    cout << "修改后：" << a << endl;
}

void TextEntrance()
{
    text();
}