#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>
#include <type_traits>



#include <cstdio>
#include <cassert>			//�ṩ�꺯��assert()


#include "example.h" 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// ֪ʶ��
/*
	��Ҫ���ͷ�ļ�
			<typeinfo>
			<type_traits>
			<cstddef>
			<limits>
			<typeindex>

	is_xxxϵ����ģ�壨C++11��
			�����ж����ݶ����Ƿ���xxx���͡�
			��is_pointer, is_null_pointer, is_const, is_signed.... 
			������<type_traits>
			��װ��һ��static��bool��Ա����value����is_xxx<type>::value��ֵ���ж�type�����Ƿ���xxx����

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
void set_fun_stdlib_type_support_lib(void);
void start_stdlib_type_support_lib(void);





static void test0(void);
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

void set_fun_stdlib_type_support_lib(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_stdlib_type_support_lib(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: TYPE_SUPPORT_LIB**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: " << endl;
		cout << "1. test1:  " << endl;


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






// test0: is_xxxϵ����ģ���ж����͡�����
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0:  is_xxxϵ����ģ���ж����͡�����" << endl;

	std::cout << std::is_pointer<int>::value << endl;
	std::cout << std::is_pointer<int *>::value << endl;
	std::cout << std::is_pointer<int &>::value << endl;
	std::cout << std::is_pointer<int **>::value << endl;
	std::cout << std::is_pointer<int[10]>::value << endl;
	std::cout << std::is_pointer<std::nullptr_t>::value << endl;



}





// test1: typeid()����
static void test1(void)
{
	cout << "test1: typeid()���� :" << endl << endl;

	// typeid()����type_info���������name()�������������������� 
	
	cout << "typeid(5).name() = ��" << typeid(5).name() << endl;
	cout << "typeid(3.12).name() = " << typeid(3.12).name() << endl;
	cout << "typeid('c').name() = " << typeid('a').name() << endl;
	cout << "typeid(\"helloWorld\").name() = " << typeid("helloWorld").name() << "	//�ַ����ı������ַ����顣" << endl;

	int i = 1;
	int* p_i = &i;
	cout << "int i = 1; int* p_i = &i; typeid(p_i).name() = " << typeid(p_i).name() << endl;

	int a[] = { 1,2,3 };
	cout << "int a[] = {1,2,3}; typeid(a).name() = " << typeid(a).name() << endl;

	int b[2][3] = { {1,2,3},{4,5,6} };
	cout << "int b[2][3] = {{1,2,3},{4,5,6}}; typeid(b).name() = " << typeid(b).name() << endl;

	class testClass {};
	testClass t;
	cout << "class testClass{}; testClass t; typeid(t).name() = " << typeid(t).name() << endl;

	cout << endl;

 

}



// test2: isxxx()ϵ�к���
static void test2(void)
{
	int* pi = NULL;
	typedef double* dptr;

	// �������еĲ��������͡����Ǳ�����
	// Բ�����в����б�ֻ��Ϊ�գ����ڷ���value;

	auto value1 = is_null_pointer<dptr>();
	cout << value1 << endl;

	cout << is_null_pointer<int*>::value << endl;


	cout << "finished " << endl;

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



