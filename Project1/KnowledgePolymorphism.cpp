#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeObject.h"

using namespace std;

#define PI 3.1415926  // ���麯���ܼ���Բ���ʱʹ��

/*
��̬��
һ���﷨��ʽ�������˶��ֲ�������ͬһ�ֺ������߲��������ݲ������ͺ�������ͬʵ�ֲ�ͬ�Ĳ���
��̬ʵ���ˡ�һ�ֽӿڣ����ַ�����
������������أ����������أ�ʵ�ֲ�ͬ����

��̬������ʽ��
1������ʱ��̬��
	��������Դ������б���ʱ�Ϳ���ȷ�������õ�����һ������
	����ʱ��̬��ͨ��������ʵ��
	�������ػ����������
2������ʱ��̬�ԣ���̬�󶨣�
	�ڳ������й����и��ݾ��������ȷ�����õ�����һ������
	����ʱ��̬ͨ���麯����ʵ�֣���������ֵǰ�� virtual��
*/

// ����������滻�������
/*
һ���滻ԭ��
	���ǻ��������ֵĳ��϶������ù������������ȡ��
�����滻��ʽ��
	1. �����������������ֵ��father f1; son s1; f1 = s1;��
	2. �����������Գ�ʼ�������������ã�father &f1 = s1;��
	3. �������������ָ��ָ����������󣬼������������ĵ�ַ���ݸ�����ָ�루father* p1; p1 = &s1;��
*/

// �麯��
/*
�麯�����壺�ں��������ͷ������virtual
virtual ������������ ��������������
{
	������
}
��ĳ����������Ϊvirtual����һ�������������б����¶����ͬ����Ա��������Ϊ�麯�����麯��������������������������������

�麯������;��
	ʵ������ʱ�Ķ�̬�ԣ���ͨ��ָ��������Ļ���ָ�룬������������ͬ�����ǳ�Ա������ʵ������ʱ��̬�󶨣���ͬһָ�����й�����ָ��ͬ�ĺ�����
ע�⣺
1��ͨ��ָ������õ����麯������ʵ�ֵ��������ຯ�����Զ�������������û�����麯��
2�������������ض���Ļ����麯����Ϊ�麯����ͬʱ����ʡ��virtual�ؼ���
3�����ܶ����鹹�캯�������Զ�������������
PS��
������virtual�ؼ��֣��������ำ������Ķ������á�ָ��ʱ�����û���ĳ�Ա�����ͺ���
*/

// ���࣬��ͨ�绰
class mobile
{
public:
	mobile() {}
	char mynumber[11]; //�����ĵ绰����
	virtual void showinfo() //��ʾ��ʽ���麯����ʵ�ֶ�̬��
	{
		cout << "The phone is mobile������" << endl;
	}
};
// ������1��GSM�͵绰
class mobilegsm :public mobile
{
public:
	mobilegsm() {}
	virtual void showinfo() //��ʾ��ʽ
	{
		cout << "The phone is mobilegsm��������1" << endl;
	}
};
// ������2��CDMA�͵绰
class mobilecdma :public mobile
{
public:
	mobilecdma() {}
	virtual void showinfo() //��ʾ��ʽ
	{
		cout << "The phone is mobilecdma��������2" << endl;
	}
};
// ��̬���麯�����Ժ�������
void mobile_Invoke()
{
	mobile m, * p1;  // �������ָ��p1���������m
	mobilegsm gsm;
	mobilecdma cdma;
	m = gsm;  // ��gsm������mobile�����ֵ���Զ������͸�ֵ��������Ϊ���ຯ��
	m.showinfo();
	m = cdma;  // ��cdma������mobile�����ֵ
	m.showinfo();
	p1 = &gsm;  // ��gsm������ַ��mobile�����ֵ����ָ�����͸�ֵ��ʵ�ֶ�̬���������ຯ��
	p1->showinfo();
	p1 = &cdma;  // ��cdma������ַ��mobile�����ֵ
	p1->showinfo();
	mobile& p4 = gsm;  // ��gsm������ʼ��mobile�����ã����������͸�ֵ��ʵ�ֶ�̬���������ຯ��
	p4.showinfo();
	mobile& p5 = cdma;  // ��cdma������ʼ��mobile������
	p5.showinfo();
}

// ����������
/*

*/
// ����
class Base
{
public:
	int x;
	virtual void f() { cout << "base class\n"; };
	virtual void show() { cout << "x=" << x << endl; };
	virtual ~Base() { cout << "destructor base class\n"; }  // ����������
															// ��������������ʵ��ͨ������ָ���ͷ����������ռ�
															// �ڱ����У������๹�캯������virtual�������delete p,pΪ����ָ�룬�ʵ��������ʱ�����û���������������������������������������Ϊû�д���������Ķ��󣩣�
															// ���ڵ��ú����д�������������Ķ���ռ䣬�������������ռ�δ���ͷ�
															// ʵ��������������ϵͳ�����ʵ��ָ��Ķ�������������
};
// ������
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
	Base* p;  // ��������ָ��
	p = new Derived;  // ��̬�������ռ䣬����ָ��ָ�������࣬���ຯ��Ϊ�麯�������µ��õĺ�����Ϊ��ָ��ָ���������ĺ���
	cin >> p->x;  // ����x
	p->f();  // ����y
	p->show();
	delete p;

}

// ������
/*
���Ƕ���ļ��ϣ����Ǵ����ƶ����г�ȡ���Զ��õ��ĳ�����������
����������������(ʵ����)�����Ϊ�����ࡣֻ���̳�

���麯���Ķ���:
virtual �������� ��������������=0
�������ľ���ʵ��ֻ���������������

�������ֿ��Զ����:���ٰ���һ�����麯������

�������ʹ��Ҫ��
1�������಻��ʵ������������������
2��������ֻ��Ϊ���౻�̳�
3�����Զ���������ָ�������

*/

// �������
class Shape
{
public:
	// ���麯��
	virtual double area() = 0;  // �������
	virtual double circumference() = 0;  // �����ܳ�
};
// ������1������
class Rectangl : public Shape  // �̳г�����
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
// ������1��Բ��
class Circle :public Shape  // �̳г�����
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
// ��������Ժ�������
void Shape_Invoke()
{
	Rectangl r1(10, 10, 10, 5.0);
	Circle c1(1, 2, 1);
	Shape* p1 = &r1;  // ����������ָ�븳ֵ
	Shape& p2 = c1;  // �������������ø�ֵ
	cout << "�����������" << p1->area() << endl;  // ͨ������ָ�����������1�ĳ�Ա����
	cout << "�������ܳ���" << p1->circumference() << endl;
	cout << "Բ�����" << p2.area() << endl;  // ͨ���������õ���������2�ĳ�Ա����
	cout << "Բ�ܳ���" << p2.circumference() << endl;
}

// ���������
/*
���������ָ����������µĲ������ܣ���Ҫ���ڶ���Ķ���Ĳ���
��������ض��壺
<��������> <����>::operator <������>(<������>)
{
	������
}
˫Ŀ����������أ�x + y <--> x.(+)(y)
*/

// �������������ʵ�ָ�����������е�
// ������
class Complex
{
private:
	double real, imag;  // ʵ�����鲿
	static Complex temp;  // ��̬�����ʹ�þ�̬���������ڳ�Ա�����ڶ�����ʱ�����ʡ�˵��ù��캯��������������ʱ�䣬���Ч��
public:
	Complex(double r = 0, double i = 0) : real(r), imag(i) { }  // ���캯��
	double Real() { return real; }  // ���ʵ��
	double Imag() { return imag; }  // ����鲿
	void print();
	Complex operator +(Complex);  // �����ӷ���+����
	Complex operator +(double);  // ������ʵ����+����
	bool operator ==(Complex);  // �еȣ�==����
	Complex operator ++();  // ��Ŀ����� x++ ����
	Complex operator ++(int);  // ��Ŀ����� ++x ����
	~Complex() { };  // ��������
};
Complex Complex::temp;  // ��̬�����

// C++�����������ж������Ķ���
/*
����һ������A a1��a1�������ж���a������������滹��һ����������һֱ������ȥ��ֱ���ڴ�ľ�������ջ�����

���������ж������ľ�̬���󡢸ö����ָ��������á�
	��Ϊ��̬�ĳ�Ա���ڶ�����ڲ�����data����������๲�����Բ�����ֵݹ鴴����
*/

// ��������� ������������������
Complex Complex::operator + (Complex c) 
{
	//Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}
// ���������������������������ұ���˫������
Complex Complex::operator + (double d) 
{
	//Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}
// ���������==
bool Complex::operator ==(Complex c) 
{
	if (real == c.real && imag == c.imag)
		return true;
	else
		return false;
}
// ǰ��++��������壬��+1�����
Complex Complex::operator ++ ()
{
	real += 1;
	return *this;
}
// ����++��������壬�������+1
Complex Complex::operator ++ (int)
{
	//Complex 
	temp = *this;
	++real;  // ����ǰ��ʵ�ֺ��ã����ٴ����ظ�
	return temp;
}
/*
��Ŀ���������֪ʶ�㣺

1���βε�����ԭ��
	ǰ��++û���βΣ�������++��һ��int�βΣ����Ǹ��β�Ҳû�б��õ�����Ŀ��ֻ��Ϊ���ƹ��﷨�����ơ�
	ǰ��++�����++�Ĳ��������غ���������ԭ�ͱ��벻ͬ�������Υ���ˡ����غ�������ӵ�в�ͬ�ĺ���ԭ�͡����﷨�涨��
	��Ȼǰ��++�����++�ķ������Ͳ�ͬ�����Ƿ������Ͳ����ں���ԭ�͡�Ϊ���ƹ��﷨���ƣ�ֻ�ø�����++������һ��int�βΡ�
2������ʵ�ֵ�����
	ǰ��++��ʵ�ֱȽϼ򵥣�����֮�󣬽�*this���ؼ��ɡ���Ҫע����ǣ�һ��Ҫ����*this��
	����++��ʵ����΢�鷳һЩ����ΪҪ��������֮ǰ�Ķ��������Ƚ����󿽱�һ�ݣ��ٽ�����������󷵻��Ǹ�������
3��Ч�ʵ�����
	�������Ҫ��������֮ǰ��ֵ����ôǰ��++�ͺ���++�ļ���Ч����һ�������ǣ�������ȻӦ������ʹ��ǰ��++�������Ƕ����û��Զ������͵�����������
	ǰ��++��Ч�ʸ��ߣ������ǣ�����++��������ʱ����
	�����ԣ�tmp��һ����ʱ���󣬻����һ�ι��캯����һ�����������Ķ��⿪������Ȼ����������ĳЩ����¿����Ż�����Щ���������ǣ�������ò�Ҫ��������������Ϊ��
	���ԣ��ڷ��������͵�ʱ�򣬾���ʹ��ǰ��++����ΪЧ�ʸߣ�����������Ч�ʵͣ�
*/


// ��ӡ������
void Complex::print()
{
	cout << real << "+" << imag << "i";
	cout << endl;
}
// ��������ز��Ժ�������
void Complex_Invoke()
{
	Complex c1(3, 4), c2(5, 6), c3;  // ����������������
	cout << "C1 = ";
	c1.print();
	cout << "C2 = ";
	c2.print();
	c3 = c1 + c2;  // ʹ����������� + ʵ�����������ļӷ�
	cout << "C3 = ";
	c3.print();
	c3 = c3 + 6.5;  // ʹ����������� + ʵ��������ʵ���ļӷ�
	cout << "C3 + 6.5 = ";
	c3.print();
	if (c1 == c2)  // ʹ����������� == �����������Ƿ����
		cout << "�����������" << endl;
	else
		cout << "�������������" << endl;

	c3 = c1++;  // ����
	c3.print();
	c3 = ++c1;  // ǰ��
	c3.print();
}
 // �����ǳ����
/*
ǳ������shallowcopy��
	ֻ����ֱ�ӳ�Ա������ֵ
�����deepcopy��
	ͬʱ������Դ ����ָ��ָ��Ŀռ䣩
ǳ�ӱ�������
	��ֵ�������=����ϵͳĬ�ϵĿ������캯��ʵ�ֵĶ���ǳ����
ʵ����ӱ�
	�Զ���һ����Ա����
	���ؿ������캯����Ҳ�и��ƹ��캯����
	���ظ�ֵ�����
*/

void PolymorphismEntrance()
{
	//mobile_Invoke();
	//Shape_Invoke();
	Complex_Invoke();
	//Derived_Invoke();
}