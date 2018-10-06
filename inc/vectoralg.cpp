#include "vectoralg.h"

vectorAlg::vectorAlg(unsigned int n, double v0) : std::vector<double> (n, v0)  // initialize by calling the constructor of std::vector<dobule>
{

}


vectorAlg vectorAlg::operator +(const vectorAlg rhs) const
{
    vectorAlg re(size());  // size() is a method of std::vector
    for (unsigned int i = 0; i < rhs.size(); i++) {
        re[i] = at(i) + rhs.at(i);  // at(i) like [i], but it checks if i is valid first
    }

    return re;
}


vectorAlg operator *(double alpha, vectorAlg v)
{
    vectorAlg re(v.size());
    for (unsigned int i = 0; i < v.size(); i++) {
        re[i] = alpha * v[i];
    }
    return re;
}


vectorAlg& vectorAlg::operator =(const vectorAlg rhs)
{
    resize(rhs.size());
    for (unsigned int i = 0; i < rhs.size(); i++) at(i) = rhs[i];

    return *this;
}
