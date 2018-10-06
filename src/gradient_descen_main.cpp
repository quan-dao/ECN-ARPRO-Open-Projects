#include "../inc/vectoralg.h"
#include "../inc/ganorm.h"
#include <iostream>


int main()
{
    srand(time(NULL));
    const unsigned int n = 3;
    // create GD object
    gaNorm gradDescentObj(n);

    int iter = 0, iter_max = 20;

    while (!gradDescentObj.checkdf() && (iter < iter_max))
    {
        gradDescentObj.updateX();
        std::cout << "iter " << iter << "\t f = " << gradDescentObj.evalf() << "\n";
        ++iter;
    }

    return 0;
}


