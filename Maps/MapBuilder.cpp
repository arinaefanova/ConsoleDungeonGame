#include "MapBuilder.h"


MapBuilder::MapBuilder(Map* map){
    m_map=map;
}


Map* MapBuilder::getMap(){
    return m_map;
}
