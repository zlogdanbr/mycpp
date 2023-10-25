#include "util.h"

using namespace mytools;
using namespace mytools::util;
using namespace mytools::unittest;
using namespace mytools::algo;


void testcase1(int N, int pos )
{
	cout << "-------------------------------------" << endl;
	cout << "N is " << N << endl;
	vector<int> v;
	
	cout << "Initializing data..." << endl;
	for( int i = 0; i < N ; i++ )
		v.push_back( rand() );
	
	cout << "Sorting data...";
	sort( v.begin(), v.end() );
	cout << "done." << endl;
		
	cout << "Searching using recursion...";
	auto t = start_tracking();
	if ( algo::binary_search_recursive<int>( v[pos], v.begin(), v.end() ) == true )
			cout << "found: " << v[pos] << endl;
	end_tracking(t);
	cout << "done." << endl;

	cout << "Searching  using STL...";
	t = start_tracking();
	if ( binary_search( v.begin() , v.end() , v[pos]) == true )
			cout << "found: " << v[pos] << endl;		
	end_tracking(t);
	cout << "done." << endl;	
	
	cout << "Searching  using STL Stroustrup...";
	t = start_tracking();
	if ( algo::_find( v.begin() , v.end() , v[pos] ) != v.end() )
			cout << "found: " << v[pos] << endl;		
	end_tracking(t);
	cout << "done." << endl;	
		
}

void testcase2(int N )
{
	cout << "-------------------------------------" << endl;
	cout << "N is " << N << endl;
	multiset<int> v;
	
	cout << "Initializing data..." << endl;
	for( int i = 0; i < N ; i++ )
		v.emplace( rand() );
	
	int pos = *prev(v.end());
	
	cout << "Searching  using STL binary search...";
	auto t = start_tracking();
	if ( binary_search( v.begin() , v.end() , pos ) == true )
			cout << "found: " << pos << endl;		
	end_tracking(t);
	cout << "done." << endl;	
	
	cout << "Searching  using my algo...";
	t = start_tracking();
	if ( algo::binary_search_recursive_set( pos, v.begin() , v.end() ) == true )
			cout << "found: " << pos << endl;		
	end_tracking(t);
	cout << "done." << endl;	
	
	cout << "Searching  using STL Stroustrup...";
	t = start_tracking();
	if ( algo::_find( v.begin() , v.end() , pos ) != v.end() )
			cout << "found: " << pos << endl;		
	end_tracking(t);
	cout << "done." << endl;	
	
	cout << "Searching  using STL ...";
	t = start_tracking();
	if ( find( v.begin() , v.end() , pos ) != v.end() )
			cout << "found: " << pos << endl;		
	end_tracking(t);
	cout << "done." << endl;				
}

void testcase3()
{
	multiset<int> v{ 1, 3, 4, 5 ,6 , 7, 8, 1000, 24 , 24, 56, -1 };
	if ( algo::binary_search_recursive_set( -1, v.begin() , v.end() ) == true )
			cout << "found: " << -1 << endl;		
}

void testcase4()
{


	algo::cllist<std::string> l;

	l.push("itemxxxxxxxx");
	l.push("itemyy");
	l.push("itemz");
	
	

	cout << "Elements: " << endl;
	for ( algo::iterator<std::string> it = l.begin(); it.crt != l.end().crt; it.crt = it.crt->next)
	{
		std::cout << it.crt->v << std::endl;
	}	

	l.pop();
	
	cout << "Elements: " << endl;
	for ( algo::iterator<std::string> it = l.begin(); it.crt != l.end().crt; it.crt = it.crt->next)
	{
		std::cout << it.crt->v << std::endl;
	}
	
	std::string s = "itemxxxxxxxx";
	std::string s2 = "itemxxasddddxxxxxx";
	

}

void testcase5()
{	
	mset_long s1{ -1 , -2, 	0, 		1, 3, 	3, 		5, 	6, 		8, 8 };
	mset_long s2{ 9  , 120, 320, 500, 1000, 1020, 1050, 1056, 2000, 4000, 7000, 10000, 7899000, 652777 };
	
	cout<< s1.size() << endl;
	algo::print_stlc(s1);
	cout<< s2.size() << endl; 	
	algo::print_stlc(s2);	
	
	algo::balance_halfs( s1, s2 );
	
	cout<< s1.size() << endl;
	algo::print_stlc(s1);
	cout<< s2.size() << endl; 	
	algo::print_stlc(s2);

}

void testcase6()
{


	algo::cllist<int> l;

	l.push(1);
	l.push(2);
	l.push(3);
	
	

	cout << "Elements: " << endl;
	for ( algo::iterator<int> it = l.begin(); it.crt != l.end().crt; it.crt = it.crt->next)
	{
		std::cout << it.crt->v << std::endl;
	}	

	l.pop();
	
	cout << "Elements: " << endl;
	for ( algo::iterator<int> it = l.begin(); it.crt != l.end().crt; it.crt = it.crt->next)
	{
		std::cout << it.crt->v << std::endl;
	}
	
	

}

int main()
{
	testcase2(20000000);
}
