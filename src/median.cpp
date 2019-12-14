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
/* Head ends here */

template<typename T>
inline
bool isEven( T& n )
{
    return ( n % 2 == 0);
}

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}

inline double ComputeLargeAverage( const long long& a, const long long& b)
{
    return (double)( (a+b)/(double)2 );
}

template <typename T>
inline
double calculateMedian( T& _MySetContainer)
{
    
    int size =  _MySetContainer.size();    
        
    if ( isEven( size ) )     
    {
        auto it  = _MySetContainer.begin();
        for(int i = 0; i < (size/2); i++,it=next(it));  
        return ComputeLargeAverage( (*it), *(prev(it)) ) ;            
    }
    else
    {                            
        if ( size > 1 )
        {
            auto it = _MySetContainer.begin();           
            for( int i = 0; i < (size+1)/2; i++,it=next(it));          
            return (double)*(prev(it));
        }
        else
            return(double)(*_MySetContainer.begin());             
    }
}

inline void printmedian( double __median )
{
    if ( __median == (long long)__median)
        cout << static_cast<long long>(__median) << endl;
    else
        cout << fixed << setprecision(1) << __median << endl;
}

void median( vector<char> s, vector<long long> X) 
{
    multiset<long long> myset;
    auto vit = X.begin();

    for( const auto& cmd: s )   
    {
        if ( cmd == 'a')
        {  
            myset.emplace(*vit);
            printmedian( calculateMedian(myset));       
        }
        //else if ( cmd == 'r')
        else
        {  
            if  ( myset.size() == 0 )
            {
                cout << "Wrong!" << endl;
                vit++;                   
                continue;
            };
        
            auto fit = _find(myset.begin(), myset.end(), *vit);
            if (  fit == myset.end() )
            {
                cout << "Wrong!" << endl;
                vit++;  
                continue;
            }
            else
            {
                myset.erase(fit);                        
                if ( myset.size() != 0 )
                    printmedian(calculateMedian(myset));
                else
                    cout << "Wrong!" << endl;
            }                  
        }        
        vit++;
    }
}

    
int main(void){

    //Helpers for input and output

    long long N;
    cin >> N;
    
    vector<char> s;
    vector<long long> X;
    char temp;
    long long tempint;
    for(long long i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }
    
    median(s,X);
    return 0;
}

