#include <iostream>
#include <eigen3/Eigen/Eigenvalues>
#include <chrono>

double eigenval(int n);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const int Size = std::atoi(argv[1]); 
    const int Reps = std::atoi(argv[2]);
    const int Seed = std::atoi(argv[3]);
    srand(Seed);
    
    double t = 0;
    for (int irep = 0; irep < Reps; ++irep) {
        t += eigenval(Size);
    }
    std::cout << t/Reps <<"\n";

    return 0;
}

double eigenval(int n)
{
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(n, n);

    auto start = std::chrono::steady_clock::now();
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
    auto end = std::chrono::steady_clock::now();
    if (eigensolver.info() != Eigen::Success) abort();

    double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;

    return time;
}
