#include "Map.h"
#include <random>

Map::Map(int size, Player* player) : m_size(size){
    m_weapons.resize(m_size, std::vector<Weapon*>(m_size));
    m_items.resize(m_size, std::vector<Item*>(m_size));
    m_enemies.resize(m_size, std::vector<Enemy*>(m_size));
    initRandomVectors();
    m_player=player;
}

void Map::initRandomVectors(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(0.5);

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            m_weapons[i][j] = dis(gen) ? new Weapon() : nullptr;
            m_items[i][j] = dis(gen) ? new Item() : nullptr;
            m_enemies[i][j] = dis(gen) ? new Enemy() : nullptr;
        }
    }
}

bool Map::isEnemyVectorNull() {
    for (const auto& row : m_enemies) {
        for (const auto& element : row) {
            if (element != nullptr) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<Weapon*>>& Map::getWeapons(){
    return m_weapons;
}

std::vector<std::vector<Item*>>& Map::getItems(){
    return m_items;
}

std::vector<std::vector<Enemy*>>& Map::getEnemies(){
    return m_enemies;
}

int Map::getSize(){
    return m_size;
}

Player* Map::getPlayer(){
    return m_player;
}

Map::~Map() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            delete m_weapons[i][j];
            delete m_items[i][j];
            delete m_enemies[i][j];
        }
    }
}
