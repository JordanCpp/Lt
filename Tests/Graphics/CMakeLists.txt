cmake_minimum_required(VERSION 3.8)

project(TestAllocators)

add_executable(Point2 "Point2.cpp")
target_link_libraries(Point2 Lt)

add_executable(Rect2 "Rect2.cpp")
target_link_libraries(Rect2 Lt)