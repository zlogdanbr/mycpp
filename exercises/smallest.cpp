/*This is a demo task.

Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
Copyright 2009–2022 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <bitset>
#include <cmath>
#include <thread>
#include <mutex>

using namespace std;

void printme( vector<int>& V )
{
	for( const auto& v: V )
		cout << v << " ";
	cout << "\n";
}

int solution( vector<int>&& A )
{
	printme(A);
	sort( A.begin(), A.end());
	
	if ( *A.rend() <= 0 )
		return 1;
	
	if ( A.size() == 1 )
		return A[0];
	
	int j = 0;
	
	for( int i = 1 ; i <= *A.rend(); i++,j++ )
	{
		if ( binary_search( A.begin()+j, A.end(), i ) == false )
		{
			return i;
		}
	}
	return *A.rend()+1;
}

int main()
{
	std::cout << solution({1,3,6,4,1,2})	<< "\n";
	std::cout << solution({1,2,3})	<< "\n";
	std::cout << solution({-1,-3})	<< "\n";
	std::cout << solution({-1,-3,1,5,6,7,8,10,11,12})	<< "\n";
}