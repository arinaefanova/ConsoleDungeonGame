#ifndef ZOOLS2023_XEFANOVA_GAMESTORAGE_H
#define ZOOLS2023_XEFANOVA_GAMESTORAGE_H

#include "Game.h"

// Singleton class

class GameStorage {
    static std::vector<Game*> s_games;

    GameStorage() = default;

    static void createGame();

    static void showSavedGames();

    static void processChoices(int choice);

    static void enterSelect();

public:

    static void menuGame();

    static std::vector<Game*>& getGames();

    ~GameStorage();
};


#endif //ZOOLS2023_XEFANOVA_GAMESTORAGE_H
