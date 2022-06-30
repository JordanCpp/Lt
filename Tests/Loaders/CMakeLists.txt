cmake_minimum_required(VERSION 3.8)

project(TestLoaders)

add_executable(TestImageLoader "TestImageLoader.cpp")
target_link_libraries(TestImageLoader LtCore LtAllocators LtGraphics LtEvents)