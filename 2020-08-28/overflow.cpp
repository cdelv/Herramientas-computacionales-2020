#include<iostream>
#include<cstdlib>

int main (int argc, char *argv[])
{
  std::cout.precision(15);
  
  double under= 1.0;
  double over= 1.0;
  int  N= std::atoi(argv[1]);
  
  for (int ii=0; ii<N; ii++ ){
    under /=2.0;
    over *=2.0;
    std::cout << ii
	      <<"\t" << under
	      <<"\t" << over
	      <<"\n";
  }


  return 0;
}
