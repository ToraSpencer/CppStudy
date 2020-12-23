#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>
 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// C++������������֪ʶ


 

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
void set_fun_function_basic(void);
void start_function_basic(void);

static unsigned long factorial(unsigned int);
static void to_binary(unsigned long);

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
void set_fun_function_basic(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_function_basic(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: function_basic**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: �򵥵ĵݹ���� " << endl;
 


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



// factorial������������׳�num!
/*. BC------------------------------------------------------------------------
**	factorial������������׳�num!
**
**	������
**			β�ݹ�ʵ�֡�
**
**	����ԭ�ͣ�
**			static unsigned long factorial(	unsigned int num				��Ҫ����׳˵�������
**															)
**			����ֵ�� unsigned long														�׳˼�����
**
*. EC------------------------------------------------------------------------
*/
static unsigned long factorial(unsigned int num)
{
	//		�ݹ���ƣ�factorial(n) == n*factorial(n-1)
	//		�ݹ���ֹ������factorial(1) == 1;	factorial(0) == 1;

	unsigned long result;

	if ((1 == num) || (0 == num))
	{
		result = 1;
	}
	else
	{
		//		 β�ݹ飺
		//				�ݹ���򵥵����Ρ�
		//				���Ժ����׵ظ�д��ѭ������ʽ��
		result = num * factorial(num - 1);
	}

	return result;

}



// to_binary���������������ʮ����������ת��Ϊ����������ӡ����
/*. BC------------------------------------------------------------------------
**	to_binary���������������ʮ����������ת��Ϊ����������ӡ����
**
**	������
**
**	����ԭ�ͣ�
**			static void to_binary(	unsigned long num							��ת��Ϊ��������ʾ��ʮ����������
**											)
**
*. EC------------------------------------------------------------------------
*/
static void to_binary(unsigned long num)
{
	//		�ݹ���ƣ� to_binary(num) �� to_binary(num/2)
	//		�ݹ���ֹ������ num == 0; num == 1;
	int remind;

	remind = num % 2;
	if (num >= 2)
	{
		to_binary(num / 2);
	}

	putchar(remind ? '1' : '0');

}


// test0: �򵥵ĵݹ���ã�
static void test0(void)
{
	unsigned long num = 1;
	int inputValid = 0;
	unsigned long result = 0;

	printf("test0: �򵥵ĵݹ���ã�\n");
	printf("\ttest0.0��β�ݹ�ʵ�ֵĽ׳˼��㣺\n");
	printf("\t\tplease input a non-negative integer:\n");

	while ((0 == inputValid) && (num >= 0))				// �Ϸ�����ļ���
	{
		setbuf(stdin, NULL);
		inputValid = scanf("%d", &num);

		if ((1 == inputValid) && (num >= 0))
		{
			break;
		}
		else
		{
			setbuf(stdin, NULL);
			printf("\t\tinvalid input. Please input again.\n");
		}
	}

	result = factorial(num);
	printf("\t\tthe factorial of %d is: factorial(%d) == %d;\n", num, num, result);


	printf("\ttest0.1���ݹ�ʵ�ֵ�ʮ���Ƶ�������ת����\n");
	printf("\t\tplease input a non-negative integer:\n");
	setbuf(stdin, NULL);
	inputValid = 0;
	while ((0 == inputValid) && (num >= 0))
	{
		setbuf(stdin, NULL);
		inputValid = scanf("%d", &num);

		if ((1 == inputValid) && (num >= 0))
		{
			break;
		}
		else
		{
			setbuf(stdin, NULL);
			printf("\t\tinvalid input. Please input again.\n");
		}
	}

	printf("\t\tthe binary form of %d is :\n", num);
	printf("\t\t");
	to_binary(num);
	setbuf(stdin, NULL);


}

// test1�� 
static void test1(void) {}


static void test2(void)
{}


static void test3(void)
{}



static void test4(void)
{}



static void test5(void)
{}