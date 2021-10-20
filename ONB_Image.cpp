#include "eigen/Eigen/Dense"

Eigen::MatrixXd rangespace(const Eigen::MatrixXd &A, double tol = EPS) {
    using index_t = Eigen::MatrixXd::Index;
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A,Eigen::ComputeFullV);
    index_t r = svd.setThreshold(tol).rank();
    return svd.matrixU().leftCols(r);
}