#include<iostream>
using namespace std;
int main()
{
	char name1[50], name2[50];  //������������������ʹ��
	//cin >> name1 >> name2;  //��������,�Կո�tab��enterΪ�ָ���
	cin.getline(name1, 50);  //�Իس�Ϊ�ָ���
	cin.getline(name2, 50);
	cout << "#######################################" << endl;
	cout << name1 << endl;
	cout << endl;
	cout << "Happy birthday to you!" << endl;
	cout << endl;
	cout << "            Sincerely yours " << name2 << endl;
	cout << "#######################################" << endl;
	//cout << "hello world" << endl;
	return 0;
}