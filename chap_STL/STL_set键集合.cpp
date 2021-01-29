#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>



#include <cstdio>


#include "example.h" 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// ֪ʶ��
/*
	1. ���й���������set, map, multiset, multimap�ײ㶼�Ǻ����
	
	2. �ص��ǲ��롢ɾ��Ч�ʸߡ�
				�����ʱ��ֻ��Ҫ�����任��Ȼ��ѽڵ��ָ��ָ���µĽڵ�Ϳ����ˡ�
				ɾ����ʱ�����ƣ������任���ָ��ɾ���ڵ��ָ��ָ�������ڵ�ҲOK�ˡ�
				�����һ�в�������ָ�뻻����ȥ�����ڴ��ƶ�û�й�ϵ�����Բ�������������ʧЧ�����⡣

	3. ���÷���
	 			begin() end() rbegin rend() ���ص�����
				clear()   �� ���������
				empty() �������ж�set�����Ƿ�Ϊ��
				max_size() �� ����set�������ܰ�����Ԫ��������
				size() �������� ���ص�ǰset�����е�Ԫ�ظ���

	4. ��map��������map�е�Ԫ����key��value�������ݣ�set�е�Ԫ��ֻ��keyһ�����ݡ�

	5. ����set�е�Ԫ�ض����Զ����򡣰���Ԫ�ص�<������������С�

	6. set�ĵ�������������const�ģ�ֻ�ܶ�����д����Ϊ�Ķ�set��Ԫ���п��ܻ�����������ǲ�����ġ�

*/












// STL��������������set, map, multiset, multimap
/*
		set 					Ψһ���ļ��ϣ����ռ�����
		map 					��ֵ�Եļ��ϣ����ռ����򣬼���Ψһ��
		multiset 				���ļ��ϣ����ռ�����
		multimap 				��ֵ�Եļ��ϣ����ռ�����
 
���ԣ�
		�ײ��Ǻ����ʵ�֡�
		����Ѹ�١�������O(log n) ���Ӷ�
		������ֱ���޸�Ԫ�أ�ֻ����ɾ���
		�����бȽ���value_compare����һ�������ӣ������涨�����м�������Ĺ���
*/




// STL�����������������unordered_set, unordered_map, unordered_multiset, unordered_multimap
/*
		(C++11 ��)unordered_set 						Ψһ���ļ��ϣ����ռ�����ɢ��
		(C++11 ��)unordered_map 						��ֵ�Եļ��ϣ����ռ�����ɢ�У�����Ψһ��
		(C++11 ��)unordered_multiset					���ļ��ϣ����ռ�����ɢ��
		(C++11 ��)unordered_multimap 					��ֵ�Եļ��ϣ����ռ�����ɢ��
 

���ԣ�
		�ײ��ǹ�ϣ�ṹ��
		����Ѹ�١�����������̯ O(1) ������ O(n) �ĸ��Ӷ�

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
void set_fun_STL_set(void);
void start_STL_set(void);

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

void set_fun_STL_set (void)
{
	pfun[0] = test0;
	pfun[1] = test1;
}



void start_STL_set(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL_set**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: set�Ļ���ʹ�÷�����API" << endl;
		cout << "1. test1: set�Ĳ��ҽӿ�" << endl;


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

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// test0: set�Ļ���ʹ�÷�����API
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: set�Ļ���ʹ�÷�����API" << endl;

	// �������͵�set:
	// 		���뵽set�еĻ�������Ԫ�ػ�Ĭ�ϴ�С�������򣬲��뵽���ʵ�λ�á�
	set<int> seti1;									// ���췽��1
	set<int>::iterator iter_i;
	baseTypePrinter btp;

	seti1.insert(1);
	seti1.insert(0);
	seti1.insert(9);
	seti1.insert(8);
	seti1.insert(11);
	seti1.insert(-3);

	for_each(seti1.begin(), seti1.end(), btp);


	// 		����Ҫ�޸�Ԫ������ķ�ʽ������ʱ

 


}


// test1: set�Ĳ��ҽӿ�
static void test1(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test1: set�Ĳ��ҽӿ�" << endl;

	set<int> seti1;									// ���췽��1
	set<int>::iterator iter_i1;
	baseTypePrinter btp;
	pair<set<int>::iterator, set<int>::iterator> pi1;

	seti1.insert(1);
	seti1.insert(0);
	seti1.insert(9);
	seti1.insert(8);
	seti1.insert(11);
	seti1.insert(-3);

	//	find�����������ҳɹ�����ָ����������ĵ�����������ʧ�ܷ���β�������
	iter_i1 = seti1.find(-3);					
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û��-3���Ԫ��" << endl;

	}
	else
	{
		cout << "\titer_i��ָ��seti1��Ԫ��-3�ĵ�������" << endl;

	}


	// lower_bound����������set���׸�С�ڵ���ָ��Ԫ�ص�Ԫ�ص�����
	iter_i1 = seti1.lower_bound(1);
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û��С�ڵ���1��Ԫ��" << endl;

	}
	else
	{
		cout << "\tseti1���׸�С�ڵ���1��Ԫ��Ϊ��*iter_i1 == " << *iter_i1 << endl;

	}



	// upper_bound������������set���׸����ڵ���ָ��Ԫ�ص�Ԫ�ص�����
	iter_i1 = seti1.upper_bound(1);
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û�д��ڵ���1��Ԫ��" << endl;

	}
	else
	{
		cout << "\tseti1���׸����ڵ���1��Ԫ��Ϊ��*iter_i1 == " << *iter_i1 << endl;

	}


	// equal_range������������һ��pari���ֱ����lower_bound��upper_bound���Է��صĵ�����
	pi1 = seti1.equal_range(1);
	if(pi1.first != seti1.end())
	{
		cout << "\t*pi1.first == " << *pi1.first << endl;
	}
	if(pi1.second != seti1.end())
	{
	cout << "\t*pi1.second == " << *pi1.second << endl;
	}


}