#include "eigen/Eigen/SVD"

std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> svd_f (const Eigen::MatrixXd& A) {
    //Full SVD-Decomposition A = UΣV^H
    //JacobiSVD just computes the svd-Values in decreasing order, if we want U and V we need to pass it as arguments
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeFullU | Eigen::ComputeFullV);
    Eigen::MatrixXd U = svd.matrixU(); 
    Eigen::MatrixXd V = svd.matrixV();  
    Eigen::VectorXd sv = svd.singularValues(); // get SVD values as a vector
    Eigen::MatrixXd Sigma = Eigen::MatrixXd::Zero(A.rows(), A.cols()); // get a Zero Matrix with the same size as A
    const unsigned p = sv.size();   //get amount of SVD-values  
    Sigma.block(0,0,p,p) = sv.asDiagonal(); //initalize the SVD-Values as Diagonal
    return std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> (U,Sigma, V); //return constructed SVD composition 

}


std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> svd_e (const Eigen::MatrixXd& A) {
    //economical SVD-Decomposition A = UΣV^H
    //JacobiSVD just computes the svd-Values in decreasing order, if we want U and V we need to pass it as arguments
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    Eigen::MatrixXd U = svd.matrixU();
    Eigen::MatrixXd V = svd.matrixV();
    Eigen::VectorXd sv = svd.singularValues();
    Eigen::MatrixXd Sigma = sv.asDiagonal();
    return std::tuple<Eigen::MatrixXd,Eigen::MatrixXd, Eigen::MatrixXd> (U,Sigma, V);

}
    

