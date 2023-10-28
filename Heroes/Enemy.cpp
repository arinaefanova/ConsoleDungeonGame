#include "Enemy.h"
#include "Monster.h"
#include "Guard.h"
#include <random>

EnemyState* Enemy::getRandomEnemy() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,2);
    int randNum = dis(gen);

    switch(randNum){
        case 1:
            return new Monster();
        case 2:
            return new Guard();
        default:
            return new Monster();
    }
}

Enemy::Enemy(){
    m_state = getRandomEnemy();
}

int Enemy::getDamage(){
    return m_state->getDamage();
}

unsigned int Enemy::getHealth(){
    return m_state->getHealth();
}

std::string Enemy::getName(){
    return m_state->getName();
}

std::string Enemy::getLetter(){
    return m_state->getLetter();
}

void Enemy::reduceHealth(int count){
    m_state->reduceHealth(count);
}

Enemy::~Enemy(){
    delete m_state;
}