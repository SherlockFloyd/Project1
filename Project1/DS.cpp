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
#define ElemType int  // 排序算法中使用

//求最大值与最小值
void FindMaxMin()
{
    int n = -1;
    double max, min;
    //double A[N];
    while (n < 1) {
        cout << "请输入待查找的元素个数\n";
        cin >> n;
        if (n < 1)
            cout << "输入错误，请重新输入！\n";
    }
    double* A = (double*)malloc(n * sizeof(double));
    cout << "请依次输入" << n << "个元素,以空格隔开，回车结束\n";
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
    cout << "该组元素中的最大值为：" << max << "\n该组元素中的最小值为：" << min;
    free(A);
}

//华氏温度与摄氏温度的换算
void TemperatureConversion()
{
    double h,f;
    cout << "请输入华氏温度：";
    cin >> h;
    f = (h - 32) * 5 / 9;
    cout << "对应摄氏温度为：" <<fixed << setprecision(1) << f;  // 摄氏度保留一位小数
}


//大小写字母转换
void CaseConversion()
{
    string str;
    cout << "请输入一个字符串：\n";
    cin >> str;

    for (char& c : str) {
        if (isupper(c)) {
            c = tolower(c);
        }
        else if (islower(c)) {
            c = toupper(c);
        }
    }
    cout << "转换后的字符串为：\n" << str << endl;
}

//判别闰年
/*闰年：能被4整除但不能被100整除，或者能被400整除*/
void JudgeLeapYears()
{
    int year;
    cout << "请输入年份: ";
    cin >> year;

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        cout << year << " 是闰年\n";
    else
        cout << year << " 不是闰年\n";

    //if (year % 4 == 0)
    //{
    //    if (year % 100 == 0)
    //    {
    //        // // 这里如果被 400 整除是闰年
    //        if (year % 400 == 0)
    //            cout << year << " 是闰年";
    //        else
    //            cout << year << " 不是闰年";
    //    }
    //    else
    //        cout << year << " 是闰年";
    //}
    //else
    //    cout << year << " 不是闰年";

}

//百分制成绩与五分制成绩互相转换
void GradeConversion()
{
    bool flag = false;
    float old_grade;
    //int new_grade;
    string new_grade;
    while (flag!=true) {
        flag = true;
        cout << "请输入百分制成绩：\n";
        try {
            cin >> old_grade;
        }
        catch(...) {
            flag = false;
        }
        if (flag == false || old_grade < 0 || old_grade>100) {
            cout << "输入有误，请重新输入！\n";
            flag = false;
        }
    }
    switch ((int)old_grade / 10) {
    case 10:
        new_grade.assign("优");
        break;
    case 9:
        new_grade.assign("优");
        break;
    case 8:
        new_grade.assign("良");
        break;
    case 7:
        new_grade.assign("中");
        break;
    case 6:
        new_grade.assign("及格");
        break;
    default:
        new_grade.assign("不及格");
    }
    cout << old_grade << "分对应的五分制成绩为：" << new_grade << endl;
}

//求两个数的最大公因数和最小公倍数
int gcd(int a, int b) {  // 辗转相除法求最大公因子
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
	
    /*
    非递归方式
    while(b!=0)
    {
    	int temp=b;
	b=a%b;
	a=temp;
    }
    return a;
    */
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void MinMultiple()
{
    int a, b;
    cout << "请输入两个正整数： \n";
    cin >> a >> b;

    cout << a << " 和 " << b << " 的最大公约数为： " << gcd(a, b) << endl;
    cout << a << " 和 " << b << " 的最小公倍数为： " << lcm(a, b) << endl;
}

//求素数、水仙花数、完全平方数
void FindNumber()
{
    // 功能选择变量
    int select;
    bool flag = false;

    // 功能实现变量
    bool isPrime = true;
    int sum, num = -1, d1, d2, d3, front = 100, rear = 1000;
    double r;

    while (flag != true) {
        flag = true;
        cout << "输入您想实现的功能序号：\n";
        cout << "1:求素数\n";
        cout << "2:求水仙花数\n";
        cout << "3:求完全平方数\n";
        cin >> select;

        switch (select) {
        case 1:  // 素数：只能被1和该数本身整除
            cout << "请输入一个正整数：\n";
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
                cout << num << "是素数\n";
            else
                cout << num << "不是素数\n";
            break;
        case 2:  // 水仙花数：该数等于各位三次方和
            /*cout << "请输入查找的区间：\n";
            cin >> front >> rear;*/
            cout << "从" << front << "到" << rear << "的水仙花数为：\n";
            for (int i = front; i < rear; i++) {
                num = i;
                d1 = num % 10;  // 十位
                num = num / 10;  
                d2 = num % 10;  // 百位
                num = num / 10;
                d3 = num % 10;  // 千位
                sum = d1 * d1 * d1 + d2 * d2 * d2 + d3 * d3 * d3;
                if (sum == i)
                    cout << i << "\t";
            }
            break;
        case 3:  // 完全平方数：该数可由一个数平方得来
            while (num < 0) {
                cout << "请输入一个正整数：\n";
                cin >> num;
            }
            /*r = sqrt(num);
            r = (int)r;
            if(r == num)
                cout << num << "是完全平方数\n";
            else
                cout << num << "不是完全平方是\n";*/

            for (int i = 1; i < num; i++) {
                sum = i * i;
                if (num == sum) {
                    cout << num << "是完全平方数\n";
                    break;
                }
                else if (sum > num)
                    cout << num << "不是完全平方是\n";
                    break;
            }
            break;
        default:
            flag = false;
            cout << "输入错误，请重新输入";
        }
    }
    
}

//统计输入字符中的类别
void CharacterStatistics()
{
    char str[N];
    int i = 0;
    int len = 0, capital = 0, smallletter = 0, digit = 0, others = 0;
    cout << "请输入一串不大于50个字符的字符串：\n";
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
    cout << "字符串总长度为：" << len << endl
        << "大写字母个数为：" << capital << endl
        << "小写字母个数为：" << smallletter << endl
        << "数 字 个 数 为：" << digit << endl
        << "其他字符个数为：" << others << endl;

}

//求两个矩阵之和、之积
void MatrixMultiplication()  // 乘法实现
{
    bool flag = false;
    const int M = 20, L = 20, K = 20;
    double A[M][L], B[L][K], C[M][K];
    int m1, n1, m2, n2;
    while (flag != true) {
        flag = true;
        cout << "请输入第一个矩阵的维数（行、列）(维数不超20)" << endl;
        cin >> m1 >> n1;

        cout << "请输入第二个矩阵的维数（行、列）(维数不超20)" << endl;
        cin >> m2 >> n2;

        if (n1 != m2) {
            flag = false;
            cout << "第一个矩阵的列数应当等于第二个矩阵的行数，请重新输入！\n";
        }
    }
    cout << "请按行优先输入第一个矩阵的元素" << endl;
    for (int i = 0; i < m1; i++)
        for (int j = 0; j < n1; j++)
            cin >> A[i][j];
    cout << "请按行优先输入第二个矩阵的元素" << endl;
    for (int i = 0; i < m2; i++)
        for (int j = 0; j < n2; j++)
            cin >> B[i][j];

    for (int i = 0; i < m1; i++) {  // 最终矩阵m1行的每一行
        for (int j = 0; j < n2; j++) {  // 最终矩阵n2列的每一列
            C[i][j] = 0;  // 初始化为0
            for (int k = 0; k < n1; k++)
                C[i][j] = C[i][j] + A[i][k] * B[k][j];  // 对应项相乘相加求和
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }
}

void MatrixPlus()  // 加法实现
{
    bool flag = false;
    const int M = 20, L = 20;
    double A[M][L], B[M][L], C[M][L];
    int m, n;
    cout << "请输入相加矩阵的维数（行、列）(维数不超20)" << endl;
    cin >> m >> n;
    cout << "请按行优先输入第一个矩阵的元素" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "请按行优先输入第二个矩阵的元素" << endl;
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
        cout << "请输入您想要实现的功能对应的序号：\n"
            << "1：两矩阵相乘" << endl
            << "2：两矩阵相加" << endl;
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
            cout << "输入错误，请重新输入！";
            flag = false;
        }
    }
    
}

//选择排序与冒泡排序
inline void Swap(int& a, int& b)  // 交换两个元素(使用内联函数定义)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectSort()
{
    int n, minix, select;
    cout << "请输入待排序元素个数:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "请输入待排序元素\n";
    for (int i = 0; i < n;i++) {
        cin >> A[i];
    }
    cout << "请选择升序或者降序：\n"
        << "1：升序" << endl
        << "2：降序" << endl;
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
    cout << "排序后的元素序列为：\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    free(A);
}

void BubbleSort()
{
    bool flag = false;  // 提前终止标志
    int n, minix, select;
    cout << "请输入待排序元素个数:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "请输入待排序元素\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "请选择升序或者降序：\n"
        << "1：升序" << endl
        << "2：降序" << endl;
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
    cout << "排序后的元素序列为：\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    free(A);
}

//快速排序
int Partition(ElemType A[], int low, int high)  // 一趟排序
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

void QuickSort(ElemType A[], int low, int high)  // 递归快排
{
    if (low < high) {
        int key = Partition(A, low, high);
        QuickSort(A, low, key - 1);
        QuickSort(A, key + 1, high);
    }
}

void QuickSortInput()  // 快排输入
{
    int n;
    cout << "请输入待排序元素个数:\n";
    cin >> n;
    ElemType* A = (ElemType*)malloc(n * sizeof(ElemType));
    cout << "请输入待排序元素\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    QuickSort(A, 0, n-1);  // 调用快排
    cout << "排序后的元素序列为：" << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << "\t";
}
// 改进型快速排序
void quicksort(int nums[],int left,int right)
{
	if(left>=right)
		return;
	int a=left,b=right,mid_index=(left+right)/2;
	while(a<=b)
	{
		while(nums[a]<nums[mid_index])
			a++;
		while(nums[b]>nums[mid_index])
			b--;
		if(a<b)
		{
			int temp=nums[a];
			nums[a]=nums[b];
			nums[b]=temp;
			a++;
			b--;
		}
	}
	quicksort(nums,left,b);
	quicksort(nums,i,right);
}



//链表的遍历、增加、删除、修改
//链表节点定义
typedef struct Linknode {
    ElemType data;
    struct Linknode* next;
}*Linklist;
// 初始化
inline Linklist Init_Linklist()
{
    Linklist L = new Linknode;
    L->next = NULL;
    return L;
}
// 判空
bool LinklistEmpty(Linklist L)
{
    if (L->next == NULL)
        return true;
    return false;
}
// 链表遍历
void PrintLinklist(Linklist L)
{
    Linknode* p = L->next;
    if (LinklistEmpty(L)) {
        cout << "该链表为空！" << endl;
        return;
    }
    cout << "该链表各节点的值依次为：" << endl;
    while (p) {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
// 添加元素
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
// 插入元素
bool InsertLinklist(Linklist L, ElemType k, int n)
{
    Linklist p = L;
    for (int i = 0; (i < n - 1 && p != NULL); i++)
        p = p->next;
    if (p == NULL) {
        cout << "插入位置超出链表长度！" << endl;
        return false;
    }
    Linknode* r = new Linknode;
    r->data = k;
    r->next = p->next;
    p->next = r;
    return true;
}
// 删除元素
bool DeleteLinklist(Linklist L,ElemType k)
{
    Linknode* p = L->next;
    Linknode* q = L;
    while (p != NULL && p->data != k) {
        p = p->next;
        q = q->next;
    }
    if (p == NULL) {
        cout << "要删除的元素不存在！" << endl;
        return false;
    }
    q->next = p->next;
    delete p;
    return true;
}
// 修改元素
bool UpdateLinklist(Linklist L, ElemType ok, ElemType k)
{
    Linknode* p = L->next;
    while (p != NULL && p->data != ok)
        p = p->next;
    if (p == NULL) {
        cout << "要修改的元素不存在！" << endl;
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

    // 初始化
    Linklist L = Init_Linklist();

    while (true) {
        cout << "1、向链表添加元素（头或尾）。" << endl
            << "2、遍历输出元素。" << endl
            << "3、插入元素（任意位置）。" << endl
            << "4、删除元素。" << endl
            << "5、修改元素值" << endl
            << "0、退出" << endl
            << "请输入您想实现的功能：" << endl;
        cin >> mode;
        switch (mode) {
        case 1:
            // 元素插入
            cout << "请输入添加的元素值，用空格隔开，回车结束：" << endl;

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

            cout << "请输入插入方式：" << endl
                << "1、头插法" << endl
                << "2、尾插法" << endl;
            cin >> mode;
            flag = (mode == 1 && mode != 2) ? AddLinklistFront(L, arr) : AddLinklistRear(L, arr);
            if (!flag)
                cout << "插入失败！" << endl;
            cout << "插入成功！" << endl;
            break;
        case 2:
            //遍历
            PrintLinklist(L);
            break;
        case 3:
            //插入
            cout << "请输入插入元素及在链表中的位置：" << endl;
            cin >> k >> located;
            flag = InsertLinklist(L, k, located);
            if (!flag)
                cout << "插入失败！" << endl;
            cout << "插入成功！" << endl;
            break;
        case 4:
            // 删除
            cout << "请输入要删除的元素：" << endl;
            cin >> k;
            flag = DeleteLinklist(L, k);
            if (!flag)
                cout << "删除失败！" << endl;
            cout << "删除成功！" << endl;
            break;
        case 5:
            // 修改元素
            cout << "请输入要修改的元素和修改后的值：" << endl;
            cin >> ok >> k;
            flag = UpdateLinklist(L, ok, k);
            if (!flag)
                cout << "修改失败！" << endl;
            cout << "修改成功！" << endl;
            break;
        case 0:
            while (L != NULL) {
                Linknode* p = L->next;
                delete L;
                L = p;
            }
            cout << "所用空间已清除！" << endl;
            return;
        default:
            cout << "输入错误，请重新输入！" << endl;
        }
    }
}

//文件的打开、读写、关闭
// 合并学生成绩
class StudentGrade { // 学生信息类
public:
    int no; // 学号
    string name; // 姓名
    string classname; // 班级
    float language; // 语文成绩
    float english; // 大英成绩
    float math; // 数学成绩
    float average; // 平均成绩
};
// 读取学生成绩，输出与输入学号相同的学生成绩
float getscore(string filename, int stdno) {
    int stdno_temp;
    float score;
    ifstream grades(filename.c_str()); // 打开成绩文件
    if (!grades) { // 判断文件打开是否正确
        cout << "文件打开错误。" << endl;
        return 0;
    }
    bool flag = false;
    while (grades) {
        grades >> stdno_temp >> score;
        if (grades) {  //读正确时
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
// 学生信息写文件运算符重载
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
// 合并学生成绩调用函数
void studentgrade_invoke()
{
    StudentGrade student;
    // 打开文件 
    ifstream basic(".\\textfile\\basic_student_information.txt"); // 学生信息文件 
    ofstream result(".\\textfile\\overall_grade.txt"); // 学生完整信息文件 

    if (!basic || !result) { // 判断文件打开是否正确 
        cout << "文件打开错误。" << endl;
        return;
    }
    result << "学号\t\t姓名\t\t班级\t\t语文\t大英\t数学\t平均" << endl;
    while (basic) {
        // 读文件 
        basic >> student.no >> student.name >> student.classname;
        if (!basic) { // 读正确时才写文件 
            break;
        }
        student.language = getscore(".\\textfile\\language_grade.txt", student.no);
        student.english = getscore(".\\textfile\\english_grade.txt", student.no);
        student.math = getscore(".\\textfile\\math_grade.txt", student.no);
        student.average = (student.language + student.english + student.math) / 3;
        // 写文件 
        result << student;
    }
    //关闭文件 
    result.close();
    basic.close();
    cout << "overall_grade.txt文件建立成功，请查阅！" << endl;
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
