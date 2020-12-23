#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>


#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>
using namespace std;

#define EPS 1e-10								//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// C++��׼�⡪���߳�֧�ֿ�
/*
**			(C++11 ��)<thread> 												std::thread �༰֧�ֺ���
**			(C++20 ��)<stop_token> 										std::jthread ��ֹͣ�Ǻ�
**			(C++11 ��)<mutex> 												����ԭ��
**			(C++14 ��)<shared_mutex> 									����Ļ���ԭ��
**			 (C++11 ��)<future>	 											�첽�����ԭ��
**			(C++11 ��)<condition_variable> 						 	�̵߳ȴ�����
**			 (C++20 ��)<semaphore> 										�ź���
**			 (C++20 ��)<latch>	 												��
**			 (C++20 ��)<barrier>	 											����
**
**
*/


// ����
/*
	������ɣ�
			1.����
			2.����
			3.���̿��ƿ�(PCB)

*/


// �߳�
/*
	�߳��ǽ����е�һ��ʵ�壬�Ǳ�ϵͳ��������͵��ȵĻ�����λ��
	Ҳ��˵���߳���CPU��ִ�е��ȵ���С��λ��
	Ҳ����˵�����̱������ܻ�ȡCPUʱ�䣬ֻ�������̲߳ſ��ԡ�

	�̡߳����̵ıȽ�
			�̲߳������ϵͳ�ĵ��ȣ�����CPU�ľ������õ������ʱ��Ƭ����ô������CPU�����С�
			�����̸����ȡ����ϵͳ�������Դ�����ڴ档


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
void set_fun_stdlib_thread_support_lib(void);
void start_stdlib_thread_support_lib(void);

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
void set_fun_stdlib_thread_support_lib(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_stdlib_thread_support_lib(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: stdlib_thread_support_lib**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  " << endl;
		cout << "1. test1��  " << endl;


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


		case 1:
			(*pfun[1])();


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}




static void test0(void) 
{

}


// test1�� <ctime>����C����ʱ�䡢���ڹ��ߡ�
static void test1(void) 
{}


// test2:
static void test2(void)
{
	using namespace chrono;

	//ѭ��1��
	auto start = system_clock::now();

	long int num = 10000000;
	for (int i = 0; i != num; i++)
	{
		int* b = new int[10]();
		delete[] b;
	}

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "����1������"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "��" << endl;


	//ѭ��2
	start = system_clock::now();

	int num2 = num >> 1;
	for (int i = 0; i != num2; i++) {
		int* b = new int[10]();
		delete[] b;
	}
	for (int i = num2; i != num; i++) {
		int* b = new int[10]();
		delete[] b;
	}

	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "����2������"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "��" << endl;

	//ѭ��3
	start = system_clock::now();

	//testfuc2(num);

	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "����3������"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "��" << endl;


}



static void test3(void)
{}



static void test4(void)
{}



static void test5(void)
{}