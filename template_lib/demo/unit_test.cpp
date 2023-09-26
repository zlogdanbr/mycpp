#include <numeric>
#include "util.h"

using namespace mytools::unittest;
using namespace mytools::util;

 
// dentro essa funcao vc implementa a funcao a testar
int calc( const std::vector<std::vector<int>>&  in)
{
    print2D(in);

    int cnt = 0;
    
    for (auto i = 0; i < in.size(); i++)
    {
        for ( auto j = 0; j < in[i].size(); j++ )
        {
            cnt = cnt + in[i][j];
        }
    }
    
    return cnt;                       
}
 
// executa o teste da funcao calc para as entradas
void RunTest()
{
      
    v3dint in;// using 	v3dint = std::vector<v2dint>;
    std::vector<int> results{2,4};
 
    v2dint  in0 {   {1},
                    {1} 
                };
                                             
    v2dint  in1 {   {2},
                    {2}
                };
                     
                                                             
                                             
    in.push_back(in0);                                                                                          
    in.push_back(in1);

     
    UnitTesting<v2dint,int>(in,results,calc);
                                                 
}
 
 
int main()
{
    RunTest();
}