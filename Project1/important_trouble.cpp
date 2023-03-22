#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "text.h"

using namespace std;


// 指针练习
void function_zhizhen()
{
    int num[] = {100, 200, 300, 400, 500};
    int *pnum = num;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int(*p)[3] = a;
    cout << *(*(p + 1) + 1) << endl; // *(p + 1)相当于a[2],即原二维数组的第二行，为行指针，+1为第二行第二个元素，再解引用-->5
    cout << (*++p)[1] << endl;       // ++p将行指针移至下一行，即第二行，（因为上一句语句并没有使用赋值运算符或自增运算符，故p指针的位置不变），再解引用为元素地址，[1]表示第二列的元素-->5

    cout << *pnum++ << '\t' << *pnum << endl;   // 先解引用，再让指针后移，符合加号在右侧的自增运算规则-->100 200
    cout << (*pnum)++ << '\t' << *pnum << endl; // 先解引用，再令指向的元素自增，（用括号改变了运算优先级，且上一个语句通过自增运算符改变了pnum指针的位置）-->200 201

    pnum = &num[0];
    cout << *pnum + 3 << endl;   // +3不属于自增运算符，属于算数运算符，解引用运算符高于算数运算符，先解引用，然后元素值加3,且由于没有赋值运算符，输出的值不会真实改变数组中的元素值-->103
    cout << *(pnum + 3) << endl; // 在上一语句的基础上用括号指定运算的优先级，先移动指针后解引用

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

void function_inherit(int a, int b)
{
    cout << "函数一：a的值为：" << a << "，b的值为：" << b << endl;
}
// 函数的重载要保证函数参数类型不同，返回值类型不同（编译报错）来实现来实现
// 当实参类型与形参类型不相同时，编译器会进行隐式类型转换，相容的类型会自动转换为形参的类型，不相容的类型会报错
// 含默认参数的变量要放在参数列表最后，🈯️默认参数的变量后面应全部有指定默认参数
// void function_inherit(int a, int b, int c)
// int function_inherit(int a, int b)
void function_inherit(float a, float b)
{
    cout << "函数二：a的值为：" << a << "，b的值为：" << b << endl;
}

// 含默认参数的变量要放在参数列表最后，🈯️默认参数的变量后面应全部有指定默认参数
// 当实参给出对应指定默认参数的形参实际值时，将自动覆盖默认参数，用实参替代
// 为形式参数赋值必须按照形式参数的顺序从左至右依次赋值，中间不能缺省。
void function_define_var(int a, int b, int c = -1, int d = -2)
{
    cout << "函数三：a的值为：" << a << "，b的值为：" << b << "，c的值为：" << c << "，d的值为：" << d << endl;
}
void inherit_invoke()
{
    int num1 = 10, num2 = 12, num5 = 13;
    float num3 = 10.2, num4 = 12.2;
    function_inherit(num1, num2);
    function_inherit(num3, num4);
    int num6 = 100;

    function_define_var(num1, num2, num5, num6);
    function_define_var(num1, num2, num6);
}
// 指针训练题
void printer_text()
{
    //         下标  0  1  2  3  4  5  6  7  8  9
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = nums;

    p = nums;
    cout << "*p + 6：" << *p + 6 << endl; // 先解引用，将指向的值加6，第一个元素由1变为7

    p = nums;
    cout << "p + 5：" << p + 5 << endl; // 指针向后移动5个单位，输出地址

    p = nums;
    *p += 5;
    cout << "*p += 5：" << *p << endl; // --> *p=*p+5 ,将指针向后移动五个单位，然后解引用取值，再将值赋给p所指向的位置

    p = nums;
    cout << "*(p + 6)：" << *(p + 6) << endl; // 括号优先级最高，先将指针后移6个单位，然后解引用输出值
}

// 快速排序
void quicksort(int nums[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = left + (right - left) / 2;
    int pivot_value = nums[pivot_index];
    int i = left, j = right;
    while (i <= j)
    {
        while (nums[i] < pivot_value)
            i++;
        while (nums[j] > pivot_value)
            j--;
        if (i <= j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(nums, left, j);
    quicksort(nums, i, right);
}

// 查找两个数组中的公共元素，以第一个数组顺序为准
void findpublicelement()
{
    int n1, n2, k = 0;
    int nums1[] = {1, 2, 3, 4, 2, 5, 6, 2, 6, 7, 8};
    int nums2[] = {11, 2, 15, 1, 20, 6, 2, 7};
    int pubelem[20];

    n1 = sizeof(nums1) / sizeof(int);
    n2 = sizeof(nums2) / sizeof(int);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                pubelem[k++] = nums1[i];
                break;
            }
        }
    }
    // 去除重复元素
    // 法一：O(n3)，暴力求解
    /*
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (pubelem[i] == pubelem[j])
            {
                for (int h = j; h < k; h++)
                    pubelem[h] = pubelem[h + 1];
                k--;
                j--;
            }
        }
    }
    */

    // 法二：O(n2)，以空间换时间，设置标记数组
    /*
    bool *flag = new bool[k];
    int a = 0, b = 0, count = 0;
    for (int i = 0; i < k; i++)
        flag[i] = true;
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (pubelem[j] == pubelem[i] && flag[i] != false)
                flag[i] = false;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (flag[i])
            a++;
        b++;
        pubelem[a] = pubelem[b];
    }
    k = a;
    */

    // 法三：O(nlogn)，利用快排先排序，后用双指针法去重
    quicksort(pubelem, 0, k);
    int i = 0;
    for (int j = 1; j < k; j++)
    {
        if (pubelem[i] != pubelem[j])
            i++;
        pubelem[i] = pubelem[j];
    }
    k = i + 1;

    cout << "数组一的内容为：" << endl;
    for (int i = 0; i < n1; i++)
        cout << nums1[i] << " ";
    cout << endl;
    cout << "数组二的内容为：" << endl;
    for (int i = 0; i < n2; i++)
        cout << nums2[i] << " ";
    cout << endl;

    cout << "两数组的公共元素为：" << endl;
    for (int i = 0; i < k; i++)
        cout << pubelem[i] << " ";
    cout << endl;
}

// 数组及指针的一系列问题
void arraytrouble()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, *p1, i1;
    p1 = a1;
    cout << "数组的地址为：" << a1 << endl;
    // cout << &(a + 1) << endl;  // 该句的意思是取数组第二个元素的地址的地址，由于第二个元素的地址没有实际存储在任何变量中，故报错
    // cout << a++ << endl;  // 本句的意思是将数组地址加1指向第二个元素，但数组名是一个常量指针，用于存储数组的起始地址，不能对其进行任何修改，所以对其自增会报错
    cout << &p1 << endl; // 本句是取指针变量的地址，即实际存储该指针的内存地址，由于p是一个指针，在内存中有实际的存储区域，故不会报错
    i1 = 2;
    cout << &p1[i1] << endl; // 本句的意思是取数组第三个元素的地址

    int p0[4];    // 定义一个数组p0，它有4个元素，每个元素的类型为int。
    int *p4;      // 定义一个指针p4，它指向一个int类型的变量。
    int *p2[4];   // 定义一个数组p2，它有4个元素，每个元素的类型为int指针。
    int *(p3[4]); // 定义一个数组p3，它有4个元素，每个元素的类型为int指针。
    int(*p5)[4];  // 定义一个指针p5，它指向一个有4个元素的int数组。

    int a2[4][10];
    int i = 2, j = 5;
    cout << *(&a2[0][0] + 10 * i + j) << endl; // 按照偏移量访问，从数组起始位置偏移第i行第j列之前的元素，以此访问a2[i][j]的值
    cout << *(a2 + i)[j] << endl;

    /*
    第二个输出的结果是错误的，因为它使用了数组下标运算符 [] 来访问a2[i][j]的值。
    具体来说，它先使用数组名a2获取数组的起始地址，然后 (a2 + i) 在该地址的基础上按照行数i进行偏移，即相当于获取a2[i]这一行的起始地址。
    然后它再在该地址的基础上按照列数j进行偏移，相当于获取a2[i][j]的地址。
    但是，由于[]运算级高于*,会导致从右向左执行，(a2 + i)的结果是一个行地址，而不是具体的数组元素的地址，(a2 + i)[j]会导致继续按行向下偏移，而不是在第i行内向后偏移，导致错误
    但是，这里的[]运算符与指针算术运算符有所不同，它按照数组的形状进行偏移，而不是按照线性地址进行偏移。
    由于a2是一个二维数组，它的每一行都是一个一维数组，因此*(a2 + i)的结果仍然是一个地址，而不是一个具体的值，
    所以使用[a2 + i][j]访问a2[i][j]的值是错误的。

    cout << (*(a2 + i))[j] << endl;  // 这样写就对了
    */
    cout << *(*(a2 + i) + j) << endl; // 等价于a2[i][j],*(a2+i)->a2[i]
    cout << *(a2[i] + j) << endl;     // 理由同上

    // int &num = 10; //报错
    const int &num = 10; // 正常运行不会报错
    /*
    在C++中，非常量的引用必须绑定到一个可修改的左值，即一个变量或者一个内存位置，因为引用的本质是一个变量的别名，通过引用来修改该变量的值。
        而int& num=10 的语句会导致编译器错误，因为num是一个非常量引用，而10是一个常量值，不可修改，所以 无法通过num来修改它。
    相反，const int& num=10 中的num是一个常量引用，其绑定到了一个常量值，只能用来读取这个值，而不能修改它。在这种情况下，编译器会为num分配一个内存地址，但会把这个地址标记为只读，因此不会导致错误。
    */
    char *strp = "string"; // 会提示警告，c++11版本之后不允许将string类型赋值给char*
    int i2 = 3;
    cout << *strp << endl;        // strp是一个char类型的指针，指向空间占用一个字节，直接对该指针解引用会输出所指向的一个字节空间内的内容，即s
    cout << *(strp + i2) << endl; // 指针后移三个单位解引用输出，即i
    cout << strp[i2] << endl;     // 输出数组中第4个元素，即i
    cout << strp << endl;         // 使用数组名输出整个字符串数组

    char *str1 = "copy", str2[10], *str3 = "hijack", *str4, *str5 = "abcd"; // 会提示警告，c++11版本之后不允许将string类型赋值给char*
    strcpy(str2, str1);                                                     // str2是一个字符数组，它有足够的空间容纳需要复制的字符串。
    /*
    strcpy(str3, str1); // 这个语句试图将"copy"字符串复制到str3指向的内存空间中，但str3指向的内存空间是只读的(定义时赋值为"hijack")，不能被修改，因此这个语句是错误的。
    strcpy(str4, str1); // 这个语句试图复制字符指针str1指向的字符串到未初始化的字符指针str4指向的内存空间中，但是str4没有被初始化，而且没有为它分配任何内存空间，因此这个语句是错误的。
    strcpy(str5, str1); // 这个语句试图将"copy"字符串复制到str5指向的内存空间中，但str5指向的内存空间只有四个字节的空间(即字符串"abcd"所占用的空间)，不足以存储"copy"字符串，（复制时会自动添加结束符占用一个字节空间）因此这个语句是错误的，
                        // 同时该语句尝试写入只读空间，具有跟语句二一样的错误。将str5的声明修改为：char str5[] = "abcd";这会为str5分配足够的内存空间来存储"abcd"字符串及其结尾的空字符，
    */
}
void arraytest01(int nums[])
{
    cout << sizeof(nums); // 长度固定为8字节
}
void arraytest01_invoke()
{
    int nums[10];
    cout << sizeof(nums); // 在数组名（指针）定义的函数体内，使用sizeof算数组长度，会自动读取数组整个长度的空间，
                          // 但当数组名作为实参传递出去之后，在被调用函数内只会看作普通的指针变量，用sizeof计算长度为8字节
    arraytest01(nums);
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









