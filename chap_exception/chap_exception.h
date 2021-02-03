#pragma once

#include "basicTools/basicTools.h"
#include "exception_��׼�쳣.h"
#include "exception_�����쳣����.h"

#pragma comment(lib, "basicTools.lib")


#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport) 
#else
#define DLL_API __declspec(dllimport)
#endif


enum EXCEPTON_MODULE
{
	MODULE_BASIC_EXCEPTION = 1,
	MODULE_STD_EXCEPTION,
};


struct chap_exception : public virtualChap
{
protected:
	chap_exception() = default;

public:
	void showModuleList();
	static virtualChap* getInstance();
	bool selectModule(const int molEnum);
};



extern "C"
{
	DLL_API void* getChap();
}
