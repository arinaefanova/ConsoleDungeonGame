#include "MapDirector.h"

MapDirector::MapDirector(MapBuilder* builder){
    m_builder=builder;
}

void MapDirector::setBuilder(MapBuilder* builder){
    m_builder=builder;
}

void MapDirector::createMap(){
    m_builder->createTopMap();
    m_builder->createMiddleMap();
    m_builder->createEndMap();
}