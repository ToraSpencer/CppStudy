#pragma once

#include <windows.h>

#include "basicTools/basicTools.h"
#include "chap_designPattern/chap_designPattern.h"


#pragma comment(lib, "./Release/basicTools.lib")

extern HMODULE Hdll;
using VOIDP = void*;
using pVV = VOIDP(*)(void);


// һ����ö�ٳ���
enum CHAP_ENUM
{
	NO_CHAP = 0,
	CHAP_DATA_TYPE = 1,
	CHAP_DESIGN_PATTERN,
};





struct reader
{
private:
	virtualChap* pc;		// ��ǰ�鿴���½ڡ�
	CHAP_ENUM currentChap;		// ��ǰ�鿴�½ڶ�Ӧ��ö�ٳ�����
	reader();

public:
	static reader* getInstance();

	~reader() noexcept;

	void showChapList();

	void showModuleList();

	void selectChap(const CHAP_ENUM ch);

	void selectMol(const int molEnum);

	void runTest(const unsigned testID);
};


