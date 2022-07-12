cmake_minimum_required(VERSION 3.8)

project(TestGraphics)

add_executable(Point2 "Point2.cpp")
target_link_libraries(Point2 LtCore)

add_executable(Rect2 "Rect2.cpp")
target_link_libraries(Rect2 LtCore)

add_executable(Color "Color.cpp")
target_link_libraries(Color LtCore LtGraphics)

add_executable(Window "Window.cpp")
target_link_libraries(Window LtCore LtGraphics LtEvents)

add_executable(FpsCounter "FpsCounter.cpp")
target_link_libraries(FpsCounter LtCore LtGraphics LtEvents)

add_executable(Monitor "Monitor.cpp")
target_link_libraries(Monitor LtCore LtGraphics LtEvents)

add_executable(Screenshoter "Screenshoter.cpp")
target_link_libraries(Screenshoter LtCore LtGraphics LtEvents)

add_executable(PixelConverter "PixelConverter.cpp")
target_link_libraries(PixelConverter LtCore LtGraphics LtEvents)

add_executable(PixelCalculator "PixelCalculator.cpp")
target_link_libraries(PixelCalculator LtCore LtGraphics LtEvents)

add_subdirectory("Base")
add_subdirectory("Cpu")
add_subdirectory("GL1")