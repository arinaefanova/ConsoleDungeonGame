#include <iostream>
#include <thread>
#include <utility>
#include "Game.h"
#include "GameStorage.h"
#include "../Maps/DungeonMapBuilder.h"
#include "GamePrints.h"


Game::Game(std::string gameName){
    m_gameName = std::move(gameName);
    m_map = nullptr;
    m_player = nullptr;
    m_size = 0;
    m_director = nullptr;
}

//The beginning of the game: choosing the size of the map, creating map, a player, calling functions to start the game
void Game::startGame(){
    int size = 0;
    std::cout << "Please, choose the map size from 2 to 7: " << std::endl;
    while (!(std::cin >> size) || size > 7 || size < 2) {
        GamePrints::printError(1);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if ((size >= 2) and (size<=7)){
        m_size=size;
        m_player = new Player(size);
        m_map = new Map(size, m_player);
        m_director = new MapDirector(new DungeonMapBuilder(m_map));
        m_director->createMap();
        GamePrints::printPlayerInfo(m_player);
        showMenu(true);
    } else {
        GamePrints::printError(2);}
    }

//Function to launch a saved game
void Game::loadGame(){
    m_director->createMap();
    showMenu(true);
}

//Function for processing the selection of 'W'.
void Game::selectUp(){
    if (m_player->getY() != 0){
        m_player->move(0, -1);
    } else {
        GamePrints::printError('w');
        showMenu(false);
    }
}

//Function for processing the selection of 'A'.
void Game::selectLeft(){
    if(m_player->getX() != 0){
        m_player->move(-1, 0);
    } else {
        GamePrints::printError('a');
        showMenu(false);
    }
}

//Function for processing the selection of 'S'.
void Game::selectDown(){
    if((m_player->getY() + 1) == m_size){
        GamePrints::printError('s');
        showMenu(false);
    } else {
        m_player->move(0, 1);}
}

//Function for processing the selection of 'D'.
bool Game::selectRight(){
    if (m_player->getY() == 0 and (m_player->getX() + 1) == m_size ){
        if (m_map->isEnemyVectorNull()){
            GamePrints::printWin();
            deleteGameByName(m_gameName);
            return true;
        } else {
            GamePrints::printError('D');
            showMenu(false);
            return false;
        }
    } else {
        if((m_player->getX() + 1) == m_size){
            GamePrints::printError('d');
            showMenu(false);
            return false;
        } else {
            m_player->move(1, 0);
            return false;
        }
    }
}

//Function for processing the selection of '1'.
void Game::selectTakeItem(){
    if (m_map->getItems()[m_player->getY()][m_player->getX()] != nullptr){
        m_player->takeItem(m_map->getItems()[m_player->getY()][m_player->getX()]);
        m_map->getItems()[m_player->getY()][m_player->getX()] = nullptr;
    } else {
        GamePrints::printError('1');
        showMenu(false);
    }
}

//Function for processing the selection of '2'.
void Game::selectTakeWeapon(){
    if (m_map->getWeapons()[m_player->getY()][m_player->getX()] != nullptr){
        Weapon* weapon = m_player->takeWeapon(m_map->getWeapons()[m_player->getY()][m_player->getX()]);
        m_map->getWeapons()[m_player->getY()][m_player->getX()] = weapon;
    } else {
        GamePrints::printError('2');
        showMenu(false);
    }
}

//Function for processing the selection of '3'.
bool Game::selectFight(){
    if (m_map->getEnemies()[m_player->getY()][m_player->getX()] != nullptr){
        if (m_player->fightEnemy(m_map->getEnemies()[m_player->getY()][m_player->getX()])) {
            std::cout << "You win " << m_map->getEnemies()[m_player->getY()][m_player->getX()]->getName() << "!" << std::endl;
            m_map->getEnemies()[m_player->getY()][m_player->getX()] = nullptr;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return false;
        } else {
            GamePrints::printLose();
            deleteGameByName(m_gameName);
            return true;
        }
    } else {
        GamePrints::printError('3');
        showMenu(false);
        return false;
    }
}

//This function receives the user's choice and calls the function to process this choice.
bool Game::processSelect(char select){
    switch(select){
        case 'a':
            selectLeft();
            return false;
        case 'd':
            return selectRight();
        case 'w':
            selectUp();
            return false;
        case 's':
            selectDown();
            return false;
        case '4':
            GameStorage::menuGame();
            return false;
        case '3':
            return selectFight();
        case '2':
            selectTakeWeapon();
            return false;
        case '1':
            selectTakeItem();
            return false;
        default:
            GamePrints::printError(5);
            return false;
    }
}

//The main function of the game menu. Performs player selection in the menu during the game
void Game::showMenu(bool print){
    bool endGame = false;
    std::string choose;
    if (print) {
        GamePrints::printMenuGame(GamePrints::getTileItem(m_player, m_map),
                                  GamePrints::getTileWeapon(m_player, m_map),
                                    GamePrints::getTileEnemy(m_player, m_map));
    } else {
        GamePrints::printError(3);
    }
    while (!(std::cin >> choose) || choose.length() != 1 || (choose != "w" && choose != "a" &&
    choose != "s" && choose != "d" && choose != "1" && choose != "2" && choose != "3" && choose != "4")) {
        GamePrints::printError(1);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    char chooseChar = choose.at(0);
    endGame = processSelect(chooseChar);
    if (!endGame){
        m_director->createMap();
        GamePrints::printPlayerInfo(m_player);
        showMenu(true);} else {
        GameStorage::menuGame();
    }
}

//Function for deleting a saved game. Called after winning the game.
void Game::deleteGameByName(const std::string& gameName){
    for (int i = 0; i < GameStorage::getGames().size(); i++){
        if (GameStorage::getGames()[i]->getGameName() == gameName) {
            GameStorage::getGames().erase(GameStorage::getGames().begin() + i);
        }
    }
}

Game::~Game() {
    delete m_player;
    delete m_map;
    delete m_director;
}

