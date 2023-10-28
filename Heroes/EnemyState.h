#ifndef ZOOLS2023_XEFANOVA_ENEMYSTATE_H
#define ZOOLS2023_XEFANOVA_ENEMYSTATE_H


#include <string>

class EnemyState {

    int m_damage;
    unsigned int m_health;

public:
    EnemyState();

    int getDamage();
    unsigned int getHealth();
    void reduceHealth(int count);

    virtual std::string getName() = 0;
    virtual std::string getLetter() = 0;

};


#endif //ZOOLS2023_XEFANOVA_ENEMYSTATE_H
