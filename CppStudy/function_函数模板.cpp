#include <string>
#include<iostream>

#include <cstdio>





using namespace std;
 


/*
	����ģ��


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
template <typename T, size_t N>
void foo(T (&arr)[N]);					// ����ģ��ʾ�����������Ͳ���T���ͷ����Ͳ���N

void set_fun_function_function_template(void);
void start_function_function_template(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);



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

// foo��������ģ��ʾ�����������Ͳ���T���ͷ����Ͳ���N
/*
	ʹ�÷�Χforѭ����������ӡ�����������е�����Ԫ�ء�

*/
template <typename T, size_t N>
void foo(T (&arr)[N])
{
	for(T elem:arr)
	{
		cout << "\t" << elem;  
	}
	cout << endl;
}
 


void set_fun_function_function_template(void) 
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_function_function_template(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: function_function_template**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: ����ģ��Ļ���ʹ��" << endl;


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


// test0:
static void test0(void)
{
	int arri[10] = {0,1,2,3,4,5,6,7,8,9};
	float arrf[5] = {1.11, 2.22, 3.33, 4.44, 5.55};

	cout << "\n\n\n\n" << endl;
	cout << "test0: ����ģ��Ļ���ʹ��" << endl;

	cout << "\tʵ��������ģ��foo<T, N>Ȼ����ã�" << endl;
	foo<int, 10>(arri);
	foo<float, 5>(arrf);

}


static void test1(void)
{}



static void test2(void)
{}



static void test3(void)
{}



static void test4(void)
{}



static void test5(void)
{}