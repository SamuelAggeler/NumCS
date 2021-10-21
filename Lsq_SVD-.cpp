#include "eigen/Eigen/Dense"

Eigen::VectorXd lsqsvd(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    Eigen::VectorXd sv = svd.singularValues();
    unsigned int r = svd.rank();
    Eigen::MatrixXd U = svd.matrixU(), V = svd.matrixV();

    return V.leftCols(r) * (sv.head(r).cwiseInverse().asDiagonal() * (U.leftCols(r).adjoint() * b));
}


//short form
Eigen::VectorXd lsqsvd_eigen(const Eigen::MatrixXd &A, const Eigen::VectorXd &b) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    return svd.solve(b);
}