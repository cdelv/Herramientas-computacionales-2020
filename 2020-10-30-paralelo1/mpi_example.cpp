//mpic++ -showme  para ver las banderas que pone
//mpic++ para compilar
//mpirun -np 4 ./a.out para que corra con 4 procesos

#include <iostream>
#include <mpi.h>

int main (int argc, char **argv)
{
  MPI_Init(&argc, &argv); //siempre hay que hacerlo para empezar la rutina
  
  int rank, size; //rank es el ID y size cuántos hay
  MPI_Comm_size(MPI_COMM_WORLD,&size); //dice cuántos hay
  MPI_Comm_rank(MPI_COMM_WORLD,&rank); //quien es
  
  std::cout<< "Hello fromprocess:" <<rank <<" out of "<<size<<std::endl;
  
  MPI_Finalize(); //siempre hay que cerrar la rutina
  
  return 0;
}
