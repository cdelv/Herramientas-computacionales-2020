//Carlos Andrés del Valle
//Andrés Felipe Vargas Londoño

#include <cmath>
#include <cstdlib>
#include <iostream>


double myatan(double x, int n);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const int NSTEPS = std::atoi(argv[1]);// 53
    const double x = std::atof(argv[2]); // 4.2
    const double exact = std::atan(x);
    double my = myatan(x, NSTEPS);
    double diff = std::fabs(my-exact)/exact;
    std::cout << diff << std::endl;

    return 0;
}


double myatan(double x, int n)
{
  double a=std::pow(2,-n/2);
  double b=x/(1+std::pow(1+x*x,0.5));
  double c=1.0;
  double d=1.0; double aux=0; double f=0;
  double J;
  double Max=std::pow(2,-n);

  
  for (J=1-a ;J>Max; J=1-a)
    {
      aux=2*c/(1+a);                  c=aux;
      aux=2*a*b/(1+b*b);              d=aux;
      aux=d/(1+std::pow(1-d*d,0.5));  d=aux;
      aux=(b+d)/(1-b*d);              d=aux;
      aux=d/(1+std::pow(1+d*d,0.5));  b=aux;
      aux=2*std::pow(a,0.5)/(1+a);    a=aux;
    
      f=c*std::log((1+b)/(1-b));
    }
   
  return f;
}
