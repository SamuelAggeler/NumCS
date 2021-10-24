#include "Eigen/Dense"

std::pair<Eigen::VectorXd, Eigen::VectorXd> hyperlsq( const Eigen::MatrixXd& A, const unsigned dim) {
    unsigned p = A.cols(), m = A.rows();
    if (p < dim + 1) {
        throw std::runtime_error ("not enough unknowns");
    }
    if (m < dim) {
        throw std::runtime_error("not enough equations");
    }
    m = std::min(m,p);
    Eigen::MatrixXd R = A.householderQr().matrixQR().template triangularView<Eigen::Upper>(); // use QR-decomposition to obtain R Matrix
    Eigen::MatrixXd V = R.block(p - dim, p - dim, m + dim - p, dim).jacobiSvd(Eigen::ComputeFullV).matrixV(); // obtain A tilde in the sketch (everything thats dependant on n) and compute SVD
    Eigen::VectorXd n = V.col(dim-1); //solution is the right most column of V
    const auto R_topleft = R.topLeftCorner(p - dim, p - dim);
    const auto R_diag = R_topleft.diagonal().cwiseAbs();
    if (R_diag.minCoeff() < (std::numeric_limits<double>::epsilon()) * R_diag.maxCoeff())
        throw std::runtime_error ("Upper left block of R is not regular");
    Eigen::VectorXd  c = -(R_topleft.template triangularView<Eigen::Upper>()).solve(R.block(0, p - dim, p - dim, dim) * n);
    return {c,n};
}