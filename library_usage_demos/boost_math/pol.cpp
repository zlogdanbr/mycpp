#include "util.h"
#include <boost/math/interpolators/cardinal_cubic_b_spline.hpp>
#include <boost/math/interpolators/cardinal_quintic_b_spline.hpp>

using namespace mytools::util;

using cubic_spline = boost::math::interpolators::cardinal_cubic_b_spline<double>;
using quadradic_spline = boost::math::interpolators::cardinal_quintic_b_spline<double>;

void readCSV(std::string filename, vector<double>& x, vector<double>& y);
void quadradicspline(std::string filename);
void cubicspline(std::string filename);


void readCSV(std::string filename, vector<double>& x, vector<double>& y)
{
	csvprocessing csv{filename};
	vector<vector<double>> data;

	
	csv.readCSV( data, 2, true );	
	
	x = csv.getcol( data, x, 1 );
	y = csv.getcol( data, y, 2 );	
	
}


void quadradicspline(std::string filename)
{
	vector<double> y1;
	vector<double> y2;
	readCSV(filename,y1,y2);	
	double t0 = 1;
    double time_step = 10;
	quadradic_spline p1(y1.data(), y1.size(), t0, time_step);
	quadradic_spline p2(y2.data(), y2.size(), t0, time_step);
	
	std::cout << p1(20) << std::endl;
	std::cout << p2(20) << std::endl;		
}


void cubicspline(std::string filename)
{
	vector<double> y1;
	vector<double> y2;
	readCSV(filename,y1,y2);
	
	double t0 = 1;
    double time_step = 1;
	cubic_spline p1(y1.data(), y1.size(), t0, time_step);
	cubic_spline p2(y2.data(), y2.size(), t0, time_step);
	
	std::cout << p1(20) << std::endl;
	std::cout << p2(20) << std::endl;	
}

int main()
{
	quadradicspline("petrol_consumption.csv");
}

