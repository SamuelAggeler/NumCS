#include "eigen/Eigen/Dense"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << "Test validity of cyclic permutation implementation in Eigen"
              <<std::endl;
    Eigen::VectorXd v{Eigen::VectorXd::LinSpaced(10, 1, 10)};
    std::cout << "Column vector v = " << v.transpose() << std::endl;

    const int n = v.size();
    v << v[n-1], v.head(n-1);
    std::cout << "Permuted column vector v = " << v.transpose() << std::endl;

    return 0;

}