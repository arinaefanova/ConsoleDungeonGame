#ifndef ZOOLS2023_XEFANOVA_DUNGEONMAPBUILDER_H
#define ZOOLS2023_XEFANOVA_DUNGEONMAPBUILDER_H


#include "MapBuilder.h"

class DungeonMapBuilder : public MapBuilder {

    std::string getMiddleLine();

    std::string getEmptyLine();

    std::string getEndLine();

    std::string changeLetter(std::string str, int place, char letter);

    void printFirstLine(int x);

    void printSecondLine(int x, int y);

    void printLastLine(int x);

    std::string printHero(int x);

    std::string printWeapon(int y, std::string str);

    std::string printItem(int y, std::string str);

    std::string printEnemy(int y, std::string str);
public:

    DungeonMapBuilder(Map* map);

    void createTopMap() override;

    void createMiddleMap() override;

    void createEndMap() override;
};


#endif //ZOOLS2023_XEFANOVA_DUNGEONMAPBUILDER_H
