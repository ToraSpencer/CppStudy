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
	std::cout << "************�½��б�***************" << std::endl;
	std::cout << "1. ��������" << std::endl;
	std::cout << "2. ���ģʽ" << std::endl;
	std::cout << "3. STL" << std::endl;



	std::cout << std::endl << std::endl;
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
	if (this->currentChap == ch)		// ѡ���½ں͵�ǰ�½���ͬ�Ļ�����ʲô��������
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
	case CHAP_BASIC_TYPES:					// ���������½�
		Hdll = LoadLibrary(L"chap_basicTypes.dll");
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
		this->currentChap = CHAP_ENUM::CHAP_BASIC_TYPES;
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


	case CHAP_STL:
		Hdll = LoadLibrary(L"chap_STL.dll");
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
		this->pc = reinterpret_cast<chap_STL*>((*pfunc)());
		this->currentChap = CHAP_ENUM::CHAP_STL;
		break;


	default:
		std::cout << "��ѡ��һ�����ڵ��½ڡ�" << std::endl;
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


bool reader::isNullChap() const
{
	if (this->pc == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool reader::isNullModule() const 
{
	if (isNullChap())
	{
		return true;
	}

	if (this->pc->isNullModule())
	{
		return true;
	}
	else 
	{
		false;
	}

}