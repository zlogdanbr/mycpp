#include "util.h"
#include "eigen.h"

void eigen_test()
{
    // 4 samples 3x4

    vector<vector<double>>  dm1{  { 1.1, 1.2, 1.3, 1.4 },
                                { 2.1, 2.2, 2.3, 2.4 },
                                { 3.1, 3.2, 3.3, 3.4 }};
    // 3 outputs    

    vector<vector<double>>  dm2{ { 4.1, 4.2, 4.3 } };     
    // 4 coeficents
    vector<vector<double>>  dm3{ { 0, 0, 0, 0 } };  
    
    MatrixXf x = convertVector2Matrix4d(dm1, 4);
    MatrixXf y = convertVector2Matrix4d(dm2, 3);
    MatrixXf coef = convertVector2Matrix4d(dm3, 4);
    int m = 4;
    double zeta = 0.001;
    MatrixXf coefn = coef.transpose() - zeta*GradientDescent(x,y,coef,m);
    coef = coefn.transpose();
    
	for(int i = 0; i < 10 ; i++ )
    {
        coefn = coef.transpose() - zeta*GradientDescent(x,y,coef,m);
        coef = coefn.transpose();
    }
    std::cout << coefn << std::endl;
}

int main()
{
	eigen_test();
}
