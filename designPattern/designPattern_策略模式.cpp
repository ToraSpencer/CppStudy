#include <string>
#include<iostream>

#include <map>
#include <cstdio>

using namespace std;



/*
	�͹���ģʽ������
			�������ڣ��ڲ��Ե����ߺͲ���֮�����һ�����㡪�����Խӿ���strategy��
			���Եĵ�������ͳһ����ʽ�������Ե�����ʹ��strategyָ�룬��ָ���Ƕ�̬�ģ�����Ҫ��ָ������ĸ�����ʵ����
			���Ա������ǲ��Թ�����Ķ��󣬼̳���strategy�ӿڣ�������㷨���붼��װ���෽���С��������Ժܷ������չ�����µĲ�����Ҫ����Ļ���ֻ��Ҫ�̳�strategy�ӿ�����һ������Ϳ����ˡ�

*/

namespace STRATEGY_PATTERN_AS1
{
	enum language { english, chinese };

	class welcomeScreen				// չʾ��ӭ��Ļ�������Խӿ�
	{
	public:
		virtual void welcome() = 0;
	};

	class welcomeEng : public welcomeScreen				// չʾӢ�Ļ�ӭ��Ļ�������Թ�����
	{
		virtual void welcome() override
		{
			cout << "nothing is impossible!" << endl;
		}

	};

	class welcomeChi : public welcomeScreen				// չʾ���Ļ�ӭ��Ļ�������Թ�����
	{
		virtual void welcome() override
		{
			cout << "����" << endl;
		}
	};

	class television		
	{
	private:
		welcomeScreen* pw;
		television() = default;					// �����޲ι��죬ʵ����һ��telivision��ʱ�����ָ�����ԡ�


	public:

		television(welcomeScreen* pw0) : pw(pw0) {}
		~television()
		{
			delete this->pw;
		}

		void showWelcome()
		{
			this->pw->welcome();
		}

		void setLanguage(language lan)
		{
			switch (lan)
			{
			case english:
				delete this->pw;
				this->pw = new welcomeEng();
				break;

			case chinese:
				delete this->pw;
				this->pw = new welcomeChi();
				break;


			};
		}

	};
}



// test1�����Բ���ģʽӦ�ó���1
static void test1() 
{
	using namespace STRATEGY_PATTERN_AS1;

	welcomeScreen* pws = nullptr;
	pws = new welcomeChi();

	television tl(pws);			// telivision�ǲ��Ե����ߡ�
	tl.showWelcome();

	tl.setLanguage(english);
	tl.showWelcome();



}

