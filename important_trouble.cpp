#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "text.h"

using namespace std;


// 指针问题
void function_zhizhen()
{
    int num[] = {100, 200, 300, 400, 500};
    int *pnum = num;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int(*p)[3] = a;
    cout << *(*(p + 1) + 1) << endl; // *(p + 1)相当于a[2],即原二维数组的第二行，为行指针，+1为第二行第二个元素，再解引用-->5
    cout << (*++p)[1] << endl;       // ++p将行指针移至下一行，即第三行，再解引用为元素地址，[1]表示第二列的元素-->5

    cout << *pnum++ << '\t' << *pnum << endl;   // 先解引用，再让指针后移，符合加号在右侧的自增运算规则
    cout << (*pnum)++ << '\t' << *pnum << endl; // 先解引用，再令指向的元素自增

    /*
    解引用与自增运算符优先级相同，遵循右结合，即运算顺序从右至左，且遵循自增运算符在变量两侧先使用后自增或先自增后使用的规则，不加括号都是对指针的自增。
    */
}
void jieyinyonglianxi()
{
    cout << "#####\t第一题\t#####" << endl;
    int y = 25, i = 0, j, a[8], *p_a;
    p_a = a; // 指向数组起始位置
    do
    {
        *p_a = y % 2;           // 解引用，指针指向元素赋值
        cout << *p_a++ << endl; // 先使用后自增，右结合，先解引用后指向下一个元素
        i++;
        y /= 2;
    } while (y >= 1);
    for (int j = 1; j <= i; j++)
        cout << *--p_a; // 先自增后使用，右结合，先指向前一个元素后解引用
    cout << endl;

    cout << "#####\t第二题\t#####" << endl;
    int anum = 25, *x;
    x = &anum;
    cout << ++*x << endl; // 先自增后使用，右结合，先解引用，指向的元素+1  （该例题是对指针所指向的元素自增而不是指针指向下一个地址，原因在于运算方向是右结合，先进行了解引用，后进行自增运算）
}

void voidptr()
{
    int num = 100;
    float fnum = 100.8;
    double dnum = 10.18;
    char c = 'A';
    void *vptr;

    vptr = &num;
    cout << "数字num的地址为：" << vptr << endl;
    cout << "数字num的值为：" << *(int *)vptr << endl;
    cout << "数字num的大小为：" << sizeof(*(int *)vptr) << "B" << endl
         << endl;

    vptr = &fnum;
    cout << "数字fnum的地址为：" << vptr << endl;
    cout << "数字fnum的值为：" << *(float *)vptr << endl;
    cout << "数字fnum的大小为：" << sizeof(*(float *)vptr) << "B" << endl
         << endl;

    vptr = &dnum;
    cout << "数字dnum的地址为：" << vptr << endl;
    cout << "数字dnum的值为：" << *(double *)vptr << endl;
    cout << "数字fnum的大小为：" << sizeof(*(double *)vptr) << "B" << endl
         << endl;

    vptr = &c;
    cout << "字符c的地址为：" << vptr << endl;
    cout << "字符c的值为：" << *(char *)vptr << endl;
    cout << "字符c的大小为：" << sizeof(*(char *)vptr) << "B" << endl
         << endl;

    /*
    不能用void声明变量，只能用void*声明空类型指针。
    不能对void*指针直接解引用，需要强制转换成其他类型 --*(leixing* )vptr。
    把其他类型的指针赋值给void*指针不需要转换。
    把void*指针赋值给其他类型的指针需要强制转换
    */
}

void function_fenzi()
{
    int a = 1, b = 3, c = 5, d = 4, x;
    if (a < b)
        if (c < d)
            x = 1;
        else if (a < c)
            if (b < d)
                x = 2;
            else
                x = 3;
        else
            x = 6;
    else
        x = 7;
    cout << "x=" << x << endl;
    /*
    else与if匹配，从上到下，else选择与其最近且没有配对的if配对
    */
}
void function_invoke_shuzhu(char nums[100])
{
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    cout << nums;
    cout << endl;
}
void function_shuzhu()
{
    // int nums[10] = {0};
    // for (int i = 0; i < 10; i++)
    // {
    //     nums[i] = i;
    // }
    char str[10] = "abcdefghi";
    // cin >> str;
    function_invoke_shuzhu(str);
    /*
    数组作为函数参数传递时，形参可不说明数组大小，形参中一维数组的长度无实际作用，实际大小为实参大小。形参中二维数组必须指明列大小。
    */
}

void f_struct()
{
    map<bool, string> Sex = {
        {1, "男"},
        {0, "女"},
    };

    // 使用typedef定义结构体
    typedef struct student1
    {
        int id;
        char name[20];
        bool sex;
    } stddd, *pstd;

    student1 std1, std2;
    stddd std10;
    pstd ps; // 指向该结构体的指针

    std1.id = 101;
    strcpy(std1.name, "fsp");
    std1.sex = 1;

    cout << std1.id << '\t' << std1.name << '\t' << Sex[std1.sex] << endl;

    ps = &std1;
    cout << ps->id << '\t' << ps->name << '\t' << Sex[ps->sex] << endl;

    // 不使用typedef定义结构体
    struct student2
    {
        int id;
        char name[20];
        bool sex;
    } std3, *pstd2;

    student2 std4;

    std3.id = 102;
    strcpy(std3.name, "mhf");
    std1.sex = 0;

    cout << std3.id << '\t' << std3.name << '\t' << Sex[std3.sex] << endl;

    pstd2 = &std3;
    cout << pstd2->id << '\t' << pstd2->name << '\t' << Sex[pstd2->sex] << endl;

    /*
    使用typedef和不使用typedef定义结构体，共同点是struct后面的均为结构体类型名，可以用该名称定义结构体变量
    不同点：
        使用typedef定义的结构体大括号后面的仍然为结构体类型名，相当于结构体类型的别名，可以使用该类型名称定义结构体变量和结构体指针变量
        不使用tyoedef定义的结构体大括号后面的为该结构体类型的变量，只能使用，不能够通过其定义新的变量。
    */
}


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
    // function_zhizhen();
    // function_fenzi();
    // function_shuzhu();
    // voidptr();
    // jieyinyonglianxi();
    f_struct();
    // text();
}









