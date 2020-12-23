#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>
#include <initializer_list>



#include <cstdio>
#include <cstdarg>			// �ṩ��һЩ֧�ֿɱ���������ĺ�


#include "example.h" 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// ֪ʶ��
/*
		1. ʵ�ֺ���������Ŀ�ɱ�ķ�����
					 C�����п���ʹ��<stdarg.h>���ṩ�Ŀɱ�����б�va_list;
					 C++11�п���ʹ��initialize_list;
					 C++��ʹ�ñ��ģ�塪����function_����ģ�壬OOP_��ģ������ģ�顣

		2. C�����еĿɱ�����б�
					��������printArgs(��������test0;
					


*/









/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���




/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_function_vararg(void);
void start_function_vararg(void);




#ifdef __cplusplus
extern "C"{
#endif
static void printArgs(int num, ...);
static void test0(void);

#ifdef __cplusplus
}
#endif


static void foo(const initializer_list<int>& ilist);


static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);



/***************************************************************************
***************************************************************************/
// extern����
void traverse_pfun(void);


/***************************************************************************
***************************************************************************/
// �Զ������ʵ��


/***************************************************************************
***************************************************************************/
// ��������

void set_fun_function_vararg(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_function_vararg(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL_set**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: C������ʹ��va_listʵ�ֲ����ɱ�ĺ�����" << endl;
		cout << "1. test1: ʹ�ó�ʼ���б�initializer_listʵ�ֿɱ��������(C++11)" << endl;
		cout << "2. test2: �����ñ��ģ��ʵ�ֵĿɱ�κ���ģ��(C++11)" << endl;


		inputTag = scanf("%d", &inputNum);


		// ������ֵ�����������������롣
		if (inputTag != 1)
		{
			printf("Invalid input. Please input again:\n");
			setbuf(stdin, NULL);
			continue;
		}

		// ��������������ֵ����Ӧ��
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




// �������Ϊinitializer_list�ĺ���
static void foo(const initializer_list<int>& ilist)
{
	for (int num : ilist)
	{
		cout << num << endl;
	}
}



#ifdef __cplusplus
extern "C"{
#endif
// �ɱ����������ѭ����ӡ���д���Ĳ�����
static void printArgs(int num, ...)
{
	int i, presentArg = 0;

	// 1. ����va_list�������汣���к꺯��va_start �� va_copy �� va_arg��va_end�������Ϣ
	va_list args;	

	// 2. ���ú꺯��va_start()����ʹ�ñ�printfArgs�������Է��ʿɱ������
	va_start(args, num);								



	// 3. ѭ����ӡ���������
	for(i = 0; i<num; i++)
	{

		// 3.1 ���ú꺯��va_arg()��ȡ�������
		// 		va_arg()���������ڲ�ָ�뵱ǰָ��Ĳ�����Ȼ��ָ�������ƶ�sizeof(int)�ľ��룬ָ����һ��������
		presentArg = va_arg(args, int);

		
		printf("��ǰ�����Ĳ�����presentArg == %d\n" , presentArg);
	}


	// 4. ���ú꺯��va_end()����������־��
	va_end(args);										

}


// test0: C������ʹ��va_listʵ�ֲ����ɱ�ĺ�����
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test0: C������ʹ��va_listʵ�ֲ����ɱ�ĺ�����" << endl;

	
	printArgs(6, 1,2,3,4,5,6);		//������ע�⺯���������Ѿ��޶��˴���Ŀɱ������Ӧ����int���͡�
	
}

#ifdef __cplusplus
}
#endif



// ���ģ��ʵ�ֵ�����������������������ֵ��
namespace VA_TEMPLATE_FUNC1 
{
	template <typename T1, typename T2>
	double maxInTowNums(const T1& num1, const T2& num2)			// �����ĺ���ģ��
	{
		if (num1 >= num2) 
		{
			double temp = num1;
			return temp;
		}
		else 
		{
			double temp = num2;
			return temp;
		}
	}


	template <typename T>
	double Max(const T& num)		// �ݹ���ֹ
	{
		double temp = num;
		return temp;
	}


	template <typename T1, typename... Types>
	double Max(const T1& num, const Types&... args) // �ݹ����
	{
		return maxInTowNums(num, Max(args...));		// ע��������������ͬ�ĵط�ʹ����...����typename���棬���ͺ��棬��������
													// �ֱ��ʾģ����ڶ�����ͣ��β��б���ڶ�����͵Ķ���βΣ��������д��ڶ������������
	}


}



// ���ģ��ʵ�ִ�ӡ�����������print����
namespace VA_TEMPLATE_FUNC2 
{

	void print()			// �ݹ���ֹ
	{						//		�ݹ���ֹ��Ϊ�޲λ���һ�����������ζ����ԡ�
		cout << endl;
		return;
	}

	template <typename T, typename... Types>
	void print(const T& firstArg, const Types&... args) 
	{
		cout << firstArg << ",  ";
		print(args...);
	}
}




// test1: ʹ�ó�ʼ���б�initializer_listʵ�ֿɱ��������(C++11)
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "'test1: ʹ�ó�ʼ���б�initializer_listʵ�ֿɱ��������(C++11)" << endl;
	
	foo({1,2,3,4,5});
 

}




// test2: �����ñ��ģ��ʵ�ֵĿɱ�κ���ģ��(C++11)
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test2: �����ñ��ģ��ʵ�ֵĿɱ�κ���ģ��(C++11)" << endl;

	cout << VA_TEMPLATE_FUNC1::Max(2,5.11,3.44, 100.9, 999, 12,-1) << endl;

	VA_TEMPLATE_FUNC2::print(23, 99.2, "i was printed by a varadic template function");


}

static void test3(void)
{
 

}

static void test4(void)
{
 

}

static void test5(void)
{
 

}



