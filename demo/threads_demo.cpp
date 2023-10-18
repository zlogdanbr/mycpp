#include <iostream>
#include <mutex> 
#include "util.h"
#include <chrono>

using namespace mytools::util;

// this is a c++ thread wrapper pool
using  myThreads = std::vector< std::thread >;

class ThreadPool
{
public:
	ThreadPool()
	{
		NumberOfCrtThreads = 0;
		alljoined = false;
	}

	~ThreadPool()
	{
		if (alljoined == false)
		{
			Join();
		}
	}

	// f function is the actual execution thread code
	void Add(std::thread& t)
	{
		NumberOfCrtThreads++;
		// you need to move t 
		ThreadDataPool.push_back(std::move(t));
	}

	void Join()
	{
		for (auto& t : ThreadDataPool)
		{
			t.join();
		}

		ThreadDataPool.clear();
		alljoined = true;

	}
	int GetNumberOfCrtThreads()const { return NumberOfCrtThreads; };
private:
	myThreads ThreadDataPool;
	int NumberOfCrtThreads;
	bool alljoined;
};

class D
{
public:
	int a;
	void jaca(){std::cout << "running jaca: " << a << std::endl;};
	bool pog = true;
};


D d;

	
void foo1()
{
	std::mutex mymutex;	
	std::cout << "foo1" << std::endl;
	mymutex.lock();
	bool f = d.pog ;
	mymutex.unlock();
	while(f)
	{
		mymutex.lock();
		d.a++;	
		mymutex.unlock();
		mymutex.lock();
		f = d.pog ;
		mymutex.unlock();	
		this_thread::sleep_for(chrono::milliseconds(50));		
	}
	
}

void foo2()
{
	std::mutex mymutex;	
	std::cout << "foo2" << std::endl;
	
	mymutex.lock();
	bool f = d.pog ;
	mymutex.unlock();
	while(f)
	{
		mymutex.lock();
		d.a++;	
		mymutex.unlock();		
		mymutex.lock();
		f = d.pog ;
		mymutex.unlock();	
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	
}

void foo3()
{
	this_thread::sleep_for(chrono::milliseconds(5000));
	d.pog = false;
}

int main()
{
	ThreadPool mts;
	d.a = 0;
	
	std::thread t1{foo1};
	std::thread t2{foo2};
	std::thread t3{foo3};
	
	mts.Add(t1);
	mts.Add(t2);
	mts.Add(t3);
	

		
	mts.Join();
	
	d.jaca();
	
}
