#ifndef ZOOLS2023_XEFANOVA_PLAYER_H
#define ZOOLS2023_XEFANOVA_PLAYER_H

#include <vector>
#include <iostream>
#include <array>
#include "../Objects/Weapon.h"
#include "../Objects/Item.h"
#include "Enemy.h"

class Player {
    std::vector<std::vector<bool>> m_playerPosition;
    std::array<Weapon*,2> m_playerWeapons = {nullptr, nullptr};
    unsigned int m_health;
    int m_strength;
    int m_magicPower;

public:
    explicit Player(int size);

    int getX();

    int getY();

    void move(int x, int y);

    Weapon* takeWeapon(Weapon* newWeapon);

    void takeItem(Item* item);

    bool fightEnemy(Enemy* enemy);

    unsigned int getHealth(){return m_health;};

    int getMagicPower(){return m_magicPower;};

    int getStrength();

    void reduceHealth(int count);

    std::array<Weapon*,2>& getWeapons(){ return m_playerWeapons;}

};


#endif //ZOOLS2023_XEFANOVA_PLAYER_H
