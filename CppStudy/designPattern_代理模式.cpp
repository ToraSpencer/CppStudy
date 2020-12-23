#include <string>
#include<iostream>

#include <cstdio>

using namespace std;


// ����ģʽ(proxy pattern)Ӧ�ó���1�������������ͬ��ҵ���ϷȨ�ޡ�
namespace PROXY_PATTERN_AS1
{
	// ��Ϸ��ͨ������ģʽʵ�ֲ�ͬvip������ҵ�Ȩ�ޡ�


	//	��Ϸģʽ�Ľӿڡ���������ͬ����Ϸģʽ�����в�ͬ��Ȩ�ޣ��е�ģʽֻ��봽��û�������
	class play
	{
	public:
		virtual void play1() = 0;
		virtual void play2() = 0;
		virtual void play3() = 0;
	};


	// �����
	class player final : public play  							// final�ؼ��ֽ�ֹ�౻�̳У��ں�������������Խ�ֹ�ú��������ء�
	{
	public:
		player() = default;

		virtual void play1() override
		{
			cout << "��ͨ��Ϸģʽ����ѵ�" << endl;
		}


		virtual void play2() override
		{
			cout << "����ģʽ��vip�ſ��Խ���" << endl;
		}

		virtual void play3() override
		{
			cout << "����ģʽ���׽�vip���Խ���" << endl;
		}

	};


	// ��ͨ��Ҵ�����
	class proxyOrdinaryPlayer :public play
	{
	private:
		player* p_player;							// ��������������������������ǹ�����ϵ��

	public:
		virtual void play1() override
		{
			p_player->play1();
		}

		virtual void play2() override
		{
			cout << "��ͨ�û����ܽ������Ϸģʽ��" << endl;
		}

		virtual void play3() override
		{
			cout << "��ͨ�û����ܽ������Ϸģʽ��" << endl;
		}
	};


	// vip��Ҵ�����
	class proxyVIPplayer : public play
	{
	private:
		player* p_player;

	public:
		virtual void play1() override
		{
			p_player->play1();
		}

		virtual void play2() override
		{
			p_player->play2();
		}

		virtual void play3() override
		{
			cout << "ֻ�а׽�VIP�û����ܽ������Ϸģʽ��" << endl;
		}
	};

	// �׽���Ҵ�����
	class proxyPlatinicVIPplayer : public play
	{
	private:
		player* p_player;
	public:
		virtual void play1() override
		{
			p_player->play1();
		}

		virtual void play2() override
		{
			p_player->play2();
		}

		virtual void play3() override
		{
			p_player->play3();
		}

	};

}


// test0: ����ģʽ(proxy pattern)Ӧ�ó���1�������������ͬ��ҵ���ϷȨ�ޡ�
static void test0()
{
	PROXY_PATTERN_AS1::play* player123456 = nullptr;
	PROXY_PATTERN_AS1::play* player999988 = nullptr;
	PROXY_PATTERN_AS1::play* player112087 = nullptr;
	PROXY_PATTERN_AS1::play* player078990 = nullptr;
	PROXY_PATTERN_AS1::play* player098056 = nullptr;

	player123456 = new PROXY_PATTERN_AS1::proxyOrdinaryPlayer();
	player999988 = new PROXY_PATTERN_AS1::proxyOrdinaryPlayer();
	player112087 = new PROXY_PATTERN_AS1::proxyVIPplayer();
	player078990 = new PROXY_PATTERN_AS1::proxyVIPplayer();
	player098056 = new PROXY_PATTERN_AS1::proxyPlatinicVIPplayer();

	player123456->play1();
	player123456->play2();
	player123456->play3();
	player112087->play1();
	player112087->play2();
	player112087->play3();
	player098056->play3();




}

