#include<iostream>
#include<cstdlib>




float suma (float x, int  Nmax);

int main (int argc, char *argv[])
{
  std::cout.precision(7);
  std::cout.setf(std::ios::scientific);

  float xval=std::atoi(argv[1]);
  int N= std::atoi(argv[2]);

  
  std::cout << suma(xval, N) << "\n";

  return 0;
}

float suma (float x, int  Nmax)
{
  float sum=1.0;
  float term=1.0;
  
  for(int ii=2; ii<Nmax, ii++)
    {
    term = term*((-x)/(ii+1));
    sum = sum + term;
  }
  return sum;  
}
