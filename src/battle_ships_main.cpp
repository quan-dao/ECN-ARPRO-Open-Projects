#include <iostream>
#include "../inc/battleshipsplayer.h"

int main()
{
    int map_size = 10;
    battleShipsPlayer player_1("human", map_size);
    battleShipsPlayer player_2("com", map_size);

    std::cout << "human's map\n";
    player_1.display();
    std::cout << "COM's map\n";
    player_2.display();
    std::cout << "COM's health:\t" << player_2.getHealth()<<"\n";

    player_1.shoot(player_2);
    std::cout << "After being shot\n";
    std::cout << "human's enemy map\n";
    player_1.display('e');
    std::cout << "COM's map\n";
    player_2.display();
    std::cout << "COM's health:\t" << player_2.getHealth();


    return 0;
}
