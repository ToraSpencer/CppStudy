#include <iostream>
#include <cmath>
#include <stdexcept>

#include <exception>
#include <string>
#include <vector>

#include <cstdio>

#include "example.h"


#define EPS 1e-6

using namespace std;



// std::exception::what()�������������쳣�����ַ���
/*. BC------------------------------------------------------------------------
������
		����һ��c����ַ�������char*�������Ƕ��쳣�Ľ��͡�

����ԭ�ͣ�
		virtual const char* what() const throw();  (C++11 ǰ)
		virtual const char* what() const noexcept; (C++11 ��)
*. EC------------------------------------------------------------------------
*/



// ��׼�쳣�ࣺstd:exception
/*
	������ͷ�ļ�<exception>
	���ࣺ std::exception
			�淶��̵������£������Զ�����쳣�඼Ӧ�ü̳���std::exception�࣬����дwhat()����

	�����ࣺ
			logic_error
					invalid_argument		�������Ϸ�
					domain_error
					length_error
					out_of_range			������Χ
					future_error(C++11)
					bad_optional_access(C++17)
			runtime_error
					range_error
					overflow_error
					underflow_error
					regex_error(C++11)
					system_error(C++11)
					ios_base::failure(C++11)
					filesystem::filesystem_error(C++17)
					nonexistent_local_time(C++20)
					ambiguous_local_time(C++20)
					tx_exception(TM TS)
					format_error(C++20)
			bad_typeid
			bad_cast
					bad_any_cast(C++17)
			bad_weak_ptr(C++11)
			bad_function_call(C++11)
			bad_alloc
					bad_array_new_length(C++11)
			bad_exception
			ios_base::failure(C++11 ǰ)
			bad_variant_access(C++17)

 
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
void set_fun_exception_std_exception(void);
void start_exception_std_exception(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);



/***************************************************************************
***************************************************************************/
// extern����
extern void traverse_pfun(void);



/***************************************************************************
***************************************************************************/
// �Զ������ʵ��



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_exception_std_exception(void)
{
	pfun[0] = test0;
}


void start_exception_std_exception(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: exception_std_exception**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "test0: �Ա�׼�쳣�Ĳ���" << endl;


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


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}
 



// test0: �Ա�׼�쳣�Ĳ���
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
    cout << "test0: �Ա�׼�쳣�Ĳ���" << endl;

	classFoo foo1;

	try
	{
		// ����һ�����쳣���յ���䣺
		classFoo foo2("xiaohong", -1);
	}
	catch(exception e)
	{
		cout << "ʹ��try-catch��䲶�����쳣���쳣�����ַ�����e.what() == " << e.what() << endl;
	}

 
	try
	{
		foo1.setAge(-12);
	}
	catch(exception e)
	{
		cout << "ʹ��try-catch��䲶�����쳣���쳣�����ַ�����e.what() == " << e.what() << endl;;
	}
	

 
}
