#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>

#include "DSA_ͼ.h"

#define EPS 1e-10					//����ǳ�С��һ����EPSilon�������������������ֵʱ����Ϊ0
#define PI 3.14159


virtualModule* DSA_graph_module::getInstance()		// �̲߳���ȫ�ĵ���ģʽ
{
	if (nullptr != p_moduleIns)
	{
		delete p_moduleIns;
	}
	p_moduleIns = new DSA_graph_module;
	return p_moduleIns;
}



 
void DSA_graph_module::test0(void) {}
 

void DSA_graph_module::test1(void) {}


void DSA_graph_module::test2(void) {}


void DSA_graph_module::test3(void) {}


void DSA_graph_module::test4(void) {}



void DSA_graph_module::test5(void) {}



void DSA_graph_module::test6(void) {}
