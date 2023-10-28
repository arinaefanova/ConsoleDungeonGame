#ifndef ZOOLS2023_XEFANOVA_GAME_H
#define ZOOLS2023_XEFANOVA_GAME_H


#include <string>
#include "../Heroes/Player.h"
#include "../Maps/Map.h"
#include "../Maps/MapDirector.h"

class Game {
    int m_size;
    std::string m_gameName;
    Player* m_player;
    Map* m_map;
    MapDirector* m_director;

private:
    void showMenu(bool print);

    static void deleteGameByName(const std::string& gameName);

    void selectUp();
    void selectLeft();
    void selectDown();
    bool selectRight();

    void selectTakeItem();
    void selectTakeWeapon();
    bool selectFight();

    bool processSelect(char select);

public:
    explicit Game(std::string gameName);

    void startGame();

    void loadGame();

    std::string getGameName(){return m_gameName;};

    ~Game();
};


#endif //ZOOLS2023_XEFANOVA_GAME_H
