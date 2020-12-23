#include <cstdio>
#include <string>
#include <iostream>
#include <vector>						//vector��ģ����ͷ�ļ�<vector>��

#include <cstdio>


using namespace std;




/*
					while(){}
					do()	while{};
					forѭ��
					��C11����Χforѭ��
					switch case

			(C++11)��Χforѭ����
					��ʽ��for(Ԫ������ elem:  c) {...}					// c����������


*/





/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
template <typename T, size_t S>
class MyArray														// �Զ�������������ģ�壬�����Ͳ���T���ͷ����Ͳ���S
{
public:
	T& operator[](size_t i);									// �����±������
	const T& operator[](size_t i) const;					// �����±��������const�汾�������ء�
																			//				��Ϊ��ҪMyArray��const����ʹ���±������ʱ�����ص�Ԫ������Ҳ��const

	T* begin(void);													// ��ȡ��ʼ��������
	const T* begin(void)	const;							// ��ȡ��ʼ��������const�汾��������
																			//				��Ϊ��ҪMyArray��const����ʹ��begin����ʱ�����صĵ�����Ҳ��const��
																			//				ע�������ǵײ�const��������ָ��������ǳ����������������ǳ�����ָ���λ�ÿ��Ըı䡣
	T* end(void);													// ��ȡβ���������
	const T* end(void) const;



private:
	//	��Ա���ݣ�
	T arr[S];													// Ԫ������ΪT�� ����ΪS�����顣

};



/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;


/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_statement(void);
void start_syntax_statement(void);


static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);


/***************************************************************************
***************************************************************************/
// extern����
template <typename T>
extern void traverse_vector(const vector<T>&, void(*pVisit)(const T&));

extern void traverse_pfun(void);



/***************************************************************************
***************************************************************************/
// �Զ������ʵ��
template <typename T, size_t S>
T&  MyArray<T,S>:: operator[](size_t i) 
{
	return this->arr[i];												// ���������쳣���������±�Խ���ʱ���׳��쳣��
}


template <typename T, size_t S>
const T& MyArray<T, S>:: operator[](size_t i) const
{
	return const_cast<MyArray&>(*this)[i];				// ��������
}


template <typename T, size_t S>
T* MyArray<T, S>:: begin(void) 
{
	return arr;
}


template <typename T, size_t S>
const T* MyArray<T, S>::begin(void)	const
{
	return const_cast<MyArray*>(this)->begin();
}
 			

template <typename T, size_t S>
T* MyArray<T, S>::end(void)
{
	return (arr + S);
}


template <typename T, size_t S>
const T* MyArray<T, S>::end(void)	const
{
	return const_cast<MyArray*>(this)->end();			// end()ָ��ת�ͳ�constָ��
}


/***************************************************************************
***************************************************************************/
// ��������
void set_fun_syntax_statement(void) 
{
	pfun[0] = test0;
}



void start_syntax_statement(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: STL_linear_container**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: ��C++11����Χforѭ�����" << endl;


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


// test0: ��C++11����Χforѭ�����
static void test0(void)
{
	// ��Χforѭ����������ʹ�������ĵ�������ʵ�֣�ֻҪһ������������begin()��end()�������Ϳ���ʹ�÷�Χforѭ����
	vector<int> vi1 = { 0,1,2,3,4,5 };
	int count = 0;
	char str[20];
	MyArray<float, 5> af1;

	cout << "test0: ��C++11����Χforѭ�����" << endl;


	// ʹ�÷�Χforѭ����������ӡvector�����е�Ԫ�أ�
	cout << "\tʹ�÷�Χforѭ����������ӡvector�����е�Ԫ�أ�for(const int& elem: vi1){...}" << endl;
	for (const int& elem : vi1)											// �������Ե�����auto elem�����������е�Ԫ�ء�
	{
		sprintf(str, "\tvi1[%d] == ", count++);
		cout << str << elem << endl;
	}
	cout << endl;


	// ʹ�÷�Χforѭ��������ֵ�Զ�������MyArray�е�Ԫ�أ���������ӡ��
	cout << "\tʹ�÷�Χforѭ��������ֵ�Զ�������MyArray�е�Ԫ�أ���������ӡ��" << endl;
	count = 0;
	for (auto& e1 : af1)
	{
		e1 = float(count--);
	}

	auto const& af2 = af1;
	count = 0;

	for (auto& e2 : af2)
	{
		sprintf(str, "\taf2[%d] == ", count++);
		cout << str << e2 << endl;
	}
	cout << endl;


}