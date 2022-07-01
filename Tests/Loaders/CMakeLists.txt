cmake_minimum_required(VERSION 3.8)

project(TestLoaders)

add_executable(ImageLoader "ImageLoader.cpp")
target_link_libraries(ImageLoader LtCore LtAllocators LtGraphics LtEvents)