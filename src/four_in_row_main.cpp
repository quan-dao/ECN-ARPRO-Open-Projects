#include </home/mquan/learnCpp/open_projects/inc/four_in_row_helper_classes.h>

int main()
{
    // initialize battle field
    BattleField battleField;

    /* GAME ON */
    int cntMove = 0;
    int maxMove = numRow * numCol;
    bool foundWinner = false;
    int choosenColumn;
    int winnerId;

    while (!foundWinner && cntMove < maxMove) {
        cout << "P1 choose column: ";
        cin >> choosenColumn;
        while (!battleField.throw_at_column(choosenColumn, 1)) {
            cout << "\nInvalid column! Choose new column";
            cin >> choosenColumn;
        }

        // check end game
        winnerId = battleField.check_end_game();
        if (winnerId > 0){
            foundWinner = true;
            cout << "\n Winner is: "<< winnerId << "\n";
        } else {
            cout << "P2 choose column: ";
            cin >> choosenColumn;
            while (!battleField.throw_at_column(choosenColumn, 2)) {
                cout << "\nInvalid column! Choose new column";
                cin >> choosenColumn;
            }
            // check end game
            winnerId = battleField.check_end_game();
            if (winnerId > 0){
                foundWinner = true;
                cout << "\n Winner is: "<< winnerId <<"\n";
            } else {
                cout << "Battle field after move " << cntMove << "\n";
                battleField.display();
                ++cntMove;
            }
        }
    }

    return 0;
}
