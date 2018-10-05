#include "gapopulation.h"
#include <algorithm>


GAPopulation::GAPopulation()
{

}


void GAPopulation::add(GAIndividual new_indv)
{
    population.push_back(new_indv);
}


GAIndividual GAPopulation::getBest()
{
    auto best_indv = std::max_element(population.begin(), population.end(), [](GAIndividual indv_1, GAIndividual indv_2){return indv_1.getFitness() < indv_2.getFitness();});  // > result in Min element
    return *best_indv;
}
