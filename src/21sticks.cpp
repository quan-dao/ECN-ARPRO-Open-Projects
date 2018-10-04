#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    // initialize random seed
    srand(time(NULL));

    int user_picks;
    int comp_picks;
    int total_sticks = 21;
    int allow_pick = 3;

    while (true)
    {
        allow_pick = min(total_sticks, 3);
        /* User turn */
        cout << "\nUser turns\tPick between 1 and" << allow_pick << " : ";
        cin >> user_picks;
        while ((user_picks > allow_pick) || (user_picks < 1))
        {
            cout << "\nMust pick between 1 and" << allow_pick << "sticks\t Pick agian:";
            cin >> user_picks;
        }
        // Check for ending game condition
        total_sticks -= user_picks;
        if (total_sticks < 2)
        {
            cout << "\nUser win !!!";
            break;
        }

        /* comp turn */
        comp_picks = rand() % allow_pick + 1;
        // Check for ending game condition
        total_sticks -= comp_picks;
        if (total_sticks < 2)
        {
            cout << "\nCOMP win !!!";
            break;
        }

        cout<<"Left over sticks: "<< total_sticks;
    }

    return 0;
}
