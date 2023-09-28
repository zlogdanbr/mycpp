#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <tuple>

class B
{
public:
	B()
	{
		ptr = new char[ 2000 ] ;
		std::cout << "Calling B Constructor" << "\n";
	}
	
	~B()
	{
		std::cout << "Calling B destructor" << "\n";
		delete [] ptr;
	}

	void dostuff() const
	{
		std::cout << "Calling B Do " << "\n";
	}		
	
	char* ptr;	
};

class A
{
public:
	A()	
	{ 
		std::cout << "Calling A Constructor" << "\n";
		_b = new B();
		allocate_me();
	}
	~A()	
	{ 
		std::cout << "Calling A destructor" << "\n";
		delete _b;
	}
	
	void dostuff() const
	{
		std::cout << "Calling A Do " << "\n";
		_b->dostuff();
	}
	
	void allocate_me()
	{
		for( int i = 0; i < 2 ; i++)
		{
			v.emplace_back( new B);
		}
	}
	
	B* _b;
	std::vector<B*> v;
		
};

void test()
{
	std::vector<A*> Vptr;
	
	for(int i = 0 ; i < 2; i++ )	
	{
		Vptr.push_back( new A );
	}
	
	Vptr.push_back(nullptr);
	
	for( auto& it : Vptr )
	{
		delete it;
	}
}

void test2()
{
	std::unique_ptr<A> ptra{ new A{} };
	ptra.reset();
	ptra->dostuff();
	
}

void test3()
{
	std::unique_ptr<A> ptra{ new A{} };

}

void foo()
{
	
}

template<typename... Args>
void Format( char* ptr , Args&&... args)
{
	// return (BoostWMessageFormatter(format) % ... % args).ToString();

	std::cout << ( args + ... )  << ptr << "\n";
}

void test4() 
{
	int a = 0;
	int b = 1;
	int c = 2;
	char* ptr = "Hello world!";
	
	Format( ptr, a, b, c );
}

int main()
{

}
