#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include "KnowledgeStandardIO.h"

using namespace std;


// 流及流库
/*
流是指从一个位置向另一个位置传输的一连串数据的集合
输入输出过程中，会在内存中为每一个数据流开辟一个内存缓冲区，用来存数据。从而匹配不同工作效率的对象。
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
|	定义基本格式控制符	定义了输入流、输出流类		定义了标准输入、输出流对象		定义文件操作流类		|
|	状态设定函数等								自动包含<ios><ostream>等							|
+-----------------------------------------------------------------------------------------------+

标准输入流
从标准输入设备(键盘)流向程序的数据.
一般使用 cin 流对象进行输入，
">>" 特点：
	1. 符号重载 2. 以空格、回车做分隔符
cin是istream类的对象，除了“>>”符号外，常用函数如下：
	函数         功能
	read		无格式输入指定字节数
	get			从流中提取字符，包括空格
	getline		从流中提取一行字符
	ignore		提取并丢弃流中指定字符
	peek		返回流中下一个字符，但不从流中删除
	gcount		统计最后输入的字符个数
	seekg		移动输入流指针
	tellg		返回输入流中指定位置的指针值

istream类的get函数
int get();
istream& get( char& rch );  -->读取一个字符,不跳过空白字符
istream& get( char* pch, int nCount, char delim = '\n' );
					|			|			|
	读取的多个字符放到pch中		|			|
						读取字符数量上限		|
									读多个字至'\n'结束，不提取'\n'（即delim仍在输入缓冲区中，不提取）

istream类的getline函数
istream& getline(char* pch, int nCount, char delim = '\n');
					|			|				|
	读取多个字符,放到 pch 中		|				|
						读取字符数量上限			|
									读取字符至delim结束，终止字符被舍弃（即delim从输入缓冲区中删除，且不提取）

PS:字符数量上限为 n ，则最多读取 n-1 个字符，后要加一个终止字符 \0
get VS  getline
相同之处：
	从输入流提取n-1个字符放入数组,
	函数返回值是非0值.
	若遇到文件结束符,则返回值为0
不同之处：
	当读到终止字符时，
	cin.getline()——将指针移到终止字符之后。
	cin.get() ——将指针移到终止字符处。
	则下次继续读取时的位置就不同
*/

// 无参get输入
void get_input1()
{
	char c;
	cout << "enter a sentence:" << endl;
	while (1) {
		c = cin.get();  // 一次只能读取一个字符
		if (c == '\n') 
			break;
		else 
			cout << c;
	}
}
// 有参get输入
void get_input2()
{
	char ch[80];
	cout << "enter a sentence:" << endl;  // 输入：I am a techer | You are my student
	cin.get(ch, 70, '|');  // 从输入中获取最多69个字符，存入ch指向的空间中，以‘|’符号结束（不包括‘|’）
	cout << ch << endl;  // 输出：I am a techer
	cin.ignore(1);  // 从输入流缓冲区中删除一个元素
	cin.get(ch, 70);  // 从输入中获取最多69个字符存入ch所指空间中
	cout << ch << endl;  // 输出：You are my student，‘|’在ignore语句中被删除
}
// 有参getline输入
void getline_input1()
{
	char ch[80];
	cout << "enter a sentence:" << endl;
	cin.getline(ch, 70, '|'); //读69个字符或遇'|'结束(从输入缓冲区中删除‘|’且不输出)
	cout << ch << endl;
	cin.getline(ch, 70); //读69个字符或遇'\n'结束
	cout << ch << endl;
}

// 标准输出流
/*
流向标准输出设备(显示器)的数据
一般使用 cout 流对象进行输出操作。
	例如，用流插入运算符“<<”输出数据.
		cout << “a=”<< a << endl;
	函数			功能
	put			无格式插入一个字节
	write		无格式插入一字节序列
	flush		刷新输出流
	seekp		移动输出流指针
	tellp		返回输出流中指定位置的指针值
	cout		是ostream类的对象，除了“<<”符号外，常用函数如下

一、
用流对象的成员函数控制输出格式：(设置成员函数的语句要在输出内容语句之上)
(1)设置状态标志流成员函数setf
	调用格式：cout.setf(ios::状态标志);
(2)清除状态标志流成员函数unsetf
	调用格式：cout.unsetf(ios::状态标志);
(3)设置域宽流成员函数width（四舍五入）
	调用格式：cout.width(n);
	只对下一次流输出有效，输出完成后该函数的作用就消失。
(4)设置实数的精度流成员函数precision
	调用格式：cout.precision(n)；
	参数n在十进制小数形式输出时代表有效数字。在以fixed形式和scientific形式输出时代表小数位数
	
(5)填充字符流成员函数fill
	调用格式：cout.fill(ch);

	在cout.setf(ios::状态标志)和cout.unsetf(ios::状态标志)中常用的状态标志如下：
		状态标志			功能
		left			输出数据在本域宽范围内左对齐
		right			输出数据在本域宽范围内右对齐
		dec				设置整数的基数为10
		oct				设置整数的基数为8
		hex				设置整数的基数为16
		showpoint		浮点数输出时，强制显示小数点
		uppercase		在以科学表示法格式E 和以十六进制输出字母时用大写表示
		scientific		用科学表示法格式显示浮点数
		fixed			用定点格式（固定小数位数）显示浮点数
	ios类的常用状态标志在引用这些值之前要加上ios::，如果有多项标志，中间则用"|"分隔。

二、
用流格式控制符控制输出格式：（格式控制符要在输出内容之前）
	多数C++流格式控制符与前面的成员函数有等价对应的关系，两者都可实现同样的功能
	C++流格式控制符一般与符号“<<”联用
	格式：cout << 格式空字符 << 输出的变量或内容
	格式控制符			功能
	dec					设置后面的整数按10进制方式显示
	hex					设置后面的整数按16进制方式显示
	oct					设置后面的整数按8进制方式显示
	endl				输出一个换行符并刷新输出流
	setfill(c)			设置填充符(默认为空格)
	setprecision(n)		设置实数精度n, 原理和成员函数precision一样
						设置定点数或科学计数法时指小数位数，设置浮点数时指有效数字位数
	setw(n)				设置域宽n（默认右对齐）
	setiosflags(flags)	设置状态标志，多个用'|'分隔
	resetiosflags(flags)清除状态标志，多个用'|'分隔

		setiosflags和resetiosflags的常用状态标志
			状态标志			功能
			ios::left		按域宽左对齐输出
			ios::right		按域宽右对齐输出
			ios::fixed		固定小数位数输出
			ios::showpos	强制设置显示正号
			ios::uppercase	科学记数法或16进制输出数据时字母大写
			ios::lowercase	科学记数法或16进制输出数据时字母小写
		状态标志与成员函数的状态标志相同
*/

// 成员函数输出
void MemberFunctions_output()
{
	cout.setf(ios::left | ios::showpoint); //设左对齐，以一般实数方式显示
	cout.precision(5); //设置除小数点外有效数字为5 
	cout << 123.456789 << endl;  // 输出：123.46

	cout.width(10); //设置显示区域宽10
	cout.fill('*'); //在显示区域空白处用*填充
	cout.unsetf(ios::left); //清除状态左对齐
	cout.setf(ios::right); //设置右对齐
	cout << 123.456789 << endl;  // 输出：****123.46

	cout.setf(ios::left | ios::fixed); //设左对齐，以固定小数位数显示
	cout.precision(3); //设置实数显示3位小数
	cout << 999.123456 << endl;   // 输出：999.123

	cout.unsetf(ios::left | ios::fixed); //清除状态左对齐和定点格式
	cout.setf(ios::left | ios::scientific); //设置左对齐，以科学计数法显示
	cout.precision(3); //设置保留3位小数
	cout << 123.45678 << endl;  // 输出1.235e+02
}
// 控制符输出
void ControlSymbols_output()
{
	int a = 128;
	cout << "dec:" << dec << a << endl; //以10进制形式输出
	cout << "hex:" << hex << a << endl; //以16进制形式输出
	cout << "oct:" << oct << a << endl; //以8进制形式输出

	char pt[] = "xi'an";
	cout << setw(10) << pt << endl; //域宽为10，输出字符串
	cout << setfill('*') << setw(10) << pt << endl;  //指定域宽10，输出字符串，空白处以"*"填充

	double B = 27.123456789;
	cout << setiosflags(ios::scientific) << setprecision(8);  //按指数形式输出，8位小数
	cout << "B=" << B << endl; //输出B值

	cout << "B=" << setprecision(4) << B << endl; //4位小数

	cout << resetiosflags(ios::scientific); //清除格式设定
	cout << "B=" << setiosflags(ios::fixed) << setprecision(6) << B;  //改为小数形式输出，小数点后6位

	cout << endl;
}

// 文件读写
/*
文件分类
1、文本文件：是一种由若干行字符构成的计算机文件。
	其编码可以是ASCII码、UNICODE码、GBK编码等等。可以用文本编辑器编辑。
2、二进制文件：除了上述以字符构成的文本文件，其他文件均称为二进制文件。

文件操作基本步骤：
1、定义一个文件流对象
2、打开文件
3、读 / 写文件
4、关闭文件

ifstream 对象只进行读操作
ofstream 对象只进行写操作
fstream 对象既可以读文件，也可以写文件

文件的打开：
文件流类的成员函数open(打开文件)形式如下：
void open (const char * filename, openmode mode)
						|				|
		文件名(如 e:\c++\file.txt)		指文件打开方式，内容如下：
		若缺少路径，则默认为当前目录。

		方式				功能
		ios::in			为输入(读)而打开文件
		ios::out		为输出(写)而打开文件
		ios::ate		打开文件，初始位置在文件尾部
		ios::app		所有输出附加在文件末尾
		ios::trunc		如果文件已存在则先删除该文件全部数据
		ios::binary		二进制方式打开文件
	每打开一个文件都有一个文件指针，指针的开始位置由打开方式指定，每次读写都从文件指针的当前位置开始。
	还可以用文件流类的构造函数来打开文件，其参数和默认值与open函数完全相同。
		例：fstream objectname("filename",ios::out|ios::binary)

文件的关闭：
1、关闭文件操作包括
	把缓冲区数据完整地写入文件
	添加文件结束标志
	切断流对象和外部文件的连接
2、当一个流对象的生存期结束，系统也会自动关闭文件；
3、若流对象的生存期没有结束，用close()关闭文件后，该流对象可以重用
mode 
*/




void StandardIOEntrance()
{
	//get_input1();
	//get_input2();
	//getline_input1();
	//MemberFunctions_output();
	ControlSymbols_output();
}