#ifndef ZOOLS2023_XEFANOVA_ENEMY_H
#define ZOOLS2023_XEFANOVA_ENEMY_H


#include <string>
#include "EnemyState.h"

class Enemy {

    EnemyState* m_state;

    EnemyState* getRandomEnemy();

public:
    Enemy();

    int getDamage();
    unsigned int getHealth();
    std::string getName();
    std::string getLetter();
    void reduceHealth(int count);

    ~Enemy();
};


#endif //ZOOLS2023_XEFANOVA_ENEMY_H
