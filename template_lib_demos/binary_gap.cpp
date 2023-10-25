#include <iostream>
#include <sstream>
#include "util.h"
#include <bitset>

std::string convertobitstring(int n)
{
	std::stringstream ss;
	ss << std::bitset<32>(n);
	return ss.str();
}

void removeleadingzeroes( std::string& str )
{
	str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
}

int findgaps(std::string & s )
{
	int sum = 0;
	int sumax = 0;
	
#ifdef ___DEBUG	
	std::string v = "";
#endif	
	
	// 10001001001011100100
	for( const auto& c: s )
	{
		if ( c == '0' )
		{
			sum++;
		}
		else
		if ( sum > 0 && c == '1')
		{
			if ( sumax < sum )
			{
				sumax = sum;					
			}
			sum = 0;
		}
		
#ifdef ___DEBUG
		std::cout << "_________________________________________" << std::endl;
		v.push_back(c);
		std::cout << "string : " << v << std::endl;
		std::cout << "sumax  : " << sumax << std::endl;
		std::cout << "sum    : " << sum << std::endl;
#endif			

	}
	return sumax;
}

int solution(int N)
{
	auto s  = convertobitstring(N);
	removeleadingzeroes(s);
#ifdef ___DEBUG
	std::cout << s << std::endl;
#endif		
	return findgaps(s);
}

int main()
{
	std::cout << solution(561892) << std::endl;
}