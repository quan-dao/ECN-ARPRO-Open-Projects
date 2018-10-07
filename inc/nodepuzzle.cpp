#include "nodepuzzle.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>


NodePuzzle::NodePuzzle() : weight_to_neighbor_(1), current_state_(9, '-'), cost_(RAND_MAX)
{
    desired_state_ = {'1', '2', '3', '4', '5', '6', '7', '8', '.'};
}


void swap(char &a, char &b)
{
    int temp = b;
    b = a;
    a = temp;
}


void NodePuzzle::setCurrentState(std::vector<char> state)
{
    current_state_ = state;
}


void NodePuzzle::setPredessorState(std::vector<char> state)
{
    predessor_state_ = state;
}


void NodePuzzle::displayState()
{
    std::cout << "------------------------\n";
    for(int y = 0; y < 3; ++y){
        for (int x = 0; x < 3; ++x) {
            std::cout << current_state_[x + 3 * y] << "\t|";
        }
        std::cout << "\n";
    }
    std::cout << "------------------------\n";
}


coord2d findInState(std::vector<char> state, char what)
{
    auto it = std::find(state.begin(), state.end(), what);
    auto scalar_pos = it - state.begin();
    int x = (int) scalar_pos % 3;
    int y = (int) scalar_pos / 3;

    return {x, y};
}


std::vector<NodePuzzle> NodePuzzle::getNeighbors()
{
    /*
    find the position of '.'
    check for 4 moving direction
    produce to neighbors
    */

    // initialize output
    std::vector<NodePuzzle> re;

    // find the position of '.'
    auto dot_coord = findInState(current_state_, '.');
    int x = dot_coord.x;
    int y = dot_coord.y;

    // move right
    if (x < 2) {
        NodePuzzle new_node;
        auto new_state = current_state_;
        swap(new_state[x + 3 * y], new_state[x + 1 + 3 * y]);
        new_node.setCurrentState(new_state);
        re.push_back(new_node);
    }

    // move left
    if (x > 0) {
        NodePuzzle new_node;
        auto new_state = current_state_;
        swap(new_state[x + 3 * y], new_state[x - 1 + 3 * y]);
        new_node.setCurrentState(new_state);
        re.push_back(new_node);
    }

    // move up
    if (y > 0) {
        NodePuzzle new_node;
        auto new_state = current_state_;
        swap(new_state[x + 3 * y], new_state[x + 3 * (y - 1)]);
        new_node.setCurrentState(new_state);
        re.push_back(new_node);
    }

    // move down
    if (y < 2) {
        NodePuzzle new_node;
        auto new_state = current_state_;
        swap(new_state[x + 3 * y], new_state[x + 3 * (y + 1)]);
        new_node.setCurrentState(new_state);
        re.push_back(new_node);
    }

    return re;
}


int NodePuzzle::evalHeuristic()
{
    if (current_state_ == desired_state_)
        return 0;

    int h = 0;
    for (auto what : current_state_) {
        auto what_current = findInState(current_state_, what);
        auto what_desired = findInState(desired_state_, what);
        h += (std::abs(what_current.x - what_desired.x) + std::abs(what_current.y - what_desired.y));
    }

    return h;
}


void NodePuzzle::setCost(int cost)
{
    cost_ = cost;
}


int NodePuzzle::getCost()
{
    return cost_;
}


std::vector<char> NodePuzzle::getCurrentState()
{
    return current_state_;
}


bool NodePuzzle::reachDesiredState()
{
    return current_state_ == desired_state_;
}


int NodePuzzle::getWeight()
{
    return weight_to_neighbor_;
}
