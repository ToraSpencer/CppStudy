#include <iostream>
#include <string>
#include <typeinfo>


#include <cstdio>

using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// ֪ʶ��
/*
			const
					constָ�롪�����㡢�ײ�const
								һ���ж���const���βκ�û�����ĺ����޷����֡� Record lookup(Phone* const)�� Record lookup(Phone*)�޷����֡�
								�෴���Ƿ���ĳ���ײ�const�βο������֡� Record lookup(Account*)�� Record lookup(const Account*)�������֡�

					const�ͺ�ĶԱȡ���const�����Ⱥ����ȫ����Ϊconst���������ʱ�����д����顣

					������ʹ��const�β�
								ֵ���ݵ��ββ���Ҫconst����
								���á�ָ���β�ʹ��const���Σ����Ա����������ݲ��ᱻ�����޸ġ�

					����ǰ��const����
								��ͨ�������෽��ǰ�����Լ�const���Σ���ʾ��������ֵ��const�������޸ġ�
								
					�������const����
								ֻ�з�static���෽�����Լ�const���Σ���const���ں���֮��
								��ʾ���෽����thisָ����constָ�룬���ܸ������Ա��ֵ��
		
			static
					Դ�ļ���static����Դ�ļ��ڵ�static����ֻ���ڱ�Դ�ļ��ڱ����ʺ͵��á�
					������static����������static�����൱��һ��ȫ�ֱ�����
					����static�������ڵ�static��Ա�����������������У�������ĳһ��������Ҫ�������ʼ�����ھ�̬�洢���С�
										 static�෽��ֻ�ܷ���static��Ա������static�෽������Ϊ������ʹ��thisָ�롣



			auto
					C��C++�ж���auto�����������кܴ�Ĳ�ͬ��
					
			extern 
			explicit

		C++�������C�����ӵĹؼ��֣�
				using 			 
						1. �����ռ�,�����ڵ����ֵ�ʹ��
									(a) using namespace �����ռ���;
									(b) using �����ռ���::����;
						2. ʹ�����ͱ�����
									(a) ��ʶ�� attr(��ѡ) = ���ͱ�ʶ ;
									(b)	template < ģ���β��б� >
 											using ��ʶ�� attr(��ѡ) = ���ͱ�ʶ ;

 											
				auto
				
				decltype
						decltype(f()) sum = x;			// �ƶ�sum�������Ǻ���f�ķ������͡�
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
void set_fun_syntax_keyword(void);
void start_syntax_keyword(void);



static int foo1(void) ;
static int foo2(void) ;
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
void set_fun_syntax_keyword(void)
{
	pfun[0] = test0;
}



void start_syntax_keyword(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: syntax_keyword**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0: test0: �ؼ���const" << endl;
		cout << "1: test1: �ؼ���static" <<endl;


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



static int foo1(void) 
{
    int num = 1;
    num++;
    return num;
}




static int foo2(void) 
{
    static int num = 1;		// �������ڵ�static����ʵ���Ͼ���ȫ�ֱ���������һ�κ�֮�����������Ч��
    num++;
    return num;
}




// test0: �ؼ���const
void test0(void) 
{
	int numi1 = 11;
	int numi2 = 22;
	int* pi1 = NULL;
	int* const cpi1 = &numi1;							// ��һ������const������ָ�뱾����һ��������cpi1������ָ������λ�á�
	const int* pci1 = &numi1;							// ��һ���ײ�const������ָ��ָ���������һ��������
																				//				������ͨ��pci1���޸���ָ���numi1��ֵ
																				//				���Ǹ�ָ�����ָ������λ�á�
	const int* const cpci1 = &numi1;			//	��һ���ǵײ�const���ڶ����Ƕ���const��ָ�뱾���ǳ������涨��ָ�������ҲӦ���ǳ�����		

	cout << "\n\n\n\n" << endl;
	cout << "test0: �ؼ���const" << endl;


	cout << "\t����/�ײ�const" << endl;
	// ����const��ָ�뱾����һ������ 
	cout << "\t\tint* const cpi1 = &numi1;	*cpci1 == " << *cpi1 << "��������const"<< endl;


	pi1 = const_cast<int*>(cpi1);							// ����ʹ��const_castȥ��cpi1��const���ԣ� pi1ָ���λ�ÿ����޸ģ�
	pi1 = &numi2;
	cout <<"\t\tpi1 = const_cast<int*>(cpi1); pi1 = &numi2; *pi1 == " << *pi1 << endl;


	// �ײ�const��ָ��ָ���������һ������
	cout << "\t\tconst int* pci1 = &numi1; *pci1 == " << *pci1<< "�����ײ�const"<< endl;
	pci1 = &numi2;												// �ײ�constָ�����ָ������λ�ã�
	cout << "\t\tpci1 = &numi2; *pci1 ==  " << *pci1 << endl;


	// ���㡢�ײ�const����ͬʱ���֡���ָ�뱾���ǳ�����ָ�������Ҳ�ǳ�����
	cout << "\t\tconst int* const cpci1 = &numi1; *cpci1 == " << *cpci1<< "�������㡢�ײ�const����ͬʱ����" << endl;
	cout << endl;

}




// test1: �ؼ���static
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: �ؼ���static" << endl;


	// ������static���������ڵ�static�����൱��һ��ȫ�ֱ�����
  for (int i = 0; i < 5; i++)
  {
      cout << "foo1 == " << foo1() << endl;
  }

  for (int i = 0; i < 5; i++)
  {
      cout << "foo2 == " << foo2() << endl;
  }
	




}



// test: const����
static void test2(void) 
{
	

}