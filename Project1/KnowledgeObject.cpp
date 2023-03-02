#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeObject.h"

using namespace std;


/*类的定义，声明及使用

C++规定不允许在类中定义该类的对象，防止套娃导致内存耗尽，栈溢出
	可以定义静态类(static classname objectname)、类指针、类引用（指针和引用的赋值必须是通过构造函数的参数传过来的，不能new出来。）
		因为静态的成员不在对象的内部，在data区，被这个类共享。所以不会出现递归创建。
*/

/*====================================================================================================*/
// 时间展示类
class Clock
{
private:  // 私有成员：定义的变量和函数在类外部不可访问，仅在本类内部可访问(不写成员类型的变量及函数默认为私有)
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
	Fraction(){}  // 若没有构造函数，使用未初始化的对象时会报错，但此时未初始化对象中存储的是不确定的随机值，不能直接拿来使用，需要覆盖
				  // 若仅有参构造函数，这创建对象时不初始化会出错，因编写了构造函数，系统不会自动分配无参构造函数，不能够使用没有值的对象，解决办法就是加一个无参构造函数
	void set(int aa, int bb);  // 设置分子分母
	void show();  // 显示分数
	Fraction add(Fraction u);  // 加一个分数
	Fraction add_pro(Fraction u);  // this指针测试函数，定义在this指针知识点处
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
Fraction Fraction::add(Fraction u) {
	int tmp;
	Fraction v;
	v.a = a * u.b + b * u.a;  // 分子
	v.b = b * u.b;  // 分母 
	tmp = divisor(v.a, v.b);  // 计算分子、分母的公约数
	v.a = v.a / tmp;  // 约去公约数
	v.b = v.b / tmp;  // 约去公约数
	return v;  // 返回结果
}

/*
！函数返回值知识点 ！
类成员函数返回类对象的方式：
1、直接返回类对象，return classname
	返回类型是类对象时自动调用拷贝构造函数，返回的是对象的副本，自动调用拷贝构造函数
2、返回类对象的引用 return &classname
	返回类型是类引用时返回实际对象的引用，此时类对象必须为全局对象，即在成员函数外部的类中定义的对象，这样在函数返回后释放栈空间时数据仍然可以保留

如果返回的对象是所调用函数的局部对象，那它就不应该被以引用或者指针的方式返回，
	因为在这个函数调用结束的时候局部对象会自动消除，所以不用我们管。也因此，我们绝对不能返回一个局部对象的引用或者指针，因为函数调用完的时候它已经不存在了。

总结：
1，如果函数返回的是局部变量，那么返回值类型不能是引用或指针。（使用局部对象会多调用一次构造和析构函数，效率较低）
2，如果函数返回的是类对象，但是该类没有public的拷贝构造函数，比如ostream类，那就返回引用。（有拷贝构造函数系统不会自动调用默认拷贝构造函数，无法完成对象拷贝）
3，有的函数，比如重载的=，可以返回对象也可以返回引用，引用比较好，因为效率高。（引用不会调用拷贝构造函数）
再总结：除了返回局部对象，一般都是返回引用。

扩展：
返回值不能是函数局部定义的数组或者其引用或者指针，
	此时返回的仅有数组的第一个元素，其余元素随着函数的返回一同被清除
*/

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
	cout << "两分数结果" << endl;
	f1.show_real();
	f2.show_real();
	f3=f1.add(f2); 
	cout << "求和结果" << endl;
	f3.show();
	cout << endl;

	f3 = f1.add_pro(f2);  // 利用f1本身的对象空间存储计算结果，不重新创建中间对象，通过this指针访问
	f1.show();
	f3.show();
	cout << "此时f1与f3值相同，通过this指针利用本身的存储空间计算的结果是破坏性的" << endl;
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


/*类的封装、重载、析构、this、指针*/
/*====================================================================================================*/
/*
构造函数(Constructor) --> 通常用于类成员变量的初始化
语法格式：
〈类名〉(<参数表>)
{
	く函数体〉
}
注意事项：
构造函数的函数名必须与类名相同
构造函数没有返回值
其功能是将对象中的所有数据成员进行初始化，一般由一系列赋值语句构成
由系统在声明对象时自动调用


析构函数(Destructor) --> 在对象被撤销时(前)执行，用于完成对象被撤消前的一些清理工作
即析构函数往往用于释放“资源”，：
如在构造函数中动态申请的内存空间，也可以被用来执行“用户希望在最后一次使用对象之后所执行的任何操作”，如输出有关信息等
语法格式：
~<类名>()
{
	<函数体>
}
注意事项：
函数名是：类名前面加"~"符号
析构函数不得返回任何值
析构诬数不得带有任何参数
其主要功能是在撤销对象之前进行一些善后处理工作

构造函数与析构函数均可定义在函数体外部，格式与普通函数定义相同：<类名>::<函数名> （均无返回值）
				必须由public修饰，才能在外部被系统调用
*/
// 日期类,含构造函数
class Date1 {
private:
	int year, month, day;
public:
	// 若没有构造函数，使用未初始化的对象时会报错，有构造函数则系统自动调用构造函数，不会报错
	// 构造函数，用于类成员变量的初始化，参数表中的变量可赋初值也可不赋初值（初值赋值遵守函数赋初值规则，无初值的变量在前，初值变量在后）
	Date1(int y , int m = 1, int d = 1) 
	{
		year = y;
		month = m;
		day = d;
	}
	// 构造函数的重载，根据参数表中的变量类型及个数自动选择构造函数
	Date1()
	{
		year = 2023;
		month = 2;
		day = 2;
		char* pd;
	}
	/*构造函数初始化的4种方法
	1.在构造函数的函数体中进行初始化
		Date (Date &d){year=d.year;month=d.month;day=d.day;}
	2.在构造函数的头部初始化
		构造函数名(参数表):变量1(初值1)，…变量n(初值n){…}
		Date():year(1900),month(1),day(1){}
	3.使用默认参数初始化
		Date(char y[],int m = 1,int d = 1)
		{
			year = atoi(y);
			month = m;
			day = d;
		}
	3.混合初始化：2、3方式结合
		Date(int y,int m,int d):year(y),month(m){day=d;}
	*/
	Date1(Date1& date) :year(date.year), month(date.month), day(date.day) {}  // 对象参数构造函数
	//Date1() :year(2023), month(3), day(3) {}  // 无参构造函数（与上面第二种方法一样，两者不能共存）
												// 默认参数构造函数，上面第一种
	// 混合初始化，首先通过无参构造函数赋初值，同时通过指向日期的字符串在函数体中赋值，没有经过处理的变量则为无参函数的初值
	Date1(char* ps) :year(2023), month(1), day(9)
	{
		char py[5], pm[3];
		pd = new char[3];  // 使用动态数组，测试析构函数
		strncpy(py, ps, 4);
		ps = ps + 5;
		strncpy(pm, ps, 2);
		ps = ps + 3;
		strncpy(pd, ps, 2);
		year = atoi(py);  // 将数字格式的字符串转换为整数类型
		month = atoi(pm);
		//day = atoi(pd);  // 使用默认参数日期
	}

	// 析构函数：无参数表无返回值，析构函数无参数决定其不能重载，只能有一个，在对象生命周期结束（调用函数返回或者运行delete），被销毁时由系统自动调用
	~Date1() 
	{
		delete[] pd;
		delete pn;
		delete[] pd;
		cout << "对象撤销时间" << endl;
	}

	int* pn = new int;  // 测试析构函数使用
	char* pd = new char[3];  // 测试析构函数使用
	void init(int, int, int);  // 设置年月日数据
	int get_year() { return year; }  // 得到年份值
	int get_month() { return month; }  // 得到月份值
	int get_day() { return day; }  // 得到日值
};

void Date1::init(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date1_Invoke()
{
	/*
	对象的存储空间：
	每个对象中的成员变量单独存储，而所有同类的对象共用同一成员函数的存储空间
	*/
	// 具有构造函数的类可在创建对象时进行初始化，自动调用构造函数进行初始化
	Date1 date1(2023, 2, 3);  // 创建一个日期类对象，并初始化
	Date1 date2;  // 调用无参构造函数进行初始化
	Date1 date3(date2);  // 调用对象参数构造函数
	char date[11] = "2023-04-04";
	Date1 date4(date);  // 调用混合初始化构造函数

	cout << date1.get_month();
	cout << date2.get_month();
	cout << date3.get_month();
	cout << date4.get_month();
	 
}

// 类的对象与指针
/*
1、指向对象的指针：类名* 指针变量名表;
	例：
	Person person1("Zhang3",19,'f');
	Person *ptr=&Person1;
	ptr->Show();
2、动态存储：对象指针 = new 类名(名字初始化值）
			delete 对象指针；
	例：Person* p=new Person;
		delete p;



-> 与 . 的使用
1、栈与堆
对象放在堆上（系统自动分配与回收），就要用指针，也就是 对象指针->函数;
	放在栈上（动态分配与回收），就要用 对象.函数;
为明确运算的优先级，一般在加括号，如：(*this).function
2、指针与对象
如果是指针访问数据成员或成员函数，用 -> ;
如果是某个数据类型的对象，访问自己的数据成员和成员函数用 . ;
*/
class Date3 {
public:
	int year, month, day;
	Date3() :year(2023), month(1), day(1){};  // 构造函数
	void init(int, int, int);  // 设置年月日数据
	void print_ymd();  // 显示年月日
	~Date3(){};  // 析构函数
};
void Date3::init(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}
void Date3::print_ymd()
{
	cout << year << "-" << month << "-" << day << endl;
}
void Date3_Invoke()
{
	Date3 date1;  // 创建Date3的对象
	Date3* p1 = &date1;  // 创建指向对象的指针
	Date3 date2;
	p1->print_ymd();
	p1->init(2023, 2, 2);  // 对象指针通过 -> 访问其变量成员和函数成员
	date2.init(2023, 2, 3);  // 对象通过 . 访问其变量成员和函数成员
	p1->print_ymd();
	date2.print_ymd();

	int* p2 = &date1.year;  // 等价于 int* p2 = &(date1.year) ，p2是指向date1中成员变量year的指针
	int year2 = p1->year;  // 指向对象的指针用 ->
	cout << *p2 << year2 << endl;

	void(Date3:: * p3)(int, int, int);  // 指向类成员函数的指针，类似Knowledge.cpp中函数指针的讲，与普通函数指针定义不同的是 Date3:: * p3 写法表明为Date3类中的指针
	void (Date3:: * p4)();  // 指向类成员函数的指针
	p3 = &Date3::init;  // p3等价于Date3中的init函数，p3为指针类型，应取成员函数地址赋值
	p4 = &Date3::print_ymd;  // p4等价于Date3中的print_ymd函数
	(date1.*p3)(2023, 4, 8);  // 等价于 date1->p3 ，调用init函数
	(date1.*p4)();  // 调用print_ymd函数

	Date3* p5 = new Date3;  // 动态申请对象指针
	delete p5;
}

/*
this指针
每一个类的成员函数都包含一个指向本类对象的指针
指针名为this
该指针指向本类对象的起始地址
当类中数据成员名与成员数中的形参名相同时，用this指针加以区分
*/
class Text
{
	int x;  // 无访问控制符，默认私有
public:
	Text(int = 0);  // 构造函数，当不赋初值时默认赋值为0，当赋初值时使用所赋值
	void print();
};
Text::Text(int x)  // 构造函数定义
{
	this->x = x;  // 使用this区分局部变量与类成员变量
}
void Text::print()
{
	int x = 12138;
	cout << "x\t的值为：" << x << endl;  // 访问局部变量x，值为局部变量的值
	cout << "this->x\t的值为：" << x << endl;  // 访问类成员变量
	cout << "(*this).x\t的值为：" << x << endl;  // // 访问类成员变量，this->x 等价于 (*this).x
}
// this指针结合分数加法函数，使用原来类的对象进行计算，覆盖原来的值，破坏了原来值
Fraction Fraction :: add_pro(Fraction u)
{
	int tmp;
	//Fraction v;
	a = a * u.b + b * u.a;  // 用本身对象存储运算结果，破坏性
	b = b * u.b;  // 分母
	tmp = divisor(a, b);  // 计算分子、分母的公约数
	a = a / tmp;  // 约去公约数
	b = b / tmp;  // 约去公约数
	return *this;  // 返回结果,返回原来的对象
}


//C++拷贝构造函数（复制构造函数）详解
/*
复制构造函数是构造函数的一种，也称拷贝构造函数，它只有一个参数，参数类型是本类的引用。
复制构造函数的参数可以是 const 引用，也可以是非 const 引用。 一般使用前者，这样既能以常量对象（初始化后值不能改变的对象）作为参数，也能以非常量对象作为参数去初始化其他对象。一个类中写两个复制构造函数，一个的参数是 const 引用，另一个的参数是非 const 引用，也是可以的。
如果类的设计者不写复制构造函数，编译器就会自动生成复制构造函数。大多数情况下，其作用是实现从源对象到目标对象逐个字节的复制，即使得目标对象的每个成员变量都变得和源对象相等。编译器自动生成的复制构造函数称为“默认复制构造函数”。
注意，默认构造函数（即无参构造函数）不一定存在，但是复制构造函数总是会存在。

下面是一个复制构造函数的例子。
#include<iostream >
using namespace std;
class Complex
{
public:
	double real, imag;
	Complex(double r, double i) {
		real= r; imag = i;
	}
};
int main(){
	Complex cl(1, 2);
1->	Complex c2 (cl);  //用复制构造函数初始化c2
	cout<<c2.real<<","<<c2.imag;  //输出 1,2
	return 0;
}
第 1-> 行给出了初始化 c2 的参数，即 c1。只有编译器自动生成的那个默认复制构造函数的参数才能和 c1 匹配，因此，c2 就是以 c1 为参数，调用默认复制构造函数进行初始化的。初始化的结果是 c2 成为 c1 的复制品，即 c2 和 c1 每个成员变量的值都相等。

如果编写了复制构造函数，则默认复制构造函数就不存在了。下面是一个非默认复制构造函数的例子。
#include<iostream>
using namespace std;
class Complex{
public:
	double real, imag;
	Complex(double r,double i){
		real = r; imag = i;
	}
1->	Complex(const Complex & c){
		real = c.real; imag = c.imag;
		cout<<"Copy Constructor called"<<endl ;
	}
};
int main(){
	Complex cl(1, 2);
2->	Complex c2 (cl);  //调用复制构造函数
	cout<<c2.real<<","<<c2.imag;
	return 0;
}
程序的输出结果是：
Copy Constructor called
1,2

第 1-> 行，复制构造函数的参数加不加 const 对本程序來说都一样。但加上 const 是更好的做法，这样复制构造函数才能接受常量对象作为参数，即才能以常量对象作为参数去初始化别的对象。

第 2-> 行，就是以 c1 为参数调用第 1-> 行的那个复制构造函数初始化的。该复制构造函数执行的结果是使 c2 和 c1 相等，此外还输出Copy Constructor called。

可以想象，如果将第 10 行删去或改成real = 2*c.real; imag = imag + 1;，那么 c2 的值就不会等于 c1 了。也就是说，自己编写的复制构造函数并不一定要做复制的工作（如果只做复制工作，那么使用编译器自动生成的默认复制构造函数就行了）。但从习惯上来讲，复制构造函数还是应该完成类似于复制的工作为好，在此基础上还可以根据需要做些別的操作。

构造函数不能以本类的对象作为唯一参数，以免和复制构造函数相混淆。例如，不能写如下构造函数：
Complex (Complex c) {...}

复制构造函数被调用的三种情况
复制构造函数在以下三种情况下会被调用。

1) 当用一个对象去初始化同类的另一个对象时，会引发复制构造函数被调用。例如，下面的两条语句都会引发复制构造函数的调用，用以初始化 c2。
Complex c2(c1);
Complex c2 = c1;
这两条语句是等价的。

注意，第二条语句是初始化语句，不是赋值语句。赋值语句的等号左边是一个早已有定义的变量，赋值语句不会引发复制构造函数的调用。例如：
Complex c1, c2; c1 = c2 ;
c1=c2;
这条语句不会引发复制构造函数的调用，因为 c1 早已生成，已经初始化过了。

2) 如果函数 F 的参数是类 A 的对象，那么当 F 被调用时，类 A 的复制构造函数将被调用。换句话说，作为形参的对象，是用复制构造函数初始化的，而且调用复制构造函数时的参数，就是调用函数时所给的实参。
#include<iostream>
using namespace std;
class A{
public:
	A(){};
	A(A & a){
		cout<<"Copy constructor called"<<endl;
	}
};
void Func(A a){ }
int main(){
	A a;
	Func(a);
	return 0;
}
程序的输出结果为：
Copy constructor called

这是因为 Func 函数的形参 a 在初始化时调用了复制构造函数。

前面说过，函数的形参的值等于函数调用时对应的实参，现在可以知道这不一定是正确的。如果形参是一个对象，那么形参的值是否等于实参，取决于该对象所属的类的复制构造函数是如何实现的。例如上面的例子，Func 函数的形参 a 的值在进入函数时是随机的，未必等于实参，因为复制构造函数没有做复制的工作。

以对象作为函数的形参，在函数被调用时，生成的形参要用复制构造函数初始化，这会带来时间上的开销。如果用对象的引用而不是对象作为形参，就没有这个问题了。但是以引用作为形参有一定的风险，因为这种情况下如果形参的值发生改变，实参的值也会跟着改变。

如果要确保实参的值不会改变，又希望避免复制构造函数带来的开销，解决办法就是将形参声明为对象的 const 引用。例如：
void Function(const Complex & c)
{
	...
}
这样，Function 函数中出现任何有可能导致 c 的值被修改的语句，都会引发编译错误。

思考题：在上面的 Function 函数中，除了赋值语句，还有什么语句有可能改变 c 的值？例如，是否允许通过 c 调用 Complex 的成员函数？

3) 如果函数的返冋值是类 A 的对象，则函数返冋时，类 A 的复制构造函数被调用。换言之，作为函数返回值的对象是用复制构造函数初始化的，而调用复制构造函数时的实参，就是 return 语句所返回的对象。例如下面的程序：
#include<iostream>
using namespace std;
class A {
public:
	int v;
	A(int n) { v = n; };
	A(const A & a) {
1->		v = a.v;
		cout << "Copy constructor called" << endl;
	}
};
A Func() {
2->	A a(4);
3->	return a;
}
int main() {
4->	cout << Func().v << endl;
	return 0;
}
程序的输出结果是：
Copy constructor called
4

第 4-> 行调用了 Func 函数，其返回值是一个对象，该对象就是用复制构造函数初始化的， 而且调用复制构造函数时，实参就是第 3-> 行 return 语句所返回的 a。复制构造函数在第 1-> 行确实完成了复制的工作，所以第 3-> 行 Func 函数的返回值和第 2-> 行的 a 相等。

需要说明的是，有些编译器出于程序执行效率的考虑，编译的时候进行了优化，函数返回值对象就不用复制构造函数初始化了，这并不符合 C++ 的标准。上面的程序，用 Visual Studio 2010 编译后的输出结果如上所述，但是在 Dev C++ 4.9 中不会调用复制构造函数。把第 2-> 行的 a 变成全局变量，才会调用复制构造函数。对这一点，读者不必深究。

*/


/*====================================================================================================*/

class XCF
{
    int a;
public:
    XCF(int aa = 0) : a(aa) { cout<<"1"; }
    XCF(XCF &x)
    {
        a = x.a;
        cout<<"2";
    }
    ~XCF() { cout<<a; }
    int Geta() { return a; }
};

void XCF_invoke()
{
    XCF d1(5), d2(d1);
    XCF *pd = new XCF(8);
    cout<<pd->Geta();
    delete pd;
}

/*
输出结果为：1218855
程序首先定义了一个名为XCF的类，该类具有一个int类型的私有变量a，一个构造函数，一个拷贝构造函数，一个析构函数和一个返回私有变量a的公有成员函数。

接下来，程序创建了两个XCF对象，d1和d2，并调用构造函数将d1的值设置为5，输出1。在创建d2时，程序调用了拷贝构造函数，并将d2的值设置为d1的值。由于拷贝构造函数的定义中包含了输出语句2，因此程序会输出数字2。

然后，程序使用new运算符创建一个名为pd的XCF对象指针，调用构造函数输出1，并将该对象的值设置为8。接着，程序通过pd指针访问了Geta函数，并输出了8。最后，程序使用delete运算符释放了pd指针所指向的内存。
delete语句执行时会显式执行delete析构函数并输出8。

在程序结束时，系统会自动调用对象的析构函数，调用对象d2的析构函数，将数字5输出到屏幕上。然后，系统会自动调用对象d1的析构函数，将数字5输出到屏幕上。最后，程序结束，输出结果为1218855。
*/
/*====================================================================================================*/






/*学生类：实例练习*/
/*====================================================================================================*/
class Students
{
private:
	int ID;  // 学号
	char Name[20];  // 姓名
	char Sex[5];  // 性别
	double DBGrade;  // 数据结构成绩
	double NWGrade;  // 计算机网络成绩
	double PCCGrade;  // 计算机组成原理成绩
	double OSGrade;  // 操作系统成绩
	double TotalGrade;  // 总成绩
public:
	void Set_info(int id, char* name, char* sex, double db, double nw, double pcc, double os);
	double Get_DBG() { return DBGrade; };
	double Get_NWG() { return NWGrade; };
	double Get_PCCG() { return PCCGrade; };
	double Get_OSG() { return OSGrade; };
	double Get_TolG() { return TotalGrade; };
	void Show();

};

void Students::Set_info(int id, char* name, char* sex, double db, double nw, double pcc, double os)
{
	ID = id;
	strcpy(Name, name);
	strcpy(Sex, sex);
	DBGrade = db;
	NWGrade = nw;
	PCCGrade = pcc;
	OSGrade = os;
	TotalGrade = DBGrade + NWGrade + PCCGrade + OSGrade;
}
void Students::Show()
{
	cout << "学号\t" << "姓名\t" << "性别\t" << "DB成绩\t" << "NW成绩\t" << "PC成绩\t" << "OS成绩\t" << "总成绩\t" << endl;
	cout << ID << "\t" << Name << "\t" << Sex << "\t" << DBGrade << "\t" << NWGrade << "\t" << PCCGrade << "\t" << OSGrade << "\t" << TotalGrade << "\t" << endl;
}

void Students_Invoke()
{
	const int COUNT = 5;  // 学生数量
	int n;
	int id;
	char name[20], sex[5];
	double db, nw, pcc, os;
	cout << "请输入学生数量：" << endl;
	cin >> n;
	//Students S[COUNT];
	Students* S = new Students[n];

	for (int i = 0; i < n; i++) {
		cout << "请按照以下格式输入第"<<i+1<<"个学生的信息：" << endl;
		cout << "学号\t" << "姓名\t" << "性别\t" << "DB成绩\t" << "NW成绩\t" << "PC成绩\t" << "OS成绩\t" << endl;
		cin >> id >> name >> sex >> db >> nw >> pcc >> os;
		S[i].Set_info(id, name, sex, db, nw, pcc, os);
	}
	for (int i = 0; i < n; i++)
		S[i].Show();

	delete[] S;
}


// 数字翻译成英文（动态数组及析构函数练习）
//定义两个全局字符指针数组，存取所需的单词
//num1中为到，空出了，所以可以直接用num1[n]调用，得到n对应单词
static char* num1[] = {
	"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten","eleven","twelve",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen"
};
//num10中为-90，空出了和，所以可以直接用num10[n/10]调用，得到n对应单词
static char* num10[] = {
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety"
};
class robot
{
	char name[20]; //机器人姓名
	char type[20]; //机器人型号
	int num; //待翻译的整数
	char* ps; //指向英文字符串
public:
	robot()//构造函数
	{
		strcpy(name, "XXXXXX");
		strcpy(type, "XXXXXX");
		num = 0;
		ps = new char[5];  // ps指向已经翻译好的英文句子
		strcpy(ps, "zero");
	}
	void set(char n[], char t[], int m); //设置修改数据
	char* out(int a);//英文中每三位数读法相同，所以定义out函数翻译小于1000的整数
	char* tran_int(int n);//将1至1999999999的整数翻译成英文句子
	void print_num();//输出整数及其英文句子
	~robot()   //析构函数 释放构造函数和set函数中动态申请的空间
	{ 
		cout << "堆区中" << strlen(ps) + 1 << "个字节空间被释放回收" << endl;
		delete[] ps;																						// 释放构造函数中申请的临时字符型动态数组
	}; 
};
//设置修改数据 
void robot::set(char n[], char t[], int m) 
{
	strcpy(name, n);
	strcpy(type, t);
	if (num == m) //待翻译的整数没有变（还是初始化时候的初值0）
		return;
	else {
		num = m;
		delete[] ps; //删除已有的英文句子
	}
	if (num > 0) {
		char* tp = tran_int(num);
		ps = new char[strlen(tp) + 1];																	//  将构造函数中声明的ps指针指向动态申请的数组空间，并作为翻译程序的传值指针，最后在析构函数中释放
		strcpy(ps, tp);
		delete[] tp;																						//  释放在trans_int中动态申请的空间
	}
	else {
		ps = new char[13];
		strcpy(ps, "负数不能翻译");
	}
}
//英文中每三位数读法相同，所以定义out函数对每组三位数进行处理
char* robot::out(int a)
{
	char k[1000] = "";  // 存放翻译句子的中间结果
	int b = a % 100;
	//若百位不为零，输出百位数加hundred，若此时十位个位均为，不加and
	if (a / 100 != 0) {
		strcat(k, num1[a / 100]);
		strcat(k, "hundred ");
		if (b != 0)
			strcat(k, "and ");
	}
	//当后两位在以内时，直接调用num1[n]，输出
	if (b < 20)
		strcat(k, num1[b]);
	//当后两位大于时
	else { //先调用num10，输出十位数
		strcat(k, num10[b / 10]);
		//个位不为时应输出"-"个位数
			if (b % 10 != 0) {
				strcat(k, "\b- ");
				strcat(k, num1[b % 10]);
			}
	}
	char* p = new char[strlen(k) + 1];																	// 动态申请的数组空间由p指针指向，存放翻译结果，没有释放，在上级调用函数中使用完后释放空间  
	strcpy(p, k);
	return p;  // 返回指向翻译好的英文句子存储地址（动态申请的数组空间地址）
}
// 翻译程序
char* robot::tran_int(int n)
{
	char* p;
	char kk[1000] = "";  // 存放翻译句子的中间结果
	if (n > 1999999999)
	{ 
		strcpy(kk, "Visual Studio平台无法处理太大的数！\n");  // cout<<"dev C++平台无法处理太大的数！"<<endl;
	}
	else
	{ 
		int a = n / 1000000000, b = (n % 1000000000) / 1000000, c = (n % 1000000) / 1000, d = n % 1000;  // 三位三位取出，存入abcd中
		//当abcd不等于0时，输出并加上billion ,million或thousand
		if (a != 0)
		{
			p = out(a);
			strcpy(kk, p);
			strcat(kk, "billion ");
			delete[] p;																						//释放在out函数中动态申请的空间
		}
		if (b != 0)
		{
			p = out(b);
			strcat(kk, p);
			strcat(kk, "million ");
			delete[] p;																						//释放在out函数中动态申请的空间
		}
		if (c != 0) {
			p = out(c);
			strcat(kk, p);
			strcat(kk, "thousand ");
			delete[] p;																						//释放在out函数中动态申请的空间
		}
		if (d != 0) { // 据英文语法规则，最后两位前一定有and
			if (d < 100 && (a != 0 || b != 0 || c != 0))
				strcat(kk, "and ");
			p = out(d);
			strcat(kk, p);
			delete[] p;																						//释放在out函数中动态申请的空间
		}
	} //end of if(n>1999999999) else
	p = new char[strlen(kk) + 1];																		// 动态申请的数组空间由p指针指向，存放翻译结果，没有释放，在上级调用函数中使用完后释放空间
	strcpy(p, kk);																			// 同时根据最大长度的数组kk实际所用到的数组空间定义p指针所指向的动态数组的大小
	return p;
}
void robot::print_num()
{
	cout << "整数为：" << num << endl;
	if (ps == NULL)  // 若指针为空，则不能直接输出
		cout << "zero" << endl;
	else
		cout << ps << endl;
}

// 翻译机器人调用入口函数
void Robot_Invoke()
{
	robot brown;
	brown.print_num();
	int n;
	cout << "请输入n：";
		cin >> n;
	brown.set("brown", "800#", n);
	brown.print_num();

}


void ObjectEntrance()
{
	//ClockInvoke();
	Fraction_Invoke();
	//Date_Invoke();
	//Students_Invoke();
	//Date1_Invoke();
	//Robot_Invoke();
}
