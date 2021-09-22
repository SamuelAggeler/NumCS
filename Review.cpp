#include <Eigen/Dense>

template <typename Matrix>
    void replaceWithId(Eigen::DenseBase<Matrix> &M){
    const int row = M.rows();
    const int col = M.cols();

    if(row == col && row %2 == 0) {
        index_t p = row/2;
        index_t q = row/2;
        MatrixXd B = M.block()
    }
    }