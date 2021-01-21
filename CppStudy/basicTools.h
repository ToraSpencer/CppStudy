#pragma once
#include "iostream"

// ǰ������
 




// ģ����ĳ������
struct virtualModule
{
protected:
	virtual void test0() = 0;
	virtual void test1() = 0;
	virtual void test2() = 0;
	virtual void test3() = 0;
	virtual void test4() = 0;
	virtual void test5() = 0;
	virtual void test6() = 0;

public:
	static virtualModule* p_moduleIns;
	virtual ~virtualModule() = default;
	void run(unsigned testID);
};


// �½���ĳ������
struct virtualChap
{
public:
	virtualModule* pm;		// ��ǰ�鿴��ģ���ָ�룬��Ҫ��caller���Է��ʣ�
							//	to be optimized: ��ʵ���淶����������Ƴ���Ԫ��Ȼ����Ȼ����Ϊprotected��Ա
	static virtualChap* p_chapIns;
	virtual ~virtualChap();

	virtual void showModuleList() = 0;
	virtual void selectModule(const int molEnum) = 0;
	virtual void runTest(const unsigned testID);
};


enum CHAP_ENUM
{
	CHAP_DATA_TYPE = 1,
	CHAP_DESIGN_PATTERN,
};


struct reader  
{
private:
	virtualChap* pc;		// ��ǰ�鿴���½ڡ�

	reader();

public:
	static reader* getInstance();

	~reader() noexcept;

	void showChapList();

	void selectChap(const CHAP_ENUM ch);

	void selectMol(const int molEnum);

	void runTest(const unsigned testID);
};



