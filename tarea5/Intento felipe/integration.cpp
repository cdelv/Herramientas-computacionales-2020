#include <iostream>
#include <cmath>
#include <chrono>
#include <omp.h>

double integral (int a, int b, int N, int Nth);

int main (int argc, char **argv){

    int a = std::atoi(argv[1]);
    int b = std::atoi(argv[2]);
    int N = std::atoi(argv[3]);
    const int Nth = std::atoi(argv[4]);

    double Int = 0, Time = 0;

    auto start = std::chrono::steady_clock::now();
    Int = integral(a, b, N, Nth);
    auto end = std::chrono::steady_clock::now();

    Time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0;

    std::cout.precision(6); std::cout.setf(std::ios::scientific);

    std::cout << Time << "\n"
              << Int << "\n";
    
    return 0;

}

double integral (int a, int b, int N, int Nth){

    double Int = 0.0;
    double l = (b-a)/(1.0*N);

#pragma omp parallel for num_threads(Nth) reduction(+:Int)
    for (int i = 1; i < N; i++){

        Int += std::pow(a + i*l ,2); 

    }

    Int += (std::pow(a ,2) + std::pow(b ,2))/2;
    Int *= l;

return Int;

}
