#include "util.h"

// Using this library https://github.com/andrea993/Matrix-Library-Cpp
#include "mat/Matrix.h"
// ------------------------------------------------------------------

using namespace mytools::util;

template<typename T>
Matrix<T> transpose( const Matrix<T>& a  )
{
	unsigned int rows = a.Rows();
	unsigned int cols = a.Cols();
	

	Matrix<T> transposed(cols, rows, 0);
	
	for(unsigned int i = 0; i < rows; i++ )
	{
		for( unsigned int j = 0; j < cols ; j++ )
		{
			transposed[j][i] = a[i][j];
		}
	}
	return transposed;
}

void times( Matrix<double>& a , int ct )
{
	for(unsigned int i = 0; i < a.Rows(); i++ )
	{
		for( unsigned int j = 0; j < a.Cols() ; j++ )
		{
			a[i][j] =ct * a[i][j];
		}
	}
}

Matrix<double> calculate_gradient( Matrix<double>& x, Matrix<double>& y, Matrix<double>& coef, int m)
{
	Matrix<double> t = transpose<double>(x)*(x*coef - y);
	times( t, m );
	return t;
}

Matrix<double> convertVector2Matrix( vector<vector<double>>& data )
{
	
	unsigned int N = data.size();
	unsigned int M = data[0].size()-1;
	
	Matrix<double> t{N,M};
	
	for(  unsigned int i = 0; i < N ; i++  )
	{
		for(  unsigned int j = 0; j < M ; j++  )
		{
			t[i][j] = data[i][j];
		}
	}
	
	return t;
}

Matrix<double> convertcol2Matrix( vector<double>& y )
{
	
	unsigned int N = y.size();
	
	Matrix<double> t{N,1};
	
	for(  unsigned int i = 0; i < N ; i++  )
	{
		t[i][0] = y[i];
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

void test1()
{
	// two samples as they were read from csv
	Matrix<double> x{ 	{1, 2, 3},
						{4, 5, 6} };	
	
	// two outputs as they are read as a collumn from csv
	Matrix<double> yt = {{ 7, 8 }};
	Matrix<double> y = transpose( yt );
	
	// coef, we have 3 variables so we need 4 coeficients	
	Matrix<double> coefy= {{ 0, 0, 0 }};
	Matrix<double> coef = transpose( coefy);

	
	cout << calculate_gradient( x, y, coef, 1 ) << "\n";
}

void test2()
{
	csvprocessing csv{"test.csv"};
	vector<vector<double>> data;
	vector<double> yr;
	
	csv.readCSV( data, 4, false );	
	Matrix<double> x  = convertVector2Matrix( data );	
	csv.getcol( data, yr, 3 );
	
	Matrix<double> y  = convertcol2Matrix( yr );
	
	// coef, we have 3 variables so we need 4 coeficients	
	Matrix<double> coefy= {{ 0, 0, 0 }};
	Matrix<double> coef = transpose( coefy);

	
	cout << calculate_gradient( x, y, coef, 2 ) << "\n";
}


int main()
{
	test2();

}
