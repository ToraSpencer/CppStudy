#include <cstdio>
#include <cstring>


#include <string>
#include <iostream>
#include <vector>						//vector��ģ����ͷ�ļ�<vector>��
#include <algorithm>
#include <iterator>
#include <regex>

#include <cstdio>
#include "example.h"
using namespace std;




/*
**	 
**
**
**
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
void set_fun_stdlib_regex(void);
void start_stdlib_regex(void);


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
void set_fun_stdlib_regex(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_stdlib_regex(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: stdlib_������ʽ**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  " << endl;
		cout << "1. test1: " << endl;
		cout << "2: test2:  " << endl;
		cout << "3: test3:  " << endl;
		cout << "4: test4:  " << endl;
		cout << "5: test5:  " << endl;


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



//	test0:  Ӧ��ʵ������ƥ�������ʽ
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test " << endl;

	// ������ʽ��ƥ�����
	/*
		��1�飨���û�������
			ƥ�����0��9��A��Z��a��z���»��ߡ��㡢���ַ�֮�е������ַ����ظ�һ�������
			�м䣬һ����@������
		�ڶ��飨��������
			ƥ�����0��9��a��z֮�е������ַ��ظ�һ������ϣ�
							����һ���㣬����a��z֮�е������ַ��ظ�2��3�飨��com��cn�ȣ���
							�ڶ����ڲ���һ�飬һ���㣬����a��z֮�е������ַ��ظ�2�飨��cn��fr�ȣ�
							�ڲ�һ�����ظ���λ�һ��
	*/

	string email_address;
	string user_name, domain_name;

	regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");



	// �����ļ���β����Windows��Ctrl+Z��UNIX��Ctrl+D������ѭ��
	while (cin >> email_address)
	{
		if (regex_match(email_address, pattern))
		{
			cout << "������ĵ����ʼ���ַ�Ϸ�" << endl;

			// ��ȡ��һ��
			user_name = regex_replace(email_address, pattern, string("$1"));

			// ��ȡ�ڶ���
			domain_name = regex_replace(email_address, pattern, string("$2"));

			cout << "�û�����" << user_name << endl;
			cout << "������" << domain_name << endl;
			cout << endl;
		}
		else
		{
			cout << "������ĵ����ʼ���ַ���Ϸ�" << endl << endl;
		}
	}
 

}



// test1:  
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test1:  " << endl;


}



// test2: 
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test2:  " << endl;


}



// test3: 
static void test3(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test3:  " << endl;


}



// test4:  
static void test4(void)
{
}



// test5:  
static void test5(void)
{
}