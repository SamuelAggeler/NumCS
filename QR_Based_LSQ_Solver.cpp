#include "eigen/Eigen/Dense"

double lsqsolve_eigen(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x) {
    x = A.householderQr().solve(b);
    return ((A*x-b).norm());
}