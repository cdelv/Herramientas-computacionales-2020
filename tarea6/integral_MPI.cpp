//compute the integral of x^2

#include <iostream>
#include "mpi.h"

void integral(int NSlocal, int pid, int nproc, int N);

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int pid = 0, nproc = 0;

    const int N = 6000000;

    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    const int NSlocal = N/nproc;

    double start = MPI_Wtime();
    integral(NSlocal, pid, nproc, N);
    double end = MPI_Wtime();

    if(pid == 0) std::cout << end-start << "\n";
    
    MPI_Finalize();
    
    return 0;
}


void integral(int NSlocal, int pid, int nproc, int N)
{
    int tag = 0;
    double xlocal = 0.0, delta = 0.0, Inlocal = 0.0;
    delta = 100.0/N;
    for(int ilocal = 0; ilocal < NSlocal; ++ilocal){
        xlocal = (ilocal+pid*NSlocal)*delta;
        Inlocal += xlocal*xlocal*delta;
    }
    if(pid == 0){
        double aux, I;
        I = Inlocal;
        for(int src = 1; src < nproc; ++src){
            MPI_Recv(&aux, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            I += aux;
        }
        std::cout.precision(14);
        std::cout << "La integral es:" << I << "\n";
    } else {
        int dest = 0;
        MPI_Send(&Inlocal, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
    }
}
