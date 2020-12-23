#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159

//	֪ʶ��
/*	
 
		C����ǿ������ת��
					(T)arg;

			
		������ʽǿ������ת����
					static_cast 		
								����ִ��������������֮���ת����
								����ִ���м̳й�ϵ��ָ�롢���õ�ת�������������֮���ת�����黹����dynamic_cast����ȫ��
								

					dynamic_cast 		
								����ִ���м̳й�ϵ��������ָ�롢���õ�ת����
								ת��ǰ�����Ͱ�ȫ��飬�������ȫ�Ļ���ת��ʧ�ܣ�����NULLָ�롣
								�������͵�ʱ��һ��Ҫʹ�ã������ָ��/����ת��Ϊ������ָ��/���ã���ʱ�����׷�����ȫ���⡣
								

					const_cast 
								����ȥ�������������const���ԣ�һ�㲻��ʹ�á�

					reinterpret_cast 
								������C����ǿ������ת��������ȫ��


	
		���Ͱ�ȫת����
					����ת���ɸ����ǰ�ȫ�ģ�����ת���������ǲ���ȫ�ġ�
					�������Ϊ�������Ϣ�Ƕ��ڸ���ģ�����ת���ɸ���ʱ�����˶���һЩ��Ϣ�����Ǹ���ת��������Ļ���������Ϣ�ն����ǲ���ȫ�ġ� 

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
void set_fun_syntax_type_conversion(void);
void start_syntax_type_conversion(void);

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


class Pet 
{
    public: virtual ~Pet() {} 
};


class Tortoise : public Pet {};


class Rabbit : public Pet {};




/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_type_conversion(void) 
{
	pfun[0] = test0;
}



void start_syntax_type_conversion(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: syntax_type_conversoin_template**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0: test0: const_cast" << endl;


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



// test0: const_cast
static void test0(void)
{
	int  numi1 = 5;
	const int* pci1 = NULL;
	int* pi1 = NULL;

	cout << "test0: const_cast" << endl;

	pci1 = &numi1;											 			// constָ��pci1ָ��numi1���ǵײ�const��������ͨ��pci1���޸�numi1��ֵ��
	pi1 = const_cast<int*>(pci1);						 	 // ʹ��pci1��pi1��ֵ������ʹ��const_cast�Ƴ���const���ԡ�


	*pi1 = 6;
	cout << "\tpci1 = &numi1; pi1 = const_cast<int*>(pci1);	 *pi1 = 6; " << endl;
	cout <<"\tnumi1 == " << numi1 << endl;

}


// test1: ʹ��dynamic_cast()ʵ����������(downcast)
static void test1(void)
{
	Pet* pet = new Rabbit;							// ָ�����Ӷ����petָ�롣
	
	Tortoise* tortoise = dynamic_cast<Tortoise*>(pet);	// Petָ����ͼ��������ΪTortoiseָ�룬��Ӧ��ʧ�ܵ�
	Rabbit* rabbit = dynamic_cast<Rabbit*>(pet);		// Petָ��ָ����������ΪRabbitָ�룬��Ӧ�ǳɹ��ģ���ΪPetָ��ԭ��ָ��ľ���Rabbit����

	
	if (tortoise == NULL)					// ת��ʧ��dynamic_cast���᷵��NULLָ�롣
	{
			printf("Petָ����������ΪTortoiseָ��ʧ��\n");
	}
	else
	{
			printf("Petָ����������ΪTortoiseָ��ɹ�\n");
	}
	
	if (rabbit == NULL)
	{
			printf("Petָ����������ΪRabbitָ��ʧ��\n");
	}
	else
	{
			printf("Petָ����������ΪRabbitָ��ɹ�\n");
	}



}
