#include<iostream>
using namespace std;
int main()
{
	char name1[50], name2[50];  //变量声明，先声明后使用
	//cin >> name1 >> name2;  //变量输入,以空格、tab、enter为分隔符
	cin.getline(name1, 50);  //以回车为分隔符
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