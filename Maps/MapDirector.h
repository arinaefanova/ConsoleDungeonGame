#ifndef ZOOLS2023_XEFANOVA_MAPDIRECTOR_H
#define ZOOLS2023_XEFANOVA_MAPDIRECTOR_H


#include "MapBuilder.h"

class MapDirector {
    MapBuilder* m_builder;

public:
    MapDirector(MapBuilder* builder);

    void setBuilder(MapBuilder* builder);

    void createMap();
};


#endif //ZOOLS2023_XEFANOVA_MAPDIRECTOR_H
