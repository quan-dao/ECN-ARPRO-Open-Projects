#include "astar4puzzle.h"
#include <vector>
#include <algorithm>


AStar4Puzzle::AStar4Puzzle(NodePuzzle initialNode)
{
    initialNode_.setCurrentState(initialNode.getCurrentState());
}


bool foundIn(std::vector<NodePuzzle> set, NodePuzzle node)
{
    int i = 0;
    bool found = false;
    while (!found && i < set.size()) {
        if (set[i].getCurrentState() == node.getCurrentState())
            found = true;
        else
            i += 1;
    }
    return found;
}


void AStar4Puzzle::findTarget()
{
    initialNode_.setCost(0 +initialNode_.evalHeuristic());

    bool reach_target = false;

    std::vector<NodePuzzle> open_set, close_set;
    open_set.push_back(initialNode_);

    while (open_set.size() > 0 && !reach_target) {
        // get min
        auto it = std::min_element(open_set.begin(), open_set.end(), [](NodePuzzle &node1, NodePuzzle &node2){return node1.getCost() < node2.getCost();});
        NodePuzzle min_node = *it;

        // remove from open_set & add to close_set
        open_set.erase(it);
        close_set.push_back(min_node);

        if (min_node.reachDesiredState())
            reach_target = true;
        else {
            // get neighborhood of min node
            auto neighborhood = min_node.getNeighbors();
            for (NodePuzzle neighbor : neighborhood) {
                if (!foundIn(close_set, neighbor)) {
                    // update cost
                    if (neighbor.evalHeuristic() + min_node.getWeight() < neighbor.getCost()) {
                        neighbor.setCost(neighbor.evalHeuristic() + min_node.getWeight());
                        neighbor.setPredessorState(min_node.getCurrentState());
                    }
                    // update open_set
                    if (!foundIn(open_set, neighbor)) {
                        open_set.push_back(neighbor);
                    }
                }
            }
        }
    }

    for (NodePuzzle node : close_set) {
        node.displayState();
    }
}


void AStar4Puzzle::buildPath()
{

}
