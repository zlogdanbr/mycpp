#include <iostream>
#include <mutex> 
#include "util.h"

using namespace mytools::util;


template<typename T>
struct mydata
{
	T a;
	std::mutex mymutex;
};

mydata<int> d;

void foo1()
{
	d.mymutex.lock();
	std::cout << "foo1" << std::endl;
	d.a++;
	std::cout << d.a << std::endl;
	d.mymutex.unlock();
}

void foo2()
{
	d.mymutex.lock();
	std::cout << "foo2" << std::endl;
	d.a++;
	std::cout << d.a << std::endl;	
	d.mymutex.unlock();
}

int main()
{
	ThreadWrapper mts;
	mts.AddAndRun(foo1);
	mts.AddAndRun(foo2);
	mts.Join();
	
}
