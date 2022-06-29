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

add_executable(Window "Window.cpp")
target_link_libraries(Window LtCore LtGraphics LtEvents)

add_executable(CpuWindow "CpuWindow.cpp")
target_link_libraries(CpuWindow LtCore LtGraphics LtEvents)

add_executable(CpuRender "CpuRender.cpp")
target_link_libraries(CpuRender LtCore LtGraphics LtEvents)

add_executable(GL1Render "GL1Render.cpp")
target_link_libraries(GL1Render LtCore LtGraphics LtEvents)

add_executable(FpsCounter "FpsCounter.cpp")
target_link_libraries(FpsCounter LtCore LtGraphics LtEvents)

add_executable(Monitor "Monitor.cpp")
target_link_libraries(Monitor LtCore LtGraphics LtEvents)

add_executable(BaseCpuImage "BaseCpuImage.cpp")
target_link_libraries(BaseCpuImage LtCore LtAllocators LtGraphics)

add_executable(CpuImageFromAllocator "CpuImageFromAllocator.cpp")
target_link_libraries(CpuImageFromAllocator LtCore LtAllocators LtGraphics)

add_executable(CpuImageFromMemory "CpuImageFromMemory.cpp")
target_link_libraries(CpuImageFromMemory LtCore LtAllocators LtGraphics)

add_executable(CpuImageFromNew "CpuImageFromNew.cpp")
target_link_libraries(CpuImageFromNew LtCore LtGraphics)

add_executable(Screenshoter "Screenshoter.cpp")
target_link_libraries(Screenshoter LtCore LtGraphics LtEvents)