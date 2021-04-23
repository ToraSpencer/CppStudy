#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
#include <limits>					// ����
#include <cmath>					// ���ݺ���
#include <fstream>					// �ļ��������
#include <cctype>					// �ַ�����
#include <ctime>       				// ���ں�ʱ�亯��
#include <cstdlib>					// ��׼��
#include <cstdio>       			// ��׼�������
#include <iomanip>					// �����������ʽ����	
#include <cstdarg> 					// ֧�ֱ䳤��������	
#include <cassert>					// ֧�ֶ���
 

// ��ʾ״̬��ö����
enum Status {
	SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW, RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED
};


// �궨��
#define DEFAULT_SIZE 1000			// ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000	// ȱʡ�����
#define MAX_ERROR_MESSAGE_LEN 100


// ��������inStream�������ո��Ʊ����ȡһ�ַ�
char GetChar(std::istream &inStream = std::cin);


class Error
{
private:
	char message[MAX_ERROR_MESSAGE_LEN];		// �쳣��Ϣ

public:
	Error(const char *mes = "һ�����쳣!");
	~Error(void) {};
	void Show() const;					// ��ʾ�쳣��Ϣ
};


// ����Ԫ��ֵ
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
{
	ElemType temp;		// ��ʱ����
						// ѭ����ֵʵ�ֽ���e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}


// ��ӡ����
template<class ElemType>
void Display(ElemType elem[], int n)
{
	for (int i = 0; i < n; i++)
	{	// ��ʾ����elem
		cout << elem[i] << "  ";
	}
	cout << endl;
}


// ��ӡ����Ԫ��
template <class ElemType>
void Write(const ElemType &e)
{
	cout << e << "  ";
}


// ģ����ĳ������
struct virtualModule
{
protected:
	virtual void test0() = 0;
	virtual void test1() = 0;
	virtual void test2() = 0;
	virtual void test3() = 0;
	virtual void test4() = 0;
	virtual void test5() = 0;
	virtual void test6() = 0;

public:
	static virtualModule* p_moduleIns;
	virtual ~virtualModule() = default;
	void run(unsigned testID);
};


// �½���ĳ������
struct virtualChap
{
public:
	virtualModule* pm;		// ��ǰ�鿴��ģ���ָ�룬��Ҫ��caller���Է��ʣ�
							//	to be optimized: ��ʵ���淶����������Ƴ���Ԫ��Ȼ����Ȼ����Ϊprotected��Ա
	static virtualChap* p_chapIns;
	virtual ~virtualChap();

	virtual void showModuleList() = 0;
	virtual bool selectModule(const int molEnum) = 0;
	virtual void runTest(const unsigned testID);
	bool isNullModule() const;
};



// ������baseTypePrinter������ӡ�������ͱ���
class baseTypePrinter
{
public:
	baseTypePrinter() = default;

	template<typename T>
	void operator()(const T& arg)
	{
		std::cout << arg << "\t";
	}

};



// ������pairPrinter�������������Ǵ�ӡpair����
class pairPrinter
{
private:
	unsigned int count = 0;

public:
	pairPrinter() = default;

	template<typename T1, typename T2>
	void operator()(const std::pair<T1, T2>& p)
	{
		std::cout << "\t(" << p.first << ", " << p.second << ")";
		this->count++;
	}

	unsigned int getCount(void)
	{
		return this->count;
	}

};


// ���뺯���ӻ���ָ�����stl����
template<typename T, typename F>
void traverseSTL(T& con, F f)
{
	std::for_each(con.begin(), con.end(), f);
	std::cout << std::endl;
}


// �������
template<typename T, typename F>
void revTraverseSTL(T& con, F f)
{
	std::for_each(con.rbegin(), con.rend(), f);
	std::cout << std::endl;
}


// lambda������ӡstd::cout֧�ֵ����ͱ�����
template <typename T>
auto disp = [](const T& arg)
{
	std::cout << arg << ", ";
};


// �Զ���pointer-like�ַ�����
struct myString
{
private:
	const char*	pc;
public:
	myString() = delete;
	myString(const char* pc0) :pc(pc0) {}
	myString(const myString& str);	// Ӧ���Լ�ʵ�ֿ������캯�������ظ�ֵ���������ʵ�����������ϵͳ����ǳ�����Ŀ������캯����
	

	
	
	const char* c_str() const
	{
		return this->pc;
	}
};



 





