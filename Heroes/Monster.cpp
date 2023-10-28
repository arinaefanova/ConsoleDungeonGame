#include "Monster.h"

Monster::Monster():EnemyState() {}

std::string Monster::getLetter(){
    return "M";
}

std::string Monster::getName(){
    return "Monster";
}
