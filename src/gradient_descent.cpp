#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;


double rand_range(double low, double up)
{
    return low + (up - low) * rand() / RAND_MAX;
}


double f(double a, double b, double x)
{
    // ax^2 + bx + 1
    return a * x * x + b *x + 1;
}


double diff_f(double a, double b, double x)
{
    return 2 * a * x + b;
}


int main()
{
    // initialize random seed
    srand(time(NULL));

    double a, b;
    a = 9 * ((double) rand()) / RAND_MAX + 1; // a random floating-point number between 1 and 10
    b = rand_range(2, 20);

    double lambda = 0.01;
    int iter = 0, max_iter = 100;
    int stuck_iter = 0, max_stuck_iter = 30;
    double stuck_threshold = 0.001;

    double x = 0;
    double last_x = x;
    // the 2nd exiting condition can be change to diff_f < diff_f_min (diff_f_min can be set to close to 0)
    while ((iter < max_iter) && (stuck_iter < max_stuck_iter))
    {
        x -= lambda * diff_f(a, b, x);
        // display result
        cout << "Interation " << iter << ":\t x= " << x << "\t f(x) =" << f(a, b, x) << "\n";

        // check for stuck condition
        double delta_f = f(a, b, x) - f(a, b, last_x);
        if (fabs(delta_f) < stuck_threshold)
        {
            stuck_iter += 1;
        }
        else
        {
            stuck_iter = 0;
        }

        // update last_x
        last_x = x;
        iter += 1;
    }

    if (stuck_iter == max_stuck_iter){
        // found the minimum
        cout << "Found minimum after "<< iter << " interations" << "\tx_min = "<< x << "\t divation from truth:"<< x + b / (2 * a) << "\n";
    }
    else{
        cout << "out of iteration, x = " << x << "\t divation from truth:"<< x + b / (2 * a) << "\n";
    }

    return 0;
}
