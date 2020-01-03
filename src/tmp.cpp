#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef multiset<long long> mset_long;
  

//#define _DEBUG

/*
7  
r 1  
a 1  
a 2  
a 1  
r 1  
r 2  
r 1

8
a -2147483648
a -2147483648
a -2147483647
r -2147483648
a 2147483647
r -2147483648
a 10
a 10


-2147483648
-2147483648
-2147483648
-2147483647.5
-2147483647
0
10
10

7
a 1073741824
a 1073741822
a 1073741825
a 1073741821
a 1073741826
a 1073741820
a 1073741827


1073741824
1073741823
1073741824
1073741823
1073741824
1073741823
1073741824

*/

stringstream out;

inline double ComputeLargeAverage( const long long& a, const long long& b)
{
    return static_cast<double>( 0.5*(a+b) );
}

inline void printmedian( double __median )
{
    if ( __median == (long long)__median)
        cout << static_cast<long long>(__median) << "\n";
    else
        cout << fixed << setprecision(1) << __median << "\n";
}

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}


inline 
void pr( const multiset<ll>& t ) 
{
	out << "[ ";
	for( const auto& _el: t )
	{
		out << _el << " ";
	}
	out << "]\n";
}

inline
ll calculateMedian( mset_long& values )
{
	if ( values.size() == 1 )
		return *values.begin();

	auto range_length = std::distance(values.begin(), values.end());
	auto mid_element_index = std::floor(range_length / 2);
	auto it = values.begin();
	std::advance( it, -mid_element_index );
	
	if ( values.size()%2 == 0 )
		return ComputeLargeAverage( *it, *next(it) );
	
	return *it;
	
}

inline
int delete_value( const ll& v, mset_long& values)
{  

	if ( values.empty() == true )
		return -1;
	
	if ( binary_search( values.begin(), values.end(), v ) == true )
		values.erase( v );
	else
		return -1;

	if ( values.empty() == true )
		return -1;
	
    return 0;
        
}

inline
void add_value( const ll& v, mset_long& values)
{
	values.emplace( v );
}

inline
void median( vector<char> s, vector<long long> X) 
{
    auto vit = X.cbegin();
	mset_long v;
    
    for( const auto& cmd: s )   
    { 
		
        if ( cmd == 'a')
        {  
			out << "-------------------------------------------" << endl;
			out << "Before add" << endl;
			pr( v );
			
            add_value( *vit, v );          
			
			out << "After add" << endl;
			pr( v );
			
        }
        else
        {  
			out << "-------------------------------------------" << endl;
			out << "Before delete" << endl;
			pr( v );
			
            if ( delete_value(*vit,v) < 0 )
            {                          
                cout << "Wrong!" << "\n" ;
				out << "value not in set" << endl;
                vit++;
                continue;
            }

			out << "After delete" << endl;
			pr( v );
                                         
        } 
		
		auto m = calculateMedian(v);
		out << "Median: " <<  m << endl;
		printmedian(m); 
        vit++;
    }
}

    
int main(void){

    //Helpers for input and output

    int N;
    cin >> N;
    
    vector<char> s;
    vector<long long> X;
    char temp;
    long long tempint;
    for(int i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }
    
    median(s,X);
	cout << out.str();
    return 0;
}

