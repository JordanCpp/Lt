cmake_minimum_required(VERSION 3.8)

project(TestAllocators)

add_executable(01_WindowAndRender "01_WindowAndRender/main.cpp")
target_link_libraries(01_WindowAndRender LtCore LtGraphics LtEvents)

add_executable(02_FpsLimiter "02_FpsLimiter/main.cpp")
target_link_libraries(02_FpsLimiter LtCore LtGraphics LtEvents)

add_executable(03_Color "03_Color/main.cpp")
target_link_libraries(03_Color LtCore LtGraphics LtEvents)

add_executable(04_FpsCounter "04_FpsCounter/main.cpp")
target_link_libraries(04_FpsCounter LtCore LtGraphics LtEvents)