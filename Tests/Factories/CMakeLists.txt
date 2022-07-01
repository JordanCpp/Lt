cmake_minimum_required(VERSION 3.8)

project(TestFactories)

add_executable(ImageFactory "ImageFactory.cpp")
target_link_libraries(ImageFactory LtCore LtAllocators LtGraphics LtEvents)