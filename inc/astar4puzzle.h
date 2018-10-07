#ifndef ASTAR4PUZZLE_H
#define ASTAR4PUZZLE_H

#include "nodepuzzle.h"
#include <vector>

class AStar4Puzzle
{
protected:
    NodePuzzle initialNode_;
    std::vector<NodePuzzle> pathNodes;
public:
    AStar4Puzzle(NodePuzzle initialNode);
    void findTarget();
    void buildPath();
};

#endif // ASTAR4PUZZLE_H
