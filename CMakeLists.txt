cmake_minimum_required(VERSION 3.24)
project(zools2023_xefanova)

set(CMAKE_CXX_STANDARD 17)

add_executable(zools2023_xefanova main.cpp Objects/Weapon.h Objects/Weapon.cpp Games/Game.cpp Games/GameStorage.cpp Objects/Item.cpp Maps/Map.cpp Heroes/Player.cpp Maps/MapDirector.h Maps/MapDirector.cpp Maps/MapBuilder.cpp Maps/DungeonMapBuilder.cpp Heroes/Enemy.cpp Heroes/Monster.cpp Heroes/Guard.cpp Games/GamePrints.h Games/GamePrints.cpp Heroes/EnemyState.cpp)
