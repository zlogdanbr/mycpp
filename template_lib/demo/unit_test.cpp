#include "util.h"

using namespace mytools::unittest;
using namespace mytools::util;
 
// imprime um vector de uma dimensao
template<typename T>
void print1D( const std::vector<T>& vec )
{
    for( const auto& v: vec )
    {
        std::cout << v;
    }
    std::cout << "\n";
}
 
 
// imprime um vetor de dias dimensoes um array de 2d
template<typename T>
void print2D( const std::vector<std::vector<T>>& mat )
{
    for( const auto& l: mat )
    {
        for( const auto& c : l )
        {
            std::cout << c << " " ;
        }
        std::cout << "\n";
    }
     
}
 
 
// funcao que chama a funcao de teste
// f e a funcao que voce precisa passar
// in e o array2d que vai ser a entrada
// expected_value e o valor esperado da saida da funcao f
// retorna falso ou verdadeiro
template<typename function>
bool myFunctionTester(function& f, const v2dint& in, int expected_value) 
{   
 
    auto calculated_val = f(in);
 
    std::cout << "expected value: " << expected_value << std::endl;   
    std::cout << "calculated value: " << calculated_val << std::endl; 
     
    return expected_value == calculated_val;
 
}
 
// Essa funcao recebe um array de entrada com os dados
// os valores esperados e a funcao a ser testada
template<typename IN, typename OUT, typename function>
void UnitTesting(   const std::vector<IN>& InData,
                    const std::vector<OUT>& Expected,
                    function& f)
{
     
    int ok = 0;
    int failed = 0;
    int cnt = 0;
    for( const auto& d: InData)     
    {
        std::cout << "\nRunning test case " << cnt << "\n";
        if ( myFunctionTester( f, d, Expected[cnt] ) == true )
        {   
            std::cout << "Test case " << cnt << " was suscessfull" << std::endl;
            ok++;
        }
        else
        {
            std::cout << "Test case " << cnt << " failed" << std::endl;
            failed++;
        }   
        cnt++;  
    }
     
    std::cout << "_____________________________________________"  << "\n";
    std::cout << "Failed: " << failed << std::endl;
    std::cout << "Sucessfull: " << ok << std::endl;   
    std::cout << "_____________________________________________"  << "\n";
     
}
 
// dentro essa funcao vc implementa a funcao a testar
int calc( const std::vector<std::vector<int>>&  in)
{
    print2D(in);
     
    return 0;                       
}
 
// executa o teste da funcao calc para as entradas
void RunTest()
{
     
 
 
    v3dint in;
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