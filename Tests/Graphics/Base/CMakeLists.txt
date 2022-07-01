cmake_minimum_required(VERSION 3.8)

project(TestGraphicsBase)

add_executable(BaseWindow "BaseWindow.cpp")
target_link_libraries(BaseWindow LtCore LtGraphics)

add_executable(BaseRender "BaseRender.cpp")
target_link_libraries(BaseRender LtCore LtGraphics)