#include "eigen/Eigen/Dense"

double lsqsolve_eigen(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd& x) {
    //Cost of =(n^2*m)
    x = A.householderQr().solve(b);
    return ((A*x-b).norm());
}