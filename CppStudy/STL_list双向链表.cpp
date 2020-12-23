#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>
 

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// STL����list˫������
/*
**	���ݽṹ������˫������������ÿ���ڵ㺬������ָ�룬�ֱ�ָ��ǰһ���ڵ�ͺ�һ���ڵ㡣
**	ʵ������������й��ܡ�
**
**
** ���ƣ�
** 		�κ�λ��ִ�в��롢ɾ����ʱ�临�Ӷȶ���O(1);
** 		˫���������ԣ�push_back(),pop_back,push_front,pop_front()
**
**
** ���ƣ�
**		��֧�������ȡ�����ṩat()�������±������
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
void set_fun_STL_list(void);
void start_STL_list(void);

template <typename T>
void dispList(const list<T>& l);

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
void set_fun_STL_list (void)
{
	pfun[0] = test0;
	pfun[1] = test1;
}



void start_STL_list (void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL_list**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  list�Ĺ��졢�������� " << endl;
		cout << "1. test1��listԪ�صķ��ʡ�����" << endl;


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


		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// ������ӡlist�ĺ�����
template <typename T>
void dispList(const list<T>& l)
{
	auto beg = l.begin();
	auto end = l.end();

	while (beg != end)
	{
		cout << "\t" << *beg;
		beg++;
	}
	cout << endl;
	return;
}



// test0:  list�Ĺ��졢��������
static void test0(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0:  list�Ĺ��졢��������" << endl;

	// explicit list(size_type n);	���캬n��0Ԫ�ص�list��
	cout << "\t���캬n��0Ԫ�ص�list��list<int> l1(5);" << endl;
	list<int> l1(5);
	dispList(l1);
	cout << endl;

	// list(size_type n, T val);	���캬n��valԪ�ص�list
	cout << "\t���캬n��valԪ�ص�list��list<double> l2(5,8);" << endl;
	list<double> l2(5, 8);
	dispList(l2);
	cout << endl;

	// ʹ��ָ����������Ȧ��һϵ��Ԫ������ʼ��list��
	cout << "\tʹ��ָ����������Ȧ��һϵ��Ԫ������ʼ��list��" << endl;
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int* p1 = arr;
	int* p2 = &arr[8];
	list<int> l31(p1, p2);							// ����ָ��������ָ���ķ�Χ���������[p1,p2)
	list<int>::iterator it1 = l31.begin();
	list<int>::iterator it2 = l31.end();
	it1++;
	it2--;
	list<int> l32(it1, it2);
	dispList(l31);
	dispList(l32);
	cout << endl;
}


// test1��listԪ�صķ��ʡ�����
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test1��listԪ�صķ��ʡ�����" << endl;


	list<int> l = list<int>();

	// ���׶ˡ�β�˷��뵥��Ԫ�أ�push_front(), push_back()
	//		void push_front(const T& x);
	//		void push_front(T&& x);
	//		void push_back(const T& x);
	//		void push_back(T&& x);
	cout << "\t���׶ˡ�β�˷��뵥��Ԫ�أ�push_front(), push_back()" << endl;
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	dispList(l);
	cout << endl;

	// ��ȡ�׶Ρ�β�˵�һ��Ԫ�أ�front(), back()
	//		T&  front();
	//		const T& front() const;
	//		T&  back();
	//		const T& back() const;
	cout << "\t��ȡ�׶Ρ�β�˵�һ��Ԫ�أ�front(), back()" << endl;
	cout << "\tl.front() = " << l.front() << endl;
	cout << "\tl.back(0 = " << l.back() << endl;
	cout << endl;



	// ����Ԫ��insert();
	//		iterator insert(const_iterator position, const T& x);
	cout << "\t����Ԫ��insert()" << endl;
	list<int> l1(3, 0);
	dispList(l1);
	cout << "\tl1.insert(l1.begin(),11);" << endl;
	l1.insert(l1.begin(), 88);
	dispList(l1);



	//		iterator insert(const_iterator position, size_type n, const T& x);
	list<int>::iterator iter = l1.begin();
	iter++;
	l1.insert(iter, 3, 77);
	cout << "\tl1.insert(iter,3,77);" << endl;
	dispList(l1);



	//		template <class InputIterator>
	//    		iterator insert (const_iterator position, InputIterator first,
	// 		                    InputIterator last);
	//		iterator insert(const_iterator position, initializer_list<T>);
}