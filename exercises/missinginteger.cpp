#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

/**
 *  
 *  Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].


Compilation successful.

Example test:   [1, 3, 6, 4, 1, 2]
OK

Example test:   [1, 2, 3]
WRONG ANSWER (got 1 expected 4)

Example test:   [-1, -3]
OK

 */

template<typename T>
void print1D( const std::vector<T>& vec )
{
    for( const auto& v: vec )
    {
        std::cout << v;
    }
    std::cout << "\n";
}

void DEBUG( std::vector<int> &A)
{
	print1D(A);
	std::cout << "first: " << *A.begin() << std::endl;
	std::cout << "Last : " << *A.rbegin() << std::endl;
}

int solution(std::vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)

    sort( A.begin(), A.end());
	
	//DEBUG(A);
    auto last = *A.rbegin();
	
	if ( last <= 0 )
		return 1;
	
	int i = 1;
	
    for( ; i < last; i++ )
    {
        if  ( std::binary_search( A.begin(), A.end(), i ) == false )
        {
            return i;
        }
    }

    return i+1;

}


int main()
{
	std::vector<int> in1{1, 3, 6, 4, 1, 2};
	std::vector<int> in2{1, 2, 3};
	std::vector<int> in3{-1, -3};
	
	std::cout << solution(in1) << std::endl;
	std::cout << solution(in2) << std::endl;
	std::cout << solution(in3) << std::endl;
	
}