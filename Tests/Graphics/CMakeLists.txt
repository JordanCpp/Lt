cmake_minimum_required(VERSION 3.8)

project(TestAllocators)

add_executable(Point2 "Point2.cpp")
target_link_libraries(Point2 LtCore)

add_executable(Rect2 "Rect2.cpp")
target_link_libraries(Rect2 LtCore)

add_executable(BaseWindow "BaseWindow.cpp")
target_link_libraries(BaseWindow LtCore LtGraphics)

add_executable(BaseRender "BaseRender.cpp")
target_link_libraries(BaseRender LtCore LtGraphics)

add_executable(Color "Color.cpp")
target_link_libraries(Color LtCore LtGraphics)

add_executable(CpuImage "CpuImage.cpp")
target_link_libraries(CpuImage LtCore LtGraphics LtAllocators)

add_executable(Window "Window.cpp")
target_link_libraries(Window LtCore LtGraphics LtEvents)

add_executable(CpuWindow "CpuWindow.cpp")
target_link_libraries(CpuWindow LtCore LtGraphics LtEvents)