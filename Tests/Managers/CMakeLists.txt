cmake_minimum_required(VERSION 3.8)

project(TestManagers)

add_executable(TestImageManager "TestImageManager.cpp")
target_link_libraries(TestImageManager LtCore LtAllocators LtGraphics LtEvents)