#ifndef ZOOLS2023_XEFANOVA_MONSTER_H
#define ZOOLS2023_XEFANOVA_MONSTER_H

#include "EnemyState.h"

class Monster : public EnemyState {

public:
    Monster();

    std::string getLetter() override;

    std::string getName() override;
};


#endif //ZOOLS2023_XEFANOVA_MONSTER_H
