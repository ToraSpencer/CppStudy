#pragma once


#include "basicTools/basicTools.h"
#pragma comment(lib, "./Release/basicTools.lib")


struct function_inline_function_module : public virtualModule
{
protected:
	function_inline_function_module() = default;

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
