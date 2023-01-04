#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>

#include "Knowledge.h"

using namespace std;

// 变量作用域及生存期
/*###########################################################################################################*/
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

// 指针传值（&-取地址符号、*-指针变量）
/*###########################################################################################################*/
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

// 指向函数的指针变量
/*###########################################################################################################*/
void FunctionPrinter()
{
	double (*pf)(double);   // <函数返回值><*指针变量名><形参类型列表（可以只写类型而不写变量名）>，（两对圆括号不可省略！）
						    // 定义指向double型函数的指针变量，该函数有一个double型参数
	pf = sqrt;  // pf指向平方根函数
	cout << (*pf)(9.0) << endl;  // 计算9的平方根
	cout << sqrt(9.0) << endl;  // 与上等价
}



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
	FunctionPrinter();
}