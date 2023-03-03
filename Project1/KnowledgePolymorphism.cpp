#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeObject.h"

using namespace std;

#define PI 3.1415926  // 在虚函数总计算圆面积时使用

/*
多态性
一种语法格式，隐含了多种操作，即同一种函数或者操作符根据参数类型和数量不同实现不同的操作
多态实现了“一种接口，多种方法”
即将运算符重载，将函数重载，实现不同功能

多态两种形式：
1、编译时多态性
	编译器对源程序进行编译时就可以确定所调用的是哪一个函数
	编译时多态性通过重载来实现
	函数重载或运算符重载
2、运行时多态性（动态绑定）
	在程序运行过程中根据具体情况来确定调用的是哪一个函数
	运行时多态通过虚函数来实现（函数返回值前加 virtual）
*/

// 派生类对象替换基类对象
/*
一个替换原则：
	凡是基类对象出现的场合都可以用公有派生类对象取代
三个替换形式：
	1. 派生类对象给基类对象赋值（father f1; son s1; f1 = s1;）
	2. 派生类对象可以初始化基类对象的引用（father &f1 = s1;）
	3. 可以令基类对象的指针指向派生类对象，即将派生类对象的地址传递给基类指针（father* p1; p1 = &s1;）
*/

// 虚函数
/*
虚函数定义：在函数定义的头部加上virtual
virtual 函数返回类型 函数名（参数表）
{
	函数体
}
在某基类中声明为virtual并在一个或多个派生类中被重新定义的同名成员函数，称为虚函数。虚函数必须在类内声明，不能在类外声明

虚函数的用途：
	实现运行时的多态性，即通过指向派生类的基类指针，访问派生类中同名覆盖成员函数（实现运行时动态绑定，即同一指针运行过程中指向不同的函数）
注意：
1、通过指针或引用调用虚函数，可实现调用派生类函数，以对象名调用则调用基类的虚函数
2、在派生类中重定义的基类虚函数仍为虚函数，同时可以省略virtual关键字
3、不能定义虚构造函数，可以定义虚析构函数
PS：
若不加virtual关键字，则将派生类赋给基类的对象、引用、指针时均调用基类的成员变量和函数
*/

// 基类，普通电话
class mobile
{
public:
	mobile() {}
	char mynumber[11]; //机主的电话号码
	virtual void showinfo() //显示制式，虚函数，实现动态绑定
	{
		cout << "The phone is mobile，基类" << endl;
	}
};
// 派生类1，GSM型电话
class mobilegsm :public mobile
{
public:
	mobilegsm() {}
	virtual void showinfo() //显示制式
	{
		cout << "The phone is mobilegsm，派生类1" << endl;
	}
};
// 派生类2，CDMA型电话
class mobilecdma :public mobile
{
public:
	mobilecdma() {}
	virtual void showinfo() //显示制式
	{
		cout << "The phone is mobilecdma，派生类2" << endl;
	}
};
// 多态与虚函数测试函数调用
void mobile_Invoke()
{
	mobile m, * p1;  // 基类对象指针p1，基类对象m
	mobilegsm gsm;
	mobilecdma cdma;
	m = gsm;  // 用gsm类对象给mobile类对象赋值，以对象类型赋值，调用仍为基类函数
	m.showinfo();
	m = cdma;  // 用cdma类对象给mobile类对象赋值
	m.showinfo();
	p1 = &gsm;  // 用gsm类对象地址给mobile类对象赋值，以指针类型赋值，实现动态调用派生类函数
	p1->showinfo();
	p1 = &cdma;  // 用cdma类对象地址给mobile类对象赋值
	p1->showinfo();
	mobile& p4 = gsm;  // 以gsm类对象初始化mobile类引用，以引用类型赋值，实现动态调用派生类函数
	p4.showinfo();
	mobile& p5 = cdma;  // 以cdma类对象初始化mobile类引用
	p5.showinfo();
}

// 虚析构函数
/*

*/
// 基类
class Base
{
public:
	int x;
	virtual void f() { cout << "base class\n"; };
	virtual void show() { cout << "x=" << x << endl; };
	virtual ~Base() { cout << "destructor base class\n"; }  // 虚析构函数
															// 定义虚析构函数实现通过基类指针释放派生类对象空间
															// 在本例中，若基类构造函数不加virtual，因仅有delete p,p为基类指针，故当程序结束时仅调用基类析构函数，不会调用派生类的析构函数（认为没有创建派生类的对象），
															// 但在调用函数中创建的是派生类的对象空间，导致派生类对象空间未能释放
															// 实现虚析构函数后系统会调用实际指向的对象类析构函数
};
// 派生类
class Derived : public Base
{
public:
	int y;
	virtual void f() {
		cin >> y;
		cout << "Derived class\n";
	}
	virtual void show() { Base::show(); cout << "y=" << y << endl; }
	~Derived() { cout << "destructor derived class\n"; }
};
void Derived_Invoke()
{
	Base* p;  // 创建基类指针
	p = new Derived;  // 动态申请对象空间，基类指针指向派生类，基类函数为虚函数，以下调用的函数均为该指针指向的派生类的函数
	cin >> p->x;  // 输入x
	p->f();  // 输入y
	p->show();
	delete p;

}

// 抽象类
/*
类是对象的集合，类是从相似对象中抽取共性而得到的抽象数据类型
将不用来声明对象(实例化)的类称为抽象类。只供继承

纯虚函数的定义:
virtual 返回类型 函数名（参数表）=0
纯虚数的具体实现只能在派生类中完成

抽象类又可以定义成:至少包含一个纯虚函数的类

抽象类的使用要求：
1、抽象类不能实例化，即不声明对象
2、抽象类只作为基类被继承
3、可以定义抽象类的指针或引用

*/

// 抽象基类
class Shape
{
public:
	// 纯虚函数
	virtual double area() = 0;  // 计算面积
	virtual double circumference() = 0;  // 计算周长
};
// 派生类1，矩形
class Rectangl : public Shape  // 继承抽象类
{ 
	int x,y;
	int width,hight;
public:
	Rectangl(int x,int y,int w,int h) 
	{
		this->x = x; 
		this->y = y; 
		width = w; 
		hight = h;
	}
	virtual double area() 
	{
		return width * hight;
	}
	virtual double circumference() 
	{
		return 2.0 * (width + hight);
	}
};
// 派生类1，圆形
class Circle :public Shape  // 继承抽象类
{
	int x, y;
	double r;
public:
	Circle(int x, int y, int r) 
	{
		this->x = x; 
		this->y = y; 
		this->r = r;
	}
	virtual double area() {
		return PI * r * r;
	}
	virtual double circumference() { return 2.0 * PI * r; }
};
// 抽象类测试函数调用
void Shape_Invoke()
{
	Rectangl r1(10, 10, 10, 5.0);
	Circle c1(1, 2, 1);
	Shape* p1 = &r1;  // 定义抽象类的指针赋值
	Shape& p2 = c1;  // 定义抽象类的引用赋值
	cout << "长方形面积：" << p1->area() << endl;  // 通过基类指针调用派生类1的成员函数
	cout << "长方形周长：" << p1->circumference() << endl;
	cout << "圆面积：" << p2.area() << endl;  // 通过基类引用调用派生类2的成员函数
	cout << "圆周长：" << p2.circumference() << endl;
}

// 运算符重载
/*
运算符重载指赋予运算符新的操作功能，主要用于对类的对象的操作
运算符重载定义：
<返回类型> <类名>::operator <操作符>(<参数表>)
{
	函数体
}
双目运算符的重载：x + y <--> x.(+)(y)
*/

/*
C++运算符重载的相关规定如下：

 1.不能改变运算符的优先级。
 2.不能改变运算符的结合性。
 3.默认参数不能和重载的运算符一起使用，也就是说，在设计运算符重载成员函数时不能使用默认函数。
 4.不能改变运算符的操作数的个数。
 5.不能创建新的运算符，只有已有运算符可以被重载
 6.运算符作用于C++内部提供的数据类型时，原来含义保持不变
 
 并不是所有运算符都可以重载

*/

// 利用运算符重载实现复数的运算和判等
// 复数类
class Complex
{
private:
	double real, imag;  // 实部，虚部
	static Complex temp;  // 静态类对象，使用静态类对象而不在成员函数内定义临时对象节省了调用构造函数和析构函数的时间，提高效率
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) { }  // 构造函数
	double Real() { return real; }  // 获得实部
	double Imag() { return imag; }  // 获得虚部
	void print();
	Complex operator +(Complex);  // 虚数加法，+重载
	Complex operator +(double);  // 虚数加实数，+重载
	bool operator ==(Complex);  // 判等，==重载
	Complex operator ++();  // 单目运算符 x++ 重载
	Complex operator ++(int);  // 单目运算符 ++x 重载
	~Complex() { };  // 析构函数
};
Complex Complex::temp;  // 静态类对象

// C++不可以在类中定义该类的对象
/*
创建一个对象A a1，a1里面又有对象a，这个对象里面还有一个对象。这样一直创建下去，直到内存耗尽，出现栈溢出。

可以在类中定义该类的静态对象、该对象的指针或者引用。
	因为静态的成员不在对象的内部，在data区，被这个类共享。所以不会出现递归创建。
*/

// 重载运算符 ＋，两边是虚数对象
Complex Complex::operator + (Complex c) 
{
	//Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}
// 重载运算符＋，左边是虚数对象，右边是双精度数
Complex Complex::operator + (double d) 
{
	//Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}
// 重载运算符==
bool Complex::operator ==(Complex c) 
{
	if (real == c.real && imag == c.imag)
		return true;
	else
		return false;
}
// 前置++运算符定义，先+1后输出
Complex Complex::operator ++ ()
{
	real += 1;
	return *this;
}
// 后置++运算符定义，先输出后+1
Complex Complex::operator ++ (int)
{
	//Complex 
	temp = *this;
	++real;  // 利用前置实现后置，减少代码重复
	return temp;
}
/*
单目运算符重载知识点：

1、形参的区别及原因
	前置++没有形参，而后置++有一个int形参，但是该形参也没有被用到。其目的只是为了绕过语法的限制。
	前置++与后置++的操作符重载函数，函数原型必须不同。否则就违反了“重载函数必须拥有不同的函数原型”的语法规定。
	虽然前置++与后置++的返回类型不同，但是返回类型不属于函数原型。为了绕过语法限制，只好给后置++增加了一个int形参。
2、代码实现的区别
	前置++的实现比较简单，自增之后，将*this返回即可。需要注意的是，一定要返回*this。
	后置++的实现稍微麻烦一些。因为要返回自增之前的对象，所以先将对象拷贝一份，再进行自增，最后返回那个拷贝。
3、效率的区别
	如果不需要返回自增之前的值，那么前置++和后置++的计算效果都一样。但是，我们仍然应该优先使用前置++，尤其是对于用户自定义类型的自增操作。
	前置++的效率更高，理由是：后置++会生成临时对象。
	很明显，tmp是一个临时对象，会造成一次构造函数和一次析构函数的额外开销。虽然，编译器在某些情况下可以优化掉这些开销。但是，我们最好不要依赖编译器的行为。
	所以，在非内置类型的时候，尽量使用前置++，因为效率高（后置自增，效率低）
*/


// 打印输出结果
void Complex::print()
{
	cout << real << "+" << imag << "i";
	cout << endl;
}
// 运算符重载测试函数调用
void Complex_Invoke()
{
	Complex c1(3, 4), c2(5, 6), c3;  // 创建三个复数对象
	cout << "C1 = ";
	c1.print();
	cout << "C2 = ";
	c2.print();
	c3 = c1 + c2;  // 使用重载运算符 + 实现两个虚数的加法
	cout << "C3 = ";
	c3.print();
	c3 = c3 + 6.5;  // 使用重载运算符 + 实现虚数和实数的加法
	cout << "C3 + 6.5 = ";
	c3.print();
	if (c1 == c2)  // 使用重载运算符 == 判两个虚数是否相等
		cout << "两个复数相等" << endl;
	else
		cout << "两个复数不相等" << endl;

	c3 = c1++;  // 后置
	c3.print();
	c3 = ++c1;  // 前置
	c3.print();
}
 // 深拷贝与浅拷贝
/*
浅拷贝（shallowcopy）
	只复制直接成员变量的值
深拷贝（deepcopy）
	同时复制资源 （如指针指向的空间）
浅接贝的运算
	赋值运算符（=）、系统默认的拷贝构造函数实现的都是浅拷贝
实现深接贝
	自定义一个成员函数
	重载拷贝构造函数（也叫复制构造函数）
	重载赋值运算符
*/

void PolymorphismEntrance()
{
	//mobile_Invoke();
	//Shape_Invoke();
	Complex_Invoke();
	//Derived_Invoke();
}
