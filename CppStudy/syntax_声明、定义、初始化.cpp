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



// syntax_���������塢��ʼ��
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
void set_fun_syntax__declare_define_initialize(void);
void start_syntax__declare_define_initialize(void);

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
class AAA 
{
private:
	int numi;
	float numf;

public:
	AAA()
	{}

	void disp()
	{
		cout << "AAA���͵Ķ����У�numi == " << this->numi << "�� numf == " << this ->numf << endl;
	}
};



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_declare_define_initialize(void) 
{

}



void start_syntax_declare_define_initialize(void) {}





//
AAA a_global;
int numi_global;
float numf_global;
static void test0(void) 
{
	extern int intName;			// ������������һ������
	int intDefined;				// ���塪������һ������ʵ�壬��һ�����ְ�������

	// ����������ȫ�ֱ��������������Ǿֲ�������main����Ҳ�㡣
	//	ȫ�ֻ������ͱ������Զ���ʼ��Ϊ0ֵ���ֲ��������͵ı��������Զ���ʼ����
	//	����������ʱ�򣬲����Ǿֲ��Ļ���ȫ�ֵģ������Զ������޲ι��캯����
	//	δ��ʼ���ľֲ���������ʹ�á�
	AAA a_local;
	int numi_local;
	float numf_local;

	a_global.disp();
	cout << "numi_global =="<< numi_global << endl;
	cout << "" << numf_global << endl;

	// ��Ĺ��캯���У����Բ���ʾ��ʼ����Ա���ݡ�
	//		Ȼ���øù��캯�������ȫ�ֶ�����Զ�����Ա���ݳ�ʼ��Ϊ0ֵ��
	//		�ֲ������Ա���ݲ����Զ���ʼ����Ϊ���ֵ�����ǲ���Ӱ��ö����ʹ�á�
	a_local.disp();



}
