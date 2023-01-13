#pragma warning(disable:4996)  // ���Ծ�������

#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>

#include "KnowledgeStandardIO.h"

using namespace std;

#define SUIT_NUMBER 4
#define FACE_NUMBER 13  // �˿���ʵ�����õ�


// ��������
/*
����ָ��һ��λ������һ��λ�ô����һ�������ݵļ���
������������У������ڴ���Ϊÿһ������������һ���ڴ滺���������������ݡ��Ӷ�ƥ�䲻ͬ����Ч�ʵĶ���
+-----------------------------------------------------------------------------------------------+
|		<ios>				<istream>				<iostream>				<fstream>			|
|																								|
|	   ios_base	  +---------->istream--------------------------------------->ifstream			|
|		  |		  |				|	+----------------->cin										|
|		  \/	  |				\/																|
|		 ios------+			 iostream--------------------------------------->fstream			|
|				  |				/\																|
|				  |				|	+------------->out\cerr\clog								|
|				  +---------->ostream--------------------------------------->ofstream			|
|																								|
|							<ostream>															|
|	���������ʽ���Ʒ�	���������������������		�����˱�׼���롢���������		�����ļ���������		|
|	״̬�趨������								�Զ�����<ios><ostream>��							|
+-----------------------------------------------------------------------------------------------+

��׼������
�ӱ�׼�����豸(����)������������.
һ��ʹ�� cin ������������룬
">>" �ص㣺
	1. �������� 2. �Կո񡢻س����ָ���
cin��istream��Ķ��󣬳��ˡ�>>�������⣬���ú������£�
	����         ����
	read		�޸�ʽ����ָ���ֽ���
	get			��������ȡ�ַ��������ո�
	getline		��������ȡһ���ַ�
	ignore		��ȡ����������ָ���ַ�
	peek		����������һ���ַ�������������ɾ��
	gcount		ͳ�����������ַ�����
	seekg		�ƶ�������ָ��
	tellg		������������ָ��λ�õ�ָ��ֵ

istream���get����
int get();
istream& get( char& rch );  -->��ȡһ���ַ�,�������հ��ַ�
istream& get( char* pch, int nCount, char delim = '\n' );
					|			|			|
	��ȡ�Ķ���ַ��ŵ�pch��		|			|
						��ȡ�ַ���������		|
									���������'\n'����������ȡ'\n'����delim�������뻺�����У�����ȡ��

istream���getline����
istream& getline(char* pch, int nCount, char delim = '\n');
					|			|				|
	��ȡ����ַ�,�ŵ� pch ��		|				|
						��ȡ�ַ���������			|
									��ȡ�ַ���delim��������ֹ�ַ�����������delim�����뻺������ɾ�����Ҳ���ȡ��

PS:�ַ���������Ϊ n ��������ȡ n-1 ���ַ�����Ҫ��һ����ֹ�ַ� \0
get VS  getline
��֮ͬ����
	����������ȡn-1���ַ���������,
	��������ֵ�Ƿ�0ֵ.
	�������ļ�������,�򷵻�ֵΪ0
��֮ͬ����
	��������ֹ�ַ�ʱ��
	cin.getline()������ָ���Ƶ���ֹ�ַ�֮��
	cin.get() ������ָ���Ƶ���ֹ�ַ�����
	���´μ�����ȡʱ��λ�þͲ�ͬ
*/

// �޲�get����
void get_input1()
{
	char c;
	cout << "enter a sentence:" << endl;
	while (1) {
		c = cin.get();  // һ��ֻ�ܶ�ȡһ���ַ�
		if (c == '\n') 
			break;
		else 
			cout << c;
	}
}
// �в�get����
void get_input2()
{
	char ch[80];
	cout << "enter a sentence:" << endl;  // ���룺I am a techer | You are my student
	cin.get(ch, 70, '|');  // �������л�ȡ���69���ַ�������chָ��Ŀռ��У��ԡ�|�����Ž�������������|����
	cout << ch << endl;  // �����I am a techer
	cin.ignore(1);  // ����������������ɾ��һ��Ԫ��
	cin.get(ch, 70);  // �������л�ȡ���69���ַ�����ch��ָ�ռ���
	cout << ch << endl;  // �����You are my student����|����ignore����б�ɾ��
}
// �в�getline����
void getline_input1()
{
	char ch[80];
	cout << "enter a sentence:" << endl;
	cin.getline(ch, 70, '|'); //��69���ַ�����'|'����(�����뻺������ɾ����|���Ҳ����)
	cout << ch << endl;
	cin.getline(ch, 70); //��69���ַ�����'\n'����
	cout << ch << endl;
}

// ��׼�����
/*
�����׼����豸(��ʾ��)������
һ��ʹ�� cout ������������������
	���磬���������������<<���������.
		cout << ��a=��<< a << endl;
	����			����
	put			�޸�ʽ����һ���ֽ�
	write		�޸�ʽ����һ�ֽ�����
	flush		ˢ�������
	seekp		�ƶ������ָ��
	tellp		�����������ָ��λ�õ�ָ��ֵ
	cout		��ostream��Ķ��󣬳��ˡ�<<�������⣬���ú�������

һ��
��������ĳ�Ա�������������ʽ��(���ó�Ա���������Ҫ������������֮��)
(1)����״̬��־����Ա����setf
	���ø�ʽ��cout.setf(ios::״̬��־);
(2)���״̬��־����Ա����unsetf
	���ø�ʽ��cout.unsetf(ios::״̬��־);
(3)�����������Ա����width���������룩
	���ø�ʽ��cout.width(n);
	ֻ����һ���������Ч�������ɺ�ú��������þ���ʧ��
(4)����ʵ���ľ�������Ա����precision
	���ø�ʽ��cout.precision(n)��
	����n��ʮ����С����ʽ���ʱ������Ч���֡�����fixed��ʽ��scientific��ʽ���ʱ����С��λ��
	
(5)����ַ�����Ա����fill
	���ø�ʽ��cout.fill(ch);

	��cout.setf(ios::״̬��־)��cout.unsetf(ios::״̬��־)�г��õ�״̬��־���£�
		״̬��־			����
		left			��������ڱ����Χ�������
		right			��������ڱ����Χ���Ҷ���
		dec				���������Ļ���Ϊ10
		oct				���������Ļ���Ϊ8
		hex				���������Ļ���Ϊ16
		showpoint		���������ʱ��ǿ����ʾС����
		uppercase		���Կ�ѧ��ʾ����ʽE ����ʮ�����������ĸʱ�ô�д��ʾ
		scientific		�ÿ�ѧ��ʾ����ʽ��ʾ������
		fixed			�ö����ʽ���̶�С��λ������ʾ������
	ios��ĳ���״̬��־��������Щֵ֮ǰҪ����ios::������ж����־���м�����"|"�ָ���

����
������ʽ���Ʒ����������ʽ������ʽ���Ʒ�Ҫ���������֮ǰ��
	����C++����ʽ���Ʒ���ǰ��ĳ�Ա�����еȼ۶�Ӧ�Ĺ�ϵ�����߶���ʵ��ͬ���Ĺ���
	C++����ʽ���Ʒ�һ������š�<<������
	��ʽ��cout << ��ʽ���ַ� << ����ı���������
	��ʽ���Ʒ�			����
	dec					���ú����������10���Ʒ�ʽ��ʾ
	hex					���ú����������16���Ʒ�ʽ��ʾ
	oct					���ú����������8���Ʒ�ʽ��ʾ
	endl				���һ�����з���ˢ�������
	setfill(c)			��������(Ĭ��Ϊ�ո�)
	setprecision(n)		����ʵ������n, ԭ��ͳ�Ա����precisionһ��
						���ö��������ѧ������ʱָС��λ�������ø�����ʱָ��Ч����λ��
	setw(n)				�������n��Ĭ���Ҷ��룩
	setiosflags(flags)	����״̬��־�������'|'�ָ�
	resetiosflags(flags)���״̬��־�������'|'�ָ�

		setiosflags��resetiosflags�ĳ���״̬��־
			״̬��־			����
			ios::left		�������������
			ios::right		������Ҷ������
			ios::fixed		�̶�С��λ�����
			ios::showpos	ǿ��������ʾ����
			ios::uppercase	��ѧ��������16�����������ʱ��ĸ��д
			ios::lowercase	��ѧ��������16�����������ʱ��ĸСд
		״̬��־���Ա������״̬��־��ͬ
*/

// ��Ա�������
void MemberFunctions_output()
{
	cout.setf(ios::left | ios::showpoint); //������룬��һ��ʵ����ʽ��ʾ
	cout.precision(5); //���ó�С��������Ч����Ϊ5 
	cout << 123.456789 << endl;  // �����123.46

	cout.width(10); //������ʾ�����10
	cout.fill('*'); //����ʾ����հ״���*���
	cout.unsetf(ios::left); //���״̬�����
	cout.setf(ios::right); //�����Ҷ���
	cout << 123.456789 << endl;  // �����****123.46

	cout.setf(ios::left | ios::fixed); //������룬�Թ̶�С��λ����ʾ
	cout.precision(3); //����ʵ����ʾ3λС��
	cout << 999.123456 << endl;   // �����999.123

	cout.unsetf(ios::left | ios::fixed); //���״̬�����Ͷ����ʽ
	cout.setf(ios::left | ios::scientific); //��������룬�Կ�ѧ��������ʾ
	cout.precision(3); //���ñ���3λС��
	cout << 123.45678 << endl;  // ���1.235e+02
}
// ���Ʒ����
void ControlSymbols_output()
{
	int a = 128;
	cout << "dec:" << dec << a << endl; //��10������ʽ���
	cout << "hex:" << hex << a << endl; //��16������ʽ���
	cout << "oct:" << oct << a << endl; //��8������ʽ���

	char pt[] = "xi'an";
	cout << setw(10) << pt << endl; //���Ϊ10������ַ���
	cout << setfill('*') << setw(10) << pt << endl;  //ָ�����10������ַ������հ״���"*"���

	double B = 27.123456789;
	cout << setiosflags(ios::scientific) << setprecision(8);  //��ָ����ʽ�����8λС��
	cout << "B=" << B << endl; //���Bֵ

	cout << "B=" << setprecision(4) << B << endl; //4λС��

	cout << resetiosflags(ios::scientific); //�����ʽ�趨
	cout << "B=" << setiosflags(ios::fixed) << setprecision(6) << B;  //��ΪС����ʽ�����С�����6λ

	cout << endl;
}

// �ļ���д
/*
�ļ�����
1���ı��ļ�����һ�����������ַ����ɵļ�����ļ���
	����������ASCII�롢UNICODE�롢GBK����ȵȡ��������ı��༭���༭��
2���������ļ��������������ַ����ɵ��ı��ļ��������ļ�����Ϊ�������ļ���

�ļ������������裺
1������һ���ļ�������
2�����ļ�
3���� / д�ļ�
4���ر��ļ�

ifstream ����ֻ���ж�����
ofstream ����ֻ����д����
fstream ����ȿ��Զ��ļ���Ҳ����д�ļ�

�ļ��Ĵ򿪣�
�ļ�����ĳ�Ա����open(���ļ�)��ʽ���£�
void open (const char * filename, openmode mode)
						|				|
		�ļ���(�� e:\c++\file.txt)		ָ�ļ��򿪷�ʽ���������£�
		��ȱ��·������Ĭ��Ϊ��ǰĿ¼��

		��ʽ				����
		ios::in			Ϊ����(��)�����ļ�
		ios::out		Ϊ���(д)�����ļ�
		ios::ate		���ļ�����ʼλ�����ļ�β��
		ios::app		��������������ļ�ĩβ
		ios::trunc		����ļ��Ѵ�������ɾ�����ļ�ȫ������
		ios::binary		�����Ʒ�ʽ���ļ�
	ÿ��һ���ļ�����һ���ļ�ָ�룬ָ��Ŀ�ʼλ���ɴ򿪷�ʽָ����ÿ�ζ�д�����ļ�ָ��ĵ�ǰλ�ÿ�ʼ��
	���������ļ�����Ĺ��캯�������ļ����������Ĭ��ֵ��open������ȫ��ͬ��
		����fstream objectname("filename",ios::out|ios::binary)

�ļ��Ĺرգ�
1���ر��ļ���������
	�ѻ���������������д���ļ�
	����ļ�������־
	�ж���������ⲿ�ļ�������
2����һ��������������ڽ�����ϵͳҲ���Զ��ر��ļ���
3�����������������û�н�������close()�ر��ļ��󣬸��������������
mode 
*/

// �ı��ļ��Ķ�д
void filewrite()
{
	//���ļ�
	ofstream out(".\\textfile\\text_file.txt");  // ��д�ļ�ģʽ�򿪣�out�Ƕ�������ʹ��ofstream��Ĺ��캯�����ļ����ȼ�������д��
	/*ofstream out1;
	out1.open("text_file.txt");*/
	if (!out) {
		cout << "���ļ�ʧ�ܣ�" << endl;
		return ;
	}
	//д�ļ�
	out << "Welcome to ";  // ʹ������������� << ������ļ���
	char ch[] = "Xi'an Jiaotong University.";
	for (int i = 0; ch[i] != 0; i++)
		out.put(ch[i]);   // ����ַ����룬ֱ���ַ���������ʹ��put��Ա�������뵽�ļ���
	out.close(); //�ر��ļ�
}
void fileread()
{
	//���ļ�
	ifstream in(".\\textfile\\text_file.txt");  // �Զ��ļ�ģʽ�򿪣�in�Ƕ�������ʹ��ifstream��Ĺ��캯�����ļ�
	if (!in){
		cout << "�����Դ��ļ�" << endl;
		return ;
	}
	//���ļ�
	char ch[80];
	in >> ch; //�� >> ��ȡ��һ������Welcome����cin��ͬ���Կո�ͻس���Ϊ�ָ�����ʹ������������� >> ���뵽�ռ���
	cout << ch;
	in >> ch; //��ȡ�ڶ�������to 
	cout << ch;
	while (in)  {  //ʣ�ಿ����get������������ʾ
		char c = in.get();
		if (in)   // Ϊ�μ�if�ж�ԭ������
			cout << c;
	}
	/*
	����жϵ����ļ�ĩβ��
	��ȡָ�빤�����裺�Ƚ�ָ�������������ռ��У�Ȼ��ָ����ƣ�����ķ���ֵ�Ƿ�Ϊ���ɱ�����������ݾ����������ǵ�ǰָ��ָ������ݡ�
	��û�ж����ļ�β��ʱ��ifstream ���� in �൱��һ��trueֵ������ֱ����ȡ��������Ч���ݺ�in��Ȼ�൱��true����ʱ�ٶ�ȡһ���ļ���in�ű�����൱��falseֵ�Ķ���
	*/
	in.close(); //�ر��ļ�
}
// �ɼ��ļ�����ƽ���ֲ����
void GradeCompute()
{
	char ch[20];
	double math, eng, phy;
	double avg;
	ifstream fin(".\\textfile\\grade_flie.txt");
	ofstream fout(".\\textfile\\grade_result_file.txt");
	if (!fin || !fout) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	while (fin) {
		fin >> ch >> math >> eng >> phy;  // ���ж�ȡ��һ�ζ�ȡһ��Ԫ�أ���ȡ��֮���ȡָ���Զ�ָ����һ�е�һ����Чλ��
		if (fin) {
			avg = (math + eng + phy) / 3;
			fout << ch << '\t' << math << '\t' << eng << '\t' << phy << '\t' << avg << endl;
		}
	}
}

// �������ļ��Ķ�д
/*
�Զ������ļ����в���ʱ�����ļ�Ҫָ����ʽ ios::binary
�Ӷ������ļ��������ݿɵ���istream�����ṩ�ĳ�Ա������
����ԭ��Ϊ��
	istream& read(char* buffer, int len)
��������ļ�������ݿɵ���ostream�����ṩ�ĳ�Ա������
����ԭ��Ϊ��
	ostream& write(const char* buffer,int len)

	���������ĸ�ʽ��ͬ��
	��һ���������ַ�ָ�룬����ָ�����������������ŵ��ڴ�ռ��ַ
	�ڶ�����������������ʾҪ������������ݵ��ֽ���
*/

// �������ļ���˳���д�������д
/*
istream ���������ָ��ĳ�Ա����:
1��istream & istream :: seekg ( long pos) ;
	��ָ���������ʼλ������ƶ���posָ���ֽ�
2��istream & istream :: seekg ( long off, ios::seek_dir );
	��ָ������� seek_dir λ���ƶ� , off ָ���ֽ�
3��long & istream :: tellg ();
	���ض�ָ�뵱ǰ��ָλ��ֵ

	ios::seek_dir ֵ��
	cur		��ǰ��ָ�����ڵĵ�ǰλ��
	beg		�ļ����Ŀ�ʼλ�� ���ļ�ͷ����
	end		�ļ����Ľ�β��
*/
class Student // ������ 
{
	char Name[10]; //*Name;
	char Class[10]; //*Class;
	char Sex;
	int Age;
public:
	Student() { }
	Student(char* Name, char* Class, char sex, int age)
	{
		//this->Name = new char[strlen(Name) + 1];
		//this->Class = new char[strlen(Class) + 1];
		strcpy(this->Name, Name);
		strcpy(this->Class, Class);
		Sex = sex;
		Age = age;
	}
	void Showme()
	{
		cout << *Name << '\t' << *Class << '\t' << Sex << '\t' << Age << endl;
	}
	~Student() {
		//delete[] Name;
		//delete[] Class;
	}
};
void Binaryfile()
{
	Student stu[3] = {
	Student("wang","dianqi11",'m',27),
	Student("liu","jixie01",'f',24),
	Student("li","shengwu12",'m',39) 
	};  // ����һ����ά���飬�������ѧ����stu[i]�ֱ�Ϊ�����ڶ�ά���飨ѧ���ࣩ���׵�ַָ�룬��һά�д�������׵�ַָ��
	//���ļ�
	ofstream file1("binary_file.dat", ios::binary);  // �Զ�������ʽ���ļ�
	if (!file1) {
		cout << "�ļ���ʧ��!"; 
		return;
	}
	//д�ļ�
	for (int i = 0; i < 3; i++)
		file1.write((char*)&stu[i], sizeof(stu[i]));  // ����ָ��ǿ��ת��Ϊ�ַ�ָ�루ָ��ָ�����ռ��С���䣩����һ����Ĵ�С������ļ���
	file1.close(); //�ر��ļ�
	///////����Ϊ���ļ�����ʾ����//////////
	Student stu2; //��������
	//���ļ�
	ifstream file2("binary_file.dat", ios::binary);
	if (!file2) {
		cout << "�ļ���ʧ��!"; 
		return;
	}
	//���ļ�
	while (file2)
	{
		file2.read((char*)&stu2, sizeof(stu2));  // ��ָ��һ�����С��ָ��ǿ��ת��Ϊ�ַ�ָ�룬�������ļ���ȡ�����ݣ���СΪһ����Ĵ�С
		if (file2) 
			stu2.Showme();
	}
	//ʵ�������ȡ���������ѧ����Ϣ
	file2.seekg(0, ios::end);  // ��λ�ļ�ָ�뵽�ļ�ĩβ
	int len = file2.tellg();  // �õ��ļ�λ�ã������������ļ���С��
	if (len <= 0) {
		cout << "�ļ�ָ�붨λʧ�ܣ�";
		return;
	}
	for (int i = len / sizeof(stu2) - 1; i >= 0; i--) {  // ��һ�����СΪ��λ��ǰ�ƶ�ָ��
		file2.seekg(i * sizeof(stu2));
		file2.read((char*)&stu2, sizeof(stu2));
		stu2.Showme();
	}
	//�ر��ļ�
	file2.close();
}


// �ļ�����ʵ��
/*====================================================================================================*/
// �˿����ϴ�ƽ�����浽�ļ�
// �˿���
class Card 
{
public:
	string suit; // ��ɫ
	string face; // ��ֵ
};
// �˿˹�����
class CardManager
{
private:
	Card deck[SUIT_NUMBER][FACE_NUMBER];
public:
	CardManager();
	void shuffle(); // ϴ��
	void deal(); //����
};
CardManager::CardManager()
{
	string suit[] = { "����","����", "÷��", "����" };
	string face[] = {
		"A","2","3","4","5","6","7","8","9","10","J","Q","K"
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[i][j].suit = suit[i];
			deck[i][j].face = face[j];
		}
	}
}
void CardManager::shuffle()
{
	srand(time(NULL)); // ���������ʼ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			int m = rand() % 4; // �������
			int k = rand() % 13; // �������
			Card temp = deck[i][j];
			deck[i][j] = deck[m][k];
			deck[m][k] = temp;
			// ͨ��������齻��ʵ��ϴ��
		}
	}
}
void CardManager::deal()
{
	char* person[4] = { "����","����","����","����" };
	ofstream poker;
	poker.open(".\\textfile\\poker_file.txt");
	for (int i = 0; i < 4; i++) {
		poker << person[i] << "���ƣ�" << endl;
		for (int j = 0; j < 13; j++) {
			poker << "��" << j + 1 << "�ţ�  "
				<< deck[i][j].suit << deck[i][j].face << "\t\t";
			if ((j + 1) % 4 == 0)
				poker << endl;
		}
		poker << endl << endl;
	}
	poker.close();
}
// �˿��Զ����Ƶ��ú���
void CardPlay_invoke()
{
	CardManager player;
	player.shuffle();
	player.deal();
}


// ͳ���ļ����ʴ�Ƶ
class wordtype
{
public:
	char word[20]; 
	int count;
};

int getwords(wordtype* words)
{
	ifstream wordsfile(".\\textfile\\words_source.txt"); // ��Ӣ���ļ� 
	if (!wordsfile) {
		cout << "�ļ��򿪴���" << endl;
		return 1;
	}

	int n = 0;  // ��������
	char word[20];  // �洢ÿ������
	int m;  // ������������λ��
	while (wordsfile) {
		wordsfile >> word; // ������ 
		if (!wordsfile) { // �ļ���βʱ�˳�ѭ�� 
			break;
		}
		bool flag = false;
		for (m = 0; m < n; m++) {
			if (!strcmp(word, words[m].word)) { // �Ѵ��ڸõ��� 
				words[m].count++; // ԭ�е��ʼ�����1 
				flag = true;
				break;
			}
		}
		if (!flag) { // �����µ��� 
			words[m].count = 1; // �µ��ʼ���Ϊ1 
			strcpy(words[m].word, word); // �����µ��� 
			n++; // �ܵ��ʼ�����1 
		}
	}
	wordsfile.close(); // �ر��ļ� 
	return n; // ���ص��ʸ��� 
}
// ���ʴ�Ƶͳ�ƺ�������
void words_invoke()
{
	wordtype words[200] = { "",0 };  // ���ʽṹ������������ʼ�� 
	int n = getwords(words); // ���û�ȡ���ʵĺ��� 
	cout << "Ӣ�ĵ���ͳ�ƽ�����£�" << endl;
	for (int m = 0; m < n; m++)
		cout << words[m].word << ':' << words[m].count << endl;
	cout << "��������" << n << "�����ʡ�" << endl;
}


// ����MP3�ļ�
bool mp3cpy(const char* szDestFile, const char* szOrigFile)
{
	ofstream d_music(szDestFile, ios::binary); // �Զ����Ʒ�ʽ��Ŀ���ļ� 
	ifstream s_music(szOrigFile, ios::binary); // �Զ����Ʒ�ʽ��ԭʼ�ļ� 

	bool bRet = true;  // ���Ƴɹ����ı�־
	if (s_music.bad()) { // ԭʼ�ļ����� 
		bRet = false;
	}
	else {
		s_music.seekg(0L, ios::beg); // ��λԭʼ�ļ���ʼ�� 
		while (!s_music.eof()) { // ԭʼ�ļ�δ��β 
			char szBuf[256] = { 0 };
			s_music.read(szBuf, sizeof(char) * 256); // ÿ�ζ�ȡԭʼ�ļ����256�ֽ� 
			int length = s_music.gcount(); // ʵ�ʶ�ȡ���ֽ��� 
			if (d_music.bad()) { // Ŀ���ļ����� 
				bRet = false;
				break;
			}
			d_music.write(szBuf, length); // ׷��ģʽ��ÿ��д��Ŀ���ļ�length���ֽ� 
		}
	}
	d_music.close(); // �ر�Ŀ���ļ� 
	s_music.close(); // �ر�ԭʼ�ļ� 

	return bRet;
}
// ����MP3�ļ�����
void mp3cpy_invoke()
{
	char szOrigFile[50]; // ԭʼ�ļ��� 
	char szDestFile[50]; // Ŀ���ļ��� 
	cout << "������ԭʼ�ļ�����Ŀ���ļ�����";
	cin >> szOrigFile;
	cin >> szDestFile;

	bool bRet = mp3cpy(szDestFile, szOrigFile); // �����ļ����ƺ��� 
	if (bRet) {
		cout << "�ļ����Ƴɹ���" << endl;
	}
	else {
		cout << "�ļ�����ʧ�ܣ�" << endl;
	}
}



void StandardIOEntrance()
{
	//get_input1();
	//get_input2();
	//getline_input1();
	//MemberFunctions_output();
	//ControlSymbols_output();
	//filewrite();
	//fileread();
	//GradeCompute();
	//Binaryfile();
	//CardPlay_invoke();
	//words_invoke();
	mp3cpy_invoke();
}