#include "eigen/Eigen/Dense"

template <typename Matrix>
    void replaceWithId(Eigen::DenseBase<Matrix> &M){
    const int row = M.rows();
    const int col = M.cols();

    if(row == col && row %2 == 0) {
        const int p = row/2;
        const int q = row/2;
        //select the submatrix of size p*q with left upper entry at position 0,p
        
        M.block<p,q>(0,p) = MatrixXd::Identity(p,q);
        std::cout << M <<;
    }
    }