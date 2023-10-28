#include <thread>
#include "Player.h"

Player::Player(int size) : m_playerPosition(size, std::vector<bool>(size, false)) {
    m_playerPosition[size - 1][0] = true;
    m_health=100;
    m_magicPower=40;
    m_strength=40;
}

int Player::getX(){
    for (int y = 0; y < m_playerPosition.size(); ++y) {
        for (int x = 0; x < m_playerPosition[y].size(); ++x) {
            if (m_playerPosition[y][x]) {
                return x;
            }
        }
    }
    return -1;
}

int Player::getY(){
    for (int y = 0; y < m_playerPosition.size(); ++y) {
        for (int x = 0; x < m_playerPosition[y].size(); ++x) {
            if (m_playerPosition[y][x]) {
                return y;
            }
        }
    }
    return -1;
}

void Player::move(int x, int y){
    int lastX = getX();
    int lastY = getY();
    m_playerPosition[getY() + y][getX() + x] = true;
    m_playerPosition[lastY][lastX] = false;
}

Weapon* Player::takeWeapon(Weapon* newWeapon){
    Weapon* replacedWeapon = nullptr;

    if (m_playerWeapons[0] == nullptr) {
        m_playerWeapons[0] = newWeapon;
    } else if (m_playerWeapons[1] == nullptr) {
        m_playerWeapons[1] = newWeapon;
    } else if (m_playerWeapons[0]->getDamage() > m_playerWeapons[1]->getDamage()) {
        replacedWeapon = m_playerWeapons[1];
        m_playerWeapons[1] = newWeapon;
    } else if (m_playerWeapons[0]->getDamage() < m_playerWeapons[1]->getDamage()) {
        replacedWeapon = m_playerWeapons[0];
        m_playerWeapons[0] = newWeapon;
    } else {
        replacedWeapon = m_playerWeapons[0];
        m_playerWeapons[0] = newWeapon;
    }
    return replacedWeapon;
}

int Player::getStrength(){
    int weaponBonus = 40;
    for (auto weapon : m_playerWeapons){
        if (weapon != nullptr){
            weaponBonus+=weapon->getDamage();}
    }
    m_strength=weaponBonus;
    return m_strength;
}

void Player::takeItem(Item* item){
    if (item->getType() == ItemType::HealthItem){
        if (m_health+item->getBonus() < 100) {
            m_health += item->getBonus();
        } else {
            m_health = 100;
            std::cerr << "The maximum health level is 100 units" << std::endl;
        }
    } else if (item->getType() == ItemType::MagicItem){
        if (m_magicPower+item->getBonus() < 100) {
            m_magicPower+=item->getBonus();
        } else {
            m_magicPower = 100;
            std::cerr << "The maximum magic level is 100 units" << std::endl;
        }
    }
}

void Player::reduceHealth(int count){
    if (m_health > count){
        m_health-=count;
    } else {
        m_health = 0;
    }
}

bool Player::fightEnemy(Enemy* enemy){
    std::cout << "-> The fight begins! <-" << std::endl;
    while (getHealth() > 0 && enemy->getHealth() > 0) {
            if (enemy->getName() == "Guard") {
                std::cout << "Player attacks " << enemy->getName() << " with strength: " << getStrength() << std::endl;
                enemy->reduceHealth(getStrength());
            } else {
                std::cout << "Player attacks " << enemy->getName() << " with magic power: " << getMagicPower() << std::endl;
                enemy->reduceHealth(getMagicPower());
            }
            std::cout <<"..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << enemy->getName() << " health now: " << enemy->getHealth() << std::endl;
            std::cout <<"..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (enemy->getHealth() > 0){
            std::cout << enemy->getName() <<  " attacks Player with damage: " << enemy->getDamage() << std::endl;
                reduceHealth(enemy->getDamage());
                std::cout <<"..." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Player health now: " << getHealth() << std::endl;
                std::cout <<"..." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
    }
    if (enemy->getHealth() <= 0) {
        return true;
    } else {
        return false;
    }
}

