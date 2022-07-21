cmake_minimum_required(VERSION 3.8)

project(Gameplay)

add_executable(CritterManager "CritterManager.cpp")
target_link_libraries(CritterManager ArcanumLibrary)

add_executable(Attribute "Attribute.cpp")
target_link_libraries(Attribute ArcanumLibrary)

add_executable(Perk "Perk.cpp")
target_link_libraries(Perk ArcanumLibrary)