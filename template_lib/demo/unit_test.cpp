#include <numeric>
#include "util.h"

using namespace mytools::unittest;
using namespace mytools::util;

 
// dentro essa funcao vc implementa a funcao a testar
int calc( const std::vector<int>&  in)
{
    print1D(in);
    int cnt = 0;
    cnt = std::accumulate(in.begin(), in.end(), cnt);
    return cnt;                       
}
 
// executa o teste da funcao calc para as entradas
void RunTest()
{
      
    v2dint in;
    std::vector<int> results{2,4};
    
    v1dint  in0 { 1,1 };                                             
    v1dint  in1 { 2,2 };
                     
                                                                                                         
    in.push_back(in0);                                                                                          
    in.push_back(in1);

     
    UnitTesting<v1dint,int>(in,results,calc);
                                                 
}
 
 
int main()
{
    RunTest();
}