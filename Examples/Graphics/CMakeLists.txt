cmake_minimum_required(VERSION 3.8)

project(ExamplesGraphics)

add_executable(01_WindowAndRender "01_WindowAndRender/main.cpp")
target_link_libraries(01_WindowAndRender LtCore LtGraphics LtEvents)

add_executable(02_FpsLimiter "02_FpsLimiter/main.cpp")
target_link_libraries(02_FpsLimiter LtCore LtGraphics LtEvents)

add_executable(03_Color "03_Color/main.cpp")
target_link_libraries(03_Color LtCore LtGraphics LtEvents)

add_executable(04_FpsCounter "04_FpsCounter/main.cpp")
target_link_libraries(04_FpsCounter LtCore LtGraphics LtEvents)

add_executable(05_DrawLine "05_DrawLine/main.cpp")
target_link_libraries(05_DrawLine LtCore LtGraphics LtEvents)

add_executable(06_FillRect "06_FillRect/main.cpp")
target_link_libraries(06_FillRect LtCore LtGraphics LtEvents)

add_executable(07_Mouse "07_Mouse/main.cpp")
target_link_libraries(07_Mouse LtCore LtGraphics LtEvents)

add_executable(08_Draw "08_Draw/main.cpp")
target_link_libraries(08_Draw LtCore LtAllocators LtGraphics LtEvents)