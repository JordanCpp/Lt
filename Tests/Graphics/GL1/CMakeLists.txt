cmake_minimum_required(VERSION 3.8)

project(TestGraphicsGL1)

add_executable(GL1Render "GL1Render.cpp")
target_link_libraries(GL1Render LtCore LtGraphics LtEvents)