#ifndef BATTLESHIPSPLAYER_H
#define BATTLESHIPSPLAYER_H

#include <string>
#include <vector>

struct boat {
    char type;
    int len;
};


class battleShipsPlayer
{
protected:
    std::string name_;
    int map_size_;
    int health_;
    std::vector<char> my_map;
    std::vector<char> enemy_map;
    std::vector<boat> fleet;
    std::vector<char> boats_list_;
public:
    battleShipsPlayer(std::string name, int map_size, bool manual_init_map=false);
    void initializeMap(bool manual);
    void shoot(battleShipsPlayer &player);  // pass-by-reference, for the change made on player inside shoot to remain after the function shoot finish
    bool checkAlive();
    char& getCell(int x, int y, char who='m');
    void display(char who='m');
    void decreaseHealth();
    int getHealth();
};

#endif // BATTLESHIPSPLAYER_H
