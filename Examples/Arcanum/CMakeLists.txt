cmake_minimum_required(VERSION 3.8)

project(Arcanum)

add_library(ArcanumLibrary STATIC
"Engine.cpp" 

"Game/Critter.cpp" 
"Game/Location.cpp" 
"Game/Tile.cpp" 
"Game/CritterScript.cpp" 
"Game/LocationScript.cpp" 

"Managers/CritterManager.cpp" 

"Gameplay/StatValue.cpp" 
"Gameplay/CritterStats.cpp"
"Gameplay/Attribute.cpp"
"Gameplay/Perk.cpp" 

"Scripts/Tester.cpp" 

"Painters/TilePainter.cpp")

target_link_libraries(ArcanumLibrary LtCore LtGraphics LtEvents LtAllocators)

add_executable(Arcanum "main.cpp" )
target_link_libraries(Arcanum ArcanumLibrary)

add_subdirectory("Tests/Game")
add_subdirectory("Tests/Gameplay")