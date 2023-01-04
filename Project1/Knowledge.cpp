#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>

#include "Knowledge.h"

using namespace std;

// ����������������
/*###########################################################################################################*/
void DefineVariables()
{
	register int n = 0;  // <�洢����><��������><������>  auto\register\static\extern
}

void PrevarVariables()
{
	extern int a, b;  // ����extern��ȫ�ֱ�������ǰ������������
	cout << "ȫ�ֱ�������ǰ���ý����" << a << "\t" << b << endl;
}

int a = 3, b = 5;  // ȫ�ֱ��������

void Variable()
{
	int a = 8;  // ͬ�������ֲ�����
	cout <<"�ֲ������ȽϽ��Ϊ��" << (a < b ? a : b) << endl;  // aΪ�ֲ�����
	cout <<"ȫ�ֱ����ȽϽ��Ϊ��" << (::a < b ? a : b) << endl;  // ʹ��"::"����ȫ�ֱ��������������aΪ�ֲ�����a
}

void StaticLocalVariables()
{
	static int n = 0;  // ��̬�ֲ��������뿪�ú��������ֵ����
	n++;
	cout << "�ú������ô���Ϊ��" << n << endl;
	while (n < 4)
		StaticLocalVariables();
}

// ��ŵ������
/*###########################################################################################################*/
void move(int n, char from, char to)
{
	cout << n << " ���̴� " << from << " �ƶ��� " << to << endl;
}

void hanoi(int n, int p1, int p2, int p3)
{
	void move(int, char, char);  // ��������
	if (n == 1)
		move(n, p1, p3);
	else {
		hanoi(n - 1, p1, p3, p2);  // ��n-1��Բ�̴�p1����p3�ƶ���p2
		move(n, p1, p3);  // ��n��Բ�̴�p1�ƶ���p3
		hanoi(n - 1, p2, p1, p3);  // ��n-1��Բ�̴�p2����p1�ƶ���p3
	}
}

void HanoiInput()
{
	int n;
	cout << "������Բ��������\n";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
}

// ���쳲��������м��ݹ�Ľ�(ǰ����Ϊ1��������������ǰ����֮��)
/*###########################################################################################################*/
double Fibonacci(int n)  // �ݹ鷽��
{
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
// �ݹ麯���Ľ�
double NewFibonacci(double f1, double f2, int n)  // ǰ�ڶ��ǰ��һ���ǰ����
{
	return n <= 1 ? f2 : NewFibonacci(f1 + f2, f1, n - 1);
}
/*β�ݹ飬�ݹ�����ں���ĩβ��ÿ�εݹ�������ϴεļ���״̬��������������*/
void FibonacciInput()
{
	int n, flag = 1;
	cout << "�����������쳲���������������" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		//cout << Fibonacci(i) << '\t';
		cout << NewFibonacci(1,1,i) << '\t';
		if (i == (flag * (flag + 1) / 2)) {
			cout << endl;
			flag++;
		}
	}
}

// ���ֲ��ҵݹ�ʵ��
/*###########################################################################################################*/
int Binary_Search(int A[], int front, int rear, int k)
{
	int num,mid;
	int n = rear - front + 1;
	if (n == 0)
		return -1;
	else {
		mid = (front + rear) / 2;
		if (k == A[mid])
			return mid;
		else {
			if (k < A[mid]) {
				num = Binary_Search(A, front, mid - 1, k);
				return num;
			}
			else {
				num = Binary_Search(A, mid+1, rear, k);
				return num;
			}
		}
	}
}
void Binary_Search_Input()
{
	int key, result, n = 20;
	int A[] = { 2,3,12,15,16,19,21,23,24,25,29,36,42,50,61,90,92,94,95,99 };
	while (true) {
		cout << "����������Ҫ���ҵ����ݣ�0-100����" << endl;
		cin >> key;
		result = Binary_Search(A, 0, n - 1, key);
		if (result == -1)
			cout << "δ�������в��ҵ���Ԫ�أ�" << endl;
		else
			cout << "���ҵ�Ԫ�� " << key << " λ�������е� " << result + 1 << " λ��" << endl;
	}
}

// �������غͺ�������ʵ�ֶ๦��������
/*###########################################################################################################*/
// �Զ��庯������
const int COL = 20;
void sort(double&, double&);
void sort(double&, double&, double&);
void sort(double&, double&, double&, double&);
void sort(double a[], int n);
void sort(char s1[], char s2[]);
void sort(char a[][COL], int n);
int mystremp(char s1[], char s2[]);
// �������غ����𼶵��ã�ʵ�ָ������͵�����
void MultifunctionSort()
{
	// ģ������
	double a = 22.8, b = 115, c = 33.2, d = -10.9;
	double v[] = { 18,9.3,3.5,5.6,10,8,9,10.5,29,20.9,8.6,-5.4,-3,-1,19 };
	char s[][COL] = {
		"Chinese","President","Xi","Jinping","has",
		"urged","all","the","citizens","to","plant","trees"
		"and","make","the","land","more","beautiful" };
	int vn = 15, sn = 17;  // һά�Ͷ�ά���鳤��

	cout << "Ĭ���������������£�" << endl;
	sort(c, d);  // �����Ƚ�
	cout << c << " " << d << endl;
	sort(b, c, d);  // �����Ƚ�
	cout << b << " " << c << " " << d << endl;
	sort(a, b, c, d);  // �����Ƚ�
	cout << a << " " << b << " " << c << " " << d << endl;
	sort(v, vn);  // һά����Ԫ�رȽ�
	for (int i = 0; i < vn; i++)
	{
		if (i == 0)
			cout << v[i];
		cout << " " << v[i];
	}
	cout << endl;
	sort(s, sn);  // ��ά����Ԫ�رȽ�
	for (int i = 0; i < sn; i++)
	{
		if (i == 0)
			cout << s[i];
		else
			cout << " " << s[i];
		cout << " ";
	}
	cout << endl;
}
void sort(double& a, double& b)
{  
	// ��������
	if (a > b)
	{
		double tmp = a;
		a = b;
		b = tmp;
	}
}
void sort(double& a, double& b, double& c)
{  
	// ���ö���������ִ����������
	sort(a, b);
	sort(a, c);
	sort(b, c);
}
void sort(double& a, double& b, double& c, double& d)
{
	// ��������������ִ����������
	sort(a, b, c);
	sort(a, d);
	sort(b, c, d);
}
void sort(double a[], int n)
{
	// ���ö���������ִ����������
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			sort(a[j], a[j + 1]);
}
void sort(char s1[], char s2[])
{
	// ���ö��ַ����ȽϺ���ִ�ж��ַ�������
	if (mystremp(s1, s2) > 0){
		char tmp[20];
		strcpy(tmp, s1);
		strcpy(s1, s2);
		strcpy(s2, tmp);
	}
}
int mystremp(char s1[], char s2[])
{
	// ���ַ����Ƚ�
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return s1[i] - s2[i];
}
void sort(char a[][COL], int n)
{  
	// ���ö���������ִ�д����飨��ά�����飩����
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			sort(a[j], a[j + 1]);
}

// ָ�봫ֵ��&-ȡ��ַ���š�*-ָ�������
/*###########################################################################################################*/
// ��ע�� ����������Ҫ֪ʶ��
void swap(int* xp,int* yp)  // ָ�������Ϊ�βΣ����յ�ַ���͵�ʵ��
{
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;

	/*void Swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}*/  
	// д����ȷ����������д�����β�ȡʵ�ʵ�ַ�����޸�

	/*int* temp;
	temp = xp;
	xp = yp;
	yp = temp;*/  
	/*����д����temp��xp��yp��Ϊָ�����͵�swap�����ֲ��������洢�ں���ջ���У�������ֵ���ı��ⲿ������ֵ���þֲ��������ź������ý���һͬ������
	������ֱ��*xp�ȼ����ⲿ����x��*yp�ȼ����ⲿ����y������temp��һ�ֲ����������ⲿ�������ɸ���ʵ�ʵ�ֵ*/
}
void swap_Input()
{
	int x = 100, y = 200;
	cout << "before swap:" << "x= " << x << " and y= " << y << endl;
	swap(&x, &y);  // ȡ������ַ��Ϊʵ�δ��ݣ����ô��ݣ�
	cout << "after swap:" << "x= " << x << " and y= " << y << endl;
}

// ����ָ����غ����еĶ��ֵ
/*###########################################################################################################*/
double faver(int s[], int n, int* max, int* min)
{
	double sum = s[0];
	*max = *min = s[0];
	for (int i = 1; i < n; i++)
	{
		sum += s[i];
		if (s[i] > *max)
			*max = s[i];
		if (s[i] < *min)
			*min = s[i];
	}
	return sum / n;
}
void faver_Input()
{
	int a[5] = { 80,89,67,76,98 };
	int max, min;
	double aver;
	aver = faver(a, 5, &max, &min);  //���ú���,���ݵ�ַ������ֵ���������������ͺ���������ͬvoid swap(int* xp,int* yp)���ע�ͣ�
	cout << "max=" << max << "\n" << "min=" << min << endl;
	cout << "aver=" << aver << endl;
}

// ����ָ�����͵ĺ���
/*###########################################################################################################*/
char* noblank(char* str)
{
	while (*str == ' ')
		str++;  // strΪָ�����ͣ�ָ��+1�ȼ���+siezof(ElemType)����ָ����һ�����ݵĵ�ַ��������ֱ��+1.
	return str;
}
void noblank_Input()  // ȥ���ַ�����ͷ�Ŀո�
{
	char s[] = "   using namespace std;";  // ���鵥���ı�������Ϊָ�������ָ�������еĵ�һ��Ԫ��
	char* s1 = s;
	char* s2;
	s2 = noblank(s1);
	cout << s2 << endl;
}

// ָ������ָ�����
/*###########################################################################################################*/
void FunctionPrinter()
{
	double (*pf)(double);   // <��������ֵ><*ָ�������><�β������б�����ֻд���Ͷ���д��������>��������Բ���Ų���ʡ�ԣ���
						    // ����ָ��double�ͺ�����ָ��������ú�����һ��double�Ͳ���
	pf = sqrt;  // pfָ��ƽ��������
	cout << (*pf)(9.0) << endl;  // ����9��ƽ����
	cout << sqrt(9.0) << endl;  // ���ϵȼ�
}



void KnEntrance()
{
	//PrevarVariables();
	//Variable();
	//StaticLocalVariables();
	//HanoiInput();
	//FibonacciInput();
	//Binary_Search_Input();
	//MultifunctionSort();
	//swap_Input();
	//faver_Input();
	//noblank_Input();
	FunctionPrinter();
}