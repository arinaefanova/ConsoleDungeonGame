#ifndef ZOOLS2023_XEFANOVA_WEAPON_H
#define ZOOLS2023_XEFANOVA_WEAPON_H

#include <string>

enum class WeaponType {
    Sword = 10,
    Axe = 15,
    Bow = 8,
    Staff = 5
};

class Weapon {
private:
    std::string m_name;
    int m_damage;

    WeaponType getRandomWeapon();
    std::string weaponTypeToString(WeaponType type);

public:
    Weapon();
    std::string getName() const;
    int getDamage() const;
};


#endif //ZOOLS2023_XEFANOVA_WEAPON_H
