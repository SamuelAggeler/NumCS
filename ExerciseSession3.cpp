#include "eigen/Eigen/Dense"
#include <iostream>

int main(int argc, char const *argv[])
{
    
    auto glambda = [] (Eigen::MatrixXd A, Eigen::VectorXd b) -> Eigen::VectorXd {
        
        return A * b;
        
    };

    Eigen::MatrixXd A(3,3);

    A << 1,2,3,
         0,4,5,
         0,0,6;

    Eigen::MatrixXd b = Eigen::VectorXd::Constant(3,3);

    for(int i = 0; i < 30; i++) {
        Eigen::VectorXd temp = glambda(A, b);
        b = temp;
    }
    std::cout << b <<std::endl;
    return 0;
}
