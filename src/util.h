//--------------------------------------------------------------------------
//	namepsace _dutil_
//	contains useful code for search, debug, etc
//--------------------------------------------------------------------------
#ifndef _UTIL_D
#define _UTIL_D


#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef multiset<long long> mset_long;

namespace _dutil_ 
{
	
	auto CompStdStrings = 
	[]( const std::string& s1, const std::string& s2 )
	{
		return  s1.size() < s2.size();
	};

	/*
	*	For as long as you send output to stringstream& out
	*	this function should output it all at the file  filename
	*/
	inline
	void print_all_debugs( stringstream& out, string& filename )
	{
		ofstream myFile;
		myFile.open( filename, ios_base::out);
		if (myFile.is_open())
		{
			myFile << out.str() << endl;
			myFile.close();
		}
	}


	/*
	*	For as long as the container type T supports the
	*   increment operator for the iterator this should
	*   print the container in the stringstream out
	*/
	template<typename T>
	inline 
	void pr( const T& t, stringstream& out ) 
	{
		out << "[ ";
		for( const auto& _el: t )
		{
			out << _el << " ";
		}
		out << "]\n";
	}
	
	/*
	*	For as long as the container type T supports the
	*   increment operator for the iterator this should
	*   print the container in the stringstream out
	*   type O must be an output stream
	*/
	template<typename T, typename O>
	inline 
	void pr( const T& t, O& out ) 
	{
		out << "[ ";
		for( const auto& _el: t )
		{
			out << _el << " ";
		}
		out << "]\n";
	}
	

	/*
	*	Prints a list of pairs, which is a double linked list
	*	of pairs
	*/
	template<typename T, typename M>
	inline
	void pr( const list<pair<T,M> >& m, stringstream& out )
	{
		for( const auto& im: m )
		{
			out << "[" << im.first << "," << im.second << "]" << " ";
		}
		out << "\n";  
	}
	
	template<typename T, typename M>
	inline
	void pr_vec( const vector<pair<T,M> >& m, stringstream& out )
	{
		for( const auto& im: m )
		{
			out << "[" << im.first << "," << im.second << "]" << " ";
		}
		out << "\n";  
	}	

	// from Bjarne Stroustrup The Pratice Of Programming
	// optimized search function
	template<typename In, typename T>
	inline In _find(In first, In last, const T& val)
	{
		while (first!=last && *first != val) ++first;
			return first;
	}

	// Implements a pair class of two integers
	// it should be used mostly because of performance issues
	template<typename T, typename S>
	class mPair
	{
	public:
		mPair(T& one, S& two ):first(one),second(two){};
		mPair( const mPair& pd)
		{
			this->first = pd.first;
			this->second = pd.second;

		};
		mPair& operator=( const mPair& pd )
		{
			this->first = pd.first;
			this->second = pd.second;
			return *this;
		};

		friend bool operator==( const mPair& p1, const mPair& p2 )
		{
			if  ( p1.first == p2.first)
				if ( p1.second == p2.second)
					return true;
			return false;   
		}

		friend bool operator!=( const mPair& p1, const mPair& p2 )
		{
			return ( p1.first != p2.first );
		}

		T first;
		S second;
	};


	/*
	*	Giving two sets of sizes N and M,  this function will redefine them
	*	so that their sizes are T or T-1 
	*/
	inline
	void balance_halfs( mset_long& mysetl, mset_long& mysetr )
	{
	 
		if ( mysetl.size() == mysetr.size() || abs( mysetl.size()-mysetr.size() ) == 1  )
			return; 
		   
		if ( mysetl.size() < mysetr.size() )
		{
			ll tmp = *mysetr.begin();
			mysetr.erase( mysetr.begin() );
			mysetl.emplace( tmp );
			
		}
		else if ( mysetl.size() > mysetr.size() )
		{
			ll tmp = *prev( mysetl.end() );
			mysetl.erase( prev( mysetl.end()) );
			mysetr.emplace( tmp );
		}

		balance_halfs(mysetl,mysetr);
			
	}
	
	// Implementation of search for inversions from the book
	// algorithm  illuminated using brute force
	//  given 1 4 2, an inversion is the pair 4 and 2 because
	// 4 > 2 but the indexes of them in the array are index1< index2
	// Complexity O(n)
	inline
	int num_inverstions_brute( const vector<int>& _arr )
	{
		int invertions = 0;
		int n = _arr.size();
		for( int i = 0; i < n; i++ )
		{
			for( int j = i+1;  j < n-1; j++)
				if ( _arr[i] > _arr[j] ) invertions++;
		}
		return invertions;
	}
	
	// supports genertic types
	template<typename T>
	inline
	int num_inverstions_brute( const vector<T>& _arr )
	{
		int invertions = 0;
		int n = _arr.size();
		for( int i = 0; i < n; i++ )
		{
			for( int j = i+1;  j < n-1; j++)
				if ( _arr[i] > _arr[j] ) invertions++;
		}
		return invertions;
	}
	
	inline 
	vector<int>& slice_vector( const vector<int>& _arr, int posi, int posf, vector<int>& o )
	{
		for( int i = posi; i < posf; i++)
			o.push_back( _arr[i] );
		return o;
	}
		
	inline
	vector<int> split_vector( const vector<int>& _arr, int _left_right)
	{
		int n = _arr.size();
		vector<int> A;
		
		int llast = 0;
		int rfirst = 0;
		
		if ( _arr.size()%2 == 0 )
		{
			llast = n/2;
			rfirst = n/2;			
		}
		else
		{
			llast  = (n+1)/2;
			rfirst = (n+1)/2;
		}
		
		if ( _left_right == 0 )
		{
			return slice_vector( _arr, 0, llast, A );
		}
		else
		{
			return slice_vector( _arr, rfirst, n, A );
		}


	}

	// Implementation of search for inversions from the book
	// algorithm  illuminated using the divide and conquer strategy
	//  given 1 4 2, an inversion is the pair 4 and 2 because
	// 4 > 2 but the indexes of them in the array are index1< index2
	// Complexity O(nlong(n))	
	inline
	int num_inverstions( const vector<int>& _arr )
	{
		
		vector<int> a  = split_vector( _arr, 0 );
		vector<int> b  = split_vector( _arr, 1 );
		
		// TODO implement
		
		return 0;
		
	}
	
	// starts computing the execution time of a code
	inline
	high_resolution_clock::time_point start_tracking()
	{
		return high_resolution_clock::now(); 
	}

	// stops  computing the execution time of a code and print 
	// elapsed time
	inline
	void end_tracking( high_resolution_clock::time_point& start, const char* msg )
	{
		cout << "________________________________________" << endl;
		cout << msg << endl;
		auto stop = high_resolution_clock::now(); 
		auto duration = duration_cast<microseconds>(stop - start);    
		cout << "Execution timing:" << duration.count() << endl; 
		cout << "________________________________________" << endl;
	}
}

#endif
