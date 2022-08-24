#include "util.h"

using namespace std;


unordered_set<string> generateAllSub(string& mys )
{
	unordered_set<string> ms;
	// Complexity O(n2) double loop
	for( size_t i = 0; i < mys.size(); i++ )
	{
		for( size_t j = 1; j < mys.size() + 1; j++ )
		{
			string tmp = mys.substr(i,j);			
			ms.insert(tmp);
		}
	}
	
	return ms;
}

// Complexity O(n2)
queue<string> generateAllSub2(string& mys )
{
	queue<string> ms;
	// Complexity O(n2) double loop
	for( size_t i = 0; i < mys.size(); i++ )
	{
		for( size_t j = 1; j < mys.size() + 1; j++ )
		{
			string tmp = mys.substr(i,j);			
			ms.push(tmp);
		}
	}
	
	return ms;
}

string twoStrings(string&& s1, string&& s2) 
{
	queue<string> ms1 = generateAllSub2(s1);
	unordered_set<string> ms2 = generateAllSub(s2);
	
	while ( ms1.size() > 0 )
	{
		auto f = ms1.front();
		if ( ms2.find( f ) != ms2.end() )
			return "YES";
		ms1.pop();
	}
	return "NO";
}

int main()
{	
	cout << twoStrings("hackerrankcommunity", "cdecdecdecde")  << endl;	
}
