#include "Weapon.h"
#include <random>

WeaponType Weapon::getRandomWeapon() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 3);
    int randNum = dis(gen);
    switch (randNum) {
        case 0:
            return WeaponType::Sword;
        case 1:
            return WeaponType::Axe;
        case 2:
            return WeaponType::Bow;
        case 3:
            return WeaponType::Staff;
        default:
            return WeaponType::Sword;
    }
}

std::string Weapon::weaponTypeToString(WeaponType type) {
    switch (type) {
        case WeaponType::Sword:
            return "Sword";
        case WeaponType::Axe:
            return "Axe";
        case WeaponType::Bow:
            return "Bow";
        case WeaponType::Staff:
            return "Staff";
        default:
            return "";
    }
}

Weapon::Weapon() {
    WeaponType type = getRandomWeapon();
    m_name = weaponTypeToString(type);
    m_damage = static_cast<int>(type);
}

std::string Weapon::getName() const {
    return m_name;
}

int Weapon::getDamage() const {
    return m_damage;
}
