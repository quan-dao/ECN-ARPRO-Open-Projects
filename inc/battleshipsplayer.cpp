#include "battleshipsplayer.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>


battleShipsPlayer::battleShipsPlayer(std::string name, int map_size, bool manual_init_map) : name_(name), map_size_(map_size), health_(0),
    my_map(map_size*map_size, '-'), enemy_map(map_size*map_size, '-')
{
    // initialize fleet
    fleet.push_back({'A', 5});
    fleet.push_back({'C', 4});
    fleet.push_back({'D', 3});
    fleet.push_back({'S', 3});
    fleet.push_back({'M', 2});

    // initialize boat list
    for (int i = 0; i < fleet.size(); ++i) {
        boats_list_.push_back(fleet[i].type);
    }

    // initialize heath
    for (int i = 0; i < fleet.size(); ++i) {
        health_ += fleet[i].len;
    }

    initializeMap(manual_init_map);
}


char& battleShipsPlayer::getCell(int x, int y, char who)
{
    if (who == 'm')
        return my_map[x + map_size_ * y];
    else
        return enemy_map[x + map_size_ * y];
}


int randInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}


void battleShipsPlayer::initializeMap(bool manual)
{
    if (manual) {
        for (int i = 0; i < my_map.size(); ++i) {
            for(int j = 0; j < my_map.size(); ++j) {
                std::cout << "cell ("<<i<<","<<j<<"): ";
                std::cin >> getCell(i, j);
                std::cout << "\n";
            }
        }
    } else {
        for (int i = 0; i < fleet.size(); ++i) {
            bool ship_created = false;
            while (!ship_created) {
                int x = randInRange(0, map_size_-1);
                int y = randInRange(0, map_size_-1);
                int dir = rand() % 2; // 1: vertical, 0: horizontal

                bool dir_check = false;
                if ((1 - dir) * x + dir * y + fleet[i].len - 1 <= 9) {dir_check = true;}

                if (dir_check) {
                    bool not_intersect = true;
                    int offset = 0;
                    while (not_intersect && offset < fleet[i].len) {
                        if (getCell(x + (1-dir) * offset, y + dir * offset) == '-') {
                            offset += 1;
                        } else {
                            not_intersect = false;
                        }
                    }
                    if (not_intersect) {
                        // create ship
                        for (int j = 0; j < fleet[i].len; ++j) {
                            getCell(x + (1-dir) * j, y + dir * j) = fleet[i].type;
                        }
                        ship_created = true;
                    }
                }
            }
        }
    }
}


void battleShipsPlayer::display(char who)
{
    std::cout << "\t";
    for (int i = 0; i < map_size_; ++i) {
        std::cout << i << "\t";
    }
    std::cout << "\n";

    for (int j = 0; j < map_size_; ++j) {
        std::cout << j << "\t";
        for (int i = 0; i < map_size_; ++i) {
            std::cout << getCell(i, j, who) << "\t";
        }
        std::cout<<"\n";
    }
}


void battleShipsPlayer::shoot(battleShipsPlayer &player)
{
    int x;
    int y;
    if (name_ == "human") {
        std::cout << "targeted cell x: ";
        std::cin >> x;
        std::cout <<"targeted cell y: ";
        std::cin >> y;
    } else {
        bool valid_target = false;
        while (!valid_target) {
            x = randInRange(0, map_size_);
            y = randInRange(0, map_size_);
            if (getCell(x, y, 'e') == '-')
                valid_target = true;
        }
    }

    bool check_hit = false;
    int i = 0;
    while (!check_hit && i < boats_list_.size()){
        if (player.getCell(x, y) == boats_list_[i]) {
            check_hit = true;
        } else {
            i += 1;
        }
    }
    if (check_hit) {
        player.getCell(x, y) = 'O';
        player.decreaseHealth();
        getCell(x, y, 'e') = 'O';
    } else {
        getCell(x, y, 'e') = 'x';  // miss
    }
}


void battleShipsPlayer::decreaseHealth()
{
    health_ -= 1;
}


bool battleShipsPlayer::checkAlive()
{
    return health_ > 0;
}


int battleShipsPlayer::getHealth()
{
    return health_;
}
