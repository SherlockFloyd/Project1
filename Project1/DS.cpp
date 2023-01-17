#include<iostream>
#include <sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include <vector>
#include<fstream>
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
//����ڵ㶨��
typedef struct Linknode {
    ElemType data;
    struct Linknode* next;
}*Linklist;
// ��ʼ��
inline Linklist Init_Linklist()
{
    Linklist L = new Linknode;
    L->next = NULL;
    return L;
}
// �п�
bool LinklistEmpty(Linklist L)
{
    if (L->next == NULL)
        return true;
    return false;
}
// �������
void PrintLinklist(Linklist L)
{
    Linknode* p = L->next;
    if (LinklistEmpty(L)) {
        cout << "������Ϊ�գ�" << endl;
        return;
    }
    cout << "��������ڵ��ֵ����Ϊ��" << endl;
    while (p) {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
// ���Ԫ��
inline bool AddLinklistFront(Linklist L, ElemType k[])
{
    for (int i = 0; k[i]!='\0'; i++) {
        Linknode* p = new Linknode;
        p->data = k[i];
        p->next = L->next;
        L->next = p;
    }
    return true;
}
inline bool AddLinklistRear(Linklist L, ElemType k[])
{
    Linklist r = L;
    for (int i = 0; i < k[i] != '\0'; i++) {
        Linknode* p = new Linknode;
        p->data = k[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return true;
}
// ����Ԫ��
bool InsertLinklist(Linklist L, ElemType k, int n)
{
    Linklist p = L;
    for (int i = 0; (i < n - 1 && p != NULL); i++)
        p = p->next;
    if (p == NULL) {
        cout << "����λ�ó��������ȣ�" << endl;
        return false;
    }
    Linknode* r = new Linknode;
    r->data = k;
    r->next = p->next;
    p->next = r;
    return true;
}
// ɾ��Ԫ��
bool DeleteLinklist(Linklist L,ElemType k)
{
    Linknode* p = L->next;
    Linknode* q = L;
    while (p != NULL && p->data != k) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL) {
        cout << "Ҫɾ����Ԫ�ز����ڣ�" << endl;
        return false;
    }
    q->next = p->next;
    delete p;
    return true;
}
// �޸�Ԫ��
bool UpdateLinklist(Linklist L, ElemType ok, ElemType k)
{
    Linknode* p = L->next;
    while (p != NULL && p->data != ok)
        p = p->next;
    if (p == NULL) {
        cout << "Ҫ�޸ĵ�Ԫ�ز����ڣ�" << endl;
        return false;
    }
    p->data = k;
    return true;
}


void LinkedListOperations()
{
    ElemType k,ok;
    int mode, located;
    bool flag;

    int arr[N];
    char c = 'a';
    int i = 0;
    /*string str;
    stringstream ss(str);
    vector<int> nums;*/

    // ��ʼ��
    Linklist L = Init_Linklist();

    while (true) {
        cout << "1�����������Ԫ�أ�ͷ��β����" << endl
            << "2���������Ԫ�ء�" << endl
            << "3������Ԫ�أ�����λ�ã���" << endl
            << "4��ɾ��Ԫ�ء�" << endl
            << "5���޸�Ԫ��ֵ" << endl
            << "0���˳�" << endl
            << "����������ʵ�ֵĹ��ܣ�" << endl;
        cin >> mode;
        switch (mode) {
        case 1:
            // Ԫ�ز���
            cout << "��������ӵ�Ԫ��ֵ���ÿո�������س�������" << endl;

            /*getchar();
            getline(cin, str);
            int tmp;
            while (ss >> tmp)
                nums.push_back(tmp);*/

            
            for (; c != '\n'; i++) {
                cin >> arr[i];
                c = getchar();
            }
            arr[i] = '\0';

            cout << "��������뷽ʽ��" << endl
                << "1��ͷ�巨" << endl
                << "2��β�巨" << endl;
            cin >> mode;
            flag = (mode == 1 && mode != 2) ? AddLinklistFront(L, arr) : AddLinklistRear(L, arr);
            if (!flag)
                cout << "����ʧ�ܣ�" << endl;
            cout << "����ɹ���" << endl;
            break;
        case 2:
            //����
            PrintLinklist(L);
            break;
        case 3:
            //����
            cout << "���������Ԫ�ؼ��������е�λ�ã�" << endl;
            cin >> k >> located;
            flag = InsertLinklist(L, k, located);
            if (!flag)
                cout << "����ʧ�ܣ�" << endl;
            cout << "����ɹ���" << endl;
            break;
        case 4:
            // ɾ��
            cout << "������Ҫɾ����Ԫ�أ�" << endl;
            cin >> k;
            flag = DeleteLinklist(L, k);
            if (!flag)
                cout << "ɾ��ʧ�ܣ�" << endl;
            cout << "ɾ���ɹ���" << endl;
            break;
        case 5:
            // �޸�Ԫ��
            cout << "������Ҫ�޸ĵ�Ԫ�غ��޸ĺ��ֵ��" << endl;
            cin >> ok >> k;
            flag = UpdateLinklist(L, ok, k);
            if (!flag)
                cout << "�޸�ʧ�ܣ�" << endl;
            cout << "�޸ĳɹ���" << endl;
            break;
        case 0:
            while (L != NULL) {
                Linknode* p = L->next;
                delete L;
                L = p;
            }
            cout << "���ÿռ��������" << endl;
            return;
        default:
            cout << "����������������룡" << endl;
        }
    }
}

//�ļ��Ĵ򿪡���д���ر�
// �ϲ�ѧ���ɼ�
class StudentGrade { // ѧ����Ϣ��
public:
    int no; // ѧ��
    string name; // ����
    string classname; // �༶
    float language; // ���ĳɼ�
    float english; // ��Ӣ�ɼ�
    float math; // ��ѧ�ɼ�
    float average; // ƽ���ɼ�
};
// ��ȡѧ���ɼ������������ѧ����ͬ��ѧ���ɼ�
float getscore(string filename, int stdno) {
    int stdno_temp;
    float score;
    ifstream grades(filename.c_str()); // �򿪳ɼ��ļ�
    if (!grades) { // �ж��ļ����Ƿ���ȷ
        cout << "�ļ��򿪴���" << endl;
        return 0;
    }
    bool flag = false;
    while (grades) {
        grades >> stdno_temp >> score;
        if (grades) {  //����ȷʱ
            if (stdno_temp == stdno) {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
        score = 0;
    grades.close();
    return score;
}
// ѧ����Ϣд�ļ����������
void operator<<(ostream& overall_grade, StudentGrade& student)
{
    overall_grade << student.no << '\t' << student.name
        << '\t' << student.classname << "\t";
    overall_grade << '\t' << student.language;
    overall_grade << '\t' << student.english;
    overall_grade << '\t' << student.math;
    overall_grade << '\t' << student.average;
    overall_grade << endl;
}
// �ϲ�ѧ���ɼ����ú���
void studentgrade_invoke()
{
    StudentGrade student;
    // ���ļ� 
    ifstream basic(".\\textfile\\basic_student_information.txt"); // ѧ����Ϣ�ļ� 
    ofstream result(".\\textfile\\overall_grade.txt"); // ѧ��������Ϣ�ļ� 

    if (!basic || !result) { // �ж��ļ����Ƿ���ȷ 
        cout << "�ļ��򿪴���" << endl;
        return;
    }
    result << "ѧ��\t\t����\t\t�༶\t\t����\t��Ӣ\t��ѧ\tƽ��" << endl;
    while (basic) {
        // ���ļ� 
        basic >> student.no >> student.name >> student.classname;
        if (!basic) { // ����ȷʱ��д�ļ� 
            break;
        }
        student.language = getscore(".\\textfile\\language_grade.txt", student.no);
        student.english = getscore(".\\textfile\\english_grade.txt", student.no);
        student.math = getscore(".\\textfile\\math_grade.txt", student.no);
        student.average = (student.language + student.english + student.math) / 3;
        // д�ļ� 
        result << student;
    }
    //�ر��ļ� 
    result.close();
    basic.close();
    cout << "overall_grade.txt�ļ������ɹ�������ģ�" << endl;
}


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

    //LinkedListOperations();

    studentgrade_invoke();

	//return 0;
}
