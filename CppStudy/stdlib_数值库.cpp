#include <cmath>								// ������ѧ����
#include <complex>							// ������
#include <valarray>							// ������ֵ�����������ģ��
#include <random>							// ��C++11�������������
#include <numeric>
#include <ratio>
#include <cfenv>


#include <iostream>
#include <string>
#include <typeinfo>


#include <cstdlib>
#include <ctime>
#include <cstdio>


using namespace std;

#define EPS 1e-10					// ����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



//  ֪ʶ��
/*
	<cmath>			������ѧ����
	<complex>		��������
	<valarray>		��ʾ�Ͳ���ֵ���������
	<random>		(C++11 ��)	��������������ֲ�
	<numeric>		������ֵ����ֵ����
	<ratio>			(C++11 ��)	����ʱ����������
	<cfenv>			(C++11 ��)	���㻷�����ʺ���
	<bit>			(C++20 ��)	λ���ݺ���
	<numbers>		(C++20 ��)	��ѧ����


	��ѧ���е����Ǻ���ֻ�ϻ��Ȳ��ϽǶȡ�


	

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
void set_fun_stdlib_numeric_lib(void);
void start_stdlib_numeric_lib(void);

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
void set_fun_stdlib_numeric_lib(void) 
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
}


void start_stdlib_numeric_lib(void)

{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: stdlib_IO_lib**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: <cmath>�е������궨�壬����غ���" << endl;
		cout << "1. test1: <cmath>�еĳ�����ͨ��ֵ���� " << endl;
		cout << "2. test2: <complex>�е�ʵ�����������󣬼����Ա��������غ��������������" << endl;
		cout << "3. test3: C++���������������<random>�������������ʹ��" << endl;


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

		case 2:
			(*pfun[2])();

		case 3:
			(*pfun[3])();


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}




// test0: <cmath>�е������궨�壬����غ���
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: <cmath>�е������궨�壬����غ���" << endl;

	// �꣺�����INFINITY����������һ��float
	cout << "INFINITY == " << INFINITY << endl;
	cout << "INFINITY+123 == " << INFINITY+123 << endl;
	cout << "typeid(INFINITY).name() == " << typeid(INFINITY).name() << endl;



	// INFINITY���Բ���Ƚ�����
	cout << (INFINITY > 999) << endl; 


	// ʹ�ú���bool isinf()���ж�һ�����Ƿ�Ϊ�����:
	cout << "isinf(INFINITY) == " << isinf(INFINITY) << endl;

}



// test1: <cmath>�еĳ�����ͨ��ֵ����
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test1: <cmath>�еĳ�����ͨ��ֵ����" << endl;

	cout << "\t����ֵ��	abs(-2) == " << abs(-2) << endl;
	cout << "\t��������ȡ����	round(5.7) == " << round(5.7) << endl;
	cout << "\t�����㣺	pow(2,5) == " << pow(2,5) << endl;
}


// test2: <complex>�е�ʵ�����������󣬼����Ա��������غ�������������ء�
static void test2(void)
{
	complex<double>	z1(0,1);
	complex<double> z2 = polar(1.0, PI/3);

	cout << "\n\n\n\n" << endl;
	cout << "test2:	<complex>�е�ʵ�����������󣬼����Ա��������غ�������������ء�" << endl;


	// ���캯��
	cout << "\tcomplex��Ĺ��캯����" << endl;
	cout << "\t\tcomplex<double> z1(1,2); z1 = " << z1 <<endl;
	cout << "\t\tcomplex<double> z2; z2 = polar(1.0,PI/3); z2 = " << z2 << endl;
	cout << endl;


	// �����������
	cout << "\tcomplex�����ص������" << endl;
	cout<< z1 * z2 << endl;

	z2 = z1;
	z2 = complex<double>(10,20);
	cout << z2 << endl;
	cout << endl;

	// complex��ĳ�Ա������
	cout << "z1.real() == " << z1.real() << endl;
	cout << "z2.imag() == " << z1.imag() << endl;
	cout << endl;

	// ��complex����ص����ⶨ��ĺ��������صĺ�����
	cout << "abs(z1) == " << abs(z1) << endl;
	cout << "arg(z1) == " << arg(z1) << endl;
	cout << "conj(z1) == " << conj(z1) << endl;
	cout << endl;
}





// test3: C++���������������<random>�������������ʹ��
static void test3(void) 
{
	default_random_engine e;								// ��������������������
	uniform_int_distribution<unsigned int>	UID_ui(1, 10);
	uniform_int_distribution<int>	UID_i(-100, 100);
	uniform_real_distribution<float> URD_f(-10, 10);

	cout << "\n\n\n\n" << endl;
	cout << "test3: C++���������������<random>�������������ʹ��" << endl;

	// ���ȷֲ���int, unsigned int, float
	cout << UID_i(e) << endl;
	cout << UID_ui(e) << endl;
	cout << URD_f(e) << endl << endl;


	//			ÿ�����µ��������������������µ��������
	cout << URD_f(e) << endl;



}


// test4: C���������������
static void test4(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test4: C���������������" << endl;
	

	srand(time(NULL));				// �Ե�ǰʱ��Ϊ���ӳ�ʼ�������������
	int a = 50;
	int b = 100;

	//	���ȷֲ����������
	//			[a, b)��������������
	cout << rand() % (b - a) + a << endl;
	//			[a, b]��������������
	cout << rand() % (b - a + 1) + a << endl;


}



