#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    srand(1);
    // unif entre -1 y 1
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(3, 3);
    std::cout << m << std::endl;

    Eigen::Matrix2d m2;
    m2 << 1, 2,
        4, 4;
    std::cout << m2 << std::endl;
    m2.setRandom();
    std::cout << m2 << std::endl;
    
    return 0;
}
