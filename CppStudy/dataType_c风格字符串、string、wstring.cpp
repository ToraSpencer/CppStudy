#include <cstdio>
#include <cstring>


#include <string>
#include <iostream>
#include <vector>						//vector��ģ����ͷ�ļ�<vector>��
#include <algorithm>
#include <iterator>


#include <cstdio>

#include "example.h"

using namespace std;



// ֪ʶ��
/*
		string
			�Ƿ�װ����Ŀɱ䳤�ַ�����
			��STL����������

		wstring
			��װ����wchar_t�������ݣ��ǿ��ַ���
			���������ASCII�ַ���Ҫ������Unicode���룬���ģ����ģ����ġ�����
			wstring��<string>ͷ�ļ��ж��壬���Ӧ��������ǰ�����L


		string, char*, const char*�ıȽ�


		C����ַ����ĳ���API����
					strcpy(), strncpy()
					strcmp()
					strcat();
					
					
		�ַ���ƥ��
					��һ������ַ���T������ĳ���ַ���P�����г���λ�á�
					C++�����ֳɵ����ӿ���ʹ�á�������string���find(), find_first_of(), find_last_of()������


		����ȫ�ĺ���
					strcpy(), strncpy()				���߶�����ȫ������strncpy��һЩ���Ժ��ٿ��Ǹ���ȫ�ķ�����
						
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
void set_fun_dataType_string(void);
void start_dataType_string(void);


static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);


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
void set_fun_dataType_string(void) 
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_dataType_string(void) 
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: dataType_string**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: C++�е��ַ�����string���󣩣�C�е��ַ�����char���飩���Լ�C/C++�е��ַ�����������" << endl;
		cout << "1. test1: string��Ľӿ�" << endl;
		cout << "2: test2: string������������" << endl;
		cout << "3: test3: C�����е��ַ�����API" << endl;
		cout << "4: test4: �ַ�����" << endl;
		cout << "5: test5: �����㷨ʵ��" << endl;
		

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



//	test0: C++�е��ַ�����string���󣩣�C�е��ַ�����char���飩���Լ�C/C++�е��ַ�����������
static void test0(void) 
{
	char Cstr1[] = "this is a C type string";				// ʹ���ַ�����������ʼ��char���顪����C�����ַ���
	char Cstr2[] = "hahahahaha";
	char Cstr3[] = "hehehehehehe";
	const char* Cstr4 = NULL;
	string str1 = "this is a C++ string object";		// ʹ���ַ�����������ʼ��string���󡪡�C++�е��ַ���
	string str2 = Cstr2;														// ʹ��C�����ַ�����C++���ַ��������ʼ����



	// C����ַ�����string���󶼿���ʹ���ַ�����������ʼ����������ʹ��cout��ӡ
	cout << "\t C���C++���ַ���������ʹ���ַ�����������ʼ����������ʹ��cout��ӡ��" << endl;
	cout << "\tCstr1 == " << Cstr1 << endl;
	cout << "\tstr1 == " << str1 << endl;
	cout << endl;
	cout << "\t C++�ַ����������ʹ��C����ַ�������ʼ����" << endl;
	cout << "\tstring str2 = Cstr2;	str2 == " << str2 << endl;
	cout << endl;


	// C�����ַ�����ʼ���Ժ�Ͳ�����Ϊһ�����屻��ֵ��ֻ������ַ��ظ�д������ʹ��strcpy()�Ⱥ���
	



	//	C�����ַ������Ը�string����ֵ
	str2 = Cstr3;															// ʹ��C�����ַ�����C++���ַ�������ֵ��
	cout << "" << endl;
	cout << "\tC�����ַ������Ը�C++���ַ�������ֵ:" << endl;
	cout << "\tstr2 = Cstr3; str2 == " << str2 << endl;


	// string��c_str()�����������װ��c����ַ���
	Cstr4 = str2.c_str();									// ע�ⷵ�ص�c����ַ�����const�ġ�
	cout << "Cstr4 == " << Cstr4 << endl;


	// string������ַ����������ıȽ�
	str1 = "hahaha";
	//		������ͬ��string������ַ���������==��������true���������ڼ��顣
	cout << "(int)(str1 == \"hahaha\") == "<<(int)(str1 == "hahaha") << endl;

}






// test1: string���API
static void test1(void)
{
	cout << "\n\n\n\n" << endl;
    cout << "test1: string��Ľӿ�" << endl;

	string str1;					// Ĭ�Ϲ��캯������Ŀ�string
	string str2(9,'a');				// ���ɸ���ͬ�ַ������string
	string str3("hello world");		// �ַ��������������string


	// ���ʵ���Ԫ�صĽӿڣ�operator[], at(), front(), back()
	cout << "\t���ʵ���Ԫ�صĽӿڣ�operator[], at(), front(), back():" << endl;
	cout << "\tstr2[2] == " << str2[2] << endl;
	try
	{
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "\tstr3.front() == "<< str3.front() << endl;
	cout << "\tstr3.back() == "<< str3.back() << endl;
	cout << endl << endl;



	// �������Ԫ�صĽӿڣ�insert, replace, substr, append
	str1 = str2.substr(2,4);
	str2.replace(3, 2, "bcbcbc");
	str3.insert(6, "new ");			// �ڵ�6���ַ�������룬����������ָ�ӡ���һ����ʼ��
	cout << "\t�������Ԫ�صĽӿڣ�insert, replace, sub_str, append, clear" << endl;
	cout << "\tstr1 == "<< str1 << endl;
	cout << "\tstr2 == "<< str2 << endl;
	cout << "\tstr3 == "<< str3 << endl;
	str1.clear();
	cout << "str1.clear(); str1 == " << str1 << endl;
	cout << endl << endl;



	// string����֮��Ĳ�����operator+=
	str1 += str2;
	str1 += str3;
	cout << "\tstring����֮��Ĳ�����operator+=" << endl;
	cout << "\tstr1 == " << str1 << endl;
	cout << endl << endl;

	
	// getline()



	// �������ӿڣ�begin, cbegin(C++11), rbegin(C++11), crbegin(C++11)...
	cout << "\tʹ�÷���������������ӡ�ַ�����"<< endl;
	for_each(str3.rbegin(), str3.rend(), printElem<char>);





}




// test2: string������������
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
  cout << "test2: string������������" << endl;

	// std::getline�����������������ж�ȡ�������string����
	//		ע��������cin������string������Ϊ�����ո���жϡ�
	string answer, number;
	cout << "Jun Lei: are you ok?" <<endl;
	setbuf(stdin, NULL);
	getline(cin, answer);
	cout << "Me: " << answer << endl;
	cout << "Jun Lei: whatever, have a nice day!" << endl;
	//		getline()���������ַ�����ֹͣ��־��
	cout << "��������룬�Ծ��ż�������" << endl;
	setbuf(stdin, NULL);
	getline(cin, number, '#');
	cout << "������ĺ����ǣ�" << number << endl;
}



 
// test3: C�����е��ַ�����API
static void test3(void)
{
		// �ַ��������������puts, fgets, fputs 
		// ��������strcpy
		// ���ӡ���strcat
		// �Ƚ�strcmp

		const char* str1 = "\tthis is a string literal";
		char str2[] = "\tthis is a copy of a string literal";
		char str3[100] = { '\0' };

		printf("\n\n\n\n");
		printf("test3: C�����е��ַ�����API\0");


		// int puts(const char* str)������ӡ�ַ�����
		puts(str1);
		puts(str2);
		printf("\n\n");


		// char *fgets(char* str, int count, FILE* stream)�����Ӹ������ж�ȡ���������޶����ַ����洢�ڸ����ַ������У�
		printf("\tPlease input a string: ");
		setbuf(stdin, NULL);
		fgets(str3, 20, stdin);
		printf("\t%s", str3);
		printf("\n\n");


		// fputs��������NULL��β���ַ���str��ÿ���ַ�д�뵽�����stream�С�
		puts("\tPlease enter a string, and it will be printed immediately. If you want to quite this mode, input q:");
		while ((fgets(str3, 100, stdin)) && (*str3 != 'q'))
		{
			printf("\t");
			fputs(str3, stdout);
		}
		puts("\tTyping and printing mode exited.");




		char string1[50] = "hello ";
		char string2[] = "world ";
		char string3[20];

		// strcpy()�����������ַ���������ȫ������ʹ��strncpy()
		/*
			 char *strcpy( char *dest, 					Ŀ���ַ���
			 						 const char *src				Դ�ַ���
			 					)
		*/

		// strncpy()�������������ַ���
		/*
			char *strncpy( char *dest,				Ŀ���ַ���
									const char *src, 			Դ�ַ�����
									size_t n							��ิ�Ƶ��ַ�������src����С��nʱ��destʣ�ಿ���ÿ��ֽ���䡣
									) 

		
		*/
		strcpy(string3, string1);	





		//			int strcmp(str1, str2)������ȷ���0��������ȣ��Ƚϵ�һ������ȵ��ַ���ASCII�룬��<�ҵĻ����ظ���
		cout << "strcmp(string1, string3) == " << strcmp(string1, string3) << endl;
		cout << "strcmp(\"abc\", \"abd\") == " << strcmp("abc", "abd") << endl;

		strcat(string1, string3);			// ɾ��string1ĩβ��'\0'����string�����ݸ��Ƶ�������
		strcat(string1, string2);			// һ��ʼ��Ҫ��֤string1���ٵĿռ��㹻�󣬿����ݵ���string2������
		cout << string1 << endl;


		// strcpy()��memcpy()�ıȽ�
		fill(string1, string1+49, '\0');		
		fill(string3, string3+19, '\0');
		strcpy(string1, "hahaha\0wawawawa");								// strcpy()����'\0'��ֹͣ						
		memcpy(string3, "hahaha\0wawawawa", 16);					// memcpy()һ���´���趨���ֽ�����
		
		printf("%s\n", string1);						
		printf("%s\n", string3);
		printf("%s\n", string3+7);


}
 


// test4: �ַ�����
static void test4(void)
{
	printf("\n\n\n\n");
	printf("test4: �ַ�����\n");

	// �������ġ�Ӣ�ġ����ֲ�ѯ����루����ַ�ΪASCII�룬ȫ���ַ�ΪGB2312��
	//		1. ��������ѯ���ַ������������ַ������ָ�롣
	char str[] = "�ǵз��ط�kju421";
	unsigned char* puc = (unsigned char*)str;


	//		2. ��ӡ����ѯ���ַ�����
	printf("\tԭ�ַ�����str == %s\n", str);


	//		3. ʹ��unsigned char*ָ����ʮ��������������ʽ�����ȡ�ַ����е����ݣ�
	printf("\tʹ��unsigned char*ָ����ʮ��������������ʽ�����ȡ�ַ����е����ݣ�\n");
	do
	{
		printf("\t0x%x,", *puc);
		puc++;

	} while (*puc != '\0');
	printf("\n");



	//	����ASCII���GB2312�룬������ȫ���ַ������ַ��� 
	//		1. �����յ��ַ�����������д�ַ����ݵ�unsigned charָ��
	char str2[100] = { '\0' };
 

	//		 2. д��ASCII������
	puc = (unsigned char*)str2;
	*puc = 33;						// !
	*(puc + 1) = 34;				// "
	*(puc + 2) = 48;				// 0
	*(puc + 3) = 49;				// 1
	*(puc + 4) = 65;				// A
	*(puc + 5) = 66;				// B
	*(puc + 6) = 97;				// a
	*(puc + 7) = 98;				// b
	*(puc + 8) = '\0';
	printf("\t��unsigned charָ������ֽ�д��ASCII���ݵ��ַ����У�ÿ���ֽ����λΪ0��\n");
	printf("\tstr == %s\n", str2);


	//		3. д��GB2312������
	*puc = 0xb0;						 
	*(puc + 1) = 0xa1;			 
	*(puc + 2) = 0xb0;				 
	*(puc + 3) = 0xa2;				 
	*(puc + 4) = 0xb0;			 
	*(puc + 5) = 0xa3;				 
	*(puc + 6) = 0xb0;				 
	*(puc + 7) = 0xa4;			 
	*(puc + 8) = '\0';
	printf("\t��unsigned charָ������ֽ�д��GB2312���ݵ��ַ����У�ÿ���ֽ����λΪ1��\n");
	printf("\tstr == %s\n", str2);

}



// test5: �����㷨C++ʵ��
static void test5(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test5: �����㷨C++ʵ��" << endl;

	// �ַ���ƥ�䡪����һ������ַ���T������ĳ���ַ���P�����г���λ�á�
	/*
	*/

	// C++�е�����ʵ���ַ���ƥ�䣺
	string str1 = "asdfajiuiuwww.baidu.comasdfuoiup";

	//			string���find()�������������ַ����е��ַ����Ӵ�
	//					size_type����string��vector��������ͣ��Ǳ�ʾ�����������޷�����������
	string::size_type num = str1.find("baidu", 0);							// �ڶ���������������ʼ��λ�á�
	if (num == string::npos)															// ����������ʱ�򷵻�npos��һ�����-1
	{
		cout << "û���ҵ�ģ���ַ���" << endl;
	}
	else
	{ 
		cout << "�ҵ�ģ���ַ�����λ����" << num << endl;
	}


	//			string���find_first_of()��find_last_of()�������������ַ����Ӵ���һ�Ρ����һ�γ��ֵ�λ��
	string::size_type num1 = str1.find_first_of("asd");
	string::size_type num2 = str1.find_last_of("asd");
	if (num1 != num2)			
	{
		cout << "�Ӵ�asd�����˲�ֹһ��" << endl;				// ���������ַ������ж��Ӵ���Ŀ���ַ����г��ֵĴ���
	}


}



// test: ���ַ�wstring��
static void test6(void)
{
	// wstring��<string>ͷ�ļ��ж��壬���Ӧ��������ǰ�����L
	wstring str = L"abcde";
	cout << str.size() << endl;


	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;

	cout << static_cast<unsigned char>(str[1]) << endl;

}