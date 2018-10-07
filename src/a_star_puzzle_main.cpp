#include <iostream>
#include <vector>
#include <algorithm>
#include "../inc/nodepuzzle.h"
#include "../inc/astar4puzzle.h"


int main()
{
    std::vector<char> a = {'1', '2', '3', '7', '4', '5', '8', '6', '.'};
//    std::vector<char> b = a;
//    if (b == a)
//        std::cout << "equal\n";
//    auto it = std::find(a.begin(), a.end(), '.');
//    std::cout << "found this: "<< *it <<"\n";
//    auto pos = it - a.begin();
//    std::cout << "distance from begin: "<<pos << "\n";
//    int x = (int) pos % 3;
//    int y = (int) pos / 3;
//    std::cout << "found at x = " << x <<"\ty = " << y <<"\n";

    NodePuzzle initial_node;
    initial_node.setCurrentState(a);

    AStar4Puzzle a_star_solver(initial_node);
    a_star_solver.findTarget();

//    auto neighbors = initial_node.getNeighbors();
//    std::cout << "neighbors state\n";
//    for(auto nei : neighbors) {
//        nei.displayState();
//    }

//    std::vector<coord2d> b;
//    b.push_back({1,1});
//    b.push_back({2,0});
//    b.push_back({3,5});
//    auto it = std::min_element(b.begin(), b.end(), [](coord2d &ele1, coord2d &ele2){return ele1.y < ele2.y;});
//    auto min_ele = *it;
//    std::cout << "min element = " << min_ele.y <<"\n";
//    // remove min
//    b.erase(it);
//    for(auto ele:b)
//        std::cout << ele.x << "\t";

}
