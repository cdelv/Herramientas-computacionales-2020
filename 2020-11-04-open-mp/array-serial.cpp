#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>


void print_elapsed(auto start, auto end);

int main(int argc, char **argv)
{
  int N=std::atoi(argv[1]);
  double * data =new double [N]; //pedimos memoria porque no cabe en la ram


  
  auto start = std::chrono::steady_clock::now();
  for(int i=0; i<N; i++) //fill the array
    {
      data[i]=std::sin(i)+std::log(i+1);
    }
  auto end = std::chrono::steady_clock::now();

  

  //compute mean

  //print
  print_elapsed(start, end);
  std::cout<<data[N/2]<<std::endl;
  delete [] data;


  return 0;
}
void print_elapsed(auto start, auto end )
{
  std::cout << "Elapsed time in ms: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
            << "\n";
}
