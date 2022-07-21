cmake_minimum_required(VERSION 3.8)

project(Game)

add_executable(StatValue "StatValue.cpp")
target_link_libraries(StatValue ArcanumLibrary)

add_executable(CritterStats "CritterStats.cpp")
target_link_libraries(CritterStats ArcanumLibrary)