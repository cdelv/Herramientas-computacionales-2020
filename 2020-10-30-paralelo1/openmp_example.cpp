//g++ -fopenmp openmp_example.cpp
//export OMP_NUM_THREADS=4

#include <iostream>
#include<omp.h>

int main(void)
{
  double x=10; //variable pública
  #pragma omp parallel
  {
    double y=10; //variable privada
    
    int tid=omp_get_thread_num(); //dice el ID del thread
    int nth=omp_get_num_threads();

    if(tid==0){
    std::cout << "number of threads: " << nth<<"\n" <<std::endl;
    }
    
      std::cout << "Hello world, from thread "<<tid<<"\n" << std::endl;
  }
  return 0;
}
