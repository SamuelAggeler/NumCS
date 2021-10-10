#include "eigen/Eigen/Dense"
#include <iostream>


int main(int argc, char const *argv[])
{
    std::cout << "test\n";
}

template <typename Matrix>
    void replaceWithId(Eigen::DenseBase<Matrix> &M){
    int n = M.cols();
    assert (n == M.rows() && n % 2 == 0);
    M.block(0,n/2,n/2,n/2) = Eigen::MatrixXd::Identity(n/2,n/2);
    }
             