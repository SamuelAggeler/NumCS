#include "Eigen/Dense"

Eigen::VectorXd signalgen() {
    const int N = 64;
    const Eigen::ArrayXd t = Eigen::ArrayXd::LinSpaced(N, 0, N);
    //create two strong singals
    const Eigen::VectorXd x = ((2*M_PI/N*t).sin() + (14*M_PI/N*t).sin()).matrix();
    //return signal with some white noice from a random vector
    return x + Eigen::VectorXd::Random(N);
}