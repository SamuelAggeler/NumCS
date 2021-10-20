#include "eigen/Eigen/Dense"

Eigen::MatrixXd::Index rankSVD(const Eigen::MatrixXd &A, double tol = EPS) {
    if (A.norm() == 0) {
        return Eigen::MatrixXd::Index(0);
    }
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    const Eigen::VectorXd sv = svd.singularValues();
    Eigen::MatrixXd::Index n = sv.size();
    Eigen::MatrixXd::Index r = 0;
    while ((r < n) && (sv (r) >= sv(0)* tol)) { //compare with largest singular value = sv(0)
        r++;
    }
    return r; // return nummerical rank
}

//Eigen has a predefined function for this
Eigen::MatrixXd::Index rank_eigen(const Eigen::MatrixXd &A, double tol = EPS) {
    return A.jacobiSvd().setThreshold(tol).rank();
}