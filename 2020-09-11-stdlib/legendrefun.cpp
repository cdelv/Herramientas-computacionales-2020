//imprimir los valores de la funcion de legendre orden 2 entre 0 y 10 en pasos de 0.1
//compile como: g++ -std=c++17 legendrefun.cpp
#include <iostream>
#include <cmath>
#include <cstdlib>


int main(int argc, char *argv[])
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  
 double orden=5, Xmin=-1.0, Xmax=1.0, dx=0.01;
  
  for (double x=Xmin; x<=Xmax; x+=dx){
    
    //---------------orden, valor de x------------------    
    std::cout << x << "\t" << std::legendre(orden, x) << std::endl;
  }
  return 0;
}
