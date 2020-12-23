#include <ctime>
#include <cstdio>
#include <typeinfo>
#include <chrono>

#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>


#ifdef WIN32
#include <windows.h>
#endif



using namespace std;

#define EPS 1e-10								//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// C++��׼�⡪�����߿�
/*
	���߿���¿��Է�Ϊ���ࣺ����֧�ֿ⡢ͨ�ÿ�

	���ݣ�
		����ָ���������
		���ں�ʱ��
		��������hash (C++11)
		�ַ���ת�� (C++17)
		���ߺ���
		pair�� tuple (C++11)
		optional (C++17)�� any (C++17)
		variant (C++17)��format (C++20)
 
*/



// struct tm����<time.h>�����һ���ṹ�壬������ʱ���ʾ
void test0()
{
	// C++ ��׼��û���ṩ��ν���������ͣ��̳���C�����������ں�ʱ������Ľṹ�ͺ���
	// windowsϵͳ�ṩ�ļ�ʱ�ӿڡ���GetTickCount();
	DWORD start = GetTickCount();			// typedef unsigned long DWORD

											// C���Ա�׼���еļ�ʱ�ӿڡ���clock()��������ʼ���˿̴�����ʱ������¼��ʱ�䣬��λΪ����
	clock_t start_c = clock();
	Sleep(2000);
	clock_t end_c = clock();

	DWORD end = GetTickCount();
	DWORD interval = end - start;
	cout << interval << endl;				// windows
	cout << end_c - start_c << endl;		// c����


	// C���Ա�׼�⡪��time()������ȡ1970.1.1 00:00:00���˿̾�����������					 
	time_t now = time(0);

	cout << "1970 ��Ŀǰ��������:" << now << endl;


	//  C���Ա�׼�⡪����ʽ��ʱ����������localtime()
	/*
		std::tm* localtime( const std::time_t *time );
		�����̰߳�ȫ�ģ�������WINDOWS�ṩ��localtime_s(),��linux�ṩ��localtime_r()
	*/


	//  C��׼���ж��������ʱ��ṹ�壺 struct tm;
	tm *ltm = nullptr;


	ltm = localtime(&now);			// ������������ת��Ϊtm����
	cout << "��: " << 1900 + ltm->tm_year << endl;
	cout << "��: " << 1 + ltm->tm_mon << endl;
	cout << "��: " << ltm->tm_mday << endl;
	cout << "ʱ��: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;


	struct tm now_tm;
	localtime_s(&now_tm, &now);
	cout << "��: " << 1900 + now_tm.tm_year << endl;
	cout << "��: " << 1 + now_tm.tm_mon << endl;
	cout << "��: " << now_tm.tm_mday << endl;
	cout << "ʱ��: " << now_tm.tm_hour << ":";
	cout << now_tm.tm_min << ":";
	cout << now_tm.tm_sec << endl;


}

