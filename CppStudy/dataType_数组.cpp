#include <string>
#include<iostream>
#include <cstddef>
#include <memory>
#include <iterator>

#include <cstdio>
using namespace std;



// ֪ʶ��
/*
			1. �����ά�ȱ�����һ���������ʽ
			
			2. �ַ�����������ԣ�
							�������ַ�������������ʼ��char[]��ע��ĩβԪ����'\0'������������ò���ǲ���ȫ�ģ�����
			3. size_t���ͣ�
							�����±�һ�㶨��Ϊsize_t����
							��һ��������ص��޷�������
							��<cstddef>�ж���
							����Ƶ��㹻���Ա��ܱ�ʾ�ڴ����������Ĵ�С��
			4. �������������
							�������±�Խ�硣
							һ�����������鲻������ֻ���Լ�С�ġ�

			5. ���õ����顪��������
				 ��������ã�
								int (&arri)[10];		// arri��һ��10Ԫ��int��������á�

			6. ָ������飺
								 int *(piarr)[10];					// piarr�Ǻ���10��int*ָ��Ԫ�ص����顣
				�����ָ�룺
									int (*parri)[10];						// parri�������ָ�룬ָ��һ��10Ԫ�ص�int���顣
									float (*parrf)[] = {1.11, 2.22, 3.33};			// parrf��float�����ָ�롣


			7. ������Ϊ�����Ĳ���
							��������һ�����飬������ֵ���ݻ������ô��ݣ����˻�Ϊ������Ԫ�ص�ָ�롣
							void printf(const int[]);	// []�ڲ���Ҫд������д��Ҳ��д
																				// ��Ϊ��������ָ�����ʽ���ݽ������ģ�������������Ϣ��
																				// �����ϴ��ݵ���const int*
			8. ����ĳ�ʼ��������test4
							ȫ�������Ԫ��ֵ���Զ���ʼ��Ϊ0���ֲ����鲻���ʼ����
							����ʹ��memset()����������Ԫ��ֵ��ʼ��Ϊ0�����Ҵ˺������ʱ�̶����Խ���������Ԫ��ֵ��0��
						
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
void set_fun_dataType_array(void);
void start_dataType_array(void);


static void foo(const int arr[]);

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
void set_fun_dataType_array(void) 
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_dataType_array(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: dataType_array**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
    	cout << "0: test0: �������������ʼ��" << endl;
		cout << "1: test1: ָ������顢�����ָ��" << endl;
		cout << "2: test2: ��C++11����׼�⺯��begin(), end()����������" << endl;
		cout << "3: test3: ������Ϊ��������" << endl; 
		cout << "4: test4: ����ĳ�ʼ��" << endl;
		cout << "5: test5: " << endl; 

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




// ������Ϊ�������ݸ������������ڼ���Զ��˻�Ϊָ�롣
static void foo(const int arr[])
{
	cout << "sizeof(arg) == " << sizeof(arr) << endl;			// ע��sizeof()�ǲ�����(operator)�����Ǻ�����

}





// test0: �������������ʼ���������÷�
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: �������������ʼ��" << endl;

	// ��������ʱ������ά�ȱ�����һ���������ʽ��
	int arri1[5];

	const unsigned int size1 = 4;
	constexpr unsigned int size2 = 3;
	float arrf1[size1];
	float arrf2[size2];				// ���������ָ��size1�ǳ�����size2�ǳ������ʽ�Ļ������벻ͨ����


	// ����ʱ�������ʼֵ������Բ�дά�ȣ�
	int arri2[] = {1,2,3};


	// �б��ʼ������ֻ��ʼ���������顣
	int arri3[5] = { 9 };					// ��Ԫ����Ϊ9������Ԫ��Ĭ�ϳ�ʼ����ֵΪ0��
	for (int i: arri3) 
	{
		cout << "\t" << i;
	}
	cout << endl;


	// ʹ��sizeof���Ի�ȡ�����������Ԫ����
	cout << "\tarri1������Ϊ��sizeof(arri1) == " << sizeof(arri1) << endl;
	cout << "\tarrf1��Ԫ����ĿΪ��sizeof(arrf1)/sizeof(float) == " << sizeof(arrf1) / sizeof(float) << endl;
}




// test1:  ָ������顢�����ָ�롣
static void test1(void) 
{
	int* (arr1)[10];			// arr1��ָ�������, arr1��������
	int (*arr2)[10];			// arr2�������ָ�룬�������û��������

	cout << "\n\n\n\n" << endl;
	cout << "test1: ָ������顢�����ָ�롣" << endl;

	cout << "sizeof(int) == " << sizeof(int) << endl;
	cout << "sizeof(int*) == " << sizeof(int*) << endl;
	cout << "sizeof(void*) == " << sizeof(void*) << endl;


	cout << "sizeof(arr1) == " << sizeof(arr1) << endl;      // sizeof(������)���ص����������������
	cout << "sizeof(arr2) == " << sizeof(arr2) << endl;      // arr2������������ֻ��һ��ָ�룬C++������ָ����������һ���ģ��ɻ���������

}



// test2: ��C++11����׼�⺯��begin(), end()����������
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test2: ��C++11����׼�⺯��begin(), end()����������" << endl;


	// begin(), end()����������ͷ�ļ�<iterator>
	// ����������ֱ𷵻��������Ԫ��ָ�롢β��ָ�롣
	int arri1[] = {1,2,3,4,5};
	int* pi = arri1;

	cout << "\t��������arri1:" << endl;
	while (pi != end(arri1))
	{
		cout << "\t" << *(pi++);
	}
	cout << endl;


}





// test3: ������Ϊ��������
static void test3(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test3: ������Ϊ��������"<< endl;

	
	int arr[] = {1,2,3,4,5};

	cout << sizeof(arr) << endl;			// ���Ϊ20��ע��sizeof()�ǲ�����(operator)�����Ǻ��������鴫�ݸ�sizeof�����˻�Ϊָ�롣sizeof(arg)Ҳ����д��sizeof arg;
	foo(arr);													// ��ӡ���Ϊ4��32λ����

	
}



// test4: ����ĳ�ʼ��
static void test4(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test4: ����ĳ�ʼ��"<< endl;

	auto fDisp = [](int* pi, int len)
	{
		for (int i = 0; i<len; i++)
		{
			cout << *pi << "  ";
			pi++;
		}
		cout << endl;
	};


	auto foo = [&fDisp]()
	{
		int arri[10];		// arri��lambda���ʽ�ڣ���һ���ֲ��������
		fDisp(arri, 10);	// ��ʱ������ӡarri������Ԫ�أ����Կ���û�г�ʼ����
		memset(arri, 0, sizeof(arri));
		fDisp(arri, 10);	// ��ʱ��ӡȫ��Ϊ0��
	};


	foo();
}

void test5() {}