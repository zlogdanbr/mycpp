#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>

void f(int a)
{
	std::cout << a + 5 << "\n";
}

template<typename Function>
void applyit( Function& f, int b )
{
	f(b);
}

int main()
{
	int b = 6;
	applyit(f,b);
}
