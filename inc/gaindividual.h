#ifndef GAINDIVIDUAL_H
#define GAINDIVIDUAL_H

#include <stdlib.h>

struct indiValue {
    double x;
    double y;
};

const double inf_val = -5;
const double sup_val = 5;


class GAIndividual
{
    indiValue value;
    double fitness;
public:
    GAIndividual(double value_x, double value_y);
    void evalFitness();
    double getFitness();
    indiValue getValue();
    void mutate();
};

double drand(double min, double max);
GAIndividual cross(GAIndividual indv_1, GAIndividual indv_2);

#endif // GAINDIVIDUAL_H
