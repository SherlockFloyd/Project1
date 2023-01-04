#include<iostream>
#include<cmath>
#include<iomanip>
#include "DS.h"
using namespace std;

#define N 100
#define ElemType int  // �����㷨��ʹ��

//�����ֵ����Сֵ
void FindMaxMin()
{
    int n = -1;
    double max, min;
    //double A[N];
    while (n < 1) {
        cout << "����������ҵ�Ԫ�ظ���\n";
        cin >> n;
        if (n < 1)
            cout << "����������������룡\n";
    }
    double* A = (double*)malloc(n * sizeof(double));
    cout << "����������" << n << "��Ԫ��,�Կո�������س�����\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    max = A[0];
    min = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    cout << "����Ԫ���е����ֵΪ��" << max << "\n����Ԫ���е���СֵΪ��" << min;
    free(A);
}

//�����¶��������¶ȵĻ���
void TemperatureConversion()
{
    double h,f;
    cout << "�����뻪���¶ȣ�";
    cin >> h;
    f = (h - 32) * 5 / 9;
    cout << "��Ӧ�����¶�Ϊ��" <<fixed << setprecision(1) << f;  // ���϶ȱ���һλС��
}


//��Сд��ĸת��
void CaseConversion()
{
    string str;
    cout << "������һ���ַ�����\n";
    cin >> str;

    for (char& c : str) {
        if (isupper(c)) {
            c = tolower(c);
        }
        else if (islower(c)) {
            c = toupper(c);
        }
    }
    cout << "ת������ַ���Ϊ��\n" << str << endl;
}

//�б�����
/*���꣺�ܱ�4���������ܱ�100�����������ܱ�400����*/
void JudgeLeapYears()
{
    int year;
    cout << "���������: ";
    cin >> year;

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        cout << year << " ������\n";
    else
        cout << year << " ��������\n";

    //if (year % 4 == 0)
    //{
    //    if (year % 100 == 0)
    //    {
    //        // // ��������� 400 ����������
    //        if (year % 400 == 0)
    //            cout << year << " ������";
    //        else
    //            cout << year << " ��������";
    //    }
    //    else
    //        cout << year << " ������";
    //}
    //else
    //    cout << year << " ��������";

}

//�ٷ��Ƴɼ�������Ƴɼ�����ת��
void GradeConversion()
{
    bool flag = false;
    float old_grade;
    //int new_grade;
    string new_grade;
    while (flag!=true) {
        flag = true;
        cout << "������ٷ��Ƴɼ���\n";
        try {
            cin >> old_grade;
        }
        catch(...) {
            flag = false;
        }
        if (flag == false || old_grade < 0 || old_grade>100) {
            cout << "�����������������룡\n";
            flag = false;
        }
    }
    switch ((int)old_grade / 10) {
    case 10:
        new_grade.assign("��");
        break;
    case 9:
        new_grade.assign("��");
        break;
    case 8:
        new_grade.assign("��");
        break;
    case 7:
        new_grade.assign("��");
        break;
    case 6:
        new_grade.assign("����");
        break;
    default:
        new_grade.assign("������");
    }
    cout << old_grade << "�ֶ�Ӧ������Ƴɼ�Ϊ��" << new_grade << endl;
}

//���������������������С������
int gcd(int a, int b) {  // շת��������������
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void MinMultiple()
{
    int a, b;
    cout << "������������������ \n";
    cin >> a >> b;

    cout << a << " �� " << b << " �����Լ��Ϊ�� " << gcd(a, b) << endl;
    cout << a << " �� " << b << " ����С������Ϊ�� " << lcm(a, b) << endl;
}

//��������ˮ�ɻ�������ȫƽ����
void FindNumber()
{
    // ����ѡ�����
    int select;
    bool flag = false;

    // ����ʵ�ֱ���
    bool isPrime = true;
    int sum, num = -1, d1, d2, d3, front = 100, rear = 1000;
    double r;

    while (flag != true) {
        flag = true;
        cout << "��������ʵ�ֵĹ�����ţ�\n";
        cout << "1:������\n";
        cout << "2:��ˮ�ɻ���\n";
        cout << "3:����ȫƽ����\n";
        cin >> select;

        switch (select) {
        case 1:  // ������ֻ�ܱ�1�͸�����������
            cout << "������һ����������\n";
            cin >> num;
            for (int i = 2; i <= num / 2; ++i)
            {
                if (num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                cout << num << "������\n";
            else
                cout << num << "��������\n";
            break;
        case 2:  // ˮ�ɻ������������ڸ�λ���η���
            /*cout << "��������ҵ����䣺\n";
            cin >> front >> rear;*/
            cout << "��" << front << "��" << rear << "��ˮ�ɻ���Ϊ��\n";
            for (int i = front; i < rear; i++) {
                num = i;
                d1 = num % 10;  // ʮλ
                num = num / 10;  
                d2 = num % 10;  // ��λ
                num = num / 10;
                d3 = num % 10;  // ǧλ
                sum = d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3;
                if (sum == i)
                    cout << i << "\t";
            }
            break;
        case 3:  // ��ȫƽ��������������һ����ƽ������
            while (num < 0) {
                cout << "������һ����������\n";
                cin >> num;
            }
            /*r = sqrt(num);
            r = (int)r;
            if(r == num)
                cout << num << "����ȫƽ����\n";
            else
                cout << num << "������ȫƽ����\n";*/

            for (int i = 1; i < num; i++) {
                sum = i * i;
                if (num == sum) {
                    cout << num << "����ȫƽ����\n";
                    break;
                }
                else if (sum > num)
                    cout << num << "������ȫƽ����\n";
                    break;
            }
            break;
        default:
            flag = false;
            cout << "�����������������";
        }
    }
    
}

//ͳ�������ַ��е����
void CharacterStatistics()
{
    char str[N];
    int i = 0;
    int len = 0, capital = 0, smallletter = 0, digit = 0, others = 0;
    cout << "������һ��������50���ַ����ַ�����\n";
    cin.getline(str, N);
    while (str[i] != '\0') {
        len++;
        if (str[i] <= 'Z' && str[i] >= 'A')
            capital++;
        else if (str[i] <= 'z' && str[i] >= 'a')
            smallletter++;
        else if (str[i] <= '9' && str[i] >= '0')
            digit++;
        else
            others++;
        i++;
    }
    cout << "�ַ����ܳ���Ϊ��" << len << endl
        << "��д��ĸ����Ϊ��" << capital << endl
        << "Сд��ĸ����Ϊ��" << smallletter << endl
        << "�� �� �� �� Ϊ��" << digit << endl
        << "�����ַ�����Ϊ��" << others << endl;

}

//����������֮�͡�֮��
void MatrixMultiplication()  // �˷�ʵ��
{
    bool flag = false;
    const int M = 20, L = 20, K = 20;
    double A[M][L], B[L][K], C[M][K];
    int m1, n1, m2, n2;
    while (flag != true) {
        flag = true;
        cout << "�������һ�������ά�����С��У�(ά������20)" << endl;
        cin >> m1 >> n1;

        cout << "������ڶ��������ά�����С��У�(ά������20)" << endl;
        cin >> m2 >> n2;

        if (n1 != m2) {
            flag = false;
            cout << "��һ�����������Ӧ�����ڵڶ�����������������������룡\n";
        }
    }
    cout << "�밴�����������һ�������Ԫ��" << endl;
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            cin >> A[i][j];
    cout << "�밴����������ڶ��������Ԫ��" << endl;
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            cin >> B[i][j];

    for (int i = 0; i < m1; i++) {  // ���վ���m1�е�ÿһ��
        for (int j = 0; j < n2; j++) {  // ���վ���n2�е�ÿһ��
            C[i][j] = 0;  // ��ʼ��Ϊ0
            for (int k = 0; k < n1; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j];  // ��Ӧ�����������
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }
}

void MatrixPlus()  // �ӷ�ʵ��
{
    bool flag = false;
    const int M = 20, L = 20;
    double A[M][L], B[M][L], C[M][L];
    int m, n;
    cout << "��������Ӿ����ά�����С��У�(ά������20)" << endl;
    cin >> m >> n;
    cout << "�밴�����������һ�������Ԫ��" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "�밴����������ڶ��������Ԫ��" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }
}

void MatrixOperations()
{
    bool flag = false;
    int select;
    while (flag != true) {
        flag = true;
        cout << "����������Ҫʵ�ֵĹ��ܶ�Ӧ����ţ�\n"
            << "1�����������" << endl
            << "2�����������" << endl;
        try {
            cin >> select;
        }
        catch(...) {
            select = 0;
        }
        switch (select)
        {
        case 1:
            MatrixMultiplication();
            break;
        case 2:
            MatrixPlus();
            break;
        default:
            cout << "����������������룡";
            flag = false;
        }
    }
    
}

//ѡ��������ð������
inline void Swap(int& a, int& b)  // ��������Ԫ��(ʹ��������������)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectSort()
{
    int n, minix, select;
    cout << "�����������Ԫ�ظ���:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "�����������Ԫ��\n";
    for (int i = 0; i < n;i++) {
        cin >> A[i];
    }
    cout << "��ѡ��������߽���\n"
        << "1������" << endl
        << "2������" << endl;
    cin >> select;

    for (int i = 0; i < n - 1; i++) {
        minix = i;
        for (int j = i + 1; j < n; j++) {
            if (select == 1) {
                if (A[j] < A[minix])
                    minix = j;
                else
                    continue;
            }    
            else {
                if (A[j] > A[minix])
                    minix = j;
                else
                    continue;
            }
        } 
        if (minix != i)
            Swap(A[i], A[minix]);
    }
    cout << "������Ԫ������Ϊ��\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    free(A);
}

void BubbleSort()
{
    bool flag = false;  // ��ǰ��ֹ��־
    int n, minix, select;
    cout << "�����������Ԫ�ظ���:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "�����������Ԫ��\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "��ѡ��������߽���\n"
        << "1������" << endl
        << "2������" << endl;
    cin >> select;

    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = n - 1; j > i; j--) {
            if (select == 1) {
                if (A[j - 1] > A[j]) {
                    Swap(A[j - 1], A[j]);
                    flag = true;
                }     
            }
            else {
                if (A[j - 1] < A[j]) {
                    Swap(A[j - 1], A[j]);
                    flag = true;
                }
            }
        }
        if (flag == false)
            break;
    }
    cout << "������Ԫ������Ϊ��\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    free(A);
}

//��������
int Partition(ElemType A[], int low, int high)  // һ������
{
    ElemType pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(ElemType A[], int low, int high)  // �ݹ����
{
    if (low < high) {
        int key = Partition(A, low, high);
        QuickSort(A, low, key - 1);
        QuickSort(A, key + 1, high);
    }
}

void QuickSortInput()  // ��������
{
    int n;
    cout << "�����������Ԫ�ظ���:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "�����������Ԫ��\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    QuickSort(A, 0, n-1);  // ���ÿ���
    cout << "������Ԫ������Ϊ��" << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << "\t";
}

//����ı��������ӡ�ɾ�����޸�

//�ļ��Ĵ򿪡���д���ر�


void DSEntrance()
{
    //JudgeLeapYears();

    //GradeConversion();

    //MinMultiple();

    //FindNumber();

    //FindMaxMin();

    //TemperatureConversion();

    //CaseConversion();

    //CharacterStatistics();

    //MatrixOperations();

    //SelectSort();

    //BubbleSort();

    //QuickSortInput();

	//return 0;
}
