#include <iostream>
#include <string>
#include <typeinfo>

#include <memory>
#include <vector>
#include <cstddef>
#include <cstdio>
#include <new>



using namespace std;

#define EPS 1e-10					//定义非常小的一个量EPSilon，当浮点数不大于这个值时，视为0
#define PI 3.14159



// 知识点
/*
			1. union共用体——共用体的所有成员占用同一段内存，修改一个成员会影响其余所有成员。
			
			2. 枚举特点：
							元素值必须是整型值。
							
			3. 结构体中的内存对齐问题，详见UP_内存管理章节。




*/








/***************************************************************************
***************************************************************************/
// 全局变量、类型定义
typedef struct person
{
	string name;
	bool sex;
	int age;
	string job;
} person;


struct controlWord				// 使用了位字段的结构体，其中每个成员都是一个字段。
{
	unsigned int word1 : 4;   	// 4bit为word1的值
	unsigned int : 4;        		// 4bit为空白的占位
	bool word2 : 1;
	bool word3 : 1;
};


typedef union data
{
	int numi;
	float numf;
	char ch;
} unionData;

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
inline void dispPerson(person&); 

void set_fun_dataType_EUS(void);
void start_dataType_EUS(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);


/***************************************************************************
***************************************************************************/
// extern函数
void traverse_pfun(void);


/***************************************************************************
***************************************************************************/
// 自定义类的实现


/***************************************************************************
***************************************************************************/
// 函数定义
void set_fun_dataType_EUS(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_dataType_EUS(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: dataType_EUS**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: 结构体的基本使用方法" << endl;
		cout << "1. test1：枚举类型的基本使用" << endl;
		cout << "2. test2：共用体的基本使用" << endl;
		cout << "3. test3: 结构体中的内存对齐" << endl;


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



// test0: 结构体的基本使用方法
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: 结构体的基本使用方法" << endl;

	// 结构体实例初始化：
	//		注：C中声明结构体实例时前面要加struct
	//				一般C中使用typedef   person{.....}person; 这样的格式声明结构体，然后声明实例的时候就不用写struct了
	person p1 = {"xiaoming", true, 18, "doctor"};
	person p2 = {};						// 此时所有成员值为0


	dispPerson(p1);
	cout << endl;
	dispPerson(p2);
	cout << endl;


}



// test1：枚举类型的基本使用
static void test1(void)
{
	// 定义枚举类型的主要目的是：增加程序的可读性。
	// 枚举类型最常见也最有意义的用处之一就是用来描述状态量
	cout << "\n\n\n\n" << endl;
	cout << "test0: 结构体的基本使用方法" << endl;



	// 定义枚举类型
	enum weekDay{SUN, MON, TUE, WED, THU, FRI, SAT};		// 默认情形下，枚举常量取值为0, 1, 2,...	
	enum color{RED, BLUE, GREEN = 1, YELLOW};						// 取值可重复，此时取值分别为0,1,1,2		



	// 枚举类型的信息
	cout << "typeid(SUN).name() " << typeid(SUN).name() << endl;	// 枚举常量SUN的类型是weekDay，weekDay即是类型名。
	cout << "sizeof(weekDay) == " << sizeof(weekDay) << endl;		// 这样返回值是weekDay类型的大小
	cout << "sizeof(SUN)" << sizeof(SUN) << endl;								// 枚举类型的大小不确定，编译器会根据其值大小来分配，可能是1,2,4字节，一定是整型。
	

	// 简单的应用举例：
	int num;
	int inputValid = 0;
	string str;
	enum person{alice = 1, bob, cindy, david, eric, frank, grey};
	cout << "请输入要查看的选手编号" << endl;
	while(0 == inputValid)
	{
		setbuf(stdin, NULL);
		inputValid = scanf("%d", &num);

		if(0 == inputValid || num < 1 || num > 6)
		{
			cout << "输入不合法，请重新输入。" << endl;
			setbuf(stdin, NULL);
		}
	}
	switch(num)
	{
		case 1:
			str = "alice";
			break;

		case 2:
			str = "bob";
			break;

		case 3:
			str = "cindy";
			break;

		case 4:
			str = "eric";
			break;

		case 5:
			str = "frank";
			break;

		case 6:
			str = "grey";
			break;

		default:
			break;
	}
	cout << num << "号选手是" << str << endl;
}



// test2: 共用体的基本使用
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test2:  共用体的基本使用" << endl;

	unionData a;
	a.numi = 99;
	printf("sizeof(unionData) == %u\n", sizeof(unionData));
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	// union中一个成员的更改，会影响到其他成员
	a.numi = 1;
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	a.numf = 3.14;
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	a.ch = 'a';
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);
	
 
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