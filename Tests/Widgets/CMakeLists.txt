cmake_minimum_required(VERSION 3.8)

project(TestWidgets)

add_executable(Widget "Widget.cpp")
target_link_libraries(Widget LtWidgets LtGraphics LtEvents LtCore)

add_executable(Factory "Factory.cpp")
target_link_libraries(Factory LtWidgets LtGraphics LtEvents LtCore)