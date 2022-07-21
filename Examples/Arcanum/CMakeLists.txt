cmake_minimum_required(VERSION 3.8)

project(Arcanum)

add_executable(Arcanum "main.cpp" "Engine.cpp")
target_link_libraries(Arcanum LtCore LtGraphics LtEvents LtAllocators)