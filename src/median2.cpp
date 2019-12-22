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
mset_long mysetl;
mset_long mysetr;   

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

inline void pr( const multiset<long long>& _set_ )
{
    if ( _set_.empty() == true )
    {
        cout << "[nullptr]" << "\n";
    }
    else
    {
        cout << "[ ";
        for( const auto& s : _set_ )
            cout << s << " ";
        cout << "]\n";
    }    
}

inline void Debug(const char* msg )
{
    cout << msg << endl;    
    pr( mysetl);
    pr( mysetr);
}

inline double ComputeLargeAverage( const long long& a, const long long& b)
{
    return static_cast<double>( 0.5*a + 0.5*b );
}

inline void printmedian( double __median )
{
    if ( __median == (long long)__median)
        cout << static_cast<long long>(__median) << "\n";
    else
        cout << fixed << setprecision(1) << __median << "\n";
}


inline int sl()
{
    return mysetl.size();
}

inline int sr()
{
    return mysetr.size();
}

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}

inline double calculateMedian()
{
    int left_size = sl();
    int right_size = sr();
    
    //  1 2 3    4 5 6
    //  1 2      3 4
    //  1        1
    if ( left_size == right_size )
    {
        return  ComputeLargeAverage( *prev( mysetl.end() ), *mysetr.begin() );
    }
    else
    //  1       3  4
    //  1 2 5   7  8  9 10
    // nullptr 1
    if ( left_size < right_size )
    {
        return *mysetr.begin();
    }
    else
    // 1 2 3 4  5 6 7
    // 1  nullptr
    {
        return *prev( mysetl.end() );
    }
        
}

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


int delete_value( const ll& v)
{
    
    if ( mysetl.empty() == true && mysetr.empty() == true )
        return -1;
    
    if ( v <= *prev(mysetl.end() ) )
    {
        auto fit = _find( mysetl.begin(), mysetl.end(), v );
        if ( fit == mysetl.end() )
            return -1;
        else
            mysetl.erase( fit );
    }
    else
    {
        auto fit = _find( mysetr.begin(), mysetr.end(), v );
        if ( fit == mysetr.end() )
            return -1;
        else
            mysetr.erase( fit );
    }
    
    if ( mysetl.empty() == true && mysetr.empty() == true )
        return -1;
    
    return 0;
        
}

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

void median( vector<char> s, vector<long long> X) 
{
    auto vit = X.cbegin();
    
    for( const auto& cmd: s )   
    { 
        if ( cmd == 'a')
        {          
            add_value( *vit );
            balance_halfs();           
            printmedian(calculateMedian());       
        }
        else
        {             
            if ( delete_value(*vit) < 0 )
            {                          
                cout << "Wrong!" << "\n" ;
                vit++;
                continue;
            }
            
            balance_halfs();               
            printmedian( calculateMedian() );
                
        }        
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
    return 0;
}

