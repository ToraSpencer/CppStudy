#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
using namespace std;


/* auto������C++11������˵����
 * 			�ñ��������ݳ�ʼֵ���ƶϱ��������͡�
 */
void test1()
{
	cout << "" << endl;
	int a = 1;
	int b = 2;
	auto c = a+b;				// ����c��ʼ��Ϊa+b�Ľ����


	cout << "c = a+b = " << c << endl;
	cout << "typeid(c).name() = " << typeid(c).name() << endl;
}

void test2()
{
	int i1 = 5;
	const int ci1 = 10;
	auto p1 = &i1;		// auto����Զ���const����������auto������ָ�붼����const
	auto p2 = &ci1;		// �˴��ǵײ�const��auto��p2�����������const int*����ʼָ��int������ֻ��ָ�롣
}

int main()
{
	//test1();
	test2();

	return 0;
}


