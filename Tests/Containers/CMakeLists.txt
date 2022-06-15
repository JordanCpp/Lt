cmake_minimum_required(VERSION 3.8)

project(TestContainers)

add_executable(Vector "Vector.cpp")
target_link_libraries(Vector Lt)

add_executable(String "String.cpp")
target_link_libraries(String Lt)

add_executable(Array "Array.cpp")
target_link_libraries(Array Lt)

add_executable(StaticString "StaticString.cpp")
target_link_libraries(StaticString Lt)

add_executable(StaticVector "StaticVector.cpp")
target_link_libraries(StaticVector Lt)