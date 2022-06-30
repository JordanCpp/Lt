cmake_minimum_required(VERSION 3.8)

project(TestInput)

add_executable(Mouse "Mouse.cpp")
target_link_libraries(Mouse LtCore LtGraphics)