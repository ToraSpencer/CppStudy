#include <string>
#include<iostream>

#include <cstdio>


#include "example.h"


using namespace std;


// ֪ʶ��
/*
	#define���������꣨macro������ 
			��ʽ
						#define ��  �滻��
						��һ�����滻�峬��һ�У���һ�е���ĩβ��Ҫ��\
			ע��
						���滻�ı�������ȫ���ı��滻�����Ǻ��滻Ϊ�ַ���
						����һ���Ǻ�(token)���ַ������������ַ����ַ���
									������������#define PI 3.14159
									˫�����е�PI���ᱻ�滻����Ϊ���ַ����ַ���
									�����ط���PI�ᱻ�滻���ı�3.14159
			���ࡪ������1. ������(object-like macro)��	2. �ຯ����(function-like macro)

			�꺯�����ຯ���꣩
						��test2;
						

	����ض���
			�ȳ������еĺ궨�壺#undef  PI
			���ض���ú꣺ #define PI 3.14159

	#include���������ļ�����
	

	Ԥ�������
			C��׼��Ԥ����õ�һЩ����
			�����Ա��ض���
			��__FILE__, __LINE__��


	Ԥ���������ָ��
			#line
						����__FILE__��__LINE__������
						���ӣ�
									#line 1000				 // ��ǰ�к�����Ϊ1000 
									#line 10 "temp.c"     // ��ǰ�к�����Ϊ10����ǰԴ�ļ�������Ϊtemp.c

	��������
			#ifdef, #else, #endif
			#ifndef, #else, #endif
			#if, #elif, #else, #endif

	�Ǻ�ճ�ϼ�����##�����
			�����ں���滻����
			�������Ǻ�ճ�ϳ�һ���Ǻţ�Ȼ����Ϊ�ú���滻��


	#pragma������������ָʾ
			��Դ��������ӱ���ָ��
			�趨��������״̬��������ָʾ���������һЩ�ض��Ķ�����
			#pragma once
						ͨ������ͷ�ļ��У�ʹ�ø�ͷ�ļ�ֻ������һ�Ρ�
						�Ǳ�׼��������׼�ķ���Ӧ����ʹ��#ifndef
						���Ǳ��㷺���ã�ע����Щ�ϵı��������ܲ�֧�֡�
			#pragma comment
						���ӿ��ļ���
			#pragma pack
						�����ڴ����



									

	#error������������ָ��
			��Ԥ������������ʾ�ô���ָ���е��ı�
			���ӣ�#error not C11



	����Ԥ�����
			ANSI C��׼���м�����׼Ԥ����꣺
						__FILE__����ǰԴ�����ļ������ַ���������
						__LINE__����ǰԴ�����кŵ����ͳ���
						__DATE__��Ԥ��������ڣ��ַ���������
						__TIME__����������ʱ�䣬�ַ���������
						__STDC__����Ҫ������ϸ���ѭANSI C��׼ʱ�ñ�ʶ����ֵΪ1��
						__cplusplus������дC++����ʱ�ñ�ʶ�������塣

	���������ĺ궨��
			#define _DEBUG              // ���Ժ꣬���ʹ��VS������Ŀʱ�����������ѡ��Debug�Ļ��������Զ�����˺ꡣ
			#define _NDEBUG             // release��
			#define _WINDLL             // ��ʾҪ��һ���õ�MFC��DLL
			#define _DLL                // ����������Ϊ��̬���ӿ�ʱ����ֵΪ1��
			
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
void set_fun_UP_preprocessing(void);
void start_UP_preprocessing(void);
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
void set_fun_UP_preprocessing(void) 
{
	pfun[0] = test0;
}



void start_UP_preprocessing(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: PREPROCESSING**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: ����Ԥ������ţ������������" << endl;
 


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

 
		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// test0: ����Ԥ������ţ�����������
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: ����Ԥ������ţ������������" << endl;

	cout << "\t��ǰԴ�ļ������ƣ�__FILE__ == " << __FILE__ << "�� ���ַ�����������"<< endl;
	cout << "\t��ǰԴ�ļ��еĴ����кţ�__LINE__ == " << __LINE__ << "����ʮ����������" << endl;
	cout << "\t��ǰԴ�ļ��Ĵ������ڣ�__DATE__ == " << __DATE__ << "�� ���ַ�����������" << endl;
	cout << "\t��ǰԴ�ļ��ı���ʱ�䣺__TIME__ == " << __TIME__ << "�� ���ַ�����������" << endl;
	cout << endl;

#ifdef __cplusplus
	cout << "\tC/C++��ϱ���п���ʹ��#ifdef __cplusplus ... #endif �� extern \"C\"{}������C��C++�Ĵ��롣" << endl;
	cout << "\tC++03��__cplusplus = 199711L" << endl;
	cout << "\tC++11��__cplusplus = 201103L" << endl;
	cout << "\t���Ը���__cplusplus���ֵ���жϵ�ǰC++�������İ汾��" << endl;
	cout << "\t��ǰ��Ŀ�У�__cplusplus == " << __cplusplus << endl;
	cout << endl;
#endif


	// #error #warning ������󡢱��뾯��
#ifndef __cplusplus
	#error this project should be processed with c++ compiler
#endif



 
	#line 1000								// ��ǰ�к�����Ϊ1000 
	cout << "\t��ǰ�к�����Ϊ1000 ��#line 1000; __LINE__ == " << __LINE__ << endl;
	#line 10 "temp.c"						 // ��ǰ�к�����Ϊ10����ǰԴ�ļ�������Ϊtemp.c
	cout << "\t��ǰ�к�����Ϊ10����ǰԴ�ļ�������Ϊtemp.c:" << endl;
	cout << "\t__LINE__ == " << __LINE__ << endl;
	cout << "\t__FILE__ == " << __FILE__<< endl;
}






// test1�����õ�һЩ�Զ����ļ���
#define GENCLASS( className )   class className : public Person	
GENCLASS(bitch)
{
public:
	virtual void say()
		{
			 std::cout << "Hello, i'm a bitch, my name is "<< this->name << ". I'm " << this->age  \
			 << " years old. I live in "<< this->address << ". I'm a "<< this->career \
			 << "." << std::endl;
		}

};


// test2: �꺯��
/*
	���еĲ������������������滻�弴Ϊ�����塣
	�꺯��û��inline������ȫ����Ϊֻ�ǵ�����չ������������ȫ���
	ע��ÿ����������ü����ţ�����������������ŵĻ�TIMES(1+2,3+4)��չ��Ϊ1+2*3+4��
*/
#define TIMES(x,y) (x)*(y)	

// 	#���Խ��꺯���еĲ����ַ�����
//			��ʱ���꺯���еĲ���xΪ__FILE__�����䲻�ᱻ��չ��������ֱ��ת��Ϊ�ַ�����
#define _STRING(x) #x

static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test2: �꺯��" << endl;

	cout << TIMES(1+2, 3+4) << endl;
	cout << _STRING(__FILE__) << endl;

}
