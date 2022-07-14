cmake_minimum_required(VERSION 3.8)

project(Game)

add_executable(Game "main.cpp" "Engine.cpp")
target_link_libraries(Game LtCore LtGraphics LtEvents)