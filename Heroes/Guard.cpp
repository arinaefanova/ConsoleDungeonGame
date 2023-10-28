#include "Guard.h"

Guard::Guard(): EnemyState() {}

std::string Guard::getLetter(){
    return "G";
}

std::string Guard::getName(){
    return "Guard";
}