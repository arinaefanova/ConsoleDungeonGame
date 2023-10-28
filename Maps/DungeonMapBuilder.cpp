#include "DungeonMapBuilder.h"

DungeonMapBuilder::DungeonMapBuilder(Map* map) : MapBuilder(map){}


void DungeonMapBuilder::createTopMap(){
    if (m_map->getPlayer()->getY() == 0){
        printFirstLine(m_map->getPlayer()->getX());
    } else {
        printFirstLine(-1);}
}

void DungeonMapBuilder::createMiddleMap(){
    for (int i = 2; i < m_map->getSize() ; i++){
        if (m_map->getPlayer()->getY() == (i-1)) {
            printSecondLine(m_map->getPlayer()->getX(),  i - 1);}
        else { printSecondLine(-1, i - 1);}
    }
}

void DungeonMapBuilder::createEndMap(){
    if (m_map->getPlayer()->getY() == (m_map->getSize() - 1)){
        printLastLine(m_map->getPlayer()->getX());}
    else {printLastLine(-1);}
}


void DungeonMapBuilder::printFirstLine(int x){
    for(int i = 0; i < m_map->getSize(); i++){
        std::cout << " _______________";
    }
    std::cout << std::endl;
    std::cout << printWeapon(0, changeLetter(getEmptyLine(), getEmptyLine().length() - 2, 'E')) << std::endl;
    std::cout << changeLetter(getEmptyLine(), getEmptyLine().length() - 2, 'X') << std::endl;

    std::cout << changeLetter(printHero(x), printHero(x).length() - 1, ' ') << std::endl;

    std::string line = printItem(0,changeLetter(getEmptyLine(), getEmptyLine().length() - 2, 'I'));
    std::cout << printEnemy(0, line) << std::endl;

    std::cout << changeLetter(getMiddleLine(), getMiddleLine().length() - 2, 'T') << std::endl;
}

void DungeonMapBuilder::printSecondLine(int x, int y){
    for(int i = 0; i < 3; i++){
        if (i==0){
            std::cout << printWeapon(y, getEmptyLine()) << std::endl;
        }
        if (i == 1){
            std::cout << getEmptyLine() << std::endl;
            std::cout << printHero(x) << std::endl;
        }
        if (i == 2){
            std::string line = printItem(y, getEmptyLine());
            std::cout << printEnemy(y, line) << std::endl;
        }
    }
    std::cout << getMiddleLine() << std::endl;
}

void DungeonMapBuilder::printLastLine(int x){
    for(int i = 0; i < 3; i++) {
        if (i == 0) {
            std::cout << printWeapon(m_map->getSize() - 1, getEmptyLine()) << std::endl;
        }
        if (i == 1) {
            std::cout << getEmptyLine() << std::endl;
            std::cout << printHero(x) << std::endl;
        }
        if (i == 2) {
            std::string line = printItem(m_map->getSize() - 1, getEmptyLine());
            std::cout << printEnemy(m_map->getSize() - 1, line) << std::endl;
        }
    }
    std::cout << getEndLine() << std::endl;
}

std::string DungeonMapBuilder::printHero(int x){
    std::string str = "|";
    for (int i = 1; i <= m_map->getSize(); i++){
        if ((i-1) == x){
            if(i == m_map->getSize()){
                str.append("       P       |");
            } else {
                str.append("       P        ");}
        } else if (i == m_map->getSize()) {
            str.append("               |");
        } else {
            str.append("                ");
        }
    }
    return str;
}

std::string DungeonMapBuilder::printWeapon(int y, std::string str){
    const auto& weapons = m_map->getWeapons();
    int place = 3;
    for (int x = 0; x < weapons[y].size(); ++x) {
        if (weapons[y][x] != nullptr) {
            str.replace(place, 1, "w");
        }
        place+=16;
    }
    return str;
}

std::string DungeonMapBuilder::printItem(int y, std::string str){
    const auto& items = m_map->getItems();
    int place = 3;
    for (int x = 0; x < items[y].size(); ++x) {
        if (items[y][x] != nullptr) {
            str.replace(place, 1, items[y][x]->getLetter());
        }
        place+=16;
    }
    return str;
}

std::string DungeonMapBuilder::printEnemy(int y, std::string str){
    const auto& enemies = m_map->getEnemies();
    int place = 13;
    for (int x = 0; x < enemies[y].size(); ++x) {
        if (enemies[y][x] != nullptr) {
            str.replace(place, 1, enemies[y][x]->getLetter());
        }
        place+=16;
    }
    return str;
}

std::string DungeonMapBuilder::changeLetter(std::string str, int place, char letter){
    str[place] = letter;
    return str;
}

std::string DungeonMapBuilder::getMiddleLine(){
    std::string str = "|";
    for (int i=0; i < m_map->getSize(); i++){
        str += "______   ______|";
    }
    return str;
}

std::string DungeonMapBuilder::getEndLine(){
    std::string str = "|";
    for (int i=0; i < m_map->getSize(); i++){
        str += "_______________|";
    }
    return str;
}

std::string DungeonMapBuilder::getEmptyLine(){
    std::string str = "|";
    for (int i=0; i < m_map->getSize(); i++){
        str += "               |";
    }
    return str;
}
