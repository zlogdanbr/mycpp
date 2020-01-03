//--------------------------------------------------------------------------
//	namepsace _dutil_
//	contains useful code for search, debug, file, buffer handling etc
//	you can use this freely but I don't take responsability for whatever
//  problems this will likely cause
//  I use C++14
//  I use stl
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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef multiset<long long> mset_long;

namespace _dutil_ 
{
	
	namespace ds
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
			
			mPair( mPair&& pd)
			{
				this->first = pd.first;
				this->second = pd.second;
				pd.first = 0;
				pd.second = 0;

			};
			
			mPair& operator=( mPair&& pd )
			{
				this->first = pd.first;
				this->second = pd.second;
				pd.first = 0;
				pd.second = 0;
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
		
		// implementation of a graph according to the - excellent - book 
		// C++ Data Structures and Algorithm Design Principles
		template<typename T>
		class graph
		{
		public:
			graph( int atn_nodes ):n_nodes(atn_nodes)
			{
				data = vector<vector< pair<int, int> > >( atn_nodes, vector< pair<int, int >>());
			}
			
			graph( const graph& g )
			{
				this->n_nodes = g.n_nodes;
				this->data = g.data;
			}
			
			graph& operator=( const graph& g )
			{
				if ( this != &g )
				{
					this->n_nodes = g.n_nodes;
					this->data = g.data;
				}
				return *this;
			}
			
			// A move constructor simply needs to cleanup whatever memory has been
			// allocated by the original resource g and move everything to this
			graph( graph&& g )
			{		
				this->n_nodes = g.n_nodes;
				this->data = g.data;
				g.n_nodes = 0;
				g.data.clear();	
			}
			
			// A move assignment simply needs to cleanup whatever memory has been
			// allocated by the original resource g and move everything to this
			graph& operator=( graph&& g )
			{
				if ( this != &g)
				{
					this->n_nodes = g.n_nodes;
					this->data = g.data;
					g.n_nodes = 0;
					g.data.clear();	
				}
				return *this;
			}
			
			virtual ~graph(){};
			
			
			// type T should be an enum type
			void addEdge(const T c1, const T c2, int dis)
			{
				auto n1 = static_cast<int>(c1);
				auto n2 = static_cast<int>(c2);
				
				data[n1].emplace_back( n2, dis);
				data[n2].emplace_back( n1, dis );
			}
			
			// type T should be an enum type
			void removeEdge( const T c1, const T c2 )
			{
				auto n1 = static_cast<int>(c1);
				auto n2 = static_cast<int>(c2);	

				remove_if( data[n1].begin(), data[n1].end(), [n2](const auto& pair)
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
				// pr_vec
				for( const auto& rows: data )
				{
					if ( rows.size() != 0 )
						_dutil_::ds::pr_vec<int,int>( rows, out );
					else
						out << "empty" << "\n";
				}
				cout << out.str();
			}
			
		private:	
			vector< vector< pair<int,int> > > data;
			int n_nodes;
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
	
	}
	
	namespace _other_util
	{
		class csvprocessing
		{
		public:
		
			csvprocessing(std::string& filename)
			{
				this->filename = filename;
			}
			
			~csvprocessing(){};
			
			int readCSV(vector<vector<double>>& obs, int nfields)
			{
				ifstream myFile;
				myFile.open(filename, ios_base::in);

				if (myFile.is_open())
				{
					while (myFile.good())
					{
						string Line;
						getline(myFile, Line);
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
			
		private:
			csvprocessing(const csvprocessing&) = delete;
			csvprocessing operator=(const csvprocessing&) = delete;
			std::string filename;
		};

		
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
	
	namespace _buffer
	{
		
		int ConvertHexStringToDecimalString( const char* HexInputString, std::string& Output ) ;
		char* vSetCurrentTimeStamp( char* szTimeStamp );
		char* vSetCurrentTimeStamp( char* szTimeStamp, int isize );
		int calculateCRC( char* buffer, int size );
		unsigned char* sConvertHexBin2String( 	unsigned char ch, 
												unsigned char* buffer);
		char* szConvertStringToData( char* stringbuffer, char* hexbuffer, int size);
		
		inline
		int iConvertBin2Ascii(char* bBindata, int iDataSize, char* szDataAscii )
		{
			// ex: 0x55 = U
			//     0x21 = !
			//     0x00 gets converted to . to avoid problems with NULL terminators
			//     control chars get converted to .

			if (( bBindata == NULL )||(szDataAscii) == NULL )
				return 1;

			for(int i = 0; i < iDataSize; i++ )
			{
				if ( bBindata[i] < 0x20 )
					szDataAscii[i] = '.';
				else
					szDataAscii[i] =  bBindata[i] ;
			}

			return 0;
		}

		/************************************************************************************
		* int iConvertBinArray2String( char* bBindata, 
		*												 int iDataSize,
		*												 char* szDataString )
		* description: Originally the data from the MF is binary, thus to print it in a file we must convert
		*			   it to an ASCII representation of this array of bytes. This convertion is not literal,
		*			   because each nibble of the bin values is converted to an ASCII byte. The output is
		*			   twice as big as the input
		* INPUT:		Original data buffer and its size
		* OUTPUT:	 	New buffer	
		* RETURNS:	    returns 0 OK else 1
		*************************************************************************************/
		inline
		int iConvertBinArray2String(	char* bBindata, 
										int iDataSize,
										char* szDataString ) 
		{	

			if (( bBindata == NULL )||(szDataString) == NULL )
				return 1;

			for(int i = 0; i < iDataSize ; i++)
			{
				char tmp[3];
				memset(tmp,0,3);
				sConvertHexBin2String((unsigned char)bBindata[i],(unsigned char*)tmp);
				memcpy((szDataString+2*i),tmp,2);
			}

			return 0;
		}
		
		/************************************************************************************
		*unsigned char* sConvertHexBin2String(unsigned char ch, unsigned char* buffer)
		* description: Originally the data from the MF is binary, thus to print it in a file we must convert
		*			   it to an ASCII representation of this array of bytes. This convertion is not literal,
		*			   because each nibble of the bin values is converted to an ASCII byte. The output is
		*			   twice as big as the input. This method actually converts each nibble of a byte to
		*			   its ascii representation.
		* INPUT:		A char
		* OUTPUT:	 	2 byte ASCII array representation
		* RETURNS:	    Pointer of the first byte of this array ( includes NULL terminator )
		*************************************************************************************/
		inline
		unsigned char* sConvertHexBin2String(unsigned char ch, unsigned char* buffer)
		{
		  char tmp[3];
		  memset(tmp,0,3);
		  if ( (ch&0x0F) == 0 )
		  {
			if ( ch == 0x00 )
			{
				tmp[0] = 0x30;
				tmp[1] = 0x30;
				tmp[2] = 0x00;
			}
			else
			{
				sprintf(tmp,"%x",ch);
				if ( tmp[1] == 0 )
					tmp[1] = 0x30;
			}
		  }
		  else
		  if ( ((ch&0xF0)<<4) == 0 )
		  {
			char cfix = 0x00;
			sprintf(tmp,"%x",ch);
			cfix = tmp[0];
			tmp[0] = 0x30;
			tmp[1] = cfix;
		  }
		  else
				sprintf(tmp,"%x",ch);
		  memcpy(buffer,tmp,3);	
		  return buffer;  
		}

		inline
		int ConvertHexStringToDecimalString( const char* HexInputString, std::string& Output )
		{
			// Given an input like "0E0AFF1245EE99"
			// convert it to "14 10 255 18 69 238 153"
			char Out[ 528 ];

			if ( HexInputString == NULL )
					return -1;

			memset( Out, 0x00, sizeof( Out ) );


			std::string tmp( HexInputString );
			Output.clear();
			int len = ( ( tmp.length() - 2 )/2 );

			for( int i = 0; i < len + 1 ; i ++ )
			{
				string tmp2 = tmp.substr( 2*i , 2 );
				int tmpInteger =  strtol( tmp2.c_str(), NULL, 16 );
				sprintf( Out + strlen( Out ), "%d", tmpInteger );
				if( i == len )
				{                   
					break;
				}
			}

			Output.append( Out );

			if ( Output.length() <= 0 )
			   return -1;
			return 0;
		}

		inline
		char* vSetCurrentTimeStamp( char* szTimeStamp )
		{
			time_t rawtime;
			struct tm * timeinfo;

			char buffer[32];
			memset(buffer,0,sizeof( buffer));

			if ( szTimeStamp == NULL )
			  return NULL;

			time ( &rawtime );
			timeinfo = localtime ( &rawtime );

			// 01012000_HHMMSS
			strftime (buffer,16,"%d%m%Y_%H%M%S",timeinfo);
			memcpy(szTimeStamp,buffer,15);
			*(szTimeStamp+15)= 0x00;

			return szTimeStamp;

		}
		
		inline
		char* vSetCurrentTimeStamp( char* szTimeStamp, const char* szFormat, int isize )
		{
			time_t rawtime;
			struct tm * timeinfo;

			char buffer[32];
			memset(buffer,0,sizeof( buffer));

			if ( szTimeStamp == NULL )
					return NULL;

			time ( &rawtime );
			timeinfo = localtime ( &rawtime );

			strftime (buffer, isize, szFormat ,timeinfo);
			memcpy(szTimeStamp,buffer,isize);
			*(szTimeStamp+isize)= 0x00;

			return szTimeStamp;
		}

		inline
		int calculateCRC( char* buffer, int size )
		{
			int CRC = 0;
			int Index = 0;
			for( Index = 0; Index < size ; Index++ )
					CRC = CRC + buffer[ Index ];
			return CRC;
		}
		
		inline
		char* szConvertStringToData( char* stringbuffer, char* hexbuffer, int size )
		{
			int i = 0;
			for( i = 0 ; i < size/2 ; i++  )
			{
				char buf[3];
				memset(buf,0,3);
				memcpy(buf,&stringbuffer[2*i],2);
				buf[2] = 0;
				hexbuffer[ i ] = strtol( buf, NULL, 16 );
			}
			return hexbuffer;
		}
		

		inline 
		void ReplaceCharsFromString( std::string& mystring, char whattoChange, char changeTo )
		{
			for( int IndexOnString = 0; IndexOnString < (int)mystring.size() ; IndexOnString++ )
			{
				if ( mystring[ IndexOnString ] == whattoChange )
				{
					mystring[ IndexOnString ] =  changeTo;
				}
			}
		}

		inline
		void GetTimeStamp( std::string& stamp )
		{
			time_t rawtime;
			struct tm * timeinfo;
			char buffer [128];

			memset( buffer, 0x00, sizeof( buffer ) );
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			strftime (buffer,16,"%d%m%Y_%H%M%S",timeinfo);

			stamp = buffer;
		}
	
	}

}

#endif
