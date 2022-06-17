cmake_minimum_required(VERSION 3.8)

project(TestAllocators)

add_executable(01_WindowAndRender "Graphics/01_WindowAndRender/main.cpp")
target_link_libraries(01_WindowAndRender LtCore LtGraphics LtEvents)

add_executable(02_FpsLimiter "Graphics/02_FpsLimiter/main.cpp")
target_link_libraries(02_FpsLimiter LtCore LtGraphics LtEvents)

add_executable(03_Color "Graphics/03_Color/main.cpp")
target_link_libraries(03_Color LtCore LtGraphics LtEvents)