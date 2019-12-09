
// https://www.hackerrank.com/challenges/simple-text-editor/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
/*                IN
8
1 abc
3 3
2 3
1 xy
3 2
4
4
3 1
*/
/*                OUT
c
y
a
*/

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0;
    cin >> n;
    string s;
    stack< string > cache;   

    for( int i = 0; i < n ; i++)
    {
        int opt = 0;
        cin >> opt;
        switch ( opt )
        {
            case 1:
            {                
                string tmp;
                cin >> tmp;
                cache.push( s );
                s = s + tmp;                              
                break;
            }
            case 2:
            {                      
                int k = 0;
                cin >> k; 
                cache.push( s );
                s.erase( s.size()-k, k );                       
                break;
            }
            case 3:
            {
                int k = 0;
                cin >> k;
                if ( s.size() != 0 )
                    cout << s.at(k-1) << endl;
                break;
            }
            case 4:
            {   
                if ( cache.empty() == false )
                {
                    string s_stored = cache.top();
                    cache.pop();
                    s = s_stored;
                }
                break;
                
            }
        }
    }
    return 0;
}
