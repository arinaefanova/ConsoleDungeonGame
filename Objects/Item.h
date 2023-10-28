#ifndef ZOOLS2023_XEFANOVA_ITEM_H
#define ZOOLS2023_XEFANOVA_ITEM_H


#include <string>
#include <random>

enum class ItemType {
    HealthItem = 15,
    MagicItem = 20
};

class Item {
    std::string m_name;
    int m_bonus;
    ItemType m_itemType;

    ItemType getRandomItem();

    std::string itemTypeToString(ItemType type);

public:
    Item();

    std::string getName() const { return m_name; }

    int getBonus() const { return m_bonus; }

    ItemType getType() const { return m_itemType; }

    std::string getLetter();

};


#endif //ZOOLS2023_XEFANOVA_ITEM_H
