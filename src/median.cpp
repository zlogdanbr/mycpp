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
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef multiset<long long> mset_long;
typedef high_resolution_clock::time_point tp;


// starts computing the execution time of a code
inline
const tp start_tracking()
{
	return high_resolution_clock::now(); 
}

// stops  computing the execution time of a code and print 
// elapsed time
inline
double end_tracking( tp& start, int opt=0 )
{
	auto stop = high_resolution_clock::now(); 
	if (opt != 0 )
	{
		auto duration = duration_cast<seconds>(stop - start);    
		return (duration.count());
	}
	else
	{
		auto duration = duration_cast<microseconds>(stop - start);    
		return (duration.count());
	}
}
	
#define _TIME_EXEC
	
class Median
{
public:

#ifdef _TIME_EXEC

	Median()
	{		
		t_exec_algo1 = 0;
		t_exec_algo2 = 0;
		t_exec_algo3 = 0;
		cnt    = 1;
	}

	~Median()
	{	
		print();	
	}	
		
	inline void print()
	{
		cout << "Average time adding: 			 : " << fixed << setprecision(6) << t_exec_algo1/cnt << " microseconds\n";
		cout << "Average time deleting			 : " << fixed << setprecision(6) << t_exec_algo2/cnt << " microseconds\n";
		cout << "Average time balancing			 : " << fixed << setprecision(6) << t_exec_algo3/cnt << " microseconds\n";
	}
	
	inline
	void printme()
	{	
		
		out << "Left:" << endl;
		out << "[";
		for( const auto v: mysetl )
			out << v << " ";
		out << "]\n";
		
		out << "Right:" << endl;
		out << "[";
		for( const auto v: mysetr )
			out << v << " ";
		out << "]\n";
	}


#endif	
    
	void pr()
	{
		cout << out.str() ;
	}
	
    void median( char& cmd,  long long& value) 
    { 
		if ( cmd == 'a')
		{
			
#ifdef _TIME_EXEC			
			auto t = start_tracking();			
			add_value( value );			
			t_exec_algo1 = t_exec_algo1 + end_tracking(t);
#else
			add_value( value );	
#endif
		
		}
		else
		{ 
#ifdef _TIME_EXEC	
			auto t = start_tracking();	
			if ( delete_value(value) < 0 )
			{                          
				out << "Wrong!" << "\n" ;			
				t_exec_algo2 = t_exec_algo2 + end_tracking(t);			
				return;
			}				
					
			t_exec_algo2 = t_exec_algo2 + end_tracking(t);
#else
			if ( delete_value(value) < 0 )
			{                          
				out << "Wrong!" << "\n" ;						
				return;
			}				
#endif	
		} 
		
		
#ifdef _TIME_EXEC
		auto t = start_tracking();	
		balance_halfs();		
		t_exec_algo3 = t_exec_algo3 + end_tracking(t);			
		printmedian(calculateMedian()); 	
		cnt++;
#else
		balance_halfs();				
		printmedian(calculateMedian()); 
#endif	

    }    

private:

    inline void printmedian( double __median) 
    {
        if ( __median == (long long)__median)
            out << static_cast<long long>(__median) << "\n";
        else
            out << fixed << setprecision(1) << __median << "\n";
    }

    inline double ComputeLargeAverage( const long long& a, const long long& b) 
    {
        //return static_cast<double>( 0.5*(a+b) );
		return  0.5*(a+b);
    }

    inline int sl() const
    {
        return mysetl.size();
    }

    inline int sr() const
    {
        return mysetr.size();
    }
    
    inline 
    double calculateMedian()
    {
        int left_size = sl();
        int right_size = sr();

        if ( left_size == right_size )
        {
            return  ComputeLargeAverage( *prev( mysetl.end() ), *mysetr.begin() );
        }
        else
        if ( left_size < right_size )
        {
            return *mysetr.begin();
        }
        else
        {
            return *prev( mysetl.end() );
        }           
    }    
	   
    inline 
    bool _find_Del(mset_long& cont, mset_long::iterator first, mset_long::iterator last, ll val)
    {
        while (first!=last && *first != val) ++first;
        if ( first == last )
            return false;
        cont.erase(first);
        return true;
    }
	
    inline
    void balance_halfs()
    {
     
        if ( sl() == sr() || abs( sl()-sr() ) == 1  )
            return; 
           
        if ( sl() < sr() )
        {
            ll tmp = *mysetr.begin();
            mysetr.erase( mysetr.begin() );
            mysetl.emplace( tmp );
            
        }
        else if ( sl() > sr() )
        {
            ll tmp = *prev( mysetl.end() );
            mysetl.erase( prev( mysetl.end()) );
            mysetr.emplace( tmp );
        }

        balance_halfs();
            
    }
	
    inline
    int delete_value( const ll& v)
    {
        
        if ( mysetl.empty() == true && mysetr.empty() == true )
            return -1;
        
        if ( v <  *mysetl.begin() )
            return -1;
	
        
        if ( v <= *prev(mysetl.end() ) )
        {
            if ( _find_Del( mysetl, mysetl.begin(), mysetl.end(), v ) == false )
                return -1;
        }
        else
        {
            if ( _find_Del( mysetr, mysetr.begin(), mysetr.end(), v ) == false )
                return -1;
        }
        
        if ( mysetl.empty() == true && mysetr.empty() == true )
            return -1;
        
        return 0;
            
    }

	inline
    void add_value( const ll& v)
    {
        if ( mysetl.empty() == true && mysetr.empty() == true )
        {
            mysetl.emplace(v);
        }
        else
        if ( mysetr.empty() == true && mysetl.size() == 1 )
        {
            mysetr.emplace(v);
        }
        else
        {
            if ( v <= *prev( mysetl.end()) )
                mysetl.emplace(v);
            else
                mysetr.emplace(v);           
        }
        
        if ( sl() == 1 && sr() == 1 )
        {
            if (  *mysetr.begin() < *mysetl.begin() )
            {
                mysetr.swap( mysetl );
            }
        }
    }
    
    mset_long mysetl;
    mset_long mysetr;
	stringstream out;
	
#ifdef _TIME_EXEC	
	double t_exec_algo1;
	double t_exec_algo2;
	double t_exec_algo3;
	int cnt;
#endif	

};    


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


    
int main(void){

    //Helpers for input and output
        //Helpers for input and output
    ios::sync_with_stdio(0);
    cin.tie(0);
		
    int N;
    cin >> N;
    
    char temp;
    long long tempint;
	Median m;

#ifdef _TIME_EXEC			
	auto t = start_tracking();
#endif	
	
    for(int i = 0; i < N; i++)
	{
        cin >> temp >> tempint;
        m.median( temp, tempint );
    }

#ifdef _TIME_EXEC		
	double t1 = end_tracking(t,1);
#endif	

	m.pr();
	
#ifdef _TIME_EXEC	
	cout << "it took " << t1  << " seconds to execute the algo" << endl;
#endif	

    return 0;
}
