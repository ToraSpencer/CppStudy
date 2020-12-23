#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>				// �ַ�����ͷ�ļ�
//#include <syncstream>				// C++20��
#include <iomanip>
#include <streambuf>
#include <string>
#include <typeinfo>



#include <cstdio>




#ifdef linux
#include <cstrubg>				// ��Ҫʹ��stderror()����
#endif



using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// ֪ʶ��
/*
	���õĸ�ʽ�����ݷ�
			setiosflags()			ʹ�ö���ö�ٳ������趨�����ʽ��
			setw()					���ÿ��
			setprecision()			���ø��������ȡ�
			hex						��ʮ��������ʽ�������
			fixed					����ͨС����ʽ���������
			scientific				�Կ�ѧ��������ʽ���������
			left					����룬���ڿ�Ȳ���ʱ������ַ���ӵ��ұߡ�Ĭ���������Ҷ��롣



	C++����Ҫ�ļ���������
			cin��������istream��
							�ӱ�׼�����ȡ���ݡ�
							
			cout��������ostream��
					�ӱ�׼���д�����ݡ�
					
			cerr��������ostream��
					����������������Ϣ��д�뵽��׼����
					
			clog��������ostream��
					������cerr�������л��壬��������ʱ�������


	C����Ҫ�ļ���������
			stdin
			stdout
			stderr


	C��IO��صĺ���
			scanf()					�ӱ�׼����stdin�����̣���ȡ��ʽ����������
			printf()				���ݸ�ʽ���������׼���stdout����Ļ���ϡ�
			fprintf()				���ݸ�ʽ�����뵽�������С�
			strerror()			���մ���Ų����ڲ�����������������һ��ָ�������Ϣ�ַ�����ָ�롣���ɵĴ����ַ���ȡ���ڿ���ƽ̨�ͱ�������


	C++IO���͵��ص�
			���󲻿��Ը�ֵ����ֵ

			�����ܴ���������

			�����βκͷ��ص�һ�㶼�������͵����ã������Ƕ��󡣶����Ƿ�const�����ã���Ϊ��дһ���������ı���״̬��
						���͵����Ӿ����ڶ�������/���������>>/<<������������ص�ʱ�򣬷������������á�
						������	istream& operator>>(istream& is, Complex& cc);	



	������
				ÿ�����������������һ����������
				�����������ã���������д�����ݡ�
				��������ᵼ�»�����ˢ�£�
						1. ��������������
						2. ����������
						3. ʹ��endl��flush�Ȳ��ݷ���ˢ�¡�
				������Ҫ�Ĳ��ݷ�
						endl
						ends
						flush
						unitbuf


	cin�������Ҫ������
				cin.get() 						//һ��ֻ�ܶ�ȡһ���ַ�
				cin.get(һ������) 				//��һ���ַ�
				cin.get(��������) 				//���Զ��ַ���
				cin.getline()					// ��cin�����ж�һ�У����뵽string�����С�
				cin.ignore()
				cin.putback()


	fstream��ļ�����Ҫ����
				���ֹ��캯��
								fstream(str);					// str���ļ�·��
								fstream(str, mode);		// mode�Ǵ�ģʽ
											in	�Զ��ķ�ʽ��
											out	��д�ķ�ʽ��
											app	ÿ��д����ǰ����λ���ļ�ĩβ
											ate	���ļ���������λ���ļ�ĩβ
											trunc	�ض��ļ�
											binary	�Զ����Ʒ�ʽ����IO������
				open()
				close()
				is_open()
								����һ��boolֵ��˵���ļ��Ƿ�ɹ��򿪲�����δ�رա�

	string���ࡪ��stringstream
				������string�����������ݣ����߽���string������������ݡ�
				��Ҫ����
							str()
										����1				str(void)��������stringstream�����ڷ�װ��string����
										����2				str(str1)�������ַ���str1���󿽱�����ǰstringstream�����С�
										Ӧ��				����Ӧ��stringstream����������������ת��Ϊstring.


*/


// δ����ĺ���ԭ��
/*
		int scanf(const char *format, ...) 
		
		int printf(const char *format, ...)
		
		int fprintf(FILE *stream, const char *format, ...)
		
		char *strerror(int errnum)
					��ͷ�ļ�<string.h>�ж���





/*





// ������Բ���Ҫ��֪ʶ��
/*
		IO��ͷ�ļ���
					<iosfwd>			����IO�е����ǰ������
					<ios> 				std::ios_base �ࡢ	std::basic_ios ��ģ�塢 ���� typedef
					<istream> 		std::basic_istream ��ģ�塢 ���� typedef
					<ostream> 		std::basic_ostream�� std::basic_iostream ��ģ�塢	���� typedef
					<iostream>		������׼������
					<fstream> 		std::basic_fstream�� std::basic_ifstream��	std::basic_ofstream ��ģ�塢	����typedef
					<sstream> 		std::basic_stringstream��	std::basic_istringstream�� std::basic_ostringstream ��ģ�塢 ���� typedef
					<syncstream>	(C++20 ��) std::basic_osyncstream�� std::basic_syncbuf�� һЩtypedef
					<strstream> 	(C++98 ������)  
					<iomanip> 		����IO��ʽ�ĸ�������
					<streambuf> 		std::basic_streambuf ��ģ��
					<cstdio>			C ��������������


		IO���е��ࣺ
					ifstream
							��������<fstream>
							�����ļ�������

					ofstream
							��������<fstream>
							����ļ�������

					fstream
							��������<fstream>
							��������ļ�������
							���Զ�Ҳ����д
							
					��ļ̳й�ϵ��
							istream �� ifstream
									�� istringstream

					

*/



/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
struct myDate 
{
	int year, month, day;
};



/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_stdlib_IO_lib(void);
void start_stdlib_IO_lib(void);

template<typename T>
inline string toString(const T&);					// string������ʵ�ֵĽ���������ת��Ϊstring���͵ĺ���

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
void set_fun_stdlib_IO_lib(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;

}


void start_stdlib_IO_lib(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: stdlib_IO_lib**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: <iomanip>�еĲ��ݷ�(manipulator)�����������ʽ��" << endl;
		cout << "1. test1���ļ����ࡪ��ifstream, ofstream" << endl;
		cout << "2. test2: ʹ��cin��������������" << endl;
		cout << "3. test3��string��" << endl;
		cout << "4. test4: ʹ��scanf()�ķ���ֵ��������Ϸ�����" << endl;

			

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

		case 4:
			(*pfun[4])();

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}


template <typename T>
inline string toString(const T& arg)
{
	ostringstream os;
	os << arg;
	return os.str();							// string�����str()���������������װ���ַ�������
}




// test0: <iomanip>�еĲ��ݷ�(manipulator)�����������ʽ��
static void test0(void)
{
	double d1, d2, d3;
	d1 = 3.1415926;
	d2 = 232.2345;
	d3 = 90989.111;

	cout << "\n\n\n\n" << endl;
	cout << "test0: <iomanip>�еĲ��ݷ�(manipulator)�����������ʽ��" << endl;


	// setw()��cout.width()��������ָ������������Ŀ�ȣ����������Զ����ո�Ĭ���Ҷ��롣
	cout << setw(10) << d1 << endl;
	cout.width(10);								// ���һ�κ���趨��ʧЧ
	cout << d2 << endl;
	cout.width(10);
	cout << d3 << endl;
	cout << endl << endl;


	// setiosflags()��������ʹ�ö���ö�ٳ������趨�����ʽ��
	cout << "������ʽ����ios_base::left" << endl;
	cout << setiosflags(ios_base::left) << setw(20) << d1 << endl;			// ���������
	cout << setw(20)<< d2 << endl;
	cout << resetiosflags(ios_base::left) << setw(20) << d3 << endl;			// ����һ�κ�һֱ��Ч����Ҫ�ֶ�����
	cout << "����ǰ�����š���ios_base::showpos" << endl;
	cout << setiosflags(ios_base::showpos) << 1234 << endl;
	cout << resetiosflags(ios_base::showpos);							// �ֶ�������ʽ
	cout << endl << endl;


	// setprecision()�����������ø��������ȣ�
	cout << "setprecision()�����������ø��������ȣ�" << endl;
	cout << setprecision(1) << d2 << endl;					// ��ʱsetprecision()���õ�����Ч����λ����λ��������ʱĬ��ʹ�ÿ�ѧ������ios_base::scientific
	cout << setiosflags(ios_base::fixed) << setprecision(1) << d2 << endl;
																					// ָ�����������ios_base::fixed���ʱ��setprecision���õ���С�������λ����


}





// test1���ļ����ࡪ��ifstream, ofstream
static void test1(void)
{
	// �������롢����ļ������󡣳�����ļ��Ķ������룬д�����
	//		����������������������Գ�����ӽ������ģ���������׼�������д����cout <<..���ļ�������д������еı�����file>>arg
	//		���ϱ�̹淶��д����ֻд���·������д����·����
	//		ios_base::binary ָ����ģʽΪ�����ƣ���ָ���Ļ�Ĭ��Ϊ�ı�ģʽ
	//		ios_base::out�������ģʽ��û���ļ��򴴽��ļ������ļ�������ļ����ݡ�
	//		ios_base::app����׷��ģʽ����append��дʱ�����ԭ�����ݣ���ĩβ��ʼд��
	ofstream writeFile1("test1.xxx");					  
	ofstream writeFile2("test2.xxx", ios_base::out|ios_base::binary); 
	ofstream writeTextFile("myText.txt", ios_base::out);
	ifstream readFile1("test1.xxx");					
	ifstream readFile2("test2.xxx", ios_base::in|ios_base::binary);


	string str1 = "hello world";
	string str11;
	int inum1 = 2019;
	float fnum1 = 2019.4;
	char str2[100];

	cout << "\n\n\n\n" << endl;
	cout << "test1: ʹ��ifstream, ofstream��д�ļ�	" << endl;


	// д�������ļ����������ͱ�������������write()����д�룬Ҳ������������������
	writeFile1 << str1 << inum1 << fnum1 << endl;
	writeFile1.close();					// ����������֮��Ҫ�ر��ļ���


	// д�������ļ����Զ������ͱ�������write()����д�룬��ʹ�����ص�������������
	// write()����
	/*
		basic_ostream& write( const char_type* s,		��д������ݵ�ͷ��ָ�룬ǿתΪchar*
						  std::streamsize count			��д�������ֽ�����
							)
							
		����������д�Զ���ṹ��ʵ����������д����󣻣�����Ϊʲô��
	*/
	myDate dt = {2020, 3, 15};
	writeFile2.write(reinterpret_cast<char*>(&dt), sizeof(dt));
	writeFile2.close();

	
	// д�ı��ļ�
	writeTextFile<< str1<<inum1<<fnum1;
	

	


	// ���ļ���
	// getline()�����������������ж�ȡ���ݴ洢���ַ�����
	/*
		basic_istream& getline( char_type* s, 
							std::streamsize count 
							);
					
	*/
	readFile1.getline(str2,30);
	ifstream readTextFile("myText.txt", ios_base::in);
	readTextFile>>str11;		// ֱ���������������
	cout << str2 << endl;
	readFile1.close();


	// ���ļ�
	// read()�������������������ļ��ж�ȡ���ݡ�
	/*
		basic_istream& read( char_type* s,					���ն�ȡ���ݵı�����ͷ��ָ�룬ǿתΪchar*	
						   std::streamsize count			��ȡ������ֽ�����
							);
	*/
	myDate dt_input;
	readFile2.read(reinterpret_cast<char*>(&dt_input), sizeof(dt_input));
	cout << "������"<< dt_input.year << "-" << dt_input.month << "-"<< dt_input.day << endl;
	readFile2.close();


}	



// test2: ʹ��cin�������������룺
static void test2(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test2: ʹ��cin��������������" << endl;


	// ��ȡ�����">>"��������ȡcin�����е�����
	int numi1;
	cout << "������һ������" << endl;
	cin >> numi1;
	cout << "����������ǣ�" << numi1 << endl;
	cout << endl << endl;
	
	

	// cin.get()��������������>>������>>�ܾ����ܿո�get()����
	setbuf(stdin, NULL);					// ��ջ�����
	cout << "������һ���ַ�������q������" << endl;
	char ch;
	while ((ch = cin.get()) != 'q')
	{
		cout.put(ch);
	}
	setbuf(stdin, NULL);					// ��ջ�����
	cin.clear();
	cout << endl << endl;


	// getline()��������cin�ж�ȡһϵ���ַ������ҿ���������ֹ�ַ������ҿ��Դ���string����
	string str;
	cout << "������һ���ַ�������p����" << endl;
	getline(cin, str, 'p');					// ��cin�ж�ȡһϵ���ַ�������str������p����
	cin.clear();
	setbuf(stdin, NULL);					// ��ջ�����
	cout << "������ַ���Ϊ��"<< str << endl;



}



// test3: string��
static void test3(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test3: string��" << endl;


	// string������ʵ�ֵ�toString������
	int numi1 = 999;
	string str = toString(numi1);
	cout << str << endl;


	stringstream ss;
	// �ַ���������ƴ�ӡ���ʽ���ȹ���������ͨ��sstream��ʵ�֣���C�����з��㡣
	//		��ʽ���ַ���
	for (int i = 1; i < 10; i++) 
	{
		ss << "���ǵ�" << i << "��ѭ��";
		cout << ss.str() << endl;
		ss.str("");					// ʹ�ÿ��ַ��������oss������ĵײ��ַ�����
	}

	// string����ƴ��
	string str1, str2;
	str1 = "hahaha";
	str2 = "wawawa";
	ss << str1 << str2;
	str1 = ss.str();
	ss.str("");
	cout << str1 << endl << endl;;

	// C�����ַ���ƴ��
	char cstr1[50] = "hahaha";
	char cstr2[50] = "wawawa";
	char cstr3[50] = "1";
	ss << cstr1 << cstr2;
	ss >> cstr1;				// c�����ַ���������ʹ��"="��ֵ��c������ʹ��strcpy();
	// ��������������������������ss����ʧЧ״̬���������clear()���������ٴ�ʹ�á�
	ss.clear();				// clear()��������ʹ���������´�����Ч״̬��
	ss << cstr1;
	ss >> cstr3;
	ss.str("");
	cout << cstr1 << endl;
	cout << cstr3 << endl;
}



// test4: ʹ��scanf()�ķ���ֵ��������Ϸ�����
static void test4(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test4: ʹ��scanf()�ķ���ֵ��������Ϸ�����" << endl;


	int inputValid = 0;
	int num;
	cout << "������һ������" << endl;
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
	cout << "�����������" << num << endl;


}
