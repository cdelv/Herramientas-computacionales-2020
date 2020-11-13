#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    int N = std::atoi(argv[1]); 
    Eigen::MatrixXd A(N, N);
    Eigen::VectorXd b(N);
    A = Eigen::MatrixXd::Random(N, N);
    b = Eigen::VectorXd::Random(N);
    //std::cout << "Here is the matrix A:\n" << A << std::endl;
    //std::cout << "Here is the vector b:\n" << b << std::endl;
    Eigen::VectorXd x(N) ;
    //x = A.colPivHouseholderQr().solve(b);
    x = A.partialPivLu().solve(b);
    //std::cout << "The solution is:\n" << x << std::endl;
    std::cout << "Error: " << (A*x - b).norm() << std::endl;
}
