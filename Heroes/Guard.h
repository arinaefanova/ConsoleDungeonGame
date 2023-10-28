#ifndef ZOOLS2023_XEFANOVA_GUARD_H
#define ZOOLS2023_XEFANOVA_GUARD_H

#include "EnemyState.h"

class Guard : public EnemyState {

public:
    Guard();

    std::string getLetter() override;

    std::string getName() override;

};


#endif //ZOOLS2023_XEFANOVA_GUARD_H
