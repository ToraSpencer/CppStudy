#include <cstdlib>
#include <cstdio>


#include <string>
#include<iostream>

#include <memory>					// 使用memset()函数需要#include <memory.h>或<string.h>

#include "example.h"
using namespace std;





// 知识点
/*
	内存区域分类：
				栈区——编译器自动分配释放。
				堆区——程序员分配、释放
							  堆区的内存是所有程序共享的。
				全局区（静态区）——存放全局变量和static变量，程序整个运行期间都存在。
				常量区———存放const常量、字面量等；
									 程序结束后由系统释放。
				程序代码区———存放CPU执行的机器指令。


	内存分配的方式：
				1. 静态区分配——如全局变量
				2. 栈上分配
				3. 堆上分配———使用malloc, new，allocator<T>对象





	常见内存管理错误
				野指针错误
						使用了野指针，访问了不该访问的内存。
						解决方法——指针所指的内存被释放后，要将指针悬空

				过度释放
						对一块内存释放多次

				内存泄露
						由于疏忽或错误造成程序未能释放已经不再使用的内存的情况。
						solution——内存使用完立刻释放

	malloc和new，以及free和delete的区别。
				new，delete可以执行构造、析构函数，malloc, free不可以


	内存对齐的概念
				处理器存取内存的时候有内存存取粒度这样一个概念，即大部分处理器会以4byte, 8byte等单位来存取内存。
				假设内存存取粒度是4byte，则取32位的int变量的时候，处理器只能从地址为4的倍数的内存读取数据。
				可以使用预编译指令#pragma pack(n)来指定对齐系数n，即表示内存存取粒度为nbyte
				结构体中的内存对齐
					基于以上原则，一个结构体实例所占的存储空间不是所有成员的大小加和，其中可能存在一些空洞。
					这些空洞使用指针查看貌似是随机值？日后可以多做了解。


	注意动态数组——堆上创建的数组和普通数组的区别
				动态数组不能使用begin(),end()


	allocator<T>类模板
				定义在<memory>头文件中。
				作用类似于C语言中的malloc，可以开辟一片未构造数据对象的内存空间。
				

*/



//	malloc————动态内存分配
/*. BC------------------------------------------------------------------------
		malloc————动态内存分配
		函数原型：
				void*  malloc(std::size_t size);				// <cstdlib>
*. EC------------------------------------------------------------------------
*/






/***************************************************************************
***************************************************************************/
// 全局变量、类型定义
typedef struct 
{
	char a;
	short b;
	int c;
	long d;							// 32位系统中long的大小是4字节，64位系统中是8字节。
	char e;
	long long f;				// long long的大小是8字节。
}stru;



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;


/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_UP_memory_management(void);
void start_UP_memory_management(void);


static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);



/***************************************************************************
***************************************************************************/
// extern函数
extern void traverse_pfun(void);




/***************************************************************************
***************************************************************************/
// 自定义类的实现



/***************************************************************************
***************************************************************************/
// 函数定义
void set_fun_UP_memory_management(void) 
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_UP_memory_management(void) 
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: UP_memory_management**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0: test0: C/C++中的内存分区" << endl;
		cout << "1:  test1: C中的动态内存的基本使用" << endl;
		cout << "2:  test2: C++中的动态内存的基本使用" << endl;
		cout << "3:  test3: 结构体中的内存对齐" << endl;
 

		inputTag = scanf("%d", &inputNum);

		// 若输入值不是整数，重新输入。
		if (inputTag != 1)
		{
			printf("Invalid input. Please input again:\n");
			setbuf(stdin, NULL);
			continue;
		}

		// 对三级界面输入值的响应。
		switch (inputNum)
		{
		case -2:
			traverse_pfun();
			break;

		case -1:
			interfaceLevel = 2;
			break;

		case 0:
			(*pfun[0])();
			break;

		case 1:
			(*pfun[1])();
			break;

		case 2:
			(*pfun[2])();
			break;

		case 3:
			(*pfun[3])();
			break;

		case 4:
			(*pfun[4])();
			break;

		case 5:
			(*pfun[5])();
			break;


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// test0: C++中的内存分区
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0：C++中的内存分区" << endl;

	int i1;											// 栈区
	char str1[] = "abc";				// 栈区
	char* pc;										// 栈区
	char str2[] = "123";				// "123"是字符串字面量，在文字常量区；str2在栈区
	const char* str3 = "123";				// str3是指向字符串字面量"123"的指针。
	static int i2 = 2;							// 全局区（静态区）
	auto p1 = (char*)malloc(10);		// 分配出来的空间在堆区。
	auto p2 = (char*)malloc(20);		// 分配出来的空间在堆区。
	free(p1);
	free(p2);

}



// test1: C中的动态内存的基本使用
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test1: C中的动态内存的基本使用" << endl;


	// C语言中的动态内存相关的基本函数，以下函数都在stdlib.h中
	/*
		1. malloc（）、calloc（）————堆上分配新的内存区域。
					malloc()开辟的内存未初始化，需要用memset()初始化
					calloc()开辟的内存是初始化了的。
		2. realloc（）————调整已分配的内存区域。
		3. free（）————释放已分配的内存区域。
	*/

	//			使用malloc开辟未初始化的堆内存，初始化之前不可以使用。
	int* pi1 = (int*)malloc(100);							// 分配100个字节的堆内存，返回其首地址int*类型的指针。
																						// malloc()直接返回的是void类型的指针。
	int* pi2 = (int*)malloc(25 * sizeof(int));			// 同上


	//			检测内存是否分配成功
	if (pi1)					
	{
		cout << "malloc()分配堆内存成功" << endl;	 
	}
	else
	{
		cout << "malloc分配堆内存失败" << endl;
		return;
	}

	//			使用memset将一块内存中的内容全部设定为指定的值
	/*
		void *memset(	void *buffer,					内存对应的指针或数组
									int c,								复给内存的值
									int count							内存的长度
								)
	*/
	memset(pi1, 'a', 100);					// 用字S符'a'填充pi1所指的堆内存。
	char* pc1 = (char*)pi1;
	*(pc1 + 5) = '\0';							
	printf("%s", pc1);
 
	
	//			使用free()释放堆内存。
	free(pi1);
	free(pi2);

}



// test2: C++中的动态内存的基本使用
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test2: C++中的动态内存的基本使用" << endl;

	// 使用new分配动态内存给堆对象。
	int* pi1 = new int;											// 若开辟内存失败则抛出std::bad_alloc类型的异常。
	int* pi2 = new (nothrow) int; 					// 若开辟内存失败则返回一个空指针，不抛出异常。
	float* pf1 = new float(3.14159);				// 分配动态内存，并进行初始化。
	int* parri1 = new int[5];							// 分配动态数组对象，要指明元素个数
																			// 动态数组并不是一个真正的数组对象，不能使用begin(), end(), 范围for循环
	classFoo* pclass1 = new classFoo();		// 分配类对象，要调用构造函数。


	// 使用delete来释放动态内存；
	delete pi1;
	delete pi2;
	delete[] parri1;									// 释放动态数组，delete之后要加[]
	delete pclass1;										// delete类对象，本质是执行其析构函数。 


	// 释放内存之后指针要置空。
	pi1 = NULL;
	parri1 = NULL;
	pclass1 = NULL;




}




// test3: 结构体中的内存对齐
static void test3(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test3: 结构体中的内存对齐" << endl;

	stru s1 = {1,2,3,4,5,6};
	unsigned char* pc= NULL;
	pc = reinterpret_cast<unsigned char*>(&s1);

	// s1的内存应该是这样的：
	/*
		char a; short b; int c; long d; char e; long long f;

		axbbcccc
		dddddddd
		exxxxxxx
		ffffffff
		所以一共占32字节，结构体实例内部的数据分布可以使用一个unsigned char*指针来查看验证。
	*/

	
	cout << "sizeof(s1) == " << sizeof(s1) << endl;
	cout << "结构体实例s1内部数据分布：" << endl;
	for(int i = 1; i<=32; i++)
	{
		printf("%d. 0x%x\n" , i, *pc);
		pc++;
		if(i>=32)
		{
			break;
		}
			
	}


	

}



static void test4(void)
{}



static void test5(void)
{}