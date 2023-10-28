#include "Item.h"

ItemType Item::getRandomItem() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    int randNum = dis(gen);
    switch (randNum) {
        case 0:
            return ItemType::HealthItem;
        case 1:
            return ItemType::MagicItem;
        default:
            return ItemType::HealthItem;
    }
}

std::string Item::itemTypeToString(ItemType type) {
    switch (type) {
        case ItemType::HealthItem:
            return "Health item";
        case ItemType::MagicItem:
            return "Magic item";
        default:
            return "";
    }
}


Item::Item() {
    m_itemType = getRandomItem();
    m_name = itemTypeToString(m_itemType);
    m_bonus = static_cast<int>(m_itemType);
}


std::string Item::getLetter(){
    if (m_itemType == ItemType::HealthItem){
        return "h";
    } else {
        return "m";
    }
}