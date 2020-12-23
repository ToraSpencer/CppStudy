#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <utility>  				// �ṩpair����


#include <cstdio>

#include "example.h" 
using namespace std;

#define EPS 1e-10					// ����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


 


// ֪ʶ��
/*
	 1. map, multimap, unordered_map, unordered_multimap��������
					1. Ԫ����pair����
					2. ������Ԫ�صļ���ͬ������multi-��ͷ��map��set����
					3. ������ǿ�ͷΪunorderedָ����������������˳�򱣴��ڲ���Ԫ�ء�

		2. map�ļ��ֹ��캯����ʽ


		3. map��set����ĵײ�ԭ����ʹ�������"<"���Ƚ�Ԫ��


		4. ���������������unordered_map��unordered_set����ʹ�ù�ϣ��������֯Ԫ�ء�


		5. map�ĳ��÷���
					1. ��
									insert()
									
					2. ɾ
									erase()����3����
									
					3. ��		
									find(), count(), lower_bound(), upper_bound()

					4. �ģ����ʣ�		
									�±�����[]
				


*/




/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
struct person
{
	string name;
	bool sex;
	int age;
	string job;
};



/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
inline void dispPerson(person&); 

void set_fun_STL_map(void);
void start_STL_map(void);

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
inline void dispPerson(person& p) 
{
	if(p.age)
	{
		cout << p.name << ", male, age: " << p.age << ", career: " << p.job << endl;
	}
	else
	{
		cout << p.name << ", female, age: " << p.age << ", career: " << p.job << endl;
	}
	
	
}



void set_fun_STL_map(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;
}



void start_STL_map(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL����map**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: map�Ļ���ʹ�÷�����API" << endl;
		cout << "1. test1: multimap�Ļ���ʹ�÷�����API" << endl;
		cout << "2. test2: map/multimapӦ�ó��������������������������Ϣ��" << endl;

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


// test0: map�Ļ���ʹ�÷�����API
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: map�Ļ���ʹ�÷�����API" << endl;

	map<int, string>  mis;
	map<int, string>::iterator iter1;
	pairPrinter pp;


	// ��ɾ���
	cout << "\tmap����ɾ��ģ�" << endl;

	//			ʹ��insert������Ԫ��
	mis.insert(make_pair(6, "xiaohong"));			// ����pair����
	mis.insert(make_pair(5,"ali"));

	//			ʹ���±�����������ӡ��޸�Ԫ��
	mis[1] = "xiaoming";								// �±���������޸ü�ʱ�����ü����иü�ʱ�޸ĸü���						
	mis[33] = "laowang";
	mis[33] = "laoli";	
	for_each(mis.begin(), mis.end(), pp);
	cout << endl;

	//			erase()���������ɾ��Ԫ��
	mis.erase(1);				
	for_each(mis.begin(), mis.end(), pp);
	cout << endl;


	//			find()�������������Ԫ��
	iter1 = mis.find(33);
	mis.erase(iter1);				// erase()�������������ɾ��Ԫ��
	for_each(mis.begin(), mis.end(), pp);
	cout << endl;
}





// test1: multimap�Ļ���ʹ�÷�����API
static void test1(void) 
{

	// multimap�п����м���ͬ��Ԫ�أ���ͬ����Ԫ�ػ����ڴ洢��
	// multimapû���±����㣬����api��map���ơ�
	cout << "\n\n\n\n" << endl;
	cout << "test1: multimap�Ļ���ʹ�÷�����api" << endl;

	multimap<string, int> mmss;
	pairPrinter pp;

	mmss.insert(make_pair("xiaohong", 16));
	mmss.insert(make_pair("xiaoming", 17));
	mmss.insert(make_pair("xiaohong", 8));
	mmss.insert(make_pair("xiaohong", 2));
	mmss.insert(make_pair("laowang", 1));
	for_each(mmss.begin(), mmss.end(), pp);
	cout << endl;


	// ���Ҳ���ӡ��ĳһ����ȫ��Ԫ�أ�
	cout << "\t���ҳ�multimap��ĳ��������Ԫ��" << endl;
	int num = mmss.count("xiaohong");							// multimap::count()������������ĳ��Ԫ�صĸ�����
	multimap<string, int>::iterator iter1 = mmss.find("xiaohong");	// ���ص�һ����Ϊxiaohong��Ԫ�صĵ�����
	for(int i = 1; i<=num; i++)
	{
		cout << "\t";
		//pp(*(iter1++));
	}
	cout << endl;

}



// test2: Ӧ�ó�������vector��multimapʵ�ֵı������������������Ϣ��
static void test2(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test2: map/multimapӦ�ó��������������������������Ϣ��" << endl;

	person p1 = { "xiaoming", true,  10, "student" };
	person p2 = { "xiaohong", false,  11, "doctor" };
	person p3 = { "xiaolan", true,  12, "teacher" };
	person p4 = { "xiaohuang", true,  10, "teacher" };
	person p5 = { "laowang", true,  13, "worker" };
	person p6 = { "laoli", false,  10, "famer" };
	person p7 = { "xiaoming", false,  10, "famer" };


	// ���ݴ���������
	vector<person> vp;
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);
	vp.push_back(p6);
	vp.push_back(p7);


	// ������������������multimap:
	multimap<string, int> m_name;			// ����������Ԫ�ؼ��Ǹ���������ֵ�Ǹ�����vp�����е��±ꡣ
	multimap<int, int> m_age;					// ����������
	for(int i=0; i<=6; i++)
	{
		m_name.insert(make_pair(vp[i].name, i));
		m_age.insert(make_pair(vp[i].age, i));
	}


	// ��������ӡ���ݣ�
	multimap<string, int>::iterator iter1;
	multimap<int, int>::iterator iter2;
	int num;
	
	//		�������֡�xiaoming��
	num = m_name.count("xiaoming");
	iter1 = m_name.find("xiaoming");
	for(int i = 1; i<= num; i++)
	{
		cout << "\t";
		dispPerson(vp[(*iter1).second]);
		iter1++;
	}
	cout << endl;

	//		��������10
	num = m_age.count(10);
	iter2 = m_age.find(10);
	for(int i = 1; i<= num; i++)
	{
		cout << "\t";
		dispPerson(vp[(*iter2).second]);
		iter2++;
	}
	cout << endl;


}



static void test3(void) 
{}



static void test4(void)
{}



static void test5(void)
{}