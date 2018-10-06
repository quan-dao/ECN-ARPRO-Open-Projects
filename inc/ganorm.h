#ifndef GANORM_H
#define GANORM_H

#include "gradientdescent.h"

class gaNorm :public gradientDescent
{

public:
    gaNorm(unsigned int n);
    virtual double evalf();
    virtual vectorAlg evaldf();
    virtual void updateX();
    virtual bool checkdf();
};

#endif // GANORM_H
