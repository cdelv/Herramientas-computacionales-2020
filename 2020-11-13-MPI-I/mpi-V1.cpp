//mpic++ mpi-V1.cpp
//mpirun -np 4 --oversubscribe ./a.out
#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int pid=0; int nproc=0;

  MPI_Comm_rank(MPI_COMM_WORLD, & pid);
  MPI_Comm_size(MPI_COMM_WORLD, & nproc);

  std::cout <<"Hello world from "<<pid<<" out of "<<nproc<<std::endl;;

  MPI_Finalize();
  return 0;
}
