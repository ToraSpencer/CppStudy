#pragma once


#include "basicTools/basicTools.h"
#pragma comment(lib, "./Release/basicTools.lib")


struct basicTypes_reference_module : public virtualModule
{
protected:
	basicTypes_reference_module() = default;

public:
	static virtualModule* getInstance();
	virtual void test0();
	virtual void test1();
	virtual void test2();
	virtual void test3();
	virtual void test4();
	virtual void test5();
	virtual void test6();
};

