cmake_minimum_required(VERSION 3.8)

project(ExamplesCore)

add_executable(01_Console "01_Console/main.cpp")
target_link_libraries(01_Console LtCore)

add_executable(02_Directory "02_Directory/main.cpp")
target_link_libraries(02_Directory LtCore)

add_executable(03_Convert "03_Convert/main.cpp")
target_link_libraries(03_Convert LtCore)