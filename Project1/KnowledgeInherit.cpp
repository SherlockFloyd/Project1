#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeInherit.h"

using namespace std;

class person
{
protected:
	char* name; //����,�������Ȳ�ȷ����ʹ��ָ�룬�洢ʱ���ö�̬����ռ�
	char sex; //�Ա�
	char pid[19]; //���֤����
	int weight; //����
	int high; //���
public:
	person() { cout << "����person�޲ι��캯��"; }; //�޲ι��캯��
	person(char* n, char s, char* p, int w, int h); //�вι��캯��
	void change_data(char* n, char s, char* p, int w, int h);//�޸�����
	void walking(int k, int v); //��v�ٶ�����k��
	void hearing(char* sentence); //ģ�������ظ����������
	void speaking(); //ģ��˵������
	void writing(); //����Ļ�ϻ���
	void show(); //����˵�����ֵ
	~person() {
		delete[] name;
		cout << "����person��������";
	}; //��������
};
// ���캯������
person::person(char* n, char s, char* p, int w, int h)
{
	change_data(n, s, p, w, h);
	cout << "����person�вι��캯��";
}
// �޸���Ϣ
void person::change_data(char* n, char s, char* p, int w, int h)
{
	char* pname = new char[strlen(n) + 1];  // �����������ݶ�̬��������ռ��С��+1�Ǵ洢������'\0'
	strcpy(pname, n);  // �����µĿռ������ԭ�еĿռ���Ϊ�˱������ݶ����ԣ���ֹ�ⲿ�����ƻ������ڲ��������
	strcpy(this->pid, p);
	this->name = pname;  // ����������ָ��ָ������Ŀռ䣬���ͷ�
	sex = s;
	weight = w;
	high = h;
}
// ģ������
void person::walking(int k, int v)
{
	cout << "\n" << name << "ˮƽֱ������" << k << "��" << endl;
	for (int i = 0; i < k; i++){
		cout << ' ' << "o_o";
		Sleep(1000 / v);
		cout << "\b\b\b";
	}
	cout << endl;
}
// ģ����
void person::hearing(char* sentence) 
{
	char* p = new char[strlen(sentence) + 1];  // ��̬����������ӳ��ȴ�С������ռ�
	strcpy(p, sentence);  // ������������
	char* pp = p;  // ָ�����ppָ��̬����ռ�
	cout << "I hear you! ��˵���ǣ�";
	cout << pp << endl;
	delete[] pp;  // �ͷŶ�̬����ռ�
}
// ģ��˵
void person::speaking()
{
	int n = 4;
	cout << "���ڳ���..." << endl;
	for (int i = 0; i < n; i++) {
		Sleep(i * 1000);
		cout << "\007";
	}
}
// ģ��д
void person::writing() {
	int a=2;
	//cout << "please input A:";
	//cin >> a;                  //ͼ����߿��봰����߽�ľ���ֵ�����滻�����ⳣ����Ҳ���Ժ��ԡ�
	cout << "���ڻ���..." << endl;
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
// �����Ϣ
void person::show()
{
	cout << "����\t" << "�Ա�\t" << "���֤��\t\t" << "����\t" << "���\t" << endl;
	cout << name << "\t" << sex << "\t" << pid << "\t" << weight << "\t" << high << endl;
}



// ������̳�
/*
�����ࣨ���ࣩ�Ķ��壺
class ��������: �̳з�ʽ������Ȩ�ޣ� ���ࣨ���ࣩ��1, �̳з�ʽ ������2, ��, �̳з�ʽ ������n
{
	���������ӵĳ�Ա������
};
�̳з�ʽΪ public��protected��private ������ָ�������Ա���������е���߷���Ȩ�ޣ������������ȡ������ȡ��С����
	+---------+-------------+--------------+-------------+
	| ������ʽ | �������Ȩ�� | ���������Ȩ�� | �ⲿ�������� |
	+---------+-------------+--------------+-------------+
	|         |  public     |  public      |  ��ֱ�ӷ���  |
	|         +-------------+--------------+-------------+
	| ���м̳� |  protected  |  protected   | ����ֱ�ӷ��� |
	|         +-------------+--------------+-------------+
	|         |  private    | ����ֱ�ӷ���  | ����ֱ�ӷ���  |
	+---------+-------------+--------------+-------------+
	|         |  public     |  protected   | ����ֱ�ӷ��� |
	|         +-------------+--------------+-------------+
	| �����̳� |  protected  |  protected   | ����ֱ�ӷ��� |
	|         +-------------+--------------+-------------+
	|         |  private    | ����ֱ�ӷ���  | ����ֱ�ӷ���  |
	+---------+-------------+--------------+-------------+
	|         |  public     |  private     | ����ֱ�ӷ��� |
	|         +-------------+--------------+-------------+
	| ˽�м̳� |  protected  |  private     | ����ֱ�ӷ��� |
	|         +-------------+--------------+-------------+
	|         |  private    | ����ֱ�ӷ���  | ����ֱ�ӷ���  |
	+---------+-------------+--------------+-------------+

1����һ��������ǰ�������(����)��������Ĺ��̳�Ϊ�������²�������Ϊ������
2����ļ̳У�inheritance����ָ����ӻ�������õ���������������̳л�������ݺͺ���
3������������ͬʱҲ�������ӻ����¶������ݺͺ���������������Ĳ����

������ı仯��
1. ���������µ����ݳ�Ա
2. ���������µĺ�����Ա
3. �������¶������еĺ�����Ա
4. ���Ըı����г�Ա������ֵ
����������ã�
1. �ӻ�����ܳ�Ա
2. ������Ի��������
3. ������Ի����Ա�ĸ���
4. ϵͳ��Ĭ��ֵ����˽�м̳�
*/
class sing_star : public person
{
	float salary;  // нˮ
public:
	sing_star();  // �޲ι��캯�������캯�����ܼ̳У�����ÿ���඼�й��캯��
	sing_star(char* n, char s, char* p, int w, int h, float s1);  // �вι��캯��
	void change_data(char* n, char s, char* p, int w, int h, float s1);
	void show(); //����˵�����ֵ
	void playing();  // �ݳ�
	~sing_star()
	{
		// person::~person();  // �Զ����û�����������������ֶ�������ᱨ��
		cout << "����sing_star��������";
	}
};
// �޲ι��캯��
sing_star::sing_star() :person()   // ���û��๹�캯�����ù����ֶΣ��ں����������ö����ֶ�
{
	salary = 0.0;  // ��������������Ա���г�ʼ��
	cout << "����sing_star�޲ι��캯��";
}
// �вι��캯��
sing_star::sing_star(char* n, char s, char* p, int w, int h, float s1)
{
	person::change_data(n, s, p, w, h);  // ���û��ຯ��
	salary = s1;
	cout << "����sing_star�вι��캯��";
}
// ������Ϣ
void sing_star::change_data(char* n, char s, char* p, int w, int h, float s1)
{
	person::change_data(n, s, p, w, h);
	salary = s1;
}
void sing_star::show()
{
	cout << "����\t" << "�Ա�\t" << "���֤��\t" << "����\t" << "���\t" << "нˮ\t" << endl;
	cout << name << "\t" << sex << "\t" << pid << "\t\t" << weight << "\t" << high << "\t" << salary << endl;
}
void sing_star::playing()
{
	cout << "�����ݳ�..." << endl;
	cout << "�ݳ����ѽ������´��������";
}
// �̳в��Ժ�������
void PersonInvoke()
{
	char sentence[21];
	person laowang("��", 'M', "410527666666666666", 100, 175);
	laowang.show();
	cout << "����������˵�Ļ���" << endl;
	cin >> sentence;
	laowang.hearing(sentence);
	laowang.speaking();
	laowang.writing();

	sing_star deng("������", 'w', "C668669", 43, 157, 500000.5);  // �ȵ��û���Ĺ��캯�����ٵ�������Ĺ��캯��
	deng.show();
	deng.walking(9,2);  // ���û����еĺ���ʵ�����ٶ�2����9��
	deng.playing();
}

/*
������Ĺ��캯������������
�����๹�캯�����壺
<��������::>��������(�����ܱ�): ������1(������1)������������n(������n)����Ƕ������1�����������1����������Ƕ������m�����������m��
{
		�����������ӳ�Ա�ĳ�ʼ����
}

�����๹�캯����ִ�д���
1�����û��๹�캯��������˳�������Ǳ��̳�ʱ�����Ļ�����˳��ִ�С�
2��������Ƕ�����캯�������ô��򰴸�����������������������˳��
3��ִ�������๹�캯�����е����ݡ�
����������������ִ�д����빹�캯���෴����
1��ִ������������������
2��ִ����Ƕ���������������
3��ִ�л�������������

�����๹�캯���ĵ��ù���
	�����๹�캯�������Զ����û����Ĭ�Ϲ��캯��������ǰ����Ĭ�Ϲ��캯��������ڡ�
	ͨ������£�Ĭ�Ϲ��캯��ϵͳ���Զ����ɵģ���������ڻ����У������Լ�������һ���������Ĺ��캯�������ʱ��ϵͳ�ǲ���Ϊ�����Զ�����Ĭ�Ϲ��캯���ģ�
	���ʱ�����������޷��Զ����û����Ĭ�Ϲ��캯���ˣ���Ϊ��������Ͳ�����Ĭ�Ϲ��캯����
	����������������ֽ����������һ���ڻ����ж���һ��Ĭ�Ϲ��캯�������������Ĺ��캯������
							 ������������е�ÿһ�����캯������ʽ�ĵ��û����еĴ��ι��캯����
	ͨ�����ǻ�����������һ��������������в�δ��ʽ���幹�캯�������ʱ����������ֻ��ϵͳ�Զ����ɵ�Ĭ�Ϲ��캯����
	���һ����������ǲ�Ϊ�������һ��Ĭ�Ϲ��캯���������ͻ�������

1������Ĺ��캯��ֻ�Ի�������ݳ�Ա���г�ʼ����������Ĺ��캯��ֻ�����������������ݳ�Ա���г�ʼ����ͬʱҲ����û���Ĺ��캯����
2���������ཨ��һ������ʱ��ִ�й��캯����˳���ǣ��ȵ��û���Ĺ��캯������ִ�������๹�캯������
3���ͷŶ���ʱ��ִ������������˳���ǣ��ȵ�������������������ٵ��û��������������
4�������캯���������������ܱ��̳У������Ա����� ��
*/
// ����
class Person
{
	char* Name; //����
	int Age; //����
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
// ������
class Employee : public Person
{
	char* Dept;  // �����ص�
	Person Leader;  // ��Ƕ����Ķ���
public:
	// �вι��캯�������û���Ĺ��캯�������������Ƕ���󣨹��캯���� ���൱��{}�����������壬����Ĺ��캯����ϵͳ�Զ�����Ϊʲô��Ҫ�ֶ����ã�ԭ�������֪ʶ�㣩
	Employee(char* name, int age, char* dept, char* name1, int age1) : Person(name, age), Leader(name1, age1)
	{
		Dept = new char[strlen(dept) + 1];
		strcpy(Dept, dept);
		cout << "constructor of Employee" << endl;
	}
	~Employee() { cout << "deconstrucor of Employee" << endl; delete[] Dept; }
}; 
// �����๹���������������Ե���
void Employee_Invoke()
{
	Employee emp("�Ź���", 40, "���´�", "��ľ��", 36);
}


void InheritEntrance()
{
	//PersonInvoke();
	//Employee_Invoke();
}