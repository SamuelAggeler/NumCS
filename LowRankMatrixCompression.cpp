#include "Eigen/Dense"

Eigen::MatrixXd lowrankbestapprox (const Eigen::MatrixXd &A, unsigned int k) {
    //eco SVD
    const Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    //U_k Σ_k V_k
    //get Σ_k largest k SV as diagonal
    return (svd.matrixU().leftCols(k)) * (svd.singularValues().head(k).asDiagonal()) * (svd.matrixV().leftCols(k).transpose());
}

