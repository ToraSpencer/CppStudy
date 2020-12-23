#include <string>
#include<iostream>

#include <cstdio>

using namespace std;


// ����ģʽ
/*
	Ӧ�ó�����
	����ϵͳ�е������������Ӧ���ǵ����ģ����������ж�������������task manager��ʵ����
	����������ĳЩ����ҲӦ���ǵ����ģ������ĵ��༭���Ĺ����䣬��ɫ���ô��ڵȵȡ�


*/



// �򵥵��̲߳���ȫ�ĵ���ģʽ��
namespace SIMPLE_SINGLETON		
{
	class taskManager
	{
	private:
		static taskManager* tm_instance;		// Ψһʵ��������ʵ������ڶ��ϡ�
		taskManager() = default;						// ���캯������Ϊ˽�еġ�
		taskManager(const taskManager&) {}				// �����д�Ļ����������public��Ĭ�Ͽ������캯�����ⲿ���Խ��п������졣
		~taskManager() = default;						// ͬ�ϡ�

	public:
		static taskManager* getInstance()
		{
			if (nullptr == tm_instance)
			{
				tm_instance = new taskManager;
				cout << "������һ�����������ʵ����" << endl;

			}
			else
			{
				cout << "�������������ʵ����������ָ�롣" << endl;
			}

			return tm_instance;
		}

	};
	taskManager* taskManager::tm_instance = nullptr;		// ��ʼ��Ϊ��ָ�롣
}



// meyer's singleton����һ�ּ���������̰߳�ȫ�ĵ���ģʽ
namespace MEYERS_SINGLETON				
{
	class taskManager
	{
	private:
		taskManager() = default;
		taskManager(const taskManager&) {}
		~taskManager() = default;

	public:
		static taskManager& getInstance()		// ע�ⷵ�ص�������
		{
			static taskManager tm_instance;		// �����ڵ�static��������������һ�ε���ʱ�����ñ�����������ջ�����Ҳ���ͷţ�
												//		�ظ����ú��������ظ����������Һ����ڵ�static�������̰߳�ȫ�ġ�
			return tm_instance;
		}

	};

}


