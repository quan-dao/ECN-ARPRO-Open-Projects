#include "../inc/gaindividual.h"
#include "../inc/gapopulation.h"
#include <time.h>
#include <iostream>


int main()
{
    srand(time(NULL));  // initialize random seed
    // indiv 1
    GAIndividual indiv_1(0, 0);
    indiv_1.evalFitness();
    // indiv 2
    GAIndividual indiv_2(-2, 4);
    indiv_2.evalFitness();

    std::cout << "Fitness of 1:\t"<< indiv_1.getFitness() << "\tFitness of 2:\t"<< indiv_2.getFitness() << "\n";

    //crossover
    auto new_indi = cross(indiv_1, indiv_2);
    new_indi.evalFitness();
    std::cout << "-------- New individual info -------------\n";
    std::cout << "Value:\t" << new_indi.getValue().x << "\t" << new_indi.getValue().y << "\n";
    std::cout << "Fitness:\t" << new_indi.getFitness() << "\n";

    std::cout << "-------- Mutatted New individual -------------\n";
    new_indi.mutate();
    new_indi.evalFitness();
    std::cout << "Value:\t" << new_indi.getValue().x << "\t" << new_indi.getValue().y << "\n";
    std::cout << "Fitness:\t" << new_indi.getFitness() << "\n";

    // create a new population contains 3 individuals above
    GAPopulation new_popu;
    new_popu.add(indiv_1);
    new_popu.add(indiv_2);
    new_popu.add(new_indi);
    auto best_indv = new_popu.getBest();
    std::cout << "Best fitness among the population:" << best_indv.getFitness();


    return 0;
}
