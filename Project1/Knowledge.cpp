#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>

#include "Knowledge.h"

using namespace std;

// 变量作用域及生存期
/*###########################################################################################################*/
/*
全局变量：默认为外部的，即在整个程序的多个文件中均可使用，默认省略extern标识符
静态全局变量：只声明一次，仅能在本文件中使用
静态局部变量：只声明一次，具有局部作用域和全局（本文件）生命期
extern使用时必须保证
	1、使用#include "External_file.cpp"引入外部文件
	2、使用前的声明时所使用的变量或函数需要与定义时所使用的名称和类型完全一致
*/
void DefineVariables()
{
	register int n = 0;  // <存储类型><数据类型><变量名>  auto\register\static\extern
}

void PrevarVariables()
{
	extern int a, b;  // 利用extern在全局变量定义前对其声明调用
	cout << "全局变量定义前调用结果：" << a << "\t" << b << endl;
}

int a = 3, b = 5;  // 全局变量定义点

void Variable()
{
	int a = 8;  // 同名变量局部优先
	cout <<"局部变量比较结果为：" << (a < b ? a : b) << endl;  // a为局部变量
	cout <<"全局变量比较结果为：" << (::a < b ? a : b) << endl;  // 使用"::"访问全局变量，其中输出的a为局部变量a
}

void StaticLocalVariables()
{
	static int n = 0;  // 静态局部变量，离开该函数后变量值不变
	n++;
	cout << "该函数调用次数为：" << n << endl;
	while (n < 4)
		StaticLocalVariables();
}

// 汉诺塔问题
/*###########################################################################################################*/
void move(int n, char from, char to)
{
	cout << n << " 号盘从 " << from << " 移动到 " << to << endl;
}

void hanoi(int n, int p1, int p2, int p3)
{
	void move(int, char, char);  // 函数声明
	if (n == 1)
		move(n, p1, p3);
	else {
		hanoi(n - 1, p1, p3, p2);  // 将n-1个圆盘从p1借助p3移动到p2
		move(n, p1, p3);  // 将n号圆盘从p1移动到p3
		hanoi(n - 1, p2, p1, p3);  // 将n-1个圆盘从p2借助p1移动到p3
	}
}

void HanoiInput()
{
	int n;
	cout << "请输入圆盘总数：\n";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
}

// 求解斐波那契数列及递归改进(前两项为1，后面各项等于其前两项之和)
/*###########################################################################################################*/
double Fibonacci(int n)  // 递归方法
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
// 递归函数改进
double NewFibonacci(double f1, double f2, int n)  // 前第二项、前第一项、当前项数
{
	return n <= 1 ? f2 : NewFibonacci(f1 + f2, f1, n - 1);
}
/*尾递归，递归调用在函数末尾，每次递归均保持上次的计算状态，避免冗余运算*/
void FibonacciInput()
{
	int n, flag = 1;
	cout << "请输入待求解的斐波那契数列项数：" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		//cout << Fibonacci(i) << '\t';
		cout << NewFibonacci(1,1,i) << '\t';
		if (i == (flag * (flag + 1) / 2)) {
			cout << endl;
			flag++;
		}
	}
}

// 二分查找递归实现
/*###########################################################################################################*/
int Binary_Search(int A[], int front, int rear, int k)
{
	int num,mid;
	int n = rear - front + 1;
	if (n == 0)
		return -1;
	else {
		mid = (front + rear) / 2;
		if (k == A[mid])
			return mid;
		else {
			if (k < A[mid]) {
				num = Binary_Search(A, front, mid - 1, k);
				return num;
			}
			else {
				num = Binary_Search(A, mid+1, rear, k);
				return num;
			}
		}
	}
}
void Binary_Search_Input()
{
	int key, result, n = 20;
	int A[] = { 2,3,12,15,16,19,21,23,24,25,29,36,42,50,61,90,92,94,95,99 };
	while (true) {
		cout << "请输入您想要查找的数据（0-100）：" << endl;
		cin >> key;
		result = Binary_Search(A, 0, n - 1, key);
		if (result == -1)
			cout << "未在数组中查找到该元素！" << endl;
		else
			cout << "查找到元素 " << key << " 位于数组中第 " << result + 1 << " 位。" << endl;
	}
}

// 利用重载和函数调用实现多功能排序函数
/*###########################################################################################################*/
// 自定义函数声明
const int COL = 20;
void sort(double&, double&);
void sort(double&, double&, double&);
void sort(double&, double&, double&, double&);
void sort(double a[], int n);
void sort(char s1[], char s2[]);
void sort(char a[][COL], int n);
int mystremp(char s1[], char s2[]);
// 以下重载函数逐级调用，实现复杂类型的排序
void MultifunctionSort()
{
	// 模拟用例
	double a = 22.8, b = 115, c = 33.2, d = -10.9;
	double v[] = { 18,9.3,3.5,5.6,10,8,9,10.5,29,20.9,8.6,-5.4,-3,-1,19 };
	char s[][COL] = {
		"Chinese","President","Xi","Jinping","has",
		"urged","all","the","citizens","to","plant","trees"
		"and","make","the","land","more","beautiful" };
	int vn = 15, sn = 17;  // 一维和二维数组长度

	cout << "默认用例排序结果如下：" << endl;
	sort(c, d);  // 两数比较
	cout << c << " " << d << endl;
	sort(b, c, d);  // 三数比较
	cout << b << " " << c << " " << d << endl;
	sort(a, b, c, d);  // 四数比较
	cout << a << " " << b << " " << c << " " << d << endl;
	sort(v, vn);  // 一维数组元素比较
	for (int i = 0; i < vn; i++)
	{
		if (i == 0)
			cout << v[i];
		cout << " " << v[i];
	}
	cout << endl;
	sort(s, sn);  // 二维数组元素比较
	for (int i = 0; i < sn; i++)
	{
		if (i == 0)
			cout << s[i];
		else
			cout << " " << s[i];
		cout << " ";
	}
	cout << endl;
}
void sort(double& a, double& b)
{  
	// 二数排序
	if (a > b)
	{
		double tmp = a;
		a = b;
		b = tmp;
	}
}
void sort(double& a, double& b, double& c)
{  
	// 调用二数排序函数执行三数排序
	sort(a, b);
	sort(a, c);
	sort(b, c);
}
void sort(double& a, double& b, double& c, double& d)
{
	// 调用三数排序函数执行四数排序
	sort(a, b, c);
	sort(a, d);
	sort(b, c, d);
}
void sort(double a[], int n)
{
	// 调用二数排序函数执行数组排序
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			sort(a[j], a[j + 1]);
}
void sort(char s1[], char s2[])
{
	// 调用二字符串比较函数执行二字符串排序
	if (mystremp(s1, s2) > 0){
		char tmp[20];
		strcpy(tmp, s1);
		strcpy(s1, s2);
		strcpy(s2, tmp);
	}
}
int mystremp(char s1[], char s2[])
{
	// 二字符串比较
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return s1[i] - s2[i];
}
void sort(char a[][COL], int n)
{  
	// 调用二串排序函数执行串数组（二维字数组）排序
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			sort(a[j], a[j + 1]);
}


/*
引用与指针：
引用：<类型>& <变量名>
	引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

引用很容易与指针混淆，它们之间有三个主要的不同：
	1、不存在空引用。引用必须连接到一块合法的内存。
	2、一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
	3、引用必须在创建时被初始化。指针可以在任何时间被初始化。
*/

// 指针传值（&-取地址符号、*-指针变量,指针的使用必须先初始化）
/*###########################################################################################################*/

/*
1）常量指针
语法：const 数据类型 *变量名;
不能通过解引用的方法修改内存地址中的值（用原始的变量名是可以修改的）。
注意：
	指向的变量（对象）可以改变（之前是指向变量a的，后来可以改为指向变量b）。
	一般用于修饰函数的形参，表示不希望在函数里修改内存地址中的值。
	如果用于形参，虽然指向的对象可以改变，但这么做没有任何意义。
	如果形参的值不需要改变，建议加上const修饰，程序可读性更好。
2）指针常量
语法：数据类型 * const 变量名;
指向的变量（对象）不可改变。
注意：
	在定义的同时必须初始化，否则没有意义。
	可以通过解引用的方法修改内存地址中的值。
	C++编译器把指针常量做了一些特别的处理，改头换面之后，有一个新的名字，叫引用。
3）常指针常量
语法：const 数据类型 * const 变量名;
指向的变量（对象）不可改变，不能通过解引用的方法修改内存地址中的值。
常引用。

常量指针：指针指向可以改，指针指向的值不可以更改。
指针常量：指针指向不可以改，指针指向的值可以更改。
常指针常量：指针指向不可以改，指针指向的值不可以更改。

指针的数组表示
在C++内部，用指针来处理数组。
C++编译器把   数组名[下标]  解释为  *(数组首地址+下标)
C++编译器把   地址[下标]  解释为  *(地址+下标)



void关键字
在C++中，void表示为无类型，主要有三个用途：
1）函数的返回值用void，表示函数没有返回值。
void func(int a,int b)
{
    // 函数体代码。
    return;
}
2）函数的参数填void，表示函数不需要参数（或者让参数列表空着）。
int func(void)
{
    // 函数体代码。
    return 0;
}
3）的形参用void *，表示接受任意数据类型的指针。
注意：
	不能用void声明变量，它不能代表一个真实的变量，但是，用void *可以。
	不能对void *指针直接解引用（需要转换成其它类型的指针）。
	把其它类型的指针赋值给void*指针不需要转换。
	把void *指针赋值给把其它类型的指针需要转换。

*/
// 指针练习
void function_zhizhen()
{
    int num[] = {100, 200, 300, 400, 500};
    int *pnum = num;
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int(*p)[3] = a;
    cout << *(*(p + 1) + 1) << endl; // *(p + 1)相当于a[2],即原二维数组的第二行，为行指针，+1为第二行第二个元素，再解引用-->5
    cout << (*++p)[1] << endl;       // ++p将行指针移至下一行，即第三行，再解引用为元素地址，[1]表示第二列的元素-->5

    cout << *pnum++ << '\t' << *pnum << endl;   // 先解引用，再让指针后移
    cout << (*pnum)++ << '\t' << *pnum << endl; // 先解引用，再令指向的元素自增
}

// ！注意 ！其中有重要知识点
void swap(int* xp,int* yp)  // 指针变量作为形参，接收地址类型的实参
{
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;

	/*void Swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}*/  
	// 写法正确，引用类型写法，形参取实际地址进行修改

	/*int* temp;
	temp = xp;
	xp = yp;
	yp = temp;*/  
	/*错误写法，temp、xp、yp都为指针类型的swap函数局部变量，存储在函数栈区中，交换其值不改变外部变量的值，该局部变量随着函数调用结束一同被销毁
	而上面直接*xp等价于外部变量x，*yp等价于外部变量y，利用temp这一局部变量交换外部变量，可更改实际的值*/
}
void swap_Input()
{
	int x = 100, y = 200;
	cout << "before swap:" << "x= " << x << " and y= " << y << endl;
	swap(&x, &y);  // 取变量地址作为实参传递（引用传递）
	cout << "after swap:" << "x= " << x << " and y= " << y << endl;
}

// 利用指针带回函数中的多个值
/*###########################################################################################################*/
double faver(int s[], int n, int* max, int* min)
{
	double sum = s[0];
	*max = *min = s[0];
	for (int i = 1; i < n; i++)
	{
		sum += s[i];
		if (s[i] > *max)
			*max = s[i];
		if (s[i] < *min)
			*min = s[i];
	}
	return sum / n;
}
void faver_Input()
{
	int a[5] = { 80,89,67,76,98 };
	int max, min;
	double aver;
	aver = faver(a, 5, &max, &min);  //调用函数,传递地址，带回值（或者用引用类型函数，方法同void swap(int* xp,int* yp)里的注释）
	cout << "max=" << max << "\n" << "min=" << min << endl;
	cout << "aver=" << aver << endl;
}

// 返回指针类型的函数
/*###########################################################################################################*/
char* noblank(char* str)
{
	while (*str == ' ')
		str++;  // str为指针类型，指针+1等价于+siezof(ElemType)，即指向下一个数据的地址，并不是直接+1.
	return str;
}
void noblank_Input()  // 去除字符串开头的空格
{
	char s[] = "   using namespace std;";  // 数组单独的变量名即为指针变量，指向数组中的第一个元素
	char* s1 = s;
	char* s2;
	s2 = noblank(s1);
	cout << s2 << endl;
}

// 函数指针，指向函数的指针变量
/*###########################################################################################################*/
void FunctionPrinter()
{
	double (*pf)(double);   // <函数返回值><*指针变量名><形参类型列表（可以只写类型而不写变量名）>，（两对圆括号不可省略！）
						    // 定义指向double型函数的指针变量，该函数有一个double型参数
	pf = &sqrt;  // pf指向平方根函数，pf为指针变量，应赋地址（但不加&符号也正确，但在定义类函数指针时必须加&，不知道为什么）
	cout << (*pf)(9.0) << endl;  // 计算9的平方根
	cout << sqrt(9.0) << endl;  // 与上等价
}

 // 指针与一维数组及关系运算
void One_Dimensional_ArrayPrinter()
{
	double a[5] = { 1,2,3.5,4,5.7 }, * p;  // a、p为double型指针变量，x为数组首地址，故a+1即为数组a首元素的下一个元素
	for (p = a; p < a + 5; p++)     // 将数组首地址赋给p，当p超过数组首地址后五个元素后终止，p++是指指向p指针下一个元素
									// 指针p+i = p + i*siezof(ElemType)，即指向当前元素的第后i数据的地址，并不是直接+i.
									// 指针p-i = p - i*siezof(ElemType)，即指向当前元素的第前i数据的地址，并不是直接-i.
		cout << *p << "\t";
	cout << endl;

	p = a;
	// 数组元素不同表示形式
	cout << "a[i]" << "\t" << "*(a+i)" << "\t" << "*(p+i)" << "\t" << "p[i]" << endl;
	for (int i = 0; i < 5; i++)
		cout << a[i] << "\t" << p[i] << "\t" << *(a + i) << "\t" << *(p + i) << endl;
		     // 下标法1----------2----------------指针法1-------------2-------
			 // a[i] = p[i] = *(a+i) = *(p+i)
};

// // 指针与一维数组及关系运算
void Two_Dimensional_ArrayPrinter()
{
	/*
	由于
	a[0]是由a[0][0],a[0][1],a[0][2]和a[0][3]四个元素构成的一维数组，(a相当于一维数组的首地址)
	因此
	a[0]代表&a[0][0],即0行的首元素的地址
	这样
	a[0]+1代表首元素的下一个元素的地址即&a[0][1]		-->a[0]+j代表&a[0][j]
	同理
	a[1]代表&a[1][0],即1行的首元素的地址				-->a[1]+j代表&a[1][j]

	a[i]代表&a[i[0],即i行的首元素的地址				-->a[i]+j代表&a[i][j]

	由此得到：*(a[i]+j)等价于a[i][j]
	又由于    a[i]等价于*(a+i),因此，*(a[i]+j)也等价于*(*(a+i)+j)
	即：      *(*(a+i)+j)与a[i][j]等价
	我们将    *(*(a+i)+j)称为二维数组元素a[i][j]的指针法表示。
	其中，    a为首行地址，a+i为i行的行地址，而*(a+i)为a的i行0列元素的地址，而*(a+i)+j为a的i行j列元素的地址。
	*/
	int a[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12} }; // 三行四列的二维数组可看作三个一维数组
						// 三个一维数组的首地址分别为a[0],a[1],a[2]
						// 
	// 指向具有M个元素的一维数组指针的定义格式--> 类型名 (*变量名)[M]; 利用该指针变量可指向二维数组的行地址，M表示二维数组的列数
	int(*p)[4];  //数组行指针
	cout << "----------------------------------" << endl;  // 法一
	for (p = a; p < a + 3; p++)  // a+i->依次指向下一行
	{	//输出p所指行的各列元素值
		for (int j = 0; j < 4; j++)
			cout << *(*p + j) << "\t";  // *p + j 表示改行的第j个元素的地址，加*表示该元素
		cout << endl;
	}

	cout << "----------------------------------" << endl;  // 法二
	for (p = a; p < a + 3; p++)  // a+i->依次指向下一行
	{	//输出p所指行的各列元素值
		for (int* q = *p; q < *p + 4; q++)  // q是指向列元素类型的指针，初值为*p,即该行0列元素的地址
											// <*p>整体为一维数组的首地址(与一维数组写法相似)，即行首地址、行数组指针
			cout << *q << "\t";  // 
		cout << endl;
	}
}

// 字符型指针
void StringPrinter()
{
	/*
	字符串常量可看成存放在一个一维的字符数组中，当指针指向字符串后，引用字符串中的字符可使用下面的形式：
	*(指针变量+下标) / 指针变量[下标]
	
	char str[],*pstr 异同点
	str[] -->字符型数组
	pstr  -->字符型指针

	// 未初始化时
	cin >> str;  !正确!，可从键盘接收数据流，保存至str数组中
	cin >> pstr; !错误!，未初始化时pstr指针变量没有所指向的对象，不能进行读入值

	str = "abc"  !错误!，str数组名为常量指针，不能够被赋值
	pstr = "abc" !正确!，指针变量可以进行赋值（保存首地址）

	为字符数组 str[] 赋值方法 1、定义时赋值
							2、使用strcpy()函数 (int型数组可以直接用 = 赋值)
	*/
	char* str1 = "Hello World";;

	// 指针数组定义格式 --> 类型 *数组名[元素个数]; 存储数据类型为ElemType指针类型
	int* ptr[5];  // 定义5个int型的指针数组
	char* str[] = { "Basic","Fortran","C++","Java"};  // 定义指向多个字符串的指针数组，str[i]将指向第i个字符串

	// 实例：月份数字与英文转换
	void ConversionMonth_Input();
	ConversionMonth_Input();
}

// 结构体指针
void StructPrinter()
{
	/*
	结构体变量的指针：&结构体变量名
	1.定义指向结构体变量的指针
	  结构体类型*指针变量名；
	2.使用结构指针访问结构变量中的成员
	格式1：(*指针变量).成员名
	格式2：指针变量->成员名
		其中：->为结构指向运算符
	*/

	typedef struct Date {
		int year;
		int month;
		int day;
	}*date;

	Date d = { 2023,1,8 }, * p = &d;  // 定义日期结构变量和指针变量
	date s = &d;
	cout << "格式一：" << (*p).year << "-" << (*p).month << "-" << (*p).day << endl;
	cout << "格式二：" << p->year << "-" << p->month << "-" << p->day << endl;
	cout << "指针型：" << s->year << "-" << s->month << "-" << s->day << endl;
}

// 动态数组（可通过变量指定数组长度）
void DynamicArrays()
{
	/*
	new 运算符--用于动态申请所需的内存空间
	1.动态申请单个变量
		指针变量 = new 类型; 无名变量，通过同类型指针指向
	2.动态申请一维数组
		指针变量 = new 类型[元素个数]; 无名变量，通过同类型指针指向

	delete 运算符--用于释放动态申请的存储空间
	1.动态释放单个变量：
		delete 指针变量;	释放单个动态变量
	2.动态释放数组
		delete[] 指针变量;  释放动态数组

	动态数组可在函数体中动态申请空间而暂时不释放返回动态数组的指针，实现函数返回后数据不丢失
	*/
	double* pd = new double(100.0);  // 动态申请一个double型变量，初值为100.0

	int n;
	cout << "请输入动态申请一维数组的长度：" << endl;
	cin >> n;
	int* pi = new int[n];  // 动态申请长度为n的int型数组，若申请失败（内存不足），则为pi返回NULL，即0值
	// int* pi = (int*)malloc(n * sizeof(int));  // C语言molloc用法
	// free(pi);
	if (pi == NULL) {
		cout << "申请失败！";
		return;
	}
	cout << "请输入数组各元素：" << endl;
	for (int i = 0; i < n; i++)
		cin >> pi[i];
	for (int i = 0; i < n; i++)
		cout << pi[i] << "\t";

	delete pd;
	delete[] pi;
}
// 指针的应用
void UsingPrinter()
{
	void CharSort_Input();
	CharSort_Input();  // 自定义字符串排序

	void IPAddressTranslation_Input();
	IPAddressTranslation_Input();  // IP二进制转十进制
}

//const用法
/*
1、修饰变量
	const 类型 变量名;  -->该变量是常量，不能修改，可以使用和输出（应在声明时赋值）
	/ 类型 const 变量名;
2、修饰引用
	const 类型& 引用名;  --> 常引用，可以是普通变量或者常量的引用，但一般引用不能是常量的引用（有可能通过引用修改变量值导致错误）
3、修饰指针--常内容指针
	const 类型* 指针名;  -->常内容指针，指针所指向的内容不能修改，但该指针可以赋值修改
	/ const (类型)* 指针名;
	类型* const 指针名;  -->常指针，指针变量的值（即所指向的地址）不能修改，但该指针指向的内容可以修改（应在声明时赋值）
	/ const (类型*) 指针名;
	const 类型* const 指针名  -->此时指针和其所指向的内容均不可变
4、修饰函数
	出现在返回值前
	const 返回类型 函数名();   -->返回值是常量，既可以将其赋值给常量（定义时），也可以赋值给普通变量
	const 返回类型* 函数名();  -->返回值是常内容指针，应将函数结果赋值给内容常量指针，不能赋值给普通指针
	返回类型* const 函数名();  -->返回值是常指针，函数结果无特殊赋值要求
	出现在函数形参中
	返回类型 函数名(const 类型 变量名,类型* const 指针名,const 类型* 指针名);  -->表明该变量在函数内使用受限
5、修饰对象/对象指针/对象引用
	const 类名 对象名;  -->常量对象，该对象的所有成员（数据成员）不能修改
						  对于const修饰的对象，只能调用对象的const成员函数，不能调用非const成员函数（非const成员函数会有修改成员变量的企图）
		const成员函数声明：返回类型 成员函数名() const;
						  不能修改数据成员的值，也不能访问非const成员函数
		const成员变量声明：const 类型 变量名;
						  该成员变量只能在构造函数头部进行初始化
						  例：	A(int x):Value(x){
									Value = 10; X!  // 只能在初始化列表中（头部，冒号后面）赋值
								}
						  
	const 类名* 对象名;  -->常对象指针，不能通过该引用名修改对象的成员
	类名* const 对象名;  -->常量指针
	const 类名& 引用名 = 指针名;  -->常引用

PS：引用和指针常量不能修改是指不能通过该常量引用名或指针名修改内容，若有其他普通引用或者指针指向相同的内容，则仍可以通过该普通引用或者指针改变内容

*/

/*函数实例*/
/*###########################################################################################################*/

// 月份转换函数
char* ConversionMonth(int n)
{
	static char* month[] = {
		"Illegal month",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	return (n >= 1 && n <= 12) ? month[n] : month[0];
}
//调用入口，用户输入
void ConversionMonth_Input()
{
	int n;
	cout << "请输入月份：" << endl;
	cin >> n;
	cout << n << "-" << ConversionMonth(n) << endl;  // 输出字符串指针变量即输出该字符串中的内容
}

//自定义字符串排序函数
/*自定义字符串拷贝和比较函数*/
//字符串拷贝函数
void CustomizationStrcpy(char* s1, char* s2)
{
	while (*s2 != 0)
		*s1++ = *s2++;
	* s1 = '\0';
}
//字符串比较函数
int CustomizationStrcmp(char* s1, char* s2)
{
	while (*s1 = *s2 && *s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
//字符交换函数
void charswap(char* p,char* q)
{
	char t[10];
	CustomizationStrcpy(t, p);
	CustomizationStrcpy(p, q);
	CustomizationStrcpy(q, t);
}
void CharSort(char(*p)[10], int n)  // 传入二维数组的行地址
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			//if (strcmp(p[i], p[j]) > 0)  // 默认库函数
			if (CustomizationStrcmp(p[i], p[j]) > 0)
			{
				/*char t[10];
				strcpy(t, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], t);*/
				charswap(p[i], p[j]);
			}
}
//打印输出字符串
void CharPrint(char(*s)[10], int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << s[i] << " ";
	cout << s[n - 1] << endl;
}
//调用入口，用户输入
void CharSort_Input()
{
	int n;
	// char str[][10] = { "Zhang","Wang","Wen","xu","Li","zhou" };
	cout << "请输入字符串个数：";
	cin >> n;
	char(*str)[10] = new char[n][10];
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个字符串：";
		cin >> str[i];
	}
	CharSort(str, n);
	cout << "排序后的" << n << "个字符串：" << endl;
	CharPrint(str, n);

	delete[] str;
}

//IP地址二进制转十进制
//自定义合法性检验函数
bool check(char* str)
{
	int i;
	for (i = 0; i < 32; i++)
		if (str[i] != '1' && str[i] != '0')
			return false;
	return true;
}
//自定义32位二进制数转换为十进制数函数
int BaseConversion(char* str)
{
	int n = 0;
	for (int i = 0; i < 8; i++)
		if (str[i] == '1')  // 二进制转十进制公式
			n = n * 2 + 1;
		else
			n = n * 2;
	return n;
}
//调用入口，用户输入
void IPAddressTranslation_Input()
{
	char IP[33];
	cout << "请输入32位二进制IP地址：" << endl;
	cin >> IP;
	if (strlen(IP) != 32)
		cout << "IP地址长度应为32位" << endl;
	else
		if (!check(IP))
			cout << "串中有8/1外字符，非正确IP地址" << endl;
		else
		{  //四次调用BaseConversion函数分别转换四组二进制数
			cout << "IP址对应的点分十进制写法为：" << endl;
			cout << BaseConversion(IP) << "." << BaseConversion(IP + 8) << "."
				<< BaseConversion(IP + 16) << "." << BaseConversion(IP + 24) << endl;
		}
}

/*###########################################################################################################*/


void KnEntrance()
{
	//PrevarVariables();
	//Variable();
	//StaticLocalVariables();
	//HanoiInput();
	//FibonacciInput();
	//Binary_Search_Input();
	//MultifunctionSort();
	//swap_Input();
	//faver_Input();
	//noblank_Input();
	//FunctionPrinter();
	//One_Dimensional_ArrayPrinter();
	//Two_Dimensional_ArrayPrinter();
	//StringPrinter();
	//StructPrinter();
	UsingPrinter();
}
