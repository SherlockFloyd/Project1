#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

#include "KnowledgeObject.h"


/*类的定义，声明及使用*/
/*====================================================================================================*/
// 时间展示类
class Clock
{
private:  // 私有成员：定义的变量和函数在类外部不可访问，仅在本类内部可访问
	int Hour;
	int Minute;
	int Second;
	float Price;
public:  // 公有成员：定义的变量和函数在类外部可访问
	void Set(int h, int m, int s, float p);  // 设置修改4个数据成员的值的函数
	void Run();  // 模拟运行
	void Report_Time();  // 整点报时，类体外定义
	void Show_Time()  // 内联函数 --> 在类体内直接定义的函数，输出时间
	{
		cout << Hour << ":" << Minute << ":" << Second;
	}
protected:  // 保护成员：定义的变量和函数在本类及继承类中可访问，类外部不可访问

};

/*
在体外定义成员函数：<返回类型><类名> :: <函数名>(<参数表>)
{
	<函数体>
}
*/ 
void Clock::Set(int h, int m, int s, float p)  // 设置修改4个数据成员的值的函数
{
	Hour = h;
	Minute = m;
	Second = s;
	Price = p;
}
void Clock::Run()  // 模拟运行
{
	int i = 0;
	for (i = 0; i < 10; i++) {  //只模拟运行10秒钟
		Second++;
		if (Second == 60) {
			Second = 0;
			Minute++;
			if (Minute == 60) {
				Minute = 0;
				Hour++;
				if (Hour == 24)Hour = 0;
			}
		}
		Sleep(1000);  //程序暂停1秒
		cout << "\r                      \r";  //不换行，返回当前行的首位,同时利用空格消除同行中残留的字符
		Show_Time();
	}
	cout << endl;
}
void Clock::Report_Time()
{
	Show_Time();
	if (Minute == 0 && Second == 0)
	{
		for (int i = 0; i < Hour; i++)  // 几点响几声，0点不响
		{
			cout << "\007";
			Sleep(1000);
		}
	}
}
void ClockInvoke()
{
	Clock c1;  // 声明了一个Clock类的对象
	c1.Set(3, 59, 50, 1000);  // 对象通过 . 运算符访问类中的成员函数
	cout << "模拟钟表当前的时间为：" << endl;
	c1.Report_Time();
	c1.Run();
	c1.Report_Time();
	cout << endl;
}

// 分数操作类
class Fraction
{
private:
	int divisor(int p, int q);  // 求最大公约数
protected:
	int a;  // 分子可以定义为保护成员
	int b;  // 分母应该定义为保护成员，因为要防止分母为0
public:
	void set(int aa, int bb);  // 设置分子分母
	void show();  // 显示分数
	Fraction add(Fraction u);  // 加一个分数
};
// 设置分子、分母
void Fraction::set(int aa, int bb)
{
	a = aa;
	if (bb != 0) // 分母有效性检验
		b = bb;
	else
	{
		a = 0;
		b = 1;
	}
}
void Fraction::show()
{
	cout << a << "/" << b << endl;
}
//分数相加，本类对象加u
Fraction Fraction::add(Fraction u) {  // 分数求和有问题	
	int tmp;
	Fraction v{};
	v.a = a * v.b + b * u.a;  // 分子
	v.b = b * u.b;  // 分母 
	tmp = divisor(v.a, v.b);  // 计算分子、分母的公约数
	v.a = v.a / tmp;  // 约去公约数
	v.b = v.b / tmp;  // 约去公约数
	return v;  // 返回结果
}
//计算公约数，私有成员
int Fraction::divisor(int p, int q)
{
	int r;
	if (p < q){
		int tmp;
		tmp = p;
		p = q;
		q = tmp;
	}
	r = p % q;
	while (r != 0){
		p = q;
		q = r;
		r = p % q;
	}
	return q;
}
// Real类继承Fraction类
class Real:public Fraction {
public:
	void show_real()
	{
		cout << a<<"/" << b << '=' << a / (double)b << endl;  // 显示分数
	}
};

void Fraction_Invoke()
{
	Real f1, f2;
	Fraction f3;
	int a, b, c, d;
	cout << "请以分子、分母的顺序依次输入两个分数" << endl;
	cin >> a >> b;
	cin >> c >> d;
	f1.set(a, b);
	f2.set(c, d);
	f1.show_real();
	f2.show_real();
	f3=f1.add(f2);   // 分数求和有问题
	f3.show();
	cout << endl;
}


// 日期类
class Date {
private:
	int year, month, day;
	void SetSystemDate();  // 取得系统日期
public:
	void init(int, int, int);  // 设置年月日数据
	void print_ymd();  // 显示年月日
	void print_mdy();  // 显示月日年
	int get_year() {return year;}  // 得到年份值
	int get_month() {return month;}  // 得到月份值
	int get_day() {return day;}  // 得到日值
	bool IsLeapYear();  // 判断是否为闰年
};

// 取得系统日期
void Date::SetSystemDate()  
{
	tm* gm;  // tm是时间（含年月日时分秒）结构体
	time_t t = time(NULL);  // time t是长整型，t表示（总秒数）
	gm = gmtime(&t);
	year = 1900 + gm->tm_year;
	month = gm->tm_mon + 1;
	day = gm->tm_mday;
}
// 日期初始化
void Date::init(int yy, int mm, int dd)
{
	if (yy >= 1900 && yy <= 9999)
		year = yy;
	else
	{
		SetSystemDate();
		return;
	}
	if (mm >= 1 && mm <= 12)
		month = mm;
	else
	{
		SetSystemDate();
		return;
	}
	if (dd >= 1 && dd <= 31)
		day = dd;
	else
	{
		SetSystemDate();
		return;
	}
};
void Date::print_ymd()
{
	cout << year << "-" << month << "-" << day << endl; 
}
void Date::print_mdy()
{
	cout << month << "-" << day << "-" << year << endl; 
}
bool Date::IsLeapYear()
{
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return true;
	else
		return false; 
}

void Date_Invoke()
{
	Date date1;  // 创建一个日期类对象，但未初始化
	date1.print_ymd();  // 显示未初始化数据的情况
	system("pause");
	date1.init(2022, 3, 28);  // 初始化数据成员
	date1.print_ymd();  // 按年月日显示日期
	system("pause");
	Date date2;  // 再创建一个日期类对象
	date2.init(2023, 13, 28);  // 初始化错误的日期数据
	date2.print_mdy();  // 按月日年显示日期
	system("pause");
	if (date1.IsLeapYear())  // 判断闰年函数
		cout << date1.get_year() << "是闰年" << endl;
	else
		cout << date1.get_year() << "不是闰年" << endl;
}

void ObjectEntrance()
{
	//ClockInvoke();
	//Fraction_Invoke();
	Date_Invoke();
}