#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>



#include <cstdio>
#include <cassert>			//�ṩ�꺯��assert()


#include "example.h" 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// ֪ʶ��
/*
		1. ������Ϣ��
					����ԭ�͡���void assert( int expression );
					���á����򵥵�˵����������������ش�������ֹ����ִ��
					������̡����ȼ�����ʽ expression�������ֵΪ�٣���Ϊ0������ô������stderr��ӡһ��������Ϣ��Ȼ��ͨ������ abort ����ֹ�������С�

		2. assert�����������Զ��׼��Ĵ���ģ������Ǵ����쳣�ġ�
					������쳣�ǲ�һ���ģ������ǲ�Ӧ�ó��ֵģ��쳣�ǲ��ɱ���ġ�
					c�����쳣����ͨ�������ж����������������и��Ե��쳣������ơ�


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
void set_fun_UP_assert(void);
void start_UP_assert(void);





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

void set_fun_UP_assert(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_UP_assert(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: UP_ASSERT**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: ���ԵĻ���ʹ��" << endl;
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






// test0: ���ԵĻ���ʹ��
static void test0(void)
{

	cout << "\n\n\n\n" << endl;
	cout << "test0: ���ԵĻ���ʹ��" << endl;

	int flag;
	cout << "please input a integer" << endl;
	cin >> flag;
	
	assert(flag);
	cout << "flag >0" << endl;			// ��������ֵ����0�Ļ������򲻻����е��������֮ǰ�ͱ�abort�ˡ�

}






static void test1(void)
{
 

}


static void test2(void)
{
 

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



