#include<iostream>
#include<cmath>
using namespace std;

struct Student
{
	int snumber;
	char name[20];
	int age;
};

// ��������
void Swap(int &x,int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// ʵ�־���ת��
void Tranmat(int a[][10], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			Swap(a[i][j], a[j][i]);
}

int text()
{
	// �����Ӽ�����
	/*int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << c << endl;*/

	// �洢��Ϣ����
	/*double money, years, rate, sum;
	cout << "�����뱾�𡢴�����ޣ��꣩�������ʣ����ո����" << endl;
	cin >> money >> years >> rate;
	while (money > 0) {
		sum = money * pow((1 + rate), years);
		cout << "��ϢΪ��";
		cout << sum << endl;
		cin >> money >> years >> rate;
	}
	cout << "������ֹ";*/

	// ��������
	/*cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;

	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;*/
	
	// ���������ռһ���ռ䣬�������ִ��������Ԫ�����͵ĸ���-1
	/*char name[6];
	cin >> name;
	cout << name << endl;*/

	// ����һԪ���η���
	/*double a, b, c;
	double delta;
	double x, x1, x2;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			cout << "�����ϵ�������ɷ���" << endl;
		}
		else {
			x = -c / b;
			cout << "ʵ��ΪһԪһ�η��̣���Ϊ" << x;
		}
	}
	else {
		delta = b * b - 4.0 * a * c;
		if (delta >= 0) {
			delta = sqrt(delta);
			x1 = (-b + delta) / (2.0 * a);
			x2 = (-b - delta) / (2.0 * a);
			cout << "������ʵ�����ֱ�Ϊ��" << "x1=" << x1 << "x2=" << x2;
		}
		else {
			delta = sqrt(-delta);
			x1 = -b / (2.0 * a);
			x2 = delta / (2.0 * a);
			cout << "�����и������ֱ�Ϊ��" << "x1=" << x1 << "+" << x2 << "i" << "," << "x2=" << x1 << "-" << x2 << "i";
		}
	}*/
	

	
	return 0;
}

int main() {
	const int N = 10;
	int a[N][N], n;
	cout << "������������С��10����";
	cin >> n;
	cout << "���������������Ԫ�أ��Կո�ͻس�������\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	Tranmat(a, n);
	cout << "ת�þ������£�\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}