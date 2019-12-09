// https://www.hackerrank.com/challenges/abstract-classes-polymorphism/copy-from/133478012
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <list>

using namespace std;

void pr( const list<pair<int,int>>& m )
{
    for( const auto& im: m )
    {
        cout << "[" << im.first << "," << im.second << "]" << " ";
    }
    cout << "\n";  
}

// from Bjarne Stroustrup The Pratice Of Programming
template<typename In, typename T>
inline In _find(In first, In last, const T& val)
{
    while (first!=last && *first != val) ++first;
        return first;
}

class PairDerived
{
public:
    PairDerived(int& one, int& two ):first(one),second(two){};
    PairDerived( const PairDerived& pd)
    {
        this->first = pd.first;
        this->second = pd.second;

    };
    PairDerived& operator=( const PairDerived& pd )
    {
        this->first = pd.first;
        this->second = pd.second;
        return *this;
    };

    friend bool operator==( const PairDerived& p1, const PairDerived& p2 )
    {
        if  ( p1.first == p2.first)
            if ( p1.second == p2.second)
                return true;
        return false;   
    }

    friend bool operator!=( const PairDerived& p1, const PairDerived& p2 )
    {
        return ( p1.first != p2.first );
    }

    int first;
    int second;
};


class LRUCache 
{
public:
    LRUCache( int cap ):cap(cap)
    {
        _full = false;
    };

    ~LRUCache()
    {

    }

    inline void set( int key, int value)
    {
        if ( _full == false )
        {
            if ( !(l.size() < cap ))
                _full = true;
        }
                        
        if ( _full == true )
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
        for( const auto& it: l)
            if ( key == it.first )
                return it.second;
        return -1;
    }

private:
    int cap;
    list< PairDerived > l;
    bool _full;  

};

int main() {
