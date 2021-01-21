#include "basicTools.h"



virtualModule* virtualModule::p_moduleIns = nullptr;


void virtualModule::run(unsigned testID)
{
	switch (testID)
	{
	case 1:
		test1();
		break;
	case 2:
		test2();
		break;
	default:
		break;
	}
}


virtualChap* virtualChap::p_chapIns = nullptr;


virtualChap::~virtualChap()
{
	std::cout << "������chapϵ����ĵ���������" << std::endl;
	if (this->pm != nullptr)
	{
		delete this->pm;
		this->pm = nullptr;
	}
}


void virtualChap::runTest(const unsigned testID)
{
	if (nullptr == this->pm)
	{
		std::cout << "��ǰû��ȷ���κ�ģ��" << std::endl;
		return;
	}
	this->pm->run(testID);
}


reader::reader()
{
	this->pc = nullptr;
}


reader* reader::getInstance()		// ����chapter��moduleһ�������ڶ��ϣ�����ʹ��meyer's singleton
{
	static reader caller_instance;
	return &caller_instance;
}


reader::~reader()		noexcept	// Ҫ����ײ㿪ʼ��������deleteָ�롣
{
	if (this->pc != nullptr)
	{
		delete this->pc;
		this->pc = nullptr;
	}
}


void reader::showChapList()
{
	std::cout << "1. dataType" << std::endl;
	std::cout << "2. design pattern" << std::endl;
}


void reader::selectChap(const CHAP_ENUM ch)
{
	// to be optimized: ϣ�������е�this->pcָ���chapter�����������жϣ�����ͽ��յ�ch��Ӧ������һ��������Ҫ���κβ�����
	if (pc != nullptr)
	{
		delete this->pc;
		this->pc = nullptr;
	}

	switch (ch)
	{
	case CHAP_DATA_TYPE:
		// ���ض�̬�⡣����
		//this->pc = chap1::getInstance();
		break;
	case CHAP_DESIGN_PATTERN:
		//this->pc = chap2::getInstance();
		break;
	default:
		break;
	}



}


void reader::selectMol(const int molEnum)
{
	if (this->pc == nullptr)
	{
		return;
	}
	this->pc->selectModule(molEnum);
}


void reader::runTest(const unsigned testID)
{
	this->pc->pm->run(testID);
}