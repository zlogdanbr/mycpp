#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include "util.h"

using namespace mytools::algo;
using namespace mytools::unittest;

int calc2(const std::vector<std::string>& input)
{	
	// 1 2 3 6 
	// 1 2 3 5
	std::stack<int> out;
	for( const auto& command: input )
	{
		if ( command == "D" )
		{
			out.push( out.top()*2);
		}
		else
		if ( command == "C" )
		{
			if ( out.empty() == false )
			{
				out.pop();
			}
		}
		else
		if ( command == "+")
		{
			int s  = sumtlastwo(out);
			out.push(s);
		}
		else
		{
			int n = stoi(command);	
			out.push(n);
		}
	}
	
	//printstack(out);
	return sumALLstack(out);
	
	
}

// D dobra o ultimo
// + soma os dois ultimos
// C cancela e apaga o ultimo
//strings de numeros convertidos em  ints
// saida é a soma final de todos os elementos
void RunTest2() noexcept
{
	std::vector<std::string> input1{"1","2","3","D","C","+"};
	std::vector<std::string> input2{"1","2","D","D","C","+"};
	// 1 2 4 6
	std::vector<std::vector<std::string>> in;

	std::vector<int> results{11,13};
	
	in.push_back(input1);
	in.push_back(input2);
	
	UnitTesting<std::vector<std::string>,int>(in,results,calc2);
}

int main()
{
	RunTest2();
}
