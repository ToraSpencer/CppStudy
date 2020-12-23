#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
using namespace std;

#define EPS 1e-10					 
#define PI 3.14159



// ֪ʶ��
/*
			����ָ��������﷨���������ͺ���������ʽ���ƣ�ֻ�Ǻ����������*pf

			����ĳ����foo()��������foo��&foo��ʾ��ָ�롣

			�ص�����
					���һ�����������ᱻ��ʽ��ֱ�ӵ��ã����ǽ��亯��ָ�봫��һ��caller��������caller�������ã���������ͱ���Ϊ�ص�������

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
void set_fun_dataType_function_pointer(void);
void start_dataType_function_pointer(void);

static void foo(void);
static void goo(void);
static int add_intNum(int x, int y);

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
void set_fun_dataType_function_pointer(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
}


void start_dataType_function_pointer(void)
{
	interfaceLevel = 3;

	while (3 == interfaceLevel)
	{
		printf("\n\n\n\n\n");
		printf("**************************MENU: dataType_functionPointer**********************\n");
		printf("Please choose a demon function to run:\n");
		printf("-2: Run all existed demon function.\n");
		printf("-1: Back to the previous interface.\n");
		printf("0: test0: ����ָ��Ļ���ʹ��\n");
		printf("1: test1: ����ָ�����顢��������ָ��\n");
		printf("2: test2: �ص�����\n");

		inputTag = scanf("%d", &inputNum);


		if (inputTag != 1)
		{
			printf("Invalid input. Please input again:\n");
			setbuf(stdin, NULL);
			continue;
		}


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

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}

}


namespace MY_CALCULATOR
{
	typedef float(*unaryOP)(const float& num);			// �лص�����ʱʹ��typedef������غ���ָ�����ͣ��������Խ�caller�����Ĳ����б�д�ĸ���ࡣ
	typedef float(*binaryOP)(const float& num1, const float& num2);

	float add(const float& num1, const float& num2)
	{
		return num1 + num2;
	}

	float minus(const float& num1, const float& num2)
	{
		return num1 - num2;
	}

	float sqrt(const float& num)
	{
		return std::sqrt(num);
	}


	// ����1��������һԪ���㣺
	float calculate(unaryOP pfunc, const float& num)
	{
		float number = num;
		return (*pfunc)(number);
	}


	// ����2�������ж�Ԫ����
	float calculate(binaryOP pfunc, const float& num1, const float& num2)
	{
		float number1 = num1;
		float number2 = num2;
		return (*pfunc)(number1, number2);
	}

}






static void foo(void)
{
	printf("\tthis is a string printed by the void function foo.\n");

}




static void goo(void)
{
	printf("\tthis is a string printed by the void function goo.\n");


}



static int add_intNum(int x, int y)
{
	return (x + y);

}




// test0: ����ָ��Ļ���ʹ��
static void test0(void)
{
	// 1. ����ָ����������������ͺ���������ʽ���ƣ�ֻ�Ǻ����������*pf
	void(*pfv)(void) = NULL;
	int(*pfi)(int x, int y) = NULL;
	int temp = 0;

	cout << "\n\n\n\n" << endl;
	cout << "test0: ����ָ��Ļ���ʹ��" << endl;


	// 2.  
	pfv = foo;
	pfi = add_intNum;


	// 3. 
	cout << "\tnow test the void function:" << endl;
	(*pfv)();
	cout << endl;

	cout << "\tnow test the int function:" << endl;
	temp = (*pfi)(3, 4);
	cout << "\t(*pfi)(3,4) == " << temp << endl;
	cout << endl;

}




// test1: ����ָ�����顢��������ָ�롣
static void test1(void)
{
	// 1. ��������ָ������
	void(*pfv[10])(void) = { NULL };

	// 2. ����ָ��
	void(**ppfv)(void) = NULL;

	printf("\n\n\n\n");
	printf("\ttest1: ����ָ�����顢��������ָ��\n");


	// 3. 
	ppfv = &pfv[0];
	*ppfv = foo;
	ppfv++;
	*ppfv = goo;


	// 4.  
	ppfv = &pfv[0];
	(**ppfv)();
	ppfv++;
	(**ppfv)();
}


// test2: �ص�����
static void test2(void) 
{
	printf("\n\n\n\n");
	printf("test2: �ص�����");


	cout << MY_CALCULATOR::calculate((MY_CALCULATOR::add), 1.0f, 2.0f) << endl;
	cout << MY_CALCULATOR::calculate((MY_CALCULATOR::add), 3.0f, 1.0f) << endl;
	cout << MY_CALCULATOR::calculate((MY_CALCULATOR::sqrt), 3.0f) << endl;



}

