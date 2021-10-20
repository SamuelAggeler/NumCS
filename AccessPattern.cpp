#include "eigen/Eigen/Dense"
#include <iostream>

int main(int argc, char const *argv[])
{
    Eigen::MatrixXd M = Eigen::MatrixXd::Random(5,5);
    Eigen::VectorXd x = Eigen::VectorXd::Random(5);
    std::cout <<"This is the Matrix M : " << std::endl;
    std::cout << M << std::endl;
    std::cout <<"This is the vector x : " << std::endl;
    std::cout << x << std::endl;
    std::cout <<"This is the inefficient Product : " << std::endl;
    std::cout << M*x << std::endl;

    std::cout <<"THis is the fast version : " << std::endl; 
    double* mptr = M.data();
    

    return 0;
}
