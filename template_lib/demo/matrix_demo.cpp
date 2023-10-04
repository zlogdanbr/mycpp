#include "util.h"


using namespace mytools::util;
using namespace mytools::mymath;


void test()
{
	vector<vector<double>> data { 	{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0}};
									
	Dmatrix<double> d{data,4,10};
	
	
	vector<vector<double>> a = convertMatrix2vector( d );
	for( const auto& l1: a )
	{
		for( const auto& l2: l1 )
		{
			cout << l2 << " ";
		}
		cout << "\n";
	}
}

void test_gauss()
{
	vector<vector<double>> a 	{ 	{1,1,2},
									{1,2,3}};
	
	vector<double> x( 2,0 );   

	gauss<double>( a, x );
	
	for( const auto& xi : x )
	{
		cout << xi << " " ;
	}
	cout << "\n";
	
}		

void image_ops_tests()
{
	vector<vector<double>> data { 	{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0}};
									
	Dmatrix<double> d{data,4,10};
	
	vector<Dmatrix<double>> sub;
		
	for( int i = 1; i < 4-1; i++ )
	{
		for( int j = 1; j < 10-1; j++ )
		{
			vector<vector<double>> sub8raw = {  {d(i-1,j-1),d(i-1,j),d(i-1,j+1)},
												{d(i,j-1),d(i,j),d(i,j+1)},
												{d(i+1,j-1),d(i+1,j),d(i+1,j+1)}};
			Dmatrix<double> tmp{sub8raw,3,3};
			sub.push_back( tmp );
		}
	}		
}

void matrix_ops_tests()
{	

	vector<vector<double>> data1  	{{1,1, 1},
									{1, 1, 1},
									{1, 1, 1}};
							
	vector<vector<double>> data2  	{{2, 2, 2},
									{2, 2, 2},
									{2, 2, 2}};
									
	vector<vector<double>> data3  	{{1, 1, 1}};							
	vector<vector<double>> data4  	{{2, 2, 2}};	
	vector<vector<double>> data5  	{{1},{1},{1}};					
	vector<vector<double>> data6  	{{2}, {2},{2}};

	vector<vector<double>> data7 { 	{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0},
									{ 1,2,3,4,5,6,7,8,9,0}};	
									
	vector<vector<double>> data8 { 	{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2},
									{ 1,2}};	
	
	Dmatrix<double> d1{data1,3,3};
	Dmatrix<double> d2{data2,3,3};
	Dmatrix<double> d3{data3,1,3};
	Dmatrix<double> d4{data4,1,3};
	Dmatrix<double> d5{data5,3,1};	
	Dmatrix<double> d6{data6,3,1};
	Dmatrix<double> d7{data7,4,10};
	Dmatrix<double> d8{data8,10,2};
	
	
	Dmatrix<double> sum;	
	sum = d1 + d2;
	Dmatrix<double> sub;
	sub = d2 - d1;	
	Dmatrix<double> mul;
	mul = d7*d8;
	
	cout << sum;
	cout << sub;
	cout << mul;
}		

int main()
{
	matrix_ops_tests();
}
