#include <string>
#include <iostream>
#include <vector>						//vector��ģ����ͷ�ļ�<vector>��
using namespace std;


/* vector:
 * 		�����Ƕ�̬���飺
 * 				Ԫ�����ڴ��������洢��
 * 				���Կ����ڴ汻����ʱ������Ҫ���Ԫ�أ������·����ڴ棬��������Ϊԭ����������
 * 		�ص㣺
 * 				β�壬βɾ�ٶȺܿ죬����λ�ÿ��ܱȽ�����
 * 				֧��������ʡ�
 */

// ������ӡvectorԪ�صĺ���
template <typename T>
void dispVector(vector<T> v)
{
	vector<int>::const_iterator it1,it2;
	it1 = v.cbegin();
	it2 = v.cend();
	while(it1!=it2)
	{
		cout << *it1 << "   ";
		it1++;
	}
	cout << endl;
}

//test1():vector��������������������е��ص㣺
void test1()
{
	cout << "test1():vector��������������������е��ص㣺" << endl << endl;
	vector<int>vi;
	vector<int>::iterator iter_i;
	vector<int>::const_iterator citer_i;

	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);
	vi.push_back(6);

	//vector����ʹ���±�v[i]ֱ�ӷ���Ԫ�أ�
	cout << "vector����ʹ���±�v[i]ֱ�ӷ���Ԫ�أ�" << endl;
	for(int i  = 0; i<=vi.size()-1; i++)
	{cout << vi[i] << "  ";}
	cout << endl;
}

//test2():���캯������ʼ��������
void test2()
{
	cout << "test2():�������캯������ʼ������" << endl << endl;

	// vector<_Tp>() ����/�޲ι��죺
	cout << "vector<_Tp>() ����/�޲ι��죺" << endl;
	vector<int> vi1;				//����һ����������
	cout << "is vi1 empty?  " << vi1.empty() << endl << endl;

	// vector<_Tp>(int size) �������size��0Ԫ�ص�vector
	cout << "vector<_Tp>(int size) �������size��0Ԫ�ص�vector" << endl;
	vector<int> vi2(3);				//����һ���趨����Ϊ3��������
	dispVector(vi2);
	cout << endl;
	cout << "the capacity of vi2 is : " << vi2.capacity() << endl;
	vi2.push_back(1);
	vi2.push_back(2);
	vi2.push_back(3);
	vi2.push_back(4);
	dispVector(vi2);
	cout << "now the actual size of vi2 is : " << vi2.size() << endl;
	//ʵ�ʴ洢��Ԫ�������ǿ��Գ���������capacity��
	cout << endl << endl;


	// vector<_Tp>(int size, _Tp val)���������n��ֵΪvalԪ�ص�vector
	cout << "vector<_Tp>(int size, _Tp val)���������n��ֵΪvalԪ�ص�vector" << endl;
	vector<int> vi3(3,10);					//����һ���趨����Ϊ3����ֵȫΪ10��������
	vector<int> vi4 = vector<int>(8,14);	//��������ʵ�������������ǵ�Ч�ġ�
	dispVector(vi3);
	dispVector(vi4);
	cout << endl;

	// ������������Ԫ�ص�ָ�룬����Χ�ڵ�Ԫ�ط���vector:
	cout << "������������Ԫ�ص�ָ�룬����Χ�ڵ�Ԫ�ط���vector:" << endl;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	vector<int> vi5(arr,arr+9);
	dispVector(vi5);

	// ��������������������Χ�ڵ�Ԫ�ط���vector��
	cout << "��������������������Χ�ڵ�Ԫ�ط���vector��" << endl;
	vector<int>::iterator it1 = vi5.begin();
	vector<int>::iterator it2 = vi5.end();
	it1++;
	it2--;
	vector<int> vi6(it1,it2);
	dispVector(vi6);
	cout << endl;



}

// test3():vector���ʡ�����Ԫ�صĳ�Ա������
void test3()
{
	cout << "test3():vector���ʡ���������Ԫ�صĳ�Ա������" << endl << endl;

	// push_back():��ĩβ���Ԫ�ء�
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);

	// pop_back():ɾ��ĩβ��Ԫ�ء�
	cout << "pop_back():ɾ��ĩβ��Ԫ�ء�" << endl;
	cout << "vi.pop_back()֮ǰ�����vi:" << endl;
	dispVector(vi);
	vi.pop_back();
	cout << "vi.pop_back()֮�����vi:" << endl;
	dispVector(vi);
	cout << endl;

	// T front():���ص�һ��Ԫ�ص�����
	cout << "T front():���ص�һ��Ԫ�ص����ã�" << endl;
	cout << "vi.front() = " << vi.front() << endl;
	cout << endl;

	// T back():�������һ��Ԫ�ص����ã�
	cout << "T back():�������һ��Ԫ�ص����ã�" << endl;
	cout << "vi.back() = " << vi.back() << endl;
	cout << endl;

	// at(i): ����Ԫ�ص����ã����ַ�����ֱ�����±���ʰ�ȫ��iԽ��ʱ���׳��쳣��
	cout << "at(i): ����Ԫ�ص����ã����ַ�����ֱ�����±���ʰ�ȫ��iԽ��ʱ���׳��쳣��" << endl;
	cout << "vi.at(1) = " << vi.at(1) << endl;
	cout << "����Ҳ����ʹ���Լ��Լ��������++vi.at(1) = " << ++vi.at(1) << endl;
	cout << endl;



	// ����Ԫ��insert();
    //		iterator insert(const_iterator position, const T& x);					���뵥��Ԫ��
    //		iterator insert(const_iterator position, size_type n, const T& x);		��������ͬԪ��
    //		template <class InputIterator>											�ӱ��������ѡȡһϵ��Ԫ�ز��뵽�������е�ĳλ�á�
    //    		iterator insert (const_iterator position, InputIterator first,
    // 		                    InputIterator last);  ע��first��last�����Ǳ������Ԫ�صĵ�������Ԫ�����ͱ���ƥ�䡣
    //		iterator insert(const_iterator position, initializer_list<T>);
	cout << "����Ԫ��insert()" << endl;
	cout << "v.insert(v.begin(),88):���뵥��Ԫ��" << endl;
	vector<int> v(3,0);
	dispVector(v);
	v.insert(v.begin(),88);
	dispVector(v);

	cout << "v.insert(iter,3,77):��������ͬԪ��" << endl;
	vector<int>::iterator iter = v.begin();
	iter++;
	v.insert(iter,3,77);
	dispVector(v);

	cout << "v.insert(iter,it1,it2)���ӱ��������ѡȡһϵ��Ԫ�ز��뵽�������У�" << endl;
	vector<int>::iterator it1,it2;
	it1 = vi.begin();
	it2 = vi.end();
	it1+=2;
	iter = v.begin()+3;
	v.insert(iter,it1,it2);
	dispVector(v);
	cout << endl;

}

//test4():vector�ĵ�����
void test4()
{
	cout << "test4():vector�ĵ�����" << endl << endl;

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
	for(citer_i = vi.begin(); citer_i != vi.end(); citer_i++)
	{cout << *citer_i << endl;}							//const_iteratorֻ�ܷ���Ԫ�أ��������޸�Ԫ�ء�
	cout << endl;


	// ʹ��iterator������vector������Ԫ�ء�
	// !!!����������flag �� iter == v.end();
	cout << "use iterator to traverse all the items on the vector container:" << endl;
	for(iter_i = vi.begin(); iter_i != vi.end(); iter_i++)
	{cout << *iter_i << endl;}
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

}

// test5():vector��������Ա������
void test5()
{
	//clear()�����vector
	//swap()������vector����֮���Ԫ�ؽ�����

	vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);

	//empty()������boolֵ��ʾ�����Ƿ�Ϊ�ա�
	cout << "empty()������boolֵ��ʾ�����Ƿ�Ϊ��.   vi.empty() = " << vi.empty() << endl;
	cout << endl;

	//size():����vector����Ԫ������
	cout << "size():����vector����Ԫ������  vi.size() = " << vi.size() << endl;
	cout << endl;

	//capacity():����vector��ǰ��������vector����ʱ���������Զ�����Ϊԭ����������������Ӧ�ڿ��ٵ��ڴ�ռ䡣
	cout << "capacity():����vector��ǰ��������vector����ʱ���������Զ�����Ϊԭ����������������Ӧ�ڿ��ٵ��ڴ�ռ䡣" << endl;
	cout << "vi.capacity() = " << vi.capacity() << endl;
	cout << endl;

	//reserve():�趨vector��������capacity
	cout << "" << endl;
	vi.reserve(8);
	cout << "vi.reserve(8)�趨vector��������capacity; vi.capacity() = " << vi.capacity() << endl;

	//max_size():����STL�涨��vector��������ɵ�Ԫ������
	cout << "max_size():����STL�涨��vector��������ɵ�Ԫ������  vi.max_size() =  " << vi.max_size() << endl;
	cout << endl;
}

//test6()����ȡ���������ԣ�
void test6()
{
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);

	cout<<"vi.size() = "<< vi.size()<< endl;					// Ԫ�ظ���
	cout << "vi.empty() = "<< vi.empty()<< endl;				// �Ƿ�Ϊ��
	cout <<"vi.capacity() = " <<vi.capacity() <<endl;			// ����

}


int main()
{
	//test1();
	//test2();
	test3();
	//test4();
	//test5();
	//test6();

	return 0;
}
