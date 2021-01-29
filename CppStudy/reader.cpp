#include "reader.h"


reader::reader()
{
	this->pc = nullptr;
	this->currentChap = CHAP_ENUM::NO_CHAP;
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
	std::cout << "1. ��������" << std::endl;
	std::cout << "2. ���ģʽ" << std::endl;
}


void reader::showModuleList() 
{
	if (this->pc == nullptr) 
	{
		std::cout << "��ǰδָ���½ڡ�" << std::endl;
		return;
	}
	this->pc->showModuleList();
}


void reader::selectChap(const CHAP_ENUM ch)
{
	if (this->currentChap == ch) 
	{
		return;
	}

	if (pc != nullptr && Hdll != nullptr)
	{
		delete this->pc;
		this->pc = nullptr;
		FreeLibrary(Hdll);
	}

	pVV pfunc = nullptr;

	switch (ch)
	{
	case CHAP_DATA_TYPE:					// ���������½�
		// ���ض�̬�⡣����
		//this->pc = chap1::getInstance();
		break;

	case CHAP_DESIGN_PATTERN:				// ���ģʽ�½�
		Hdll = LoadLibrary(L"chap_designPattern.dll");
		if (Hdll == nullptr)
		{
			std::cout << "��̬�����ʧ��" << std::endl;
			return;
		}
		pfunc = (pVV)(GetProcAddress(Hdll, "getChap"));
		if (pfunc == nullptr)
		{
			std::cout << "��̬�⺯����ȡʧ��" << std::endl;
			return;
		}
		this->pc = reinterpret_cast<chap_designPattern*>((*pfunc)());
		this->currentChap = CHAP_ENUM::CHAP_DESIGN_PATTERN;
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