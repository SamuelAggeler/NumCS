#include "eigen/Eigen/Dense"
#include <iostream>


int main(int argc, char const *argv[])
{
    std::cout << "test\n";
}

template <typename Matrix>
    void replaceWithId(Eigen::DenseBase<Matrix> &M){
    const int row = M.rows();
    const int col = M.cols();

    if(row == col && row %2 == 0) {
        const int p = row/2;
        const int q = row/2;
        //select the submatrix of size p*q with left upper entry at position 0,p
        Eigen::MatrixXd A(p,q);
        
        M.block<p,q>(0,p) = Eigen::MatrixXd::Identity(p,q);
        
    }
    }