#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define N 100

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
    cout << "Enter a string: ";
    cin >> str;

    for (char& c : str) {
        if (isupper(c)) {
            c = tolower(c);
        }
        else if (islower(c)) {
            c = toupper(c);
        }
    }

    cout << "Modified string: " << str << std::endl;
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

//求两个数的最大公因数和最小公倍数

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

//求两个矩阵之和、之积

//选择排序与冒泡排序

//链表的遍历、增加、删除、修改

//文件的打开、读写、关闭


int main()
{
    //JudgeLeapYears();

    //FindNumber();

    //FindMaxMin();

    //TemperatureConversion();

    CaseConversion();
	return 0;
}
