#include<iostream>
#include<cmath>
using namespace std;

struct Student
{
	int snumber;
	char name[20];
	int age;
};

// 两数交换
void Swap(int &x,int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// 实现矩阵转置
void Tranmat(int a[][10], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			Swap(a[i][j], a[j][i]);
}

int text()
{
	// 基础加减运算
	/*int a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << c << endl;*/

	// 存储本息计算
	/*double money, years, rate, sum;
	cout << "请输入本金、存款期限（年）、年利率，按空格隔开" << endl;
	cin >> money >> years >> rate;
	while (money > 0) {
		sum = money * pow((1 + rate), years);
		cout << "本息为：";
		cout << sum << endl;
		cin >> money >> years >> rate;
	}
	cout << "程序终止";*/

	// 数据类型
	/*cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;

	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;*/
	
	// 数组结束符占一个空间，数组数字代表该数组元素类型的个数-1
	/*char name[6];
	cin >> name;
	cout << name << endl;*/

	// 计算一元二次方程
	/*double a, b, c;
	double delta;
	double x, x1, x2;
	cout << "请输入一元二次方程的三个系数a,b,c:";
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			cout << "输入的系数不构成方程" << endl;
		}
		else {
			x = -c / b;
			cout << "实际为一元一次方程，根为" << x;
		}
	}
	else {
		delta = b * b - 4.0 * a * c;
		if (delta >= 0) {
			delta = sqrt(delta);
			x1 = (-b + delta) / (2.0 * a);
			x2 = (-b - delta) / (2.0 * a);
			cout << "方程有实根，分别为：" << "x1=" << x1 << "x2=" << x2;
		}
		else {
			delta = sqrt(-delta);
			x1 = -b / (2.0 * a);
			x2 = delta / (2.0 * a);
			cout << "方程有复根，分别为：" << "x1=" << x1 << "+" << x2 << "i" << "," << "x2=" << x1 << "-" << x2 << "i";
		}
	}*/
	

	
	return 0;
}

int main() {
	const int N = 10;
	int a[N][N], n;
	cout << "输入矩阵阶数（小于10）：";
	cin >> n;
	cout << "按行优先输入矩阵元素，以空格和回车结束。\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	Tranmat(a, n);
	cout << "转置矩阵如下：\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}