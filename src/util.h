#include "util.h"

using namespace _dutil_;
using namespace _dutil_::_other_util;



void testcase(int N, int pos )
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


	algo::List<std::string> l;

	l.push("itemxxxxxxxx");
	l.push("itemyy");
	l.push("itemz");

	cout << "Elements: " << endl;


	for ( algo::iterator<std::string> it = l.begin(); it.crt != l.end().crt; it.crt = it.crt->next)
	{
		std::cout << it.crt->v << std::endl;
	}

}

int main()
{
	testcase4();
}
