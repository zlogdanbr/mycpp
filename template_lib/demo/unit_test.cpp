#include "util.h"

using namespace mytools::unittest;
using namespace mytools::util;
 

 
// dentro essa funcao vc implementa a funcao a testar
int calc( const std::vector<std::vector<int>>&  in)
{
    print2D(in);
     
    return 0;                       
}
 
// executa o teste da funcao calc para as entradas
void RunTest()
{
      
    v3dint in;// using 	v3dint = std::vector<v2dint>;
    std::vector<int> results{6,10,6,6,8,6,0,24,21};
 
    v2dint  in0 {   {1,0,1,0,0},
                    {1,0,1,1,1},
                    {1,1,1,1,1},
                    {1,0,0,1,0} };
                                             
    v2dint  in1 {   {1,0,1,0,0},
                    {1,0,1,1,1},
                    {1,1,1,1,1},
                    {1,1,1,1,1},
                    {1,0,0,1,0} };
                     
    v2dint  in2 {   {1,0,1,1,1},
                    {1,0,1,1,1},
                    };  
                                             
    v2dint  in3 {   {1,1,1,0,0},
                    {1,1,1,1,1},
                    {1,1,0,1,1},
                    };  
                                             
    v2dint  in4 {   {1,1,1,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    };  
                     
    v2dint  in5 {   {1,1},
                    {1,1},
                    {1,1},          };  
                     
    v2dint  in6 {   {1,1},
                    {1,1},  };  
 
    v2dint  in7 {   {1,1,1,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    {1,1,0,1,1,1,1},
                    {1,1,0,1,1,1,1},                    
                    };  
 
    v2dint  in8 {   {1,1,1,0,0,0,0},
                    {1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1},
                    {1,1,0,0,1,0,1},
                    {1,1,0,1,1,0,1},
                    {1,1,0,1,1,1,1},                    
                    };                  
                                             
    in.push_back(in0);                                                                                          
    in.push_back(in1);
    in.push_back(in2);
    in.push_back(in3);
    in.push_back(in4);
    in.push_back(in5);
    in.push_back(in6);
    in.push_back(in7);
    in.push_back(in8);
     
    UnitTesting<v2dint,int>(in,results,calc);
                                                 
}
 
 
int main()
{
    RunTest();
}