#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// C++�﷨�������ʽ��constexpr
/*
		 
*/


/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_expression(void);
void start_syntax_expression(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);


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
void set_fun_syntax_expression(void) {}



void start_syntax_expression(void) {}



// �������ʽconstexpr�ļ�Ӧ��
constexpr unsigned fooConst()			// ����ֵΪconstexpr�ĺ���
{
	return 9;
}
 
static void test0(void) 
{
	int arr[fooConst()];				// fooConst()��������һ���������ʽ�����������������顣

	cout << sizeof(arr) << endl;

}
