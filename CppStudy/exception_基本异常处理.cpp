#include <iostream>
#include <cmath>
#include <stdexcept>

#include <cstdio>

#define EPS 1e-6

using namespace std;


/*
**	�﷨�����쳣���׳�������
**		@ �쳣���׳�throw����������ת��ʱ�����쳣ʱ��Ӧ������һ����Ӧ���쳣����ʹ��throw�׳�
**		@ �쳣�Ĵ���
**				# ͨ��try catch����������쳣��
**				#
**				# try(�쳣)
**
**
**
*/



/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���

//		�Զ�����쳣�࣬���ձ�׼�쳣����ʵ�֡�
class myException
{
public:
	myException();

};






/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;


/***************************************************************************
***************************************************************************/
// ��������
void set_fun_exception_basic(void);
void start_exception_basic(void);

// �Զ��帡���������������쳣����
double Divide(float a, float b);		// �쳣����������ֻ���׳�int���͵��쳣							
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
void set_fun_exception_basic(void)
{
	pfun[0] = test0;
}


void start_exception_basic(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: exception_basic**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "test0: �����쳣����" << endl;


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


//	Divide���������Զ��帡���������������쳣����
/*. BC------------------------------------------------------------------------
 
*. EC------------------------------------------------------------------------
*/
double Divide(float a, float b)  
{
	float temp = double(a/b);

	if ((b <= EPS) && (b >= -EPS))				// ����ĸΪ0���׳��쳣
	{
		throw 0;								// �׳�int���͵��쳣
	}

	return temp;
}




// test0: �򵥵��쳣���Ƶ�չʾ��
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
    cout << "test0: �����쳣����" << endl;
 
}
