#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
using namespace std;

#define EPS 1e-10					 
#define PI 3.14159



// ֪ʶ��
/*
		����
				��һ������ı�����
				���ñ����ʼ�����������������ٳ�ʼ����
				���úͳ�ʼֵ�ǰ�(bind)��һ��ģ���������в�����������

		���ô���(passed by reference)
				ָ�������β����������͡� 
				��ʱ�β���ʵ�εı������βκ�ʵ�ε�ֵ����һ�𣬲����п����ķ�����
				���Ӧ��ֵ����(passed by value)�У�ʵ�ε�ֵ�������βΡ�
				�����β�����Ϊ��const����ʱ��ֻ�ܰ���ֵ����"hello",123������������������ֵ���Ͳ�����Ϊ��ʵ��



		
				
			 

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
void set_fun_dataType_reference(void);
void start_dataType_reference(void);


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
void set_fun_dataType_reference(void)
{
	pfun[0] = test0;
	pfun[1] = test1;

}


void start_dataType_reference(void)
{
	interfaceLevel = 3;

	while (3 == interfaceLevel)
	{
		printf("\n\n\n\n\n");
		printf("**************************MENU: dataType_functionPointer**********************\n");
		printf("Please choose a demon function to run:\n");
		printf("-2: Run all existed demon function.\n");
		printf("-1: Back to the previous interface.\n");
		printf("0: test0:  ");
		printf("1: test1: ");


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

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}

}







// test0:  
static void test0(void)
{
	int num1 = 99;
	int& num2 = num1;								// ����num2��num1��ֵ����һ��
	cout << "num2 == " << num2 << endl;

	num2 = 100;											// ʹ������num2���ı����num1��ֵ��
	cout << "num1 == " << num1 << endl;



}




// test1: 
static void test1(void)
{

}


