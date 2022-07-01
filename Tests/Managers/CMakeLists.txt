cmake_minimum_required(VERSION 3.8)

project(TestManagers)

add_executable(ImageManager "ImageManager.cpp")
target_link_libraries(ImageManager LtCore LtAllocators LtGraphics LtEvents)

add_executable(PathManager "PathManager.cpp")
target_link_libraries(PathManager LtCore LtAllocators LtGraphics LtEvents)