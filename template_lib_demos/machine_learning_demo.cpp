#include "util.h"


using namespace mytools::util;
using namespace mytools::mymath;


inline Dmatrix<double> calculate_gradient( 	const Dmatrix<double>& x, 
										const Dmatrix<double>& y, 
										const Dmatrix<double>& coef, 
										double m)
{	

	Dmatrix<double> ao = x*coef ;
	Dmatrix<double> a1 = ao - y;
	Dmatrix<double> a2 = transpose<double>(x);
	times<double,double>( a2, m );
	return a2*a1;
}

inline void gradient_batch( 	std::string filename, 
								int col_data, 
								int col_y,
								int samples,
								double learning_rate,
								bool has_header,
								int iterations,
								Dmatrix<double>& coef )
{
	
	csvprocessing csv{filename};
	vector<vector<double>> data;
	vector<double> yr;
	
	csv.readCSV( data, col_data, has_header );	
	Dmatrix<double> x  = convertVector2Matrix( data );	
	csv.getcol( data, yr, col_y );	
	Dmatrix<double> y  = convertcol2Matrix( yr );
		
	double s = (2/static_cast<double>(samples));
		
	for( int i = 0; i < iterations; i++ )
	{
		Dmatrix<double> grad = calculate_gradient( x, y, coef, s) ;
		times<double,double>(grad,learning_rate);
		Dmatrix<double> tmp = coef - grad;
		coef = tmp;
	}
	
	cout << "coef final" << endl;
	cout << coef ;

}

void test_case01()
{
	vector<vector<double>> data3  {{1},{1},{1}};
	Dmatrix<double> d4{data3,3,1};
	gradient_batch("petrol_consumption.csv", 4, 3, 49, 0.00000001, true, 10, d4);
}

void test_case02()
{
	vector<vector<double>> data3  {{15}};
	Dmatrix<double> d4{data3,1,1};
	gradient_batch("in.csv", 2, 1, 40, 0.02, true, 10000, d4);
}

void test_case03()
{
	vector<vector<double>> data3  {{2},{2}};
	Dmatrix<double> d4{data3,2,1};
	gradient_batch("heart.data.csv", 3, 2, 498, 0.1, true, 3, d4);
}

int main()
{
	test_case01();
}

