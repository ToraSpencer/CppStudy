#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>


using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// sizeof()�����������һ�������������ռ���ڴ��ֽ�����	
/*
    sizeof(����);           ��sizeof(num)
    sizeof(������);         ��sizeof(int)
			 
*/




// ��Ŀ�������b ? x : y;   
/*
    ��������b����bֵΪtrue���������ʽx�������ؽ����
        ��bֵΪfalse���������ʽy�������ؼ�������
			 
*/



/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_specialOperator(void);
void start_syntax_specialOperator(void);

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
void set_fun_syntax_specialOperator(void) 
{
	pfun[0] = test0;
    pfun[1] = test1;
    pfun[2] = test2;
}



void start_syntax_specialOperator(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: syntax_��������������**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0: test0: sizeof()�����" << endl;
        cout << "1: test1: ��Ŀ�����" << endl;
        cout << "2: test2: " << endl;


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

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}


// test0: sizeof()�����
static void test0(void)
{
    cout << "\n\n\n\n" << endl;
	cout << "test0: sizeof()�����" << endl;

    int arri[5];
    cout << "\t����arriռ�ڴ棺sizeof(arri) == " << sizeof(arri) << endl;
    cout << "\t����arri��Ԫ������sizeof(arri)/sizeof(int) == " << sizeof(arri)/sizeof(int) << endl;

    // ����ָ��ռ�ڴ涼��һ���ģ��ɲ���ϵͳλ��������64λϵͳ��ָ��ռ8�ֽڣ��������ֳ���
    int* pi;
    double* pd;
    void* pv;
    cout << "\t" << sizeof(pi) << endl;
    cout << "\t" << sizeof(pd) << endl;
    cout << "\t" << sizeof(pv) << endl;

}



// test1: ��Ŀ�����
static void test1(void)
{
    cout << "\n\n\n\n" << endl;
	cout << "test1: ��Ŀ�����" << endl;


    // Ӧ�����ӡ��������ж�������������������ż����
    int inputValid = 0;
    int num;
    string str;

    cout << "������һ��������" << endl;
    while(0 == inputValid)
    {
        setbuf(stdin, NULL);
        inputValid = scanf("%d", &num);
        
        if(0 == inputValid)
        {
            cout << "���벻�Ϸ������������롣" << endl;
            setbuf(stdin, NULL);
        }
    }
    str = (num%2 == 0) ? "ż��": "����";
    cout << "�����������" << str << endl;
     





}


static void test2(void)
{


}