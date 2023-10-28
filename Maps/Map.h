#ifndef ZOOLS2023_XEFANOVA_MAP_H
#define ZOOLS2023_XEFANOVA_MAP_H


#include <vector>
#include "../Heroes/Player.h"
#include "../Objects/Weapon.h"
#include "../Heroes/Enemy.h"

class Map {
    int m_size;
    Player* m_player;
    std::vector<std::vector<Weapon*>> m_weapons;
    std::vector<std::vector<Item*>> m_items;
    std::vector<std::vector<Enemy*>> m_enemies;

    void initRandomVectors();

public:

    Map(int size, Player* player);

    int getSize();

    Player* getPlayer();

    std::vector<std::vector<Weapon*>>& getWeapons();

    std::vector<std::vector<Item*>>& getItems();

    std::vector<std::vector<Enemy*>>& getEnemies();

    bool isEnemyVectorNull();

    ~Map();
};


#endif //ZOOLS2023_XEFANOVA_MAP_H
