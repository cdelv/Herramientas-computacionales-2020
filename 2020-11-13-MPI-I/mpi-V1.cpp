//mpic++ mpi-V1.cpp
//mpirun -np 4 --oversubscribe ./a.out
#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  std::cout <<"Hello world"<<std::endl;;

  MPI_Finalize();
  return 0;
}
