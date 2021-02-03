#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>


#include <iostream>
#include <string>
#include <typeinfo>

#include <cstdio>
#include "stdlib_线程支持库.h"

#define EPS 1e-10								//定义非常小的一个量EPSilon，当浮点数不大于这个值时，视为0
#define PI 3.14159



// C++标准库——线程支持库
/*
**			(C++11 起)<thread> 												std::thread 类及支持函数
**			(C++20 起)<stop_token> 										std::jthread 的停止记号
**			(C++11 起)<mutex> 												互斥原语
**			(C++14 起)<shared_mutex> 									共享的互斥原语
**			 (C++11 起)<future>	 											异步计算的原语
**			(C++11 起)<condition_variable> 						 	线程等待条件
**			 (C++20 起)<semaphore> 										信号量
**			 (C++20 起)<latch>	 												闩
**			 (C++20 起)<barrier>	 											屏障
**
**
*/


// 进程
/*
	进程组成：
			1.程序
			2.数据
			3.进程控制块(PCB)

*/


// 线程
/*
	线程是进程中的一个实体，是被系统独立分配和调度的基本单位。
	也有说，线程是CPU可执行调度的最小单位。
	也就是说，进程本身并不能获取CPU时间，只有它的线程才可以。

	线程、进程的比较
			线程参与操作系统的调度，参与CPU的竞争，得到分配的时间片，获得处理机（CPU）运行。
			而进程负责获取操作系统分配的资源，如内存。


*/


virtualModule* stdlib_thread_support_module::getInstance()		// 线程不安全的单例模式
{
	if (nullptr != p_moduleIns)
	{
		delete p_moduleIns;
	}
	p_moduleIns = new stdlib_thread_support_module;
	return p_moduleIns;
}



void stdlib_thread_support_module::test0(void)
{

}


// test1： <ctime>——C风格的时间、日期工具。
void stdlib_thread_support_module::test1(void)
{}


// test2:
void stdlib_thread_support_module::test2(void)
{
	using namespace std::chrono;

	//循环1：
	auto start = system_clock::now();

	long int num = 10000000;
	for (int i = 0; i != num; i++)
	{
		int* b = new int[10]();
		delete[] b;
	}

	auto end = system_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	std::cout << "程序1花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "秒" << std::endl;


	//循环2
	start = system_clock::now();

	int num2 = num >> 1;
	for (int i = 0; i != num2; i++) {
		int* b = new int[10]();
		delete[] b;
	}
	for (int i = num2; i != num; i++) {
		int* b = new int[10]();
		delete[] b;
	}

	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	std::cout << "程序2花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "秒" << std::endl;

	//循环3
	start = system_clock::now();

	//testfuc2(num);

	end = system_clock::now();
	duration = duration_cast<microseconds>(end - start);
	std::cout << "程序3花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den << "秒" << std::endl;


}


void stdlib_thread_support_module::test3(void)
{}



void stdlib_thread_support_module::test4(void)
{}



void stdlib_thread_support_module::test5(void)
{}


void stdlib_thread_support_module::test6(void) {}