#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>
#include <stack>					// stack����������
#include <queue>					// queue, priority_queue����������

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// STL����������������stack, queue, priority_queue,
/*
	 �����������ã�
				ʹ��һ���µĽӿڣ����ǵ�ԭ�г���Ľӿڡ�
				����������ģ��




**
*/



// stack����ջģ����
/*
	Ĭ��������deque

	��������������vector, list

	��Ա���ݣ�
			container_type			Container										�ײ���������
			value_type				Container::value_type
			size_type					Container::size_type
			reference					Container::reference
			const_reference		Container::const_reference

	��Ա������
			stack<int> s;									// ʹ��Ĭ�ϵ�����dequeʵ��ջ����s��
			stack<int, vector<int> > stk;  		// ʹ������vectorʵ��ջ����stk!!!ע��ո�

			operator=										// ��ֵ���������

			void push(const T& el);   				// ��ջ��ѹ��β�ˣ�����Ԫ��el
			void pop();    									// ɾ��ջ����β�ˣ�Ԫ�أ�����������ֵ
			��C++11��emplace							// ��ջ��ԭλ����Ԫ��
			const T& top();    							// ����ջ����β�ˣ�Ԫ�ص�ֵ������ɾ����Ԫ��

			bool empty()									// ���ײ�������Ƿ�Ϊ��	
			size_type size()									// �������ɵ�Ԫ����
			void swap(stack& s)						// ������������		


*/


// queue��������ģ����
/*
	Ĭ��������deque
	��������������list
	��Ա���ݣ�
			container_type			Container										�ײ���������
			value_type				Container::value_type
			size_type					Container::size_type
			reference					Container::reference
			const_reference		Container::const_reference


	��Ա������
			queue<T>
			queue<T,container<T>>

			operator=										// ��ֵ���������

			void push(const T& el);					// ��Ӳ�������β�˼���Ԫ�ء�
			void pop();										// ���Ӳ��������׶�ɾ��Ԫ�ء�

			��C++11��emplace
		  
			T& front();										// �����ײ�Ԫ��
			T& back();										// ����β��Ԫ��
			
			bool empty()									// ���ײ�������Ƿ�Ϊ��
			size_type size()									// �������ɵ�Ԫ����
			void swap(queue& q)						// ������������


*/



// priority_queue�������ȼ�������ģ�塪��Ԫ���������еĶ���
/*


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
void set_fun_STL_adapter(void);
void start_STL_adapter(void);

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
void set_fun_STL_adapter(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
}



void start_STL_adapter(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL_adapter**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  stack��ģ��ĳ�Ա" << endl;
		cout << "1. test1��queue��ģ��ĳ�Ա  " << endl;


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



// test0:  stack��ģ��ĳ�Ա
static void test0(void) 
{
	stack<char> stc1;										// Ĭ���������deque����stack
	stack<int, vector<int>> sti1;						// ָ��ʹ��vector������stack
	stack<float, list<float>> stf1;


	cout << "\n\n\n\n" << endl;
	cout << "test0:  stack��ģ��ĳ�Ա" << endl;

	stc1.push('a');																			// ѹջ����
	stc1.push('b');
	stc1.push('c');
	stc1.push('d');
	stc1.push('e');
 

	cout << "\tstc1.empty() = " << stc1.empty() << endl;				// �鿴�Ƿ�Ϊ��
	cout << "\tstc1.size() = " << stc1.size() << endl;						// �鿴��ǰԪ����

	stc1.pop();																					// ��ջ����
	cout << "\tstc1.top() = " << stc1.top() << endl;						// ����ջ��Ԫ��
	cout << endl;
	
}


// test1��queue��ģ��ĳ�Ա 
static void test1(void)
{
	queue<int> qi1;
	queue<double, list<double>> qd1;

	cout << "\n\n\n\n" << endl;
	cout << "test1��queue��ģ��ĳ�Ա " << endl;

	qi1.push(0);						
	qi1.push(1);
	qi1.push(2);

	cout << "\tqi1.front() = " << qi1.front() << endl;
	cout << "\tqi1.back() = " << qi1.back() << endl;

	


}