#include "util.h"

using namespace std;

using namespace mytools::unittest;

void print( const unordered_set<string>& myset )
{
	for( const auto& s: myset )
		cout << s << " ";
	cout << "\n";
}

unordered_set<string> generateAllSub(string& mys )
{
	unordered_set<string> ms;
	string tmp = "";
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


string twoStrings(string&& s1, string&& s2) 
{
	unordered_set<string> ms1 = generateAllSub(s1);
	unordered_set<string> ms2 = generateAllSub(s2);
	
	auto& myrefbigger = ms1.size() >= ms2.size() ? ms1: ms2;
	auto& myrefsmallr = ms1.size() < ms2.size() ? ms1: ms2;
	
	for( auto it = myrefsmallr.begin(); it != myrefsmallr.end(); it++ )
	{	
		if ( myrefbigger.find( *it ) != myrefbigger.end() )
		{
			return "YES";
		}
	}

	return "NO";
}

int main()
{
	auto tp = start_tracking();
	cout << twoStrings("hackerrankcommunity", "cdecdecdecde")  << endl;
	end_tracking(tp);
}
