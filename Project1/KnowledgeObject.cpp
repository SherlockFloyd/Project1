#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeObject.h"

using namespace std;


/*��Ķ��壬������ʹ��*/
/*====================================================================================================*/
// ʱ��չʾ��
class Clock
{
private:  // ˽�г�Ա������ı����ͺ��������ⲿ���ɷ��ʣ����ڱ����ڲ��ɷ���(��д��Ա���͵ı���������Ĭ��Ϊ˽��)
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
	Fraction(){}  // ��û�й��캯����ʹ��δ��ʼ���Ķ���ʱ�ᱨ������ʱδ��ʼ�������д洢���ǲ�ȷ�������ֵ������ֱ������ʹ�ã���Ҫ����
	void set(int aa, int bb);  // ���÷��ӷ�ĸ
	void show();  // ��ʾ����
	Fraction add(Fraction u);  // ��һ������
	Fraction add_pro(Fraction u);  // thisָ����Ժ�����������thisָ��֪ʶ�㴦
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
Fraction Fraction::add(Fraction u) {
	int tmp;
	Fraction v;
	v.a = a * u.b + b * u.a;  // ����
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
	cout << "���������" << endl;
	f1.show_real();
	f2.show_real();
	f3=f1.add(f2); 
	cout << "��ͽ��" << endl;
	f3.show();
	cout << endl;

	f3 = f1.add_pro(f2);  // ����f1����Ķ���ռ�洢�������������´����м����ͨ��thisָ�����
	f1.show();
	f3.show();
	cout << "��ʱf1��f3ֵ��ͬ��ͨ��thisָ�����ñ���Ĵ洢�ռ����Ľ�����ƻ��Ե�" << endl;
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


/*��ķ�װ�����ء�������this��ָ��*/
/*====================================================================================================*/
/*
���캯��(Constructor) --> ͨ���������Ա�����ĳ�ʼ��
�﷨��ʽ��
��������(<������>)
{
	�������塵
}
ע�����
���캯���ĺ�����������������ͬ
���캯��û�з���ֵ
�书���ǽ������е��������ݳ�Ա���г�ʼ����һ����һϵ�и�ֵ��乹��
��ϵͳ����������ʱ�Զ�����


��������(Destructor) --> �ڶ��󱻳���ʱ(ǰ)ִ�У�������ɶ��󱻳���ǰ��һЩ������
�������������������ͷš���Դ������
���ڹ��캯���ж�̬������ڴ�ռ䣬Ҳ���Ա�����ִ�С��û�ϣ�������һ��ʹ�ö���֮����ִ�е��κβ�������������й���Ϣ��
�﷨��ʽ��
~<����>()
{
	<������>
}
ע�����
�������ǣ�����ǰ���"~"����
�����������÷����κ�ֵ
�����������ô����κβ���
����Ҫ�������ڳ�������֮ǰ����һЩ�ƺ�����

���캯���������������ɶ����ں������ⲿ����ʽ����ͨ����������ͬ��<����>::<������> �����޷���ֵ��
				������public���Σ��������ⲿ��ϵͳ����
*/
// ������,�����캯��
class Date1 {
private:
	int year, month, day;
public:
	// ��û�й��캯����ʹ��δ��ʼ���Ķ���ʱ�ᱨ���й��캯����ϵͳ�Զ����ù��캯�������ᱨ��
	// ���캯�����������Ա�����ĳ�ʼ�����������еı����ɸ���ֵҲ�ɲ�����ֵ����ֵ��ֵ���غ�������ֵ�����޳�ֵ�ı�����ǰ����ֵ�����ں�
	Date1(int y , int m = 1, int d = 1) 
	{
		year = y;
		month = m;
		day = d;
	}
	// ���캯�������أ����ݲ������еı������ͼ������Զ�ѡ���캯��
	Date1()
	{
		year = 2023;
		month = 2;
		day = 2;
		char* pd;
	}
	/*���캯����ʼ����4�ַ���
	1.�ڹ��캯���ĺ������н��г�ʼ��
		Date (Date &d){year=d.year;month=d.month;day=d.day;}
	2.�ڹ��캯����ͷ����ʼ��
		���캯����(������):����1(��ֵ1)��������n(��ֵn){��}
		Date():year(1900),month(1),day(1){}
	3.ʹ��Ĭ�ϲ�����ʼ��
		Date(char y[],int m = 1,int d = 1)
		{
			year = atoi(y);
			month = m;
			day = d;
		}
	3.��ϳ�ʼ����2��3��ʽ���
		Date(int y,int m,int d):year(y),month(m){day=d;}
	*/
	Date1(Date1& date) :year(date.year), month(date.month), day(date.day) {}  // ����������캯��
	//Date1() :year(2023), month(3), day(3) {}  // �޲ι��캯����������ڶ��ַ���һ�������߲��ܹ��棩
												// Ĭ�ϲ������캯���������һ��
	// ��ϳ�ʼ��������ͨ���޲ι��캯������ֵ��ͬʱͨ��ָ�����ڵ��ַ����ں������и�ֵ��û�о�������ı�����Ϊ�޲κ����ĳ�ֵ
	Date1(char* ps) :year(2023), month(1), day(9)
	{
		char py[5], pm[3];
		pd = new char[3];  // ʹ�ö�̬���飬������������
		strncpy(py, ps, 4);
		ps = ps + 5;
		strncpy(pm, ps, 2);
		ps = ps + 3;
		strncpy(pd, ps, 2);
		year = atoi(py);  // �����ָ�ʽ���ַ���ת��Ϊ��������
		month = atoi(pm);
		//day = atoi(pd);  // ʹ��Ĭ�ϲ�������
	}

	// �����������޲������޷���ֵ�����������޲��������䲻�����أ�ֻ����һ�����ڶ����������ڽ��������ú������ػ�������delete����������ʱ��ϵͳ�Զ�����
	~Date1() 
	{
		delete[] pd;
		delete pn;
		delete[] pd;
		cout << "������ʱ��" << endl;
	}

	int* pn = new int;  // ������������ʹ��
	char* pd = new char[3];  // ������������ʹ��
	void init(int, int, int);  // ��������������
	int get_year() { return year; }  // �õ����ֵ
	int get_month() { return month; }  // �õ��·�ֵ
	int get_day() { return day; }  // �õ���ֵ
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
	����Ĵ洢�ռ䣺
	ÿ�������еĳ�Ա���������洢��������ͬ��Ķ�����ͬһ��Ա�����Ĵ洢�ռ�
	*/
	// ���й��캯��������ڴ�������ʱ���г�ʼ�����Զ����ù��캯�����г�ʼ��
	Date1 date1(2023, 2, 3);  // ����һ����������󣬲���ʼ��
	Date1 date2;  // �����޲ι��캯�����г�ʼ��
	Date1 date3(date2);  // ���ö���������캯��
	char date[11] = "2023-04-04";
	Date1 date4(date);  // ���û�ϳ�ʼ�����캯��

	cout << date1.get_month();
	cout << date2.get_month();
	cout << date3.get_month();
	cout << date4.get_month();
	 
}

// ��Ķ�����ָ��
/*
1��ָ������ָ�룺����* ָ���������;
	����
	Person person1("Zhang3",19,'f');
	Person *ptr=&Person1;
	ptr->Show();
2����̬�洢������ָ�� = new ����(���ֳ�ʼ��ֵ��
			delete ����ָ�룻
	����Person* p=new Person;
		delete p;



-> �� . ��ʹ��
1��ջ���
������ڶ��ϣ�ϵͳ�Զ���������գ�����Ҫ��ָ�룬Ҳ���� ����ָ��->����;
	����ջ�ϣ���̬��������գ�����Ҫ�� ����.����;
Ϊ��ȷ��������ȼ���һ���ڼ����ţ��磺(*this).function
2��ָ�������
�����ָ��������ݳ�Ա���Ա�������� -> ;
�����ĳ���������͵Ķ��󣬷����Լ������ݳ�Ա�ͳ�Ա������ . ;
*/
class Date3 {
public:
	int year, month, day;
	Date3() :year(2023), month(1), day(1){};  // ���캯��
	void init(int, int, int);  // ��������������
	void print_ymd();  // ��ʾ������
	~Date3(){};  // ��������
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
	Date3 date1;  // ����Date3�Ķ���
	Date3* p1 = &date1;  // ����ָ������ָ��
	Date3 date2;
	p1->print_ymd();
	p1->init(2023, 2, 2);  // ����ָ��ͨ�� -> �����������Ա�ͺ�����Ա
	date2.init(2023, 2, 3);  // ����ͨ�� . �����������Ա�ͺ�����Ա
	p1->print_ymd();
	date2.print_ymd();

	int* p2 = &date1.year;  // �ȼ��� int* p2 = &(date1.year) ��p2��ָ��date1�г�Ա����year��ָ��
	int year2 = p1->year;  // ָ������ָ���� ->
	cout << *p2 << year2 << endl;

	void(Date3:: * p3)(int, int, int);  // ָ�����Ա������ָ�룬����Knowledge.cpp�к���ָ��Ľ�������ͨ����ָ�붨�岻ͬ���� Date3:: * p3 д������ΪDate3���е�ָ��
	void (Date3:: * p4)();  // ָ�����Ա������ָ��
	p3 = &Date3::init;  // p3�ȼ���Date3�е�init������p3Ϊָ�����ͣ�Ӧȡ��Ա������ַ��ֵ
	p4 = &Date3::print_ymd;  // p4�ȼ���Date3�е�print_ymd����
	(date1.*p3)(2023, 4, 8);  // �ȼ��� date1->p3 ������init����
	(date1.*p4)();  // ����print_ymd����

	Date3* p5 = new Date3;  // ��̬�������ָ��
	delete p5;
}

/*
thisָ��
ÿһ����ĳ�Ա����������һ��ָ��������ָ��
ָ����Ϊthis
��ָ��ָ����������ʼ��ַ
���������ݳ�Ա�����Ա���е��β�����ͬʱ����thisָ���������
*/
class Text
{
	int x;  // �޷��ʿ��Ʒ���Ĭ��˽��
public:
	Text(int = 0);  // ���캯������������ֵʱĬ�ϸ�ֵΪ0��������ֵʱʹ������ֵ
	void print();
};
Text::Text(int x)  // ���캯������
{
	this->x = x;  // ʹ��this���־ֲ����������Ա����
}
void Text::print()
{
	int x = 12138;
	cout << "x\t��ֵΪ��" << x << endl;  // ���ʾֲ�����x��ֵΪ�ֲ�������ֵ
	cout << "this->x\t��ֵΪ��" << x << endl;  // �������Ա����
	cout << "(*this).x\t��ֵΪ��" << x << endl;  // // �������Ա������this->x �ȼ��� (*this).x
}
// thisָ���Ϸ����ӷ�������ʹ��ԭ����Ķ�����м��㣬����ԭ����ֵ���ƻ���ԭ��ֵ
Fraction Fraction :: add_pro(Fraction u)
{
	int tmp;
	//Fraction v;
	a = a * u.b + b * u.a;  // �ñ������洢���������ƻ���
	b = b * u.b;  // ��ĸ
	tmp = divisor(a, b);  // ������ӡ���ĸ�Ĺ�Լ��
	a = a / tmp;  // Լȥ��Լ��
	b = b / tmp;  // Լȥ��Լ��
	return *this;  // ���ؽ��,����ԭ���Ķ���
}



/*ѧ���ࣺʵ����ϰ*/
/*====================================================================================================*/
class Students
{
private:
	int ID;  // ѧ��
	char Name[20];  // ����
	char Sex[5];  // �Ա�
	double DBGrade;  // ���ݽṹ�ɼ�
	double NWGrade;  // ���������ɼ�
	double PCCGrade;  // ��������ԭ��ɼ�
	double OSGrade;  // ����ϵͳ�ɼ�
	double TotalGrade;  // �ܳɼ�
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
	cout << "ѧ��\t" << "����\t" << "�Ա�\t" << "DB�ɼ�\t" << "NW�ɼ�\t" << "PC�ɼ�\t" << "OS�ɼ�\t" << "�ܳɼ�\t" << endl;
	cout << ID << "\t" << Name << "\t" << Sex << "\t" << DBGrade << "\t" << NWGrade << "\t" << PCCGrade << "\t" << OSGrade << "\t" << TotalGrade << "\t" << endl;
}

void Students_Invoke()
{
	const int COUNT = 5;  // ѧ������
	int n;
	int id;
	char name[20], sex[5];
	double db, nw, pcc, os;
	cout << "������ѧ��������" << endl;
	cin >> n;
	//Students S[COUNT];
	Students* S = new Students[n];

	for (int i = 0; i < n; i++) {
		cout << "�밴�����¸�ʽ�����"<<i+1<<"��ѧ������Ϣ��" << endl;
		cout << "ѧ��\t" << "����\t" << "�Ա�\t" << "DB�ɼ�\t" << "NW�ɼ�\t" << "PC�ɼ�\t" << "OS�ɼ�\t" << endl;
		cin >> id >> name >> sex >> db >> nw >> pcc >> os;
		S[i].Set_info(id, name, sex, db, nw, pcc, os);
	}
	for (int i = 0; i < n; i++)
		S[i].Show();

	delete[] S;
}


// ���ַ����Ӣ�ģ���̬���鼰����������ϰ��
//��������ȫ���ַ�ָ�����飬��ȡ����ĵ���
//num1��Ϊ�����ճ��ˣ����Կ���ֱ����num1[n]���ã��õ�n��Ӧ����
static char* num1[] = {
	"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten","eleven","twelve",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen"
};
//num10��Ϊ-90���ճ��˺ͣ����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
static char* num10[] = {
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety"
};
class robot
{
	char name[20]; //����������
	char type[20]; //�������ͺ�
	int num; //�����������
	char* ps; //ָ��Ӣ���ַ���
public:
	robot()//���캯��
	{
		strcpy(name, "XXXXXX");
		strcpy(type, "XXXXXX");
		num = 0;
		ps = new char[5];  // psָ���Ѿ�����õ�Ӣ�ľ���
		strcpy(ps, "zero");
	}
	void set(char n[], char t[], int m); //�����޸�����
	char* out(int a);//Ӣ����ÿ��λ��������ͬ�����Զ���out��������С��1000������
	char* tran_int(int n);//��1��1999999999�����������Ӣ�ľ���
	void print_num();//�����������Ӣ�ľ���
	~robot()   //�������� �ͷŹ��캯����set�����ж�̬����Ŀռ�
	{ 
		cout << "������" << strlen(ps) + 1 << "���ֽڿռ䱻�ͷŻ���" << endl;
		delete[] ps;																						// �ͷŹ��캯�����������ʱ�ַ��Ͷ�̬����
	}; 
};
//�����޸����� 
void robot::set(char n[], char t[], int m) 
{
	strcpy(name, n);
	strcpy(type, t);
	if (num == m) //�����������û�б䣨���ǳ�ʼ��ʱ��ĳ�ֵ0��
		return;
	else {
		num = m;
		delete[] ps; //ɾ�����е�Ӣ�ľ���
	}
	if (num > 0) {
		char* tp = tran_int(num);
		ps = new char[strlen(tp) + 1];																	//  �����캯����������psָ��ָ��̬���������ռ䣬����Ϊ�������Ĵ�ֵָ�룬����������������ͷ�
		strcpy(ps, tp);
		delete[] tp;																						//  �ͷ���trans_int�ж�̬����Ŀռ�
	}
	else {
		ps = new char[13];
		strcpy(ps, "�������ܷ���");
	}
}
//Ӣ����ÿ��λ��������ͬ�����Զ���out������ÿ����λ�����д���
char* robot::out(int a)
{
	char k[1000] = "";  // ��ŷ�����ӵ��м���
	int b = a % 100;
	//����λ��Ϊ�㣬�����λ����hundred������ʱʮλ��λ��Ϊ������and
	if (a / 100 != 0) {
		strcat(k, num1[a / 100]);
		strcat(k, "hundred ");
		if (b != 0)
			strcat(k, "and ");
	}
	//������λ������ʱ��ֱ�ӵ���num1[n]�����
	if (b < 20)
		strcat(k, num1[b]);
	//������λ����ʱ
	else { //�ȵ���num10�����ʮλ��
		strcat(k, num10[b / 10]);
		//��λ��ΪʱӦ���"-"��λ��
			if (b % 10 != 0) {
				strcat(k, "\b- ");
				strcat(k, num1[b % 10]);
			}
	}
	char* p = new char[strlen(k) + 1];																	// ��̬���������ռ���pָ��ָ�򣬴�ŷ�������û���ͷţ����ϼ����ú�����ʹ������ͷſռ�  
	strcpy(p, k);
	return p;  // ����ָ����õ�Ӣ�ľ��Ӵ洢��ַ����̬���������ռ��ַ��
}
// �������
char* robot::tran_int(int n)
{
	char* p;
	char kk[1000] = "";  // ��ŷ�����ӵ��м���
	if (n > 1999999999)
	{ 
		strcpy(kk, "Visual Studioƽ̨�޷�����̫�������\n");  // cout<<"dev C++ƽ̨�޷�����̫�������"<<endl;
	}
	else
	{ 
		int a = n / 1000000000, b = (n % 1000000000) / 1000000, c = (n % 1000000) / 1000, d = n % 1000;  // ��λ��λȡ��������abcd��
		//��abcd������0ʱ�����������billion ,million��thousand
		if (a != 0)
		{
			p = out(a);
			strcpy(kk, p);
			strcat(kk, "billion ");
			delete[] p;																						//�ͷ���out�����ж�̬����Ŀռ�
		}
		if (b != 0)
		{
			p = out(b);
			strcat(kk, p);
			strcat(kk, "million ");
			delete[] p;																						//�ͷ���out�����ж�̬����Ŀռ�
		}
		if (c != 0) {
			p = out(c);
			strcat(kk, p);
			strcat(kk, "thousand ");
			delete[] p;																						//�ͷ���out�����ж�̬����Ŀռ�
		}
		if (d != 0) { // ��Ӣ���﷨���������λǰһ����and
			if (d < 100 && (a != 0 || b != 0 || c != 0))
				strcat(kk, "and ");
			p = out(d);
			strcat(kk, p);
			delete[] p;																						//�ͷ���out�����ж�̬����Ŀռ�
		}
	} //end of if(n>1999999999) else
	p = new char[strlen(kk) + 1];																		// ��̬���������ռ���pָ��ָ�򣬴�ŷ�������û���ͷţ����ϼ����ú�����ʹ������ͷſռ�
	strcpy(p, kk);																			// ͬʱ������󳤶ȵ�����kkʵ�����õ�������ռ䶨��pָ����ָ��Ķ�̬����Ĵ�С
	return p;
}
void robot::print_num()
{
	cout << "����Ϊ��" << num << endl;
	if (ps == NULL)  // ��ָ��Ϊ�գ�����ֱ�����
		cout << "zero" << endl;
	else
		cout << ps << endl;
}

// ��������˵�����ں���
void Robot_Invoke()
{
	robot brown;
	brown.print_num();
	int n;
	cout << "������n��";
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