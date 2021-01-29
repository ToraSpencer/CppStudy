#include <string>
#include <iostream>
#include <fstream>
#include <vector>						//vector��ģ����ͷ�ļ�<vector>��

#include <cstdio>


using namespace std;




// ֪ʶ��
/*
				1. vector�ײ��ǿɶ�̬����������˳���֧�������ȡ�����ǲ���ɾ����ʱ��
				
				2. vector��������ʱ���·����ڴ棬���е�����ʧЧ
				
				3. vectorִ�в������ʱ����û�з������������ڴ����·��䣬�����Ԫ�غ�ĵ�����ʧЧ��ǰ��ĵ�������Ȼ��Ч��
				
				4. ��C++11��STL����������ʹ���б��ʼ����

				5.  ������������ɾ���
							����
									push_back()			
									insert()			����������λ������Ԫ�أ�����һ���Բ�����Ԫ�ء�
									emplace(), 
									emplace_back()
									ע�⣺forwad_list��֧��push_back()��emplace_back()		

							ɾ��
									erase() 
									clear() 
							
							�飺
									��������û��find(), count()���������������У�����ʹ��STL�㷨���е�find����ʵ�֡�

							�ģ�
									swap() 
									assign()
									resize()			// ������Ԫ�����������ֽ�����

									
									

				6. �ײ�ṹ
							vector��������			˳���
							list��������			˫������
							forward_list��������	��������
							deque����				˫�˶���
							
							




*/





 


/***************************************************************************
***************************************************************************/
// ȫ�ֱ��������Ͷ���
class Complex					// �Զ��帴����
{
private:
	float real;
	float imag;
public:
	// ���졢��������
	Complex();
	Complex(float x, float y);

	// get/set����
	double getReal()	const;
	double getImag()	const;

	// ��ͨ����
	string toString();

	// ���������
	Complex operator+(Complex& cc);					//���ؼӺ��������ʹ������������ļӷ����㡣
	operator double();								//���������double()���������鲿Ϊ0ʱ�������ô������������ת��Ϊdouble�������ݡ�

};



/***************************************************************************
***************************************************************************/
// extern����
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;


/***************************************************************************
***************************************************************************/
// ��������
template <typename T>
void traverse_vector(const vector<T>&, void(*pVisit)(const T&));			// ���������Ĳ�����

template <typename T>
void print(const T&);													// ֻ����������ӡ��Ԫ�ص�ֵ��

void set_fun_STL_linear_container(void);
void start_STL_linear_container(void);


static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);
static void test5(void);
static void test6(void);
static void test7(void);
static void test8(void);
static void test9(void);
static void test10(void);
static void test11(void);


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
template <typename T>
void traverse_vector(const vector<T>& v, void(*pVisit)(const T&))		// ���������Ĳ�����
{
	for (auto elem : v)
	{
		(*pVisit)(elem);
	}
}



template <typename T>
void print(const T& elem)															// ֻ����������ӡ��Ԫ�ص�ֵ��
{
	cout << "\t" << elem << endl;
}



void set_fun_STL_linear_container(void)
{
	pfun[0] = test0;
	pfun[1] = test1;
	pfun[2] = test2;
	pfun[3] = test3;
	pfun[4] = test4;
	pfun[5] = test5;

}



void start_STL_linear_container(void)
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
		cout << "0. test0(): vector��������������������е��ص�" << endl;
		cout << "1. test1(): �������캯������ʼ������" << endl;
		cout << "2. test2(): vector���ʡ���������Ԫ�صĳ�Ա����" << endl;
		cout << "3. test3(): vector�ĵ�����" << endl;
		cout << "4. test4(): vector��������Ա����" << endl;
		cout << "5. test5(): vector������ʧЧ����" << endl;
		cout << "6. test6(): Ԫ�ط������������Ŀ�������" << endl;
		cout << "7. test7(): һ��Ӧ�ó�����" << endl;

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

		case 6:
			(*pfun[6])();
			break;


		case 7:
			(*pfun[7])();
			break;
 

		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}
}



// test0(): vector��������������������е��ص㣺
static void test0(void)
{
	vector<int>vi;
	vector<int>::iterator iter_i;
	vector<int>::const_iterator citer_i;

	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);
	vi.push_back(6);

	cout << "\n\n\n\n" << endl;
	cout << "test0(): vector��������������������е��ص㣺" << endl << endl;


	// 1. vector, string, array����ʹ���±�v[i]ֱ�ӷ���Ԫ�أ�
	for (int i = 0; i <= vi.size() - 1; i++)
	{
		cout << "\t" << vi[i] ;
	}
	cout << endl;

}





// test1():�������캯������ʼ��������
static void test1(void)
{
	vector<int> vi1;												// ����һ����������






	cout << "\n\n\n\n" << endl;
	cout << "test1(): �������캯������ʼ��������" << endl << endl;

	cout << "\tvi1.empty == " << vi1.empty() << endl;
	cout << endl;


	// 1. ָ��������������
	vector<int> vi2(3);			
	cout << "vi2.capacity() ==  " << vi2.capacity() << endl;
	traverse_vector(vi2, print);
	cout << endl;

	vi2.push_back(1);
	vi2.push_back(2);
	vi2.push_back(3);
	vi2.push_back(4);

	// 	1.1 push_back��ȥ�ĸ�Ԫ��֮��vi2���Զ����ݣ�
	cout << "vi2.size() == " << vi2.size() << endl;
	traverse_vector(vi2, print);
	cout << endl << endl;


	// 2. ָ��������������Ԫ��ͳһ��ʼֵ��
	vector<int> vi3(3, 10); 		
	traverse_vector(vi3, print);
	cout << endl;

	// 3. ʹ�ó�ʼ���б��ʼ��vector������
	vector<int> vi4 = {1,2,3,4};										// ��������ʵ�������������ǵ�Ч�ġ�
	int arr[] = { 1, 2, 3 };


	// 4. ��������������������
	vector<int> vi5(arr, arr + 3);									





}




// test2(): ������������ɾ���
static void test2(void)
{
	cout << "\n\n\ntest2():������������ɾ���" << endl << endl;




}



// test3():vector�ĵ�����
static void test3(void)
{
	cout << "\n\n\ntest3():vector�ĵ�����" << endl << endl;

	vector<int>vi;
	vector<int>::iterator iter_i;
	vector<int>::const_iterator citer_i;

	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);
	vi.push_back(6);

	// ʹ��const_iterator������vector������Ԫ�ء�
	cout << "use const_iterator to traverse all the items on the vector container:" << endl;
	for (citer_i = vi.begin(); citer_i != vi.end(); citer_i++)
	{
		cout << *citer_i << endl;
	}							//const_iteratorֻ�ܷ���Ԫ�أ��������޸�Ԫ�ء�
	cout << endl;


	// ʹ��iterator���޸�vector�е�Ԫ�ء�
	cout << "use iterator to change the vector's item's value: " << endl;
	iter_i = vi.begin();								//������ָ���һ��Ԫ�ء�
	*iter_i = -1;
	cout << "vi[0] == " << *iter_i << endl;
	iter_i++;
	*iter_i = -2;
	cout << "vi[1] == " << *iter_i << endl;
	iter_i += 1;
	*iter_i = -3;
	cout << "vi[2] == " << *iter_i << endl;
	cout << endl;


	// vector�ĵ�����ʧЧ���⣺
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);


	vector<int>::iterator  iter1 = vec.begin();
	vector<int>::iterator  iter2 = iter1;
	iter2++;


	cout << "*iter1 == " << *iter1 << endl;			// ò�Ʋ������֮�󣬼�ʹ�ǲ����֮ǰ��iteratorҲʧЧ�ˡ�
	cout << "*iter2 == " << *iter2 << endl;


	vec.insert(iter2, 999);


	for (const auto& elem : vec)
	{
		cout << elem << ",  ";
	}
	cout << endl;

	cout << "*iter1 == " << *iter1 << endl;			// ò�Ʋ������֮�󣬼�ʹ�ǲ����֮ǰ��iteratorҲʧЧ�ˡ�
	cout << "*iter2 == " << *iter2 << endl;

	vector<int>::iterator iter = vec.begin() + 3;
	cout << "*iter == " << *iter << endl;

	cout << distance(vec.begin(), iter) << endl;

}



// test4():vector��������Ա������
static void test4(void)
{
	//clear()�����vector
	//reverse()
	//swap()������vector����֮���Ԫ�ؽ�����

	vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);


	cout << "\n\n\ntest4():vector��������Ա����" << endl << endl;

	//empty()������boolֵ��ʾ�����Ƿ�Ϊ�ա�
	cout << "vi.empty() = " << vi.empty() << endl;
	cout << endl;


	//size():����vector����Ԫ������
	cout << "vi.size() = " << vi.size() << endl;
	cout << endl;


	//capacity():����vector��ǰ��������vector����ʱ���������Զ�����Ϊԭ����������������Ӧ�ڿ��ٵ��ڴ�ռ䡣
	cout << "vi.capacity() = " << vi.capacity() << endl;
	cout << endl;


	//reverse():�趨vector��������capacity
	cout << "" << endl;
	vi.reserve(8);
	cout << "vi.capacity() = " << vi.capacity() << endl;


	//max_size():����STL�涨��vector��������ɵ�Ԫ������
	cout << "vi.max_size() =  " << vi.max_size() << endl;
	cout << endl;
	

	//at(int ����)������Ԫ�ص����á�
	cout << " vi.at(1) = " << vi.at(1) << endl;
	cout << endl;
}




// test5()����vector������ʧЧ����
static void test5(void)
{
	vector<int> v1 = {1,2,3};		// ��ʼʱv1����Ϊ3������ʹ��v1.capacity()�鿴��
	auto iter1 = v1.begin();
	v1.push_back(4);				// ��ʱv1���������ı䣬�ڴ����·��䣬���е�����ʧЧ��
	cout << *iter1 << endl;			// ��ʱ��������������Ϊ�������Ѿ�ʧЧ��

	// ִ�в��������ʱ��ͬ��




}




// test6()����Ԫ�ط������������еĿ�������
static void test6(void) 
{
	// ָ�롢����Ϊ��ָ�������󱻴���vectorʱ����������ǳ����
	int num1 = 999;
	int num2 = 888;
	int num3 = 777;
	int* p1 = &num1;
	int* p2 = &num2;
	int* p3 = &num3;

	vector<int*> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);

	for (const auto& elem : vec)
	{
		cout << *elem << ", ";
	}
	cout << endl;

	*p1 = 111;
	*p2 = 222;
	*p3 = 333;

	for (const auto& elem : vec)
	{
		cout << *elem << ", ";
	}
	cout << endl;

}




// test7()����Ӧ�ó���
static void test7(void)
{
	// Ӧ�ó�����������string����Ȼ��ͨ���ö���������Ӧ���ļ������
	//		���������string����ϣ�����ļ���������Ӻ�׺"_x", "_y"����ʾx��y������������ݡ�
	string str = "data.dat";


	// �顪��find()������������������û��find����
	auto iter = find(str.begin(), str.end(), 'x');
	if (iter == str.end())
	{
		cout << "error" << endl;
	}
	auto dis = distance(str.begin(), iter);


	// ������insert()������������λ�ò��룬���ҿ���һ���Բ�����Ԫ��
	/*
		basic_string& insert( size_type index,
								const CharT* s
								);
	*/
	str.insert(dis, "_x");
	cout << str << endl;
	fstream file(str, ios::out);
	file.close();

}

