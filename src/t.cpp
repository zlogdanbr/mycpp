#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <list>
using namespace std;

class LRUCache
{
public:

    LRUCache( int& capacity ):capacity(capacity)
    {

    };
        
    void set(int key, int value)
    {
        pair<int,int> p(key,value);
        auto it = find( l.begin(), l.end(), p);
        
        if ( it != l.end())
        {
            l.erase( it );
        }
        else
        {
            if ( l.size() >= capacity )
                l.pop_front();
        }
        l.push_back(p);
    }
    
    int get( int key )
    {
        auto it = l.cbegin();
        while( it != l.cend())
        {
            if ( it->first == key)
                return it->second;
            it++;
        }
        return -1;
    }

private:
    list<pair<int,int> > l;
    int capacity;
    int cnt;
    
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
