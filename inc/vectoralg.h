#ifndef VECTORALG_H
#define VECTORALG_H
#include <vector>


class vectorAlg : public std::vector<double>
{
public:
    vectorAlg(unsigned int n, double v0 = 0);
    vectorAlg operator +(const vectorAlg rhs) const;
    vectorAlg& operator =(const vectorAlg rhs);
};


vectorAlg operator *(double alpha, const vectorAlg v);

#endif // VECTORALG_H
