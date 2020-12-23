#include <iostream>
#include <string>
#include <typeinfo>

#include <memory>
#include <vector>
#include <cstddef>
#include <cstdio>
#include <new>



using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// ֪ʶ��
/*
			1. union�����塪������������г�Առ��ͬһ���ڴ棬�޸�һ����Ա��Ӱ���������г�Ա��
			
			2. ö���ص㣺
							Ԫ��ֵ����������ֵ��
							
			3. �ṹ���е��ڴ�������⣬���UP_�ڴ�����½ڡ�




*/








/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
typedef struct person
{
	string name;
	bool sex;
	int age;
	string job;
} person;


struct controlWord				// ʹ����λ�ֶεĽṹ�壬����ÿ����Ա����һ���ֶΡ�
{
	unsigned int word1 : 4;   	// 4bitΪword1��ֵ
	unsigned int : 4;        		// 4bitΪ�հ׵�ռλ
	bool word2 : 1;
	bool word3 : 1;
};


typedef union data
{
	int numi;
	float numf;
	char ch;
} unionData;

typedef struct
{
	char a;
	short b;
	int c;
	long d;							// 32λϵͳ��long�Ĵ�С��4�ֽڣ�64λϵͳ����8�ֽڡ�
	char e;
	long long f;				// long long�Ĵ�С��8�ֽڡ�
}stru;
 


/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
inline void dispPerson(person&); 

void set_fun_dataType_EUS(void);
void start_dataType_EUS(void);

static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);


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
void set_fun_dataType_EUS(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_dataType_EUS(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: dataType_EUS**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: �ṹ��Ļ���ʹ�÷���" << endl;
		cout << "1. test1��ö�����͵Ļ���ʹ��" << endl;
		cout << "2. test2��������Ļ���ʹ��" << endl;
		cout << "3. test3: �ṹ���е��ڴ����" << endl;


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



// test0: �ṹ��Ļ���ʹ�÷���
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: �ṹ��Ļ���ʹ�÷���" << endl;

	// �ṹ��ʵ����ʼ����
	//		ע��C�������ṹ��ʵ��ʱǰ��Ҫ��struct
	//				һ��C��ʹ��typedef   person{.....}person; �����ĸ�ʽ�����ṹ�壬Ȼ������ʵ����ʱ��Ͳ���дstruct��
	person p1 = {"xiaoming", true, 18, "doctor"};
	person p2 = {};						// ��ʱ���г�ԱֵΪ0


	dispPerson(p1);
	cout << endl;
	dispPerson(p2);
	cout << endl;


}



// test1��ö�����͵Ļ���ʹ��
static void test1(void)
{
	// ����ö�����͵���ҪĿ���ǣ����ӳ���Ŀɶ��ԡ�
	// ö���������Ҳ����������ô�֮һ������������״̬��
	cout << "\n\n\n\n" << endl;
	cout << "test0: �ṹ��Ļ���ʹ�÷���" << endl;



	// ����ö������
	enum weekDay{SUN, MON, TUE, WED, THU, FRI, SAT};		// Ĭ�������£�ö�ٳ���ȡֵΪ0, 1, 2,...	
	enum color{RED, BLUE, GREEN = 1, YELLOW};						// ȡֵ���ظ�����ʱȡֵ�ֱ�Ϊ0,1,1,2		



	// ö�����͵���Ϣ
	cout << "typeid(SUN).name() " << typeid(SUN).name() << endl;	// ö�ٳ���SUN��������weekDay��weekDay������������
	cout << "sizeof(weekDay) == " << sizeof(weekDay) << endl;		// ��������ֵ��weekDay���͵Ĵ�С
	cout << "sizeof(SUN)" << sizeof(SUN) << endl;								// ö�����͵Ĵ�С��ȷ�����������������ֵ��С�����䣬������1,2,4�ֽڣ�һ�������͡�
	

	// �򵥵�Ӧ�þ�����
	int num;
	int inputValid = 0;
	string str;
	enum person{alice = 1, bob, cindy, david, eric, frank, grey};
	cout << "������Ҫ�鿴��ѡ�ֱ��" << endl;
	while(0 == inputValid)
	{
		setbuf(stdin, NULL);
		inputValid = scanf("%d", &num);

		if(0 == inputValid || num < 1 || num > 6)
		{
			cout << "���벻�Ϸ������������롣" << endl;
			setbuf(stdin, NULL);
		}
	}
	switch(num)
	{
		case 1:
			str = "alice";
			break;

		case 2:
			str = "bob";
			break;

		case 3:
			str = "cindy";
			break;

		case 4:
			str = "eric";
			break;

		case 5:
			str = "frank";
			break;

		case 6:
			str = "grey";
			break;

		default:
			break;
	}
	cout << num << "��ѡ����" << str << endl;
}



// test2: ������Ļ���ʹ��
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test2:  ������Ļ���ʹ��" << endl;

	unionData a;
	a.numi = 99;
	printf("sizeof(unionData) == %u\n", sizeof(unionData));
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	// union��һ����Ա�ĸ��ģ���Ӱ�쵽������Ա
	a.numi = 1;
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	a.numf = 3.14;
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);

	a.ch = 'a';
	printf("%d, %f, %c\n", a.numi, a.numf, a.ch);
	
 
}




// test3: �ṹ���е��ڴ����
static void test3(void)
{
	cout << "\n\n\n\n" << endl;
	cout << " test3: �ṹ���е��ڴ����" << endl;

	stru s1 = {1,2,3,4,5,6};
	unsigned char* pc= NULL;
	pc = reinterpret_cast<unsigned char*>(&s1);

	// s1���ڴ�Ӧ���������ģ�
	/*
		char a; short b; int c; long d; char e; long long f;

		axbbcccc
		dddddddd
		exxxxxxx
		ffffffff
		����һ��ռ32�ֽڣ��ṹ��ʵ���ڲ������ݷֲ�����ʹ��һ��unsigned char*ָ�����鿴��֤��
	*/

	
	cout << "sizeof(s1) == " << sizeof(s1) << endl;
	cout << "�ṹ��ʵ��s1�ڲ����ݷֲ���" << endl;
	for(int i = 1; i<=32; i++)
	{
		printf("%d. 0x%x\n" , i, *pc);
		pc++;
		if(i>=32)
		{
			break;
		}
			
	}



}



static void test4(void)
{}



static void test5(void)
{}