#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <omp.h>

double fun(double x);
double simpson (double a, double b, int n, int nThreads);
template <typename t1, typename t2>
void print_elapsed(t1 start, t2 end );

int main(int argc, char **argv)
{
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);
  
  double a=0, b=10, N=1000000;

  int nThreads=std::atoi(argv[1]);

  auto start = std::chrono::steady_clock::now();
   simpson(a,b, N, nThreads);//<<std::endl;
  auto end = std::chrono::steady_clock::now();
  print_elapsed(start, end);
  
  return 0;
}
//funcion para integrar
double fun(double x)
{
  return x*x;
}
//integracion
double simpson (double a, double b, int n, int nThreads)
{
  double h=(b-a)/n;
  double suma=0, x=0;

  #pragma omp parallel for num_threads(nThreads) reduction(+: suma)
  for(int ii=0; ii<=n; ii++){
    x=a+h*ii;

    if(ii==0 || ii==n){
      suma+=fun(x);
    }
    else{ if(ii%2==0){suma+=2*fun(x);}
      else{suma+=4*fun(x);}
    }
  }
    return suma*h/3;
  }

template <typename t1, typename t2>
void print_elapsed(t1 start, t2 end )
{
  std::cout.precision(6); std::cout.setf(std::ios::scientific);
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start)\
.count()/1000.0 << "\n";
}

