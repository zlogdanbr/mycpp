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

#define _DEBUG

/*

TEST CASE 1:
7
r 1
a 1
a 2
a 1
r 1
r 2
r 1

TEST CASE 2
6										
a -2147483648					
a -2147483648
a -2147483647
r -2147483648
a 2147483647
r -2147483648

OUTPUT
-2147483648
-2147483648
-2147483648
-2147483647.5
-2147483647
0

TEST CASE 3
3
a -2147483648
a -2147483648
a -2147483647


*/
template<typename T>
inline
bool isEven( T& n )
{
    return ( n % 2 == 0);
}

template <typename T>
inline 
void pr( const T& fv )
{
	if ( fv.size() == 0 )
	{
		cout << "[nullptr]" << endl;
		return;
	}
	
	int i = 0;
	for( auto f: fv )
	{
		cout << "f[" << i << "]= " << f << endl;
		i++;
	}

}

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}

template <typename T>
inline
float calculateMedian( T& orig)
{

	int size =  orig.size();	
		
    if ( isEven( size ) ) 	
	{
		orig.sort();
		auto it  = orig.begin();
		int i = 0;
		float n = 0;
		
#ifdef _DEBUG
		for(; i < (size/2); i++,it=next(it))
		{
			cout << "i: " << i << " *it: " << *it << " it->next:  " << *next(it) << endl;
		}
#else
		for(; i < (size/2); i++,it=next(it));
#endif		
		n = ( (float)(*it) + (float)*(prev(it)))/ (float)2;		
	    return (float)n ;			
	}
    else
	{							
		//  1 2 3 4 5
		int i = 0;
		float n = 0;
		if ( size > 1 )
		{
			orig.sort();
			auto it = orig.begin();
			
#ifdef _DEBUG
			for(; i < (size+1)/2; i++,it=next(it));
			{
				cout << "i: " << i << " *it: " << *it << " it->next:  " << *next(it) << endl;
			}
#else
			for(; i < (size+1)/2; i++,it=next(it));
#endif			
			n = (float)*(prev(it));
		}
		else
		{
			auto it = orig.begin();
			n = (float)(*it);
			i++;
		}
			
        return n;	
	}
}

inline void printmedian( float& __median, int precision )
{

	if ( __median == (int)__median)
	{

#ifdef _DEBUG
		cout << "Median actually calculated( integer )" << endl;
#endif
		cout << static_cast<int>(__median) << endl;
	}
	else
	{
#ifdef _DEBUG
		cout << "Median actually calculated(float)" << endl;
#endif
		cout << fixed << setprecision(precision) << __median << endl;
	}
}

void median( vector<char> s, vector<int> X) 
{
    list<int> myset;
    auto vit = X.begin();

    for( const auto& cmd: s )   
    {
        if ( cmd == 'a')
        {
			
#ifdef _DEBUG
			cout << "----------------------------------" << endl;
			cout << "Command to add " << *vit << endl;
			cout << "----------------------------------" << endl;
			cout << "Before adding:" << endl;		
			pr(myset);
#endif	
			myset.push_front(*vit);
			// if ( myset.size() < 2 )
				// myset.push_back(*vit);
			// else
				// myset.push_front(*vit);
			
#ifdef _DEBUG	
			cout << "After adding:" << endl;
			pr(myset);			
#endif
		    float m = calculateMedian(myset);
			printmedian(m,1);	
	
        }
        else if ( cmd == 'r')
        {
			
#ifdef _DEBUG
			cout << "----------------------------------" << endl;
			cout << "Command to remove: " << *vit << endl;
			cout << "----------------------------------" << endl;			
			cout << "Before delete:" << endl;
			pr(myset);
			cout << "Size is : " << myset.size() << endl;
#endif	

			if  ( myset.size() == 0 )
			{
				cout << "Wrong!" << endl;
				vit++;
				
#ifdef _DEBUG	
				cout << "After:" << endl;
				pr(myset);
#endif					
				continue;
			};
			
			//auto fit = find(myset.begin(), myset.end(), *vit);
			auto fit = _find(myset.begin(), myset.end(), *vit);
            if (  fit == myset.end() )
            {
                cout << "Wrong!" << endl;
				vit++;

#ifdef _DEBUG	
				cout << "After:" << endl;
				pr(myset);
#endif	
				continue;
            }
            else
            {
				myset.erase(fit);

#ifdef _DEBUG	
				cout << "After delete:" << endl;
				pr(myset);
#endif				
			
				if ( myset.size() != 0 )
				{					
					float m =  calculateMedian(myset);
					printmedian(m,1);
				}
				else
					cout << "Wrong!" << endl;
            }			
		
        }		
        vit++;
    }
}

    
int main(){

//Helpers for input and output

	int N;
	cin >> N;
	
	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	
	median(s,X);
	return 0;

}

