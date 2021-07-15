#pragma once
//�б�Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������


template <typename T> 
void List<T>::mergeSort ( ListNodePosi<T> & p, int n ) 
{ 
   if ( n < 2 ) return;				//��������Χ���㹻С����ֱ�ӷ��أ�����...
   int m = n >> 1;						//���е�Ϊ��
   ListNodePosi<T> q = p; 
   for (int i = 0; i < m; i++) 
	   q = q->succ;							//�ҵ������б����
   mergeSort(p, m); 
   mergeSort(q, n - m);					//ǰ�������б���ֱ�����
   p = merge ( p, m, *this, q, n - m );				//�鲢
} 

//ע�⣺�����p��Ȼָ��鲢������ģ��£����