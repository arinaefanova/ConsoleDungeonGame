#include <random>
#include "EnemyState.h"

EnemyState::EnemyState(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,10);
    int randNum = dis(gen);

    m_damage=(randNum * 5);
    m_health=(randNum * 10);
}

int EnemyState::getDamage() {
    return m_damage;
}

unsigned int EnemyState::getHealth() {
    return m_health;
}

void EnemyState::reduceHealth(int count){
    if (m_health > count){
        m_health-=count;
    } else {
        m_health = 0;
    }
}
