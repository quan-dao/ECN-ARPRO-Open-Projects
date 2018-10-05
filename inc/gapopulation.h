#ifndef GAPOPULATION_H
#define GAPOPULATION_H

#include <vector>
#include "gaindividual.h"


class GAPopulation
{
    std::vector<GAIndividual> population;
public:
    GAPopulation();
    void add(GAIndividual new_indv);
    GAIndividual getBest();
};

#endif // GAPOPULATION_H
