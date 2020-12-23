#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>



#include <cstdio>



#include "example.h" 
using namespace std;

#define EPS 1e-10					// ����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// ֪ʶ��
/*
	��̬��
		��Ӧ���У�һЩ����������Ҫ����ʹ�ã��Ͱ���Щ�������Ϊ��̬���ļ���
		�����Ӳ����У����������Ӿ�̬���ļ�ȡ������Ĵ��룬���Ƶ����ɵĿ�ִ���ļ��С�
		linuxϵͳ�о�̬���ļ���׺Ϊ.a
		windowsϵͳ�о�̬���ļ���׺Ϊ.lib
		�е�.lib�ļ�Ϊwindows�ж�̬��ĵ�����ļ���
				������Ϊ������ļ���.lib�ļ����ԣ���ʵ�ʵ�ִ�д���λ�ڶ�̬���С�
				�����ֻ�����˵�ַ���ű�ȣ�ȷ�������ҵ���Ӧ������һЩ������ַ��Ϣ��
				��������Ϊ��̬���.lib��˵���䱾��Ͱ�����ʵ��ִ�д��롢���ű�ȵ�

		
	WINDOWS�еĶ�̬��
		windowsϵͳ�ж�̬���ļ���׺Ϊ.dll
		��ʽ����
				�������������ͨ������LoadLibrary(), FreeLibrary()ָ��DLL�ļ��غ�ж�� 
				�������������������������LoadLibrary()����ʱ�Ž�DLL���ص����̵��ڴ�ռ䡣	
				��ʽ����ʱ��ֻ����Ҫʹ��dll�ļ�������ҪLIB�ļ���
		��ʽ����
				��ʽ����ʱû����ʽ�ص���LoadLibrary()��FreeLibrary()����˳�Ϊ��ʽ���ء�
				��������������ʱ������dll�ļ��󣬽���̬���ӿ���ص�����������̵��ڴ�ռ䡣 
				��ʽ���ر�����Ҳ��ͨ��LoadLibrary()����ʵ�ּ��ع�����
				��Ҫʹ��lib�ļ���dll�ļ���

	LINUX�еĶ�̬��
		linuxϵͳ�ж�̬���ļ���׺Ϊ.so



	DLL�ļ�
		DLL��EXE�ļ�һ�������а�����Ҳ�ǳ���Ķ�����ִ�д���ͳ����������Դ
		DLL�еĴ�������API������ʽ���ֵ�
		ͨ�׵�˵��DLL�а����ĳ�����붼��������һ����Сģ�飬Ӧ�ó���ͨ����������DLL���ض��İ�ť��������DLL�������ť������Ĺ���

		
		


	��̬��Ͷ�̬�������
		��̬���ڳ�������ӽ׶α����Ƶ��˳����У��ͳ������е�ʱ��û�й�ϵ��
		��̬���ǳ���������ʱ��ϵͳ��̬���ص��ڴ��й�������á�
		ʹ�ö�̬����ŵ���ϵͳֻ������һ�Σ���ͬ�ĳ�����Եõ��ڴ�����ͬ�Ķ�̬��ĸ�������˽�ʡ�˺ܶ��ڴ档


	���þ�̬��ķ�ʽ��
			������̬���ͷ�ļ�����#include "lib1/lib1.h"
			����Ԥ����ָ��뾲̬�⡪����#pragma comment(lib,"lib1.lib")
			���ʹ����VS������һ�����Ը�Ϊ����Ŀ����->������->����������֮�м���.lib�ļ���





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
void set_fun_dynamic_static_library(void);
void start_dynamic_static_library(void);





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

void set_fun_dynamic_static_library(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_UP_dynamic_static_library(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: UP_DYNAMIC_STATIC_LIBRARY**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  " << endl;
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






// test0: 
static void test0(void)
{

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



