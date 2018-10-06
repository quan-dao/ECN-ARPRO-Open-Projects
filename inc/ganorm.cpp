#include "ganorm.h"
#include <stdlib.h>
#include <time.h>



gaNorm::gaNorm(unsigned int n) : gradientDescent(n)
{
    for (int i = 0; i < n; ++i) {
        x_[i] = -1 + (double)rand() / RAND_MAX * 2;  // create a random number in [-1, 1];
    }
}


double gaNorm::evalf()
{
    // calculate norm 2 of vector x
    double re = 0;
    for (unsigned int i = 0; i < x_.size(); ++i) {
        re += x_[i] * x_[i];
    }

    return re;
}


vectorAlg gaNorm::evaldf()
{
    vectorAlg re(x_.size());

    for (unsigned int i = 0; i < x_.size(); ++i) {
        re[i] = 2 * x_[i];
    }

    return re;
}


void gaNorm::updateX()
{
    x_ = x_ + alpha_ * evaldf();
}


bool gaNorm::checkdf()
{
    double re = 0;
    for (unsigned int i = 0; i < x_.size(); ++i) {
        re += x_[i] * x_[i];
    }

    return re < 1e-3;
}
