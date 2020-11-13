//Carlos Andres del Valle y  Andres Vargas Londoño
//g++ minimizarerror.cpp //para graficar -----plot "datos.dat" u 1:2 w l t "original", "" u 1:3 w l t "modificada"
#include<iostream>
#include<cmath>
#include<cstdlib>

float fun1(float x1);
float fun2(float x2);

int main (int argc, char *argv[])
{
  //presicion y notacion cientifica
  std::cout.precision(8);
  std::cout.setf(std::ios::scientific);
  //el ejercicio pide que no use double 
  float x=0;
  
  for(x=0; x<=1; x+=0.01){   
    //imprime la x, la funcion y la funcion modificada
    std::cout<< x <<"\t"<< fun1(x) <<"\t" << fun2(x) << std::endl;
  }
  return 0;
}
//funcion original 
float fun1(float x1)
{
  return 5-std::sqrt(25+x1*x1);
}
//funcion modificada con la info de la pag 24 de la presentacion de errores
float fun2(float x2)
{
  return (x2*x2)/(-5-std::sqrt(25+x2*x2));
}
