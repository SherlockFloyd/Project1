#pragma warning(disable:4996)  // 忽略警告提醒

#include<iostream>
#include<windows.h>
#include<iomanip>
#include<cstring>
#include<vector>
#include<algorithm>
#include "KnowledgeTemplate.h"

using namespace std;

//函数模板
/*
解决函数重载重复代码问题

函数模板是用类型做参数，设计出的通用的函数。
其定义形式为：
template <class T1,class T2,,,>  // T1,T2是变量类型，需要用在下面的函数定义中
函数返回类型 函数名(函数参数表)
{
	//函数模板定义
}
其中template表示定义的是模板，< >里是模板的类型参数，可以是一个或多个。

模板工作方式
1、函数模板只是说明，不能直接执行，需要实例化为模板函数后才能执行
2、在说明了一个函数模板后，当编译系统发现有一个对应的函数调用时，将根据实参中的类型来确认是否匹配函数模板中对应的形参，然后生成一个重载函数。

例：
	函数模板如下：						编译时发现：										编译系统产生实际函数：
	template <class T>					......											int max_function(int a,int b)
	T max_function(T a,T b)		-->		max_function(6,7);  //发现参数为整形		-->		{
	{									......												return a>b?a:b;
		return a>b?a:b;																	}
	}
*/

// 函数模板求数组元素最小值
// 模板begin-----------------------
template <class T>  // T为返回值及形参变量类型
T min_fun(T a[], int n)  // 形参为数组和数组元素个数，数组类型待定，编译时根据函数自动产生
{
	int i; T minv = a[0];
	for (i = 1; i < n; i++) {
		if (minv > a[i])
			minv = a[i];
	}
	return minv;
}
// 模板end-------------------------
// 函数模板调用函数
void min_fun_invoke()
{
	int a[] = { 1,3,0,2,7,6,4,5,2 };  // 数组元素类型为int型
	double b[] = {1.2,-3.4,6.8,9,8 };  // 数组元素类型为double型
	cout << "a数组的最小值为 : "
		<< min_fun(a,9) << endl;  // 调用模板，在编译时实例化参数为int型
	cout << "b数组的最小值为 : "
		<< min_fun(b,5) << endl;  // 调用模板，在编译时实例化参数为double型
}

//类模板
/*
类是对问题空间的抽象，而类模板则是对类的抽象，是对一批仅仅成员数据类型不同的类的抽象
程序中可以首先定义一个类模板，然后通过使用不同的实参生成不同的类。
类模板的定义格式：
template <class <类型参数>>  // 此处的class指某种类型，不是C++中的类
class <类名>
{
	……
};
类模板的使用方法
格式： 
类模板名 <数据类型> 对象名;
例：
	template <class T>
	class stack
	{
		T dat[100];
		int top;
	public:
		//进栈
		void push(T e)
		{ …… }
		//出栈
		T pop( )
		{ …… }
	}

	stack <int> s1; // 定义一个整数类型栈
	stack <char> s2; // 定义一个字符类型栈

在C++的标准模板库(STL)中，定义了大量类模板（其中也包括栈），
	使用这些优秀的类模板可以我们提高编程效率，提高程序可靠性
*/

// STL
/*
STL是一个具有工业强度的，高效的C++程序库
它实现了诸多在计算机科学领域里常用的基本数据结构和基本算法
STL主要包含了容器、算法、迭代器
STL系由Alexander Stepanov和Meng Lee等人创造于惠普实验室，于1994年2月年正式成为ANSI/ISO C++的一部份

容器：
是容纳、包含相同类型元素的对象，主要用类模板实现
1、序列型容器：容器中的元素按线性结构组织起来，可以逐个读写元素。主要代表有vector(向量)、deque(双端队列) 、list(双向链表)
2、关联型容器：关联容器通过键(key)存储和读取元素。主要有map(映射)、set(集合)等
3、容器适配器：是对前面提到的某些容器(如vector)进行再包装，使其变为另一种容器。典型的有栈(stack)、队列(queue)等

迭代器：
是用于确定元素位置的数据类型，可用来遍历容器中的元素
通过迭代器可以读取、修改它指向的元素，它的用法和指针类似
每一种容器都定义了一种迭代器

	定义一个容器类的迭代器的方法：
	容器类名<元素类型>::iterator 变量名;
		例： vector<int>:: iterator it;
	访问一个迭代器指向的元素：
	* 迭代器变量名
		例： *it=5；

算法：
由许多函数模版组成的集合，实现了大量通用算法，用于操控各种容器
STL中提供的算法涉及到：比较、交换、查找、遍历、复制、修改、移除、反转、排序、合并等。大约有70种标准算法
算法通过迭代器来操纵容器中的元素
算法可以处理容器，也可以处理C语言的数组
*/

//Vector
/*
*vector主要特征
vector 实际上就是对动态数组封装
可以像数组一样可以使用下标访问元素，若vector长度为n，则其下标为 0~n-1
根据下标访问元素效率高
vector对象的空间随着插入删除操作自动调整
因为空间自动调整比较耗费时间，因此频繁插入删除的情况下，vector效率稍差
使用vector必须包含头文件#include<vector>
vector-对象创建
创建一个空向量
vector<int> v1; // int 类型向量
vector<string> s1; // string 类型向量

从已有向量复制创建向量
vector<int> v2( v1 ); // 拷贝v1内容到v2（拷贝构造函数）

创建10个元素的向量
vector<string> s2( 10 );

创建10个元素的向量，所有元素都是 1.5
vector<double> v3( 10, 1.5 );

创建向量指针
vector<int> *pvec = new vector<int>( 10, 1.5 );

vector-向量大小相关函数
	函数				功能
	v.size()		返回向量的大小
	v.max_size()	返回向量可容纳的最大个数
	v.empty()		返回向量是否为空
	v.resize(n)		调整向量大小，使其可以容纳n个元素，如果 n < v.size() 则删除多出来的元素; 否则，添加新元素
	v.resize(n,t)	调整向量的大小，使其可以容纳n个元素，所有新添加的元素初始化为t
	v.capacity()	获取向量的容量，再分配内存空间之前所能容纳的元素个数

	| 0	| 1	| 2	|..	|23	|	|..	|..	|
						|			|
					v.size()	v.capacity()

主要成员函数由以下实例展示：
*/

void vector1_invoke()
{
	//创建空对象
	vector<int> v1;
	//vector-尾部添加元素
	v1.push_back(1);												// | 1	|	|	|
	v1.push_back(2);												// | 1	| 2	|	|	|
	//任意位置插入元素  // v1.begin(), v1.end() 获取相应位置的迭代器
	v1.insert(v1.begin(), 0); //头部插入0						// | 0	| 1	| 2	|	|	|
	v1.insert(v1.end(), 4); //尾部插入4						// | 0	| 1	| 2	| 4	|	|
	v1.insert(v1.end() - 1, 3); //倒数第二位置3				// | 0	| 1	| 2	| 3	| 4	|	|
	//用下标访问元素
	v1[4] = 10; // 修改4号元素的值为10，									// | 0	| 1	| 2	| 3	|10	|	|
	//v1[5]=6; 超界错误
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";  // 输出	0	1	2	3	10
	//删除尾部元素
	v1.pop_back(); //删除 10												// | 0	| 1	| 2	| 3	|	|	|
	//删除任意元素
	v1.erase(v1.begin()); //删除0									// | 1	| 2	| 3	|	|	|	|
	v1.erase(v1.begin(), v1.end()); //全删					// | 	| 	| 	|	|	|	|
	v1.clear();  // 清空向量
}

//vector迭代器
/*
向量上的迭代器定义、使用
	vector<int>::iterator it(迭代器名称)； *it = 5;
vector上迭代器支持随机访问：
1. 提供读写操作
2. 并能在数据中随机移动(前后，跳跃式)
用加、减操作移动迭代器：
	it++; ++it; //指向下一元素
	it--; --it; //指向前一元素
	it + i： 返回指向 it 后面的第i个元素的迭代器
	it – i ： 返回指向 it 前面的第i个元素的迭代器
用 <, <=, >, >=，==，!= 判断迭代器前后、相等关系：
	it1 < it2 // 表示判断是否 it1 在 it2 之前
	其中 <、>、<=、>= 在vector向量容器中成立，在其他非线性容器中不成立

begin()和end()函数
每种容器都定义了一对命名为begin和end的函数，用于返回迭代器。如果容器中有元素，由begin返回的迭代器指向第一个元素：
	it = v1.begin(); // 指向v1[0]
由 end 返回的迭代器指向vector的末端元素的下一个。通常称为超出末端迭代器，表明它指向了一个不存在存在的元素
	it = v1.end(); // 指向末端元素的下一个
如果vector为空，begin返回的迭代器不end返回的迭代器相同

用迭代器读取元素
	vector<int>::iterator it;
	for(it=v1.begin(); it<v1.end(); it++)
		cout<<*it<<" ";

以迭代器为参数的插入删除函数
	v.insert(p,t)
	在迭代器p所指向的元素前面插入值为 t 的元素

	v.insert(p,n,t)
	在迭代器p所指向的元素前面插入n个值为t的新元素

	v.insert(p,b,e)
	在迭代器p所指向的元素前面插入迭代器b和e标记的范围内的元素（包含b 不包含e）

	v.erase(p)
	删除迭代器p指向的容器中的元素

	v.erase(b,e)
	删除迭代器b和e所标记范围内的元素

通过迭代器进行删除和插入由以下实例给出：
*/
void vector2_invoke()
{
	vector<int> v2(3, 1);															// | 1	| 1	| 1	|	|	|	|	|	|  v2
	vector<int> v1(4, 0);															// | 0	| 0	| 0	| 0	|	|	|	|	|  v1
	v1.insert(v1.begin(), 5); // 在头部插入5								// | 5	| 0	| 0	| 0	| 0	|	|	|	|  v1
	v1.insert(v1.end(), 7); // 在尾部插入7								// | 5	| 0	| 0	| 0	| 0	| 7	|	|	|  v1
	//定义一个迭代器it，指向数组中下标为4的元素																 it
	vector<int>::iterator it = v1.begin() + 4;										// | 5	| 0	| 0	| 0	| 0	| 7	|	|	|  v1
	v1.insert(it, 9);  // 在下标为4处插入9								// | 5	| 0	| 0	| 0	| 9	| 0	| 7	|	|  v1
	// 删除偶数元素
	for (it = v1.begin(); it < v1.end(); ) {
		if (*it % 2 == 0) it = v1.erase(it);
		else it++;
	}																				// | 5	| 9	| 7	|	|	|	|	|	|  v1
	// 将v1的一部分拷贝到v2
	v2.insert(v2.begin(), v1.begin(), v1.begin() + 2);			// | 5	| 9	| 1	| 1	| 1	|	|	|	|  v2

}
/*
用迭代器循环删除的一个问题
以下代码错误：
	vecotr<int>::iterator it = vc.begin();
	for( ; it != vc.end(); it++ )
	{ 
		if( ***** ) 
			vc.erase(it); 
	}
原因：erase()删除元素后，it失效，并不是指向下一个元素（此时it指向删除元素的下一个元素，但删除元素之后的元素全部前移，导致下标减一）
解决方案：
	for(it=v1.begin(); it<v1.end(); ) 
	{
		if(*******) 
			it=v1.erase(it);
		else it++;
	}
在C++11标准中，erase() 会返回一个iterator，这个iterator指向了“当前删除元素的后继元素”

*/

//vector上的应用算法
/*
排序 sort( )
查找 find( )
替换 replace( )
合并 merge( )
反序 reverse( )
统计 count( )
其他等等算法

许多算法往往以迭代器作参数。比如排序和查找都需要两个迭代器参数（表示起始位置、终止位置）
有的算法返回一个迭代器。比如find算法，在容器中查找一个元素，并返回一个指向该元素的迭代器
算法主要在头文件<algorithm>和<numeric>中定义，使用时必须包含其中一个
*/
/*
find()
简化形式： find( first, last, val)
first 和 last 这两个参数都是容器的迭代器，它们给出了容器中的查找区间起点和终点。
	这个区间是个左闭右开的区间[first,last)，即区间的起点是位于查找范围之中的，而终点不是
val参数是要查找的元素的值
函数返回值是一个迭代器。如果找到，则该迭代器指向被找到的元素。如果找不到，则该迭代器指向查找区间终点。
*/
void vector_find_invoke()
{
	vector<int> v(5, 3);
	vector<int>::iterator p;
	p = find(v.begin(), v.end(), 3);
	if (p != v.end()) 
		cout << *p << endl;
	p = find(v.begin(), v.end(), 5);
	if (p == v.end()) 
		cout << "not found\n";
}
/*
sort()
简化形式：
void sort( first, last )
first 和 last 这两个参数都是容器的迭代器，它们给出了容器中的查找区间起点和终点
*/
void vector_sory_invoke()
{
	vector<string> v;
	v.push_back("food");
	v.push_back("candy");
	v.push_back("apple");
	sort(v.begin(), v.end());
	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
}
/*
merge()
简化形式：
merge(f1, e1, f2, e2, p) 
f1、e1、f2、e2、p都是迭代器
将有序序列v1中[f1, e1)和有序序列v2中[f2, e2)合并成有序序列，存入p的前面
*/
void vector_merge_invoke()
{
	int A[] = { 5, 10,15,20, 25 };
	int B[] = { 50,40,30,20,10 };
	vector<int> v(10);  // 定义一个长度为10的向量容器
	vector<int>::iterator it;
	sort(A, A + 5); sort(B, B + 5);
	merge(A, A + 5, B, B + 5, v.begin());
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
}
/*
其他算法示例：
replace( first, last, old, new ) // first, last为迭代器
作用：将 [ first,last ) 范围内的所有值为old的替换为new

reverse(start, end) // start, end为迭代器
作用：将序列中 [start, end) 范围反转排列顺序

count(start, end, searchValue) // start, end为迭代器
作用：统计[start, end) 范围内等于searchValue的元素个数

accumulate(first, last, init) // first, last为迭代器
作用：将[ first,last )范围内的所有值相加，再加上init后返回
*/

/*
序列型容器概览
关联容器概览
map容器
容器适配器概览

以上知识点位于文件".\\Knowledgefile\\container.pdf"
*/
void TemplateEntrance()
{
	//min_fun_invoke();
	//vector1_invoke();
	vector2_invoke();
}