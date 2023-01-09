#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeInherit.h"

using namespace std;

class person
{
protected:
	char* name; //人名,人名长度不确定，使用指针，存储时采用动态分配空间
	char sex; //性别
	char pid[19]; //身份证号码
	int weight; //体重
	int high; //身高
public:
	person() { cout << "调用person无参构造函数"; }; //无参构造函数
	person(char* n, char s, char* p, int w, int h); //有参构造函数
	void change_data(char* n, char s, char* p, int w, int h);//修改数据
	void walking(int k, int v); //以v速度行走k步
	void hearing(char* sentence); //模拟听，重复输入的内容
	void speaking(); //模拟说，唱歌
	void writing(); //在屏幕上画画
	void show(); //输出人的属性值
	~person() {
		delete[] name;
		cout << "调用person析构函数";
	}; //析构函数
};
// 构造函数定义
person::person(char* n, char s, char* p, int w, int h)
{
	change_data(n, s, p, w, h);
	cout << "调用person有参构造函数";
}
// 修改信息
void person::change_data(char* n, char s, char* p, int w, int h)
{
	char* pname = new char[strlen(n) + 1];  // 根据输入内容动态申请数组空间大小，+1是存储结束符'\0'
	strcpy(pname, n);  // 创建新的空间而不用原有的空间是为了保持数据独立性，防止外部数据破坏导致内部程序出错
	strcpy(this->pid, p);
	this->name = pname;  // 将类中名字指针指向申请的空间，不释放
	sex = s;
	weight = w;
	high = h;
}
// 模拟行走
void person::walking(int k, int v)
{
	cout << "\n" << name << "水平直线行走" << k << "步" << endl;
	for (int i = 0; i < k; i++){
		cout << ' ' << "o_o";
		Sleep(1000 / v);
		cout << "\b\b\b";
	}
	cout << endl;
}
// 模拟听
void person::hearing(char* sentence) 
{
	char* p = new char[strlen(sentence) + 1];  // 动态申请输入句子长度大小的数组空间
	strcpy(p, sentence);  // 拷贝数组内容
	char* pp = p;  // 指针变量pp指向动态数组空间
	cout << "I hear you! 你说的是：";
	cout << pp << endl;
	delete[] pp;  // 释放动态数组空间
}
// 模拟说
void person::speaking()
{
	int n = 4;
	cout << "正在唱歌..." << endl;
	for (int i = 0; i < n; i++) {
		Sleep(i * 1000);
		cout << "\007";
	}
}
// 模拟写
void person::writing() {
	int a=2;
	//cout << "please input A:";
	//cin >> a;                  //图案左边框离窗口左边界的距离值，可替换成任意常量，也可以忽略。
	cout << "正在画画..." << endl;
	for (int x = 0; x < 30; x++) {
		for (int y = 0; y < 60 + a; y++) {
			if (x == 0 || x == 29) { if (y < a)cout << " "; else cout << "*"; }
			else if (x == 1) { if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else cout << " "; }
			else if (x == 2) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 9 || y == a + 50)cout << "*";
				else if (y == a + 22 || y == a + 24 || y == a + 26 || y == a + 28 || y == a + 30 || y == a + 32 || y == a + 34 ||
					y == a + 36 || y == a + 38)cout << "*"; else cout << " ";
			}
			else if (x == 3) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == 8 + a || y == 10 + a)cout << "*";
				else if (y == 12 + a || y == 18 + a || y == a + 42 || y == a + 47 || y == a + 49 || y == a + 51)cout << "*"; else cout << " ";
			}
			else if (x == 4) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 8 || y == a + 11 || y == a + 15 || y == a + 45
					|| y == a + 48 || y == a + 51)cout << "*"; else cout << " ";
			}
			else if (x == 5) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 8 || y == a + 13 || y == a + 47 || y == a + 51)
					cout << "*"; else cout << " ";
			}
			else if (x == 6) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 8 || y == a + 51)
					cout << "*"; else cout << " ";
			}
			else if (x == 7) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 6
					|| y == a + 53)cout << "*"; else cout << " ";
			}
			else if (x == 8) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 5
					|| y == a + 54)cout << "*"; else cout << " ";
			}
			else if (x == 9) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 4
					|| y == a + 55)cout << "*"; else cout << " ";
			}
			else if (x == 10) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 3
					|| y == a + 56)cout << "*";
				else if (y >= a + 9 && y != a + 10 && y != a + 12 && y != a + 14 && y != a + 16 && y != a + 18 && y != a + 20 && y != a + 22 && y != a + 24 && y != a + 26 && y <= a + 27)cout << "*";
				else if (y >= a + 32 && y != a + 33 && y != a + 35 && y != a + 37 && y != a + 39 && y != a + 41 && y != a + 43 && y != a + 45 && y != a + 47 && y != a + 49 && y <= a + 50)cout << "*"; else cout << " ";
			}
			else if (x == 11) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 10 || y == a + 49 || y == a + 26 || y == a + 33)
					cout << "*"; else if (y >= a + 14 && y <= a + 17)cout << "*"; else if (y >= a + 42 &&
						y <= a + 45)cout << "*"; else cout << " ";
			}
			else if (x == 12) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 12 || y == a + 24 || y == a + 35 || y == a + 47)
					cout << "*"; else cout << " ";
			}
			else if (x == 13) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y >= a + 14 && y != a + 15 && y != a + 17 && y != a + 19 && y <= a + 20)cout << "*"; else if
					(y >= a + 39 && y != a + 40 && y != a + 42 && y != a + 44 && y <= a + 45)cout << "*"; else cout << " ";
			}
			else if (x == 14) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else cout << " ";
			}
			else if (x == 15) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 8 || y == 50 + a) cout << "*"; else cout << " ";
			}
			else if (x == 16) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 8 || y == 50 + a) cout << "*"; else cout << " ";
			}
			else if (x == 17) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 8 || y == 50 + a) cout << "*"; else cout << " ";
			}
			else if (x == 18) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 9 || y == 49 + a) cout << "*"; else cout << " ";
			}
			else if (x == 19) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 2
					|| y == a + 57)cout << "*"; else if (y == a + 10 || y == 48 + a) cout << "*"; else cout << " ";
			}
			else if (x == 20) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 3
					|| y == a + 56)cout << "*"; else if (y == a + 11 || y == 47 + a) cout << "*"; else cout << " ";
			}
			else if (x == 21) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 4
					|| y == a + 55)cout << "*"; else if (y == a + 13 || y == 45 + a) cout << "*"; else cout << " ";
			}
			else if (x == 22) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 5
					|| y == a + 54)cout << "*"; else if (y == a + 15 || y == 43 + a) cout << "*"; else cout << " ";
			}
			else if (x == 23) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 7
					|| y == a + 52)cout << "*"; else if (y == a + 17 || y == 41 + a) cout << "*"; else cout << " ";
			}
			else if (x == 24) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 10
					|| y == a + 49)cout << "*"; else if (y == a + 21 || y == a + 25 || y == a + 29 || y == a + 33 || y == a + 37)cout << "*"; else cout << " ";
			}
			else if (x == 25) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 13
					|| y == a + 46)cout << "*"; else cout << " ";
			}
			else if (x == 26) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if
					(y >= a + 17 && y != a + 18 && y != a + 20 && y != a + 22 && y != a + 24 && y != a + 26 &&
						y != a + 28 && y != a + 29 && y != a + 31 && y != a + 33 && y != a + 35 && y != a + 37 &&
						y != a + 39 && y != a + 41 && y <= 42 + a)cout << "*"; else cout << " ";
			}
			else if (x == 27) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 16
					|| y == a + 25 || y == a + 29 || y == a + 30 || y == a + 31 || y == a + 35 || y == a + 43)cout << "*"; else cout << " ";
			}
			else if (x == 28) {
				if (y < a)cout << " "; else if (y == a || y == 59 + a) cout << "$"; else if (y == a + 15
					|| y == a + 26 || y == a + 27 || y == a + 33 || y == a + 34 || y == a + 44)cout << "*"; else cout << " ";
			}

		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	system("pause");
}
// 输出信息
void person::show()
{
	cout << "姓名\t" << "性别\t" << "身份证号\t\t" << "体重\t" << "身高\t" << endl;
	cout << name << "\t" << sex << "\t" << pid << "\t" << weight << "\t" << high << endl;
}



// 派生与继承
/*
派生类（子类）的定义：
class 派生类名: 继承方式（访问权限） 基类（父类）名1, 继承方式 基类名2, …, 继承方式 基类名n
{
	派生类增加的成员声明；
};
继承方式为 public、protected、private ，用来指明基类成员在派生类中的最高访问权限（基类和派生类取交集，取最小）。
	+---------+-------------+--------------+-------------+
	| 派生方式 | 基类访问权限 | 派生类访问权限 | 外部函数调用 |
	+---------+-------------+--------------+-------------+
	|         |  public     |  public      |  可直接访问  |
	|         +-------------+--------------+-------------+
	| 公有继承 |  protected  |  protected   | 不可直接访问 |
	|         +-------------+--------------+-------------+
	|         |  private    | 不可直接访问  | 不可直接访问  |
	+---------+-------------+--------------+-------------+
	|         |  public     |  protected   | 不可直接访问 |
	|         +-------------+--------------+-------------+
	| 保护继承 |  protected  |  protected   | 不可直接访问 |
	|         +-------------+--------------+-------------+
	|         |  private    | 不可直接访问  | 不可直接访问  |
	+---------+-------------+--------------+-------------+
	|         |  public     |  private     | 不可直接访问 |
	|         +-------------+--------------+-------------+
	| 私有继承 |  protected  |  private     | 不可直接访问 |
	|         +-------------+--------------+-------------+
	|         |  private    | 不可直接访问  | 不可直接访问  |
	+---------+-------------+--------------+-------------+

1、从一个或多个以前定义的类(基类)产生新类的过程称为派生，新产生的类为派生类
2、类的继承（inheritance）是指新类从基类那里得到基类的特征，即继承基类的数据和函数
3、派生的新类同时也可以增加或重新定义数据和函数，即产生了类的层次性

派生类的变化：
1. 可以增加新的数据成员
2. 可以增加新的函数成员
3. 可以重新定义已有的函数成员
4. 可以改变现有成员的数据值
派生类的作用：
1. 从基类接受成员
2. 派生类对基类的扩充
3. 派生类对基类成员的改造
4. 系统的默认值就是私有继承
*/
class sing_star : public person
{
	float salary;  // 薪水
public:
	sing_star();  // 无参构造函数，构造函数不能继承，所以每个类都有构造函数
	sing_star(char* n, char s, char* p, int w, int h, float s1);  // 有参构造函数
	void change_data(char* n, char s, char* p, int w, int h, float s1);
	void show(); //输出人的属性值
	void playing();  // 演唱
	~sing_star()
	{
		// person::~person();  // 自动调用基类的析构函数，若手动调用则会报错
		cout << "调用sing_star析构函数";
	}
};
// 无参构造函数
sing_star::sing_star() :person()   // 调用基类构造函数设置共有字段，在函数体中设置独有字段
{
	salary = 0.0;  // 对派生类新增成员进行初始化
	cout << "调用sing_star无参构造函数";
}
// 有参构造函数
sing_star::sing_star(char* n, char s, char* p, int w, int h, float s1)
{
	person::change_data(n, s, p, w, h);  // 调用基类函数
	salary = s1;
	cout << "调用sing_star有参构造函数";
}
// 更新信息
void sing_star::change_data(char* n, char s, char* p, int w, int h, float s1)
{
	person::change_data(n, s, p, w, h);
	salary = s1;
}
void sing_star::show()
{
	cout << "姓名\t" << "性别\t" << "身份证号\t" << "体重\t" << "身高\t" << "薪水\t" << endl;
	cout << name << "\t" << sex << "\t" << pid << "\t\t" << weight << "\t" << high << "\t" << salary << endl;
}
void sing_star::playing()
{
	cout << "正在演唱..." << endl;
	cout << "演唱会已结束，下次早点来！";
}
// 继承测试函数调用
void PersonInvoke()
{
	char sentence[21];
	person laowang("王", 'M', "410527666666666666", 100, 175);
	laowang.show();
	cout << "请输入您想说的话：" << endl;
	cin >> sentence;
	laowang.hearing(sentence);
	laowang.speaking();
	laowang.writing();

	sing_star deng("邓紫棋", 'w', "C668669", 43, 157, 500000.5);  // 先调用基类的构造函数，再调用子类的构造函数
	deng.show();
	deng.walking(9,2);  // 调用基类中的函数实现以速度2行走9步
	deng.playing();
}

/*
派生类的构造函数与析构函数
派生类构造函数定义：
<派生类名::>派生类名(参数总表): 基类名1(参数表1)，…，基类名n(参数表n)，内嵌对象名1（对象参数表1），…，内嵌对象名m（对象参数表m）
{
		派生类新增加成员的初始化；
}

派生类构造函数的执行次序：
1、调用基类构造函数，调用顺序按照它们被继承时声明的基类名顺序执行。
2、调用内嵌对象构造函数，调用次序按各个对象在派生类内声明的顺序。
3、执行派生类构造函数体中的内容。
派生类析构函数的执行次序（与构造函数相反）：
1、执行派生类析构函数。
2、执行内嵌对象的析构函数。
3、执行基类析构函数。

派生类构造函数的调用规则：
	派生类构造函数可以自动调用基类的默认构造函数，但是前提是默认构造函数必须存在。
	通常情况下，默认构造函数系统会自动生成的，但是如果在基类中，我们自己定义了一个带参数的构造函数，这个时候，系统是不会为基类自动生成默认构造函数的，
	这个时候派生类则无法自动调用基类的默认构造函数了，因为基类根本就不存在默认构造函数。
	遇到这种情况有两种解决方案：其一，在基类中定义一个默认构造函数（不带参数的构造函数），
							 其二，派生类中的每一个构造函数都显式的调用基类中的带参构造函数。
	通常我们还会遇到这样一种情况，派生类中并未显式定义构造函数，这个时候派生类中只有系统自动生成的默认构造函数，
	如此一来，如果我们不为基类设计一个默认构造函数，则程序就会编译出错。

1、基类的构造函数只对基类的数据成员进行初始化，派生类的构造函数只对派生类新增的数据成员进行初始化，同时也会调用基类的构造函数。
2、用派生类建立一个对象时，执行构造函数的顺序是：先调用基类的构造函数，再执行派生类构造函数本身。
3、释放对象时，执行析构函数的顺序是：先调用子类的析构函数，再调用基类的析构函数。
4、！构造函数和析构函数不能被继承，但可以被调用 ！
*/
// 基类
class Person
{
	char* Name; //姓名
	int Age; //年龄
public:
	Person(char* name, int age)
	{
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
		Age = age;
		cout << "constructor of person" << Name << endl;
	}
	~Person() { cout << "deconstrutor of person" << Name << endl; delete[] Name;}
};
// 派生类
class Employee : public Person
{
	char* Dept;  // 工作地点
	Person Leader;  // 内嵌基类的对象
public:
	// 有参构造函数，调用基类的构造函数和派生类的内嵌对象（构造函数中 ：相当于{}，标明函数体，基类的构造函数由系统自动调用为什么还要手动调用，原因见上面知识点）
	Employee(char* name, int age, char* dept, char* name1, int age1) : Person(name, age), Leader(name1, age1)
	{
		Dept = new char[strlen(dept) + 1];
		strcpy(Dept, dept);
		cout << "constructor of Employee" << endl;
	}
	~Employee() { cout << "deconstrucor of Employee" << endl; delete[] Dept; }
}; 
// 派生类构造与析构函数测试调用
void Employee_Invoke()
{
	Employee emp("张弓长", 40, "人事处", "李木子", 36);
}


void InheritEntrance()
{
	//PersonInvoke();
	//Employee_Invoke();
}