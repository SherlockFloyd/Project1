#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define N 100

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

//���������������������С������

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

//����������֮�͡�֮��

//ѡ��������ð������

//����ı��������ӡ�ɾ�����޸�

//�ļ��Ĵ򿪡���д���ر�


int main()
{
    //JudgeLeapYears();

    //FindNumber();

    //FindMaxMin();

    //TemperatureConversion();

    CaseConversion();
	return 0;
}
