#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define _DEBUG

/*
Sample Input

5 3
1 2 100
2 5 100
3 4 100

Sample Output

200


1000000000 3
1 2 100
2 5 100
3 4 100

*/

typedef high_resolution_clock::time_point tp;

inline
const tp start_tracking()
{
    return high_resolution_clock::now(); 
}

inline
void end_tracking( tp& start, const char* msg )
{
    cout << "________________________________________" << endl;
    cout << msg << endl;
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);    
    cout << "Execution timing:" << duration.count() << endl; 
    cout << "________________________________________" << endl;
}

inline void calcmax( vector<long long>& m, long long& max, int& op, int& index )
{
    int a = 0;
    int b = 0;
	int c = 0;
    if ( index < op )
    {
        cin >> a;
        cin >> b;
		cin >> c;
		
        for( auto it = m.begin()+ a-1 ; it != m.begin()+ b; it++ )  
        {				
            *it = *it+c;
            if ( *it > max ) max = *it;
        } 

        index++;
        calcmax( m, max, op, index );
    } 
    
    return;

}

int main()
{
    int n  = 0 ;
    int op  = 0;

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> op;
    cin.ignore();
    
    vector<long long> m(n,0);
    long long max = 0;
    int i = 0;
	
	auto t = start_tracking();
    calcmax( m, max, op, i);   
    cout << max << endl;
	end_tracking( t, "End" );
   
}
