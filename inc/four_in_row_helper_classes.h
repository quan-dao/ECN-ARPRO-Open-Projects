#ifndef FOUR_IN_ROW_HELPER_CLASSES
#define FOUR_IN_ROW_HELPER_CLASSES

#endif // FOUR_IN_ROW_HELPER_CLASSES

#include <iostream>
#include <vector>

using namespace std;

const int numRow = 6, numCol = 7;
const int identicalCoinsThreshold = 3;  // threshold for number of coins that are identical to last move coin
const char player1Coin = 'O', player2Coin = 'x';

class BattleField
{
    vector<vector<char> > field;
    int lastMove[3];  // {rowIdx, colIdx, playerId} - used for check_end_game()
public:
    BattleField();  // constructor
    void display();
    bool throw_at_column(int colIdx, int playerId);
    int check_end_game();
    int count_coin_1dir(char checkType, char justDroppedCoin);  // dir = 1 go Left, = -1 go Right; checkType = 'r', 'c'
    int count_coin_2dir(char checkType, char justDroppedCoin);  // checkType = 'D', 'd'
};


BattleField::BattleField()
{
    /* initialize size */
    field.resize(numRow);
    for(int i = 0; i < numRow; ++i){
        field[i].resize(numCol);
    }

    /* initialize value*/
    for (int i = 0; i < numRow; ++i){
        for (int j = 0; j < numCol; ++j){
            field[i][j] = '-';
        }
    }
}


void BattleField::display()
{
    // horizontal number line
    for (int j = 0; j < numCol; ++j){
        cout << "\t" << j;
    }
    cout << "\n";

    for(int i = 0; i < numRow; ++i){
        cout << i << "\t";
        for(int j = 0; j < numCol; ++j){
            cout << field[i][j] << "\t";
        }
        cout << "\n";
    }
}


bool BattleField::throw_at_column(int colIdx, int playerId)
{
    // return true if the column is valid
    int idxRow = numRow - 1;
    bool foundEmptyCell = false;
    while (!foundEmptyCell && idxRow > -1){
        if(field[idxRow][colIdx] == '-'){
            foundEmptyCell = true;
        }else{
            --idxRow;
        }
    }

    if (foundEmptyCell){
        // change the cell according to player_id
        if (playerId == 1){
            field[idxRow][colIdx] = player1Coin;
        }else{
            field[idxRow][colIdx] = player2Coin;
        }

        // Update lastMove
        lastMove[0] = idxRow;
        lastMove[1] = colIdx;
        lastMove[2] = playerId;

        return true;
    }else{
        return false;
    }
}


int BattleField::check_end_game()
{
    // identify justDroppedCoin
    char justDroppedCoin;
    if (lastMove[2] == 1){
        justDroppedCoin = player1Coin;
    }else{
        justDroppedCoin = player2Coin;
    }

    int numIdenticalCoins;

    /* Row check */
    numIdenticalCoins = count_coin_1dir('r', justDroppedCoin);

    /* Column check */
    if (numIdenticalCoins < identicalCoinsThreshold){
        numIdenticalCoins = count_coin_1dir('c', justDroppedCoin);
    }

    /* Main Diagonal check */
    if (numIdenticalCoins < identicalCoinsThreshold){
        numIdenticalCoins = count_coin_2dir('D', justDroppedCoin);
    }

    /* Suplement diag. check */
    if (numIdenticalCoins < identicalCoinsThreshold){
        numIdenticalCoins = count_coin_2dir('d', justDroppedCoin);
    }

    if (numIdenticalCoins == identicalCoinsThreshold){
        return lastMove[2];  // id of the winner
    } else {
        return 0;  // not end yet!
    }

}


int BattleField::count_coin_1dir(char checkType, char justDroppedCoin)
{
    // go 2 ways
    int numIdenticalCoins = 0;

    bool sameCoinDecrease = true, sameCoinIncrease = true;

    int idxRollingDecrease, idxRollingIncrease, idxSup;
    if (checkType == 'r') {
        idxRollingDecrease = lastMove[1] - 1;
        idxRollingIncrease = lastMove[1] + 1;
        idxSup = numCol;
    } else {
        idxRollingDecrease = lastMove[0] - 1;
        idxRollingIncrease = lastMove[0] + 1;
        idxSup = numRow;
    }

    while ((sameCoinDecrease || sameCoinIncrease) && (numIdenticalCoins < identicalCoinsThreshold)){
        char newCoinDecrease = '-', newCoinIncrease = '-';
        if (checkType == 'r'){
            if (idxRollingDecrease > -1) {
                newCoinDecrease = field[lastMove[0]][idxRollingDecrease];
            }
            if (idxRollingIncrease < idxSup) {
                newCoinIncrease = field[lastMove[0]][idxRollingIncrease];
            }
        } else {
            if (idxRollingDecrease > -1) {
                newCoinDecrease = field[idxRollingDecrease][lastMove[1]];
            }
            if (idxRollingIncrease < idxSup) {
                newCoinIncrease = field[idxRollingIncrease][lastMove[1]];
            }
        }

        /* compare to justDroppedCoin */
        // decrease
        if (newCoinDecrease == justDroppedCoin) {
            --idxRollingDecrease;
            ++numIdenticalCoins;
        } else {
            sameCoinDecrease = false;
        }
        // increase
        if (newCoinIncrease == justDroppedCoin) {
            ++idxRollingIncrease;
            ++numIdenticalCoins;
        } else {
            sameCoinIncrease = false;
        }
    }

    return numIdenticalCoins;
}


int BattleField::count_coin_2dir(char checkType, char justDroppedCoin)
{
    int numIdenticalCoins = 0;
    bool sameCoinUp = true, sameCoinDown = true;

    int idxRollingUp[2], idxRollingDown[2];

    int idxSup[2] = {numRow, numCol};

    if (checkType == 'D') {
        // main Diagonal
        idxRollingUp[0] = lastMove[0] - 1;
        idxRollingUp[1] = lastMove[1] - 1;
        idxRollingDown[0] = lastMove[0] + 1;
        idxRollingDown[1] = lastMove[1] + 1;
    } else {
        // complement diagonal
        idxRollingUp[0] = lastMove[0] - 1;
        idxRollingUp[1] = lastMove[1] + 1;
        idxRollingDown[0] = lastMove[0] + 1;
        idxRollingDown[1] = lastMove[1] - 1;
    }

    while ((sameCoinUp || sameCoinDown) && (numIdenticalCoins < identicalCoinsThreshold)) {
        /* get newCoin */
        char newCoinUp = '-', newCoinDown = '-';
        // if the idx pair is valid, newCoinUp and/or Down is updated
        if ((idxRollingUp[0] > -1) && (idxRollingUp[0] < idxSup[0]) && (idxRollingUp[1] > -1) && (idxRollingUp[1] < idxSup[1])) {
            newCoinUp = field[idxRollingUp[0]][idxRollingUp[1]];
        }
        if ((idxRollingDown[0] > -1) && (idxRollingDown[0] < idxSup[0]) && (idxRollingDown[1] > -1) && (idxRollingDown[1] < idxSup[1])) {
            newCoinDown = field[idxRollingDown[0]][idxRollingDown[1]];
        }

        /* comapre */
        // up
        if (newCoinUp == justDroppedCoin){
            ++numIdenticalCoins;
            --idxRollingUp[0];
            if (checkType == 'D'){
                --idxRollingUp[1];
            } else {
                ++idxRollingUp[1];
            }
        } else {
            sameCoinUp = false;
        }
        // down
        if (newCoinDown == justDroppedCoin){
            ++numIdenticalCoins;
            ++idxRollingDown[0];
            if (checkType == 'D'){
                ++idxRollingDown[1];
            } else {
                --idxRollingDown[1];
            }
        } else {
            sameCoinDown = false;
        }
    }

    return numIdenticalCoins;
}
