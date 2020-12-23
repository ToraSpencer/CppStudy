#include <string>
#include <iostream>
#include <typeinfo>
#include <exception>
#include <stdexcept>

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159





// ֪ʶ��
/*
		



*/




/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
class Complex					// �Զ��帴����
{
public:
	float real;
	float imag;

// ��Ԫ����������
	friend istream& operator>>(istream&, const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);

//		1. ���졢����������
	Complex();
	Complex(float x, float y);

//		2. static��Ա����
//		3. �Գ�Ա����get / set�ĺ���
 


//		4. ��������������ĺ���
	Complex& operator+(const Complex& cc)	const;			// ���ؼӷ������
	Complex& operator=(const Complex& cc);		// ���ظ�ֵ�����
	operator float();													// ����C��������ת�������

//		5. ��������




};





/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
istream& operator>>(istream&, Complex&);									// ����<<�������������һ������
ostream& operator<<(ostream&, const Complex&);						// ����>>������������һ������

void set_fun_syntax_overloaded_operator(void);
void start_syntax_overloaded_operator(void);

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
Complex::Complex() : real(0), imag(0)
{}


Complex::Complex(float x, float y) : real(x), imag(y)
{}



Complex& Complex::operator+(const Complex& cc)	const
{
	Complex temp;

	temp.real = real + cc.real;
	temp.imag = imag + cc.imag;

	return temp;
}


Complex& Complex::operator=(const Complex& cc)	 
{
	Complex temp;

	temp.real = cc.real;
	temp.imag = cc.imag;

	return temp;
}


Complex::operator float() 
{
	float temp;

	// ���������鲿��Ϊ0���׳��쳣������ת��ʧ�ܡ�
	if (this->imag > EPS || this->imag < -EPS)			// �ж�һ���������Ƿ�Ϊ0����ȷ����
	{
		throw invalid_argument("imaginary part is not zero;");
	}

	temp = this->real;

	return temp;

}


istream& operator>>(istream& is, Complex& cc)	
{
	is >> cc.real >> cc.imag;
	return is;
}


ostream& operator<<(ostream& os, const Complex& cc) 
{
	os << cc.real;
	if (cc.imag >= 0)
	{
		os << " + ";
	}
	else
	{
		os << " - ";
	}
	os << "i" << cc.imag;

	return os;
}



void set_fun_syntax_overloaded_operator(void) 
{
	pfun[0] = test0;

}



void start_syntax_overloaded_operator(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: syntax_overloaded_operator**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0: test0���Զ��帴����Complex�г��������������" << endl;


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



// test0���Զ��帴����Complex�г��������������
static void test0(void)
{
	Complex c1 = Complex();
	Complex c2 = Complex(3,0);
	Complex c3 = Complex(2,5);

	cout << "\n\n\n\n" << endl;
	cout << "test0���Զ��帴����Complex�г��������������" << endl;


	cout << "\tc1 == " << c1 << endl;
	cout << "\tc2 == " << c2 << endl;
	cout << "\tc3 == " << c2 << endl;

	c1 = c3;
	cout << "\tc1 = c3; c1 == " << c1 << endl;
	

	// !!!!!?????????????
	cout << "\t��ֵ����������д����Ժ��ٸ���;" << endl;
	c1 = c2 + c3;
	cout << "\tc1 = c2 + c3; c1 == " << c1 << endl;
	
	cout << "\ttypeid(c1).name()" << typeid(c1).name() << endl;


}
