#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include "vectoralg.h"

class gradientDescent
{
protected:
   vectorAlg x_;
   double alpha_;
public:
    gradientDescent(unsigned int n, double alpha = -0.01);
    virtual double evalf() = 0;
    virtual vectorAlg evaldf() = 0;
    virtual void updateX() = 0;
    virtual bool checkdf() = 0;
};

#endif // GRADIENTDESCENT_H
