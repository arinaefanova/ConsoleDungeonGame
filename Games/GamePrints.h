#ifndef ZOOLS2023_XEFANOVA_GAMEPRINTS_H
#define ZOOLS2023_XEFANOVA_GAMEPRINTS_H


#include "../Heroes/Player.h"
#include "Game.h"

class GamePrints {
public:
    static void printError(int codeError);

    static void printError(char codeError);

    static void printMenuApplication();

    static void printMenuGame(std::string tileItem, std::string tileWeapon, std::string tileEnemy);

    static void printPlayerInfo(Player* player);

    static void printStart();

    static std::string getTileWeapon(Player* player, Map* map);

    static std::string getTileEnemy(Player* player, Map* map);

    static std::string getTileItem(Player* player, Map* map);

    static void printWin();

    static void printLose();
};


#endif //ZOOLS2023_XEFANOVA_GAMEPRINTS_H
