cmake_minimum_required(VERSION 3.8)

project(ExamplesWidgets)

add_executable(01_Application "01_Application/main.cpp")
target_link_libraries(01_Application LtCore LtGraphics LtEvents LtWidgets LtAllocators)