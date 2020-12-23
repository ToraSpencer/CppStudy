#include <iostream>
#include <string>
#include <typeinfo>

#include <memory>
#include <vector>
#include <cstddef>
#include <new>

#include <cstdio>



using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159



// ֪ʶ��
/*
			1. ָ�������״̬������ָ�롢Ұָ�롢����ָ�루ָ��ʵ�����ݶ���
						��ָ��
									��ֵΪ0��ָ��
									��ָ���κ����ݶ���

						Ұָ��
									δ����ʼ����ָ�룬��ָ���ڴ汻�ͷ�֮���ָ�롣
									��ʱָ��ָ���λ��δ֪�������������
									һ��ʹ��Ұָ��Ļ������������ᱨ��




			2. ���ú�ָ�������
							(1). ���ñ��뱻��ʼ����ָ�벻��Ҫ��
							(2). ���ó�ʼ��֮�󲻿ɸı䣬ָ�����
							(3). �����ڿ����ã����ڿ�ָ�롣





			3. ��������ָ����ģ��shared_ptr, unique_ptr, weak_ptr�Ļ�����Ϣ(C++11)
							����ָ����Ҫ��������Ѷ��󣬶���ջ����û�б�Ҫʹ�ã��õĻ����ܻ��������쳣��
							
							shared_ptr
									�ɹ��������ָ�롣
									����5��shared_ptrָ��ָ��ͬһ�����ݶ���������ݶ�������ü���Ϊ5
									һ����������ü�������0ʱ���ᱻ���٣��ڴ���ͷš�
							
							unique����ptr
									���ɹ���ģ�Ψһ������ָ�롣
			



			4. shared_ptr��unique_ptr�ıȽ�
							(1) shared_ptr, unique_ptr��ͬ�Ľӿڣ�
											p.get()
														��������ָ������д洢��ָ�롣
											p			
														�������жϣ�������ָ��pָ��һ�������򷵻�true
											*p
											p->member
											p.swap(q)
														��������ָ�����p,q�д洢��ָ��
											p.reset(��ָͨ��)
														��������ָ��ָ��Ķ���
							

							(2) shared_ptr���еĽӿ�
											p.use_count()
														����һ��long, ������pָ��Ķ���ǰ�����ٸ�shared_ptrָ��ָ��
											p.unique()
														���p�Ƿ���unique�ģ�����ָ��Ķ���ǰֻ��p��һ��shared_ptrָ��ָ���򷵻�true

							(3) unique_ptr���еĽӿڣ�
											p.release()
														���ر�����������ָͨ�룬���ޱ���������򷵻�NULL

														

			5. �����Ĳ���Ұָ��Ĵ���
							����ָ�������ʱ��δ��ʼ����
							delete����free��һ��ָ���Ժ�δ����ָ������
							�����ڲ�������һ��ָ��ջ�ڴ��ָ�롣��Ϊջ�ڴ��ں���������ͻ��ͷš�


			6. �ڴ�й©��memory leak�� 
							��1�����ڴ�й© ��Heap leak����
											���ڴ�ָ���ǳ���������ͨ��malloc,realloc new�ȴӶ��з����һ���ڴ档����������ƵĴ������ⲿ���ڴ�û�б��ͷţ���ô�˺�����ڴ潫���ᱻʹ�ã��ͻ����Heap Leak. 	
							��2��ϵͳ��Դй¶��Resource Leak��.
											��Ҫָ����ʹ��ϵͳ�������Դ���� Bitmap,handle ,SOCKET��û��ʹ����Ӧ�ĺ����ͷŵ�������ϵͳ��Դ���˷ѣ����ؿɵ���ϵͳЧ�ܽ��ͣ�ϵͳ���в��ȶ��� 

							����һ����ַ�ʽ�ǳ�������ʱ��Խ����ռ���ڴ�Խ�࣬�����þ�ȫ���ڴ棬����ϵͳ������

							�ɳ��������һ���ڴ棬��û���κ�һ��ָ��ָ��������ô����ڴ��й¶�ˡ�

			7. ��η�ֹ�ڴ�й©
							���õı���ϰ�ߣ���new��deleteҪ��֤�ɶԳ��֣�new���������ݶ���ʹ�����֮��Ҫ��ʱ���ͷŵ������߾���ʹ������ָ�롣
						


			8. ����ڴ�й©��;��
							1. ʹ�ù������BoundsChecker����һ������ʱ�����⹤�ߣ�����Ҫ��λ��������ʱ�ڷ����ĸ��ִ���


			


			9. �ڴ�й©���޸�;��

*/





// make_shared<T>()������������һ��shared_ptrָ��
/*. BC------------------------------------------------------------------------
������  
	���ٶ�̬�ڴ�ռ䣬����shared_ptr����
	Դ��ͷ�ļ�<memory>
	���ɵ�T���Ͷ���ĳ�ʼֵ��Ĭ�ϵġ�
	���ӣ�shared_ptr<int> p = make_shared<int>(42);

						
	����1��
		shared_ptr<T> make_shared( Args&&... args 			����T����Ĺ��캯�������б�
															);	
		����ֵ��
			ָ���������T���Ͷ����shared_ptrָ�롣
			

	����2��
		shared_ptr<T> make_shared();

		����ֵ��
			ͬ�ϡ�
								 
 
*. EC------------------------------------------------------------------------
*/







/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
class Foo
{
private:

public:


};




/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;



/***************************************************************************
***************************************************************************/
// ��������
void set_fun_dataType_pointer(void);
void start_dataType_pointer(void);

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

void set_fun_dataType_pointer(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
}



void start_dataType_pointer(void)
{
	// ����㼶����Ϊ3�������������棺
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: dataType_pointer**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0: ʹ�ùؼ���new��deleteֱ�ӹ����ڴ档" << endl;
		cout << "1. test1������ָ��shared_ptr, unique_ptr�Ļ���ʹ��" << endl;
		cout << "2. test2���Զ�������ʹ������ָ��shared_ptr, unique_ptr" << endl;
		cout << "3. test3: ��ָ��" << endl;


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

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// test0: ʹ�ùؼ���new��deleteֱ�ӹ����ڴ档
static void test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: ʹ�ùؼ���new��deleteֱ�ӹ����ڴ档" << endl;
 
	int *p1 = new int; 							// �������ڴ�ʧ�����׳�std::bad_alloc
	int *p2 = new (nothrow) int; 		// �������ڴ�ʧ���򷵻�һ����ָ��
	int i0;                   
	int *p0 = new int;        
	                         
	delete p0;   

	int i(1024);              
	string s(10, '9');       


	// δ�����������ѳ�ʼ���˵����ݶ���
	int *pi = new int(1024);  
	string *ps = new string(10, '9');    
 
 

	vector<int> *pv = new vector<int>; 	// empty vector
	for (int i = 0; i != 10; ++i)
	{
		pv->push_back(i);              // add elements to the allocated vector
	}


	cout << "*pi: " << *pi
	     << "\ti: " << i << endl
	     << "*ps: " << *ps
	     << "\ts: " << s << endl;
	
	for (auto b = pv->begin(); b != pv->end(); ++b)
	{
		cout << *b << " ";
	}
	
	cout << endl;


	// �ڴ�ʹ������Ժ���Ҫɾ�����Ӧ��ָ�룬���������ڴ�й©
	delete pi;   
	delete ps;  
	delete pv;   
	
 
	// �����ڴ�Ŀ��ٺ��ͷţ�
	int *pia = new int[42];  
	delete [] pia; 			// �ͷ������ڴ��ʱ��Ҫ��delete֮�����[]
	typedef int arrT[42];   
	int *p = new arrT;      
	delete [] p;           

}




// test1������ָ��shared_ptr, unique_ptr�Ļ���ʹ��
static void test1(void) 
{
	float f1 = 1.10;
	shared_ptr<float> pf1;						// Ĭ�Ϲ��캯��������һ���յ�shared_ptrָ�� 
	shared_ptr<float> pf2(&f1);					// ������ָͨ�빹��shared_ptrָ��
	shared_ptr<float> pf3(new float(1.11));		// ������ָͨ�빹�죬��Ϲؼ���new
	shared_ptr<int> pi1;
	shared_ptr<int> pi2 = make_shared<int>(12);	// ʹ��make_shared��������shared_ptrָ��

	cout << "\n\n\n\n" << endl;
	cout << "test1������ָ��shared_ptr, unique_ptr" << endl;

	cout << "\tpi1.use_count() == " << pi2.use_count() << endl;
	cout << "\tpi1.unique() == " << pi2.unique() << endl;

	pi1 = pi2;
	cout << "pi1 = pi2; �� pi1,pi2����ͬһ�����ݶ���" << endl;
	cout << "\tpi1.use_count() == " << pi2.use_count() << endl;
	cout << "\tpi1.unique() == " << pi2.unique() << endl;

}



// test2: �Զ�������ʹ������ָ��shared_ptr, unique_ptr
static void test2(void)
{

	// ����ָ��Ĭ��ʹ��delete���ͷŶ����ڴ档�Զ������͵ģ���Ҫ��ɾ�����ſ���ʹ��delete

}



// test3: ��ָ��
static void test3(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test3����ָ��" << endl;

	// ʹ�ÿ�ָ�������ʲ����ڵ��ڴ�ռ䣬��������ָ���쳣���Ӷ��������
	// ����ʹ��p==NULL���ʽ���ص�boolֵ���ж��Ƿ��ǿ�ָ��
	int *pi1 = NULL;
	int *pi2 = NULL;

	if (pi1 == NULL && pi1 == NULL && pi2 == NULL && pi2 == NULL)
	{
		cout << "pi1��pi2���ǿ�ָ�롣д��NULL��nullptr�����ԡ�" << endl;
	}

	cout << "(int)(pi1 == NULL) == " << (int)(pi1 == NULL) << endl;
	cout << "(int)(pi1 == NULL)" << (int)(pi2 == NULL) << endl;



}





// test4: 
static void test4(void) 
{


}
