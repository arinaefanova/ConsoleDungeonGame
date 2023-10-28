#include "GamePrints.h"

// The function returns an error by numeric code.
void GamePrints::printError(int codeError){
switch(codeError){
    case 1: std::cerr << "Error: Incorrect number. Please enter a valid number:" << std::endl; break;
    case 2: std::cerr << "Incorrect map size!" << std::endl; break;
    case 3: std::cerr << "Select another choice: " << std::endl; break;
    case 4: std::cerr << "Error: Incorrect choice. Please enter a valid choice:" << std::endl; break;
    case 5: std::cerr << "Error: Incorrect choice." << std::endl; break;
    case 6: std::cerr << "You don't have any saved games." << std::endl; break;
    default: std::cerr << "Input error." << std::endl; break;}
}

// The function returns an error by char.
void GamePrints::printError(char codeError){
    switch(codeError){
        case 'a': std::cerr << "There is no exit to the left!" << std::endl; break;
        case 'd': std::cerr << "There is no exit to the right!" << std::endl; break;
        case 'D': std::cerr << "You haven't killed all the enemies yet!" << std::endl; break;
        case 'w': std::cerr << "There is no exit to the up!" << std::endl; break;
        case 's': std::cerr << "There is no exit to the down!" << std::endl; break;
        case '3': std::cerr << "There are no enemies here!" << std::endl; break;
        case '2': std::cerr << "There are no weapons here!" << std::endl; break;
        case '1': std::cerr << "There are no items here!" << std::endl; break;
        default: std::cerr << "Input error." << std::endl; break;
    }
}

//Function for printing main menu choices of program.
void GamePrints::printMenuApplication(){
    std::cout << "Welcome to console game Witcher!" << std::endl;
    std::cout << "Select and enter the number: " << std::endl;
    std::cout << "1 - Start new game" << std::endl;
    std::cout << "2 - Load a saved game" << std::endl;
    std::cout << "3 - Exit" << std::endl;
}

//Function for displaying menu text
void GamePrints::printMenuGame(std::string tileItem, std::string tileWeapon, std::string tileEnemy){
    std::cout << "Select and enter the number of actions you want to perform: " << std::endl;
    std::cout << "w - Go up" << std::endl;
    std::cout << "a - Go left" << std::endl;
    std::cout << "d - Go right" << std::endl;
    std::cout << "s - Go down" << std::endl;
    std::cout << "1 - Take an item " << tileItem << std::endl;
    std::cout << "2 - Take a weapon " << tileWeapon << std::endl;
    std::cout << "3 - Fight the enemy " << tileEnemy << std::endl;
    std::cout << "4 - Go back to the Game Menu" << std::endl;
}

//Function for displaying actual info about the player
void GamePrints::printPlayerInfo(Player* player){
    std::cout << "*************************************************" << std::endl;
    std::cout << "              Player information: " << std::endl;
    std::cout << "Health: " << player->getHealth();
    std::cout << "     Magic Power: " << player->getMagicPower();
    std::cout << "     Strength: " << player->getStrength()<<std::endl;
    std::cout << "Weapons(max. 2): " << std::endl;
    std::string str;
    for (auto & i : player->getWeapons()) {
        if (i != nullptr) {
            str += "     " + i->getName() + " (damage: " + std::to_string(i->getDamage()) + ")" ;
        }
    }
    if (player->getWeapons()[0] == nullptr && player->getWeapons()[1] == nullptr ){
        std::cout << "-- empty --" << std::endl;
    } else {
        std::cout << str << std::endl;
    }
    std::cout << "*************************************************" << std::endl;
}

//Function for displaying info about weapon in the map cell where the player is located
std::string GamePrints::getTileWeapon(Player* player, Map* map){
    if (map->getWeapons()[player->getY()][player->getX()] != nullptr){
        return "(w) - " + map->getWeapons()[player->getY()][player->getX()]->getName() + " (damage: " +
               std::to_string(map->getWeapons()[player->getY()][player->getX()]->getDamage()) + ")";
    } else {
        return "- there are no weapons here.";
    }
}

//Function for displaying info about enemy in the map cell where the player is located
std::string GamePrints::getTileEnemy(Player* player, Map* map){
    if (map->getEnemies()[player->getY()][player->getX()] != nullptr){
        return "(" + map->getEnemies()[player->getY()][player->getX()]->getLetter()
               + ") - " + map->getEnemies()[player->getY()][player->getX()]->getName() + " (damage: " +
               std::to_string(map->getEnemies()[player->getY()][player->getX()]->getDamage()) + ", health: " +
               std::to_string(map->getEnemies()[player->getY()][player->getX()]->getHealth()) + ")";
    } else {
        return "- there are no enemies here.";
    }
}


//Function for displaying info about item in the map cell where the player is located
std::string GamePrints::getTileItem(Player* player, Map* map){
    if (map->getItems()[player->getY()][player->getX()] != nullptr){
        return "(" + map->getItems()[player->getY()][player->getX()]->getLetter() + ") - "
               + map->getItems()[player->getY()][player->getX()]->getName() + " (bonus: " +
               std::to_string(map->getItems()[player->getY()][player->getX()]->getBonus()) + ")";
    } else {
        return "- there are no items here.";
    }
}

//Function for displaying text "Game Menu". Called in the main menu of program
void GamePrints::printStart(){
    std::cout << "\n"
                 "  __  __  __ __ ___   __ __ ___ __  _ _  _  \n"
                 " / _]/  \\|  V  | __| |  V  | __|  \\| | || | \n"
                 "| [/\\ /\\ | \\_/ | _|  | \\_/ | _|| | ' | \\/ | \n"
                 " \\__/_||_|_| |_|___| |_| |_|___|_|\\__|\\__/  \n" << std::endl;
}

//Function for displaying text "YOU WIN". Called after winning the game.
void GamePrints::printWin(){
    std::cout << "\n"
                 " __     ______  _    _  __          _______ _   _ _ \n"
                 " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | | |\n"
                 "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| | |\n"
                 "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` | |\n"
                 "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |_|\n"
                 "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_(_)\n"
                 "                                                    \n"
                 "                                                    " << std::endl;
}

//Function for displaying text "YOU LOSE". Called after losing the game.
void GamePrints::printLose(){
    std::cout << "\n"
                 "__     __  ____   _    _   _        ____    _____  ______\n"
                 "\\ \\   / / / __ \\ | |  | | | |      / __ \\  / ____||  ____|\n"
                 " \\ \\_/ / | |  | || |  | | | |     | |  | || (___  | |__\n"
                 "  \\   /  | |  | || |  | | | |     | |  | | \\___ \\ |  __|\n"
                 "   | |   | |__| || |__| | | |____ | |__| | ____) || |____\n"
                 "   |_|    \\____/  \\____/  |______| \\____/ |_____/ |______|\n"
                 "                                                    " << std::endl;
}
