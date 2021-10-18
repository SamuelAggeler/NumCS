#include "eigen/Eigen/Dense"

// backwards subsitution starting from a_n and solving back to a_1 Runtime O(n^2)
// Never use eigen.invers function use solver instead


Eigen::MatrixXd U;
Eigen::MatrixXd L;
Eigen::VectorXd b;

//used for solving forward substitution
Eigen::VectorXd y = L.triangularView<Eigen::UnitLower>().solve(b);

//used for backward substitution
Eigen::VectorXd d = U.triangularView<Eigen::Upper>().solve(y);

// because Matrix is positiv definitiv we have more efficient solver llt or ldlt 
Eigen::VectorXd x = lhs.lu().solve(rhs);

//linear Date Fitting

//HouseHolderQR / FullPivHousholderQR / ColPivHousholderQR difference numeric stable vs speed
//generally doesn't matter which one we choose.

//shape Identification 




