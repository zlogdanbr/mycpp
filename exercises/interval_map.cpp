/*
The representation in the std::map must be canonical, that is, 
consecutive map entries must not contain the same value: ..., (3,'A'), (5,'A'), ... is not allowed. Likewise, 
the first entry in m_map must not contain the same value as m_valBegin. 
Initially, the whole range of K is associated with a given initial value, 
passed to the constructor of the interval_map<K,V> data structure.
*/

#include <map>
#include <iostream>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) 
	{
		// INSERT YOUR SOLUTION HERE
		if (!( keyBegin < keyEnd ))
		{
			return;
		}
		
		// intialize
		if ( m_map.empty() == true )
		{
			if ( val == this->m_valBegin )
				return;
			auto range = keyEnd - keyBegin;
			m_map[ range ] = val;
			return;
		}
		else
		{
			auto pval = m_map.rbegin()->second;
						
			if ( pval == val )
				return;
			
			m_map[ 
		}
		
		
				
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
	
	void printme() const
	{
		if ( m_map.empty() == true )
		{
			std::cout << "Internal map is empty" << std::endl;
			return;
		}
		for( const auto& m : m_map )
		{
			std::cout << "(" << m.first << "," << m.second  << ") ";
		}
		std::cout << std::endl;
	}
	
	
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

// interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.

//
//Each key-value-pair (k,v) in interval_map<K,V>::m_map means that the value v is associated with all keys from k (including) 
//to the next key (excluding) in m_map. The member interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.

/*

-2 -> 'A'
-1 -> 'A'
0 -> 'A'
1 -> 'B'
2 -> 'B'
3 -> 'A'
4 -> 'A'
5 -> 'A'

*/

int main()
{
	interval_map<int,char> M{'A'};
	M.assign(1,3,'B');;
	M.assign(3,6,'A');	
	M.printme();
	
}

