cmake_minimum_required(VERSION 3.8)

project(Arcanum)

add_executable(Arcanum 
"main.cpp" 

"Engine.cpp" 

"Game/Critter.cpp" 
"Game/Location.cpp" 
"Game/Tile.cpp" 
"Game/CritterScript.cpp" 

"Managers/CritterManager.cpp" 

"Gameplay/StatValue.cpp" 
"Gameplay/CritterStats.cpp" 

"Scripts/Tester.cpp" 

"Painters/TilePainter.cpp")

target_link_libraries(Arcanum LtCore LtGraphics LtEvents LtAllocators)