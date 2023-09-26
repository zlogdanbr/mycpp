//--------------------------------------------------------------------------
//	namespace mytools
//
//	Contains useful code for search, debug, file, buffer handling etc
//	You can use this freely but I don't take responsability for whatever
//  problems this will likely cause. I use this as a library for my code.
//  
//  
//  IMPORTANT:
//  I use STL
//	I use C++17
//
//	It contains the following nested namespaces
//	>namespace mytools::algo
//  Contains code to be used with STL, DS and algorithms
//  >namespace mytools::util
//	Contains useful code not buffer/string related
//	>namespace mytools::mymath
//  Linear algebra, matrix, numerical methods
//
//--------------------------------------------------------------------------
//	2020/2021/2022 Daniel V. Gomes
//--------------------------------------------------------------------------



#ifndef _UTIL_D
#define _UTIL_D


#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <thread>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef multiset<long long> mset_long;
typedef high_resolution_clock::time_point tp;

namespace mytools
{

	namespace algo
	{

		// Some useful lambda functions
		auto compstrsize =
			[](const std::string& s1,
				const std::string& s2)
		{
			return  s1.size() < s2.size();
		};

		auto compint = [](const int& a,
			const int& b) -> bool { return a == b; };

		auto compstr = [](const std::string& a,
			const std::string& b) -> bool { return a == b; };

		auto isgreaterthan = [](const int& a,
			const int& b) -> bool { return a > b; };

		auto isgreaterthans = [](const std::string& a,
			const std::string& b) -> bool
		{
			return  (a.length() >= b.length());
		};

		void test()
		{
			std::cout << "Test" << std::endl;
		}

		/*
		*	For as long as you send output to stringstream& out
		*	this function should output it all at the file  filename
		*/
		void print_all_debugs(stringstream& out,
				string& filename)
		{
			ofstream myFile;
			myFile.open(filename, ios_base::out);
			if (myFile.is_open())
			{
				myFile << out.str() << endl;
				myFile.close();
			}
		}


		/*
		*	Prints a list of pairs, which is a double linked list
		*	of pairs
		*/
		template<typename T, typename M>
		void print_pairs(const list<pair<T, M> >& m,
				stringstream& out)
		{
			for (const auto& im : m)
			{
				out << "[" << im.first << "," << im.second << "]" << " ";
			}
			out << "\n";
		}

		/*
		*	Prints a list of pairs, which is a vector
		*	of pairs
		*/
		template<typename T, typename M>
		void print_vector(const vector<pair<T, M> >& m,
				stringstream& out)
		{
			for (const auto& im : m)
			{
				out << "[" << im.first << "," << im.second << "]" << " ";
			}
			out << "\n";
		}

		/*
		*	Prints a generic STL containerwhich
		*/
		template<typename T>
		void print_stlc(T& m)
		{
			cout << "[ ";
			for (const auto& im : m)
			{
				cout << im << " ";
			}
			cout << "]\n";
		}

		/*
		* 	implementation of binary search for a multiset
		*	 not as fast as brute force search by Stroustrup
		*/
		template<typename T, typename Iterator>
		bool binary_search_recursive_set(T N,
				Iterator first,
				Iterator last)
		{

			Iterator mid = first;
			auto range_length = std::distance(first, last);
			auto mid_element_index = std::floor(range_length / 2);
			advance(mid, mid_element_index);

			if (range_length == 1)
				return false;

			if (*mid == N)
			{
				return true;
			}
			else
				if (*mid > N)
				{
					binary_search_recursive_set(N, mid, last);
				}
				else
					if (*mid < N)
					{
						binary_search_recursive_set(N, first, mid);
					}

			return true;

		}

		/*
		* 	implementation of recursive binary search
		*/
		template<typename T, typename Iterator>
		bool binary_search_recursive(T N,
				Iterator first,
				Iterator last)
		{

			// Get the middle element of the current range
			auto range_length = std::distance(first, last);
			auto mid_element_index = std::floor(range_length / 2);
			auto mid_element = *(first + mid_element_index);

			// If only one element left in the current range
			if (range_length == 1)
				return false;

			// Compare the middle element of current range with N
			if (mid_element == N)
			{
				return true;
			}
			else if (mid_element > N)
			{
				std::advance(last, -mid_element_index);
			}
			if (mid_element < N)
			{
				std::advance(first, mid_element_index);
			}

			binary_search_recursive(N, first, last);

			return true;

		}


		/*
		* from Bjarne Stroustrup The Pratice Of Programming
		*	optimized search function, if the container is not
		*	sorted this is the best algorithm
		*/
		template<typename In, typename T>
		In _find(In first,
			In last,
			const T& val)
		{
			while (first != last && *first != val) ++first;
			return first;
		}

		/*
		* 	from Bjarne Stroustrup The Pratice Of Programming
		*	optimized search function, if the container is not
		*	sorted this is the best algorithm, adapted to delete
		* 	a specific value
		*/
		bool _find_Del(mset_long& cont,
				mset_long::iterator first,
				mset_long::iterator last,
				ll val)
		{
			while (first != last && *first != val) ++first;
			if (first == last)
				return false;
			cont.erase(first);
			return true;
		}

		/*
		* Implements a pair class of two integers
		* it should be used mostly because of performance issues
		*/
		template<typename T, typename S>
		class mPair
		{
		public:
			mPair(T& one, S& two) :first(one), second(two) {};
			mPair(const mPair& pd)
			{
				this->first = pd.first;
				this->second = pd.second;
			};

			mPair& operator=(const mPair& pd)
			{
				this->first = pd.first;
				this->second = pd.second;
				return *this;
			};

			mPair(mPair&& pd)
			{
				this->first = pd.first;
				this->second = pd.second;
				pd.first = 0;
				pd.second = 0;

			};

			mPair& operator=(mPair&& pd)
			{
				this->first = pd.first;
				this->second = pd.second;
				pd.first = 0;
				pd.second = 0;
				return *this;
			};

			friend bool operator==(const mPair& p1, const mPair& p2)
			{
				if (p1.first == p2.first)
					if (p1.second == p2.second)
						return true;
				return false;
			}

			friend bool operator!=(const mPair& p1, const mPair& p2)
			{
				return (p1.first != p2.first);
			}

			T first;
			S second;
		};

		// implementation of a graph according to the - excellent - book 
		// C++ Data Structures and Algorithm Design Principles
		template<typename T>
		class graph
		{
		public:
			graph(int atn_nodes) :n_nodes(atn_nodes)
			{
				data = vector<vector< pair<int, int> > >(atn_nodes, vector< pair<int, int >>());
			}

			graph(const graph& g)
			{
				this->n_nodes = g.n_nodes;
				this->data = g.data;
			}

			graph& operator=(const graph& g)
			{
				if (this != &g)
				{
					this->n_nodes = g.n_nodes;
					this->data = g.data;
				}
				return *this;
			}

			// A move constructor simply needs to cleanup whatever memory has been
			// allocated by the original resource g and move everything to this
			graph(graph&& g)
			{
				this->n_nodes = g.n_nodes;
				this->data = g.data;
				g.n_nodes = 0;
				g.data.clear();
			}

			// A move assignment simply needs to cleanup whatever memory has been
			// allocated by the original resource g and move everything to this
			graph& operator=(graph&& g)
			{
				if (this != &g)
				{
					this->n_nodes = g.n_nodes;
					this->data = g.data;
					g.n_nodes = 0;
					g.data.clear();
				}
				return *this;
			}

			virtual ~graph() {};


			// type T should be an enum type
			void addEdge(const T c1,
				const T c2,
				int dis)
			{
				auto n1 = static_cast<int>(c1);
				auto n2 = static_cast<int>(c2);

				data[n1].emplace_back(n2, dis);
				data[n2].emplace_back(n1, dis);
			}

			// type T should be an enum type
			void removeEdge(const T c1,
				const T c2)
			{
				auto n1 = static_cast<int>(c1);
				auto n2 = static_cast<int>(c2);

				remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair)
				{
					return pair.first == n2;
				});

				remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair)
				{
					return pair.first == n1;
				});
			}

			void print_me() const
			{
				stringstream out;
				// print_vector
				for (const auto& rows : data)
				{
					if (rows.size() != 0)
						print_vector<int, int>(rows, out);
					else
						out << "[empty]" << "\n";
				}
				cout << out.str();
			}

		private:
			vector< vector< pair<int, int> > > data;
			int n_nodes;
		};


		/*
		*	Giving two sets of sizes N and M,  this function will redefine them
		*	so that their sizes are T or T-1
		*/
		void balance_halfs(mset_long& mysetl,
				  mset_long& mysetr)
		{

			if (mysetl.size() == mysetr.size() || llabs(mysetl.size() - mysetr.size()) == 1)
				return;

			if (mysetl.size() < mysetr.size())
			{
				ll tmp = *mysetr.begin();
				mysetr.erase(mysetr.begin());
				mysetl.emplace(tmp);

			}
			else if (mysetl.size() > mysetr.size())
			{
				ll tmp = *prev(mysetl.end());
				mysetl.erase(prev(mysetl.end()));
				mysetr.emplace(tmp);
			}

			balance_halfs(mysetl, mysetr);

		}


		// this is an implementation of a node for the LL below. The only thing useful with this is
		// actually writing it for the sake of fun. 	
		template<typename T>
		class Node
		{
		public:
			Node(T v)
			{
				this->v = v;
			}
			~Node() {};
			Node<T>* next;
			Node<T>* prev;
			T v;

			Node(const Node& n)
			{
				this->next = n.next;
				this->prev = n.prev;
				this->v = n.v;
			}

			Node<T>& operator=(const Node& n)
			{
				if (this != &n)
				{
					this->next = n.next;
					this->prev = n.prev;
					this->v = n.v;
				}
				return *this;
			}

			friend bool operator==(const Node& n1, const Node& n2)
			{
				return (n1.v == n2.v);
			}

			friend bool operator!=(const Node& n1, const Node& n2)
			{
				return (n1.v != n2.v);
			}

			friend bool operator<(const Node& n1, const Node& n2)
			{
				return (n1.v < n2.v);
			}

			friend bool operator>(const Node& n1, const Node& n2)
			{
				return (n1.v < n2.v);
			}
		};

		// The node class needs an iterator class
		template<typename T>
		class iterator
		{
		public:
			Node<T>* next;
			Node<T>* prev;
			Node<T>* crt;

			iterator<T>()
			{
				this->next = nullptr;
				this->prev = nullptr;
				this->crt = nullptr;
			}

			iterator<T>(const iterator& it)
			{
				this->next = it.next;
				this->prev = it.prev;
				this->crt = it.crt;
			}

			iterator<T> operator =(const iterator& it)
			{
				if (this != &it)
				{
					this->next = it.next;
					this->pre = it.prev;
					this->crt = it.crt;
				}
				return this;
			}

			iterator<T>* operator++(int)
			{
				this->crt = this->next;
				return this;
			}

			iterator<T>* operator++()
			{
				this->crt = this->next;
				return this;
			}


			T operator*()
			{
				return this->crt->v;
			}

			friend bool operator==(iterator<T>& a1, iterator<T>& a2)
			{
				return (a1->crt->v == a2->crt->v);
			}


		};

		// this is an implementation of a Double LL. The only thing useful with this is
		// actually writing it for the sake of fun. 
		// it is much better to do this:
		//
		// #include <list>		// from STL
		// list<double> l;
		// 
		template<typename T >
		class cllist
		{
		public:
			cllist()
			{
				head = nullptr;
				tail = nullptr;
				size = 0;
			}

			~cllist()
			{
				clear();
			}

			iterator<T> begin() const
			{
				iterator<T> tmp;
				tmp.crt = tail;
				return tmp;
			}

			iterator<T> end() const
			{
				iterator<T> tmp;
				tmp.crt = head->next;
				return tmp;
			}

			virtual void clear() final
			{
				it.crt = tail;
				for (it.crt = tail; it.crt->next != nullptr; )
				{
					Node<T>* c = it.crt;
					it.crt = it.crt->next;
					delete c;
				}
				size = 0;
				cout << "all cleared " << endl;
			}

			virtual int push(T v) final
			{
				Node<T>* n = new Node<T>(v);
				if (head != nullptr)
				{
					n->next = nullptr;
					head->next = n;
					n->prev = head;
					head = n;
				}
				else
				{
					head = n;
					n->next = nullptr;
					n->prev = nullptr;
				}

				if (size == 0)
				{
					tail = n;
				}
				size++;

				return size;
			}

			virtual int pop() final
			{

				if (size != 0)
				{
					Node<T>* new_head = head->prev;
					delete head;
					head = nullptr;
					head = new_head;
					head->next = nullptr;
				}
				else
				{
					delete tail;
					tail = nullptr;
					head = nullptr;
				}

				return 0;

			}


			void advance(iterator<T>& it, int pos)
			{
				int i = 0;
				do
				{
					it++;;
				} while (i++ < pos);

			}

			virtual int getSize() const final
			{
				return this->size;
			}

			template<typename F>
			int find(T v, F& f)
			{
				Node<T>* it = cllist<T>::tail;
				for (int i = 0; i < cllist<T>::size; i++, it = it->next)
				{
					if (f(v, it->v) == true)
						return i;
				}
				return -1;
			}


			bool binary_search(iterator<T> first, iterator<T> last, T v)
			{

				int range_length = &last - &first;
				int mid_element_index = std::floor(range_length / 2);
				iterator<T> mid_element = first;
				advance(mid_element, mid_element_index);

				if (*mid_element == v)
					return true;

				if (*mid_element > v)
				{
					binary_search(mid_element, last, v);
				}
				else
					if (*mid_element < v)
					{
						binary_search(first, mid_element, v);
					}

				if (range_length == 1)
					return false;

				return true;
			}


			template<typename F>
			bool remove(T v, F& f)
			{
				Node<T>* it = cllist<T>::tail;
				for (int i = 0; i < cllist<T>::size; i++, it = it->next)
				{
					if (f(v, it->v) == true)
					{
						if (it == cllist<T>::tail)
						{
							cllist<T>::tail = it->next;
							delete it;
							cllist<T>::size--;
							return true;
						}
						else if (it == cllist<T>::head)
						{
							delete cllist<T>::head;
							cllist<T>::size--;
							Node<T>* it2 = cllist<T>::tail;
							for (int k = 0; i < cllist<T>::size; k++, it2 = it2->next)
							{
								cllist<T>::head = it2;
							}
						}
						else
						{
							Node<T>* it2 = cllist<T>::tail;
							for (int j = 0; j < (i - 1); j++, it2 = it2->next);
							it2->next = it->next;
							cllist<T>::size--;
							delete it;
						}
					}
				}
				return false;
			}

		private:
			int size;
			Node<T>* head;
			Node<T>* tail;
			iterator<T> it;

		};

		template<typename T>
		void initstack(std::vector<T>&& s1, std::stack<T>& mystack)
		{
			for (const auto& s : s1)
				mystack.push(s);
		}

		template<typename T>
		void clearStack(std::stack<T>& mystack)
		{
			while (mystack.empty() == false)
			{
				mystack.pop();
			}
		}

		template<typename T>
		void printstack(const std::stack<T>& mystack)
		{
			std::stack<T> mystack2 = mystack;
			while (mystack2.empty() == false)
			{
				std::cout << mystack2.top() << " ";
				mystack2.pop();
			}
			std::cout << "\n";
		}

		template<typename T>
		T sumALLstack(std::stack<T>& mystack)
		{
			std::stack<T> mystack2 = mystack;
			T sum = 0;
			while (mystack2.empty() == false)
			{
				sum = sum + mystack2.top();
				mystack2.pop();
			}
			return sum;
		}

		template<typename T>
		T sumtlastwo(const std::stack<T>& mystack)
		{
			std::stack<int> mystack2 = mystack;
			auto p0 = mystack2.top();
			mystack2.pop();
			auto p1 = mystack2.top();
			return p0 + p1;
		}

		template<typename T>
		void initqueue(std::vector<T>&& s1, std::queue<T>& myqueue)
		{
			for (const auto& s : s1)
				myqueue.push(s);
		}

		template<typename T>
		void printque(const std::queue<T>& myqueue)
		{
			std::queue<T> myqueue2 = myqueue;
			while (myqueue2.empty() == false)
			{
				std::cout << myqueue2.front() << " ";
				myqueue2.pop();
			}
			std::cout << "\n";
		}
	}

	namespace util
	{


		// this is a c++ thread wrapper pool
		using  myThreads = std::vector< std::thread >;

		class ThreadWrapper
		{
		public:
			ThreadWrapper()
			{
				NumberOfCrtThreads = 0;
				alljoined = false;
			}

			~ThreadWrapper()
			{
				if (alljoined == false)
				{
					Join();
				}
			}

			// f function is the actual execution thread code
			template<typename F>
			void AddAndRun(F& f)
			{
				std::thread t{ f };
				NumberOfCrtThreads++;
				// you need to move t 
				ThreadDataPool.push_back(std::move(t));
			}

			void Join()
			{
				for (auto& t : ThreadDataPool)
				{
					t.join();
				}

				ThreadDataPool.clear();
				alljoined = true;

			}
			int GetNumberOfCrtThreads()const { return NumberOfCrtThreads; };
		private:
			myThreads ThreadDataPool;
			int NumberOfCrtThreads;
			bool alljoined;
		};

		// Basically it reads a csv file and copies it to a const vector<vector<double>>& obs
		// after you calling the readCSV method
		class csvprocessing
		{
		public:

			csvprocessing(const std::string& filename)
			{
				this->filename = filename;
			}

			~csvprocessing() {};


			int readCSV(vector<vector<double>>& obs,
				int nfields,
				bool ignoreheader) const
			{
				ifstream myFile;
				myFile.open(filename, ios_base::in);

				if (myFile.is_open())
				{
					while (myFile.good())
					{

						string Line;
						getline(myFile, Line);

						if (ignoreheader == true)
						{
							ignoreheader = false;
							continue;
						}

						if (Line.length() == 0)
						{
							break;
						}

						int pos = 0;
						int start = 0;
						vector<double> ob;
						int cnt = 0;
						while (pos != -1)
						{
							if (cnt < nfields)
							{
								pos = Line.find(',', start);
								string tmp = Line.substr(start, pos - start);
								start = pos + 1;
								double f = stof(tmp);
								ob.push_back(f);
								cnt++;
							}
							else
							{
								break;
							}
						}
						obs.push_back(ob);
					}
					myFile.close();
				}
				else
				{
					return -1;
				}

				return 0;
			};

			vector<double>& getcol(const vector<vector<double>>& obs, vector<double>& vec, int col) const
			{
				for (const auto& v : obs)
				{
					vec.push_back(v[col]);
				}
				return vec;
			}

		private:
			csvprocessing(const csvprocessing&) = delete;
			csvprocessing operator=(const csvprocessing&) = delete;
			std::string filename;
		};


		// starts computing the execution time of a code
		const tp start_tracking()
		{
			return high_resolution_clock::now();
		}

		// stops  computing the execution time of a code and print 
		// elapsed time
		void end_tracking(tp& start)
		{
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			cout << "Execution time(ms): " << duration.count() / 1000 << endl;
		}



	}

	namespace unittest
	{
		// useful alias
		using  	v1dint = std::vector<int>;
		using 	v2dint = std::vector< v1dint >;
		using 	v3dint = std::vector<v2dint>;


		// Prints a one D vector
		template<typename T>
		void print1D(const std::vector<T>& vec) noexcept
		{
			for (const auto& v : vec)
			{
				std::cout << v;
			}
			std::cout << "\n";
		}


		// prints a 2d vector
		template<typename T>
		void print2D(const std::vector<std::vector<T>>& mat) noexcept
		{
			for (const auto& l : mat)
			{
				for (const auto& c : l)
				{
					std::cout << c << " ";
				}
				std::cout << "\n";
			}

		}

		// this function is called to validate the output of the input IN
		// against the expected output expected value
		// you are supposed to provide the == operator if the data type
		// does not support it already
		template<typename function, typename T, typename M>
		bool myFunctionTester(	function& f, 
								const M& in, 
								T& expected_value)  noexcept
		{

			auto calculated_val = f(in);

			std::cout << "expected value: " << expected_value << std::endl;
			std::cout << "calculated value: " << calculated_val << std::endl;

			return expected_value == calculated_val;

		}

		// the input data is passed as an vector so you need to
		// add your test case input data to a vector and
		// provide  the vector of expected values
		// f is a template for the function that you will test
		// so it requires a parameter of input
		template<typename IN, typename OUT, typename function>
		void UnitTesting(	const std::vector<IN>& InData,
							const std::vector<OUT>& Expected,
							function& f) noexcept
		{

			int ok = 0;
			int failed = 0;
			int cnt = 0;
			for (const auto& d : InData)
			{
				std::cout << "\nRunning test case " << cnt << "\n";
				if (myFunctionTester(f, d, Expected[cnt]) == true)
				{
					std::cout << "Test case " << cnt << " was suscessfull" << std::endl;
					ok++;
				}
				else
				{
					std::cout << "Test case " << cnt << " failed" << std::endl;
					failed++;
				}
				cnt++;
			}

			std::cout << "_____________________________________________" << "\n";
			std::cout << "Failed: " << failed << std::endl;
			std::cout << "Sucessfull: " << ok << std::endl;
			std::cout << "_____________________________________________" << "\n";

		}
	}

	namespace mymath
	{

		// Adapted from
		// https://www.codewithc.com/c-program-for-linear-exponential-curve-fitting/
		// It performs an exponential regression
		int exponentialRegression(const vector<double>& x,
			const vector<double>& y,
			double& a,
			double& b)
		{

			double sumx = 0;
			double sumy = 0;
			double sumxy = 0;
			double sumx2 = 0;
			double A;
			vector<double> Y;

			for (const auto& item : y)
			{
				double tmp = item;
				Y.push_back(log(tmp));
			}

			auto n = Y.size();

			for (int i = 0; i <= n - 1; i++)
			{
				sumx = sumx + x[i];
				sumx2 = sumx2 + x[i] * x[i];
				sumy = sumy + Y[i];
				sumxy = sumxy + x[i] * Y[i];

			}

			A = ((sumx2 * sumy - sumx * sumxy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0);
			b = ((n * sumxy - sumx * sumy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0);
			a = exp(A);
			printf("The curve is Y= %4.3fe^%4.3fX\n", a, b);
			return 0;
		}

		// adapted from
		// https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
		// Solves a linear system of size n, implicit at the vector a size
		// I was looking for an algorithm for this when I stumbled upon the
		// C++ code so why do it myself :-) ?
		template<typename T >
		int gauss(vector < vector<T> > a, vector<T>& ans)
		{
			const double EPS = 1e-9;
			const int INF = 2;
			int n = (int)a.size();
			int m = (int)a[0].size() - 1;

			vector<int> where(m, -1);
			for (int col = 0, row = 0; col < m && row < n; ++col)
			{
				int sel = row;
				for (int i = row; i < n; ++i)
					if (abs(a[i][col]) > abs(a[sel][col]))
						sel = i;
				if (abs(a[sel][col]) < EPS)
					continue;
				for (int i = col; i <= m; ++i)
					swap(a[sel][i], a[row][i]);
				where[col] = row;

				for (int i = 0; i < n; ++i)
					if (i != row) {
						T c = a[i][col] / a[row][col];
						for (int j = col; j <= m; ++j)
							a[i][j] -= a[row][j] * c;
					}
				++row;
			}

			ans.assign(m, 0);
			for (int i = 0; i < m; ++i)
				if (where[i] != -1)
					ans[i] = a[where[i]][m] / a[where[i]][i];
			for (int i = 0; i < n; ++i) {
				T sum = 0;
				for (int j = 0; j < m; ++j)
					sum += ans[j] * a[i][j];
				if (abs(sum - a[i][m]) > EPS)
					return 0;
			}

			for (int i = 0; i < m; ++i)
				if (where[i] == -1)
					return INF;
			return 1;
		}


		// My custom matrix class 
		template<typename T>
		class Dmatrix final {

		public:

			explicit Dmatrix() {};
			explicit Dmatrix(int _N, int _M) :N(_N), M(_M)
			{
				for (int i = 0; i < _N; i++)
				{
					vector<T> tmp(_M, 0);
					data.emplace_back(tmp);
				}
			};

			explicit Dmatrix(int _M) :M(_M)
			{
				this->N = 1;
				vector<T> tmp(M, 0);
				data.push_back(tmp);

			};

			explicit Dmatrix(const Dmatrix& m)
			{
				this->N = m.N;
				this->M = m.M;
				this->data = m.data;
			}

			explicit Dmatrix(vector<vector<T>>& data, int _N, int _M)
			{
				this->N = _N;
				this->M = _M;
				this->data = data;
			}

			Dmatrix& operator=(const Dmatrix& m)
			{
				this->N = m.N;
				this->M = m.M;
				this->data = m.data;
				return *this;
			}

			Dmatrix(Dmatrix&& m) noexcept
			{
				this->N = m.N;
				this->M = m.M;
				this->data = m.data;
				N = 0;
				M = 0;
				data.clear();
			}

			Dmatrix& operator=(Dmatrix&& m)
			{
				if (this != &m)
				{
					this->N = m.N;
					this->M = m.M;
					N = 0;
					M = 0;
					this->data = m.data;
					data.clear();
				}
				return *this;
			}

			// Access the individual elements                                                                                                                                                                                               
			T& operator()(int& row, const int& col)
			{
				return this->data[row][col];
			}

			const T& operator()(const int& row, const int& col) const
			{
				return this->data[row][col];
			}

			vector<vector<T>>& getdata() { return this->data; };
			const int& rows() const { return this->N; };
			const int& cols() const { return this->M; };

			friend ostream& operator<<(ostream& os, const Dmatrix& m)
			{

				for (int i = 0; i < m.N; i++)
				{
					for (int j = 0; j < m.M; j++)
					{
						os << m.data[i][j] << " ";
					}
					os << "\n";
				}

				return os;
			}

			friend Dmatrix operator+(const Dmatrix& m1, const Dmatrix& m2)
			{
				Dmatrix<T> m3(m1.rows(), m1.cols());
				if ((m1.rows() == m2.rows()) && (m1.cols() == m2.cols()))
				{
					for (int i = 0; i < m1.rows(); i++)
					{
						for (int j = 0; j < m1.cols(); j++)
						{
							m3(i, j) = m1(i, j) + m2(i, j);
						}
					}
					return m3;
				}

				return m3;
			}

			friend Dmatrix operator-(const Dmatrix& m1, const Dmatrix& m2)
			{

				Dmatrix<T> m3(m1.rows(), m1.cols());
				if ((m1.rows() == m2.rows()) && (m1.cols() == m2.cols()))
				{
					for (int i = 0; i < m1.rows(); i++)
					{
						for (int j = 0; j < m1.cols(); j++)
						{
							m3(i, j) = m1(i, j) - m2(i, j);
						}
					}

					return m3;
				}

				return m3;
			}

			friend Dmatrix operator*(const Dmatrix& m1, const Dmatrix& m2)
			{
				Dmatrix<T> c(m1.rows(), m2.cols());
				if (m1.cols() != m2.rows())
				{
					return c;
				}
				else
				{
					for (int i = 0; i < m1.rows(); i++)
					{
						for (int j = 0; j < m2.cols(); j++)
						{
							for (int k = 0; k < m2.rows(); k++)
							{
								c(i, j) = c(i, j) + (m1(i, k) * m2(k, j));
							}
						}
					}
				}

				return c;
			}

		private:

			vector<vector<T>> data;
			int N = 0;
			int M = 0;
		};

		// multiplies a matrix by a value ct
		template<typename M, typename T>
	        void times(Dmatrix<M>& a, T ct)
		{
			for (int i = 0; i < a.rows(); i++)
			{
				for (int j = 0; j < a.cols(); j++)
				{
					a(i, j) = ct * a(i, j);
				}
			}
		}

		// useful debug, prints all info on a matrix
		template<typename M>
		void d(Dmatrix<M>& a)
		{
			cout << "Size: " << a.rows() << " x " << a.cols() << endl;
			cout << "Contents:" << endl;
			cout << a;
		}

		// converts a vector of a vector to a matrix
		Dmatrix<double> convertVector2Matrix(vector<vector<double>>& data)
		{

			auto N = data.size();
			auto M = data[0].size() - 1;

			Dmatrix<double> t(N, M);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					t(i, j) = data[i][j];
				}
			}

			return t;
		}

		// converts a matrix to a vector of a vector
		vector<vector<double>> convertMatrix2vector(Dmatrix<double>& mat)
		{

			int N = mat.rows();
			int M = mat.cols();

			vector<vector<double>> out;

			for (int i = 0; i < N; i++)
			{
				vector<double> tmp;
				for (int j = 0; j < M; j++)
				{
					tmp.push_back(mat(i, j));
				}
				out.push_back(tmp);
			}

			return out;
		}

		// converts a vector ( typically a collumn of a csv file )
		// to a matrix
		Dmatrix<double> convertcol2Matrix(vector<double>& y)
		{

			auto N = y.size();

			Dmatrix<double> t(N, 1);

			for (int i = 0; i < N; i++)
			{
				t(i, 0) = y[i];
			}
			return t;
		}


		// transpose NxN matrix and 1xN or Nx1
		template<typename T>
		Dmatrix<T> transpose(const Dmatrix<T>& m1)
		{
			int rows = m1.rows();
			int cols = m1.cols();

			cout << "rows: " << rows << endl;
			cout << "cols: " << cols << endl;

			Dmatrix<T> out(cols, rows);

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					out(j, i) = m1(i, j);
				}
			}

			return out;
		}

	}


}

#endif
