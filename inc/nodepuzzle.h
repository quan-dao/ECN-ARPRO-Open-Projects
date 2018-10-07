#ifndef NODEPUZZLE_H
#define NODEPUZZLE_H

#include <vector>

struct coord2d {
    int x;
    int y;
};


class NodePuzzle
{
protected:
    std::vector<char> current_state_;
    int weight_to_neighbor_;
    std::vector<char> desired_state_;
    std::vector<char> predessor_state_;
    int cost_;
public:
    NodePuzzle();  // initialize current_state & weight_to_neighbor
    std::vector<NodePuzzle> getNeighbors();
    void setPredessorState(std::vector<char> state);
    void setCurrentState(std::vector<char> state);
    int evalHeuristic();
    void setCost(int cost);
    int getCost();
    int getWeight();
    bool reachDesiredState();
    void displayState();
    std::vector<char> getCurrentState();
};

#endif // NODEPUZZLE_H
