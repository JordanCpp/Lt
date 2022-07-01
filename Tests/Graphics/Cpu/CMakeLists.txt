cmake_minimum_required(VERSION 3.8)

project(TestGraphicsCpu)

add_executable(CpuWindow "CpuWindow.cpp")
target_link_libraries(CpuWindow LtCore LtGraphics LtEvents)

add_executable(CpuRender "CpuRender.cpp")
target_link_libraries(CpuRender LtCore LtGraphics LtEvents)