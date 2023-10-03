#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <utility>
#include <iomanip>
#include "util.h"

using namespace mytools::util;
using namespace mytools::mymath;

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

template<typename N, typename M>
void getTuple( std::tuple<N,M>& _mytuple)
{
	for( const auto& it: std::get<0>(_mytuple) )
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::get<1>(_mytuple) << std::endl;
}

void test5()
{
	std::vector<int> v{1,2,3};
	std::string a{"Hello world"};
	std::tuple<std::vector<int>,std::string> t(v,a);
	getTuple<std::vector<int>,std::string>(t);
	
}

using namespace std;

// https://learn.microsoft.com/en-us/cpp/cpp/decltype-cpp?view=msvc-170
template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) ->decltype(forward<T1>(t1) + forward<T2>(t2))
{
   return forward<T1>(t1) + forward<T2>(t2);
}

int main()
{
	vector<vector<double>> data1  	{{1,1, 1},
									{1, 1, 1},
									{1, 1, 1}};
							
	vector<vector<double>> data2  	{{2, 2, 2},
									{2, 2, 2},
									{2, 2, 2}};
									
	Dmatrix<double> d1{data1,3,3};
	Dmatrix<double> d2{data2,3,3};
	std::cout << Plus(d1,d2);
   
}
