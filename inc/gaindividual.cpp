#include "gaindividual.h"
#include <math.h>


GAIndividual cross(GAIndividual indv_1, GAIndividual indv_2)
{
    double alpha_1 = drand(0,1);
    double alpha_2 = drand(0, 1);

    double new_x = alpha_1 * indv_1.getValue().x + (1 - alpha_1) * indv_2.getValue().x;
    double new_y = alpha_2 * indv_1.getValue().y + (1 - alpha_2) * indv_2.getValue().y;

    GAIndividual new_indv(new_x, new_y);
    return new_indv;
}


double drand(double min, double max)
{
    double alpha = (double) rand() / RAND_MAX;
    return min + alpha * (max - min);
}


GAIndividual::GAIndividual(double value_x, double value_y)
{
    // initialize an individual
    value.x = value_x;
    value.y = value_y;
    fitness = 0;
}


void GAIndividual::evalFitness()
{
    fitness = 20 + value.x * value.x + value.y * value.y - 10 * (cos(2 * M_PI * value.x) + cos(2 * M_PI * value.y));
}


double GAIndividual::getFitness()
{
    return fitness;
}

void GAIndividual::mutate()
{
    value.x += drand(0, 1);
    value.y += drand(0, 1);
}


indiValue GAIndividual::getValue()
{
    indiValue re;
    re.x = value.x;
    re.y = value.y;
    return re;
}
