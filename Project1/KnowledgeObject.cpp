#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

#include "KnowledgeObject.h"


/*��Ķ��壬������ʹ��*/
/*====================================================================================================*/
// ʱ��չʾ��
class Clock
{
private:  // ˽�г�Ա������ı����ͺ��������ⲿ���ɷ��ʣ����ڱ����ڲ��ɷ���
	int Hour;
	int Minute;
	int Second;
	float Price;
public:  // ���г�Ա������ı����ͺ��������ⲿ�ɷ���
	void Set(int h, int m, int s, float p);  // �����޸�4�����ݳ�Ա��ֵ�ĺ���
	void Run();  // ģ������
	void Report_Time();  // ���㱨ʱ�������ⶨ��
	void Show_Time()  // �������� --> ��������ֱ�Ӷ���ĺ��������ʱ��
	{
		cout << Hour << ":" << Minute << ":" << Second;
	}
protected:  // ������Ա������ı����ͺ����ڱ��༰�̳����пɷ��ʣ����ⲿ���ɷ���

};

/*
�����ⶨ���Ա������<��������><����> :: <������>(<������>)
{
	<������>
}
*/ 
void Clock::Set(int h, int m, int s, float p)  // �����޸�4�����ݳ�Ա��ֵ�ĺ���
{
	Hour = h;
	Minute = m;
	Second = s;
	Price = p;
}
void Clock::Run()  // ģ������
{
	int i = 0;
	for (i = 0; i < 10; i++) {  //ֻģ������10����
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
		Sleep(1000);  //������ͣ1��
		cout << "\r                      \r";  //�����У����ص�ǰ�е���λ,ͬʱ���ÿո�����ͬ���в������ַ�
		Show_Time();
	}
	cout << endl;
}
void Clock::Report_Time()
{
	Show_Time();
	if (Minute == 0 && Second == 0)
	{
		for (int i = 0; i < Hour; i++)  // �����켸����0�㲻��
		{
			cout << "\007";
			Sleep(1000);
		}
	}
}
void ClockInvoke()
{
	Clock c1;  // ������һ��Clock��Ķ���
	c1.Set(3, 59, 50, 1000);  // ����ͨ�� . ������������еĳ�Ա����
	cout << "ģ���ӱ�ǰ��ʱ��Ϊ��" << endl;
	c1.Report_Time();
	c1.Run();
	c1.Report_Time();
	cout << endl;
}

// ����������
class Fraction
{
private:
	int divisor(int p, int q);  // �����Լ��
protected:
	int a;  // ���ӿ��Զ���Ϊ������Ա
	int b;  // ��ĸӦ�ö���Ϊ������Ա����ΪҪ��ֹ��ĸΪ0
public:
	void set(int aa, int bb);  // ���÷��ӷ�ĸ
	void show();  // ��ʾ����
	Fraction add(Fraction u);  // ��һ������
};
// ���÷��ӡ���ĸ
void Fraction::set(int aa, int bb)
{
	a = aa;
	if (bb != 0) // ��ĸ��Ч�Լ���
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
//������ӣ���������u
Fraction Fraction::add(Fraction u) {  // �������������	
	int tmp;
	Fraction v{};
	v.a = a * v.b + b * u.a;  // ����
	v.b = b * u.b;  // ��ĸ 
	tmp = divisor(v.a, v.b);  // ������ӡ���ĸ�Ĺ�Լ��
	v.a = v.a / tmp;  // Լȥ��Լ��
	v.b = v.b / tmp;  // Լȥ��Լ��
	return v;  // ���ؽ��
}
//���㹫Լ����˽�г�Ա
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
// Real��̳�Fraction��
class Real:public Fraction {
public:
	void show_real()
	{
		cout << a<<"/" << b << '=' << a / (double)b << endl;  // ��ʾ����
	}
};

void Fraction_Invoke()
{
	Real f1, f2;
	Fraction f3;
	int a, b, c, d;
	cout << "���Է��ӡ���ĸ��˳������������������" << endl;
	cin >> a >> b;
	cin >> c >> d;
	f1.set(a, b);
	f2.set(c, d);
	f1.show_real();
	f2.show_real();
	f3=f1.add(f2);   // �������������
	f3.show();
	cout << endl;
}


// ������
class Date {
private:
	int year, month, day;
	void SetSystemDate();  // ȡ��ϵͳ����
public:
	void init(int, int, int);  // ��������������
	void print_ymd();  // ��ʾ������
	void print_mdy();  // ��ʾ������
	int get_year() {return year;}  // �õ����ֵ
	int get_month() {return month;}  // �õ��·�ֵ
	int get_day() {return day;}  // �õ���ֵ
	bool IsLeapYear();  // �ж��Ƿ�Ϊ����
};

// ȡ��ϵͳ����
void Date::SetSystemDate()  
{
	tm* gm;  // tm��ʱ�䣨��������ʱ���룩�ṹ��
	time_t t = time(NULL);  // time t�ǳ����ͣ�t��ʾ����������
	gm = gmtime(&t);
	year = 1900 + gm->tm_year;
	month = gm->tm_mon + 1;
	day = gm->tm_mday;
}
// ���ڳ�ʼ��
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
	Date date1;  // ����һ����������󣬵�δ��ʼ��
	date1.print_ymd();  // ��ʾδ��ʼ�����ݵ����
	system("pause");
	date1.init(2022, 3, 28);  // ��ʼ�����ݳ�Ա
	date1.print_ymd();  // ����������ʾ����
	system("pause");
	Date date2;  // �ٴ���һ�����������
	date2.init(2023, 13, 28);  // ��ʼ���������������
	date2.print_mdy();  // ����������ʾ����
	system("pause");
	if (date1.IsLeapYear())  // �ж����꺯��
		cout << date1.get_year() << "������" << endl;
	else
		cout << date1.get_year() << "��������" << endl;
}

void ObjectEntrance()
{
	//ClockInvoke();
	//Fraction_Invoke();
	Date_Invoke();
}