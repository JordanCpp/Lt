cmake_minimum_required(VERSION 3.8)

project(Gameplay)

add_executable(CritterManager "CritterManager.cpp")
target_link_libraries(CritterManager ArcanumLibrary)