#include "eigen/Eigen/Dense"

Eigen::MatrixXd nullspace(const Eigen::MatrixXd &A, double tol = ESP) {
    using index_t = Eigen::MatrixXd::Index;
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A,Eigen::ComputeFullV);
    index_t r = svd.setThreshold(tol).rank();
    Eigen::MatrixXd Z = svd.matrixV().rightCols(A.cols() -r);
    return Z;
}



