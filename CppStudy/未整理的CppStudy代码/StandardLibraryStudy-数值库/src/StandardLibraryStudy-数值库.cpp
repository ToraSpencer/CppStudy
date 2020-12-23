#include <cmath>							//������ѧ����
#include <complex>							//������
#include <valarray>							//������ֵ�����������ģ��
#include <random>							//�����������
#include <numeric>
#include <ratio>
#include <cfenv>

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#define pi 3.14159

//<cmath>
void test1()
{
	cout << "<cmath>: " << endl << endl;

	cout << "�����" << endl;
	cout << INFINITY << endl;
	cout << "�ú���bool isinf()���ж�һ�����Ƿ�Ϊ�����" << isinf(INFINITY) << endl;
	cout << "INFINITY������Ϊfloat: typeid(INFINITY).name() = " << typeid(INFINITY).name() << endl;
	cout << endl;

	cout << "������ֵ����" << endl;
	cout << "abs(-2) = " << abs(-2) << endl;
	cout << "round(5.7) = " << round(5.7) << endl;
	cout << endl;

	cout << "�������ú���pow(),��֧��^�������ʾ�����㡣 pow(2,5) = " << pow(2,5) << endl;




	cout << endl;
}

//<complex>
void test2()
{
	cout << "<complex>" << endl << endl;

	//���췽��
	cout << "��������Ĺ��췽����" << endl;
	complex<double> z1(0,1);
	cout << "complex<double> z1(1,2); z1 = " << z1 << endl;
	complex<double> z2;
	z2 = polar(1.0,pi/3);								//ģ�ͷ��Ǳ���ͬ��int��float����������1д��1.0
	cout << "complex<double> z2; z2 = polar(1.0,pi/3); z2 = " << z2 << endl;
	cout << endl;



	//���������
	cout << "Ϊ����������һϵ�е��������" << endl;
	cout << "�����˷���z1*z2 = " << z1*z2 << endl;		//����ֻ�ܺ͸������㣬�����Ժ�ʵ�����㣬���Խ�ʵ����д�ɸ�����
	cout << endl;


	//���غ���
	cout << "������exp():" << endl;
	cout << "matlab���exp(1j*pi/6) = exp(complex<double>(0,pi/6)) =" << exp(complex<double>(0,pi/6)) << endl;
	cout << endl;

	//��Ա��������������
	cout << "�������Ա��������غ�����" << endl;
	cout << "���ظ�����ʵ����z1.real() = " << z1.real() << endl;
	cout << "���ظ������鲿: z1.imag() = " << z1.imag() << endl;
	cout << "���ظ�����ģ: abs(z1) = " << abs(z1) << endl;
	cout << "���ظ����ķ��ǣ�arg(z1) = " << arg(z1) << endl;
	cout << "���ظ����Ĺ��conj(z1) = " << conj(z1) << endl;
	cout << endl;

	//��������ĸ�ֵ��
	cout << "ֻ�ܹ����һ���¸�������Ȼ�󽫸ö���ֵ����һ��������ʵ�ָ�ֵ��" << endl;
	z2 = complex<double>(2,3);
	cout << "z2 = complex<double>(2,3); z2 = " << z2 << endl;
	cout << endl;

}

//<random>
void test3()
{
	cout << "<random>" << endl << endl;

	default_random_engine e;
	uniform_int_distribution<unsigned> u(1,10);
	uniform_int_distribution<int> i(-100,100);
	uniform_real_distribution<float> f(-10,10);



	unsigned randomUnsigned = u(e);
	int	randomInt = i(e);
	float randomFloat = f(e);
	float randomFloat_new = f(e);

	cout << "1~10֮��������������: randomInt = " << randomUnsigned << endl;
	cout << "-100~100֮���������ֲ���������" << randomInt << endl;
	cout << "-10~10֮���������ȷֲ������������" << randomFloat << endl;
	cout << "ÿ�ε��������������������µ��������randomFloat_new = f(e) = " << randomFloat_new << endl;
	cout << endl;

	cout << "ÿ�ε��������������������µ��������" << endl;
	float temp;
	for(int i = 1;i<=10;i++)
	{
		temp = f(e);
		cout << temp << "  " << endl;
	}
}

int main()
{
	//test1();
	test2();
	//test3();

	return 0;
}

