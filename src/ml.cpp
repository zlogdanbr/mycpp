#include "util.h"


using namespace mytools::util;
using namespace mytools::mymath;


Dmatrix<double> calculate_gradient( 	Dmatrix<double>& x, 
										Dmatrix<double>& y, 
										Dmatrix<double>& coef, 
										double m)
{	
	Dmatrix<double> ao = x*coef ;
	Dmatrix<double> a1 = ao - y;
	Dmatrix<double> a2 = transpose<double>(x);
	times<double,double>( a2, m );
	return a2*a1;
}

Dmatrix<double> convertVector2Matrix( vector<vector<double>>& data )
{
	
	int N = data.size();
	int M = data[0].size()-1;
	
	Dmatrix<double> t(N,M);
	
	for(  int i = 0; i < N ; i++  )
	{
		for(  int j = 0; j < M ; j++  )
		{
			t(i,j) = data[i][j];
		}
	}
	
	return t;
}

Dmatrix<double> convertcol2Matrix( vector<double>& y )
{
	
	int N = y.size();
	
	Dmatrix<double> t(N,1);
	
	for(  int i = 0; i < N ; i++  )
	{
		t(i,0) = y[i];
	}
	return t;
}
 
 
void pr( const vector<double>& y )
{
	for( const auto& v: y )
	{
		cout << v << " " ;
	}
	cout << "\n";
}


void test_case01( std::string filename, unsigned int col_data, int col_y, bool has_header )
{
	csvprocessing csv{filename};
	vector<vector<double>> data;
	vector<double> yr;
	
	csv.readCSV( data, col_data, has_header );	
	Dmatrix<double> x  = convertVector2Matrix( data );	
	csv.getcol( data, yr, col_y );	
	Dmatrix<double> y  = convertcol2Matrix( yr );
	
	// coef, we have 3 variables so we need 4 coeficients	
	Dmatrix<double> coef(col_data - 1, 1);
	
	
	for( int i = 0; i < 1000; i++ )
	{
		Dmatrix<double> grad = calculate_gradient( x, y, coef, 1 ) ;
		times<double,double>(grad,0.1);
		coef = coef - grad;	
	}
	
	cout << coef(0,0) << endl;
	cout << coef(0,1) << endl;
	cout << coef(0,2) << endl;
	

}


int main()
{
	//test_case01("test.csv", 4, 3, false );
	test_case01("petrol_consumption.csv", 4, 3, true );
	//test();
	

}
