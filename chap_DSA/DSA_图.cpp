#include "DSA_ͼ.h"

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159

//***************�෽��ʵ��
AdjListGraphArc::AdjListGraphArc()
{
	adjVex = -1;
}


AdjListGraphArc::AdjListGraphArc(int v, AdjListGraphArc *next)
{
	adjVex = v;
	nextArc = next;
}


virtualModule* DSA_graph_module::getInstance()		// �̲߳���ȫ�ĵ���ģʽ
{
	if (nullptr != p_moduleIns)
	{
		delete p_moduleIns;
	}
	p_moduleIns = new DSA_graph_module;
	return p_moduleIns;
}


// ����ͼʵ����������ȱ�����������ȱ�����
void DSA_graph_module::test0(void) 
{
	AdjListDirGraph<int> intGraph1;
	intGraph1.InsertVex(0);
	intGraph1.InsertVex(1);
	intGraph1.InsertVex(2);
	intGraph1.InsertArc(0, 1);
	intGraph1.InsertArc(1, 2);
	intGraph1.InsertArc(2, 0);
	intGraph1.Display();

	float numf[10] = {1,2,3,4,5,6,7,8,9,10};
	AdjMatrixUndirGraph<float> floatGraph1(numf, 10);
	floatGraph1.InsertArc(1, 2);
	floatGraph1.InsertArc(3, 2);
	floatGraph1.InsertArc(1, 5);
	floatGraph1.InsertArc(9, 0);
	floatGraph1.InsertArc(7, 8);
	floatGraph1.InsertArc(4, 6);
	floatGraph1.InsertArc(1, 7);
	floatGraph1.Display();

}
 

void DSA_graph_module::test1(void) {}


void DSA_graph_module::test2(void) {}


void DSA_graph_module::test3(void) {}


void DSA_graph_module::test4(void) {}



void DSA_graph_module::test5(void) {}



void DSA_graph_module::test6(void) {}
