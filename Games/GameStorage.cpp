#include "GameStorage.h"
#include "GamePrints.h"


//Vector of saved games
std::vector<Game*> GameStorage::s_games;

//Function for processing menu choices of user.
void GameStorage::processChoices(int choice){
    switch (choice) {
        case 1:
            createGame();
            exit(0);
        case 2:
            showSavedGames();
            int whichGame;
            std::cout << "Enter the number of saved game to run:" << std::endl;
            while (!(std::cin >> whichGame) || whichGame < 0 || whichGame >= s_games.size()) {
                GamePrints::printError(1);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            s_games[whichGame]->loadGame();
            exit(0);
        case 3:
            exit(0);
        default:
            GamePrints::printError(5);
            exit(0);
    }
}

//Function for entering a menu parameter and controlling it.
void GameStorage::enterSelect(){
    int choose;
    while (!(std::cin >> choose) || choose < 1 || choose > 3) {
        GamePrints::printError(1);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    processChoices(choose);
}

//Function for displaying main menu of program. The static public function that called by the user in main.cpp
void GameStorage::menuGame(){
    GamePrints::printStart();
    GamePrints::printMenuApplication();
    enterSelect();
}

//Function creates a game, adds it to the vector of saved games and starts this game.
void GameStorage::createGame(){
    std::string gameName;
    std::cout << "Enter a name for the saved game: " << std::endl;
    std::cin >> gameName;
    Game* game = new Game(gameName);
    s_games.push_back(game);
    game->startGame();
}

//Function for displaying saved games
void GameStorage::showSavedGames(){
    if (s_games.empty()){
        GamePrints::printError(6);
        GamePrints::printError(3);
        enterSelect();
    } else {
        std::cout << "All saved games: " << std::endl;
        for (int i = 0; i < s_games.size(); i++) {
            std::cout << i << " - " << s_games[i]->getGameName() << std::endl;
        }
    }
}

std::vector<Game*>& GameStorage::getGames(){
    return s_games;
}

GameStorage::~GameStorage(){
    for (int i = 0; i < s_games.size(); i++){
        s_games.erase(s_games.begin() + i);
    }
}
