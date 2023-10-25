#include "util.h"

using namespace mytools::util;
using namespace mytools::mymath;
 
double calc_exp( double& a, double& b, double& t)
{
	return a*exp(b*t);
}

int main()
{
	std::string file = "in.csv";
	csvprocessing csv(file);
	vector<vector<double>> obs;
	csv.readCSV( obs, 2, true );
	vector<double> t;
	vector<double> y;
	t = csv.getcol( obs, t, 0);
	y = csv.getcol( obs, y, 1);	
	
	double a = 0;
	double b = 0;
	
	exponentialRegression( t, y, a , b );
	
	double value = 39;
	double ag = 15.1;
	double bg = 0.178;
	
	double p1 = calc_exp( ag, bg, value );
	double p2 = calc_exp( a, b, value );
	
	cout << "Google : " << p1 << "\n" ;
	cout << "Here : " << p2 << "\n" ;
	
}
