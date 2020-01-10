#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <list>

using namespace std;

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}

// Implements a pair class of two integers
// it should be used mostly because of performance issues
template<typename T, typename S>
class mPair
{
	public:
	mPair(T& one, S& two ):first(one),second(two){};
	mPair( const mPair& pd)
	{
		this->first = pd.first;
		this->second = pd.second;

	};

	mPair& operator=( const mPair& pd )
	{
		this->first = pd.first;
		this->second = pd.second;
		return *this;
	};

	mPair( mPair&& pd)
	{
		this->first = pd.first;
		this->second = pd.second;
		pd.first = 0;
		pd.second = 0;

	};

	mPair& operator=( mPair&& pd )
	{
		this->first = pd.first;
		this->second = pd.second;
		pd.first = 0;
		pd.second = 0;
		return *this;
	};

	friend bool operator==( const mPair& p1, const mPair& p2 )
	{
		if  ( p1.first == p2.first)
			if ( p1.second == p2.second)
				return true;
		return false;   
	}

	friend bool operator!=( const mPair& p1, const mPair& p2 )
	{
		return ( p1.first != p2.first );
	}

	T first;
	S second;
};

typedef mPair<int,int> PairDerived;


class LRUCache 
{
public:
    LRUCache( int cap ):cap(cap)
    {
    };

    ~LRUCache()
    {

    }

    inline void set( int key, int value)
    {                   
        if ( !(l.size() < cap ) )
        {
            PairDerived p(key,value);
            auto it = _find( l.begin(), l.end(), p );

            if (  it == l.end())
            {
                l.pop_back();                
            }
            else
            {
                l.erase(it);                              
            }        
        }

        l.emplace(l.begin(), key,value);
        
    }

    inline int get( int key )
    {
        return _get( key, l.begin() );
    }

    inline int _get( int& key, list< PairDerived >::iterator it )
    {
        if ( it == l.end())
            return -1;

        if ( key == it->first )
            return it->second;

        it++;
        return _get(key, it );
    }

private:
    size_t cap;
    list< PairDerived > l; 

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
