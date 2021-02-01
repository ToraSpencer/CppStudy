#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <utility>



#include <cstdio>


#include "STL_set������.h" 
using namespace std;

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


// ֪ʶ��
/*
	1. ���й���������set, map, multiset, multimap�ײ㶼�Ǻ����
	
	2. �ص��ǲ��롢ɾ��Ч�ʸߡ�
				�����ʱ��ֻ��Ҫ�����任��Ȼ��ѽڵ��ָ��ָ���µĽڵ�Ϳ����ˡ�
				ɾ����ʱ�����ƣ������任���ָ��ɾ���ڵ��ָ��ָ�������ڵ�ҲOK�ˡ�
				�����һ�в�������ָ�뻻����ȥ�����ڴ��ƶ�û�й�ϵ�����Բ�������������ʧЧ�����⡣

	3. ���÷���
	 			begin() end() rbegin rend() ���ص�����
				clear()   �� ���������
				empty() �������ж�set�����Ƿ�Ϊ��
				max_size() �� ����set�������ܰ�����Ԫ��������
				size() �������� ���ص�ǰset�����е�Ԫ�ظ���

	4. ��map��������map�е�Ԫ����key��value�������ݣ�set�е�Ԫ��ֻ��keyһ�����ݡ�

	5. ����set�е�Ԫ�ض����Զ����򡣰���Ԫ�ص�<������������С�

	6. set�ĵ�������������const�ģ�ֻ�ܶ�����д����Ϊ�Ķ�set��Ԫ���п��ܻ�����������ǲ�����ġ�

*/












// STL��������������set, map, multiset, multimap
/*
		set 					Ψһ���ļ��ϣ����ռ�����
		map 					��ֵ�Եļ��ϣ����ռ����򣬼���Ψһ��
		multiset 				���ļ��ϣ����ռ�����
		multimap 				��ֵ�Եļ��ϣ����ռ�����
 
���ԣ�
		�ײ��Ǻ����ʵ�֡�
		����Ѹ�١�������O(log n) ���Ӷ�
		������ֱ���޸�Ԫ�أ�ֻ����ɾ���
		�����бȽ���value_compare����һ�������ӣ������涨�����м�������Ĺ���
*/




// STL�����������������unordered_set, unordered_map, unordered_multiset, unordered_multimap
/*
		(C++11 ��)unordered_set 						Ψһ���ļ��ϣ����ռ�����ɢ��
		(C++11 ��)unordered_map 						��ֵ�Եļ��ϣ����ռ�����ɢ�У�����Ψһ��
		(C++11 ��)unordered_multiset					���ļ��ϣ����ռ�����ɢ��
		(C++11 ��)unordered_multimap 					��ֵ�Եļ��ϣ����ռ�����ɢ��
 

���ԣ�
		�ײ��ǹ�ϣ�ṹ��
		����Ѹ�١�����������̯ O(1) ������ O(n) �ĸ��Ӷ�

*/


virtualModule* STL_set_module::getInstance()		// �̲߳���ȫ�ĵ���ģʽ
{
	if (nullptr != p_moduleIns)
	{
		delete p_moduleIns;
	}
	p_moduleIns = new STL_set_module;
	return p_moduleIns;
}





// test0: set�Ļ���ʹ�÷�����API
void STL_set_module::test0(void) 
{
	cout << "\n\n\n\n" << endl;
	cout << "test0: set�Ļ���ʹ�÷�����API" << endl;

	// �������͵�set:
	// 		���뵽set�еĻ�������Ԫ�ػ�Ĭ�ϴ�С�������򣬲��뵽���ʵ�λ�á�
	set<int> seti1;									// ���췽��1
	set<int>::iterator iter_i;
	baseTypePrinter btp;

	seti1.insert(1);
	seti1.insert(0);
	seti1.insert(9);
	seti1.insert(8);
	seti1.insert(11);
	seti1.insert(-3);

	for_each(seti1.begin(), seti1.end(), btp);


	// 		����Ҫ�޸�Ԫ������ķ�ʽ������ʱ

 


}


// test1: set�Ĳ��ҽӿ�
void STL_set_module::test1(void)
{
	cout << "\n\n\n\n" << endl;
	cout << "test1: set�Ĳ��ҽӿ�" << endl;

	set<int> seti1;									// ���췽��1
	set<int>::iterator iter_i1;
	pair<set<int>::iterator, set<int>::iterator> pi1;

	seti1.insert(1);
	seti1.insert(0);
	seti1.insert(9);
	seti1.insert(8);
	seti1.insert(11);
	seti1.insert(-3);

	//	find�����������ҳɹ�����ָ����������ĵ�����������ʧ�ܷ���β�������
	iter_i1 = seti1.find(-3);					
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û��-3���Ԫ��" << endl;

	}
	else
	{
		cout << "\titer_i��ָ��seti1��Ԫ��-3�ĵ�������" << endl;

	}


	// lower_bound����������set���׸�С�ڵ���ָ��Ԫ�ص�Ԫ�ص�����
	iter_i1 = seti1.lower_bound(1);
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û��С�ڵ���1��Ԫ��" << endl;

	}
	else
	{
		cout << "\tseti1���׸�С�ڵ���1��Ԫ��Ϊ��*iter_i1 == " << *iter_i1 << endl;

	}



	// upper_bound������������set���׸����ڵ���ָ��Ԫ�ص�Ԫ�ص�����
	iter_i1 = seti1.upper_bound(1);
	if(iter_i1 == seti1.end())
	{
		cout << "\tseti1��û�д��ڵ���1��Ԫ��" << endl;

	}
	else
	{
		cout << "\tseti1���׸����ڵ���1��Ԫ��Ϊ��*iter_i1 == " << *iter_i1 << endl;

	}


	// equal_range������������һ��pari���ֱ����lower_bound��upper_bound���Է��صĵ�����
	pi1 = seti1.equal_range(1);
	if(pi1.first != seti1.end())
	{
		cout << "\t*pi1.first == " << *pi1.first << endl;
	}
	if(pi1.second != seti1.end())
	{
	cout << "\t*pi1.second == " << *pi1.second << endl;
	}


}


void STL_set_module::test2(void) {}


void STL_set_module::test3(void) {}


void STL_set_module::test4(void) {}


void STL_set_module::test5(void) {}


void STL_set_module::test6(void) {}