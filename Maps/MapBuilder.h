#ifndef ZOOLS2023_XEFANOVA_MAPBUILDER_H
#define ZOOLS2023_XEFANOVA_MAPBUILDER_H


#include "Map.h"

class MapBuilder {
protected:
    Map* m_map;
public:

    MapBuilder(Map* map);

    virtual void createTopMap() = 0;

    virtual void createMiddleMap() = 0;

    virtual void createEndMap() = 0;

    Map* getMap();

};


#endif //ZOOLS2023_XEFANOVA_MAPBUILDER_H
